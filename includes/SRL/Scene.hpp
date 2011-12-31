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
#ifndef srlHeaderScene
#define srlHeaderScene

#include <SRL/Environment.hpp>

#include <map>
#include <string>
#include <SRL/Object.hpp>
#include <SRL/rublyb.hpp>

namespace srl {

	class SRLAPI Scene {
		public:
			Scene();
			~Scene();
			void clearScene();
			
			srl::Object* addStaticObject(std::string name);
			srl::Object* addDynamicObject(std::string name);
			srl::Object* getObject(std::string name);
			void removeObject(srl::Object* object);
			void removeObject(std::string name);
			
			void draw();
			
			vec2 getVec2FromRuby(std::string name);
			vec3 getVec3FromRuby(std::string name);
			
		private:
			std::map<std::string, srl::Object*> mStaticObjects;
			
	};
	
};

#endif
