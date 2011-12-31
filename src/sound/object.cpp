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

#include <SRL/sound/object.hpp>
#include <SRL/Object.hpp>

namespace srl {
	
	namespace sound {
		
		/*irrklang::ISoundEngine* mEngine = NULL;
		
		void initIrrKlangEngine() {
			int currentTry = 0;
			while(mEngine == 0 && currentTry != 3) {
				mEngine = irrklang::createIrrKlangDevice();
			}
		}*/
		
		
		Object::Object(srl::Object* object) {
			//initIrrKlangEngine();
			
			mGlobalObject = object;
			//mSoundSource = NULL;
		}
		
		Object::~Object() {
		
		}
	
	};
	
};