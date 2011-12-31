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
#ifndef srlHeaderObject
#define srlHeaderObject

#include <SRL/environment.hpp>


#include <SRL/sound/object.hpp>
#include <SRL/3d/object.hpp>
#include <SRL/maths/vec3.hpp>

namespace srl {

	class Scene;
	
	class SRLAPI Object {
		public:
			void setPosition(vec3 position);
			void setRotation(vec3 rotation);
			vec3 getPosition();
			vec3 getRotation();
			
			//sound::Object* sound();
			d3::Object* d3();
			
			void draw();
			
			
		private:
			Object(Scene* scene);
			~Object();
			
			Scene* mScene;
			vec3 mPosition;
			vec3 mRotation;
			
			//sound::Object* mSoundObject;
			d3::Object* m3dObject;
			
		friend class Scene;
	};
	
};

#endif