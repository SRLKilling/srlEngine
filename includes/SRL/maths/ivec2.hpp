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
#ifndef srlHeaderIVec2
#define srlHeaderIVec2
#include <SRL/environment.hpp>

#include <cmath>

#ifdef srlNamespaceMaths
namespace srl {
#endif

	class ivec2 {
		public:
			ivec2() : x(0), y(0) {};
			ivec2(int f) : x(f), y(f) {};
			ivec2(int x, int y) : x(x), y(y) {};
			
            ivec2 operator-() {
				return ivec2(-x, -y);
			}
			
			
            ivec2  operator+  (const ivec2 &v) {
				return ivec2(x + v.x, y + v.y);
			}
            ivec2  operator+  (const int &f) {
				return ivec2(x + f, y + f);
			}
			
			ivec2& operator+= ( const ivec2 &v ) {
				x += v.x; y += v.y;
				return *this;
			}
            ivec2& operator+= ( const int &f ) {
				x += f; y += f;
				return *this;
			}
            
			
            ivec2  operator-(const ivec2 &v ) {
				return ivec2(x - v.x, y - v.y);
			}
            ivec2  operator-(const int &f) {
				return ivec2(x - f, y - f);
			}
			
            ivec2& operator-=(const ivec2 &v) {
				x -= v.x; y -= v.y;
				return *this;
			}
            ivec2& operator-=(const int &f) {
				x -= f; y -= f;
				return *this;
			}			
            
			
            ivec2  operator*  ( const ivec2 &v ) {
				return ivec2(x * v.x, y * v.y);
			}
            ivec2  operator*  ( const int &f ) {
				return ivec2(x * f, y * f);
			}
			
            ivec2& operator*= ( const ivec2 &v ) {
				x *= v.x; y *= v.y;
				return *this;
			}
            ivec2& operator*= ( const int &f ) {
				x *= f; y *= f;
				return *this;
			}
            
			
            ivec2  operator/  ( const ivec2 &v ) {
				return ivec2(x / v.x, y / v.y);
			}
            ivec2  operator/  ( const int &f ) {
				return ivec2(x / f, y / f);
			}
			
            ivec2& operator/= ( const ivec2 &v ) {
				x /= v.x; y /= v.y;;
				return *this;
			}
            ivec2& operator/= ( const int &f ) {
				x /= f; y /= f;;
				return *this;
			}
            
			
            bool operator!= ( const ivec2 &v ) {
				return (x != v.x) || (y != v.y);
			}
			bool operator== ( const ivec2 &v ) {
				return (x == v.x) || (y == v.y);
			}
			
			
			int&	operator[] ( const int i ) {
				switch(i) {
					case 0: return x; break;
					case 1: return y; break;
				}
			}
			
			
			float lenght() {
				return sqrt(x*x + y*y);
			}
			
			void normalize() {
				float l = lenght();
				x /= l; y /= l;;
			}
			
			float dot(const ivec2 &v ) {
				return x * v.x + y * v.y;
			}
			
		int x;
		int y;
	};
	
	inline float lenght(ivec2 v) {
		return sqrt(v.x*v.x + v.y*v.y);
	}
	
	inline void normalize(ivec2 v) {
		v.normalize();
	}
	
	inline ivec2 normalized(ivec2 v) {
		int l = lenght(v);
		return ivec2(v.x/l, v.y/l);
	}
	
	inline int dot(ivec2 v, ivec2 u) {
		return v.x * u.x + v.y * u.y;
	}
	
#ifdef srlNamespaceMaths	
};
#endif

#endif
