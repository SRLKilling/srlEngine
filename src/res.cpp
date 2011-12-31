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

#include <iostream>
#include <sstream>

#include <SRL/Environment.hpp>
#include <SRL/res.hpp>
//#include <physfs.h>
//#include <SOIL.h>

namespace srl {
	const std::string trim(const std::string& pString, const std::string& pWhitespace = " \t") {
		const size_t beginStr = pString.find_first_not_of(pWhitespace);
		if (beginStr == std::string::npos)
			return "";

		const size_t endStr = pString.find_last_not_of(pWhitespace);
		const size_t range = endStr - beginStr + 1;

		return pString.substr(beginStr, range);
	}

	const std::string reduce(const std::string& pString, const std::string& pFill = " ", const std::string& pWhitespace = " \t") {
		std::string result(trim(pString, pWhitespace));

		size_t beginSpace = result.find_first_of(pWhitespace);
		while (beginSpace != std::string::npos) {
			const size_t endSpace =
							result.find_first_not_of(pWhitespace, beginSpace);
			const size_t range = endSpace - beginSpace;

			result.replace(beginSpace, range, pFill);

			const size_t newStart = beginSpace + pFill.length();
			beginSpace = result.find_first_of(pWhitespace, newStart);
		}

		return result;
	}

	res* res::mRes = NULL;
	
    res::res() {
		//PHYSFS_init(NULL);
		mArchiveOpened = "";
	}
	
	res::~res() {
		//PHYSFS_deinit();
	}
    
