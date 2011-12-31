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

#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>

#include <SRL/opengl/extensions.hpp>
#include <SRL/opengl/shader.hpp>

namespace srl {
    
    namespace gl {
	
	
		bool Shader::isSupported() {
			return Ext::getInstance()->isSupported( Ext::ShaderObject_ARB );
		}
        
        Shader::Shader(Type type) {
			if(!isSupported() || !Ext::getInstance()->isSupported( (type == VertexShader)? Ext::VertexShader_ARB : Ext::FragmentShader_ARB ) )
				srlThrowErrorAsException(ShaderNotSupported, "Shader objects are not available on your harware");
		
            mType = type;
            mId = glCreateShader( (type==VertexShader)? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER );
        }
        Shader::Shader(Type type, std::string url, bool toCompile) {
			if(!isSupported() || !Ext::getInstance()->isSupported( (type == VertexShader)? Ext::VertexShader_ARB : Ext::FragmentShader_ARB ) )
				srlThrowErrorAsException(ShaderNotSupported, "Shader objects are not available on your harware");
				
            mType = type;
            mId = glCreateShader( (type==VertexShader)? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER );
            loadFromFile(url);
			
			if(toCompile)
				compile();
        }
        Shader::~Shader() {
            glDeleteShader(mId);
        }
        
        
        void Shader::loadFromMem(std::string source) {
            const char *src = source.c_str();
            int size = source.size();
            glShaderSource(mId, 1, &src, &size);
        }
        void Shader::loadFromFile(std::string url) {
            std::string source;
            std::ifstream file(url.c_str());
			source += "uniform mat4 srlProjectionMatrix;\n";
			source += "uniform mat4 srlModelViewMatrix;\n";
			source += "\n";
            if(file){
                std::string line;
                while (std::getline(file, line)) {
                    source += line;
                    source += "\n";
                }
            }
            loadFromMem(source);
            file.close();
        }
        bool Shader::loadAndCompile(std::string url) {
            loadFromFile(url);
            return compile();
        }
        
        bool Shader::compile() {
            glCompileShader(mId); 
            GLint result = GL_TRUE;
            //glGetShaderiv(mId, GL_COMPILE_STATUS, &result);
            return (result==GL_TRUE) ? true : false;
        }
		
        std::string Shader::getLog() {
            GLint logsize;
            glGetShaderiv(mId, GL_INFO_LOG_LENGTH, &logsize);
			
            char *clog = new char[logsize+1];
            glGetShaderInfoLog(mId, logsize, &logsize, clog);
			
			std::string log(clog);
            return log;
        }
        
        GLuint Shader::getId() {
        	return mId;
        }
        
        Shader::Type Shader::getType() {
            return mType;
        }
        
    };
    
};
