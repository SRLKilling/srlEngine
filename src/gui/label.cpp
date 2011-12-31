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

#include <SRL/gui/label.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {

	namespace gui {

		Label::Label(std::string str) : BaseElement(LabelType) {
			mString = str;
			mFont = NULL;
		}
		
		Label::Label(Label& l) : BaseElement(LabelType) {
			mString = l.mString;
			mFont = l.mFont;
		}
		
		Label::~Label() {
		
		}
		
		void Label::setFont(Font* font) {
			mFont = font;
		}

		Font* Label::getFont() {
			return mFont;
		}
		
		
		void Label::render() {
			if(mFont == NULL) { printf("OLONLAAAAAAAAAAA\n"); return;}
			mFont->bindFontTex();
			gl::Context::getCurrent()->pushModelview();
			gl::Context::getCurrent()->translate(200.0, 200.0, 0.0);
			gl::Context::getCurrent()->scale(2.0, 2.0, 0.0);
			char text[] = { 0x53, 0x61, 0x6C, 0x75, 0x74 };
			for(int i = 0; i < 5; i++) {
				int glyph = mFont->getGlyphId(text[i]);
				Font::GlyphInfo gi = mFont->getGlyphInfo(glyph);
				gl::Context::getCurrent()->pushModelview();
					gl::Context::getCurrent()->scale(gi.mRect.w, gi.mRect.h, 0.0);
					printf("%f  %f\n", gi.mRect.w, gi.mRect.h);
					gl::AbstractVertexBuffer::getSquareBuffer()->bind();
					gl::AbstractVertexBuffer::getSquareBuffer()->sendVertexAttribPointer(0, 2);
					mFont->getTexCoordArray()->bind();
					mFont->getTexCoordArray()->sendVertexAttribPointer(1, 2, glyph*8*4, true);
					printf("%i * 8 = %i * 4 = %i\n\n", glyph, glyph*8, glyph*8*4);
					glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
				gl::Context::getCurrent()->popModelview();
				gl::Context::getCurrent()->translate(gi.advanceX, 0.0, 0.0);
				
				// mFont->renderChar(mString[i]);
			}
			gl::Context::getCurrent()->popModelview();
			//printf("   \n\n\n");*/
			
			/*int glyph = mFont->getGlyphId('a');
			Font::GlyphInfo gi = mFont->getGlyphInfo(glyph);
			gl::Context::getCurrent()->scale((float)gi.mRect.w, (float)gi.mRect.h, 0.0);
					printf("%f  %f\n", (float)gi.mRect.w, (float)gi.mRect.h);
					
			gl::AbstractVertexBuffer::getSquareBuffer()->bind();
			gl::AbstractVertexBuffer::getSquareBuffer()->sendVertexAttribPointer(0, 2);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);*/
			
			
		}
		
		void Label::eventHandler(win::Event event) {
		
		}
	
	};
	
};