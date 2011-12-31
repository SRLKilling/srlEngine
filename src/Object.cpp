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

#include <SRL/Object.hpp>

namespace srl {

	Object::Object(Scene* scene) {
		mScene = scene;
		//mSoundObject = new sound::Object(this);
		m3dObject = new d3::Object(this);
	}
	
	Object::~Object() {
		
	}
	
	
	void Object::setPosition(vec3 position) {
		mPosition = position;
	}
	
	void Object::setRotation(vec3 rotation) {
		mRotation = rotation;
	}
	
	vec3 Object::getPosition() {
		return mPosition;
	}
	
	vec3 Object::getRotation() {
		return mRotation;
	}
	
	
	/*sound::Object* Object::sound() {
		return mSoundObject;
	}*/
	
	d3::Object* Object::d3() {
		return m3dObject;
	}
	
	
	
	void Object::draw() {
		m3dObject->draw();
	}
	
};