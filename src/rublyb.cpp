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

#include <fstream>
#include <SRL/rublyb.hpp>

extern "C" {
	#include "ruby.h"
};

#include <SRL/maths/vec2.hpp>
#include <SRL/maths/vec3.hpp>

namespace srl {

	namespace rublyb {
	
		void init() {
			initBinding();
		}
		
		void initRuby() {
			static bool isInit = false;
			if(!isInit) {
				ruby_init();
				isInit = true;
			}
		}
		
		void initRublyb() {
			static bool isInit = false;
			if(!isInit) {
				initRuby();
				doFile("Rublyb.rb");
				isInit = true;
			}
		}
		
		void initBinding() {
			static bool isInit = false;
			if(!isInit) {
				initRublyb();
				isInit = true;
			}
		}
		
		void doFile(std::string filepath) {
			std::string source;
			std::ifstream file(filepath.c_str());
			if(file.is_open()){
				std::string line;
				while (std::getline(file, line)) {
					source += line;
					source += "\n";
				}
				source += '\0';
				rb_eval_string(source.c_str());
			}
			//rb_load_file(filepath.c_str());
		}
		
		void doMain(std::string mainpath) {
			doFile("main.rb");
			rb_funcall2(rb_cObject, rb_intern("main"), 0, NULL);
			//rb_funcall(rb_cObject, rb_intern("$main"), 0); 
		}
		
		template<>
		int fromRuby<int>(std::string name) {
			return NUM2INT(rb_gv_get(name.c_str()));
		}
		
		template<>
		float fromRuby<float>(std::string name) {
			return NUM2DBL(rb_gv_get(name.c_str()));
		}
		
		template<>
		vec2 fromRuby<vec2>(std::string name) {
			VALUE vec = rb_gv_get(name.c_str());
			VALUE x = rb_iv_get(vec, "@x");
			VALUE y = rb_iv_get(vec, "@y");
			return vec2(NUM2DBL(x), NUM2DBL(y));
		}
		
		template<>
		vec3 fromRuby<vec3>(std::string name) {
			VALUE vec = rb_gv_get(name.c_str());
			VALUE x = rb_iv_get(vec, "@x");
			VALUE y = rb_iv_get(vec, "@y");
			VALUE z = rb_iv_get(vec, "@z");
			return vec3(NUM2DBL(x), NUM2DBL(y), NUM2DBL(z));
		}
	};
	
};