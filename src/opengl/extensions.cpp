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

#include <SRL/opengl/extensions.hpp>

#ifdef L3E_HOMEMADE_EXT

//-----------------------------------------------------------------------------
// Shader Extensions
//-----------------------------------------------------------------------------
PFNglGetShaderInfoLogARB           glGetShaderInfoLog            = 0;
PFNglGetShaderivARB                glGetShaderiv                 = 0;
PFNglVertexAttrib1dARB             glVertexAttrib1d              = 0;
PFNglVertexAttrib1dvARB            glVertexAttrib1dv             = 0;
PFNglVertexAttrib1fARB             glVertexAttrib1f              = 0;
PFNglVertexAttrib1fvARB            glVertexAttrib1fv             = 0;
PFNglVertexAttrib1sARB             glVertexAttrib1s              = 0;
PFNglVertexAttrib1svARB            glVertexAttrib1sv             = 0;
PFNglVertexAttrib2dARB             glVertexAttrib2d              = 0;
PFNglVertexAttrib2dvARB            glVertexAttrib2dv             = 0;
PFNglVertexAttrib2fARB             glVertexAttrib2f              = 0;
PFNglVertexAttrib2fvARB            glVertexAttrib2fv             = 0;
PFNglVertexAttrib2sARB             glVertexAttrib2s              = 0;
PFNglVertexAttrib2svARB            glVertexAttrib2sv             = 0;
PFNglVertexAttrib3dARB             glVertexAttrib3d              = 0;
PFNglVertexAttrib3dvARB            glVertexAttrib3dv             = 0;
PFNglVertexAttrib3fARB             glVertexAttrib3f              = 0;
PFNglVertexAttrib3fvARB            glVertexAttrib3fv             = 0;
PFNglVertexAttrib3sARB             glVertexAttrib3s              = 0;
PFNglVertexAttrib3svARB            glVertexAttrib3sv             = 0;
PFNglVertexAttrib4NbvARB           glVertexAttrib4Nbv            = 0;
PFNglVertexAttrib4NivARB           glVertexAttrib4Niv            = 0;
PFNglVertexAttrib4NsvARB           glVertexAttrib4Nsv            = 0;
PFNglVertexAttrib4NubARB           glVertexAttrib4Nub            = 0;
PFNglVertexAttrib4NubvARB          glVertexAttrib4Nubv           = 0;
PFNglVertexAttrib4NuivARB          glVertexAttrib4Nuiv           = 0;
PFNglVertexAttrib4NusvARB          glVertexAttrib4Nusv           = 0;
PFNglVertexAttrib4bvARB            glVertexAttrib4bv             = 0;
PFNglVertexAttrib4dARB             glVertexAttrib4d              = 0;
PFNglVertexAttrib4dvARB            glVertexAttrib4dv             = 0;
PFNglVertexAttrib4fARB             glVertexAttrib4f              = 0;
PFNglVertexAttrib4fvARB            glVertexAttrib4fv             = 0;
PFNglVertexAttrib4ivARB            glVertexAttrib4iv             = 0;
PFNglVertexAttrib4sARB             glVertexAttrib4s              = 0;
PFNglVertexAttrib4svARB            glVertexAttrib4sv             = 0;
PFNglVertexAttrib4ubvARB           glVertexAttrib4ubv            = 0;
PFNglVertexAttrib4uivARB           glVertexAttrib4uiv            = 0;
PFNglVertexAttrib4usvARB           glVertexAttrib4usv            = 0;
PFNglVertexAttribPointerARB        glVertexAttribPointer         = 0;
PFNglEnableVertexAttribArrayARB    glEnableVertexAttribArray     = 0;
PFNglDisableVertexAttribArrayARB   glDisableVertexAttribArray    = 0;
PFNglProgramStringARB              glProgramString               = 0;
PFNglBindProgramARB                glBindProgram                 = 0;
PFNglDeleteProgramsARB             glDeletePrograms              = 0;
PFNglGenProgramsARB                glGenPrograms                 = 0;
PFNglProgramEnvParameter4dARB      glProgramEnvParameter4d       = 0;
PFNglProgramEnvParameter4dvARB     glProgramEnvParameter4dv      = 0;
PFNglProgramEnvParameter4fARB      glProgramEnvParameter4f       = 0;
PFNglProgramEnvParameter4fvARB     glProgramEnvParameter4fv      = 0;
PFNglProgramLocalParameter4dARB    glProgramLocalParameter4d     = 0;
PFNglProgramLocalParameter4dvARB   glProgramLocalParameter4dv    = 0;
PFNglProgramLocalParameter4fARB    glProgramLocalParameter4f     = 0;
PFNglProgramLocalParameter4fvARB   glProgramLocalParameter4fv    = 0;
PFNglGetProgramEnvParameterdvARB   glGetProgramEnvParameterdv    = 0;
PFNglGetProgramEnvParameterfvARB   glGetProgramEnvParameterfv    = 0;
PFNglGetProgramLocalParameterdvARB glGetProgramLocalParameterdv  = 0;
PFNglGetProgramLocalParameterfvARB glGetProgramLocalParameterfv  = 0;
PFNglGetProgramivARB               glGetProgramiv                = 0;
PFNglGetProgramStringARB           glGetProgramString            = 0;
PFNglGetProgramInfoLogARB          glGetProgramInfoLog           = 0;
PFNglGetVertexAttribdvARB          glGetVertexAttribdv           = 0;
PFNglGetVertexAttribfvARB          glGetVertexAttribfv           = 0;
PFNglGetVertexAttribivARB          glGetVertexAttribiv           = 0;
PFNglGetVertexAttribPointervARB    glGetVertexAttribPointerv     = 0;
PFNglIsProgramARB                  glIsProgram                   = 0;

