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

#include <SRL/gui/layout.hpp>

namespace srl {

	namespace gui {
	
		Layout::Layout() : BaseElement(LayoutType){
		
		}
		
		Layout::~Layout() {
		
		}
		
		void Layout::addElement(BaseElement* element, int pos) {
			if(pos == -1 || pos >= mElements.size())
				mElements.push_back(element);
			else if(pos == 0)
				mElements.push_front(element);
			else {
				int iteration = 0;
				for(std::list<BaseElement*>::iterator it = mElements.begin(); it != mElements.end(); it++) {
					if(iteration == pos) mElements.insert(it, element);
					iteration++;
				}
			}
		}
		
		void Layout::eventHandler(win::Event event) {
			for(std::list<BaseElement*>::iterator it = mElements.begin(); it != mElements.end(); it++)
				if((*it)->baseEventHandler(event)) break;
		}
		
		void Layout::render() {
			for(std::list<BaseElement*>::iterator it = mElements.begin(); it != mElements.end(); it++)
				(*it)->render();
		}
	
	};

};