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

#include <SRL/opengl/abstractVertexBuffer.hpp>
#include <SRL/opengl/vertexBuffer.hpp>
#include <SRL/opengl/vertexArray.hpp>

namespace srl {

	namespace gl {
	
		AbstractVertexBuffer* AbstractVertexBuffer::getNewBuffer() {
			if(VertexBuffer::isSupported())
				return new VertexBuffer();
			else
				return new VertexArray();
		}

		AbstractVertexBuffer* AbstractVertexBuffer::getSquareBuffer() {
			static AbstractVertexBuffer* buffer = NULL;
			if(buffer != NULL) return buffer;
			
			float vertices[] = {
				0.0, 0.0,
				0.0, 1.0,
				1.0, 0.0,
				1.0, 1.0,
			};
			
			buffer = getNewBuffer();
			buffer->bind();
			buffer->alloc(8);
			buffer->sendData(0, vertices, 8);
			buffer->unbind();
			return buffer;
		}
		
	};
	
};