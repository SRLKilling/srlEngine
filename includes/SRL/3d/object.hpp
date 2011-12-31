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
#ifndef srlHeader3dObject
#define srlHeader3dObject

#include <SRL/Environment.hpp>
#include <SRL/maths/vec3.hpp>

#include <SRL/3d/imesh.hpp>

namespace srl {

	class Object;
	
	namespace d3 {
		
		class SRLAPI Object {
			public:
				Object(srl::Object* object);
				~Object();
				
				void setCubeMesh(float size);
				void setBoxMesh(vec3 size);
				void setMesh(IMesh* mMesh);
				IMesh* getMesh();
				
				void draw();
				
			private:
				srl::Object* mGlobalObject;
				IMesh* mMesh;
				vec3 mScale;
				
		};
	
	};
	
};

#endif