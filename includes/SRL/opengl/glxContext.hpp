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


#ifndef DefineHeaderGLXContext
#define DefineHeaderGLXContext

#include <SRL/Environment.hpp>
#include <SRL/opengl/context.hpp>
#include <GL/glx.h>

namespace srl {
    
	namespace gl {

		class SRLAPI glxContext : public Context {

			public:
				glxContext(::Display* display);
				~glxContext();
				void Create(Env::ContextOpenGLVersion version, bool direct, int screen = -1,  XVisualInfo* visual=NULL);
				void destroy();
			
				XVisualInfo* GetVisualFormat(int* attribList, int screen = -1);
				bool MakeCurrent(GLXDrawable drawable);

				void swap();

				void setBestPixelFormat();

				void makeCurrent();

				static GLXContext getCurrent();
		    
			private:
				GLXContext mContext;
				::Display* mDisplay;
		};

	};

};

#endif
