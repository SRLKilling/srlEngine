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



#include <SRL/opengl/textureArray.hpp>
#include <SRL/opengl/context.hpp>
#include <SRL/opengl/extensions.hpp>
//#include <cmath>

namespace srl {

    namespace gl {
	
	
		TextureArray* TextureArray::getRgbaTexture() {
			return new TextureArray();
		}
		
		TextureArray* TextureArray::getRgbTexture() {
			TextureArray* texture = new TextureArray();
			texture->mFormat = GL_RGB;
			return texture;
		}
		
		TextureArray* TextureArray::getAlphaTexture() {
			TextureArray* texture = new TextureArray();
			texture->mFormat = GL_ALPHA;
			return texture;
		}
		
		TextureArray* TextureArray::getLuminanceTexture() {
			TextureArray* texture = new TextureArray();
			texture->mFormat = GL_LUMINANCE;
			return texture;
		}
		
		TextureArray* TextureArray::getLuminanceAlphaTexture() {
			TextureArray* texture = new TextureArray();
			texture->mFormat = GL_LUMINANCE_ALPHA;
			return texture;
		}
		
		TextureArray* TextureArray::getDepthTexture() {
			TextureArray* texture = new TextureArray();
			texture->mFormat = GL_DEPTH_COMPONENT;
			return texture;
		}
		
		
		
		
        TextureArray::TextureArray() {
			mTarget = GL_TEXTURE_2D_ARRAY;
            mFormat = GL_RGBA;
            mWidth = 0;
            mHeight = 0;
			mTextureCount = 1;
        }
		
        TextureArray::TextureArray(int textureCount) {
			mTarget = GL_TEXTURE_2D_ARRAY;
            mFormat = GL_RGBA;
            mWidth = 0;
            mHeight = 0;
			mTextureCount = textureCount;
        }
		
        TextureArray::TextureArray(int width, int height) {
			mTarget = GL_TEXTURE_2D_ARRAY;
            mFormat = GL_RGBA;
            mWidth = width;
            mHeight = height;
			mTextureCount = 1;
        }
		
        TextureArray::TextureArray(int width, int height, int textureCount) {
			mTarget = GL_TEXTURE_2D_ARRAY;
            mFormat = GL_RGBA;
            mWidth = width;
            mHeight = height;
			mTextureCount = textureCount;
        }
        
		
        
        
        
        Error TextureArray::create() {
            srlReturnErrorBinding();
			
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, NULL);
			srlReturnNoError();
        }
        
        Error TextureArray::create(unsigned char* texels) {
            srlReturnErrorBinding();
			
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
        }
        
        Error TextureArray::create(int width, int height) {
            srlReturnErrorBinding();
			
			setSize(width, height);
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, NULL);
			srlReturnNoError();
        }
        
        Error TextureArray::create(int width, int height, unsigned char* texels) {
            srlReturnErrorBinding();
			
			setSize(width, height);
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
        }
		
		Error TextureArray::create(int textureCount) {
			srlReturnErrorBinding();
			
			setTextureCount(textureCount);
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, NULL);
			srlReturnNoError();
		}
		
        Error TextureArray::create(int textureCount, unsigned char* texels) {
			srlReturnErrorBinding();
			
			setTextureCount(textureCount);
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
		}
		
        Error TextureArray::create(int width, int height, int textureCount) {
			//srlReturnErrorBinding();
			
			setSize(width, height, textureCount);
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, NULL);
			srlReturnNoError();
		}
		
        Error TextureArray::create(int width, int height, int textureCount, unsigned char* texels) {
			//srlReturnErrorBinding();
			
			setSize(width, height, textureCount);
            glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, mFormat, mWidth, mHeight, mTextureCount, 0, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
		}
		
		Error TextureArray::subData(int x, int y, int width, int height, int layer, unsigned char* texels) {
			//srlReturnErrorBinding();
			
            glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, x, y, layer, width, height, 1, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
		}
		
		Error TextureArray::subData(rect r, int layer, unsigned char* texels) {
			srlReturnErrorBinding();
			
            glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, r.x, r.y, layer, r.w, r.h, 1, mFormat, GL_UNSIGNED_BYTE, texels);
			srlReturnNoError();
		}
		
		void TextureArray::setTextureCount(int textureCount) {
			mTextureCount = textureCount;
		}
        
		bool TextureArray::setSize(int width, int height) {
			mWidth = width;
			mHeight = height;
			return true;
		}
		
		bool TextureArray::setSize(int width, int height, int textureCount) {
			mWidth = width;
			mHeight = height;
			mTextureCount = textureCount;
			return true;
		}
    
        /*int TextureArray::getWidth() {
        	return mWidth;
        }
        
        
        int TextureArray::getHeight() {
        	return mHeight;
        }
        
        
        int TextureArray::getFormat() {
        
        }
        
        
        int TextureArray::getTextureType() {
        	return 0;
        }*/
        
    };
    
};