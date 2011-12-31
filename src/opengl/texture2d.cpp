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



#include <SRL/opengl/texture2d.hpp>
#include <SRL/opengl/context.hpp>
#include <SRL/opengl/extensions.hpp>
//#include <SOIL/SOIL.h>
//#include <cmath>

namespace srl {

    namespace gl {
	
	
		Texture2D* Texture2D::getRgbaTexture() {
			return new Texture2D();
		}
		
		Texture2D* Texture2D::getRgbTexture() {
			Texture2D* texture = new Texture2D();
			texture->mFormat = GL_RGB;
			return texture;
		}
		
		Texture2D* Texture2D::getAlphaTexture() {
			Texture2D* texture = new Texture2D();
			texture->mFormat = GL_ALPHA;
			return texture;
		}
		
		Texture2D* Texture2D::getLuminanceTexture() {
			Texture2D* texture = new Texture2D();
			texture->mFormat = GL_LUMINANCE;
			return texture;
		}
		
		Texture2D* Texture2D::getLuminanceAlphaTexture() {
			Texture2D* texture = new Texture2D();
			texture->mFormat = GL_LUMINANCE_ALPHA;
			return texture;
		}
		
		Texture2D* Texture2D::getDepthTexture() {
			Texture2D* texture = new Texture2D();
			texture->mFormat = GL_DEPTH_COMPONENT;
			return texture;
		}
		
		
		
		
        Texture2D::Texture2D() {
			mTarget = GL_TEXTURE_2D;
            mFormat = GL_RGBA;
            mWidth = 0;
            mHeight = 0;
        }
        
        Texture2D::Texture2D(int width, int height) {
			mTarget = GL_TEXTURE_2D;
            mFormat = GL_RGBA;
            mWidth = width;
            mHeight = height;
        }
        
		bool Texture2D::load(std::string filepath) {
			//mId = SOIL_load_OGL_texture(filepath.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);
		}
		
        
        /*bool Texture2D::load(TexLoader* loader) {
            GLenum target;
            return loader->load(mId, target, mHeight, mWidth, mFormat, mType, mInternalFormat);
        }*/
        
        
        
        Error Texture2D::create() {
            //srlReturnErrorBinding();
			
            glTexImage2D(GL_TEXTURE_2D, 0, mFormat, mWidth, mHeight, 0, mFormat, GL_UNSIGNED_BYTE, NULL);
			srlReturnNoError();
        }
        
        Error Texture2D::create(unsigned char* texels) {
			//srlReturnErrorBinding();
			
            glTexImage2D(GL_TEXTURE_2D, 0, mFormat, mWidth, mHeight, 0, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
        }
        
        Error Texture2D::create(int width, int height) {
            //srlReturnErrorBinding();
			
			setSize(width, height);
            glTexImage2D(GL_TEXTURE_2D, 0, mFormat, mWidth, mHeight, 0, mFormat, GL_UNSIGNED_BYTE, NULL);
			srlReturnNoError();
        }
        
        Error Texture2D::create(int width, int height, unsigned char* texels) {
            //srlReturnErrorBinding();
			
			setSize(width, height);
            glTexImage2D(GL_TEXTURE_2D, 0, mFormat, mWidth, mHeight, 0, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
        }
        
    
        
        
        
        bool Texture2D::setWidth(int width) {
            //if(width < 1)
                //Log::Error() << "La largeur minimum d'une texture est d'un texel (" << width << " < 1)" << srl::endl;
            //else if(width > Env::MaxTexSize)
                //Log::Error() << "La largeur de texture passée est supérieure à la largueur surpporté par OpenGL (" << width << " > " << Env::MaxTexSize << ")" << srl::endl;
            /*if(!Ext::GetInstance()->CheckForExtension("GL_ARB_texture_non_power_of_two")) {
                //if( ((width&(width-1)) != 0) || (width <= 0) )
                    //Log::Error() << "La largeur de texture passée n'est pas une puissance de deux alors que l'extensions Texture-non-power-of-two n'est pas supportée." << srl::endl;
                //else {
                    mWidth = width;
                    return true;
                //}
            }
            else {*/
                mWidth = width;
                return true;
            //}
        }
        
        
        bool Texture2D::setHeight(int height) {
            //if(height < 1)
                //Log::Error() << "La hauteur minimum d'une texture est d'un texel (" << height << " < 1)" << srl::endl;
            //else if(height > Env::MaxTexSize)
                //Log::Error() << "La hauteur de texture passée est supérieure à la largueur surpporté par OpenGL (" << height << " > " << Env::MaxTexSize << ")" << srl::endl;
           /*if(!Ext::GetInstance()->CheckForExtension("GL_ARB_texture_non_power_of_two")) {
                /*if( ((height&(height-1)) != 0) || (height <= 0) )
                    Log::Error() << "La hauteur de texture passée n'est pas une puissance de deux alors que l'extensions Texture-non-power-of-two n'est pas supportée." << srl::endl;
                else {
                    mHeight = height;
                    return true;
                //}
            }
            else {*/
                mHeight = height;
                return true;
            //}
            //return false;
        }
        
		bool Texture2D::setSize(int width, int height) {
			mWidth = width;
			mHeight = height;
			return true;
		}
    
    
        int Texture2D::getWidth() {
        	return mWidth;
        }
        
        
        int Texture2D::getHeight() {
        	return mHeight;
        }
        
        
        int Texture2D::getFormat() {
        
        }
        
        
        int Texture2D::getTextureType() {
        	return 0;
        }
        
    };
    
};
