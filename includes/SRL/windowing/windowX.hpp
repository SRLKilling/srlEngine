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


#ifndef DefineHeaderXWindow
#define DefineHeaderXWindow
#include <SRL/environment.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <SRL/windowing/event.hpp>
#include <SRL/opengl/glxContext.hpp>
#include <SRL/maths/irect.hpp>
#include <vector>
#include <queue>

namespace srl {

	namespace win {
	
		class SRLAPI Window {
			public:
				Window();
				~Window();
				
				bool getEvent(Event& event);
			
				void destroy();
				bool isRunning();
			
				void display();
			
			private:
				XVisualInfo mVisual;

				::Window mWindow;
				Atom mAtom;
				XSetWindowAttributes mAttributes;
				
				bool mDestroyed;
				irect mRect;

				gl::glxContext* mContext;
				
				void addXEventToQueue(XEvent* xevent);
				std::queue< Event > mEventQueue;
			
			public : static void processEventQueues();
			private : static std::vector< Window* > mWindowList;
					  static Display* mDisplay;
		};
	
	};

};

#endif
