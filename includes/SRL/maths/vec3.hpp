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
#ifndef srlHeaderVec3
#define srlHeaderVec3
#include <SRL/environment.hpp>

#include <SRL/maths/vec2.hpp>
#include <cmath>

#ifdef srlNamespaceMaths
namespace srl {
#endif

	class vec3 {
		public:
			vec3() : x(0), y(0), z(0) {};
			vec3(float f) : x(f), y(f), z(f) {};
			vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
			vec3(vec2 v, float _z) : x(v.x), y(v.y), z(_z) {};
			vec3(float _x, vec2 v) : x(_x), y(v.x), z(v.y) {};
			
            vec3  operator-  () {
				return vec3(-x, -y, -z);
			}
			
			
            vec3  operator+  ( const vec3 &v ) {
				return vec3(x + v.x, y + v.y, z + v.z);
			}
            vec3  operator+  ( const float &f ) {
				return vec3(x + f, y + f, z + f);
			}
			
			vec3& operator+= ( const vec3 &v ) {
				x += v.x; y += v.y; z += v.z;
				return *this;
			}
            vec3& operator+= ( const float &f ) {
				x += f; y += f; z += f;
				return *this;
			}
            
			
            vec3  operator-  ( const vec3 &v ) {
				return vec3(x - v.x, y - v.y, z - v.z);
			}
            vec3  operator-  ( const float &f ) {
				return vec3(x - f, y - f, z - f);
			}
			
            vec3& operator-= ( const vec3 &v ) {
				x -= v.x; y -= v.y; z -= v.z;
				return *this;
			}
            vec3& operator-= ( const float &f ) {
				x -= f; y -= f; z -= f;
				return *this;
			}			
            
			
            vec3  operator*  ( const vec3 &v ) {
				return vec3(x * v.x, y * v.y, z * v.z);
			}
            vec3  operator*  ( const float &f ) {
				return vec3(x * f, y * f, z * f);
			}
			
            vec3& operator*= ( const vec3 &v ) {
				x *= v.x; y *= v.y; z *= v.z;
				return *this;
			}
            vec3& operator*= ( const float &f ) {
				x *= f; y *= f; z *= f;
				return *this;
			}
            
			
            vec3  operator/  ( const vec3 &v ) {
				return vec3(x / v.x, y / v.y, z / v.z);
			}
            vec3  operator/  ( const float &f ) {
				return vec3(x / f, y / f, z / f);
			}
			
            vec3& operator/= ( const vec3 &v ) {
				x /= v.x; y /= v.y; z /= v.z;
				return *this;
			}
            vec3& operator/= ( const float &f ) {
				x /= f; y /= f; z /= f;
				return *this;
			}
            
			
            bool operator!= ( const vec3 &v ) {
				return (x != v.x) || (y != v.y) || (z != v.z);
			}
			bool operator== ( const vec3 &v ) {
				return (x == v.x) || (y == v.y) || (z == v.z);
			}
			
			
			float&	operator[] ( const int i ) {
				switch(i) {
					case 0: return x; break;
					case 1: return y; break;
					case 2: return z; break;
				}
			}
			
			
			float lenght() {
				return sqrt(x*x + y*y + z*z);
			}
			
			void normalize() {
				float l = lenght();
				if(l < 0.0) return;
				x *= 1.0 / l;
				y *= 1.0 / l;
				z *= 1.0 / l;
			}
			
			void cross( const vec3 &v ) {
				x = y * v.z - z * v.y;
				y = z * v.x - x * v.z;
				z = x * v.y - y * v.x;
			}
			
			float dot(const vec3 &v ) { 
				return x * v.x + y * v.y + z * v.z;
			}
			
		float x;
		float y;
		float z;
	};
	
	inline float lenght(vec3 v) {
		return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}
	
	inline void normalize(vec3 v) {
		v.normalize();
	}
	
	inline vec3 normalized(vec3 v) {
		float l = lenght(v);
		return vec3(v.x/l, v.y/l, v.z/l);
	}
	
	inline vec3 cross(vec3 v, vec3 u) {
		return vec3(v.y * u.z - v.z * u.y,
					v.z * u.x - v.x * u.z,
					v.x * u.y - v.y * u.x);
	}
	
	inline float dot(vec3 v, vec3 u) {
		return v.x * u.x + v.y * u.y + v.z * u.z;
	}
	
#ifdef srlNamespaceMaths	
};
#endif

#endif
