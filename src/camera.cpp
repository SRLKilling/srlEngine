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
#include <SRL/Environment.hpp>

#include <SRL/camera.hpp>
#include <SRL/opengl/context.hpp>

namespace srl {
	
	FpsCamera::FpsCamera(vec3 position, vec3 target) {
		target.normalize();
		
		mPosition = position;
		mTarget = target;
		mTarget = vec3(1.0, 0.0, 1.0);
		mTheta = 45.0;
		mPhi = 0.0;
	}
	
	FpsCamera::~FpsCamera() {
	
	}
	
	void FpsCamera::changeTarget(float theta, float phi, float sensibility) {
		mTheta += theta * sensibility;
		mPhi += phi * sensibility;
		
		if(mTheta < 0)
            mTheta = 360.0 + mTheta;
        if(mTheta > 360)
            mTheta = mTheta - 360;
            
        if(mPhi < -45)
            mPhi = -45;
        if( mPhi > 45)
            mPhi = 45;
        
        mTarget.x = cos(ToRadiant(mTheta));
        mTarget.y = sin(ToRadiant(mPhi));
        mTarget.z = sin(ToRadiant(mTheta));
	}
	
    void FpsCamera::forward(float d) {
        mPosition += mTarget * d;
    }
	
	void FpsCamera::back(float d) {
        mPosition -= mTarget * d;
    }
	
    void FpsCamera::left(float d) {
        mPosition.z -= cos(ToRadiant(mTheta)) * d;
        mPosition.x += sin(ToRadiant(mTheta)) * d;
    }
	
    void FpsCamera::right(float d) {
        mPosition.z += cos(ToRadiant(mTheta)) * d;
        mPosition.x -= sin(ToRadiant(mTheta)) * d;
    }
	
	void FpsCamera::look() {
		gl::Context::getCurrent()->look(vec3(mPosition.x, mPosition.y, mPosition.z), vec3(mTarget.x, mTarget.y, mTarget.z), vec3(0.0, 1.0, 0.0));
	}
	
};