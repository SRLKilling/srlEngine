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

#ifndef DefineHeaderTerrainQuadtree
#define DefineHeaderTerrainQuadtree
#include <SRL/environment.hpp>

#include <SRL/3D/terrainChunk.hpp>
//#include <SRL/3D/BoundingBox.hpp>

namespace srl {

	namespace d3 {
    
		class SRLAPI QuadTerrainNode {
			public:
				QuadTerrainNode(QuadTerrainNode* parent = NULL, int depth = 0);
				~QuadTerrainNode();
			
				void build(int x, int y, int w, int h, int minSize, ChunkInfo chunkInfo);
				void draw();
				void destroy();
				
			private:
				TerrainChunk* mChunk;
				QuadTerrainNode* mParent;
				QuadTerrainNode** mChildren;
				int mDepth;
				//BoundingBox mBox;
				
		};
		
	};
	
};

#endif
