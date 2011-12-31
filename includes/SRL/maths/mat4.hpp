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

#ifndef DefineHeaderMat4
#define DefineHeaderMat4
#include <SRL/environment.hpp>

#include <SRL/maths/vec3.hpp>
#include <stdio.h>

namespace srl {

    class mat4 {
        public:
            mat4() {
				for(int i = 0; i < 16; i++) mValues[i] = 0.0;
			}
			
            mat4(float* array) {
				loadFromArray(array);
			}
			
			mat4& operator= (float* array) {
				loadFromArray(array);
				return (*this);
			}
			
            mat4(const mat4& mat) {
				loadFromArray(mat.mValues);
			}
            
            mat4& operator= (const mat4 &mat) {
				loadFromArray(mat.mValues);
				return (*this);
			}
			
			
			
            mat4  operator*  ( const mat4 &mat ) {
				mat4 f;
				f.mValues[0]  = (mValues[0]  * mat.mValues[0])  +  (mValues[1]  * mat.mValues[4])  +  (mValues[2]  * mat.mValues[8] )  +  (mValues[3]  * mat.mValues[12]);
				f.mValues[1]  = (mValues[0]  * mat.mValues[1])  +  (mValues[1]  * mat.mValues[5])  +  (mValues[2]  * mat.mValues[9] )  +  (mValues[3]  * mat.mValues[13]);
				f.mValues[2]  = (mValues[0]  * mat.mValues[2])  +  (mValues[1]  * mat.mValues[6])  +  (mValues[2]  * mat.mValues[10])  +  (mValues[3]  * mat.mValues[14]);
				f.mValues[3]  = (mValues[0]  * mat.mValues[3])  +  (mValues[1]  * mat.mValues[7])  +  (mValues[2]  * mat.mValues[11])  +  (mValues[3]  * mat.mValues[15]);
				f.mValues[4]  = (mValues[4]  * mat.mValues[0])  +  (mValues[5]  * mat.mValues[4])  +  (mValues[6]  * mat.mValues[8] )  +  (mValues[7]  * mat.mValues[12]);
				f.mValues[5]  = (mValues[4]  * mat.mValues[1])  +  (mValues[5]  * mat.mValues[5])  +  (mValues[6]  * mat.mValues[9] )  +  (mValues[7]  * mat.mValues[13]);
				f.mValues[6]  = (mValues[4]  * mat.mValues[2])  +  (mValues[5]  * mat.mValues[6])  +  (mValues[6]  * mat.mValues[10])  +  (mValues[7]  * mat.mValues[14]);
				f.mValues[7]  = (mValues[4]  * mat.mValues[3])  +  (mValues[5]  * mat.mValues[7])  +  (mValues[6]  * mat.mValues[11])  +  (mValues[7]  * mat.mValues[15]);
				f.mValues[8]  = (mValues[8]  * mat.mValues[0])  +  (mValues[9]  * mat.mValues[4])  +  (mValues[10] * mat.mValues[8] )  +  (mValues[11] * mat.mValues[12]);
				f.mValues[9]  = (mValues[8]  * mat.mValues[1])  +  (mValues[9]  * mat.mValues[5])  +  (mValues[10] * mat.mValues[9] )  +  (mValues[11] * mat.mValues[13]);
				f.mValues[10] = (mValues[8]  * mat.mValues[2])  +  (mValues[9]  * mat.mValues[6])  +  (mValues[10] * mat.mValues[10])  +  (mValues[11] * mat.mValues[14]);
				f.mValues[11] = (mValues[8]  * mat.mValues[3])  +  (mValues[9]  * mat.mValues[7])  +  (mValues[10] * mat.mValues[11])  +  (mValues[11] * mat.mValues[15]);
				f.mValues[12] = (mValues[12] * mat.mValues[0])  +  (mValues[13] * mat.mValues[4])  +  (mValues[14] * mat.mValues[8] )  +  (mValues[15] * mat.mValues[12]);
				f.mValues[13] = (mValues[12] * mat.mValues[1])  +  (mValues[13] * mat.mValues[5])  +  (mValues[14] * mat.mValues[9] )  +  (mValues[15] * mat.mValues[13]);
				f.mValues[14] = (mValues[12] * mat.mValues[2])  +  (mValues[13] * mat.mValues[6])  +  (mValues[14] * mat.mValues[10])  +  (mValues[15] * mat.mValues[14]);
				f.mValues[15] = (mValues[12] * mat.mValues[3])  +  (mValues[13] * mat.mValues[7])  +  (mValues[14] * mat.mValues[11])  +  (mValues[15] * mat.mValues[15]);
				return f;
			}
            mat4& operator*= ( const mat4 &mat ) {
				(*this) = (*this) * mat;
				return (*this);
			}
			
