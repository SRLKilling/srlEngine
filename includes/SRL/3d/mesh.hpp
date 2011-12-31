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
#ifndef srlHeader3dMesh
#define srlHeader3dMesh
#include <SRL/environment.hpp>

#include <SRL/maths/vec3.hpp>

#include <SRL/3d/imesh.hpp>
#include <SRL/openGL/vertexBuffer.hpp>
#include <SRL/openGL/indexBuffer.hpp>

namespace srl {

	class Object;
	
	namespace d3 {
		
		class SRLAPI Mesh : public IMesh {
			public:
				Mesh();
				~Mesh();
				
				static Mesh* getBoxMesh();
				static Mesh* getSquareMesh();
				
				void draw();
				
			private:
				gl::VertexBuffer* mVbo;
				gl::IndexBuffer* mIbo;
		};
	
	};
	
};

#endif