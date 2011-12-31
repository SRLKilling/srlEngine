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



#include <SRL/opengl/itexture.hpp>
#include <SRL/opengl/extensions.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {

    namespace gl {
		
        ITexture::ITexture() {
            glGenTextures(1, &mId);
        }
        
        ITexture::~ITexture() {
            glDeleteTextures(1, &mId);
        }
        
        
        
        
        
        void ITexture::bind(int i) {
            //glActiveTexture(GL_TEXTURE0 + i);
			//Context::getCurrent()->bind(this);
			bindGL();
        }
        void ITexture::bindGL() {
            glBindTexture(mTarget, mId);
		}
			
        
        void ITexture::unbind() {
			Context::getCurrent()->unbindTex();
        }
		
		void ITexture::unbindGL() {
            glBindTexture(GL_TEXTURE_2D, 0);
		}
        
        
    
        void ITexture::generateMipmap() {
        	glGenerateMipmapEXT(mTarget);
        }
		
        
        
        
        bool ITexture::setParams(Env::TexFilterParams param, Env::TexFilterValues value) {
            if(param == Env::MagFilter && (value != Env::Nearest && value != Env::Linear)) return false;
                
            glTexParameteri(mTarget, param, value);
            return true;
        }
        
        
        bool ITexture::setParams(Env::TexCompareParams param, Env::TexCompareValues value) {
            if(param == Env::CompareMode && (value != Env::CompareR && value != 0x0 )) return false;
                
            glTexParameteri(mTarget, param, value);
            return true;
        }
        
        bool ITexture::setParams(Env::TexLevelParams param, int value) {
            if(value < 0) return false;
                
            glTexParameteri(mTarget, param, value);
            return true;
        }
        
        bool ITexture::setParams(Env::TexWrapParams param, Env::TexWrapValues value) {
            glTexParameteri(mTarget, param, value);
            return true;
        }
		
        bool ITexture::setParams(Env::TexLODParams param, float value) {
            glTexParameterf(mTarget, param, value);
            return true;
        }
        
    };
    
};