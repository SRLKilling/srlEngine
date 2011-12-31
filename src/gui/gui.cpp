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

#include <SRL/gui/gui.hpp>

namespace srl {

	namespace gui {
		
		GUI::GUI(win::Window* win) {
			mProgram = NULL;
			mWindow = win;
			mRect = mWindow->getRect();
			gl::Context::getCurrent()->resizeViewport(mRect.w, mRect.h);
			gl::Context::getCurrent()->setOrthogonalProj(0.0, (float)mRect.w, 0.0, (float)mRect.h, -1.0, 1.0);
		}
		
		void GUI::setProgram(gl::Program* program) {
			mProgram = program;
		}
		
		gl::Program* GUI::getProgram() {
			return mProgram;
		}
		
		void GUI::addWindow(gui::Window* window) {
			mWindowList.push_front(window);
			window->mInternalRect = irect(mRect.w/4, mRect.h/4, mRect.w/2, mRect.h/2);
		}
		
		void GUI::eventProcessing(win::Event event) {
			if(event.mType == win::Event::WindowResized && mRect != mWindow->getRect()) {
				mRect = mWindow->getRect();
				gl::Context::getCurrent()->resizeViewport(mRect.w, mRect.h);
				gl::Context::getCurrent()->setOrthogonalProj(0.0, (float)mRect.w, 0.0, (float)mRect.h, -1.0, 1.0);
			}
			for(std::list<gui::Window*>::iterator it = mWindowList.begin(); it != mWindowList.end(); ++it) {
				(*it)->eventHandler(event);
			}
		}
		
		void GUI::render() {
			mProgram->use();
			gl::Context::getCurrent()->useOrthogonal();
			gl::Context::getCurrent()->setModelviewMatrix(mat4::identity());
			gl::Context::getCurrent()->translate(0.0, mRect.h, 0.0);
			gl::Context::getCurrent()->scale(1.0, -1.0, 1.0);
			
			for(std::list<gui::Window*>::iterator it = mWindowList.begin(); it != mWindowList.end(); ++it) {
				(*it)->render();
			}
			// mProgram->unuse();
		}
		
	};
	
};

