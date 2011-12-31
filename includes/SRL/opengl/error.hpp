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

#ifndef DefineHeaderGLError
#define DefineHeaderGLError
#include <SRL/environment.hpp>


namespace srl {
    
    namespace gl {
		
		#define __func__ __PRETTY_FUNCTION__
		
		#define srlError(type, info) Error(Error::type, info, __func__, __FILE__, __LINE__)
		#define srlNoError() Error(Error::NoError, "No error occured", __func__, __FILE__, __LINE__)
		
		#define srlThrowError(type, info) Error(Error::type, info, __func__, __FILE__, __LINE__)
		#define srlThrowErrorAsException(type, info) throw Error(Error::type, info, __func__, __FILE__, __LINE__)
		
		#define srlReturnError(type, info) return Error(Error::type, info, __func__, __FILE__, __LINE__)
		#define srlReturnNoError() return Error(Error::NoError, "No error occured", __func__, __FILE__, __LINE__)
		
		#define srlReturnTypeError(return_type, type, info) Error(Error::type, info, __func__, __FILE__, __LINE__); return return_type()
		#define srlReturnPtrError(type, info) Error(Error::type, info, __func__, __FILE__, __LINE__); return NULL
        
		#define srlReturnErrorBinding() if(!Context::getCurrent()->isBound(this)) srlReturnError(ObjectNotBound, "Trying to execute method on an object which is not bound")
		
        class SRLAPI Error {
		
			public:
				enum ErrorType {
					NoError,
					UnknownError,
					
					// Context
					MatrixStackEmpty,
					
					// Ext
					ExtensionNotSupported,
					ExtensionLoadingFailed,
					
					// OpenGL Objects
					ObjectNotBound,
					
					// Shader
					ShaderNotSupported,
					
					// Program
					ProgramNotSupported,
					ProgramLinkFailed,
					
					// VertexBuffers
					VertexBufferNotSupported,
					VertexBuffer0Size,
					VertexBufferUnallocated,
					VertexBufferNegativePosition,
					VertexBufferPositionTooLarge,
					VertexBufferArrayExceedVbo,
					
					// IndexBuffers
					IndexBufferNotSupported,
					IndexBuffer0Size,
					IndexBufferNotAllocated,
					IndexBufferNegativePosition,
					IndexBufferPositionTooLarge,
					IndexBufferArrayExceedIbo,
					
					// FrameBuffers
					FrameBufferNotSupported
					
				};
				
				Error();
				Error(ErrorType type, std::string info, std::string func, std::string file, int line);
				Error(bool success);
				~Error();
				
				Error(const Error& e);
				void operator=(const Error& e);
				
				operator bool() const;
				bool operator==(ErrorType type);
				bool operator!=(ErrorType type);
				bool operator!();
				
				
				std::string what();
				std::string operator()();
				
				ErrorType type();
				std::string info();
				std::string func();
				std::string file();
				int line();
				
				static Error getLastError();
			
			private:
				ErrorType mType;
				std::string mInfo;
				std::string mFunc;
				std::string mFile;
				int mLine;
				
				static Error mLastError;
        };
		
    };
    
};

#endif
