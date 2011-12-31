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

#include <SRL/windowing/windowWin32.hpp>
#include <SRL/opengl/wglContext.hpp>

namespace srl {

	namespace win {
	
		Window::Window() {
			mWindowState = false;
			mRect = irect(0, 0, 800, 600);
			mCursor = LoadCursor(NULL, IDC_ARROW);
			create();
		}
		
		Window::~Window() {
			destroy();
		}
		
		
		HWND Window::getHandle() {
			return mWindowHandle;
		}
		
		void Window::create() {
			if(!registerWinClass())
				printf("Couldn't create window class\n");
			
			if(unicodeSupported())
				mWindowHandle = CreateWindowW( L"srlWindow" , L"", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, mRect.w, mRect.h, NULL, NULL, GetModuleHandle(NULL), this);
			else
				mWindowHandle = CreateWindowA( "srlWindow"  ,  "", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, mRect.w, mRect.h, NULL, NULL, GetModuleHandle(NULL), this);
			
			ShowWindow(mWindowHandle, SW_SHOW);
			UpdateWindow(mWindowHandle);
			
			mWindowState = true;
			mContext = new gl::wglContext(mWindowHandle);
		}
		
		void Window::destroy() {
			mWindowState = false;
			DestroyWindow(mWindowHandle);
		}
		
		
		void Window::display() {
			mContext->swap();
		}
		
