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

#include <SRL/opengl/frameBuffer.hpp>

#include <SRL/opengl/itexture.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {
    
    namespace gl {
        
		const bool FrameBuffer::isSupported() {
			return Ext::getInstance()->isSupported( Ext::FrameBuffer_EXT );
		}
		
        FrameBuffer::FrameBuffer(int w, int h) {
			if(!isSupported())
				srlThrowErrorAsException(FrameBufferNotSupported, "FrameBuffers are not available on your harware");
        	
            glGenFramebuffersEXT(1, &mId);
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mId);
            
            glDrawBuffer(GL_NONE);
	        glReadBuffer(GL_NONE);
	        
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
            
        	mWidth = w;
        	mHeight = h;
        	
        	for(int i = 0; i < 15; i++)
        	   mTextures[i] = NULL;
        	   
            mDepthTexture = NULL;
            mStencilTexture = NULL;
        }
        
        
        
        
        FrameBuffer::~FrameBuffer() {
            glDeleteFramebuffersEXT(1, &mId);
        }
        
        
        
        
        GLenum FrameBuffer::checkStatus(bool write) {
            bind();
        	GLenum status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
        	if(write) {
    			/*switch (status) {
        			default:  Log::Info() << "Framebuffer status return : 0x" << status << srl::endl;  break;
    				case GL_FRAMEBUFFER_UNDEFINED: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_UNDEFINED" << srl::endl; break;
    				case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT" << srl::endl; break;
    				case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT" << srl::endl; break;
    				case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER" << srl::endl; break;
    				case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER" << srl::endl; break;
    				case GL_FRAMEBUFFER_UNSUPPORTED: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_UNSUPPORTED" << srl::endl; break;
    				case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: Log::Warning() << "Framebuffer status return : GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE" << srl::endl; break;
    				case GL_FRAMEBUFFER_COMPLETE: Log::Info() << "Framebuffer status return : GL_FRAMEBUFFER_COMPLETE" << srl::endl; break;
        			//case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS: SRL_Except("Framebuffer status return : GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS"); break;
        		}*/
        	}
        	unbind();
        	return status;
        }
        
        
        
        
        
        void FrameBuffer::attachTexture(ITexture* texture, int i) {
            if(texture == NULL)
        	   glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT+i, GL_TEXTURE_2D, 0, 0); 
			   
		    else {
				mTextures[i] = texture;
				glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT+i, texture->mTarget, texture->mId, 0);
			}
        }
        
        
        
        
        
        void FrameBuffer::attachDepthTexture(ITexture* texture) {
    		if(texture == NULL)
        	   glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, 0, 0); 
        	   
    		else {
        		mDepthTexture = texture;
                glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, texture->mTarget, texture->mId, 0);
            }
        }
        
        
        
        
        
        void FrameBuffer::attachStencilTexture(ITexture* texture) {
    		if(texture == NULL)
        	   glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_TEXTURE_2D, 0, 0); 
        	   
    		else {
        		mStencilTexture = texture;
                glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, texture->mTarget, texture->mId, 0); 
            }
        }
        
        void FrameBuffer::bind() {
            Context::getCurrent()->bind(this);
        }
        
        void FrameBuffer::unbind() {
            Context::getCurrent()->unbindFbo();
        }
		
        void FrameBuffer::bindGL() {
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, mId);
        }
        
        void FrameBuffer::unbindGL() {
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        }
        
        
        void FrameBuffer::activate() {
            glPushAttrib(GL_VIEWPORT_BIT);
            glViewport(0, 0, mWidth, mHeight);
            
            bind();
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        
        
        
        
        void FrameBuffer::desactivate() {
            
            /*for(int i=0; i < 15; i++) {
           		if(mTextures[i] != NULL)
            	    mTex[i]->generateMipmap();
            }*/
            
            glPopAttrib();
            unbind();
        }
        
        
        
        
        ITexture *FrameBuffer::getTexture(int i) {
        	/*if(i > 15)
        		Log::Error() << "You're asking the " << i << "th texture of the frambuffer but framebuffers only have 15 texutres acttachment" << srl::endl;
        	else if(mTextures[i] == NULL)
        		Log::Error() << "You're asking the " << i << "th texture of the framebuffer wich doesn't exist" << srl::endl;
            else {*/
            	return mTextures[i];
            /*}
            return 0;*/
        }
        
        
    /*********************************************************************************************************
    ***
    ***		FboConfig Class
    ***
    *********************************************************************************************************/
        
        /*FboConfig::FboConfig() { __tryConfigs(); }
        FboConfig::~FboConfig() {}
        
        const GLenum FboConfig::stencilFormats[] = {
    		GL_NONE,
    		GL_STENCIL_INDEX1_EXT,
    		GL_STENCIL_INDEX4_EXT,
    		GL_STENCIL_INDEX8_EXT,
    		GL_STENCIL_INDEX16_EXT
    	};
        const GLenum FboConfig::depthFormats[] = {
    		GL_NONE,
    		//GL_DEPTH_COMPONENT16,
    		GL_DEPTH_COMPONENT24,
    		//GL_DEPTH_COMPONENT32,
    		//GL_DEPTH24_STENCIL8_EXT
    	};
    
        void FboConfig::__tryConfigs() {
        
        	GLuint fbo, tex;
        	GLenum target = GL_TEXTURE_2D;
        	glGenFramebuffersEXT(1, &fbo);
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
            
            GLint drawbuffer, readbuffer;
            glGetIntegerv (GL_DRAW_BUFFER, &drawbuffer);
            glGetIntegerv (GL_READ_BUFFER, &readbuffer);
            
        	for(int i = 0; i < 15; i++) {
        		mConfs[i].valid = false;
        		GLenum format = PixelFormat::GetFormat(i);
        		
        		if(format == GL_NONE && i != 0)
                    continue;
    
    			/*if(PixelUtil::isCompressed((PixelFormat)x))
    				continue;*/
    
    			/* Correct bug in ATI for non-RGB(A) format
    			int depths[4];
    			PixelUtil::getBitDepths((PixelFormat)x, depths);
    			if(format != GL_NONE && mATIMode && (!depths[0] || !depths[1] || !depths[2]))
    				continue;*/
    
                /*if(format != GL_NONE) {
    				glGenTextures(1, &tex);
    				glBindTexture(target, tex);
    				
                    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                    glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                    glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                                
    				glTexImage2D(target, 0, format, 1024, 1024, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    				glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, target, tex, 0);
                }
                else {
    				glDrawBuffer(GL_NONE);
    				glReadBuffer(GL_NONE);
    			}
                
                GLuint status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
                if(format == GL_NONE || status == GL_FRAMEBUFFER_COMPLETE_EXT) {
                
                	mConfs[i].valid = true;
                	
                    for (size_t depth = 0; depth < 5; ++depth) {
                    
                        /*if (depthFormats[depth] == GL_DEPTH24_STENCIL8_EXT && __tryFormat(GL_DEPTH24_STENCIL8_EXT)) {
                        	DepthAndStencil mode;
                            mode.depth = depth;
                            mode.stencil = GL_NONE;
                            mConfs[i].DAndS.push_back(mode);
                        }
                        else {*/
                        	/*for (size_t stencil = 0; stencil < 5 ; ++stencil) {
                                if (__tryFormat(depthFormats[depth], stencilFormats[stencil]))  {
                                    DepthAndStencil mode;
                                    mode.depth = depth;
                                    mode.stencil = stencil;
                                    mConfs[i].DAndS.push_back(mode);
                                }
                            }
                        //}
                    }
    
                }
                glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
    			glFinish();
    			
                if (format != GL_NONE)
                    glDeleteTextures(1, &tex);
            }
            
            glDrawBuffer(drawbuffer);
            glReadBuffer(readbuffer);
            
            glDeleteFramebuffersEXT(1, &fbo);
        }
        
        bool FboConfig::__tryFormat(GLenum depthFormat, GLenum stencilFormat) {
            GLuint status, rboD, rboS;
            bool failed = false;
            
    		// Depth RBO
            if(depthFormat != GL_NONE) {
    
                glGenRenderbuffersEXT(1, &rboD);
                glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, rboD);
                
                glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, depthFormat, 1024, 1024);
                glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, rboD);
            }
    		// Stencil RBO
            if(stencilFormat != GL_NONE) {
                glGenRenderbuffersEXT(1, &rboS);
                glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, rboS);
                
                glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, stencilFormat, 1024, 1024);
                glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, rboS);
            }
            
    
            status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
            
            // Detach and destroy
            glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);
            glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);
            if(rboD)
                glDeleteRenderbuffersEXT(1, &rboD);
            if(rboS)
                glDeleteRenderbuffersEXT(1, &rboS);
            
            // If it hasn't failed, and framebuffer is ok
            return status == GL_FRAMEBUFFER_COMPLETE_EXT && !failed;
        }
        
        bool FboConfig::__tryFormat(GLenum packedFormat)
        {
            GLuint RBO;
            bool failed = false;
    
    		// Depth AND Stencil RBO
            if(packedFormat != GL_NONE) {
            	glGenRenderbuffersEXT(1, &RBO);
            	glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, RBO);
    
    		    glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, packedFormat, 1024, 1024);
    		    glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, RBO);
    		    glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, RBO);
    		}
    
            GLuint status = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
    
            // Detach and destroy
            glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);
            glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, 0);
            if(RBO)
            	glDeleteRenderbuffersEXT(1, &RBO);
            	
    		// If it hasn't failed, and framebuffer is ok
            return status == GL_FRAMEBUFFER_COMPLETE_EXT && !failed;
        }*/
        
    };
    
};
