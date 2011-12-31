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

#ifndef DefineHeaderEnvironment
#define DefineHeaderEnvironment

#include <SRL/generalConfig.hpp>

// Os defines
#if defined(WIN32)
#	define SRL_WIN
#	define SRL_WGL
#elif defined(UNIX)
#	define SRL_UNIX
#	define SRL_GLX
#elif defined(APPLE)
#	define SRL_APPLE
#	define SRL_GLX
#endif
    
// Radiant/Degrees convertion
#define PI  3.14159265358979323846
#define ToRadiant(a) a*(PI/180.0)
#define ToDegrees(a) a*(180.0/PI)

// Useful pointer operation
#define srlCheckPtr(ptr) 		if(ptr == NULL) return;
#define srlCheckPtrR(ptr, ret)	if(ptr == NULL) return ret;
#define srlReturnPtr(ptr)		if(ptr != NULL) return ptr;

// Homemade Foreach
#define	srlMapForeach(key_type, value_type, value_name, map_name) for(std::map<key_type, value_type>::iterator it = map_name.begin(); it != map_name.end(); it++) { key_type key = it->first; value_type value_name = it->second;

// Includes
#ifndef SRL_HOMEMADE_EXT
#	include <GL/glew.h>
#else
#	include <GL/gl.h>
#	include <GL/glu.h>
#endif
#include <string>
	
#ifndef SRLAPI
   #define SRLAPI 
#endif
	
namespace srl {
	
    namespace Env {
        
        /**********************************************************/
        /***** Context                                            */
        
        // OpenGL versions
        enum ContextOpenGLVersion {
            Ver_4_1 = 17,
            Ver_4_0 = 18,
            
            Ver_3_3 = 12,
            Ver_3_2 = 13,
            Ver_3_1 = 14,
            Ver_3_0 = 15,
            
            Ver_2_1 = 9,
            Ver_2_0 = 10,
            
            Ver_1_5 = 1,
            Ver_1_4 = 2,
            Ver_1_3 = 3,
            Ver_1_2_1 = 4,
            Ver_1_2 = 5,
            Ver_1_1 = 6,
            Ver_1_0 = 7,
        };
        
        
        /**********************************************************/
        /***** Texture Params                                     */
    
        //***** Wrap *****
        enum TexWrapParams {
            WrapS = 0x2802,
            WrapT = 0x2803,
            WrapR = 0x8072
        };
        enum TexWrapValues {
            ClampToEdge = 0x812F,
            Repeat = 0x2901,
            MirroredRepeat = 0x8370
        };
    
        //***** Filter *****
        enum TexFilterParams {
            MinFilter = 0x2801,
            MagFilter = 0x2800
        };
        enum TexFilterValues {
            Nearest = 0x2600,
            Linear = 0x2601,
            NearestMipmapNearest = 0x2700,
            NearestMipmapLinear = 0x2702,
            LinearMipmapNearest = 0x2701,
            LinearMipmapLinear = 0x2703
        };
    
        //***** Compare *****
        enum TexCompareParams {
            CompareMode = 0x884C,
            CompareFun = 0x884D
        };
        enum TexCompareValues {
            None = 0x0000,
            CompareR = 0x884E,
            LEqual = 0x0203,
            GEqual = 0x0206,
            Equal = 0x0202,
            NotEqual = 0x0205,
            Less = 0x0201,
            Greater = 0x0204,
            Always = 0x0207,
            Never = 0x0200
        };
    
        //***** LOD *****
        enum TexLODParams {
            MinLOD = 0x813A,
            MaxLOD = 0x813B,
        };
        //***** Mimpap Leveling *****
        enum TexLevelParams {
            MaxLevel = 0x813D,
            BaseLevel = 0x813C
        };
        
        /**********************************************************/
        /***** Mesh Drawing                                       */
        enum DrawingPrimitive {
            Triangles = 0x0004,
            Quads = 0x0007
        };
        
        enum SkinType {
            Auto,
            VboSkin,
            VaSkin
        };
        
        enum RenderMode {
            NormalMode,
            SelectMode,
            RenderToTexture
        };
          
        
        /**********************************************************/
        /***** Object Type                                        */
        enum ObjectType {
            Object,
            ResManagedObject,
            ContenerObject
        };
        
        
        /**********************************************************/
        /***** Saving/Loading Errors                              */
        enum SavingError {
            FileError
        };
        
        ///
        /// \fn void Init()
        /// \brief Initialize openGL environment variable
        ///
        void Init();
        
        extern int MaxTexSize;
        
    };

};

#include <SRL/opengl/error.hpp>

#endif
