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
#include <stdio.h>
#include <fstream>

#include <SRL/Environment.hpp>
#include <SRL/opengl/extensions.hpp>
#include <SRL/opengl/context.hpp>
#include <SRL/opengl/program.hpp>
#include <iostream>

namespace srl {

    namespace gl {

    	const GLenum glTextureNumber[] = {
    		GL_TEXTURE0,
    		GL_TEXTURE1,
    		GL_TEXTURE2,
    		GL_TEXTURE3,
    		GL_TEXTURE4,
    		GL_TEXTURE5, 
    		GL_TEXTURE6,
    		GL_TEXTURE7,
    		GL_TEXTURE8,
    		GL_TEXTURE9,
    		GL_TEXTURE10,
    		GL_TEXTURE11,
    		GL_TEXTURE12,
    		GL_TEXTURE13,
    		GL_TEXTURE14,
    		GL_TEXTURE15,
    		GL_TEXTURE16,
    		GL_TEXTURE17,
    		GL_TEXTURE18,
    		GL_TEXTURE19,
    		GL_TEXTURE20,
    		GL_TEXTURE21,
    		GL_TEXTURE22,
    		GL_TEXTURE23,
    		GL_TEXTURE24,
    		GL_TEXTURE25,
    		GL_TEXTURE26,
    		GL_TEXTURE27,
    		GL_TEXTURE28,
    		GL_TEXTURE29,
    		GL_TEXTURE30,
    		GL_TEXTURE31
    	};
    
		
		bool Program::isSupported() {
			return Ext::getInstance()->isSupported( Ext::VertexProgram_ARB );
		}
		
    
        Program::Program() {
			if(!isSupported())
				srlThrowErrorAsException(ProgramNotSupported, "Program are not available on your harware");
			
			mId = glCreateProgram();
			mLinked = false;
        }
        
        
        Program::Program(gl::Shader *vs, gl::Shader *fs) {
			if(!isSupported())
				srlThrowErrorAsException(ProgramNotSupported, "Program are not available on your harware");
				
			mId = glCreateProgram();
			mLinked = false;
			
            if(vs!=0) glAttachShader(mId, vs->getId());
            if(fs!=0) glAttachShader(mId, fs->getId());
            if(vs!=0 && fs!=0)
                link();
        }
		
		Program::Program(std::string vsPath, std::string fsPath) {
			if(!isSupported())
				srlThrowErrorAsException(ProgramNotSupported, "Program are not available on your harware");
			
			mId = glCreateProgram();
			mLinked = false;
			
            Shader vs(Shader::VertexShader, vsPath);
			Shader fs(Shader::FragmentShader, fsPath);
			glAttachShader(mId, vs.getId());
			glAttachShader(mId, fs.getId());
			
			link();
		}
		
		Program::Program(std::string filepath) {
			if(!isSupported())
				srlThrowErrorAsException(ProgramNotSupported, "Program are not available on your harware");
		
			mId = glCreateProgram();
			mLinked = false;
			
			loadProgram(filepath);
		}
		
        Program::~Program() {
            //glDeleteObject(mId);
			glDeleteProgram(mId);
        }
    
    
    
    
    
        void Program::attachShader(gl::Shader *shader) {
			glAttachShader(mId, shader->getId());
        }
        
        
        void Program::detachShader(gl::Shader *shader) {
			glDetachShader(mId, shader->getId());
        }
    
    
        Error Program::link() {
            glLinkProgram(mId);
			
            if(!isLinked())
				srlReturnError(ProgramLinkFailed, "Program link failed");
			
			mLinked = true;
			srlReturnNoError();
        }
        
        
        
		
		Error Program::loadProgram(std::string filepath) {
			std::ifstream file(filepath.c_str(), std::ifstream::in);
			
			std::string line, vsMain, fsMain, vsHeader, fsHeader;
			int attribNb, outputNb;
			char state = 0;
			
			vsHeader = "#version 130\n";
			fsHeader = "#version 130\n";
			
			while(file.good()) {
				std::getline(file, line);
				if(line == "[Attrib]") state = 2;
				else if(line == "[Output]") state = 3;
				else if(line == "[Vertex Shader]") state = 4;
				else if(line == "[Fragment Shader]") state = 5;
				else switch(state) {
					case 1: {
					break; }
					
					case 2: case 3 : {
						line.erase(line.find_last_not_of(" \t") + 1);
						line.erase(0, line.find_first_not_of(" \t"));
						if(line == "") break;
						
						if(state == 2) {
							std::string attribName = line.substr(line.find_last_of(" \t"));
							glBindAttribLocation(mId, attribNb, attribName.c_str());
							attribNb++;
							vsHeader += "in " + line + ";\n";
						}
						else if(state == 3) {
							std::string outputName = line.substr(line.find_last_of(" \t"));
							glBindFragDataLocation(mId, outputNb, outputName.c_str());
							outputNb++;
							fsHeader += "out " + line + ";\n";
						}
					break; }
					
					case 4: {
						vsMain += line + "\n";
					break; }
				
					case 5: {
						fsMain += line + "\n";
					break; }
					
				}
			}
			Shader* vs = new Shader(Shader::VertexShader);
			Shader* fs = new Shader(Shader::FragmentShader);
			vs->loadFromMem(vsHeader+vsMain);
			fs->loadFromMem(fsHeader+fsMain);
			vs->compile();
			fs->compile();
			printf("VS: %s", vs->getLog().c_str());
			printf("FS: %s", fs->getLog().c_str());
			glAttachShader(mId, vs->getId());
			glAttachShader(mId, fs->getId());
			link();
			printf("Prog: %s", getLog().c_str());
			
			srlReturnNoError();
		}
		
		
		
        
        bool Program::isLinked() {
            GLint success;
            glGetProgramiv(mId, GL_LINK_STATUS, &success);
            mLinked = (success == GL_TRUE) ? true : false;
            return mLinked;
        }
		
        
        
        
        void Program::use() {
            Context::getCurrent()->bind(this);
        }
        