PFNglDeleteObjectARB               glDeleteObject                = 0;
PFNglGetHandleARB                  glGetHandle                   = 0;
PFNglDetachObjectARB               glDetachObject                = 0;
PFNglCreateShaderObjectARB         glCreateShaderObject          = 0;
PFNglShaderSourceARB               glShaderSource                = 0;
PFNglCompileShaderARB              glCompileShader               = 0;
PFNglCreateProgramObjectARB        glCreateProgramObject         = 0;
PFNglAttachObjectARB               glAttachObject                = 0;
PFNglLinkProgramARB                glLinkProgram                 = 0;
PFNglUseProgramObjectARB           glUseProgramObject            = 0;
PFNglValidateProgramARB            glValidateProgram             = 0;
PFNglUniform1fARB                  glUniform1f                   = 0;
PFNglUniform2fARB                  glUniform2f                   = 0;
PFNglUniform3fARB                  glUniform3f                   = 0;
PFNglUniform4fARB                  glUniform4f                   = 0;
PFNglUniform1iARB                  glUniform1i                   = 0;
PFNglUniform2iARB                  glUniform2i                   = 0;
PFNglUniform3iARB                  glUniform3i                   = 0;
PFNglUniform4iARB                  glUniform4i                   = 0;
PFNglUniform1fvARB                 glUniform1fv                  = 0;
PFNglUniform2fvARB                 glUniform2fv                  = 0;
PFNglUniform3fvARB                 glUniform3fv                  = 0;
PFNglUniform4fvARB                 glUniform4fv                  = 0;
PFNglUniform1ivARB                 glUniform1iv                  = 0;
PFNglUniform2ivARB                 glUniform2iv                  = 0;
PFNglUniform3ivARB                 glUniform3iv                  = 0;
PFNglUniform4ivARB                 glUniform4iv                  = 0;
PFNglUniformMatrix2fvARB           glUniformMatrix2fv            = 0;
PFNglUniformMatrix3fvARB           glUniformMatrix3fv            = 0;
PFNglUniformMatrix4fvARB           glUniformMatrix4fv            = 0;
PFNglGetObjectParameterfvARB       glGetObjectParameterfv        = 0;
PFNglGetObjectParameterivARB       glGetObjectParameteriv        = 0;
PFNglGetInfoLogARB                 glGetInfoLog                  = 0;
PFNglGetAttachedObjectsARB         glGetAttachedObjects          = 0;
PFNglGetUniformLocationARB         glGetUniformLocation          = 0;
PFNglGetActiveUniformARB           glGetActiveUniform            = 0;
PFNglGetUniformfvARB               glGetUniformfv                = 0;
PFNglGetUniformivARB               glGetUniformiv                = 0;
PFNglGetShaderSourceARB            glGetShaderSource             = 0;

