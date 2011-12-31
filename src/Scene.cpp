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

#include <fstream>
#include <SRL/Scene.hpp>

namespace srl {

	Scene::Scene() {
	}
	
	Scene::~Scene() {
		clearScene();
	}
	
	
	srl::Object* Scene::addStaticObject(std::string name) {
		srl::Object* object = new srl::Object(this);
		mStaticObjects.insert( std::make_pair(name, object) );
		return object;
	}
	
	srl::Object* Scene::getObject(std::string name) {
		std::map<std::string, srl::Object*>::iterator it = mStaticObjects.find(name);
		if(it != mStaticObjects.end())
			return it->second;
	}
	
	void Scene::removeObject(std::string name) {
		mStaticObjects.erase( mStaticObjects.find(name) );
	}
	
		
	void Scene::clearScene() {
		mStaticObjects.clear();
	}
	
	
	void Scene::draw() {
		srlMapForeach(std::string, srl::Object*, object, mStaticObjects)
			object->draw();
		}
	}
	
};