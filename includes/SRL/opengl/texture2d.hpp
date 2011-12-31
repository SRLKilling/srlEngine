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

#ifndef DefineHeaderTexture2D
#define DefineHeaderTexture2D

#include <SRL/Environment.hpp>
#include <SRL/opengl/itexture.hpp>

namespace srl {

    /// Contains all OpenGL implementation
    namespace gl {

        /// C++ implementation of OpenGL 2D Texture
        class SRLAPI Texture2D : public ITexture {
            public:
			
                ////////////////////////////////////////////////////////////
                /// Default Constructor

                Texture2D();
				
				
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param width : Width of the texture
                /// \param height : Height of the texture

                Texture2D(int width, int height);
				

                ////////////////////////////////////////////////////////////
                /// Load the texture (using SOIL)
                ///
                /// \param filepath : Path of the image file

            	bool load(std::string filepath);
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc an empty texture

                Error create();
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc the texture and fill it with texels
				///
				/// \param texels : Texels array to load
				
                Error create(unsigned char* texels);
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc an empty texture of the given size
				///
				/// \param width : Width of the texture
				/// \param height : Height of the texture
				
                Error create(int width, int height);
				
				////////////////////////////////////////////////////////////
                /// Alloc a texture of the given size and fill it with texels
				///
				/// \param width : Width of the texture
				/// \param height : Height of the texture
				/// \param texels : Texels array to load

                Error create(int width, int height, unsigned char* texels);

                ////////////////////////////////////////////////////////////
                /// Set the width of the texture
                ///
                /// \param width New width of the texture
                /// \return True if the width is correct (power-of-two if necessary, and inferior to the max size supported by openGL)

                bool setWidth(int width);

                ////////////////////////////////////////////////////////////
                /// Set the height of the texture
                ///
                /// \param height New height of the texture
                /// \return True if the width is correct (power-of-two if necessary, and inferior to the max size supported by openGL)

                bool setHeight(int height);

                ////////////////////////////////////////////////////////////
                /// Set the width of the texture
                ///
                /// \param width New width of the texture
                /// \param height New height of the texture
                /// \return True if the size is correct (power-of-two if necessary, and inferior to the max size supported by openGL)

                bool setSize(int width, int height);

                ////////////////////////////////////////////////////////////
                /// Get texture's witdh
                ///
                /// \return Texture's witdh

                int getWidth();

                ////////////////////////////////////////////////////////////
                /// Get texture's height
                ///
                /// \return Texture's height

                int getHeight();

                ////////////////////////////////////////////////////////////
                /// Get format
                ///
                /// \return Format

                int getFormat();

                ////////////////////////////////////////////////////////////
                /// Get texture type
                ///
                /// \return Internal format

                int getTextureType();
				
				
				
				
				
				
				
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new RGBA Texture2D
                ///
                /// \return New texture2d pointer
	
				static Texture2D* getRgbaTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new RGB Texture2D
                ///
                /// \return New texture2d pointer
				
				static Texture2D* getRgbTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new Alpha Texture2D
                ///
                /// \return New texture2d pointer
				
				static Texture2D* getAlphaTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new Luminance Texture2D
                ///
                /// \return New texture2d pointer
				
				static Texture2D* getLuminanceTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new LuminanceAlpha Texture2D
                ///
                /// \return New texture2d pointer
				
				static Texture2D* getLuminanceAlphaTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new depth component Texture2D
                ///
                /// \return New texture2d pointer
				
				static Texture2D* getDepthTexture();
				
	
            protected:
                GLenum mFormat;
				
                int mHeight;
                int mWidth;

            friend class FrameBuffer;
        };

    };

};

#endif

