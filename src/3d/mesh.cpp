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
#include <SRL/Environment.hpp>
#include <SRL/3d/mesh.hpp>

namespace srl {
	
	namespace d3 {
		
		Mesh::Mesh() {
			mVbo = NULL;
			mIbo = NULL;
		}
		
		Mesh::~Mesh() {
			if(mVbo)
				delete mVbo;
			if(mIbo)
				delete mIbo;
		}
		
		Mesh* Mesh::getBoxMesh() {
			static Mesh* mBox = NULL;
			srlReturnPtr(mBox);
			
			mBox = new Mesh();
			
			float vertices[] = {
				0.0, 0.0, 0.0,
				1.0, 0.0, 0.0,
				0.0, 1.0, 0.0,
				0.0, 0.0, 1.0,
				1.0, 1.0, 0.0,
				1.0, 0.0, 1.0,
				0.0, 1.0, 1.0,
				1.0, 1.0, 1.0};
				
			unsigned int indices[] = {
				0, 1, 2,
				1, 2, 4,
				0, 1, 3,
				1, 3, 5,
				0, 2, 3,
				2, 3, 6,
				1, 4, 5,
				4, 5, 7,
				2, 4, 6,
				4, 6, 7,
				3, 5, 6,
				5, 6, 7};
			
			mBox->mVbo = new gl::VertexBuffer();
			mBox->mVbo->bind();
			mBox->mVbo->alloc(8 * 3);
			mBox->mVbo->sendData(0, vertices, 8 * 3);
			mBox->mIbo = new gl::IndexBuffer();
			mBox->mIbo->bind();
			mBox->mIbo->alloc(36);
			mBox->mIbo->sendData(0, indices, 36);
			
			return mBox;
		}
		
		Mesh* Mesh::getSquareMesh() {
			static Mesh* mSquare = NULL;
			srlReturnPtr(mSquare);
			
			mSquare = new Mesh();
		
			float vertices[] = {
				0.0, 0.0, 0.0,
				0.0, 1.0, 0.0,
				1.0, 1.0, 0.0,
				0.0, 0.0, 0.0,
				1.0, 1.0, 0.0,
				1.0, 0.0, 0.0
			};
			
			mSquare->mVbo = new gl::VertexBuffer();
			mSquare->mVbo->bind();
			mSquare->mVbo->alloc(18);
			mSquare->mVbo->sendData(0, vertices, 18);
			mSquare->mVbo->unbind();
			
			return mSquare;
		}
		
		void Mesh::draw() {
			/*glPushMatrix();
				glTranslatef(position.x, position.y, position.z);
				//glRotatef(rotation.x, rotation.y, rotation.z);
				glScalef(scale.x, scale.y, scale.z);*/
				glColor3f(1.0, 1.0, 1.0);
				mVbo->bind();
				mVbo->sendVertexAttribPointer(0, 3);
				if(mIbo)mIbo->bind();
				//glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, BUFFER_OFFSET( 0 ));
				glDrawArrays(GL_TRIANGLES, 0, 18);
				mVbo->unbind();
				if(mIbo)mIbo->unbind();
			//glPopMatrix();
		}
		
	};
	
};