            vec3 operator* (vec3 vec) {
				vec3 fvec;
				fvec.x = vec.x * (mValues[0] + mValues[1] + mValues[2]  + mValues[3]);
				fvec.y = vec.y * (mValues[4] + mValues[5] + mValues[6]  + mValues[7]);
				fvec.z = vec.z * (mValues[8] + mValues[9] + mValues[10] + mValues[11]);
				return fvec;
			}
			
			
			
            float& operator[](int i) {
				return mValues[i];
			}
			
            float* array() {
				return mValues;
			}
			

			void loadFromArray(const float* array) {
				for(int i = 0; i < 16; i++) mValues[i] = array[i];
			}
			
            void loadFromArray(float* array) {
				for(int i = 0; i < 16; i++) mValues[i] = array[i];
			}
			
            void loadIdentity() {
				mValues[0]  = 1.0; mValues[4]  = 0.0; mValues[8]  = 0.0; mValues[12] = 0.0;
				mValues[1]  = 0.0; mValues[5]  = 1.0; mValues[9]  = 0.0; mValues[13] = 0.0;
				mValues[2]  = 0.0; mValues[6]  = 0.0; mValues[10] = 1.0; mValues[14] = 0.0;
				mValues[3]  = 0.0; mValues[7]  = 0.0; mValues[11] = 0.0; mValues[15] = 1.0;
			}
			
            void perspective(float fovy, float aspect, float znear, float zfar) {
				float ymax = znear * tanf( fovy * PI / 360.0 );
				float xmax = ymax * aspect;
				
				mValues[0] = 2.0 * znear / (xmax - (-xmax));
				mValues[5] = 2.0 * znear / (ymax - (-ymax));
				mValues[8] = (xmax + (-xmax)) / (xmax - (-xmax));
				mValues[9] = (ymax + (-ymax)) / (ymax - (-ymax));
				mValues[10] = (-zfar - znear) / (zfar - znear);
				mValues[11] = -1.0;
				mValues[14] = (-2.0 * znear * zfar) / (zfar - znear);
				
				mValues[1] = mValues[2] = mValues[3] = mValues[4] = mValues[6] = mValues[7] = mValues[12] = mValues[13] = mValues[15] = 0.0;
			}
			
            void ortho(float left, float right, float bottom, float top, float znear, float zfar) {
				mValues[0] = 2.0 / (right - left);
				mValues[5] = 2.0 / (top - bottom);
				mValues[10] = -2.0 / (zfar - znear);
				mValues[12] = -(right + left) / (right - left);
				mValues[13] = -(top + bottom) / (top - bottom);
				mValues[14] = -(zfar + znear) / (zfar - znear);
				mValues[15] = 1.0;
				mValues[1] = mValues[2] = mValues[3] = mValues[4] = mValues[6] = mValues[7] = mValues[8] = mValues[9] = mValues[11] = 0.0;
			}
			
            void look(vec3 eye, vec3 target, vec3 top) {
				target.normalize();
			
				vec3 side = cross(target, top);
				side.normalize();
				
				top = cross(side, target);
				
				mValues[0] = side.x;
				mValues[4] = side.y;
				mValues[8] = side.z;
				
				mValues[1] = top.x;
				mValues[5] = top.y;
				mValues[9] = top.z;
				
				mValues[2] = -target.x;
				mValues[6] = -target.y;
				mValues[10] = -target.z;
				
				mValues[3] = mValues[7] = mValues[11] = mValues[12] = mValues[13] = mValues[14] = 0.0;
				mValues[15] = 1.0;
				
				translate(-eye.x, -eye.y, -eye.z);
			}
			
