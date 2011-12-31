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

#ifndef DefineHeaderGlFrustum
#define DefineHeaderGlFrustum
#include <SRL/environment.hpp>

#include <SRL/maths/vec4.hpp>
#include <SRL/maths/mat4.hpp>

namespace srl {
    
    namespace gl {
        
        class SRLAPI Plane {
            public:
                Plane();
                Plane(vec4 normal);
                Plane(float a, float b, float c, float d);
                
                void define(vec4 normal);
                void define(float a, float b, float c, float d);
                
                bool isOn(vec3 point);
                bool isOver(vec3 point);
                bool isUnder(vec3 point);
                
                void normalize();
                
            private:
                vec4 mNormal;
        };
        
        class SRLAPI Frustum {
            protected:
                Frustum();
                
            public:
                void compute();
                void compute(mat4 mwproj);
                void compute(mat4 proj, mat4 mw);
                
                bool isIn(vec3 point);
                
                static Frustum* getInstance();
                
            private:
                Plane mPlanes[6];
                
        };
        
    };
    
};
#endif
