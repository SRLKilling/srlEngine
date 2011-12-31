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

#ifndef DefineHeaderTerrainChunk
#define DefineHeaderTerrainChunk
#include <SRL/environment.hpp>

#include <SRL/OpenGL/VertexBuffer.hpp>
#include <vector>

namespace srl {
    
	namespace d3 {
		
		struct SRLAPI ChunkInfo {
			ChunkInfo(int hmw, int hmh, int xsq, int ysq, std::vector<unsigned int>* ind) : HMw(hmw), HMh(hmh), XSquareNum(xsq), YSquareNum(ysq), Ind(ind) {};
			int HMw;
			int HMh;
			int XSquareNum;
			int YSquareNum;
			std::vector<unsigned int>* Ind;
		};
		
		
		class SRLAPI TerrainChunk {
			public:
				TerrainChunk();
				~TerrainChunk();
				
				void load(int x, int y, int w, int h, ChunkInfo info);
				void destroy();
				
				void draw();
				
			private:
				void createSquare(int ix, int iy, int x, int y, int w, int h, ChunkInfo info, bool first, bool pair);
				
				int mBeginning;
				int mSize;
				
		};
		
	};
    
};

#endif