			float determinant() {
				return ((mValues[0] * mValues[5] * mValues[10]) +
						(mValues[4] * mValues[9] * mValues[2])  +
						(mValues[8] * mValues[1] * mValues[6])  -
						(mValues[8] * mValues[5] * mValues[2])  -
						(mValues[4] * mValues[1] * mValues[10]) -
						(mValues[0] * mValues[9] * mValues[6]));
			}
			
			mat4 inverted() {
				mat4 i;
				float idet = 1.0f / determinant();
				i.mValues[0]  =  (mValues[5] * mValues[10] - mValues[9] * mValues[6]) * idet;
				i.mValues[1]  = -(mValues[1] * mValues[10] - mValues[9] * mValues[2]) * idet;
				i.mValues[2]  =  (mValues[1] * mValues[6]  - mValues[5] * mValues[2]) * idet;
				i.mValues[3]  = 0.0;
				i.mValues[4]  = -(mValues[4] * mValues[10] - mValues[8] * mValues[6]) * idet;
				i.mValues[5]  =  (mValues[0] * mValues[10] - mValues[8] * mValues[2]) * idet;
				i.mValues[6]  = -(mValues[0] * mValues[6]  - mValues[4] * mValues[2]) * idet;
				i.mValues[7]  = 0.0;
				i.mValues[8]  =  (mValues[4] * mValues[9] - mValues[8] * mValues[5]) * idet;
				i.mValues[9]  = -(mValues[0] * mValues[9] - mValues[8] * mValues[1]) * idet;
				i.mValues[10] =  (mValues[0] * mValues[5] - mValues[4] * mValues[1]) * idet;
				i.mValues[11] = 0.0;
				i.mValues[12] = -(mValues[12] * i.mValues[0] + mValues[13] * i.mValues[4] + mValues[14] * i.mValues[8]);
				i.mValues[13] = -(mValues[12] * i.mValues[1] + mValues[13] * i.mValues[5] + mValues[14] * i.mValues[9]);
				i.mValues[14] = -(mValues[12] * i.mValues[2] + mValues[13] * i.mValues[6] + mValues[14] * i.mValues[10]);
				i.mValues[15] = 1.0;
				return i;
			}
			
            void invert() {
				(*this) = inverted();
			}
			
			mat4 transposed() {
				mat4 tr;
				tr.mValues[0] = mValues[0];  tr.mValues[4] = mValues[1];  tr.mValues[8]  = mValues[2];  tr.mValues[12] = mValues[3];
				tr.mValues[1] = mValues[4];  tr.mValues[5] = mValues[5];  tr.mValues[9]  = mValues[6];  tr.mValues[13] = mValues[7];
				tr.mValues[2] = mValues[8];  tr.mValues[6] = mValues[9];  tr.mValues[10] = mValues[10]; tr.mValues[14] = mValues[11];
				tr.mValues[3] = mValues[12]; tr.mValues[7] = mValues[13]; tr.mValues[11] = mValues[14]; tr.mValues[15] = mValues[15];
				return tr;
			}
			
            void transpose() {
				(*this) = transposed();
			}
			
