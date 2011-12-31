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

#include <SRL/opengl/context.hpp>

#include <SRL/opengl/program.hpp>
#include <SRL/opengl/itexture.hpp>
#include <SRL/opengl/frameBuffer.hpp>
#include <SRL/opengl/vertexBuffer.hpp>
#include <SRL/opengl/indexBuffer.hpp>
#include <SRL/opengl/frustum.hpp>
#include <cmath>

namespace srl {

	namespace gl {

		Context::Context() {
			mTextureBound = NULL;
			mFboBound = NULL;
			mVboBound = NULL;
			mProgramBound = NULL;
		}
		
		Context::~Context() {
			
		}
		
		
		// Persp
		
		void Context::setPerspectiveProj(float fov, float aspect, float znear, float zfar) {
			mPerspInfo.fov = fov;
			mPerspInfo.aspect = aspect;
			mPerspInfo.znear = znear;
			mPerspInfo.zfar = zfar;
			
			mPerspMat.perspective(mPerspInfo.fov, mPerspInfo.aspect, mPerspInfo.znear, mPerspInfo.zfar);
		}
		
		void Context::usePerspective() {
			mProjMat = mPerspMat;
			updateProjection();
		}
		float Context::getAspect() {
			return mPerspInfo.aspect;
		}
		float Context::getFov() {
			return mPerspInfo.fov;
		}
		float Context::getZNear() {
			return mPerspInfo.znear;
		}
		float Context::getZFar() {
			return mPerspInfo.zfar;
		}
		
		
		// Ortho
		
		void Context::setOrthogonalProj(float left, float right, float bottom, float top, float znear, float zfar) {
			mOrthoMat.ortho(left, right, bottom, top, znear, zfar);
		}
		
		void Context::useOrthogonal() {
			mProjMat = mOrthoMat;
			updateProjection();
		}
		
		
		// Proj
		
		void Context::setProjectionMatrix(mat4 matrix) {
			mProjMat = matrix;
			updateProjection();
		}
		void Context::updateProjection() {
			if(mProgramBound != NULL)
				mProgramBound->uniform("srlProjectionMatrix", mProjMat);
		}
		mat4 Context::getProjectionMatrix() {
			return mProjMat;
		}
		
		
		
		
		
		// Modelview
		
		void Context::look(vec3 eye, vec3 target, vec3 up, bool isRelativeTarget) {
			mModelviewInfo.eye = eye;
			mModelviewInfo.up = up;
			mModelviewInfo.target = isRelativeTarget ? target : target - eye;
			
			mModelviewMat.look(mModelviewInfo.eye, mModelviewInfo.target, mModelviewInfo.up);
			
			updateModelview();
		}
		
		
		void Context::translate(float x, float y, float z) {
			mModelviewMat.translate(x, y, z);
			updateModelview();
		}
		void Context::rotate(float x, float y, float z) {
			mModelviewMat.rotate(x, y, z);
			updateModelview();
		}
		void Context::rotate(float x, float y, float z, float w) {
			mModelviewMat.rotate(x, y, z);
			updateModelview();
		}
		void Context::scale(float x, float y, float z) {
			mModelviewMat.scale(x, y, z);
			updateModelview();
		}
		
		
		vec3 Context::getEyePos() {
			return mModelviewInfo.eye;
		}
		vec3 Context::getTarget() {
			return mModelviewInfo.target;
		}
		vec3 Context::getAbsoluteTarget() {
			return mModelviewInfo.eye + mModelviewInfo.target;
		}
		vec3 Context::getVerticalVec() {
			return mModelviewInfo.up;
		}
		
		
		
		void Context::setModelviewMatrix(mat4 matrix) {
			mModelviewMat = matrix;
			updateModelview();
		}
		void Context::updateModelview() {
			if(mProgramBound != NULL)
				mProgramBound->uniform("srlModelViewMatrix", mModelviewMat);
		}
		mat4 Context::getModelviewMatrix() {
			return mModelviewMat;
		}
		
		
		
		mat4 Context::getModelviewProjMatrix() {
			return mProjMat * mModelviewMat;
		}
		
		
		