PFNglBindAttribLocationARB         glBindAttribLocation          = 0;
PFNglBindFragDataLocationARB       glBindFragDataLocation        = 0;
PFNglGetActiveAttribARB            glGetActiveAttrib             = 0;
PFNglGetAttribLocationARB          glGetAttribLocation           = 0;

FARPROC* ARBVertexProgramProcPtr[] = {
       (FARPROC*)&glVertexAttrib1d,
       (FARPROC*)&glVertexAttrib1dv,
       (FARPROC*)&glVertexAttrib1f,
       (FARPROC*)&glVertexAttrib1fv,
       (FARPROC*)&glVertexAttrib1s,
       (FARPROC*)&glVertexAttrib1sv,
       (FARPROC*)&glVertexAttrib2d,
       (FARPROC*)&glVertexAttrib2dv,
       (FARPROC*)&glVertexAttrib2f,
       (FARPROC*)&glVertexAttrib2fv,
       (FARPROC*)&glVertexAttrib2s,
       (FARPROC*)&glVertexAttrib2sv,
       (FARPROC*)&glVertexAttrib3d,
       (FARPROC*)&glVertexAttrib3dv,
       (FARPROC*)&glVertexAttrib3f,
       (FARPROC*)&glVertexAttrib3fv,
       (FARPROC*)&glVertexAttrib3s,
       (FARPROC*)&glVertexAttrib3sv,
       (FARPROC*)&glVertexAttrib4Nbv,
       (FARPROC*)&glVertexAttrib4Niv,
       (FARPROC*)&glVertexAttrib4Nsv,
       (FARPROC*)&glVertexAttrib4Nub,
       (FARPROC*)&glVertexAttrib4Nubv,
       (FARPROC*)&glVertexAttrib4Nuiv,
       (FARPROC*)&glVertexAttrib4Nusv,
       (FARPROC*)&glVertexAttrib4bv,
       (FARPROC*)&glVertexAttrib4d,
       (FARPROC*)&glVertexAttrib4dv,
       (FARPROC*)&glVertexAttrib4f,
       (FARPROC*)&glVertexAttrib4fv,
       (FARPROC*)&glVertexAttrib4iv,
       (FARPROC*)&glVertexAttrib4s,
       (FARPROC*)&glVertexAttrib4sv,
       (FARPROC*)&glVertexAttrib4ubv,
       (FARPROC*)&glVertexAttrib4uiv,
       (FARPROC*)&glVertexAttrib4usv,
       (FARPROC*)&glVertexAttribPointer,
       (FARPROC*)&glEnableVertexAttribArray,
       (FARPROC*)&glDisableVertexAttribArray,
       (FARPROC*)&glProgramString,
       (FARPROC*)&glBindProgram,
       (FARPROC*)&glDeletePrograms,
       (FARPROC*)&glGenPrograms,
       (FARPROC*)&glProgramEnvParameter4d,
       (FARPROC*)&glProgramEnvParameter4dv,
       (FARPROC*)&glProgramEnvParameter4f,
       (FARPROC*)&glProgramEnvParameter4fv,
       (FARPROC*)&glProgramLocalParameter4d,
       (FARPROC*)&glProgramLocalParameter4dv,
       (FARPROC*)&glProgramLocalParameter4f,
       (FARPROC*)&glProgramLocalParameter4fv,
       (FARPROC*)&glGetProgramEnvParameterdv,
       (FARPROC*)&glGetProgramEnvParameterfv,
       (FARPROC*)&glGetProgramLocalParameterdv,
       (FARPROC*)&glGetProgramLocalParameterfv,
       (FARPROC*)&glGetProgramiv,
       (FARPROC*)&glGetProgramString,
       (FARPROC*)&glGetProgramInfoLog,
       (FARPROC*)&glGetVertexAttribdv,
       (FARPROC*)&glGetVertexAttribfv,
       (FARPROC*)&glGetVertexAttribiv,
       (FARPROC*)&glGetVertexAttribPointerv,
       (FARPROC*)&glIsProgram
};

