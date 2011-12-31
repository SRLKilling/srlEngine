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

#include <SRL/windowing/windowX.hpp>
#include <stdio.h>
#include <stdlib.h>

namespace srl {
	
	namespace win {
	
		Display* Window::mDisplay = NULL;
		std::vector< Window* > Window::mWindowList;
		
		Window::Window() {
			if(mDisplay == NULL)
				mDisplay = XOpenDisplay(NULL);
			mWindowList.push_back(this);
			
			mVisual.visual = DefaultVisual(mDisplay, 0);
			mVisual.depth = DefaultDepth(mDisplay, 0);
			mVisual.screen = DefaultScreen(mDisplay);

			mAttributes.background_pixel = XWhitePixel(mDisplay, 0);
			mWindow = XCreateWindow(mDisplay, XRootWindow(mDisplay, 0), 0, 0, 800, 600, 5, mVisual.depth, InputOutput,  mVisual.visual, CWBackPixel, &mAttributes);

			XSelectInput(mDisplay, mWindow, FocusChangeMask | ButtonPressMask | ButtonReleaseMask | ButtonMotionMask |
														PointerMotionMask | KeyPressMask | KeyReleaseMask | StructureNotifyMask |
														EnterWindowMask | LeaveWindowMask);
			XMapWindow(mDisplay, mWindow);

			mAtom = XInternAtom(mDisplay, "WM_DELETE_WINDOW", false);
			XSetWMProtocols(mDisplay, mWindow, &mAtom, 1);
			
			mDestroyed = false;
			
			//XFlush(mDisplay);

			mContext = new gl::glxContext(mDisplay);
			mContext->Create(srl::Env::Ver_1_5, true, 0, &mVisual);
			mContext->MakeCurrent(mWindow);
			mContext->makeCurrent();
		}

		Window::~Window() {
			delete mContext;
			
		}
		
		
		void Window::processEventQueues() {
			int queueSize = XPending(mDisplay);
			for(int i = 0; i < queueSize; i++) {
				XEvent* event = new XEvent();
				XNextEvent(mDisplay, event);
				for(std::vector<Window*>::iterator it = mWindowList.begin(); it != mWindowList.end(); ++it) {
					if((*it)->mWindow == event->xany.window) {
						(*it)->addXEventToQueue(event);
						break;
					}
				}
			}
		}
		
		void Window::addXEventToQueue(XEvent* xevent) {
			Event event;
			
			if(xevent->type == ClientMessage) {
				if((xevent->xclient.format == 32) && (xevent->xclient.data.l[0]) == static_cast<long>(mAtom))
					event.mType = Event::Quit;
			}

			else if(xevent->type == DestroyNotify) {
				event.mType = Event::Destroyed;
				mDestroyed = true;
			}

			// Others
		   /*else {
				mEvent.mType = toEventType(mXEvent.type);
			}

			if(mEvent.mInputs) {
				/*if(mXEvent.type == KeyPress)
					mEvent.mSenderState[ toEventSenderKey( XLookupKeysym(&mXEvent.xkey, 0)) ] = true;
				else if(mXEvent.type == KeyRelease)
					mEvent.mSenderState[ toEventSenderKey( XLookupKeysym(&mXEvent.xkey, 0)) ] = false;

				if(mXEvent.type == ButtonPress)
					mEvent.mSenderState[ toEventSenderButton( mXEvent.xbutton.button ) ] = true;

				else if(mXEvent.type == ButtonRelease)
					mEvent.mSenderState[ toEventSenderButton( mXEvent.xbutton.button ) ] = false;*/

			//}
			
			mEventQueue.push(event);
			delete xevent;
		}
		
		bool Window::getEvent(Event& event) {
			if(mEventQueue.empty())
				return false;
			
			event = mEventQueue.front();
			mEventQueue.pop();
			return true;
		}
		
		
		bool Window::isRunning() {
			return !mDestroyed;
		}
		
		/*gui::Event* Window::getEvent() {
			//computeEvent();
			//return &mEvent;
		}

		gui::Event* Window::getEventWithoutComputing() {
			//return &mEvent;
		}

		void XWindow::computeEvent() {
			//XNextEvent(mDisplay, &mXEvent);

			// Close Event
			/*if(mXEvent.type == ClientMessage) {
				if((mXEvent.xclient.format == 32) && (mXEvent.xclient.data.l[0]) == static_cast<long>(mAtom))
					mEvent.mType = Event::Quit;
			}

			// Destroy Event
			else if(mXEvent.type == DestroyNotify) {
				mEvent.mType = Event::Destroyed;
			}

			// Others
			else {
				mEvent.mType = toEventType(mXEvent.type);
			}

			if(mEvent.mInputs) {
				/*if(mXEvent.type == KeyPress)
					mEvent.mSenderState[ toEventSenderKey( XLookupKeysym(&mXEvent.xkey, 0)) ] = true;
				else if(mXEvent.type == KeyRelease)
					mEvent.mSenderState[ toEventSenderKey( XLookupKeysym(&mXEvent.xkey, 0)) ] = false;

				if(mXEvent.type == ButtonPress)
					mEvent.mSenderState[ toEventSenderButton( mXEvent.xbutton.button ) ] = true;

				else if(mXEvent.type == ButtonRelease)
					mEvent.mSenderState[ toEventSenderButton( mXEvent.xbutton.button ) ] = false;*/

			//}
		//}

		void Window::destroy() {
			XDestroyWindow(mDisplay, mWindow);
		}


		/*int Window::toEventType(int i) {
			static int mType[] = {0, 0, // Reserved
				0, // KeyPress
				1, // KeyRelease
				2, // ButtonPress
				3, // ButtonRelease
				4, // MotionNotify
				5, // EnterNotify
				6, // LeaveNotify
				7, // FocusIn
				8, // FocusOut
				0, // KeymapNotify
				0, // Expose
				0, // GraphicsExpose
				0, // NoExpose
				0, // VisibilityNotify
				0, // CreateNotify
				11, // DestroyNotify
				0, // UnmapNotify
				0, // MapNotify
				0, // MapRequest
				0, // ReparentNotify
				0, // ConfigureNotify
				0, // ConfigureRequest
				0, // GravityNotify
				0, // ResizeRequest
				0, // CirculateNotify
				0, // CirculateRequest
				0, // PropertyNotify
				0, // SelectionClear
				0, // SelectionRequest
				0, // SelectionNotify
				0, // ColormapNotify
				0, // ClientMessage
				0, // MappinfNotify
				0, // GenericEvent
				0, // LASTEvent
			};

			return mType[i];
		}


		bool Window::created() {
			return mCreated;
		}*/
		
		void Window::display() {
			glXSwapBuffers(mDisplay, mWindow);
		}
		
	};
	
};
