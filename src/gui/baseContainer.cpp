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

#include <SRL/gui/baseContainer.hpp>

namespace srl {

	namespace gui {
	
		BaseContainer::BaseContainer(Type type) : BaseElement(type) {
			mLayout = NULL;
		}
		
		BaseContainer::~BaseContainer() {
			if(mLayout) delete mLayout;
		}
		
		void BaseContainer::setLayout(Layout* layout) {
			mLayout = layout;
		}
		
		Layout* BaseContainer::getLayout() {
			return mLayout;
		}
		
		void BaseContainer::eventHandler(win::Event event) {
			mLayout->baseEventHandler(event);
		}
		
		void BaseContainer::render() {
			mLayout->render();
		}
	
	};

};
