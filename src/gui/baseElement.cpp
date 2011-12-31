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

#include <SRL/gui/baseElement.hpp>
#include <SRL/opengl/context.hpp>
#include <SRL/3d/mesh.hpp>

namespace srl {

	namespace gui {
	
		BaseElement::BaseElement(Type type) {
			mType = type;
			mFocus = false;
		}
		
		BaseElement::~BaseElement() {
		
		}
		
		
		bool BaseElement::baseEventHandler(win::Event event) {
			if(mInternalRect.isIn(event.mMousePos) || mFocus)
				eventHandler(event);
			return mFocus ? false : true;
		}
		
		void BaseElement::setRect(irect rect) {
			mInternalRect = rect;
		}
		
		irect BaseElement::getRect() {
			return mInternalRect;
		}
		
		void BaseElement::drawRect(irect r) {
			gl::Context::getCurrent()->pushModelview();
			gl::Context::getCurrent()->translate((float)r.x, (float)r.y, 0.0);
			gl::Context::getCurrent()->scale((float)r.w, (float)r.h, 0.0);
			d3::Mesh::getSquareMesh()->draw();
			gl::Context::getCurrent()->popModelview();
		}
	
	};

};

