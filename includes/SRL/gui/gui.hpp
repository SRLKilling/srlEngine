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
#ifndef srlHeaderGUI
#define srlHeaderGUI

#include <SRL/Environment.hpp>
#include <SRL/windowing/window.hpp>
#include <SRL/opengl/program.hpp>
#include <SRL/gui/baseContainer.hpp>
#include <SRL/gui/window.hpp>
#include <SRL/gui/button.hpp>
#include <SRL/gui/hlayout.hpp>
#include <list>

namespace srl {

	namespace gui {
	
		class GUI {
			public:
				GUI(win::Window* win);
				~GUI();
				
				void setProgram(gl::Program* program);
				gl::Program* getProgram();
				
				void addWindow(gui::Window* window);
				
				void eventProcessing(win::Event event);
				void render();
				
			private:
				irect mRect;
				gl::Program* mProgram;
				win::Window* mWindow;
				std::list<gui::Window*> mWindowList;
		};
	
	};
	
};

#endif
