/*************************************************************************************
*                                  SRL ENGINE                                        *
*                                                                                    *
*                                                                                    *
*    Copyright (C) 2010 Pecatte Baptiste                                             *
*                                                                                    *
*    This program is free software; you can redistribute it and/or                   *
*    modify it under the terms of the GNU Lesser General Public                      *
*    License as published by the Free Software Foundation; either                    *
*    version 2.1 of the License, or (at your option) any later version.              *
*                                                                                    *
*    This program is distributed in the hope that it will be useful,                 *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU                *
*    Lesser General Public License for more details.                                 *
*                                                                                    *
*    You should have received a copy of the GNU Lesser General Public                *
*    License along with this program; if not, write to the Free Software             *
*    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA    *
*                                                                                    *
**************************************************************************************/

/*************************************************************************************
*																					 *
*								Part of a free library								 *
*																					 *
*    Title : Multiple-Precision Unsigned Integer Arithmetic		 					 *
*    Author : Philip J. Erdelsky													 *
*	 Date: October 25, 2001; update on May 16, 2011									 *
*    Web site : http://www.efgh.com/software/mpuint.htm								 *
*																					 *
**************************************************************************************/



#ifndef srlHeaderMPUInt
#define srlHeaderMPUInt

#include <SRL/Environment.hpp>
#include <SRL/maths/vec2.hpp>
#include <cmath>

#ifdef srlNamespaceMaths
namespace srl {
#endif

	class mpuint {
		public:
		
			mpuint(unsigned len){ 
				length = len; 
				value = new unsigned short[len]; 
			}
			
			mpuint(const mpuint &){ 
				length = n.length;
				value = new unsigned short[length]; 
				for (unsigned i = 0; i < length; i++) 
					value[i] = n.value[i];
			}
			
			mpuint(unsigned len, unsigned short* v) {
				length = len;
				value = new unsigned short[length];
				for (unsigned i = 0; i < length; i++) 
					value[i] = v[i];
			}
			
			~mpuint(){
				delete [] value;
			}
			
			
			
			
			bool IsZero() const {
				unsigned i;
				for (i = 0; i < length; i++) {
					if (value[i] != 0)
						return false;
				}
				return true;
			}
			
			int Compare(const mpuint &) const{
				unsigned i;
				if (length > n.length) {
					for (i = length-1; i >= n.length; i--) {
						if (value[i] != 0)
							return 1;
					}
				}
				else if (n.length > length) {
					for (i = n.length-1; i >= length; i--) {
						if (n.value[i] != 0)
							return -1;
					}
				}
				else
					i = length-1;
					
				while (true) {
					if (value[i] > n.value[i])
						return 1;
					if (value[i] < n.value[i])
						return -1;
					if (i == 0)
						return 0;
					i--;
				}
			}
			
			int Compare(unsigned short n) const {
				unsigned i;
				for (i = length-1; i >= 1; i--) {
					if (value[i] != 0)
						return 1;
				}
				return value[0] > n ? 1 : value[0] < n ? -1 : 0;
			}

			
			
			
			void operator = (const mpuint &n) {
				unsigned i;
				for (i = 0; i < length && i < n.length; i++)
					value[i] = n.value[i];
				for (; i < length; i++)
					value[i] = 0;
				for (; i < n.length; i++) {
					if (n.value[i] != 0)
						numeric_overflow();
				}
			}
			
			void operator = (unsigned short n) {
				value[0] = n;
				unsigned i;
				for (i = 1; i < length; i++)
					value[i] = 0;
			}
			
			void operator += (const mpuint &n) {
				unsigned i;
				unsigned long carry = 0;
				for (i = 0; i < length; i++) {
					unsigned long sum = value[i] + (i < n.length ? n.value[i] : 0) + carry;
					value[i] = sum;
					carry = sum >> 16;
				}
				if (carry != 0)
					numeric_overflow();
				for (; i < n.length; i++) {
					if (n.value[i] != 0)
						numeric_overflow();
				}
			}
			
			void operator += (unsigned short n) {
				value[0] += n;
				if (value[0] < n) {
					unsigned i;
					for (i = 1; i < length; i++) {
						if (++value[i] != 0)
							return;
					}
					numeric_overflow();
				}
			}
			
			void operator -= (const mpuint &n) {
				unsigned i;
				unsigned long borrow = 0;
				for (i = 0; i < length; i++) {
					unsigned long subtrahend = (i < n.length ? n.value[i] : 0) + borrow;
					borrow = (unsigned long)(value[i]) < subtrahend;
					value[i] -= subtrahend;
				}
				if (borrow != 0)
					numeric_overflow();
				for (; i < n.length; i++) {
					if (n.value[i] != 0)
						numeric_overflow();
				}
			}

			void operator -= (unsigned short n) {
				if (value[0] >= n)
					value[0] -= n;
				else {
					value[0] -= n;
					for (unsigned i = 1; i < length; i++) {
						if (--value[i] != 0xFFFF)
							return;
					}
					numeric_overflow();
				}
			}

			void operator *= (const mpuint &n) {
				unsigned i;
				unsigned short *multiplier = new unsigned short[length];
				for (i = 0; i < length; i++) {
					multiplier[i] = value[i];
					value[i] = 0;
				}
				for (i = 0; i < length; i++) {
					unsigned j;
					for (j = 0; j < n.length; j++) {
						unsigned long product = multiplier[i] * n.value[j];
						unsigned k = i + j;
						while (product != 0) {
							if (k >= length)
								numeric_overflow();
							product += value[k];
							value[k] = product;
							product >>= 16;
							k++;
						}
					}
				}
				delete [] multiplier;
			}
			
