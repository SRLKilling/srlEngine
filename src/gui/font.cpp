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
		
		
		Font::Font(std::string filename) {
			initFreetypeLib();
			mFinalGlyphArraySize = 42;
			mGlyphInfos = NULL;
			loadFont(filename);
		}
		
		void Font::loadFont(std::string filename) {
			FT_New_Face(mLibrary, filename.c_str(), 0, &mFontFace);
			FT_Select_Charmap(mFontFace, FT_ENCODING_UNICODE);
			mEnabledGlyph = new bool[mFontFace->num_glyphs];
			for(int i = 0; i < mFontFace->num_glyphs; i++) mEnabledGlyph[i] = false;
		}
		
		
		void Font::enableTable(short tablenum) {
			enableGlyph(tablenum * 0xFF, (tablenum+1) * 0xFF);
		}
		
		void Font::enableGlyph(short c) {
			mEnabledGlyph[FT_Get_Char_Index(mFontFace, c)] = true;
		}
		
		void Font::enableGlyph(short a, short b) {
			for(int i = a; i <= b; i++)
				if(FT_Get_Char_Index(mFontFace, i) != 0) mEnabledGlyph[FT_Get_Char_Index(mFontFace, i)] = true;
		}
		
		void Font::enableGlyph(short* c, int size) {
			for(int i = 0; c[i] != size; i++)
				if(FT_Get_Char_Index(mFontFace, c[i]) != 0) mEnabledGlyph[FT_Get_Char_Index(mFontFace, c[i])] = true;
		}
		
		void Font::disableGlyph(short c) {
			mEnabledGlyph[FT_Get_Char_Index(mFontFace, c)] = false;
		}
		
		void Font::disableGlyph(short a, short b) {
			for(int i = a; i < b; i++)
				mEnabledGlyph[FT_Get_Char_Index(mFontFace, i)] = false;
		}
		
		void Font::disableGlyph(short* c, int size) {
			for(int i = 0; c[i] != size; i++)
				mEnabledGlyph[FT_Get_Char_Index(mFontFace, c[i])] = false;
		}
		
		
		
		
		
		
		int Font::getGlyphId(short c) {
			for(int i = 0; i < mFinalGlyphArraySize; i++)
				if(mGlyphCorrespondingMap[i] == c) return i;
			return 0;
		}
		
		
		Font::GlyphInfo Font::getGlyphInfo(int i) {
			return mGlyphInfos[i];
		}
		
		gl::AbstractVertexBuffer* Font::getTexCoordArray() {
			return mTexCoordArray;
		}
		
		/*void Font::renderChar(short c, ivec2 pos) {
			short i = getGlyphId(c);
			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_QUADS);
				float xmin = (float)pos.x + mGlyphInfos[i].mRect.x;
				float xmax = xmin + mGlyphInfos[i].mRect.w;
				float ymin = (float)pos.y + mGlyphInfos[i].mRect.y;
				float ymax = ymin + mGlyphInfos[i].mRect.h;
				
				glTexCoord2f(mGlyphInfos[i].mCoord.x, mGlyphInfos[i].mCoord.y);
				glVertex2f(xmin, ymax);
				
				glTexCoord2f(mGlyphInfos[i].mCoord.w, mGlyphInfos[i].mCoord.y);
				glVertex2f(xmax, ymax);
				
				glTexCoord2f(mGlyphInfos[i].mCoord.w, mGlyphInfos[i].mCoord.h);
				glVertex2f(xmax, ymin);
				
				glTexCoord2f(mGlyphInfos[i].mCoord.x, mGlyphInfos[i].mCoord.h);
				glVertex2f(xmin, ymin);
			glEnd();
		}
		
		void Font::renderString(short* str, ivec2 pos) {
			for(int i = 0; str[i]!='\0'; i++) {
				renderChar(str[i], pos);
				pos.x += mGlyphInfos[getGlyphId(str[i])].advanceX;
			}
		}
		
		void Font::renderString(const wchar_t* str, ivec2 pos) {
			for(int i = 0; str[i]!='\0'; i++) {
				renderChar(str[i], pos);
				pos.x += mGlyphInfos[getGlyphId(str[i])].advanceX;
			}
		}
		
		void Font::renderString(std::wstring str, ivec2 pos) {
			for(int i = 0; i < str.length(); i++) {
				renderChar(str[i], pos);
				pos.x += mGlyphInfos[getGlyphId(str[i])].advanceX;
			}
		}*/
		

		
		void Font::bindFontTex() {
			mTexture->bind();
			gl::Context::getCurrent()->getCurrentProg()->uniform("fontTex", mTexture);
		}
		
		
		
		
		
		
		void Font::renderFont() {
			FT_Set_Pixel_Sizes(mFontFace, 16, 16);
			
			// Counting enabled glyphs and allocating correspondance and information arrays
			mFinalGlyphArraySize = 0;
			for(int i = 0; i < mFontFace->num_glyphs; i++)
				if(mEnabledGlyph[i]) mFinalGlyphArraySize++;
			
			mGlyphCorrespondingMap = new int[mFinalGlyphArraySize];
			mGlyphInfos = new GlyphInfo[mFinalGlyphArraySize];
			printf("%i", mFinalGlyphArraySize);
			mTexCoordArray = gl::AbstractVertexBuffer::getNewBuffer();
			mTexCoordArray->bind();
			mTexCoordArray->alloc(mFinalGlyphArraySize * 8);
			
			
			
			// Computing texture size and allocating pixelBuffer
			int pixelNumber = 16 * 16 * mFinalGlyphArraySize;
			int squareSize = (int)ceil(sqrt((float)pixelNumber));
			int texSize = 1;
			while(texSize < squareSize)
				texSize *= 2;
				
			unsigned char* pixelBuffer = new unsigned char[texSize * texSize];
			
			
			
			int top = 0, left = 0;
			int j = 0;
			for(int i = 0; i < mFontFace->num_glyphs; i++) {
				if(!mEnabledGlyph[i]) continue;
				
				
				// Loading glyph and updating pixelbuffer
				FT_Load_Glyph(mFontFace, i, FT_LOAD_DEFAULT);
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
				
				mGlyphCorrespondingMap[j] = i;
				
				
				// Loading and updating glyph information (advance, internal rect, texture coordinates)
				//mGlyphInfos[i].mRect = rect(bitmapGlyph->left, bitmapGlyph->top, bitmap.width, bitmap.rows);
				mGlyphInfos[j].mRect = rect(0.0, 0.0, (float)bitmap.width, (float)bitmap.rows);
				mGlyphInfos[j].mCoord = rect((float)left/(float)texSize, (float)top/(float)texSize, (float)(left+bitmap.width)/(float)texSize, (float)(top+bitmap.rows)/(float)texSize);
				mGlyphInfos[j].advanceX =  mFontFace->glyph->advance.x >> 6;
				// printf("%i  %i  %i\n", i, mFontFace->glyph->advance.x >> 6, mGlyphInfos[i].advanceX);
				mGlyphInfos[j].advanceY =  mFontFace->glyph->advance.y >> 6;
				//printf("0x%i   %f %f %f %f     %f %f %f %f\n", i, mGlyphInfos[i].mCoord.x, mGlyphInfos[i].mCoord.y, mGlyphInfos[i].mCoord.w, mGlyphInfos[i].mCoord.h, mGlyphInfos[i].mRect.x, mGlyphInfos[i].mRect.y, mGlyphInfos[i].mRect.w, mGlyphInfos[i].mRect.h);
				
				
				float data[] = {(float)left/(float)texSize, 				(float)(top+bitmap.rows)/(float)texSize,
								(float)left/(float)texSize, 				(float)top/(float)texSize,
								(float)(left+bitmap.width)/(float)texSize, 	(float)top/(float)texSize,
								(float)(left+bitmap.width)/(float)texSize,	(float)(top+bitmap.rows)/(float)texSize};
				mTexCoordArray->sendData(j * 8, data, 8);
				j++;
				
				
				
				FT_Done_Glyph((FT_Glyph)bitmapGlyph);
			
				left += 16;
				if(left >= texSize) {
					left = 0;
					top += 16;
				}
			}
			
			
			FT_Done_Face(mFontFace);
			
			// Creating texture from the pixelbuffer
			mTexture = gl::Texture2D::getLuminanceTexture();
			mTexture->bind();
			mTexture->create(texSize, texSize, pixelBuffer);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			mTexture->unbind();
		}
		
	};
	
};