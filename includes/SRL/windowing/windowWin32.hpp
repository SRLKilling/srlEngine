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


#ifndef DefineHeaderWinWindow
#define DefineHeaderWinWindow

#include <SRL/Environment.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <SRL/opengl/context.hpp>
#include <SRL/windowing/event.hpp>
#include <SRL/maths/irect.hpp>
#include <SRL/maths/ivec2.hpp>
#include <string>
#include <queue>

namespace srl {

	namespace win {
	
		class SRLAPI Window {
			public:
				Window();
				~Window();
				
				HWND getHandle();
				
				void create();
				void destroy();
					
				void display();
				bool isRunning();
				
				irect getRect();
				ivec2 getMousePos();
				
				void processEventLoop();
				bool getEvent(Event* event);
				Event::Sender getSenderFromVK(WPARAM key, LPARAM flags);
				
				void setCursorVisible(bool visible);
				void setCursor(std::string path);
				
				
			protected:
				static bool registerWinClass();
				static bool unicodeSupported();
				static LRESULT CALLBACK globalCallback(HWND handle, UINT message, WPARAM wparam, LPARAM lparam);
				void processEvent(UINT message, WPARAM wparam, LPARAM lparam);
				
				bool mWindowState;
				HWND mWindowHandle;
				HCURSOR mCursor;
				irect mRect;
				ivec2 mMouse;
				
				gl::Context* mContext;
				
				std::queue<Event> mEvents;
		};
    
	};
	
};

#endif
