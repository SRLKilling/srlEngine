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

#include <cmath>
#include <string>

#include <SRL/opengl/frustum.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {
    
    namespace gl {
        
        Plane::Plane(){
            
        }
        Plane::Plane(vec4 normal) {
            define(normal);
        }
        Plane::Plane(float a, float b, float c, float d) {
            define(a, b, c, d);
        }
        
        void Plane::define(vec4 normal) {
            mNormal = normal;
        }
        void Plane::define(float a, float b, float c, float d) {
            mNormal = vec4(a, b, c, d);
        }
        
        bool Plane::isOn(vec3 point) {
            return ((mNormal.x * point.x) + (mNormal.y * point.y) + (mNormal.z * point.z) + mNormal.w == 0);
        }
        bool Plane::isOver(vec3 point) {
            return ((mNormal.x * point.x) + (mNormal.y * point.y) + (mNormal.z * point.z) + mNormal.w > 0);
        }
        bool Plane::isUnder(vec3 point) {
            return ((mNormal.x * point.x) + (mNormal.y * point.y) + (mNormal.z * point.z) + mNormal.w < 0);
        }
        
        void Plane::normalize() {
            mNormal.normalize();
        }
        
        
        
        
        Frustum::Frustum() {
            
        }
        
        void Frustum::compute() {
            compute( Context::getCurrent()->getModelviewProjMatrix() );
        }
        
        void Frustum::compute(mat4 mwproj) {
             mPlanes[0].define( mwproj[3]-mwproj[0], mwproj[7]-mwproj[4], mwproj[11]-mwproj[8],  mwproj[15]-mwproj[12]);
			 mPlanes[0].normalize();
             mPlanes[1].define( mwproj[3]+mwproj[0], mwproj[7]+mwproj[4], mwproj[11]+mwproj[8],  mwproj[15]+mwproj[12]);
			 mPlanes[1].normalize();
             mPlanes[2].define( mwproj[3]+mwproj[2], mwproj[7]+mwproj[6], mwproj[11]+mwproj[10], mwproj[15]+mwproj[14]);
			 mPlanes[2].normalize();
             mPlanes[3].define( mwproj[3]+mwproj[1], mwproj[7]+mwproj[5], mwproj[11]+mwproj[9],  mwproj[15]+mwproj[13]);
			 mPlanes[3].normalize();
             mPlanes[4].define( mwproj[3]-mwproj[1], mwproj[7]-mwproj[5], mwproj[11]-mwproj[9],  mwproj[15]-mwproj[13]);
			 mPlanes[4].normalize();
             mPlanes[5].define( mwproj[3]-mwproj[2], mwproj[7]-mwproj[6], mwproj[11]-mwproj[10], mwproj[15]-mwproj[14]);
			 mPlanes[5].normalize();
        }
        
        void Frustum::compute(mat4 proj, mat4 mw) {
            compute( proj * mw );
        }
        
        bool Frustum::isIn(vec3 point) {
            for(int i = 0; i < 6; i++) {
                if(mPlanes[i].isUnder(point)) return false;
            }
            return true;
        }
        
        Frustum* Frustum::getInstance() {
            static Frustum CurrentFrustum;
            return &CurrentFrustum;
        }
    
    };
    
};