FARPROC* ARBShaderObjectProcPtr[] = {
       (FARPROC*)&glDeleteObject,
       (FARPROC*)&glGetHandle,
       (FARPROC*)&glDetachObject,
       (FARPROC*)&glCreateShaderObject,
       (FARPROC*)&glShaderSource,
       (FARPROC*)&glCompileShader,
       (FARPROC*)&glCreateProgramObject,
       (FARPROC*)&glAttachObject,
       (FARPROC*)&glLinkProgram,
       (FARPROC*)&glUseProgramObject,
       (FARPROC*)&glValidateProgram,
       (FARPROC*)&glUniform1f,
       (FARPROC*)&glUniform2f,
       (FARPROC*)&glUniform3f,
       (FARPROC*)&glUniform4f,
       (FARPROC*)&glUniform1i,
       (FARPROC*)&glUniform2i,
       (FARPROC*)&glUniform3i,
       (FARPROC*)&glUniform4i,
       (FARPROC*)&glUniform1fv,
       (FARPROC*)&glUniform2fv,
       (FARPROC*)&glUniform3fv,
       (FARPROC*)&glUniform4fv,
       (FARPROC*)&glUniform1iv,
       (FARPROC*)&glUniform2iv,
       (FARPROC*)&glUniform3iv,
       (FARPROC*)&glUniform4iv,
       (FARPROC*)&glUniformMatrix2fv,
       (FARPROC*)&glUniformMatrix3fv,
       (FARPROC*)&glUniformMatrix4fv,
       (FARPROC*)&glGetObjectParameterfv,
       (FARPROC*)&glGetObjectParameteriv,
       (FARPROC*)&glGetInfoLog,
       (FARPROC*)&glGetAttachedObjects,
       (FARPROC*)&glGetUniformLocation,
       (FARPROC*)&glGetActiveUniform,
       (FARPROC*)&glGetUniformfv,
       (FARPROC*)&glGetUniformiv,
       (FARPROC*)&glGetShaderSource
};

FARPROC* ARBVertexShaderProcPtr[] = {
       (FARPROC*)&glGetShaderInfoLog,
       (FARPROC*)&glGetShaderiv,
       (FARPROC*)&glBindAttribLocation,
	   (FARPROC*)&glBindFragDataLocation,
       (FARPROC*)&glGetActiveAttrib,
       (FARPROC*)&glGetAttribLocation
};

FARPROC* ARBFragmentShaderProcPtr[] = {};

