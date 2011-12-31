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

#ifndef DefineHeaderTextureArray
#define DefineHeaderTextureArray
#include <SRL/environment.hpp>

#include <SRL/opengl/itexture.hpp>
#include <SRL/maths/rect.hpp>
#include <vector>

namespace srl {

    /// Contains all OpenGL implementation
    namespace gl {

        /// C++ implementation of OpenGL Texture Array
        class SRLAPI TextureArray : public ITexture {
            public:
			
                ////////////////////////////////////////////////////////////
                /// Default Constructor

                TextureArray();
				
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param textureCount : Number of texture in the array

                TextureArray(int textureCount);
				
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param width : Textures's width in the array
                /// \param height : Textures's width in the array

                TextureArray(int width, int height);
				
                ////////////////////////////////////////////////////////////
                /// Constructor
                ///
                /// \param width : Textures's width in the array
                /// \param height : Textures's width in the array
                /// \param textureCount : Number of texture in the array

                TextureArray(int width, int height, int textureCount);



                ////////////////////////////////////////////////////////////
                /// Load the texture (using SOIL)
                ///
                /// \param filespath : Vector containing paths of textures to load

            	bool load(std::vector<std::string> filespath);
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc an empty texture array

                Error create();
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc the texture array and fill it with texels
				///
				/// \param texels : Texels array to load
				
                Error create(unsigned char* texels);
				
				
            	////////////////////////////////////////////////////////////
                /// Alloc an empty texture array of the given size
				///
				/// \param width : Textures's width in the array
				/// \param height : Textures's height in the array
				
                Error create(int width, int height);
				
				////////////////////////////////////////////////////////////
                /// Alloc a texture of the given size and fill it with texels
				///
				/// \param width : Textures's width in the array
				/// \param height : Textures's height in the array
				/// \param texels : Texels array to load

                Error create(int width, int height, unsigned char* texels);
				
				////////////////////////////////////////////////////////////
                /// Alloc an empty texture array
				///
				/// \param textureCount : Number of texture

                Error create(int numberCount);
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a texture array and fill it with texels
				///
				/// \param textureCount : Number of texture
				/// \param texels : Texels array to load

                Error create(int numberCount, unsigned char* texels);
				
				////////////////////////////////////////////////////////////
                /// Alloc an empty texture array of the given size
				///
				/// \param width : Textures's width in the array
				/// \param height : Textures's height in the array
				/// \param textureCount : Number of texture

                Error create(int width, int height, int numberCount);
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a texture array of the given size and fill it with texels
				///
				/// \param width : Textures's width in the array
				/// \param height : Textures's height in the array
				/// \param textureCount : Number of texture
				/// \param texels : Texels array to load

                Error create(int width, int height, int numberCount, unsigned char* texels);
				
				////////////////////////////////////////////////////////////
                /// Send sub data
				/// \remark You need to create the texture with a call to create(); method
				///
				/// \param x : Sub data's x position
				/// \param y : Sub data's y position
				/// \param width : Sub data's width
				/// \param height : Sub data's height
				/// \param layer : Layer to send data
				/// \param texels : Texels array to load

                Error subData(int x, int y, int width, int height, int layer, unsigned char* texels);
				
				////////////////////////////////////////////////////////////
                /// Send sub data
				/// \remark You need to create the texture with a call to create(); method
				
				/// \param rect : Rect of the subdata (position on the texture, and size of the subdata);
				/// \param layer : Layer to send data
				/// \param texels : Texels array to load

                Error subData(rect rect, int layer, unsigned char* texels);
				

                /*////////////////////////////////////////////////////////////
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

                int getTextureType();*/
				
				void setTextureCount(int textureCount);
				bool setSize(int width, int height);
				bool setSize(int width, int height, int textureCount);
				
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new RGBA TextureArray
                ///
                /// \return New TextureArray pointer
	
				static TextureArray* getRgbaTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new RGB TextureArray
                ///
                /// \return New TextureArray pointer
				
				static TextureArray* getRgbTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new Alpha TextureArray
                ///
                /// \return New TextureArray pointer
				
				static TextureArray* getAlphaTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new Luminance TextureArray
                ///
                /// \return New TextureArray pointer
				
				static TextureArray* getLuminanceTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new LuminanceAlpha TextureArray
                ///
                /// \return New TextureArray pointer
				
				static TextureArray* getLuminanceAlphaTexture();
				
				
				////////////////////////////////////////////////////////////
                /// Alloc a new depth component TextureArray
                ///
                /// \return New TextureArray pointer
				
				static TextureArray* getDepthTexture();
				
	
            protected:
                GLenum mFormat;
				
                int mHeight;
                int mWidth;
				int mTextureCount;

            friend class FrameBuffer;
        };

    };

};
#endif