        void Program::unuse() {
            Context::getCurrent()->unbindProg();
        }
        
        
        void Program::useGL() {
            //glUseProgramObject(mId);
			glUseProgram(mId);
        }
        
		void Program::unuseGL() {
			//glUseProgramObject(0);
			glUseProgram(0);
		}
        
        
        
    
        std::string Program::getLog() {
            GLint infologLength;
            //glGetObjectParameteriv(mId, GL_OBJECT_INFO_LOG_LENGTH_ARB, &infologLength);
			glGetProgramiv(mId, GL_INFO_LOG_LENGTH, &infologLength);
            if(infologLength > 0) {
    		    char *infoLog = new char[infologLength];
    		    glGetProgramInfoLog(mId, infologLength, NULL, infoLog);
    		    std::string str(infoLog, infologLength);
    		    delete[] infoLog;
    		    return str;
            }
			return std::string("");
        }
        
        
        
        
        void Program::uniform(std::string var, float x) {
            glUniform1f(glGetUniformLocation(mId, var.c_str()), x);
        }
    
        void Program::uniform(std::string var, float x, float y) {
            glUniform2f(glGetUniformLocation(mId, var.c_str()), x, y);
        }
		
        void Program::uniform(std::string var, float x, float y, float z) {
            glUniform3f(glGetUniformLocation(mId, var.c_str()), x, y, z);
        }
		
        void Program::uniform(std::string var, float x, float y, float z, float w) {
            glUniform4f(glGetUniformLocation(mId, var.c_str()), x, y, z, w);
        }
		
		
		
        void Program::uniform(std::string var, int x) {
            glUniform1i(glGetUniformLocation(mId, var.c_str()), x);
        }
		
        void Program::uniform(std::string var, int x, int y) {
            glUniform2i(glGetUniformLocation(mId, var.c_str()), x, y);
        }
		
		void Program::uniform(std::string var, int x, int y, int z) {
            glUniform3i(glGetUniformLocation(mId, var.c_str()), x, y, z);
        }
		
        void Program::uniform(std::string var, int x, int y, int z, int w) {
            glUniform4i(glGetUniformLocation(mId, var.c_str()), x, y, z, w);
        }
		
		
		
        void Program::uniform(std::string var, vec2 vec) {
			glUniform2f(glGetUniformLocation(mId, var.c_str()), vec.x, vec.y);
		}
		
		void Program::uniform(std::string var, vec3 vec) {
			glUniform3f(glGetUniformLocation(mId, var.c_str()), vec.x, vec.y, vec.z);
		}
	
		void Program::uniform(std::string var, rect r) {
			glUniform4f(glGetUniformLocation(mId, var.c_str()), r.x, r.y, r.w, r.h);
		}
		
		
		
        void Program::uniform(std::string var, mat4 val) {
            glUniformMatrix4fv(glGetUniformLocation(mId, var.c_str()), 1, GL_FALSE, val.array());
        }
    
	
	
        void Program::uniform(std::string var, ITexture *tex, int i) {
			if(tex == NULL) return;
            tex->bind(i);
            // glUniform1i(glGetUniformLocation(mId, var.c_str()), i);
        }
        
    };
    
};
