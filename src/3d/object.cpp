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

#include <SRL/Object.hpp>
#include <SRL/3d/object.hpp>
#include <SRL/3d/mesh.hpp>

namespace srl {
	
	namespace d3 {
		
		Object::Object(srl::Object* object) {
			mGlobalObject = object;
			mMesh = NULL;
			mScale = vec3(1.0, 1.0, 1.0);
		}
		
		Object::~Object() {
		
		}
		
		void Object::setCubeMesh(float size) {
			mScale = vec3(size, size, size);
			mMesh = Mesh::getBoxMesh();
		}
		void Object::setBoxMesh(vec3 size) {
			mScale = size;
			mMesh = Mesh::getBoxMesh();
		}
		
		void Object::setMesh(IMesh* mesh) {
			mMesh = mesh;
		}
		
		IMesh* Object::getMesh() {
			return mMesh;
		}
		
		
		void Object::draw() {
			srlCheckPtr(mMesh);
			//mGlobalObject->getPosition(), mGlobalObject->getRotation(), mScale
			mMesh->draw();
		}
	
	};
	
};