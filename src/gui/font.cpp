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

#include <SRL/opengl/context.hpp>
#include <SRL/opengl/program.hpp>
#include <SRL/gui/font.hpp>
#include <cmath>

namespace srl {
	
	namespace gui {
		
		void Font::initFreetypeLib() {
			static bool isInit = false;
			if(!isInit) { FT_Init_FreeType(&mLibrary); isInit = true; }
		}	
		
		FT_Library Font::mLibrary = NULL;
		
		
		Font::Font(std::string filename, int* glyphToEnable, int arraySize) {
			initFreetypeLib();
			
			FT_New_Face(mLibrary, filename.c_str(), 0, &mFontFace);
			FT_Select_Charmap(mFontFace, FT_ENCODING_UNICODE);
			
			if(glyphToEnable != NULL) {
				mGlyphNum = arraySize;
				mCharToGlyph = new int[mGlyphNum];
				memcpy(mCharToGlyph, glyphToEnable, mGlyphNum * sizeof(int));
			}
			else {
				mGlyphNum = 0xFF;
				mCharToGlyph = new int[0xFF];
				for(int i = 0; i < 0xFF; ++i) mCharToGlyph[i] = i;
			}
		}
		
		Font::~Font() {
			delete[] mCharToGlyph;
			FT_Done_Face(mFontFace);
		}
		
		
		
		
		Font::SizedFontInfo* Font::operator[](int size) {
			return getFontBySize(size);
		}
		
		Font::SizedFontInfo* Font::getFontBySize(int size) {
			std::map<int, SizedFontInfo*>::iterator it = mSizedFontInfoMap.find(size);
			if(it == mSizedFontInfoMap.end())
				return render(size);
			
			return it->second;
		}
		
		
		
		
		
		int Font::getGlyphIndex(short c) {
			for(int i = 0; i < mGlyphNum; i++)
				if(mCharToGlyph[i] == c) return i;
			return 0;
		}
		
		
		
		
		
		
		
		
		Font::SizedFontInfo* Font::render(int size) {
			FT_Set_Pixel_Sizes(mFontFace, size, size);
			
			// Computing texture size
			int pixelNumber = size * size * mGlyphNum;
			int squareSize = (int)ceil(sqrt((float)pixelNumber));
			int texSize = 1;
			while(texSize < squareSize)
				texSize *= 2;
				
			
			SizedFontInfo* mSizeFont = new SizedFontInfo;
			mSizeFont->mTexCoordBuffer = gl::AbstractVertexBuffer::getNewBuffer();
			mSizeFont->mTexCoordBuffer->bind();
			mSizeFont->mTexCoordBuffer->alloc(mGlyphNum * 8);
			mSizeFont->mGlyphInfos = new int[mGlyphNum * 3];
			mSizeFont->mTexture = gl::Texture2D::getLuminanceTexture();
			unsigned char* pixelBuffer = new unsigned char[texSize * texSize];
			
			int top = 0, left = 0;
			for(int i = 0; i < mGlyphNum; i++) {
				// Loading glyph and updating pixelbuffer
				FT_Load_Char(mFontFace, mCharToGlyph[i], FT_LOAD_DEFAULT);
				FT_Glyph glyph; FT_Get_Glyph(mFontFace->glyph, &glyph);
				FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, 0, 1);
				FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph)glyph;
				FT_Bitmap bitmap = bitmapGlyph->bitmap;
				char* buffer = (char*)bitmap.buffer;
				
				for (int y = 0; y < bitmap.rows; ++y) {
					for (int x = 0; x < bitmap.width; ++x) {
						pixelBuffer[(top+y)*texSize  +left+x] = (unsigned char)buffer[x];
					}
					buffer += bitmap.pitch;
				}
				
				
				// Loading and updating glyph information (advance, internal rect, texture coordinates)
				//mGlyphInfos[i].mRect = rect(bitmapGlyph->left, bitmapGlyph->top, bitmap.width, bitmap.rows);
				mSizeFont->mGlyphInfos[i*3   ] = bitmap.width;
				mSizeFont->mGlyphInfos[i*3 +1] = bitmap.rows;
				mSizeFont->mGlyphInfos[i*3 +2] = mFontFace->glyph->advance.x >> 6;
				
				
				float data[] = {(float)left/(float)texSize, 				(float)(top+bitmap.rows)/(float)texSize,
								(float)left/(float)texSize, 				(float)top/(float)texSize,
								(float)(left+bitmap.width)/(float)texSize,	(float)(top+bitmap.rows)/(float)texSize,
								(float)(left+bitmap.width)/(float)texSize, 	(float)top/(float)texSize};
				mSizeFont->mTexCoordBuffer->sendData(i * 8, data, 8);
				
				
				left += size;
				if(left >= texSize) {
					left = 0;
					top += size;
				}
				FT_Done_Glyph((FT_Glyph)bitmapGlyph);
			}
			
			// Creating texture from the pixelbuffer
			mSizeFont->mTexture->bind();
			mSizeFont->mTexture->create(texSize, texSize, pixelBuffer);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			mSizeFont->mTexture->unbind();
			
			return mSizeFont;
		}
		
	};
	
};