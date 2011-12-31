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
#ifndef srlHeaderVec4
#define srlHeaderVec4
#include <SRL/environment.hpp>

#include <SRL/maths/vec3.hpp>
#include <cmath>

#ifdef srlNamespaceMaths
namespace srl {
#endif

	class vec4 {
		public:
			vec4() : x(0), y(0), z(0), w(0) {};
			vec4(float f) : x(f), y(f), z(f), w(f) {};
			vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
			vec4(vec2 v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {};
			vec4(float x, vec2 v, float w) : x(x), y(v.x), z(v.y), w(w) {};
			vec4(float x, float y, vec2 v) : x(x), y(y), z(v.x), w(v.y) {};
			vec4(vec3 v, float w) : x(v.x), y(v.y), z(v.z), w(w) {};
			vec4(float x, vec3 v) : x(x), y(v.x), z(v.y), w(v.z) {};
			
            vec4  operator-  () {
				return vec4(-x, -y, -z, -w);
			}
			
			
            vec4  operator+  ( const vec4 &v ) {
				return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
			}
            vec4  operator+  ( const float &f ) {
				return vec4(x + f, y + f, z + f, w + f);
			}
			
			vec4& operator+= ( const vec4 &v ) {
				x += v.x; y += v.y; z += v.z; w += v.w;
				return *this;
			}
            vec4& operator+= ( const float &f ) {
				x += f; y += f; z += f; w += f;
				return *this;
			}
            
			
            vec4  operator-  ( const vec4 &v ) {
				return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
			}
            vec4  operator-  ( const float &f ) {
				return vec4(x - f, y - f, z - f, w - f);
			}
			
            vec4& operator-= ( const vec4 &v ) {
				x -= v.x; y -= v.y; z -= v.z; w -= v.w;
				return *this;
			}
            vec4& operator-= ( const float &f ) {
				x -= f; y -= f; z -= f; w -= f;
				return *this;
			}			
            
			
            vec4  operator*  ( const vec4 &v ) {
				return vec4(x * v.x, y * v.y, z * v.z, w * v.w);
			}
            vec4  operator*  ( const float &f ) {
				return vec4(x * f, y * f, z * f, w * f);
			}
			
            vec4& operator*= ( const vec4 &v ) {
				x *= v.x; y *= v.y; z *= v.z; w *= v.w;
				return *this;
			}
            vec4& operator*= ( const float &f ) {
				x *= f; y *= f; z *= f; w *= f;
				return *this;
			}
            
			
            vec4  operator/  ( const vec4 &v ) {
				return vec4(x / v.x, y / v.y, z / v.z, w / v.w);
			}
            vec4  operator/  ( const float &f ) {
				return vec4(x / f, y / f, z / f, w /f);
			}
			
            vec4& operator/= ( const vec4 &v ) {
				x /= v.x; y /= v.y; z /= v.z; w /= v.w;
				return *this;
			}
            vec4& operator/= ( const float &f ) {
				x /= f; y /= f; z /= f; w /= f;
				return *this;
			}
            
			
            bool operator!= ( const vec4 &v ) {
				return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
			}
			bool operator== ( const vec4 &v ) {
				return (x == v.x) || (y == v.y) || (z == v.z) || (w == v.w);
			}
			
			
			float&	operator[] ( const int i ) {
				switch(i) {
					case 0: return x; break;
					case 1: return y; break;
					case 2: return z; break;
					case 3: return w; break;
				}
			}
			
			
			float lenght() {
				return sqrt(x*x + y*y + z*z);
			}
			
			void normalize() {
				float l = lenght();
				x /= l; y /= l; z /= l; w /= l;
			}
			
			void cross( const vec3 &v ) {
				x = y * v.z - z * v.y;
				y = z * v.x - x * v.z;
				z = x * v.y - y * v.x;
			}
			
			float dot(const vec3 &v ) { 
				return x * v.x + y * v.y + z * v.z;
			}
			float dot(const vec4 &v ) { 
				return x * v.x + y * v.y + z * v.z;
			}
			
		float x;
		float y;
		float z;
		float w;
	};
	
	inline float lenght(vec4 v) {
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}
	
	inline void normalize(vec4 v) {
		v.normalize();
	}
	
	inline vec4 normalized(vec4 v) {
		float l = lenght(v);
		return vec4(v.x/l, v.y/l, v.z/l, v.w);
	}
	
	inline vec4 cross(vec4 v, vec4 u) {
		return vec4(v.y * u.z - v.z * u.y,
					v.z * u.x - v.x * u.z,
					v.x * u.y - v.y * u.x,
					v.w);
	}
	
	inline float dot(vec4 v, vec4 u) {
		return v.x * u.x + v.y * u.y + v.z * u.z;
	}
	inline float dot(vec3 v, vec4 u) {
		return v.x * u.x + v.y * u.y + v.z * u.z;
	}
	inline float dot(vec4 v, vec3 u) {
		return v.x * u.x + v.y * u.y + v.z * u.z;
	}
	
#ifdef srlNamespaceMaths	
};
#endif

#endif
