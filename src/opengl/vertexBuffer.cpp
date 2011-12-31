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

#include <SRL/opengl/vertexBuffer.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {

    namespace gl {
		
		bool VertexBuffer::isSupported() {
			return Ext::getInstance()->isSupported( Ext::VertexBufferObject_ARB );
		}
	
            
        VertexBuffer::VertexBuffer() {
			if(!isSupported())
				srlThrowErrorAsException(VertexBufferNotSupported, "VertexBufferObjects are not supported by your hardware");
			
            glGenBuffers(1, &mVbo);
            mSize = 0;
            mFutureSize = 0;
        }
        
        VertexBuffer::VertexBuffer(int size, bool isInByteSize, bool allocate) {
			if(!isSupported())
				srlThrowErrorAsException(VertexBufferNotSupported, "VertexBufferObjects are not supported by your hardware");
				
            glGenBuffers(1, &mVbo);
            
            if(allocate)
                alloc(size, isInByteSize);
			else {
				if(!isInByteSize)
					size *= sizeof(GLfloat);
				mFutureSize = size;
			}
			
        }
        
        VertexBuffer::~VertexBuffer() {
            glDeleteBuffers(1, &mVbo);
        }



    
        Error VertexBuffer::alloc() {
			srlReturnErrorBinding();
		
			if(mFutureSize == 0) {
				free();
				srlReturnError(VertexBuffer0Size, "The vertex buffer object has not been allocated because the given size is zero");
			}
			
            mSize = mFutureSize;
            glBufferData(GL_ARRAY_BUFFER, mSize * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
			srlReturnNoError();
        }
        
        
        Error VertexBuffer::alloc(int size, bool isInByteSize) {
			srlReturnErrorBinding();
		
			if(!isInByteSize)
				size *= sizeof(GLfloat);
				
            mFutureSize = size;
            return alloc();
        }
        
        
        Error VertexBuffer::free() {
			srlReturnErrorBinding();
		
            mSize = 0;
            glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_STATIC_DRAW);
			
			srlReturnNoError();
        }
        
        
        Error VertexBuffer::sendVertexAttribPointer(int index, int component, int begin, bool isInByteSize) {
			srlReturnErrorBinding();
			
            if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex buffer");
				
			 if(!isInByteSize)
				 begin *= sizeof(float);
			
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, component, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(begin));
            
			srlReturnNoError();
        }
    
    
    
		void VertexBuffer::bind() {
			Context::getCurrent()->bind(this);
		}
        
		void VertexBuffer::unbind() {
			Context::getCurrent()->unbindVbo();
		}
    
        void VertexBuffer::bindGL() {
            glBindBuffer(GL_ARRAY_BUFFER, mVbo);
        }
		
        void VertexBuffer::unbindGL() {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }




        
        
        void VertexBuffer::setSize(int size, bool isInByteSize) {
			if(!isInByteSize)
				size *= sizeof(GLfloat);
				
            mFutureSize = size;
        }
        
        int VertexBuffer::getSize() {
            return mSize;
        }
            
                
				
				
				
        Error VertexBuffer::sendData(int position, float x, bool isInBytePos) {
			srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(VertexBufferUnallocated, "Trying to send data to a non-allocated vertex buffer");
		
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex buffer but the given position is superior than the vertex buffer size");
                
				
            glBufferSubData(GL_ARRAY_BUFFER, position, sizeof(GLfloat), &x);
            
			srlReturnNoError();
        }
        
        
        Error VertexBuffer::sendData(int position, float x, float y, bool isInBytePos) {
			srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(VertexBufferUnallocated, "Trying to send data to a non-allocated vertex buffer");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex buffer but the given position is superior than the vertex buffer size");
                
				
            float data[] = {x, y};
            glBufferSubData(GL_ARRAY_BUFFER, position, 2 * sizeof(GLfloat), data);
            
			srlReturnNoError();
        }
        
        
        Error VertexBuffer::sendData(int position, float x, float y, float z, bool isInBytePos) {
			srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(VertexBufferUnallocated, "Trying to send data to a non-allocated vertex buffer");
				
			if(!isInBytePos)
				position *= sizeof(GLfloat);
			
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex buffer but the given position is superior than the vertex buffer size");
                
				
            float data[] = {x, y, z};
            glBufferSubData(GL_ARRAY_BUFFER, position, 3 * sizeof(GLfloat), data);
            
			srlReturnNoError();
        }
        
        
        Error VertexBuffer::sendData(int position, float x, float y, float z, float w, bool isInBytePos) {
			srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(VertexBufferUnallocated, "Trying to send data to a non-allocated vertex buffer");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex buffer but the given position is superior than the vertex buffer size");
                
				
            float data[] = {x, y, z, w};
            glBufferSubData(GL_ARRAY_BUFFER, position, 4 * sizeof(GLfloat), data);
            
			srlReturnNoError();
        }
        
		
		
		
        Error VertexBuffer::sendData(int position, float* data, int arraySize, bool isInBytePos) {
            srlReturnErrorBinding();
			
			if(mSize == 0)
				srlReturnError(VertexBufferUnallocated, "Trying to send data to a non-allocated vertex buffer");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
			arraySize *= sizeof(GLfloat);
			
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex buffer but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex buffer but the given position is superior than the vertex buffer size");
			else if(position + arraySize > mSize)
				srlReturnError(VertexBufferArrayExceedVbo, "The given array exceeds the vertex buffer because Position + ArraySize is superior to the vertex buffer size");
				
            glBufferSubData(GL_ARRAY_BUFFER, position, arraySize, data);
            
			srlReturnNoError();
        }
        
        /*bool VertexBuffer::sendData(int position, srl::Vector<float> vec) {
            if(!mAllocated || position < 0 || position > mSize * mComponentNb)
                return false;
                
            bind();
            float data[] = {vec.x, vec.y, vec.z, vec.w};
            glBufferSubData(GL_ARRAY_BUFFER, position * sizeof(GL_FLOAT) , mComponentNb * sizeof(GL_FLOAT), data);
            return true;
        }
        
        
        
        
        bool VertexBuffer::sendVertex(int position, float x) {
            if(!mAllocated || position < 0 || position > mSize)
                return false;
                
            bind();
            float data[] = {x};
            glBufferSubData(GL_ARRAY_BUFFER, position * mComponentNb, sizeof(GL_FLOAT), data);
            return true;
        }
        
        
        bool VertexBuffer::sendVertex(int position, float x, float y) {
            if(!mAllocated || position < 0 || position > mSize)
                return false;
                
            bind();
            float data[] = {x, y};
            glBufferSubData(GL_ARRAY_BUFFER, position * mComponentNb, 2 * sizeof(GL_FLOAT), data);
            return true;
        }
        
        
        bool VertexBuffer::sendVertex(int position, float x, float y, float z) {
            if(!mAllocated || position < 0 || position > mSize)
                return false;
                
            bind();
            float data[] = {x, y, z};
            glBufferSubData(GL_ARRAY_BUFFER, position * mComponentNb * sizeof(GL_FLOAT), 3 * sizeof(GL_FLOAT), data);
            return true;
        }
        
        
        bool VertexBuffer::sendVertex(int position, float x, float y, float z, float w) {
            if(!mAllocated || position < 0 || position > mSize)
                return false;
                
            bind();
            float data[] = {x, y, z, w};
            glBufferSubData(GL_ARRAY_BUFFER, position * mComponentNb * sizeof(GL_FLOAT), 4 * sizeof(GL_FLOAT), data);
            return true;
        }
        
        bool VertexBuffer::sendVertex(int position, srl::Vector<float> vec) {
            if(!mAllocated || position < 0 || position > mSize)
                return false;
                
            bind();
            float data[] = {vec.x, vec.y, vec.z, vec.w};
            glBufferSubData(GL_ARRAY_BUFFER, position * mComponentNb * sizeof(GL_FLOAT), mComponentNb * sizeof(GL_FLOAT), data);
            return true;
        }
        
        bool VertexBuffer::sendVertexArray(int position, float* array, int arraySize) {
            if(!mAllocated || position < 0 || position > mSize)
                return false;
                
            bind();
            glBufferSubData(GL_ARRAY_BUFFER, position * 3 * sizeof(GL_FLOAT), arraySize * mComponentNb * sizeof(GL_FLOAT), array);
            return true;
        }*/
        
    };

};
