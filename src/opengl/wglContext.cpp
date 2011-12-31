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

#include <SRL/opengl/wglContext.hpp>

namespace srl {

	namespace gl {

		wglContext::wglContext(HWND  WindowHandle) { 
			hDC = GetDC(WindowHandle);
			
			int BestFormat = 0;
			// Antialiasing level > 0
			/*if (0 > 0)
			{
				// Get the wglChoosePixelFormatARB function (it is an extension)
				PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
		
				int IntAttributes[] =
				{
					WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
					WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
					WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
					WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
					WGL_SAMPLE_BUFFERS_ARB, (Params.AntialiasingLevel ? GL_TRUE : GL_FALSE),
					WGL_SAMPLES_ARB,        Params.AntialiasingLevel,
					0,                      0
				};
		
				int   Formats[128];
				UINT  NbFormats;
				float FloatAttributes[] = {0, 0};
				bool  IsValid = wglChoosePixelFormatARB(myDeviceContext, IntAttributes, FloatAttributes, sizeof(Formats) / sizeof(*Formats), Formats, &NbFormats) != 0;
				if (!IsValid || (NbFormats == 0))
				{
					// Antialiasing level > 2
					if (0 > 2)
					{
						// No format matching our needs : reduce the multisampling level
						std::cerr << "Failed to find a pixel format supporting "
								  << Params.AntialiasingLevel << " antialiasing levels ; trying with 2 levels" << std::endl;
		
						Params.AntialiasingLevel = IntAttributes[1] = 2;
						IsValid = wglChoosePixelFormatARB(myDeviceContext, IntAttributes, FloatAttributes, sizeof(Formats) / sizeof(*Formats), Formats, &NbFormats) != 0;
					}
		
					if (!IsValid || (NbFormats == 0))
					{
						// Cannot find any pixel format supporting multisampling ; disabling antialiasing
						std::cerr << "Failed to find a pixel format supporting antialiasing ; antialiasing will be disabled" << std::endl;
						Params.AntialiasingLevel = 0;
					}
				}
		
				// Get the best format among the returned ones
				if (IsValid && (NbFormats > 0))
				{
					int BestScore = 0xFFFF;
					for (UINT i = 0; i < NbFormats; ++i)
					{
						// Get the current format's attributes
						PIXELFORMATDESCRIPTOR Attribs;
						Attribs.nSize    = sizeof(PIXELFORMATDESCRIPTOR);
						Attribs.nVersion = 1;
						DescribePixelFormat(myDeviceContext, Formats[i], sizeof(PIXELFORMATDESCRIPTOR), &Attribs);
		
						// Evaluate the current configuration
						int Color = Attribs.cRedBits + Attribs.cGreenBits + Attribs.cBlueBits + Attribs.cAlphaBits;
						int Score = EvaluateConfig(Mode, Params, Color, Attribs.cDepthBits, Attribs.cStencilBits, Params.AntialiasingLevel);
		
						// Keep it if it's better than the current best
						if (Score < BestScore)
						{
							BestScore  = Score;
							BestFormat = Formats[i];
						}
					}
				}
			}*/
		
			// Find a pixel format with no antialiasing, if not needed or not supported
			if (BestFormat == 0)
			{
				/*typedef int (APIENTRY* PFNChoosePixelFormat)(HDC, const PIXELFORMATDESCRIPTOR*);
				PFNChoosePixelFormat wglChoosePixelFormat = reinterpret_cast<PFNChoosePixelFormat>(wglGetProcAddress("wglChoosePixelFormatARB"));*/
				
				// Setup a pixel format descriptor from the rendering settings
				 PIXELFORMATDESCRIPTOR PixelDescriptor = {
					sizeof(PIXELFORMATDESCRIPTOR),
					1,
					PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
					PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
					32,                        //Colordepth of the framebuffer.
					0, 0, 0, 0, 0, 0,
					0,
					0,
					0,
					0, 0, 0, 0,
					24,                        //Number of bits for the depthbuffer
					8,                        //Number of bits for the stencilbuffer
					0,                        //Number of Aux buffers in the framebuffer.
					PFD_MAIN_PLANE,
					0,
					0, 0, 0
				}; 
				/*PIXELFORMATDESCRIPTOR PixelDescriptor;
				//ZeroMemory(&PixelDescriptor, sizeof(PIXELFORMATDESCRIPTOR));
				PixelDescriptor.nSize        = sizeof(PIXELFORMATDESCRIPTOR);
				PixelDescriptor.nVersion     = 1;
				PixelDescriptor.iLayerType   = PFD_MAIN_PLANE;
				PixelDescriptor.dwFlags      = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
				PixelDescriptor.iPixelType   = PFD_TYPE_RGBA;
				PixelDescriptor.cColorBits   = static_cast<BYTE>(32);
				PixelDescriptor.cDepthBits   = static_cast<BYTE>(32);
				PixelDescriptor.cStencilBits = static_cast<BYTE>(0);*/
		
				// Get the pixel format that best matches our requirements
				BestFormat = ChoosePixelFormat(hDC, &PixelDescriptor);
				
				if (BestFormat == 0) {
					//std::cerr << "Failed to find a suitable pixel format for device context -- cannot create OpenGL context" << std::endl;
					return;
				}
			}
		
			// Extract the depth and stencil bits from the chosen format
			PIXELFORMATDESCRIPTOR ActualFormat = {};
			ActualFormat.nSize    = sizeof(PIXELFORMATDESCRIPTOR);
			ActualFormat.nVersion = 1;
			DescribePixelFormat(hDC, BestFormat, sizeof(PIXELFORMATDESCRIPTOR), &ActualFormat);
			//Params.DepthBits   = ActualFormat.cDepthBits;
			//Params.StencilBits = ActualFormat.cStencilBits;
		
			// Set the chosen pixel format
			if (!SetPixelFormat(hDC, BestFormat, &ActualFormat))
			{
				//std::cerr << "Failed to set pixel format for device context -- cannot create OpenGL context" << std::endl;
				return;
			}
		
			// Create the OpenGL context from the device context
			hRC = wglCreateContext(hDC);
			if (hRC == NULL)
			{
				//std::cerr << "Failed to create an OpenGL context for this window" << std::endl;
				return;
			}
			
			// Share display lists with other contexts
			HGLRC CurrentContext = wglGetCurrentContext();
			if (CurrentContext)
				wglShareLists(CurrentContext, hRC);
		
		
			makeCurrent();
			// Enable multisampling
			/*if (Params.AntialiasingLevel > 0)
				glEnable(GL_MULTISAMPLE_ARB);*/
			
			
			
		}
		
