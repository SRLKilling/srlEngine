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

#include <SRL/OpenGL/Context.hpp>
#include <SRL/3d/terrainQuadtree.hpp>
//#include <SRL/3d/Frustum.hpp>

namespace srl {

	namespace d3 {

		QuadTerrainNode::QuadTerrainNode(QuadTerrainNode* parent, int depth) {
			mParent = parent;
			mChildren = 0;
			mChunk = 0;
			mDepth = depth;
		}
		
		QuadTerrainNode::~QuadTerrainNode() {
			destroy();
		}
		
		
		void QuadTerrainNode::build(int x, int y, int w, int h, int minSize, ChunkInfo chunkInfo) {
			mChunk = new TerrainChunk();
			mChunk->load(x, y, w, h, chunkInfo);
			
			if(mDepth +1 >= minSize)
				return;
			
			int positions[] = {x,       y,
							   x + w/2, y,
							   x + w/2, y + h/2,
							   x,       y + h/2};
			
			//mBox.setMin( srl::Vector<float>(x, 0, y));
			//mBox.setMax( srl::Vector<float>(x+w, 255, y+h));
			
			
			mChildren = new QuadTerrainNode*[4];
			for(int i = 0; i < 4; i++) {
				mChildren[i] = new QuadTerrainNode(this, mDepth +1);
				mChildren[i]->build(positions[i*2], positions[i*2 +1], w/2, h/2, minSize, chunkInfo);
			}
				
		}
				
		void QuadTerrainNode::destroy() {
			if(mChunk != 0)
				delete mChunk;
				
			if(mChildren != 0);
				delete[] mChildren;
		}
		
		void QuadTerrainNode::draw() {
			/*if(mBox.inFrustum() != 1)
				return;*/
				
			//float distanceToCam = (srl::Context::getCurrent()->getEyePos() - mBox.getCenter()).length();
				
			if(mChildren == 0){// || distanceToCam > 1000 - mDepth*100) {
				mChunk->draw();
			}
			else {
				for(int i = 0; i < 4; i++)
					mChildren[i]->draw();
			}
		}
		
	};
    
};