		bool Window::isRunning() {
			return mWindowState ? true: false;
		}
		
		
		void Window::processEventLoop() {
			MSG Message;
			while (PeekMessage(&Message, mWindowHandle, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
		}
		
		void Window::processEvent(UINT message, WPARAM wparam, LPARAM lparam) {
			if(mWindowHandle == NULL)
				return;
			
			switch(message) {
					
				case WM_DESTROY :
					break;
		
				case WM_SETCURSOR :
					if(LOWORD(lparam) == HTCLIENT)
						SetCursor(mCursor);
					break;
		
				case WM_CLOSE : {
					Event event(mMouse, Event::Quit, Event::CloseButton);
					mEvents.push(event);
					break;
				}
		
				case WM_SIZE : {
					
					RECT Rect;
					GetClientRect(mWindowHandle, &Rect);
					mRect.x = Rect.left;                mRect.y = Rect.top;
					mRect.w = Rect.right - Rect.left;   mRect.h = Rect.bottom - Rect.top;
					
					Event event(mMouse, Event::WindowResized);
					mEvents.push(event);
					break;
				}
		
				// Gain focus event
				case WM_SETFOCUS :
					break;
		
				// Lost focus event
				case WM_KILLFOCUS :
					break;
		
				// Text event
				case WM_CHAR : {
					Event event(mMouse, Event::CharacterEvent);
					event.mCharacter = wparam;
					mEvents.push(event);
					break;
				}
		
				// Keydown event
				case WM_KEYDOWN :
				case WM_SYSKEYDOWN : {
					Event event(mMouse, Event::KeyPressed);
					mEvents.push(event);
					break;
				}
		
				// Keyup event
				case WM_KEYUP :
				case WM_SYSKEYUP :
					break;
		
				// Mouse wheel event
				case WM_MOUSEWHEEL :
					break;
		
				// Mouse left button down event
				case WM_LBUTTONDOWN : {
					Event event(mMouse, Event::MouseButtonPressed, Event::LeftButton);
					mEvents.push(event);
					break;
				}
		
				// Mouse left button up event
				case WM_LBUTTONUP : {
					Event event(mMouse, Event::MouseButtonReleased, Event::LeftButton);
					mEvents.push(event);
					break;
				}
		
				// Mouse right button down event
				case WM_RBUTTONDOWN : {
					Event event(mMouse, Event::MouseButtonPressed, Event::RightButton);
					mEvents.push(event);
					break;
				}
		
				// Mouse right button up event
				case WM_RBUTTONUP : {
					Event event(mMouse, Event::MouseButtonReleased, Event::RightButton);
					mEvents.push(event);
					break;
				}
		
				// Mouse wheel button down event
				case WM_MBUTTONDOWN : {
					Event event(mMouse, Event::MouseButtonPressed, Event::MiddleButton);
					mEvents.push(event);
					break;
				}
		
				// Mouse wheel button up event
				case WM_MBUTTONUP : {
					Event event(mMouse, Event::MouseButtonReleased, Event::MiddleButton);
					mEvents.push(event);
					break;
				}
		
				// Mouse X button down event
				/*case WM_XBUTTONDOWN :
					printf("XButtonDown\n");
					break;
		
				// Mouse X button up event
				case WM_XBUTTONUP :
					printf("XButtonUp\n");
					break;*/
		
				// Mouse move event
				case WM_MOUSEMOVE : {
					mMouse.x = LOWORD(lparam);
					mMouse.y = HIWORD(lparam);
					
					Event event(mMouse, Event::MouseMoved);
					mEvents.push(event);
					break;
				}
		
				// Mouse leave event
				case WM_MOUSELEAVE :
					break;
					
			}
		}
		
		bool Window::getEvent(Event* event) {
			if(mEvents.empty())
				processEventLoop();
				
			if(!mEvents.empty()) {
				*event = mEvents.front();
				mEvents.pop();
				return true;
			}
			
			return false;
		}
		
		
		
		irect Window::getRect() {
			return mRect;
		}
		
		ivec2 Window::getMousePos() {
			return mMouse;
		}
		
		
		void Window::setCursorVisible(bool visible) {
			if(visible)
				mCursor = LoadCursor(NULL, IDC_ARROW);
			else
				mCursor = NULL;
				
			SetCursor(mCursor);
		}
		
		void Window::setCursor(std::string path) {
			mCursor = LoadCursorFromFile(path.c_str());
		}
		
		
		Event::Sender Window::getSenderFromVK(WPARAM key, LPARAM flags) {
			/*switch (key) {
				case VK_MENU :       return (flags & (1 << 24)) ? Event::RightAlt     : Event::LeftAlt;
				case VK_CONTROL :    return (flags & (1 << 24)) ? Event::RightControl : Event::LeftControl;
				case VK_LWIN :       return Event::LSystem;
				case VK_RWIN :       return Event::RSystem;
				case VK_APPS :       return Event::Menu;
				case VK_OEM_1 :      return Event::SemiColon;
				case VK_OEM_2 :      return Event::Slash;
				case VK_OEM_PLUS :   return Event::Equal;
				case VK_OEM_MINUS :  return Event::Dash;
				case VK_OEM_4 :      return Event::LBracket;
				case VK_OEM_6 :      return Event::RBracket;
				case VK_OEM_COMMA :  return Event::Comma;
				case VK_OEM_PERIOD : return Event::Period;
				case VK_OEM_7 :      return Event::Quote;
				case VK_OEM_5 :      return Event::BackSlash;
				case VK_OEM_3 :      return Event::Tilde;
				case VK_ESCAPE :     return Event::Escape;
				case VK_SPACE :      return Event::Space;
				case VK_RETURN :     return Event::Return;
				case VK_BACK :       return Event::Back;
				case VK_TAB :        return Event::Tab;
				case VK_PRIOR :      return Event::PageUp;
				case VK_NEXT :       return Event::PageDown;
				case VK_END :        return Event::End;
				case VK_HOME :       return Event::Home;
				case VK_INSERT :     return Event::Insert;
				case VK_DELETE :     return Event::Delete;
				case VK_ADD :        return Event::Add;
				case VK_SUBTRACT :   return Event::Subtract;
				case VK_MULTIPLY :   return Event::Multiply;
				case VK_DIVIDE :     return Event::Divide;
				case VK_PAUSE :      return Event::Pause;
				case VK_F1 :         return Event::F1;
				case VK_F2 :         return Event::F2;
				case VK_F3 :         return Event::F3;
				case VK_F4 :         return Event::F4;
				case VK_F5 :         return Event::F5;
				case VK_F6 :         return Event::F6;
				case VK_F7 :         return Event::F7;
				case VK_F8 :         return Event::F8;
				case VK_F9 :         return Event::F9;
				case VK_F10 :        return Event::F10;
				case VK_F11 :        return Event::F11;
				case VK_F12 :        return Event::F12;
				case VK_F13 :        return Event::F13;
				case VK_F14 :        return Event::F14;
				case VK_F15 :        return Event::F15;
				case VK_LEFT :       return Event::Left;
				case VK_RIGHT :      return Event::Right;
				case VK_UP :         return Event::Up;
				case VK_DOWN :       return Event::Down;
				case VK_NUMPAD0 :    return Event::Numpad0;
				case VK_NUMPAD1 :    return Event::Numpad1;
				case VK_NUMPAD2 :    return Event::Numpad2;
				case VK_NUMPAD3 :    return Event::Numpad3;
				case VK_NUMPAD4 :    return Event::Numpad4;
				case VK_NUMPAD5 :    return Event::Numpad5;
				case VK_NUMPAD6 :    return Event::Numpad6;
				case VK_NUMPAD7 :    return Event::Numpad7;
				case VK_NUMPAD8 :    return Event::Numpad8;
				case VK_NUMPAD9 :    return Event::Numpad9;
				case 'A' :           return Event::A;
				case 'Z' :           return Event::Z;
				case 'E' :           return Event::E;
				case 'R' :           return Event::R;
				case 'T' :           return Event::T;
				case 'Y' :           return Event::Y;
				case 'U' :           return Event::U;
				case 'I' :           return Event::I;
				case 'O' :           return Event::O;
				case 'P' :           return Event::P;
				case 'Q' :           return Event::Q;
				case 'S' :           return Event::S;
				case 'D' :           return Event::D;
				case 'F' :           return Event::F;
				case 'G' :           return Event::G;
				case 'H' :           return Event::H;
				case 'J' :           return Event::J;
				case 'K' :           return Event::K;
				case 'L' :           return Event::L;
				case 'M' :           return Event::M;
				case 'W' :           return Event::W;
				case 'X' :           return Event::X;
				case 'C' :           return Event::C;
				case 'V' :           return Event::V;
				case 'B' :           return Event::B;
				case 'N' :           return Event::N;
				case '0' :           return Event::Num0;
				case '1' :           return Event::Num1;
				case '2' :           return Event::Num2;
				case '3' :           return Event::Num3;
				case '4' :           return Event::Num4;
				case '5' :           return Event::Num5;
				case '6' :           return Event::Num6;
				case '7' :           return Event::Num7;
				case '8' :           return Event::Num8;
				case '9' :           return Event::Num9;
			}*/
			
			return Event::NoSender;
		}
		
		
		
		
		
		
		
		bool Window::registerWinClass() {
			static bool classDefined = false;
			
			if(classDefined)
				return true;
			
			if(unicodeSupported()) {
				WNDCLASSW WindowClass;
				WindowClass.style         = 0;
				WindowClass.lpfnWndProc   = &Window::globalCallback;
				WindowClass.cbClsExtra    = 0;
				WindowClass.cbWndExtra    = 0;
				WindowClass.hInstance     = GetModuleHandle(NULL);
				WindowClass.hIcon         = NULL;
				WindowClass.hCursor       = 0;
				WindowClass.hbrBackground = 0;
				WindowClass.lpszMenuName  = NULL;
				WindowClass.lpszClassName = L"srlWindow";
				if(!RegisterClassW(&WindowClass))
					return false;
			}
			else {
				WNDCLASSA WindowClass;
				WindowClass.style         = 0;
				WindowClass.lpfnWndProc   = &Window::globalCallback;
				WindowClass.cbClsExtra    = 0;
				WindowClass.cbWndExtra    = 0;
				WindowClass.hInstance     = GetModuleHandle(NULL);
				WindowClass.hIcon         = NULL;
				WindowClass.hCursor       = 0;
				WindowClass.hbrBackground = 0;
				WindowClass.lpszMenuName  = NULL;
				WindowClass.lpszClassName = "srlWindow";
				if(!RegisterClassA(&WindowClass))
					return false;
			}
			return true;
		}
		
		
		
		bool Window::unicodeSupported() {
			static bool alreadyKnown = false;
			static bool Unicode = false;
			
			if(alreadyKnown)
				return Unicode;
			
			OSVERSIONINFO VersionInfo;
			ZeroMemory(&VersionInfo, sizeof(VersionInfo));
			VersionInfo.dwOSVersionInfoSize = sizeof(VersionInfo);
		
			if (GetVersionEx(&VersionInfo))
				Unicode = ( VersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT );
				
			alreadyKnown = true;
			return Unicode;
		}
		
		
		
		LRESULT CALLBACK Window::globalCallback(HWND handle, UINT message, WPARAM wparam, LPARAM lparam) {
			if(message == WM_CREATE) {
				long This = reinterpret_cast<long>(reinterpret_cast<CREATESTRUCT*>(lparam)->lpCreateParams);
				SetWindowLongPtr(handle, GWLP_USERDATA, This);
			}
			
			Window* win = reinterpret_cast<Window*>(GetWindowLongPtr(handle, GWLP_USERDATA));
			if(win) {
				win->processEvent(message, wparam, lparam);
				/*if (Window->myCallback)
					return CallWindowProc(reinterpret_cast<WNDPROC>(Window->myCallback), Handle, Message, WParam, LParam);*/
			}
			
			if (message == WM_CLOSE)
				return 0;
			
			return unicodeSupported() ? DefWindowProcW(handle, message, wparam, lparam) :
										DefWindowProcA(handle, message, wparam, lparam);
		}
		
	};
    
};