static const char* ARBVertexProgramProcName[] = {
       "glVertexAttrib1dARB",
       "glVertexAttrib1dvARB",
       "glVertexAttrib1fARB",
       "glVertexAttrib1fvARB",
       "glVertexAttrib1sARB",
       "glVertexAttrib1svARB",
       "glVertexAttrib2dARB",
       "glVertexAttrib2dvARB",
       "glVertexAttrib2fARB",
       "glVertexAttrib2fvARB",
       "glVertexAttrib2sARB",
       "glVertexAttrib2svARB",
       "glVertexAttrib3dARB",
       "glVertexAttrib3dvARB",
       "glVertexAttrib3fARB",
       "glVertexAttrib3fvARB",
       "glVertexAttrib3sARB",
       "glVertexAttrib3svARB",
       "glVertexAttrib4NbvARB",
       "glVertexAttrib4NivARB",
       "glVertexAttrib4NsvARB",
       "glVertexAttrib4NubARB",
       "glVertexAttrib4NubvARB",
       "glVertexAttrib4NuivARB",
       "glVertexAttrib4NusvARB",
       "glVertexAttrib4bvARB",
       "glVertexAttrib4dARB",
       "glVertexAttrib4dvARB",
       "glVertexAttrib4fARB",
       "glVertexAttrib4fvARB",
       "glVertexAttrib4ivARB",
       "glVertexAttrib4sARB",
       "glVertexAttrib4svARB",
       "glVertexAttrib4ubvARB",
       "glVertexAttrib4uivARB",
       "glVertexAttrib4usvARB",
       "glVertexAttribPointerARB",
       "glEnableVertexAttribArrayARB",
       "glDisableVertexAttribArrayARB",
       "glProgramStringARB",
       "glBindProgramARB",
       "glDeleteProgramsARB",
       "glGenProgramsARB",
       "glProgramEnvParameter4dARB",
       "glProgramEnvParameter4dvARB",
       "glProgramEnvParameter4fARB",
       "glProgramEnvParameter4fvARB",
       "glProgramLocalParameter4dARB",
       "glProgramLocalParameter4dvARB",
       "glProgramLocalParameter4fARB",
       "glProgramLocalParameter4fvARB",
       "glGetProgramEnvParameterdvARB",
       "glGetProgramEnvParameterfvARB",
       "glGetProgramLocalParameterdvARB",
       "glGetProgramLocalParameterfvARB",
       "glGetProgramivARB",
       "glGetProgramStringARB",
       "glGetProgramInfoLog",
       "glGetVertexAttribdvARB",
       "glGetVertexAttribfvARB",
       "glGetVertexAttribivARB",
       "glGetVertexAttribPointervARB",
       "glIsProgramARB",
       NULL
};

static const char* ARBShaderObjectProcName[] = {       
       "glDeleteObjectARB",
       "glGetHandleARB",
       "glDetachObjectARB",
       "glCreateShaderObjectARB",
       "glShaderSourceARB",
       "glCompileShaderARB",
       "glCreateProgramObjectARB",
       "glAttachObjectARB",
       "glLinkProgramARB",
       "glUseProgramObjectARB",
       "glValidateProgramARB",
       "glUniform1fARB",
       "glUniform2fARB",
       "glUniform3fARB",
       "glUniform4fARB",
       "glUniform1iARB",
       "glUniform2iARB",
       "glUniform3iARB",
       "glUniform4iARB",
       "glUniform1fvARB",
       "glUniform2fvARB",
       "glUniform3fvARB",
       "glUniform4fvARB",
       "glUniform1ivARB",
       "glUniform2ivARB",
       "glUniform3ivARB",
       "glUniform4ivARB",
       "glUniformMatrix2fvARB",
       "glUniformMatrix3fvARB",
       "glUniformMatrix4fvARB",
       "glGetObjectParameterfvARB",
       "glGetObjectParameterivARB",
       "glGetInfoLogARB",
       "glGetAttachedObjectsARB",
       "glGetUniformLocationARB",
       "glGetActiveUniformARB",
       "glGetUniformfvARB",
       "glGetUniformivARB",
       "glGetShaderSourceARB",
       NULL
};

static const char* ARBVertexShaderProcName[] = {
       "glGetShaderInfoLog",
       "glGetShaderiv",
       "glBindAttribLocationARB",
	   "glBindFragDataLocationEXT",
       "glGetActiveAttribARB",
       "glGetAttribLocationARB",
       NULL
};

static const char* ARBFragmentShaderProcName[] = { NULL };






PFNglCreateShaderARB 			glCreateShader = 0;
PFNglCompileShaderARB 			glCompileShaderABC = 0;
PFNglDeleteShaderARB 			glDeleteShader = 0;