            void translate(float x, float y, float z) {
				mValues[12] = mValues[0] * x + mValues[4] * y + mValues[8]  * z + mValues[12];
				mValues[13] = mValues[1] * x + mValues[5] * y + mValues[9]  * z + mValues[13];
				mValues[14] = mValues[2] * x + mValues[6] * y + mValues[10] * z + mValues[14];
				mValues[15] = mValues[3] * x + mValues[7] * y + mValues[11] * z + mValues[15];
			}
            void rotate(float x, float y, float z) {
				translate(x, y, z);
				/*Values[12] = Values[0] * x + Values[4] * y + Values[8]  * z + Values[12];
				Values[13] = Values[1] * x + Values[5] * y + Values[9]  * z + Values[13];
				Values[14] = Values[2] * x + Values[6] * y + Values[10] * z + Values[14];
				Values[15] = Values[3] * x + Values[7] * y + Values[11] * z + Values[15];
				
				float xcos = cos( ToRadiant(x) );
				float xsin = sin( ToRadiant(x) );
				float ycos = cos( ToRadiant(y) );
				float ysin = sin( ToRadiant(y) );
				float zcos = cos( ToRadiant(z) );
				float zcos = cos( ToRadiant(z) );
				
				f.mValues[0]  = (mValues[0]  * mat.mValues[0])  +  (mValues[1]  * mat.mValues[4])  +  (mValues[2]  * mat.mValues[8] )  +  (mValues[3]  * mat.mValues[12]);
				f.mValues[1]  = (mValues[0]  * mat.mValues[1])  +  (mValues[1]  * mat.mValues[5])  +  (mValues[2]  * mat.mValues[9] )  +  (mValues[3]  * mat.mValues[13]);
				f.mValues[2]  = (mValues[0]  * mat.mValues[2])  +  (mValues[1]  * mat.mValues[6])  +  (mValues[2]  * mat.mValues[10])  +  (mValues[3]  * mat.mValues[14]);
				f.mValues[3]  = (mValues[0]  * mat.mValues[3])  +  (mValues[1]  * mat.mValues[7])  +  (mValues[2]  * mat.mValues[11])  +  (mValues[3]  * mat.mValues[15]);
				f.mValues[4]  = (mValues[4]  * mat.mValues[0])  +  (mValues[5]  * mat.mValues[4])  +  (mValues[6]  * mat.mValues[8] )  +  (mValues[7]  * mat.mValues[12]);
				f.mValues[5]  = (mValues[4]  * mat.mValues[1])  +  (mValues[5]  * mat.mValues[5])  +  (mValues[6]  * mat.mValues[9] )  +  (mValues[7]  * mat.mValues[13]);
				f.mValues[6]  = (mValues[4]  * mat.mValues[2])  +  (mValues[5]  * mat.mValues[6])  +  (mValues[6]  * mat.mValues[10])  +  (mValues[7]  * mat.mValues[14]);
				f.mValues[7]  = (mValues[4]  * mat.mValues[3])  +  (mValues[5]  * mat.mValues[7])  +  (mValues[6]  * mat.mValues[11])  +  (mValues[7]  * mat.mValues[15]);
				f.mValues[8]  = (mValues[8]  * mat.mValues[0])  +  (mValues[9]  * mat.mValues[4])  +  (mValues[10] * mat.mValues[8] )  +  (mValues[11] * mat.mValues[12]);
				f.mValues[9]  = (mValues[8]  * mat.mValues[1])  +  (mValues[9]  * mat.mValues[5])  +  (mValues[10] * mat.mValues[9] )  +  (mValues[11] * mat.mValues[13]);
				f.mValues[10] = (mValues[8]  * mat.mValues[2])  +  (mValues[9]  * mat.mValues[6])  +  (mValues[10] * mat.mValues[10])  +  (mValues[11] * mat.mValues[14]);
				f.mValues[11] = (mValues[8]  * mat.mValues[3])  +  (mValues[9]  * mat.mValues[7])  +  (mValues[10] * mat.mValues[11])  +  (mValues[11] * mat.mValues[15]);
				f.mValues[12] = (mValues[12] * mat.mValues[0])  +  (mValues[13] * mat.mValues[4])  +  (mValues[14] * mat.mValues[8] )  +  (mValues[15] * mat.mValues[12]);
				f.mValues[13] = (mValues[12] * mat.mValues[1])  +  (mValues[13] * mat.mValues[5])  +  (mValues[14] * mat.mValues[9] )  +  (mValues[15] * mat.mValues[13]);
				f.mValues[14] = (mValues[12] * mat.mValues[2])  +  (mValues[13] * mat.mValues[6])  +  (mValues[14] * mat.mValues[10])  +  (mValues[15] * mat.mValues[14]);
				f.mValues[15] = (mValues[12] * mat.mValues[3])  +  (mValues[13] * mat.mValues[7])  +  (mValues[14] * mat.mValues[11])  +  (mValues[15] * mat.mValues[15]);*/
			}
            void scale(float x, float y, float z) {
				mValues[0]*=x;
				mValues[4]*=y;
				mValues[8]*=z;
				
				mValues[1]*=x;
				mValues[5]*=y;
				mValues[9]*=z;

				mValues[2]*=x;
				mValues[6]*=y;
				mValues[10]*=z;

				mValues[3]*=x;
				mValues[7]*=y;
				mValues[11]*=z;
			}
			
			static mat4 identity() {
				mat4 mat;
				mat.loadIdentity();
				return mat;
			}
			
        private:
            float mValues[16];
    };

};
 
#endif
