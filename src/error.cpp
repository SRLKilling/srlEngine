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

#include <SRL/error.hpp>
#include <iostream>
#include <sstream>

namespace srl {
		
	Error Error::mLastError;
	
	Error::Error() {
		mType = Error::NoError;
		mInfo = "No error occured";
		mFunc = "Error::Error()";
		mFile = __FILE__;
		mLine = __LINE__;
		
		mLastError = *this;
	}
	
	Error::Error(Error::ErrorType type, std::string info, std::string func, std::string file, int line) {
		mType = type;
		mInfo = info;
		mFunc = func;
		mFile = file;
		mLine = line;
		
		if(type != NoError) std::cout << what() << std::endl;
		
		mLastError = *this;
	}
	
	Error::Error(bool success) {
		if(success) {
			mType = Error::NoError;
			mInfo = "No error occured ; function return true";
			mFunc = "Error::Error(bool)";
			mFile = __FILE__;
			mLine = __LINE__;
		}
		else {
			mType = UnknownError;
			mInfo = "Unknown error ; function return false";
			mFunc = "Error::Error(bool)";
			mFile = "Unknown";
			mLine = 0;
		}
		
		mLastError = *this;
	}
	
	Error::Error(const Error& e) {
		mType = e.mType;
		mInfo = e.mInfo;
		mFile = e.mFile;
		mLine = e.mLine;
	}
	
	void Error::operator=(const Error& e) {
		mType = e.mType;
		mInfo = e.mInfo;
		mFile = e.mFile;
		mLine = e.mLine;
	}
	
	Error::operator bool() const {
		return mType == NoError;
	}
	
	bool Error::operator==(Error::ErrorType type) {
		return mType == type;
	}
	
	bool Error::operator!=(Error::ErrorType type) {
		return mType != type;
	}
	
	bool Error::operator!() {
		return mType != NoError;
	}
	
	std::string Error::what() {
		if(mType == NoError)
			return "[Info] No error occurred \n\n";
	
		std::stringstream out;
		out << "[Error] occured in " << mFile;
		out << " (" << mLine << ") :\n";
		out << mFunc << "\n";
		out << mInfo << "\n\n";
		return out.str();
	}
	
	Error::ErrorType Error::type() {
		return mType;
	}
	
	std::string Error::info() {
		return mInfo;
	}
	
	std::string Error::file() {
		return mFile; 
	}
	
	int Error::line() {
		return mLine;
	}
	
	Error Error::getLastError() {
		return mLastError;
	}
	
	gl::Error Error::getLastGLError() {
		return gl::Error::getLastError();
	}
		
};