		wglContext::~wglContext() {
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(hRC);
		}
		
		void wglContext::swap() {
			SwapBuffers(hDC);
		}
		
		void wglContext::setBestPixelFormat() {
			PIXELFORMATDESCRIPTOR pfd = {0}; 
			int pixelFormat; 
	 
			pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);			// Set the size of the structure
			pfd.nVersion = 1;									// Always set this to 1
																// Pass in the appropriate OpenGL flags
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
			pfd.dwLayerMask = PFD_MAIN_PLANE;					// We want the standard mask (this is ignored anyway)
			pfd.iPixelType = PFD_TYPE_RGBA;						// We want RGB and Alpha pixel type
			pfd.cColorBits = 32;						// Here we use our #define for the color bits
			pfd.cDepthBits = 32;						// Depthbits is ignored for RGBA, but we do it anyway
			pfd.cAccumBits = 0;									// No special bitplanes needed
			pfd.cStencilBits = 0;								// We desire no stencil bits
		 
			pixelFormat = ChoosePixelFormat(hDC, &pfd);
			SetPixelFormat(hDC, pixelFormat, &pfd);
		}
		
		void wglContext::makeCurrent() {
			if(wglMakeCurrent(hDC, hRC) == TRUE)
				Context::setCurrent(this);
		}
	
	};
	
};