PFNglCreateProgramARB 			glCreateProgram = 0;
PFNglAttachShaderARB 			glAttachShader = 0;
PFNglDetachShaderARB 			glDetachShader = 0;
PFNglLinkProgramARB 			glLinkProgramABC = 0;
PFNglUseProgramARB 				glUseProgram = 0;
PFNglDeleteProgramARB 			glDeleteProgram = 0;


FARPROC* ProgramProcPtr[] = {
	(FARPROC*)&glCreateShader,
	(FARPROC*)&glCompileShaderABC,
	(FARPROC*)&glDeleteShader,
	(FARPROC*)&glCreateProgram,
	(FARPROC*)&glAttachShader,
	(FARPROC*)&glDetachShader,
	(FARPROC*)&glLinkProgramABC,
	(FARPROC*)&glUseProgram,
	(FARPROC*)&glDeleteProgram,
};


static const char* ProgramProcName[] = {
	"glCreateShader",
	"glCompileShader",
	"glDeleteShader",
	"glCreateProgram",
	"glAttachShader",
	"glDetachShader",
	"glLinkProgram",
	"glUseProgram",
	"glDeleteProgram",
	NULL
};









//-----------------------------------------------------------------------------
// Frame Buffer Object Extensions
//-----------------------------------------------------------------------------
PFNGLBINDFRAMEBUFFEREXTPROC              glBindFramebufferEXT        = 0;
PFNGLBINDRENDERBUFFEREXTPROC             glBindRenderbufferEXT       = 0;
PFNGLGENRENDERBUFFERSEXTPROC             glGenRenderbuffersEXT       = 0;
PFNGLGENFRAMEBUFFERSEXTPROC              glGenFramebuffersEXT        = 0;
PFNGLRENDERBUFFERSTORAGEEXTPROC          glRenderbufferStorageEXT    = 0;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC         glFramebufferTexture2DEXT   = 0;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC      glFramebufferRenderbufferEXT= 0;
PFNGLDELETEFRAMEBUFFERSEXTPROC           glDeleteFramebuffersEXT     = 0;
PFNGLDELETERENDERBUFFERSEXTPROC          glDeleteRenderbuffersEXT    = 0;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC       glCheckFramebufferStatusEXT = 0;
PFNGLGENERATEMIPMAPEXTPROC               glGenerateMipmapEXT         = 0;

FARPROC* EXTFrameBufferProcPtr[] = {
       (FARPROC*)&glBindFramebufferEXT,
       (FARPROC*)&glBindRenderbufferEXT,
       (FARPROC*)&glGenRenderbuffersEXT,
       (FARPROC*)&glGenFramebuffersEXT,
       (FARPROC*)&glRenderbufferStorageEXT,
       (FARPROC*)&glFramebufferTexture2DEXT,
       (FARPROC*)&glFramebufferRenderbufferEXT,
       (FARPROC*)&glDeleteFramebuffersEXT,
       (FARPROC*)&glDeleteRenderbuffersEXT,
       (FARPROC*)&glCheckFramebufferStatusEXT,
       (FARPROC*)&glGenerateMipmapEXT
};

static const char* EXTFrameBufferProcName[] = {
       "glBindFramebufferEXT",
       "glBindRenderbufferEXT",
       "glGenRenderbuffersEXT",
       "glGenFramebuffersEXT",
       "glRenderbufferStorageEXT",
       "glFramebufferTexture2DEXT",
       "glFramebufferRenderbufferEXT",
       "glDeleteFramebuffersEXT",
       "glDeleteRenderbuffersEXT",
       "glCheckFramebufferStatusEXT",
       "glGenerateMipmapEXT",
       NULL
};



//-----------------------------------------------------------------------------
// Buffer Object Extensions
//-----------------------------------------------------------------------------
PFNglGenBuffersARB                   glGenBuffers    = 0;
PFNglBindBufferARB                   glBindBuffer    = 0;
PFNglBufferDataARB                   glBufferData    = 0;
PFNglBufferSubDataARB                glBufferSubData = 0;
PFNglDeleteBuffersARB                glDeleteBuffers = 0;

