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
#ifndef srlHeaderIRect
#define srlHeaderIRect

#include <SRL/Environment.hpp>
#include <SRL/maths/ivec2.hpp>
#include <cmath>

#ifdef srlNamespaceMaths
namespace srl {
#endif

	class irect {
		public:
			irect() : x(0), y(0), w(0), h(0) {};
			irect(int x, int y) : x(x), y(y), w(0), h(0) {};
			irect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {};
			
			void resize(int neww, int newh) {
				w = neww;
				h = newh;
			}
			
			void resizeDec(int wdec, int hdec) {
				w += wdec;
				h += hdec;
			}
			
			irect operator-() {
				return irect(-x, -y, -w, -h);
			}

			irect operator*(const int &i) {
				return irect(x, y, w * i, h * i);
			}

			irect& operator*= (const int &i) {
				this->operator*(i);
				return *this;
			}



			irect operator/(const int &i) {
				return irect(x, y, w / i, h / i);
			}


			irect& operator/= (const int &i) {
				this->operator/(i);
				return *this;
			}


			bool operator!=(const irect &r) {
				return (x != r.x) || (y != r.y) || (w != r.w) || (h != r.h);
			}
			bool operator==(const irect &r) {
				return (x == r.x) || (y == r.y) || (w == r.w) || (h == r.h);
			}

			bool isIn(ivec2 point) {
				return (point.x > x && point.x < x+w) && (point.y > y && point.y < y+h);
			}

			int&	operator[] ( const int i ) {
				switch(i) {
					case 0: return x; break;
					case 1: return y; break;
					case 2: return w; break;
					case 3: return h; break;
				}
			}

			/*vec2 pos() {
				return vec2(w, y);
			}

			vec2 size() {
				return vec2(w, h);
			}*/

			/*rect union(rect r) {

			}

			rect inter(rect r) {

			}*/

			int x;
			int y;
			int w;
			int h;
	};
	
#ifdef srlNamespaceMaths	
};
#endif

#endif
