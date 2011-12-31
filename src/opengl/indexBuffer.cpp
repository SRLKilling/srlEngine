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

#include <SRL/opengl/indexBuffer.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {
    
    namespace gl {
        
		bool IndexBuffer::isSupported() {
			return Ext::getInstance()->isSupported( Ext::VertexBufferObject_ARB );
		}
		
		
        IndexBuffer::IndexBuffer() {
			if(!isSupported())
				srlThrowErrorAsException(IndexBufferNotSupported, "VertexBufferObjects are not supported by your hardware");
				
            glGenBuffers(1, &mIbo);
            mSize = 0;
            mFutureSize = 0;
        }
    
        IndexBuffer::IndexBuffer(int size, bool isByteSize, bool allocate) {
			if(!isSupported())
				srlThrowErrorAsException(IndexBufferNotSupported, "VertexBufferObjects are not supported by your hardware");
				
            glGenBuffers(1, &mIbo);
			
            if(allocate)
                alloc(size, isByteSize);
        }
        
        IndexBuffer::~IndexBuffer() {
            glDeleteBuffers(1, &mIbo);
        }
    
    
		void IndexBuffer::bind() {
            Context::getCurrent()->bind(this);
        }
        
        void IndexBuffer::unbind() {
            Context::getCurrent()->unbindIbo();
        }
        
        void IndexBuffer::bindGL() {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIbo);
        }
        
        void IndexBuffer::unbindGL() {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    
    
    
    
        Error IndexBuffer::alloc() {
			srlReturnErrorBinding();
		
			if(mFutureSize == 0) {
				free();
				srlReturnError(IndexBuffer0Size, "The index buffer object has not been allocated because the given size is zero");
			}
			
            mSize = mFutureSize;
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, mSize * sizeof(unsigned int), NULL, GL_STATIC_DRAW);
			srlReturnNoError();
        }
        
        Error IndexBuffer::alloc(int size, bool isByteSize) {
            srlReturnErrorBinding();
		
			if(!isByteSize)
				size *= sizeof(unsigned int);
				
            mFutureSize = size;
            return alloc();
        }
        
        /*void IndexBuffer::alloc(std::vector<unsigned int> vec) {
            mFutureSize = vec.size();
            alloc();
            
			
            bind();
            int i = 0;
            for(std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++) {
                sendData(i, *it);
                i++;
            }
            
        }*/
    
		Error IndexBuffer::free() {
			srlReturnErrorBinding();
		
            mSize = 0;
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, NULL, GL_STATIC_DRAW);
			
			srlReturnNoError();
		}
    
    
        
        
    
        void IndexBuffer::setSize(int size, bool isByteSize) {
			if(!isByteSize)
				size *= sizeof(unsigned int);
				
            mFutureSize = size;
        }
        
        int IndexBuffer::getSize() {
            return mSize;
        }
        
		
		
    
        Error IndexBuffer::sendData(int position, unsigned int index, bool isInBytePos) {
			srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(IndexBufferNotAllocated, "Trying to send data to a non-allocated index buffer");
		
			if(!isInBytePos)
				position *= sizeof(unsigned int);
				
            if(position < 0)
                srlReturnError(IndexBufferNegativePosition, "Trying to send data into an index buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(IndexBufferPositionTooLarge, "Trying to send data into an index buffer but the given position is superior than the vertex buffer size");
                
				
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, position, sizeof(unsigned int), &index);
			
			srlReturnNoError();
        }
        
        Error IndexBuffer::sendData(int position, unsigned int* data, int arraySize, bool isInBytePos) {
			srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(IndexBufferNotAllocated, "Trying to send data to a non-allocated index buffer");
			
			if(!isInBytePos)
				position *= sizeof(GLuint);
				
			arraySize *= sizeof(GLuint);
			
            if(position < 0)
                srlReturnError(IndexBufferNegativePosition, "Trying to send data into an index buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(IndexBufferPositionTooLarge, "Trying to send data into an index buffer but the given position is superior than the vertex buffer size");
			else if(position + arraySize > mSize)
				srlReturnError(IndexBufferArrayExceedIbo, "The given array exceeds the index buffer because Position + ArraySize is superior to the index buffer size");
				
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, position, arraySize, data);
            
			srlReturnNoError();
        }
    };
    
};
