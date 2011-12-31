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


#ifndef DefineHeaderContext
#define DefineHeaderContext

#include <SRL/Environment.hpp>
#include <SRL/maths/irect.hpp>
#include <SRL/maths/mat4.hpp>
#include <stack>

namespace srl {
    
    namespace SRLAPI gl {
        class Program;
        class ITexture;
        class FrameBuffer;
		class VertexBuffer;
		class IndexBuffer;
        class Frustum;
    
		class Context {
			public:
				struct FbConfig {
					FbConfig(int oglmajv = 3, int oglminv = 0, int cbits = 32, int rbits = 8, int gbits = 8, int bbits = 8, int abits = 8, int dbits = 24, int sbits = 8, int accbits = 0, int accrbits = 0, int accgbits = 0, int accbbits = 0, int accabits = 0, bool dbuffer = true, bool stereo = false) :
						 mOpenglMajorVersion(oglmajv), mOpenglMinorVersion(oglminv), mColorBits(cbits), mRedBits(rbits), mGreenBits(gbits), mBlueBits(bbits), mAlphaBits(abits), mDepthBits(dbits), mStencilBits(sbits), mAccumColorBits(accbits), mAccumRedBits(accrbits), mAccumGreenBits(accgbits), mAccumBlueBits(accbbits), mAccumAlphaBits(accabits), mDoubleBuffering(dbuffer), mStereoscopic(stereo) {};
					int mOpenglMajorVersion;
					int mOpenglMinorVersion;
					int mColorBits;
					int mRedBits;
					int mGreenBits;
					int mBlueBits;
					int mAlphaBits;
					int mDepthBits;
					int mStencilBits;
					int mAccumColorBits;
					int mAccumRedBits;
					int mAccumGreenBits;
					int mAccumBlueBits;
					int mAccumAlphaBits;
					int mAuxBuffers;
					bool mDoubleBuffering;
					bool mStereoscopic;
				};
				
				Context();
				virtual ~Context();
				
				virtual void makeCurrent() = 0;
				virtual void swap() = 0;
				
				// Proj
				
				void setPerspectiveProj(float fov, float aspect, float znear, float zfar);
				void usePerspective();
				float getAspect();
				float getFov();
				float getZNear();
				float getZFar();
				
				void setOrthogonalProj(float left, float right, float bottom, float top, float znear, float zfar);
				void useOrthogonal();
				
				void setProjectionMatrix(mat4 matrix);
				void updateProjection();
				mat4 getProjectionMatrix();
				
				// Modelview and transformations
				
				void look(vec3 eye, vec3 target, vec3 up, bool isRelativeTarget = true);
				
				void translate(float x, float y, float z);
				void rotate(float x, float y, float z);
				void rotate(float x, float y, float z, float w);
				void scale(float x, float y, float z);
				
				void setModelviewMatrix(mat4 matrix);
				void updateModelview();
				mat4 getModelviewMatrix();
				
				vec3 getEyePos();
				vec3 getTarget();
				vec3 getAbsoluteTarget();
				vec3 getVerticalVec();
				
				void computeFrustum();
				
				// Matrix Stack
				
				void pushModelview();
				Error popModelview();
				
				// MvProj
				
				mat4 getModelviewProjMatrix();
				
				// Viewport
				
				void setViewport(irect viewport);
				void resizeViewport(int w, int h);
				void resizeViewportDec(int wdec, int hdec);
				irect getViewport();
				
				// Binding
				
				void bind(Program* program);
				bool isBound(Program* program);
				void unbindProg();
				Program* getCurrentProg();
				
				void bind(ITexture* texture);
				bool isBound(ITexture* texture);
				void unbindTex();
				
				void bind(FrameBuffer* fbo);
				bool isBound(FrameBuffer* fbo);
				void unbindFbo();
				
				void bind(VertexBuffer* vbo);
				bool isBound(VertexBuffer* vbo);
				void unbindVbo();
				
				void bind(IndexBuffer* ibo);
				bool isBound(IndexBuffer* ibo);
				void unbindIbo();
				
				void unbindAll();
			
				static Context* getCurrent();
			
			protected:
				static void setCurrent(Context* context);
				static Context* mCurrentContext;
			
			private:
				// Persp
				struct PerspectiveInfo {
					float fov;
					float aspect;
					float znear;
					float zfar;
				};
				PerspectiveInfo mPerspInfo;
				mat4 mPerspMat;
				
				// Ortho
				struct OrthogonalInfo {
					float left;
					float right;
					float bottom;
					float top;
					float znear;
					float zfar;
				};
				OrthogonalInfo mOrthoInfo;
				mat4 mOrthoMat;
				
				// Proj
				mat4 mProjMat;
				
				// Modelview
				struct ModelViewInfo {
					vec3 eye;
					vec3 target;
					vec3 up;
				};
				ModelViewInfo mModelviewInfo;
				mat4 mModelviewMat;
				std::stack<mat4> mModelviewStack;
				
				
				irect mViewport;
				
				
				
				// Bound objects
				Program* mProgramBound;
				ITexture* mTextureBound;
				FrameBuffer* mFboBound;
				VertexBuffer* mVboBound;
				IndexBuffer* mIboBound;
				
		};
		
	};
    
};

#endif 