			void operator *= (unsigned short n) {
				unsigned i;
				unsigned long product = 0;
				for (i = 0; i < length; i++) {
					product += n * value[i];
					value[i] = product;
					product >>= 16;
				}
				if (product != 0)
					numeric_overflow();
			}
			
			void operator /= (const mpuint &n) { 
				mpuint remainder(n.length); 
				mpuint dividend(*this); 
				Divide(dividend, n, *this, remainder);
			}

			void operator /= (unsigned short n) {
				(void) remainder(n);
			}
			
			void operator %= (const mpuint &n) { 
				mpuint quotient(length); 
				mpuint dividend(*this);
				Divide(dividend, n, quotient, *this);
			}
			
			void operator %= (unsigned short n) {
				*this = remainder(n);
			}
			static void Divide(const mpuint &, const mpuint &, mpuint &, mpuint &);
			char *edit(char *s) const {
				mpuint n(*this);
				unsigned i = 0; 
				do 
					s[i++] = n.remainder(10) + '0'; 
				while (!n.IsZero());
				s[i] = 0; 
				unsigned j; 
				for (j = 0; --i > j; j++) { 
					char c = s[i]; 
					s[i] = s[j];
					s[j] = c; 
				}
				return s; 
			}
			
			bool scan(const char *&s){ 
				const char *t = s; 
				bool found = false; 
				while (*t == ' ' || *t == '\t')
					t++;
				*this = 0; 
				while ('0' <= *t && *t <= '9') { 
					found = true;
					*this *= 10; 
					*this += (unsigned short) (*t++ - '0'); 
				} 
				s = t;
				return found; 
			}

			
			void dump() const {
				unsigned i;
				for (i = 0; i < length; i++)
					printf(" %x", value[i]);
				putchar('\n');
			}
			
			bool operator == (const mpuint &n) const {return Compare(n) == 0;}
			bool operator != (const mpuint &n) const {return Compare(n) != 0;}
			bool operator >  (const mpuint &n) const {return Compare(n) >  0;}
			bool operator >= (const mpuint &n) const {return Compare(n) >= 0;}
			bool operator <  (const mpuint &n) const {return Compare(n) <  0;}
			bool operator <= (const mpuint &n) const {return Compare(n) <= 0;}
			bool operator == (unsigned short n) const {return Compare(n) == 0;}
			bool operator != (unsigned short n) const {return Compare(n) != 0;}
			bool operator >  (unsigned short n) const {return Compare(n) >  0;}
			bool operator >= (unsigned short n) const {return Compare(n) >= 0;}
			bool operator <  (unsigned short n) const {return Compare(n) <  0;}
			bool operator <= (unsigned short n) const {return Compare(n) <= 0;}
			
			
			static void Power(const mpuint &base, const mpuint &exponent, const mpuint &modulus, mpuint &result){
				mpuint r(2*base.length+1);
				r = 1;
				bool one = true;
				unsigned i = exponent.length;
				while (i-- != 0) {
					unsigned bit = 1 << 15;
					do {
						if (!one) {
							mpuint n(r);
							r *= n;
							r %= modulus;
						}
						if (exponent.value[i] & bit) {
							r *= base;
							r %= modulus;
							one = false;
						}
						bit >>= 1;
					} while (bit != 0);
				}
				result = r;
			}
			
			
			static void EuclideanAlgorithm(const mpuint &x, const mpuint &y, mpuint &a, mpuint &b, mpuint &g) {
				unsigned length = x.length;
				if (y.length > length)
					length = y.length;
				if (x <= y) {
					mpuint q(length), r(length);
					mpuint::Divide(y, x, q, r);
					if (r == 0) {
						a = 1;
						b = 0;
						g = x;
					}
					else {
						mpuint ap(length);
						EuclideanAlgorithm(x, r, ap, b, g);
						// a = ap + b * q;
						a = b;
						a *= q;
						a += ap;
					}
				}
				else {
					mpuint ap(length), bp(length);
					EuclideanAlgorithm(y, x, bp, ap, g);
					// a = y - ap;
					a = y;
					a -= ap;
					// b = x - bp;
					b = x;
					b -= bp;
				}
			}
			
			static void GreatestCommonDivisor(const mpuint &x, const mpuint &y, mpuint &g) {
				if (x <= y) {
					mpuint r(y);
					r %= x;
					if (r == 0)
						g = x;
					else
						GreatestCommonDivisor(x, r, g);
				}
				else
					GreatestCommonDivisor(y, x, g);
			}
			
			
			unsigned length;
			unsigned short *value;

		private:
			unsigned short remainder(unsigned short n) {
				unsigned i = length;
				unsigned rem = 0;
				while (i-- != 0) {
					unsigned long dividend = (unsigned long) rem << 16 | (unsigned long) value[i];
					value[i] = dividend / n;
					rem = dividend % n;
				}
				return rem;
			}
			
			void shift(unsigned bit){
				for (unsigned i = 0; i < length; i++) { 
					unsigned long x = value[i] << 1 | bit; 
					value[i] = x; 
					bit = x >> 16; 
				} 
				if (bit != 0) 
					numeric_overflow();
			}
		
	};
	
#ifdef srlNamespaceMaths	
};
#endif
