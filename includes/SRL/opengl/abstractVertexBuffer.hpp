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

#ifndef DefineHeaderAbstractVertexBuffer
#define DefineHeaderAbstractVertexBuffer

#include <vector>
#include <SRL/Environment.hpp>
#include <SRL/opengl/extensions.hpp>
#include <SRL/maths/vec3.hpp>

namespace srl {
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        /// Abstract model of a vertexBuffer. To be inerithed. See VertexBuffer and VertexArray for specific opengl implementation.
        class SRLAPI AbstractVertexBuffer {
            public:
                 
				
                ////////////////////////////////////////////////////////////
                /// Return a new buffer object inherited of AbstractVertexBuffer : VertexArray or VertexBuffer if supported.
				/// \return Pointer to the new buffer object
                
				static AbstractVertexBuffer* getNewBuffer();
				
				
				////////////////////////////////////////////////////////////
                /// Return a buffer representing a 2d square : {(0,0) (1,0) (1,1) (0,1)}
				/// \return Pointer to the square buffer
				static AbstractVertexBuffer* getSquareBuffer();
				 
				 
				 
				 
				 
				 
                ////////////////////////////////////////////////////////////
                /// Allocate the vertex buffer
                
                virtual Error alloc() =0;
                
                ////////////////////////////////////////////////////////////
                /// Allocate the vertex buffer
                ///
                /// \param size : Size of the vertex buffer
				/// \param isInByteSize : Indicate if size is given in data count or in bytes. False by default.
                
                virtual Error alloc(int size, bool isInByteSize = false) =0;
                
                ////////////////////////////////////////////////////////////
                /// Free the buffer
                
                virtual Error free() =0;
                
                
                
				
                ////////////////////////////////////////////////////////////
                /// Bind the buffer
                virtual void bind() =0;
                
				
                ////////////////////////////////////////////////////////////
                /// Send vertex attrib pointer to openGL
				
                virtual Error sendVertexAttribPointer(int index, int component, int begin = 0, bool isInByte = false) =0;
				
				
                ////////////////////////////////////////////////////////////
                /// Unbind the buffer
                virtual void unbind() =0;
                
				
				
                
                ////////////////////////////////////////////////////////////
                /// Set the size of the buffer
                ///
                /// \param size : New size
				/// \param isInByteSize : Indicate if size is given in data count or in bytes. False by default.
                
                virtual void setSize(int size, bool isInByteSize = false) =0;
                
                
                ////////////////////////////////////////////////////////////
                /// Get the buffer size
                ///
                /// \return Current (allocated) size of the vertex buffer in byte
                
                virtual int getSize() =0;
                
				
				
				
                ////////////////////////////////////////////////////////////
                /// Send a data to the buffer
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                virtual Error sendData(int position, float x, bool isInBytePos = false) =0;
                
                ////////////////////////////////////////////////////////////
                /// Send data to the buffer
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                virtual Error sendData(int position, float x, float y, bool isInBytePos = false) =0;
                
                ////////////////////////////////////////////////////////////
                /// Send data to the buffer
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \param z : Data to be sent (z)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                virtual Error sendData(int position, float x, float y, float z, bool isInBytePos = false) =0;
                
                ////////////////////////////////////////////////////////////
                /// Send data to the buffer
                ///
                /// \param position : Position of the data in the buffer 
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \param z : Data to be sent (z)
                /// \param w : Data to be sent (w)
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                virtual Error sendData(int position, float x, float y, float z, float w, bool isInBytePos = false) =0;
                
                ////////////////////////////////////////////////////////////
                /// Send an array to the buffer
                ///
                /// \param position : Position of the data in the buffer 
                /// \param data : Array to be sent
                /// \param arraySize : Size of the array
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                virtual Error sendData(int position, float* data, int arraySize, bool isInBytePos = false) =0;
                
                /*////////////////////////////////////////////////////////////
                /// Send a data to the buffer
                /// \remark Position is the first data position in the buffer, not a vector position
                ///
                /// \param position : Position of the data in the buffer 
                /// \param vec : Vector to be sent
                /// \return True if position is correct (0 < position < size)
                
                bool sendData(int position, srl::Vector<float> vec);
                
                
                ////////////////////////////////////////////////////////////
                /// Send a vector to the buffer
                /// \remark Position is the vector position in the buffer. \n
                ///         Exemple : If it's 2 for a 3-component buffer, data will be put in the 6th cell.
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \return True if position is correct (0 < position < size)
                
                bool sendVertex(int position, float x);
                
                ////////////////////////////////////////////////////////////
                /// Send a vector to the buffer
                /// \remark Position is the vector position in the buffer. \n
                ///         Exemple : If it's 2 for a 3-component buffer, data will be put in the 6th cell.
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \return True if position is correct (0 < position < size)
                
                bool sendVertex(int position, float x, float y);
                
                ////////////////////////////////////////////////////////////
                /// Send a vector to the buffer
                /// \remark Position is the vector position in the buffer. \n
                ///         Exemple : If it's 2 for a 3-component buffer, data will be put in the 6th cell.
                ///
                /// \param position : Position of the data in the buffer
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \param y : Data to be sent (z)
                /// \return True if position is correct (0 < position < size)
                
                bool sendVertex(int position, float x, float y, float z);
                
                ////////////////////////////////////////////////////////////
                /// Send a vector to the buffer
                /// \remark Position is the vector position in the buffer. \n
                ///         Exemple : If it's 2 for a 3-component buffer, data will be put in the 6th cell.
                ///
                /// \param position : Position of the data in the buffer 
                /// \param x : Data to be sent (x)
                /// \param y : Data to be sent (y)
                /// \param y : Data to be sent (z)
                /// \param w : Data to be sent (w)
                /// \return True if position is correct (0 < position < size)
                
                bool sendVertex(int position, float x, float y, float z, float w);
                
                ////////////////////////////////////////////////////////////
                /// Send a vector to the buffer
                /// \remark Position is the vector position in the buffer. \n
                ///         Exemple : If it's 2 for a 3-component buffer, data will be put in the 6th cell.
                ///
                /// \param position : Position of the data in the buffer 
                /// \param vec : Vector to be sent
                /// \return True if position is correct (0 < position < size)
                
                bool sendVertex(int position, srl::Vector<float> vec);
                
                ////////////////////////////////////////////////////////////
                /// Send a vector array to the buffer
                /// \remark Position is the vector position in the buffer. \n
                ///         Exemple : If it's 2 for a 3-component buffer, data will be put in the 6th cell.
                ///
                /// \param position : Position of the data in the buffer 
                /// \param data : Array to be sent
                /// \param arraySize : Size of the array
                /// \return True if position is correct (0 < position < size)
                
                bool sendVertexArray(int position, float* fata, int arraySize);*/
                
                
            protected:
				void bindGL();
				static void unbindGL();
				friend class Context;
				
        };
        
    };
    
};

#endif