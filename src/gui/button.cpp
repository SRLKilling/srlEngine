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

#include <SRL/gui/button.hpp>
#include <stdio.h>

namespace srl {

	namespace gui {
	
		Button::Button(std::string text) : BaseElement(ButtonType) {
		
		}
		
		Button::~Button() {
		
		}
		
		void Button::eventHandler(win::Event event) {
			printf("Event on button !\n");
		}
		
		void Button::render() {
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_QUADS);
				glVertex2f(mInternalRect.x+10.0, mInternalRect.y+10.0);
				glVertex2f(mInternalRect.x+10.0, mInternalRect.h-10.0);
				glVertex2f(mInternalRect.w-10.0, mInternalRect.h-10.0);
				glVertex2f(mInternalRect.w-10.0, mInternalRect.y+10.0);
			glEnd();
		}
	
	};

};