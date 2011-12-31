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
#ifndef srlHeaderRect
#define srlHeaderRect
#include <SRL/environment.hpp>

#include <SRL/maths/vec2.hpp>
#include <cmath>

#ifdef srlNamespaceMaths
namespace srl {
#endif

	class rect {
		public:
			rect() : x(0), y(0), w(0), h(0) {};
			rect(float x, float y) : x(x), y(y), w(0), h(0) {};
			rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {};
			rect(const rect& r) : x(r.x), y(r.y), w(r.w), h(r.h) {};
			
			void resize(float newx, float newy) {
				x = newx;
				y = newy;
			}
			
			void resizeDec(float xdec, float ydec) {
				x += xdec;
				y += ydec;
			}
			
			rect& operator=(const rect& r) {
				x = r.x; y = r.y; h = r.h; w = r.w;
				return *this;
			}
			
            rect operator-() {
				return rect(-x, -y, -w, -h);
			}
			
            rect operator*(const float &f) {
				return rect(x, y, w * f, h * f);
			}
			
            rect& operator*= (const float &f) {
				this->operator*(f);
				return *this;
			}
            
			
			
            rect operator/(const float &f) {
				return rect(x, y, w / f, h / f);
			}
			
			
            rect& operator/= (const float &f) {
				this->operator/(f);
				return *this;
			}
            
			
            bool operator!=(const rect &r) {
				return (x != r.x) || (y != r.y) || (w != r.w) || (h != r.h);
			}
			bool operator==(const rect &r) {
				return (x == r.x) || (y == r.y) || (w == r.w) || (h == r.h);
			}
			
			bool isIn(vec2 point) {
				return (point.x > x && point.x < x+w) && (point.y > y && point.y < y+h);
			}
			
			float&	operator[] ( const int i ) {
				switch(i) {
					case 0: return x; break;
					case 1: return y; break;
					case 2: return w; break;
					case 3: return h; break;
				}
			}
			
			vec2 pos() {
				return vec2(w, y);
			}
			
			vec2 size() {
				return vec2(w, h);
			}
			
			/*rect union(rect r) {
			
			}
			
			rect inter(rect r) {
			
			}*/
			
		float x;
		float y;
		float w;
		float h;
	};
	
#ifdef srlNamespaceMaths	
};
#endif

#endif
