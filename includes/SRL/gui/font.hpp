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
#ifndef srlHeaderFont
#define srlHeaderFont
#include <SRL/environment.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_SIZES_H

#include <SRL/opengl/texture2d.hpp>
#include <SRL/opengl/abstractVertexBuffer.hpp>
#include <SRL/maths/rect.hpp>
#include <SRL/maths/ivec2.hpp>

namespace srl {
	
	namespace gui {
	
		class Font {
			public:
				
				struct GlyphInfo {
					rect mRect;
					rect mCoord;
					int advanceX;
					int advanceY;
				};
				
				Font();
				Font(std::string filename);
				
				void loadFont(std::string filename);
				void renderFont();
				
				void bindFontTex();
				int getGlyphId(short c);
				GlyphInfo getGlyphInfo(int i);
				gl::AbstractVertexBuffer* getTexCoordArray();
				
				/*void renderChar(short c, ivec2 pos=ivec2(0.0));
				void renderString(short* str, ivec2 pos=ivec2(0.0));
				void renderString(const wchar_t* str, ivec2 pos=ivec2(0.0));
				void renderString(std::wstring str, ivec2 pos=ivec2(0.0));*/
				
				
				void enableTable(short tablenum);
				void enableGlyph(short c);
				void enableGlyph(short a, short b);
				void enableGlyph(short* c, int size);
				void disableGlyph(short c);
				void disableGlyph(short a, short b);
				void disableGlyph(short* c, int size);
				
			private:
				static void initFreetypeLib();
				static FT_Library mLibrary;
				
				
				FT_Face mFontFace;
				bool* mEnabledGlyph;
				
				gl::Texture2D* mTexture;
				
				int* mGlyphCorrespondingMap;
				int mFinalGlyphArraySize;
				GlyphInfo* mGlyphInfos;
				gl::AbstractVertexBuffer* mTexCoordArray;
		};
		
	};
	
};

#endif