	Error res::openArchive(std::string path, bool autoClose) {
		/*if(mRes == NULL) mRes = new res();////////////////////////////////////
		
		if(mRes->mArchiveOpened != "") {
			if(autoClose) closeArchive();
			else srlReturnError(ArchiveAlreadyOpened, "Another archive is already opened. Close this one with res::closeArchive before openging another one");
		}
			
		PHYSFS_addToSearchPath(path.c_str(), 1);
		mRes->mArchiveOpened = path;
		
		if(!PHYSFS_exists("archive.cfg"))
			srlReturnError(BadArchiveEmptyConfig, "You're trying to open a bad archive : there's not config file \"archive.cfg\" within it");
		
		PHYSFS_file* file = PHYSFS_openRead("archive.cfg");
		int bufferSize = PHYSFS_fileLength(file);
		unsigned char* fileBuffer = new unsigned char[bufferSize];
		PHYSFS_read(file, fileBuffer, 1, bufferSize);
		PHYSFS_close(file);*//////////////////////////////////////////////
		
		/*int cLine = 1, cChar = 0;
		bool inComment = false;
		bool inGroup = false;
		bool lineUsed = false;
		bool inKey = false;
		bool inValue = false;
		int mKeyStart = 0, mKeyEnd = 0;
		int mValueStart = 0, mValueEnd = 0;
		
		for(int i = 0; i < fileLength; i++) {
			cChar++;
			if( mCfg[i] == '\n' ) {
				if(inGroup)
					printf("[%i] Missing end of group definition ']'\n", cLine);
				if(inComment)
					inComment = false;
				
				mLine++;
				cChar = 0;
				continue;
			}
			
			if(inComment) continue;
			
			if( mCfg[i] == ';' ) inComment = true; continue;
			
			if( mCfg[i] == '\t' || mCfg[i] == '\v' || mCfg[i] == ' ')
				continue;
			
			if( mCfg[i] == '=' && inKey ) {
				inKey = false; inValue = true;
				continue;
			}
			
			if( (mCfg[i] >= 45 && mCfg[i] <= 90) || (mCfg[i] >= 97 && mCfg[i] <= 122) {
				if(!inKey && !inValue) {
					inKey = true;
					mKeyStart = i;
					mKeyEnd = i;
				}
				else if(inKey) {
					mKeyEnd = i;
				}
				else if(inValue && mValueEnd == 0) {														0561999431
					mValueStart = i;
					mValueEnd = i;
				}
				else if(inValue) {
					mValueEnd = i;
				}
			} 
		}*/
		
		/*class stdStream : public std::istream, public std::streambuf {////////////////////////////////////////////
			public:
				stdStream( const char * begin, const char * end ) : std::istream( this ) {
					setg( const_cast<char *>(begin), const_cast<char *>(begin), const_cast<char *>(end) );
				}
		};
		
		stdStream fileStream((char*)fileBuffer, (char*)(&fileBuffer[bufferSize]));
		
		std::string section = "General";
		for (std::string line; std::getline(fileStream, line);) {
			line = trim(line);
			if(line[0] == '#' || line[0] == ';')
				continue;
				
			if(line[0] == '[') {
				int end = line.find_first_of("]");
				section = trim(line.substr(1, end-1));
				continue;
			}
			
			size_t equal = line.find_first_of("=");
			std::string key( reduce(line.substr(0, equal-1)) );
			std::string value( trim(line.substr(equal+1, line.size() - (equal+1) -(fileStream.eof()?0:1))) );
			mRes->mConfig[section][key] = value;
		}*////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/*for(int i = 0; i < bufferSize+1; i++) {
			if(mCfg[i] == '=') {
				/*if(mEqualPos > i)
					srlReturnNoError();
				else*/
					/*mEqualPos = i;
			}
			
			if(mCfg[i] == '\n' || mCfg[i] == 26) {
				std::string key((char*)&mCfg[mLineStart], mEqualPos - mLineStart);
				std::string value((char*)&mCfg[mEqualPos+1], i-1 - (mEqualPos+1));
				std::cout << "\"" << value << "\"" << "   /  "<< i << "    " << mCfg[i] << "    " << mCfg[i-1] << std::endl;
				key = reduce(key); value = reduce(value);
				mRes->mConfig[key] = value;
				mLineStart = i+1;
			}
		}*/
		
		
		
		srlReturnNoError();
	}
	
	bool res::sectionExists(std::string section) {
		return mRes->mConfig.find(section) != mRes->mConfig.end();
	}
	
	bool res::confExists(std::string section, std::string key) {
		if(!sectionExists(section)) return false;
		return mRes->mConfig[section].find(key) != mRes->mConfig[section].end();
	}
	
	std::string res::getConf(std::string section, std::string key) {
		return confExists(section, key) ? mRes->mConfig[section][key] : "";
	}
	
	int res::getConfAsInt(std::string section, std::string key) {
		if(!confExists(section, key))
			return 0;
			
		int convertedValue;
		std::istringstream buffer(mRes->mConfig[section][key]);
		buffer >> convertedValue;
		return convertedValue;
	}
	
	float res::getConfAsFloat(std::string section, std::string key) {
		if(!confExists(section, key))
			return 0.0;
			
		float convertedValue;
		std::istringstream buffer(mRes->mConfig[section][key]);
		buffer >> convertedValue;
		return convertedValue;
	}
	
	
	void res::closeArchive() {
		if(mRes == NULL) mRes = new res();
		
		//PHYSFS_removeFromSearchPath(mRes->mArchiveOpened.c_str()); ///////////////////////////////////////
		mRes->mConfig.clear();
		mRes->mArchiveOpened = "";
	}
	
	bool res::fileExists(std::string path) {
		//return PHYSFS_exists(path.c_str()) != 0;
	}
	bool res::fileExists(std::string section, std::string key) {
		//return PHYSFS_exists( getConf(section, key).c_str() ) != 0;
	}
	
	unsigned char* res::getFileBuffer(std::string path, int* bufferSize) {
		/*PHYSFS_file* mFile = PHYSFS_openRead(path.c_str());
		
		*bufferSize = PHYSFS_fileLength(mFile);
		unsigned char* mBuffer = new unsigned char[*bufferSize];
		PHYSFS_read(mFile, mBuffer, 1, *bufferSize);
		
		PHYSFS_close(mFile);
		return mBuffer;*/
	}
	
	unsigned char* res::getFileBuffer(std::string section, std::string key, int* bufferSize) {
		return getFileBuffer( getConf(section, key), bufferSize );
	}
	
	unsigned char* res::getTexture2DBuffer(std::string path, int* width, int* height, int* channels) {
		int mFileSize;
		unsigned char* mBuffer = getFileBuffer(path, &mFileSize);
		unsigned char* mTexels = NULL;//SOIL_load_image_from_memory(mBuffer, mFileSize, width, height, channels, SOIL_LOAD_AUTO);
		delete[] mBuffer;
		return mTexels;
	}
	unsigned char* res::getTexture2DBuffer(std::string section, std::string key, int* width, int* height, int* channels) {
		return getTexture2DBuffer( getConf(section, key), width, height, channels );
	}
	
	gl::Texture2D* res::getTexture2D(std::string path) {
		gl::Texture2D* mTex = NULL;
		/*int width, height, channels;
		unsigned char* mTexels = getTexture2DBuffer(path, &width, &height, &channels);
		
		switch(channels) {
			case 1: mTex = gl::Texture2D::getLuminanceTexture();		break;	
			case 2: mTex = gl::Texture2D::getLuminanceAlphaTexture();	break;
			case 3: mTex = gl::Texture2D::getRgbTexture(); 				break;
			case 4: mTex = gl::Texture2D::getRgbaTexture();				break;
		}
		
		mTex->bind();
		mTex->create(width, height, mTexels);
		mTex->generateMipmap();
		mTex->unbind();*/
		return mTex;
	}
	
	gl::Texture2D* res::getTexture2D(std::string section, std::string key) {
		return getTexture2D( getConf(section, key) );
	}
	
	gl::TextureArray* res::getTextureArray(std::string section) {
		int textureCount = getConfAsInt(section, "textureCount");
		
		int baseWidth, baseHeight, baseChannels;
		unsigned char* buffer = getTexture2DBuffer(section, "texture1", &baseWidth, &baseHeight, &baseChannels);
		
		gl::TextureArray* texture = new gl::TextureArray();
		/*texture->bind();
		texture->create(baseWidth, baseHeight, textureCount);
		texture->subData(0, 0, baseWidth, baseHeight, 0, buffer);
		
		delete[] buffer;
		int width, height, channels;
		for(int i = 1; i < textureCount; i++) {
			std::stringstream stream;
			stream << "texture" << i +1;
			unsigned char* buffer = getTexture2DBuffer(section, stream.str(), &width, &height, &channels);
			
			if(baseWidth != width && baseHeight != height)
				return NULL;
				
			texture->subData(0, 0, width, height, i, buffer);
			delete[] buffer;
		}
		texture->generateMipmap();
		texture->unbind();*/
		return texture;
	}
	
};