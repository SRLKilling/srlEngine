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
#ifndef DefineHeaderTerrain
#define DefineHeaderTerrain
#include <SRL/environment.hpp>

#include <SRL/3d/terrainQuadtree.hpp>
#include <SRL/OpenGL/VertexBuffer.hpp>
#include <SRL/OpenGL/IndexBuffer.hpp>
#include <SRL/OpenGL/texture2d.hpp>
#include <SRL/opengl/texturearray.hpp>
#include <SRL/OpenGL/Program.hpp>
#include <SRL/3d/imesh.hpp>
#include <SRL/maths/vec3.hpp>
#include <SRL/error.hpp>

namespace srl {
    
	namespace d3 {
	
		class SRLAPI Terrain : public IMesh {
			public:
				Terrain();
				~Terrain();
				
				void loadFromFile(std::string path, std::string sectionName = "Terrain");
				void destroy();
				
				void draw(vec3 position, vec3 rotation, vec3 scale);
				
			private:
				QuadTerrainNode* mRoot;
				gl::VertexBuffer mVertices;
				gl::VertexBuffer mNormals;
				gl::IndexBuffer mIndices;
				
				gl::Program* mProgram;
				gl::Texture2D* mNormalMap;
				gl::Texture2D* mAlphaMap;
				gl::TextureArray* mDetailMaps;
				
		};
    
	};
	
};

#endif