		void Context::setViewport(irect viewport) {
			mViewport = viewport;
			glViewport(mViewport.x, mViewport.y, mViewport.w, mViewport.h);
		}
		irect Context::getViewport() {
			return mViewport;
		}
		
		void Context::resizeViewport(int w, int h) {
			mViewport.resize(w,h);
			glViewport(mViewport.x, mViewport.y, mViewport.w, mViewport.h);
		}
		void Context::resizeViewportDec(int wdec, int hdec) {
			mViewport.resizeDec(wdec, hdec);
			glViewport(mViewport.x, mViewport.y, mViewport.w, mViewport.h);
		}
		
		
		
		
		
		void Context::computeFrustum() {
			gl::Frustum::getInstance()->compute();
		}
		
		
		
		void Context::pushModelview() {
			mModelviewStack.push( mModelviewMat );
		}
		
		Error Context::popModelview() {
			if(mModelviewStack.empty())
				srlReturnError(MatrixStackEmpty, "Cannot pop matrix because the matrix stack is empty");
				
			mModelviewMat = mModelviewStack.top();
			mModelviewStack.pop();
			updateModelview();
			srlReturnNoError();
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		void Context::bind(Program* program) {
			if(mProgramBound == program)
				return;
				
			if(program == NULL)
				unbindProg();
			else {
				mProgramBound = program;
				mProgramBound->useGL();
				mProgramBound->uniform("srlProjectionMatrix", mProjMat);
				mProgramBound->uniform("srlModelViewMatrix", mModelviewMat);
			}
		}		
		
		bool Context::isBound(Program* program) {
			return mProgramBound == program;
		}
		
		void Context::unbindProg() {
			mProgramBound = NULL;
			Program::unuseGL();
		}
		
		Program* Context::getCurrentProg() {
			return mProgramBound;
		}
		
		
		
		void Context::bind(ITexture* texture) {
			if(mTextureBound == texture)
				return;
				
				
			if(texture == NULL)
				unbindTex();
			else {
				mTextureBound = texture;
				mTextureBound->bindGL();
			}
		}
		
		bool Context::isBound(ITexture* texture) {
			return mTextureBound == texture;
		}
		
		void Context::unbindTex() {
			mTextureBound = NULL;
			ITexture::unbindGL();
		}
		
		
		
		void Context::bind(FrameBuffer* fbo) {
			if(mFboBound == fbo)
				return;
				
				
			if(fbo == NULL)
				unbindFbo();
			else {
				mFboBound = fbo;
				mFboBound->bindGL();
			}
		}
		
		bool Context::isBound(FrameBuffer* fbo) {
			return mFboBound == fbo;
		}
		
		void Context::unbindFbo() {
			mFboBound = NULL;
			FrameBuffer::unbindGL();
		}
		
		
		
		void Context::bind(VertexBuffer* vbo) {
			if(mVboBound == vbo)
				return;
				
				
			if(vbo == NULL)
				unbindVbo();
			else {
				mVboBound = vbo;
				mVboBound->bindGL();
			}
		}
		
		bool Context::isBound(VertexBuffer* vbo) {
			return mVboBound == vbo;
		}
		
		void Context::unbindVbo() {
			mVboBound = NULL;
			VertexBuffer::unbindGL();
		}
		
		
		
		void Context::bind(IndexBuffer* ibo) {
			if(mIboBound == ibo)
				return;
				
				
			if(ibo == NULL)
				unbindIbo();
			else {
				mIboBound = ibo;
				mIboBound->bindGL();
			}
		}
		
		bool Context::isBound(IndexBuffer* ibo) {
			return mIboBound == ibo;
		}
		
		void Context::unbindIbo() {
			mIboBound = NULL;
			IndexBuffer::unbindGL();
		}
		
		
		
		void Context::unbindAll() {
			unbindTex();
			unbindVbo();
			unbindFbo();
			unbindProg();
		}
		
		
		
		
		
		Context* Context::mCurrentContext = NULL;
		void Context::setCurrent(Context* context) {
			mCurrentContext = context;
		}
		Context* Context::getCurrent() {
			return mCurrentContext;
		}
		
	};
    
};
