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

#ifndef DefineHeaderShader
#define DefineHeaderShader

#include <SRL/Environment.hpp>
#include <string>

namespace srl {
    
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        class Program;
        
        /// C++ implementation of OpenGL Shader
        class SRLAPI Shader {
            public:
			
				static bool isSupported();
			
                enum Type {
                    VertexShader,
                    FragmentShader
                };
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param type : Shader type (VertexShader or FragmentShader)
                
                Shader(Type type);
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param type : Shader type (VertexShader or FragmentShader)
                /// \param path : Local path to a text file to load
				/// \param toCompile : If true, it'll compile the program after loading it (True by default)
                
                Shader(Type type, std::string path, bool toCompile = true);
                
                ////////////////////////////////////////////////////////////
                /// Destructor
                
                ~Shader();
                
                
                
                
                ////////////////////////////////////////////////////////////
                /// Load the shader from the memory
                ///
                /// \param source : The source to load
                
                void loadFromMem(std::string source);
                
                ////////////////////////////////////////////////////////////
                /// Load the shader from a file
                ///
                /// \param path : The path of the file to load
                
                void loadFromFile(std::string path);
                
                ////////////////////////////////////////////////////////////
                /// Compile the shader
                ///
                /// \return True if shader has been compiled successfully
                
                bool compile();
                
                ////////////////////////////////////////////////////////////
                /// Load the shader from a file and compile it. (Equivalent to loadFromFile(std::string path) + compile() )
                ///
                /// \param path : The path of the file to load
                /// \return True if shader has been compiled successfully
                
                bool loadAndCompile(std::string path);
                
                
                ////////////////////////////////////////////////////////////
                /// Get the shader's log
                ///
                /// \return Shader's log
                std::string getLog();
                
                ////////////////////////////////////////////////////////////
                /// Get the shader's id
                ///
                /// \return Shader's id
                GLuint getId();
                
                ////////////////////////////////////////////////////////////
                /// Get the shader's type (Vertex Shader or Fragment Shader)
                ///
                /// \return Shader's type
                Type getType();
                
            protected:
                GLuint mId;
                Type mType;
            
            friend class Program;
            
        };
    
    };
    
};

#endif
