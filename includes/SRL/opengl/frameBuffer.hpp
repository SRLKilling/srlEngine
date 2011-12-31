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

#ifndef DefineHeaderFrameBuffer
#define DefineHeaderFrameBuffer
#include <SRL/environment.hpp>

#include <SRL/opengl/extensions.hpp>
#include <vector>

namespace srl {
    
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        class ITexture;
            
        /// C++ implementation of OpenGL FrameBufferObject
        class SRLAPI FrameBuffer {
            public:
                
				static const bool isSupported();
				
                ////////////////////////////////////////////////////////////
                /// Default Constructor.
                ///
                /// \param w :  Width of the FrameBuffer
                /// \param h :  Height of the FrameBuffer
                
                FrameBuffer(int w, int h);
                
                
                
                ////////////////////////////////////////////////////////////
                /// Destructor
                
                ~FrameBuffer();
                
                
                
                
                
                ////////////////////////////////////////////////////////////
                /// Attach or detach the texture to the framebuffer.
                ///
                /// \param tex :  Texture to bind. If NULL, detach the texture
                /// \param i :  Attachement index (must be < 15).
                
                void attachTexture(ITexture* tex, int i);
                
                ////////////////////////////////////////////////////////////
                /// Attach the texture as depthbuffer to the framebuffer.
                ///
                /// \param tex :  Texture to bind
                
                void attachDepthTexture(ITexture* tex);
                
                ////////////////////////////////////////////////////////////
                /// Attach the texture as stencilbuffer to the framebuffer.
                ///
                /// \param tex :  Texture to bind
                
                void attachStencilTexture(ITexture* tex);
                
        		////////////////////////////////////////////////////////////
                /// Get an attached texture.
                ///
                /// \param i : Attachment index of the texture to get (0 as default)
                
        		ITexture *getTexture(int i = 0);
        		
        		void bind();
        		
        		static void unbind();
        		
        		////////////////////////////////////////////////////////////
                /// Activate the framebuffer. 
                /// Call it before drawing
                
                void activate();
                
        		////////////////////////////////////////////////////////////
                /// Desactivate the framebuffer. 
                /// Call it after drawing.
                
                void desactivate();
                
                ////////////////////////////////////////////////////////////
                /// Check the framebuffer status and return it
                ///
                /// \param write :  If true, write the status
                /// \return Framebuffer status
                
                GLenum checkStatus(bool write);
                
            private:
				void bindGL();
				static void unbindGL();
				friend class Context;
			
                GLuint mId;
                
                ITexture* mTextures[15];
                ITexture* mDepthTexture;
                ITexture* mStencilTexture;
                
                int mWidth;
                int mHeight;
        };
        
        	
    	/// Useful class to get possible and best Framebuffer config
    	/// Use getSingleton() to get an instance of this class
    	/*class SRLAPI_GL FboConfig: public srl::Singleton<FboConfig> {
    		public:
    			FboConfig();
    			~FboConfig();
    			
    			bool Valid(int x);
    			GLenum getFormat(int x);
    			GLenum getIntFormat(int x);
    			GLenum getDepth(int x);
    			GLenum getStencil(int x);
                
    			
    			static const GLenum stencilFormats[];
    			static const GLenum depthFormats[];
    			
    		private:
    			struct DepthAndStencil { GLenum depth; GLenum stencil; };
    			struct Config { bool valid; std::vector<DepthAndStencil> DAndS; };
    			Config mConfs[51];
    			
    			void __tryConfigs();
    			bool __tryFormat(GLenum depthFormat, GLenum stencilFormat);
    			bool __tryFormat(GLenum packedFormat); // For Packed Format (GL_DEPTH24_STENCIL8)
    		
    	};*/
	
    };
    
};

#endif
