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
#include <SRL/error.hpp>

namespace srl {

	namespace gui {

		Label::Label(std::string str, int charsize) : BaseElement(LabelType) {
			mString = str;
			mFont = NULL;
			mCharSize = charsize;
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
		
		
		void Label::setCharSize(int charsize) {
			mCharSize = charsize;
		}
		
		int Label::getCharSize() {
			return mCharSize;
		}
		
		
		void Label::render() {
			if(mFont == NULL) {
				srlError(NoFont, "Trying to render a label without any font specified. Use Label::setFont.");
				return;
			}
				
			Font::SizedFontInfo* mFontSized = mFont->getFontBySize(mCharSize);
			mFontSized->mTexture->bind();
			
			gl::Context::getCurrent()->pushModelview();
			gl::Context::getCurrent()->translate(mInternalRect.x, mInternalRect.y, 0.0);
			
			for(int i = 0; i < mString.size(); i++) {
				int index = mFont->getGlyphIndex(mString[i]);
				
				gl::Context::getCurrent()->pushModelview();
					gl::Context::getCurrent()->scale(mFontSized->mGlyphInfos[index*3], -mFontSized->mGlyphInfos[index*3 +1], 0.0);
					
					gl::AbstractVertexBuffer::getSquareBuffer()->bind();
					gl::AbstractVertexBuffer::getSquareBuffer()->sendVertexAttribPointer(0, 2);
					mFontSized->mTexCoordBuffer->bind();
					mFontSized->mTexCoordBuffer->sendVertexAttribPointer(1, 2, index*8);
					glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
					
				gl::Context::getCurrent()->popModelview();
				gl::Context::getCurrent()->translate(mFontSized->mGlyphInfos[index*3 +2], 0.0, 0.0);
			}
			
			gl::Context::getCurrent()->popModelview();
		}
		
		void Label::eventHandler(win::Event event) {
		
		}
	
	};
	
};