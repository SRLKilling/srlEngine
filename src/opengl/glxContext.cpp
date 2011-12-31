/*************************************************************************************
*                                  SRL ENGINE                                        *
*                                                                                    *
*                                                                                    *
*  File : Log.h                                                                      *
*  Author: SRL Killing                                                               *
*  Date: 25/02/10 20:30                                                              *
*  Description:                                                                      *
*                                                                                    *  
*  Licence :  LGPL                                                                   *
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

#include <SRL/opengl/glxContext.hpp>
#include <stdio.h>

namespace srl { 
    
	namespace gl {

		glxContext::glxContext(::Display* display) {
			mDisplay = display;
		}
		glxContext::~glxContext() {
			destroy();
		}
		void glxContext::Create(Env::ContextOpenGLVersion version, bool direct, int screen, XVisualInfo* visual) {
			
			int attrib[] = {GLX_RGBA, GLX_RED_SIZE, 4, GLX_GREEN_SIZE, 4, GLX_BLUE_SIZE, 4, None};
			
			XVisualInfo* visuali = glXChooseVisual(mDisplay, DefaultScreen(mDisplay), attrib);
			
			mContext = glXCreateContext(mDisplay, visuali, 0, True);
			
			// Array storing number of disponible openGL versions
			/*int minorVersionArray[] = {
				// 1.x
			-1,      5, 4, 3, 21, 2, 1, 0,
				// 2.x
			-1,      1, 0,
				// 3.x
			-1,      3, 2, 1, 0,
				// 4.x
			-1,      1, 0,
				
			};
			int majorVersion;
			int minorVersionIndex = version;

			//Find major version
			if(version < 8)
				majorVersion = 1;
			else if(version < 11)
				majorVersion = 2;
			else if(version < 16)
				majorVersion = 3;
			else if(version < 19)
				majorVersion = 4;

			// If screen == -1, then set the screen id to the default screen
			if(screen == -1)
				screen = DefaultScreen(mDisplay);

			// If user want a 3.0, or greater, context
			if(majorVersion >= 3) {
				
				const GLubyte* name = (const GLubyte*)"glXCreateContextAttribsARB";
				PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribs = reinterpret_cast<PFNGLXCREATECONTEXTATTRIBSARBPROC>(glXGetProcAddress((const GLubyte*)"glXCreateContextAttribsARB"));
				
				if(glXCreateContextAttribs == NULL)
				return;//Log::Error() << "Failed to get glXCreateContextAttribs pointer to implement an 3.0 openGL context with GLX" << srl::endl;
				else {
				int nbConfigs = 0;
				GLXFBConfig* fbconf = glXChooseFBConfig(mDisplay, screen, NULL, &nbConfigs);
				while(majorVersion >= 3) {
					
					/*int attributes[] = {
					GLX_CONTEXT_MAJOR_VERSION_ARB, majorVersion,
					GLX_CONTEXT_MINOR_VERSION_ARB, minorVersionArray[minorVersionIndex],
					0, 0
					};*/
					
					/*int attributes[] = {
					GLX_CONTEXT_MAJOR_VERSION_ARB, 1,
					GLX_CONTEXT_MINOR_VERSION_ARB, 1,
					0, 0
					}; 
					
					mContext = glXCreateContextAttribs(mDisplay, fbconf[0], NULL, direct ? True : False, attributes);
					if(mContext = None)
							printf("NONE !!!\n");
					
					if(mContext == NULL) {
					//Log::Info() << "Failed to create a " << majorVersion << "." << minorVersionArray[minorVersionIndex] << " . " << srl::endl;
					
					if(minorVersionIndex-1 == 0) {
						majorVersion=0;
					}
					// If the next minor version is "-1", it mean that we have to change the major version, and get the next minor version
					else if(minorVersionArray[minorVersionIndex-1] == -1 && minorVersionIndex-1 != 0) {
						minorVersionIndex -= 2;
						majorVersion--;
					}
					// Else, just increment the minor version index
					else
						minorVersionIndex++;
						
					//Log::Info() << "Trying to create a " << majorVersion << "." << minorVersionArray[minorVersionIndex] << srl::endl;
					}
				}
				}
			}

					if(mContext = None)
							printf("NONE !!!\n");
			if(mContext == NULL) {
				if(visual == NULL)
					return;//Log::Error() << "Impossible to create a GLX context because the given glxVisualInfo pointer is NULL" << srl::endl;
				else
					mContext = glXCreateContext(mDisplay, visual, 0, direct ? True : False );
				
			}
		
			if(mContext == NULL)
				return;//Log::Error() << "Failed to create a GLX context for this window" << srl::endl;
			//else
				//Log::Info() << "GLX context creation success" << srl::endl;*/
		    
			//printf("OLOL\n");
			//int attrib[] = {0, 0};
			//printf("OLOL\n");
			//XVisualInfo* visuali = glXChooseVisual(mDisplay, DefaultScreen(mDisplay), attrib);
			//if(visuali = NULL)
				//printf("OFAIL\n");
			//printf("OLOL\n");
			//printf("OLOL\n");
		}
		
		void glxContext::destroy() {
			glXMakeCurrent(mDisplay, None, NULL); 
			glXDestroyContext(mDisplay, mContext);
		}

		XVisualInfo* glxContext::GetVisualFormat(int* attribList, int screen) {
			if(screen == -1.0)
				screen = DefaultScreen(mDisplay);
			return glXChooseVisual(mDisplay, screen, attribList);
		}
		bool glxContext::MakeCurrent(GLXDrawable drawable) {
			return glXMakeCurrent(mDisplay, drawable, mContext);
		}

		GLXContext glxContext::getCurrent() {
			return glXGetCurrentContext();
		}
		
		void glxContext::makeCurrent() {
			Context::setCurrent(this);
		}
		
		void glxContext::swap() {
			
		}

	};
    
};

