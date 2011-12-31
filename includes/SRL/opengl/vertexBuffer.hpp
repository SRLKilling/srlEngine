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

#ifndef DefineHeaderVertexBuffer
#define DefineHeaderVertexBuffer

#include <vector>
#include <SRL/Environment.hpp>
#include <SRL/opengl/extensions.hpp>
#include <SRL/opengl/abstractVertexBuffer.hpp>
#include <SRL/maths/vec3.hpp>

namespace srl {
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        /// C++ implementation of OpenGL VertexBuffer
        class SRLAPI VertexBuffer : public AbstractVertexBuffer  {
            public:
                
				static bool isSupported();
				
                ////////////////////////////////////////////////////////////
                /// Default Constructor
                
                VertexBuffer();
                
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param size : Size of the vertex buffer
				/// \param isByteSize : Indicate if size is given in data count or in bytes. False by default.
                /// \param allocate : If true, alloc the vertex buffer. False by default.
                
                VertexBuffer(int size, bool isByteSize = false, bool allocate = false);
                
                ////////////////////////////////////////////////////////////
                /// Destructor
                
                ~VertexBuffer();
                
                
                
                    
                ////////////////////////////////////////////////////////////
                /// Allocate the vertex buffer
                
                Error alloc();
                
                ////////////////////////////////////////////////////////////
                /// Allocate the vertex buffer
                ///
                /// \param size : Size of the vertex buffer
				/// \param isByteSize : Indicate if size is given in data count or in bytes. False by default.
                
                Error alloc(int size, bool isByteSize = false);
                
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
                
                
            private:
				void bindGL();
				static void unbindGL();
				friend class Context;
				
                GLuint mVbo;
                int mSize;
                int mFutureSize;
                
        };
        
    };
    
};

#endif
