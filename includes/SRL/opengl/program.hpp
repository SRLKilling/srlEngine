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

#ifndef DefineHeaderProgram
#define DefineHeaderProgram

#include <SRL/opengl/shader.hpp>
#include <SRL/opengl/itexture.hpp>

#include <SRL/maths/rect.hpp>
#include <SRL/maths/vec2.hpp>
#include <SRL/maths/vec3.hpp>
#include <SRL/maths/mat4.hpp>

namespace srl {
    
    /// Contains all OpenGL implementation
    namespace gl {
        
        /// C++ implementation of OpenGL Program
        class SRLAPI Program {
            public:
                
				static bool isSupported();
				
                ////////////////////////////////////////////////////////////
                /// Default Constructor
                
                Program();
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param vs : Pointer to the Vertex Shader
                /// \param fs : Poitner to the Fragment Shader
                
                Program(gl::Shader* vs, gl::Shader* fs);
                
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param vs : Local path to a text file to load as vertex shader
                /// \param fs : Local path to a text file to load as fragment shader
                
                Program(std::string vsPath, std::string fsPath);
				
				////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param filepath : Local path to a text file to be load.
                
                Program(std::string filepath);
				
                ////////////////////////////////////////////////////////////
                /// Destructor
                
                ~Program();
    
    
				
				
				////////////////////////////////////////////////////////////
                /// 
                ///
                /// \param 
                
                void bindAttrib(int attrib, std::string attribName);
				
				////////////////////////////////////////////////////////////
                /// 
                ///
                /// \param 
                
                void bindFragData(int fragdata, std::string fragDataName);
				
                ////////////////////////////////////////////////////////////
                /// Attach a shader
                ///
                /// \param shader : Shader to attach
                
                void attachShader(gl::Shader *shader);
                
                ////////////////////////////////////////////////////////////
                /// Detach a shader
                ///
                /// \param shader : Shader to detach
                
                void detachShader(gl::Shader *shader);
                
                ////////////////////////////////////////////////////////////
                /// Link shaders
                
                Error link();
                
				
				
				
				
				////////////////////////////////////////////////////////////
                /// Load a program
				///
				/// \param filepath : Local path to the program to be load
                
                Error loadProgram(std::string filepath);
				
                
                
                
                
                ////////////////////////////////////////////////////////////
                /// Get if shaders are linked or not
                ///
                /// \return True if shaders have been linked successfully
                
                bool isLinked();
                
                
                ////////////////////////////////////////////////////////////
                /// Use the program (send a using event to the current srl::Context)
                
                void use();
				
                
                ////////////////////////////////////////////////////////////
                /// Stop using the program
                
                static void unuse();
                
                
                
                ////////////////////////////////////////////////////////////
                /// Get the program's log
                ///
                /// \return Program's log
                
                std::string getLog();
    
    
    
    
    
                void uniform(std::string var, float x);
                void uniform(std::string var, float x, float y);
                void uniform(std::string var, float x, float y, float z);
                void uniform(std::string var, float x, float y, float z, float w);
				
                void uniform(std::string var, int x);
                void uniform(std::string var, int x, int y);
                void uniform(std::string var, int x, int y, int z);
                void uniform(std::string var, int x, int y, int z, int w);
				
                void uniform(std::string var, vec2 vec);
                void uniform(std::string var, vec3 vec);
                void uniform(std::string var, rect r);
				
                void uniform(std::string var, mat4 val);
				
                void uniform(std::string var, ITexture* tex, int i = 0);  
                
            private:
				void useGL();
				static void unuseGL();
				friend class Context;
				
                GLuint mId;
                bool mLinked;
        };

    };

};

#endif