FARPROC* ARBBufferObjectProcPtr[] = {
       (FARPROC*)&glGenBuffers,
       (FARPROC*)&glBindBuffer,
       (FARPROC*)&glBufferData,
       (FARPROC*)&glBufferSubData,
       (FARPROC*)&glDeleteBuffers,
};

static const char* ARBBufferObjectProcName[] = {
       "glGenBuffersARB",
       "glBindBufferARB",
       "glBufferDataARB",
       "glBufferSubDataARB",
       "glDeleteBuffersARB",
       NULL
};










//-----------------------------------------------------------------------------
// Point Sprite
//-----------------------------------------------------------------------------
PFNglPointParameterfARB      glPointParameterf  = 0;
PFNglPointParameterfvARB     glPointParameterfv = 0;

FARPROC* ARBPointSpriteProcPtr[] = {
       (FARPROC*)&glPointParameterf,
       (FARPROC*)&glPointParameterfv
};

static const char* ARBPointSpriteProcName[] = {
       "glPointParameterf",
       "glPointParameterfv",
       NULL
};






/////////// WINDOWS POUR LES 2 EXT SUIV

//-----------------------------------------------------------------------------
// Multi texturing Extensions
//-----------------------------------------------------------------------------
PFNglMultiTexCoord2fARB              glMultiTexCoord2f      = 0;
PFNglActiveTextureARB                glActiveTexture        = 0;
PFNglClientActiveTextureARB          glClientActiveTexture  = 0;
PFNglCompressedTexImage2DARB         glCompressedTexImage2D = 0;
// Multi texturing functions
FARPROC* ARBMultiTexturingProcPtr[] = {
       (FARPROC*)&glMultiTexCoord2f,
       (FARPROC*)&glActiveTexture,
       (FARPROC*)&glClientActiveTexture,
       (FARPROC*)&glCompressedTexImage2D
};
// Multi texturing functions
static const char* ARBMultiTexturingProcName[] = {
       "glMultiTexCoord2fARB",
       "glActiveTextureARB",
       "glClientActiveTextureARB",
       "glCompressedTexImage2DARB",
       NULL
};



//-----------------------------------------------------------------------------
// Texture3D
//-----------------------------------------------------------------------------
PFNglTexImage3DEXT                  glTexImage3D           = 0;
PFNglTexSubImage3DEXT               glTexSubImage3D        = 0;

FARPROC* EXTTexture3DProcPtr[] = {
       (FARPROC*)&glTexImage3D,
       (FARPROC*)&glTexSubImage3D
};
static const char* EXTTexture3DProcName[] = {
       "glTexImage3DEXT",
       "glTexSubImage3DEXT",
       NULL
};

//-----------------------------------------------------------------------------
// TextureArray
//-----------------------------------------------------------------------------

FARPROC* EXTTextureArrayProcPtr[] = {};
static const char* EXTTextureArrayProcName[] = { NULL };










#include <iostream>

namespace srl {
    
	namespace gl {
	
		Ext::Ext() {
			const GLubyte* exts = glGetString(GL_EXTENSIONS);
			std::string extensions( (const char*)exts );
			std::string extNames[] = {
				"GL_ARB_shader_objects",
				"GL_ARB_vertex_program",
				"GL_ARB_vertex_shader",
				"GL_ARB_fragment_shader",
				"GL_ARB_vertex_buffer_object",
				"GL_ARB_point_sprite",
				"GL_ARB_multitexture",
				"GL_EXT_framebuffer_object",
				"GL_EXT_texture3D",
				"GL_EXT_texture_array",
				"GL_ARB_vertex_program"
			};
			
		
			for(int i = 0; i < 10; i++) {
				int pos = extensions.find( extNames[i] );
				if(pos == std::string::npos)
					isSupportedArray[i] = false;
				else
					isSupportedArray[i] = true;
			isSupportedArray[i]=true;
			}
		}
		
		Ext::~Ext() {
			
		}
		
		Ext* Ext::getInstance() {
			static Ext mInstance;
			return &mInstance;
		}
		
