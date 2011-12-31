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

#ifndef DefineHeaderMat3
#define DefineHeaderMat3
#include <SRL/environment.hpp>

#include <SRL/maths/vec3.hpp>

namespace srl {

    class mat3 {
        public:
            mat3() {
				for(int i = 0; i < 9; i++) mValues[i] = 0.0;
			}
			
			mat3(float a, float b, float c,
				 float d, float e, float f,
				 float g, float h, float i) {
				 
				mValues[0] = a; mValues[3] = d; mValues[6] = g;
				mValues[1] = b; mValues[4] = e; mValues[7] = h;
				mValues[2] = c; mValues[5] = f; mValues[8] = i;
			}
			
            mat3(float* array) {
				loadFromArray(array);
			}
			
			mat3& operator= (float* array) {
				loadFromArray(array);
				return (*this);
			}
			
            mat3(const mat3& mat) {
				loadFromArray(mat.mValues);
			}
            
            mat3& operator= (const mat3 &mat) {
				loadFromArray(mat.mValues);
				return (*this);
			}
			
			
			
            mat3  operator*  ( const mat3 &mat ) {
				return mat3(mValues[0] * mat[0] + mValues[3] * mat[1] + mValues[6] * mat[2],
							mValues[1] * mat[0] + mValues[4] * mat[1] + mValues[7] * mat[2],
							mValues[2] * mat[0] + mValues[5] * mat[1] + mValues[8] * mat[2],
					
							mValues[0] * mat[3] + mValues[3] * mat[4] + mValues[6] * mat[5],
							mValues[1] * mat[3] + mValues[4] * mat[4] + mValues[7] * mat[5],
							mValues[2] * mat[3] + mValues[5] * mat[4] + mValues[8] * mat[5],
					
							mValues[0] * mat[6] + mValues[3] * mat[7] + mValues[6] * mat[8],
							mValues[1] * mat[6] + mValues[4] * mat[7] + mValues[7] * mat[8],
							mValues[2] * mat[6] + mValues[5] * mat[7] + mValues[8] * mat[8]);
			}
			
            mat3& operator*= ( const mat3 &mat ) {
				(*this) = (*this) * mat;
				return (*this);
			}
			
            vec3 operator* (vec3 vec) {
				return vec3(vec.x * (mValues[0] + mValues[1] + mValues[2]),
							vec.y * (mValues[2] + mValues[4] + mValues[5]),
							vec.z * (mValues[6] + mValues[7] + mValues[8]));
			}
			
			
			float convolution(mat3 m) {
				return (mValues[0] * m[0]) + (mValues[1] * m[1]) + (mValues[2] * m[2]) +
					   (mValues[3] * m[3]) + (mValues[4] * m[4]) + (mValues[5] * m[5]) +
					   (mValues[6] * m[6]) + (mValues[7] * m[7]) + (mValues[8] * m[8]);
			}
			
			
            float& operator[](int i) {
				return mValues[i];
			}
			
			const float& operator[](int i) const {
				return mValues[i];
			}
			
            float* array() {
				return mValues;
			}
			

			void loadFromArray(const float* array) {
				for(int i = 0; i < 9; i++) mValues[i] = array[i];
			}
			
            void loadFromArray(float* array) {
				for(int i = 0; i < 9; i++) mValues[i] = array[i];
			}
			
            void loadIdentity() {
				mValues[0]  = 1.0; mValues[3]  = 0.0; mValues[6]  = 0.0;
				mValues[1]  = 0.0; mValues[4]  = 1.0; mValues[7]  = 0.0;
				mValues[2]  = 0.0; mValues[5]  = 0.0; mValues[8] = 1.0;
			}
			
			mat3 transposed() {
				mat3 tr;
				tr.mValues[0] = mValues[0];  tr.mValues[3] = mValues[1];  tr.mValues[6] = mValues[2];
				tr.mValues[1] = mValues[3];  tr.mValues[4] = mValues[4];  tr.mValues[7] = mValues[5];
				tr.mValues[2] = mValues[6];  tr.mValues[5] = mValues[7];  tr.mValues[8] = mValues[8];
				return tr;
			}
			
            void transpose() {
				(*this) = transposed();
			}

        private:
            float mValues[9];
    };

};
 
#endif
