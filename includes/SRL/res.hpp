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

#ifndef DefineHeaderRes
#define DefineHeaderRes

#include <SRL/Environment.hpp>
#include <SRL/opengl/texture2d.hpp>
#include <SRL/opengl/texturearray.hpp>
#include <SRL/error.hpp>
#include <map>

namespace srl {
	
    class SRLAPI res {
		public:
			static Error openArchive(std::string path, bool autoClose = false);
			
			static bool sectionExists(std::string section);
			static bool    confExists(std::string section, std::string key);
			
			static std::string  getConf(std::string section, std::string key);
			static int   		getConfAsInt(std::string section, std::string key);
			static float 		getConfAsFloat(std::string section, std::string key);
			
			static bool 			 fileExists(std::string path);
			static unsigned char* getFileBuffer(std::string path, int* bufferSize);
			static bool 			 fileExists(std::string section, std::string key);
			static unsigned char* getFileBuffer(std::string section, std::string key, int* bufferSize);
			
			static unsigned char* getTexture2DBuffer(std::string path, int* width, int* height, int* channels);
			static gl::Texture2D* getTexture2D		(std::string path);
			static unsigned char* getTexture2DBuffer(std::string section, std::string key, int* width, int* height, int* channels);
			static gl::Texture2D* getTexture2D		(std::string section, std::string key);
			
			static gl::TextureArray* getTextureArray(std::vector<std::string> paths);
			static gl::TextureArray* getTextureArray(std::string section);
			
			static void closeArchive();
			
		private:
			res();
			~res();
			static res* mRes;
			
			std::string mArchiveOpened;
			std::map<std::string, std::map<std::string, std::string> > mConfig;
	};

};

#endif