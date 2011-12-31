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

#ifndef DefineHeaderITexture
#define DefineHeaderITexture
#include <SRL/environment.hpp>

namespace srl {

    /// Contains all OpenGL implementation
    namespace gl {

        /// C++ implementation of OpenGL Texture
        class SRLAPI ITexture {
            public:
			
                ////////////////////////////////////////////////////////////
                /// Default Constructor

                ITexture();
				

                ////////////////////////////////////////////////////////////
                /// Destructor

                ~ITexture();


                ////////////////////////////////////////////////////////////
                /// Bind the texture

                void bind(int i = 0);


                ////////////////////////////////////////////////////////////
                /// Unbind the texture

                static void unbind();
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc an empty texture

                virtual Error create() = 0;
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc the texture and fill it with texels
				///
				/// \param texels : Texels array to load
				
                virtual Error create(unsigned char* texels) = 0;


                ////////////////////////////////////////////////////////////
                /// Generate mipmap if possible using extensions glGenerateMipmapARB

            	void generateMipmap();

                ////////////////////////////////////////////////////////////
                /// Set texture parameter (Wraping parameters)
                ///
                /// \param param : Texture parameter to change
                /// \param value : Value to set
                /// \return True if param and values are corrects

                bool setParams(Env::TexWrapParams param, Env::TexWrapValues value);

                ////////////////////////////////////////////////////////////
                /// Set texture parameter (Filter parameters)
                ///
                /// \param param : Texture parameter to change
                /// \param value : Value to set
                /// \return True if param and values are corrects

                bool setParams(Env::TexFilterParams param, Env::TexFilterValues value);

                ////////////////////////////////////////////////////////////
                /// Set texture parameter (Comparaison parameters)
                ///
                /// \param param : Texture parameter to change
                /// \param value : Value to set
                /// \return True if param and values are corrects

                bool setParams(Env::TexCompareParams param, Env::TexCompareValues value);

                ////////////////////////////////////////////////////////////
                /// Set texture parameter (LOD parameters)
                ///
                /// \param param : Texture parameter to change
                /// \param value : Value to set
                /// \return True if param and values are corrects

                bool setParams(Env::TexLODParams param, float value);

                ////////////////////////////////////////////////////////////
                /// Set texture parameter (Mipmap Levels parameters)
                ///
                /// \param param : Texture parameter to change
                /// \param value : Value to set
                /// \return True if param and values are corrects

                bool setParams(Env::TexLevelParams param, int value);
				
	
            protected:
				void bindGL();
				static void unbindGL();
				friend class Context;
			
                GLuint mId;
                GLenum mTarget;
				
				friend class FrameBuffer;
        };

    };

};

#endif