		Error Ext::initAvailableExtensions() {
			bool error = false;
			if(initExtension( VertexProgram_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( ShaderObject_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( VertexShader_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( FragmentShader_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( VertexBufferObject_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( PointSprite_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( MultiTexture_ARB ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( FrameBuffer_EXT ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( Texture3D_EXT ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( TextureArray_EXT ) == Error::ExtensionLoadingFailed) error = true;
			if(initExtension( Program ) == Error::ExtensionLoadingFailed) error = true;
			
			if(error)
				srlReturnError(ExtensionLoadingFailed, "Wgl or glx failed while getting the proc adress of an extension");
			else
				srlReturnNoError();
		}

		Error Ext::initExtension( Ext::ExtensionName id ) {
			const char** extProcNames[] = {
				ARBVertexProgramProcName,
				ARBShaderObjectProcName,
				ARBVertexShaderProcName,
				ARBFragmentShaderProcName,
				ARBBufferObjectProcName,
				ARBPointSpriteProcName,
				ARBMultiTexturingProcName,
				EXTFrameBufferProcName,
				EXTTexture3DProcName,
				EXTTextureArrayProcName,
				ProgramProcName
			};
			
			if( !isSupported(id) )
				srlReturnError(ExtensionNotSupported, "Extension is not supported by your hardware : n" + (int)id);
			
			FARPROC** extProcPtrs[]  = {
				ARBVertexProgramProcPtr,
				ARBShaderObjectProcPtr,
				ARBVertexShaderProcPtr,
				ARBFragmentShaderProcPtr,
				ARBBufferObjectProcPtr,
				ARBPointSpriteProcPtr,
				ARBMultiTexturingProcPtr,
				EXTFrameBufferProcPtr,
				EXTTexture3DProcPtr,
				EXTTextureArrayProcPtr,
				ProgramProcPtr
			};
				
			const char** extProcName = extProcNames[id];
			FARPROC** extProcPtr = extProcPtrs[id];

			for(int i=0; extProcName[i]; ++i) {
			
				#if defined(L3E_GLX)
				if((*(extProcPtr[i]) = (FARPROC)glXGetProcAddress((const GLubyte*)extProcName[i])) == NULL) {
				#elif defined(L3E_WGL)
				if((*(extProcPtr[i]) = (FARPROC)wglGetProcAddress(extProcName[i])) == NULL) {
				#endif
					srlReturnError(ExtensionLoadingFailed, "Wgl or glx failed while getting the proc adress of an extension : \"" + std::string(extProcName[i]) + "\"");
				}
			}
				
			srlReturnNoError();
		}
		
		
		bool Ext::isSupported( Ext::ExtensionName name ) {
			return isSupportedArray[name];
		}
	
	};

};

#else
#include <stdio.h>
namespace srl {
    
	namespace gl {
	
		Ext::Ext() {
			glewInit();
			const char* extNames[] = {
				"GL_ARB_shader_objects",
				"GL_ARB_vertex_program",
				"GL_ARB_vertex_shader",
				"GL_ARB_fragment_shader",
				"GL_ARB_vertex_buffer_object",
				"GL_ARB_point_sprite",
				"GL_ARB_multitexture",
				"GL_EXT_framebuffer_object",
				"GL_EXT_texture3D",
				"GL_EXT_texture_array",
			};
			for(int i = 0; i < 10; i++) {
				isSupportedArray[i] = glewIsSupported(extNames[i]);
			}
		}
		
		Ext::~Ext() {
			
		}
		
		Ext* Ext::getInstance() {
			static Ext mInstance;
			return &mInstance;
		}
		
		Error Ext::initAvailableExtensions() {
			//glewInit();
			srlReturnNoError();
		}


		Error Ext::initExtension( Ext::ExtensionName id ) {
			srlReturnNoError();
		}
		
		
		bool Ext::isSupported( Ext::ExtensionName name ) {
			return isSupportedArray[name];
		}
	
	};

};

#endif
