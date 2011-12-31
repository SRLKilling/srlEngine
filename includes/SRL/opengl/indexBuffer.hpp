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

#ifndef DefineHeaderIndexBuffer
#define DefineHeaderIndexBuffer

#include <SRL/Environment.hpp>
#include <SRL/opengl/extensions.hpp>
#include <vector>

namespace srl {
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        /// C++ implementation of OpenGL IndexBufferObject
        class SRLAPI IndexBuffer {
            
            public:
				
				static bool isSupported();
			
                ////////////////////////////////////////////////////////////
                /// Default Constructor.
                
                IndexBuffer();
                
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param size : Size of the index buffer
				/// \param isByteSize : Indicate if size is given in data count or in bytes. False by default.
                /// \param allocate : If true, alloc the index buffer. False by default.
                
                IndexBuffer(int size, bool isByteSize = false, bool alloc = false);
                
                
                ////////////////////////////////////////////////////////////
                /// Destructor
                
                ~IndexBuffer();
				
				
				
				
				
                ////////////////////////////////////////////////////////////
                /// Allocate the index buffer
                
                Error alloc();
                
                ////////////////////////////////////////////////////////////
                /// Allocate the index buffer
                ///
                /// \param size : Size of the index buffer
				/// \param isByteSize : Indicate if size is given in data count or in bytes. False by default.
                
                Error alloc(int size, bool isByteSize = false);
                
                ////////////////////////////////////////////////////////////
                /// Allocate the index buffer
                ///
                /// \param vec : Vector containing data that will be copied into the data store for initialization
                
                Error alloc(std::vector<unsigned int> vec);
				
                ////////////////////////////////////////////////////////////
                /// Free the index buffer
				
				Error free();
				
				
                
                
                ////////////////////////////////////////////////////////////
                /// Bind the buffer
				
                void bind();
                
                
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
                /// \return Current (allocated) size of the index buffer in byte
				
                int getSize();
				
				
				
				
				
                ////////////////////////////////////////////////////////////
                /// Send an index to the buffer
                ///
                /// \param position : Position of the index in the buffer
                /// \param index : Index to add
				/// \param isInBytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, unsigned int index, bool isInBytePos = false);
                
                
                ////////////////////////////////////////////////////////////
                /// Send an index array to the buffer
                ///
                /// \param position : Position of the index in the buffer
                /// \param data : Array to be send
                /// \param arraySize : Size of the array
				/// \param isInytePos : Indicate if position is given in data count or in bytes. False by default.
                
                Error sendData(int position, unsigned int* data, int arraysize, bool isInBytePos = false);
				
				
                
            private:
                void bindGL();
                static void unbindGL();
				friend class Context;
				
                GLuint mIbo;
                int mSize;
                int mFutureSize;
                
        };
    
    };
    
};

#endif
