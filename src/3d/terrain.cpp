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

#include <iostream>
#include <SRL/maths/mat3.hpp>
#include <SRL/3D/terrain.hpp>
#include <SRL/opengl/texture2d.hpp>
#include <SRL/res.hpp>
#include <SOIL/SOIL.h>

#define coord(x, y) ((x)*width + (y))
#define HeightMacro(x, y) ((float)heightmap[ coord(x, y) ])

namespace srl {
    
	namespace d3 {
	
		Terrain::Terrain() {
			mRoot = new QuadTerrainNode();
			mProgram = new gl::Program("shaders/terrain.vs", "shaders/terrain.fs");
			
			/*gl::Texture2D* tex = gl::Texture2D::getRgbaTexture();
			tex->load("data/heightmaptest_normalmap.png");
			mProgram->use();
			mProgram->uniform("normalmap", tex, 0);
			mProgram->unuse();*/
		}
		
		Terrain::~Terrain() {
			delete mRoot;
		}
		
		
		
		void Terrain::loadFromFile(std::string path, std::string sectionName) {
			res::openArchive(path);
			
			
			
			int width,height,channels;
			unsigned char* heightmap = res::getTexture2DBuffer(sectionName, "heightmap", &width, &height, &channels);
			
			for(int i = 0; i < width*height; i++)
				heightmap[i] /= 2;
			
			float* tmpArray = new float[width * height * 3];
			for(int i = 0; i < height; i++) {
				for(int j = 0; j < width; j++) {
					tmpArray[ coord(i, j)*3   ] = (float)i;
					tmpArray[ coord(i, j)*3 +1] = (float)heightmap[ coord(i, j) ];
					tmpArray[ coord(i, j)*3 +2] = (float)j;
				}
			}
			
			mVertices.bind();
			mVertices.alloc(width * height * 3);
			mVertices.sendData(0, tmpArray, width * height * 3);
			
			if(res::fileExists(sectionName, "normalmap")) {
				mNormalMap = res::getTexture2D(sectionName, "normalmap");
			}
			else {
				// Sobel operator
				mat3 gx(-1.0, -2.0, -1.0,
						 0.0,  0.0,  0.0,
						 1.0,  2.0,  1.0);
						
				mat3 gy(-1.0, 0.0, 1.0,
						-2.0, 0.0, 2.0,
						-1.0, 0.0, 1.0);
				
				for(int i = 1; i < height-1; i++) {
				   for(int j = 1; j < width-1; j++) {
						
						/*vec3 v1 = vec3( 0.0, ((float)heightmap[ coord(i-1, j) ] -(float)heightmap[ coord(i, j) ])/2,  1.0); v1.normalize();
						vec3 v2 = vec3( 1.0, ((float)heightmap[ coord(i, j-1) ] -(float)heightmap[ coord(i, j) ])/2,  0.0); v2.normalize();
						vec3 v3 = vec3( 0.0, ((float)heightmap[ coord(i+1, j) ] -(float)heightmap[ coord(i, j) ])/2, -1.0); v3.normalize();
						vec3 v4 = vec3(-1.0, ((float)heightmap[ coord(i, j+1) ] -(float)heightmap[ coord(i, j) ])/2,  0.0); v4.normalize();
						
						vec3 n = normalized( normalized(cross(v1, v2)) + normalized(cross(v2, v3)) + normalized(cross(v3, v4)) + normalized(cross(v4, v1)) );
						
						
						float sx = coord(i < height-1 ? i+1 : i, j) - coord(i != 0 ? i-1 : i, j);
						if (i == 0 || i == height -1)
							sx *= 2;

						float sy = coord(i, j < width-1 ? j+1 : j) - coord(i, j != 0 ?  j-1 : j);
						if (j == 0 || j == width -1)
							sy *= 2;
							
						n = normalized(vec3(-sx, 1, -sy));*/
						
						mat3 img( HeightMacro(i+1, j-1)/5, HeightMacro(i+1, j)/5, HeightMacro(i+1, j+1)/5,
								  HeightMacro(i  , j-1)/5, HeightMacro(i  , j)/5, HeightMacro(i  , j+1)/5,
								  HeightMacro(i-1, j-1)/5, HeightMacro(i-1, j)/5, HeightMacro(i-1, j+1)/5);
								  
						
						float cx = img.convolution( gx );
						float cy = img.convolution( gy );
						/*mat3 fx = gx * img;
						mat3 fy = gy * img;
						
						float cx = fx[0] + fx[1] + fx[2] + fx[6] + fx[7] + fx[8];
						float cy = fx[0] + fx[2] + fx[3] + fx[5] + fx[6] + fx[8];*/
						float cz = 0.5 + sqrt((cx*cx, cy*cy));
						
						vec3 n(cx, cz, cy);
						n.normalize();
						
						tmpArray[ coord(i, j)*3   ] = n.x;
						tmpArray[ coord(i, j)*3 +1] = n.y;
						tmpArray[ coord(i, j)*3 +2] = n.z;
					}
				}
				
				/*mNormals.bind();
				mNormals.alloc(width * height * 3);
				mNormals.sendData(0, tmpArray, width * height * 3);*/
				
			}
			
			std::vector<unsigned int> indicesVec;
			mRoot->build(0, 0, width, height, 5, ChunkInfo(width, height, 16, 16, &indicesVec));
			
			unsigned int indices[indicesVec.size()];
			for(int i = 0; i < indicesVec.size(); i++)
				indices[i] = indicesVec[i];
			
			mIndices.bind();
			mIndices.alloc(indicesVec.size());
			mIndices.sendData(0, indices, indicesVec.size());
			
			mAlphaMap = res::getTexture2D(sectionName, "alphamap");
			mDetailMaps = res::getTextureArray( res::getConf(sectionName, "detailtexturearray") );
			
			res::closeArchive();
		}
		
		
		void Terrain::destroy() {
			mRoot->destroy();
		}
		
		
		void Terrain::draw(vec3 position, vec3 rotation, vec3 scale) {
			mProgram->use();
			mProgram->uniform("normalmap", mNormalMap, 0);
			mProgram->uniform("detailmaps", mDetailMaps, 1);
			mProgram->uniform("alphamap", mAlphaMap, 2);
			
			mVertices.bind();
			mVertices.sendVertexAttribPointer(0, 3);
			
			/*mNormals.bind();
			mNormals.sendVertexAttribPointer(1, 3);*/
			
			mIndices.bind();
			mRoot->draw();
			mIndices.unbind();
			
			//mNormals.unbind();
			mVertices.unbind();
			
			mProgram->unuse();
		}
	
	};
    
};
