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

#include <SRL/3d/terrainChunk.hpp>

namespace srl {

	namespace d3 {
	
		TerrainChunk::TerrainChunk() {
			mBeginning = 0;
			mSize = 0;
		}
		
		TerrainChunk::~TerrainChunk() {
			destroy();
		}
		
		void TerrainChunk::load(int x, int y, int w, int h, ChunkInfo info) {
			mBeginning = info.Ind->size();
			
			info.Ind->push_back(x * info.HMh + y);
			
			int finalXSquareNum = (x + w < info.HMw) ? info.XSquareNum : info.XSquareNum;
			int finalYSquareNum = (y + h < info.HMh) ? info.YSquareNum : info.YSquareNum;
			for(int i = 0; i < finalXSquareNum; i++) {
				bool pair = (i%2 == 0);
				
				for(int j = 0; j < finalXSquareNum; j++) {
					int line = pair ? j : finalXSquareNum-1 - j;
					bool first = (pair && line == 0) || (!pair && line == info.XSquareNum-1);
					
					createSquare(i, line, x, y, w, h, info, first, pair);
				}
			}
			
			mSize = info.Ind->size() - mBeginning;
		}
		
		void TerrainChunk::destroy() {
			
		}
		
		void TerrainChunk::createSquare(int ix, int iy, int x, int y, int w, int h, ChunkInfo info, bool first, bool pair) {
			int xSq = w / info.XSquareNum;
			int ySq = h / info.YSquareNum;
			
			if(xSq < 1) xSq = 1;
			if(ySq < 1) ySq = 1;
			
			int xPos = ix*xSq + x;
			int yPos = iy*ySq + y;
			
			if((xPos +xSq) >= info.HMw) xSq = w / info.XSquareNum - 1;
			if((yPos +ySq) >= info.HMh) ySq = h / info.YSquareNum - 1;
			
			if(pair) {
				if(first)
					info.Ind->push_back((xPos +xSq)* info.HMh + yPos    );
					
				info.Ind->push_back(xPos       * info.HMh + (yPos +ySq) );
				info.Ind->push_back((xPos +xSq)* info.HMh + (yPos +ySq) );
			}
			else {
				if(first)
					info.Ind->push_back((xPos +xSq)* info.HMh + (yPos +ySq) );
					
				info.Ind->push_back(xPos       * info.HMh + yPos        );
				info.Ind->push_back((xPos +xSq)* info.HMh + yPos        );
			}
		}
		
		void TerrainChunk::draw() {
			glDrawElements(GL_TRIANGLE_STRIP, mSize, GL_UNSIGNED_INT, BUFFER_OFFSET( mBeginning * sizeof(unsigned int) ));
		}
		
	};
    
};
