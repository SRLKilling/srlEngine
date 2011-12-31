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

#include <SRL/opengl/vertexArray.hpp>

namespace srl {

    namespace gl {
            
        VertexArray::VertexArray() {
            mData = NULL;
            mSize = 0;
            mFutureSize = 0;
        }
        
        
        VertexArray::VertexArray(int size, bool isInByteSize, bool allocate) {
            mData = NULL;
            mSize = 0;
            mFutureSize = 0;
            
            if(allocate)
                alloc(size);
			else {
				if(!isInByteSize)
					size *= sizeof(GLfloat);
				mFutureSize = size;
			}
        }
        
        VertexArray::~VertexArray() {
            free();
        }
    
    
    
    
        Error VertexArray::alloc() {
            if(mFutureSize == 0) {
				free();
				srlReturnError(VertexBuffer0Size, "The vertex buffer object has not been allocated because the given size is zero");
			}
			
            mSize = mFutureSize;
            mData = new GLfloat[mSize];
			srlReturnNoError();
        }
        
        Error VertexArray::alloc(int size, bool isInByteSize) {
			if(!isInByteSize)
				size *= sizeof(GLfloat);
				
            mFutureSize = size;
            return alloc();
        }
        
        Error VertexArray::free() {
            if(mData != NULL) {
				mSize = 0;
                delete[] mData;
				srlReturnNoError();
			}
			srlReturnError(VertexBufferUnallocated, "Trying to free an unallocated vertex array");
        }
        
        
        Error VertexArray::sendVertexAttribPointer(int index, int component, int begin, bool isInByteSize) {
            if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex array");
				
			if(!isInByteSize)
				begin *= sizeof(GLfloat);
			
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, component, GL_FLOAT, GL_FALSE, 0, (char*)(mData) + begin);
            
			srlReturnNoError();
        }
        
		
		
		
        void VertexArray::bind() {
		}
        
		void VertexArray::unbind() {
		}

		
		
		
		void VertexArray::setSize(int size, bool isInByteSize) {
			if(!isInByteSize)
				size *= sizeof(GLfloat);
				
            mFutureSize = size;
        }
        
        int VertexArray::getSize() {
            return mSize;
        }



        Error VertexArray::sendData(int position, float x, bool isInBytePos) {
			if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex array");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex array but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex array but the given position is superior than the vertex array size");
                
			
			float* pData = (float*)((char*)(mData) + position);
			pData[0] = x;
            
			srlReturnNoError();
        }
        
        
        Error VertexArray::sendData(int position, float x, float y, bool isInBytePos) {
			if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex array");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex array but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex array but the given position is superior than the vertex array size");
                
			
			float* pData = (float*)((char*)(mData) + position);
			pData[0] = x;
			pData[1] = y;
            
			srlReturnNoError();
        }
        
        
        Error VertexArray::sendData(int position, float x, float y, float z, bool isInBytePos) {
			if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex array");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex array but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex array but the given position is superior than the vertex array size");
                
			
			float* pData = (float*)((char*)(mData) + position);
			pData[0] = x;
			pData[1] = y;
			pData[2] = z;
            
			srlReturnNoError();
        }
        
        
        Error VertexArray::sendData(int position, float x, float y, float z, float w, bool isInBytePos) {
			if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex array");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex array but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex array but the given position is superior than the vertex array size");
                
			
			float* pData = (float*)((char*)(mData) + position);
			pData[0] = x;
			pData[1] = y;
			pData[2] = z;
			pData[3] = w;
            
			srlReturnNoError();
        }
        
		
		
		
        Error VertexArray::sendData(int position, float* data, int arraySize, bool isInBytePos) {
			if(mSize == 0)
                srlReturnError(VertexBufferUnallocated, "Trying to send a vertex attrib pointer of an unallocated vertex array");
			
			if(!isInBytePos)
				position *= sizeof(GLfloat);
				
			//arraySize *= sizeof(GLfloat);
			
            if(position < 0)
                srlReturnError(VertexBufferNegativePosition, "Trying to send data into a vertex array but the given position is negative");
			else if(position > mSize)
			    srlReturnError(VertexBufferPositionTooLarge, "Trying to send data into a vertex array but the given position is superior than the vertex array size");
			else if(position + arraySize > mSize)
				srlReturnError(VertexBufferArrayExceedVbo, "The given array exceeds the vertex array because Position + ArraySize is superior to the vertex array size");
				
			float* pData = (float*)((char*)(mData) + position);
			for(int i = 0; i < arraySize; i++)
				pData[i] = data[i];
            
			srlReturnNoError();
        }
        
    };
    
};
