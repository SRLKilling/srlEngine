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

#ifndef DefineHeaderVertexArray
#define DefineHeaderVertexArray

#include <vector>
#include <SRL/Environment.hpp>
#include <SRL/opengl/abstractVertexBuffer.hpp>
#include <SRL/maths/vec3.hpp>

namespace srl {
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        /// C++ implementation of OpenGL VertexArray
        class SRLAPI VertexArray : public AbstractVertexBuffer {
            public:
                
                ////////////////////////////////////////////////////////////
                /// Default Constructor
                
                VertexArray();
                
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param size : Size of the vertex buffer
				/// \param isInByteSize : Indicate if size is given in data count or in bytes. False by default.
                /// \param allocate : If true, alloc the vertex buffer. False by default.
                
                VertexArray(int size, bool isInByteSize = false, bool allocate = false);
                
                ////////////////////////////////////////////////////////////
                /// Destructor
                
                ~VertexArray();
                
                
                
                    
                ////////////////////////////////////////////////////////////
                /// Allocate the vertex buffer
                
                Error alloc();
                
                ////////////////////////////////////////////////////////////
                /// Allocate the vertex buffer
                ///
                /// \param size : Size of the vertex buffer
				/// \param isInByteSize : Indicate if size is given in data count or in bytes. False by default.
                
                Error alloc(int size, bool isInByteSize = false);
                
                ////////////////////////////////////////////////////////////
                /// Free the buffer
                
                Error free();
                
                
                
				
                ////////////////////////////////////////////////////////////
                /// Bind the buffer
                void bind();
                
				
                ////////////////////////////////////////////////////////////
                /// Send vertex attrib pointer to openGL
				
                Error sendVertexAttribPointer(int index, int component, int begin = 0, bool isInByte = false);
				
				
                ////////////////////////////////////////////////////////////
                /// Unbind the buffer
                void unbind();
                
				
				
                
                ////////////////////////////////////////////////////////////
                /// Set the size of the buffer
                ///
                /// \param size : New size
				/// \param isByteSize : Indicate if size is given in data count or in bytes. False by default.
                
                void setSize(int size, bool isByteSize = false);
                
                
                ////////////////////////////////////////////////////////////
                /// Get the buffer size
                ///
                /// \return Current (allocated) size of the vertex buffer in byte
                
                int getSize();
                
				
				
				
                ////////////////////////////////////////////////////////////
                /// Send a data to the buffer
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, float x, bool isInBytePos = false);
                
                ////////////////////////////////////////////////////////////
                /// Send data to the buffer
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, float x, float y, bool isInBytePos = false);
                
                ////////////////////////////////////////////////////////////
                /// Send data to the buffer
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \param z : Data to be sent (z)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, float x, float y, float z, bool isInBytePos = false);
                
                ////////////////////////////////////////////////////////////
                /// Send data to the buffer
                ///
                /// \param position : Position of the data in the buffer 
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \param z : Data to be sent (z)
                /// \param w : Data to be sent (w)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, float x, float y, float z, float w, bool isInBytePos = false);
                
                ////////////////////////////////////////////////////////////
                /// Send an array to the buffer
                ///
                /// \param position : Position of the data in the buffer 
                /// \param data : Array to be sent
                /// \param arraySize : Size of the array
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, float* data, int arraySize, bool isInBytePos = false);
                
            private:
                GLfloat* mData;
                int mSize;
                int mFutureSize;
        };
        
    };
    
};

#endif
