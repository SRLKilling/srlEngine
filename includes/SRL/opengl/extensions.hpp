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


#ifndef DefineHeaderExtensions
#define DefineHeaderExtensions

#include <SRL/Environment.hpp>
#include <SRL/opengl/error.hpp>

#ifndef L3E_HOMEMADE_EXT
	#include <GL/glew.h>
	#define BUFFER_OFFSET(i) ((char*)NULL + (i))

#else
	#include <GL/gl.h>
	#include <GL/glu.h>

	#if defined(L3E_WGL)
		#include <windows.h>
		
	#elif defined(L3E_GLX)
		#include <GL/glx.h>
		
	#endif

	#ifndef FARPROC
		#define FARPROC void*
	#endif

	#ifndef APIENTRY
		#define APIENTRY
	#endif

#ifdef L3E_WIN
    typedef unsigned int GLhandleARB;
    typedef ptrdiff_t GLsizeiptr;

    #define GL_DEPTH_COMPONENT24              0x81A6
    #define GL_TEXTURE_COMPARE_FUNC           0x884D
    #define GL_DEPTH_TEXTURE_MODE             0x884B
    #define GL_CLAMP_TO_EDGE_SGIS             0x812F
    #define GL_VERTEX_SHADER                  0x8B31
    #define GL_FRAGMENT_SHADER                0x8B30
    #define GL_COMPILE_STATUS                 0x8B81
    #define GL_ELEMENT_ARRAY_BUFFER           0x8893
    #define GL_STREAM_DRAW                    0x88E0
    #define GL_GENERATE_MIPMAP_SGIS           0x8191
    #define GL_CLAMP_TO_EDGE                  0x812F
    #define GL_ARRAY_BUFFER                   0x8892
    #define GL_STATIC_DRAW                    0x88E4
#endif

//-----------------------------------------------------------------------------
// GLSL EXTENSIONS
//-----------------------------------------------------------------------------
typedef char GLchar;

// GL_ARB_vertex_program
#define GL_VERTEX_PROGRAM_ARB                           0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB                0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                  0x8643
#define GL_COLOR_SUM_ARB                                0x8458
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB              0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB               0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                 0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB           0x886A
#define GL_CURRENT_VERTEX_ATTRIB_ARB                    0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB              0x8645
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB                0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB            0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB         0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB     0x88B3
#define GL_MAX_VERTEX_ATTRIBS_ARB                       0x8869

// GL_ARB_shader_objects
#define GL_PROGRAM_OBJECT_ARB                           0x8B40
#define GL_SHADER_OBJECT_ARB                            0x8B48
#define GL_OBJECT_TYPE_ARB                              0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                           0x8B4F
#define GL_BLEND_EQUATION_ARB GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_OBJECT_DELETE_STATUS_ARB                     0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB                    0x8B81
#define GL_OBJECT_LINK_STATUS_ARB                       0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB                   0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB                   0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB                  0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB                   0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB         0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB              0x8B88

// GL_ARB_vertex_shader
#define GL_VERTEX_SHADER_ARB                            0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB            0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                       0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB           0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB         0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB                 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB       0x8B8A

// GL_ARB_fragment_shader
#define GL_FRAGMENT_SHADER_ARB                          0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB          0x8B49


typedef unsigned int GLhandle;
typedef unsigned int GLhandleARB;

typedef void (APIENTRY * PFNglVertexAttrib1dARB)(GLuint index, GLdouble x);
typedef void (APIENTRY * PFNglVertexAttrib1dvARB)(GLuint index, GLdouble *v);
typedef void (APIENTRY * PFNglVertexAttrib1fARB)(GLuint index, GLfloat x);
typedef void (APIENTRY * PFNglVertexAttrib1fvARB)(GLuint index, GLfloat *v);
typedef void (APIENTRY * PFNglVertexAttrib1sARB)(GLuint index, GLshort x);
typedef void (APIENTRY * PFNglVertexAttrib1svARB)(GLuint index, GLshort *v);
typedef void (APIENTRY * PFNglVertexAttrib2dARB)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRY * PFNglVertexAttrib2dvARB)(GLuint index, GLdouble *v);
typedef void (APIENTRY * PFNglVertexAttrib2fARB)(GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRY * PFNglVertexAttrib2fvARB)(GLuint index, GLfloat *v);
typedef void (APIENTRY * PFNglVertexAttrib2sARB)(GLuint index, GLshort x, GLshort y);
typedef void (APIENTRY * PFNglVertexAttrib2svARB)(GLuint index, GLshort *v);
typedef void (APIENTRY * PFNglVertexAttrib3dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRY * PFNglVertexAttrib3dvARB)(GLuint index, GLdouble *v);
typedef void (APIENTRY * PFNglVertexAttrib3fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRY * PFNglVertexAttrib3fvARB)(GLuint index, GLfloat *v);
typedef void (APIENTRY * PFNglVertexAttrib3sARB)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRY * PFNglVertexAttrib3svARB)(GLuint index, GLshort *v);
typedef void (APIENTRY * PFNglVertexAttrib4NbvARB)(GLuint index, GLbyte *v);
typedef void (APIENTRY * PFNglVertexAttrib4NivARB)(GLuint index, GLint *v);
typedef void (APIENTRY * PFNglVertexAttrib4NsvARB)(GLuint index, GLshort *v);
typedef void (APIENTRY * PFNglVertexAttrib4NubARB)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRY * PFNglVertexAttrib4NubvARB)(GLuint index, GLubyte *v);
typedef void (APIENTRY * PFNglVertexAttrib4NuivARB)(GLuint index, GLuint *v);
typedef void (APIENTRY * PFNglVertexAttrib4NusvARB)(GLuint index, GLushort *v);
typedef void (APIENTRY * PFNglVertexAttrib4bvARB)(GLuint index, GLbyte *v);
typedef void (APIENTRY * PFNglVertexAttrib4dARB)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRY * PFNglVertexAttrib4dvARB)(GLuint index, GLdouble *v);
typedef void (APIENTRY * PFNglVertexAttrib4fARB)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRY * PFNglVertexAttrib4fvARB)(GLuint index, GLfloat *v);
typedef void (APIENTRY * PFNglVertexAttrib4ivARB)(GLuint index, GLint *v);
typedef void (APIENTRY * PFNglVertexAttrib4sARB)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRY * PFNglVertexAttrib4svARB)(GLuint index, GLshort *v);
typedef void (APIENTRY * PFNglVertexAttrib4ubvARB)(GLuint index, GLubyte *v);
typedef void (APIENTRY * PFNglVertexAttrib4uivARB)(GLuint index, GLuint *v);
typedef void (APIENTRY * PFNglVertexAttrib4usvARB)(GLuint index, GLushort *v);
typedef void (APIENTRY * PFNglVertexAttribPointerARB)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer);
typedef void (APIENTRY * PFNglEnableVertexAttribArrayARB)(GLuint index);
typedef void (APIENTRY * PFNglDisableVertexAttribArrayARB)(GLuint index);
typedef void (APIENTRY * PFNglProgramStringARB)(GLenum target, GLenum format, GLsizei len, GLvoid *string);
typedef void (APIENTRY * PFNglBindProgramARB)(GLenum target, GLuint program);
typedef void (APIENTRY * PFNglDeleteProgramsARB)(GLsizei n, GLuint *programs);
typedef void (APIENTRY * PFNglGenProgramsARB)(GLsizei n, GLuint *programs);
typedef void (APIENTRY * PFNglProgramEnvParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRY * PFNglProgramEnvParameter4dvARB)(GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRY * PFNglProgramEnvParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRY * PFNglProgramEnvParameter4fvARB)(GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRY * PFNglProgramLocalParameter4dARB)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRY * PFNglProgramLocalParameter4dvARB)(GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRY * PFNglProgramLocalParameter4fARB)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRY * PFNglProgramLocalParameter4fvARB)(GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRY * PFNglGetProgramEnvParameterdvARB)(GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRY * PFNglGetProgramEnvParameterfvARB)(GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRY * PFNglGetProgramLocalParameterdvARB)(GLenum target, GLuint index, GLdouble *params);
typedef void (APIENTRY * PFNglGetProgramLocalParameterfvARB)(GLenum target, GLuint index, GLfloat *params);
typedef void (APIENTRY * PFNglGetProgramivARB)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNglGetProgramStringARB)(GLenum target, GLenum pname, GLvoid *string);
typedef void (APIENTRY * PFNglGetProgramInfoLogARB) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRY * PFNglGetVertexAttribdvARB)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRY * PFNglGetVertexAttribfvARB)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNglGetVertexAttribivARB)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNglGetVertexAttribPointervARB)(GLuint index, GLenum pname, GLvoid *pointer);
typedef GLboolean (APIENTRY * PFNglIsProgramARB)(GLuint program);

typedef void (APIENTRY * PFNglDeleteObjectARB)(GLhandleARB obj);
typedef GLhandleARB (APIENTRY * PFNglGetHandleARB)(GLenum pname);
typedef void (APIENTRY * PFNglDetachObjectARB)(GLhandleARB containerObj, GLhandleARB attachedObj);
typedef GLhandleARB (APIENTRY * PFNglCreateShaderObjectARB)(GLenum shaderType);
typedef void (APIENTRY * PFNglShaderSourceARB)(GLhandleARB shaderObj, GLsizei count, const char* *string, GLint *length);
typedef void (APIENTRY * PFNglCompileShaderARB)(GLhandleARB shaderObj);
typedef GLhandleARB (APIENTRY * PFNglCreateProgramObjectARB)();
typedef void (APIENTRY * PFNglAttachObjectARB)(GLhandleARB containerObj, GLhandleARB obj);
typedef void (APIENTRY * PFNglLinkProgramARB)(GLhandleARB programObj);
typedef void (APIENTRY * PFNglUseProgramObjectARB)(GLhandleARB programObj);
typedef void (APIENTRY * PFNglValidateProgramARB)(GLhandleARB programObj);
typedef void (APIENTRY * PFNglUniform1fARB)(GLint location, GLfloat v0);
typedef void (APIENTRY * PFNglUniform2fARB)(GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRY * PFNglUniform3fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRY * PFNglUniform4fARB)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRY * PFNglUniform1iARB)(GLint location, GLint v0);
typedef void (APIENTRY * PFNglUniform2iARB)(GLint location, GLint v0, GLint v1);
typedef void (APIENTRY * PFNglUniform3iARB)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRY * PFNglUniform4iARB)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRY * PFNglUniform1fvARB)(GLint location, GLsizei count, GLfloat *value);
typedef void (APIENTRY * PFNglUniform2fvARB)(GLint location, GLsizei count, GLfloat *value);
typedef void (APIENTRY * PFNglUniform3fvARB)(GLint location, GLsizei count, GLfloat *value);
typedef void (APIENTRY * PFNglUniform4fvARB)(GLint location, GLsizei count, GLfloat *value);
typedef void (APIENTRY * PFNglUniform1ivARB)(GLint location, GLsizei count, GLint *value);
typedef void (APIENTRY * PFNglUniform2ivARB)(GLint location, GLsizei count, GLint *value);
typedef void (APIENTRY * PFNglUniform3ivARB)(GLint location, GLsizei count, GLint *value);
typedef void (APIENTRY * PFNglUniform4ivARB)(GLint location, GLsizei count, GLint *value);
typedef void (APIENTRY * PFNglUniformMatrix2fvARB)(GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
typedef void (APIENTRY * PFNglUniformMatrix3fvARB)(GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
typedef void (APIENTRY * PFNglUniformMatrix4fvARB)(GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
typedef void (APIENTRY * PFNglGetObjectParameterfvARB)(GLhandleARB obj, GLenum pname, GLfloat *params);
typedef void (APIENTRY * PFNglGetObjectParameterivARB)(GLhandleARB obj, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNglGetInfoLogARB)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, const char *infoLog);
typedef void (APIENTRY * PFNglGetAttachedObjectsARB)(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
typedef GLint (APIENTRY * PFNglGetUniformLocationARB)(GLhandleARB programObj, const char *name);
typedef void (APIENTRY * PFNglGetActiveUniformARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, const char *name);
typedef void (APIENTRY * PFNglGetUniformfvARB)(GLhandleARB programObj, GLint location, GLfloat *params);
typedef void (APIENTRY * PFNglGetUniformivARB)(GLhandleARB programObj, GLint location, GLint *params);
typedef void (APIENTRY * PFNglGetShaderSourceARB)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, const char *source);

typedef void (APIENTRY * PFNglGetShaderInfoLogARB) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRY * PFNglGetShaderivARB) (GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRY * PFNglBindAttribLocationARB)(GLhandleARB programObj, GLuint index, const char *name);
typedef void (APIENTRY * PFNglBindFragDataLocationARB)(GLhandleARB programObj, GLuint index, const char *name);
typedef void (APIENTRY * PFNglGetActiveAttribARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, const char *name);
typedef GLint (APIENTRY* PFNglGetAttribLocationARB)(GLhandleARB programObj, const char *name);


// Vertex program functions
extern PFNglVertexAttrib1dARB             glVertexAttrib1d;
extern PFNglVertexAttrib1dvARB            glVertexAttrib1dv;
extern PFNglVertexAttrib1fARB             glVertexAttrib1f;
extern PFNglVertexAttrib1fvARB            glVertexAttrib1fv;
extern PFNglVertexAttrib1sARB             glVertexAttrib1s;
extern PFNglVertexAttrib1svARB            glVertexAttrib1sv;
extern PFNglVertexAttrib2dARB             glVertexAttrib2d;
extern PFNglVertexAttrib2dvARB            glVertexAttrib2dv;
extern PFNglVertexAttrib2fARB             glVertexAttrib2f;
extern PFNglVertexAttrib2fvARB            glVertexAttrib2fv;
extern PFNglVertexAttrib2sARB             glVertexAttrib2s;
extern PFNglVertexAttrib2svARB            glVertexAttrib2sv;
extern PFNglVertexAttrib3dARB             glVertexAttrib3d;
extern PFNglVertexAttrib3dvARB            glVertexAttrib3dv;
extern PFNglVertexAttrib3fARB             glVertexAttrib3f;
extern PFNglVertexAttrib3fvARB            glVertexAttrib3fv;
extern PFNglVertexAttrib3sARB             glVertexAttrib3s;
extern PFNglVertexAttrib3svARB            glVertexAttrib3sv;
extern PFNglVertexAttrib4NbvARB           glVertexAttrib4Nbv;
extern PFNglVertexAttrib4NivARB           glVertexAttrib4Niv;
extern PFNglVertexAttrib4NsvARB           glVertexAttrib4Nsv;
extern PFNglVertexAttrib4NubARB           glVertexAttrib4Nub;
extern PFNglVertexAttrib4NubvARB          glVertexAttrib4Nubv;
extern PFNglVertexAttrib4NuivARB          glVertexAttrib4Nuiv;
extern PFNglVertexAttrib4NusvARB          glVertexAttrib4Nusv;
extern PFNglVertexAttrib4bvARB            glVertexAttrib4bv;
extern PFNglVertexAttrib4dARB             glVertexAttrib4d;
extern PFNglVertexAttrib4dvARB            glVertexAttrib4dv;
extern PFNglVertexAttrib4fARB             glVertexAttrib4f;
extern PFNglVertexAttrib4fvARB            glVertexAttrib4fv;
extern PFNglVertexAttrib4ivARB            glVertexAttrib4iv;
extern PFNglVertexAttrib4sARB             glVertexAttrib4s;
extern PFNglVertexAttrib4svARB            glVertexAttrib4sv;
extern PFNglVertexAttrib4ubvARB           glVertexAttrib4ubv;
extern PFNglVertexAttrib4uivARB           glVertexAttrib4uiv;
extern PFNglVertexAttrib4usvARB           glVertexAttrib4usv;
extern PFNglVertexAttribPointerARB        glVertexAttribPointer;
extern PFNglEnableVertexAttribArrayARB    glEnableVertexAttribArray;
extern PFNglDisableVertexAttribArrayARB   glDisableVertexAttribArray;
extern PFNglProgramStringARB              glProgramString;
extern PFNglBindProgramARB                glBindProgram;
extern PFNglDeleteProgramsARB             glDeletePrograms;
extern PFNglGenProgramsARB                glGenPrograms;
extern PFNglProgramEnvParameter4dARB      glProgramEnvParameter4d;
extern PFNglProgramEnvParameter4dvARB     glProgramEnvParameter4dv;
extern PFNglProgramEnvParameter4fARB      glProgramEnvParameter4f;
extern PFNglProgramEnvParameter4fvARB     glProgramEnvParameter4fv;
extern PFNglProgramLocalParameter4dARB    glProgramLocalParameter4d;
extern PFNglProgramLocalParameter4dvARB   glProgramLocalParameter4dv;
extern PFNglProgramLocalParameter4fARB    glProgramLocalParameter4f;
extern PFNglProgramLocalParameter4fvARB   glProgramLocalParameter4fv;
extern PFNglGetProgramEnvParameterdvARB   glGetProgramEnvParameterdv;
extern PFNglGetProgramEnvParameterfvARB   glGetProgramEnvParameterfv;
extern PFNglGetProgramLocalParameterdvARB glGetProgramLocalParameterdv;
extern PFNglGetProgramLocalParameterfvARB glGetProgramLocalParameterfv;
extern PFNglGetProgramivARB               glGetProgramiv;
extern PFNglGetProgramStringARB           glGetProgramString;
extern PFNglGetProgramInfoLogARB          glGetProgramInfoLog;
extern PFNglGetVertexAttribdvARB          glGetVertexAttribdv;
extern PFNglGetVertexAttribfvARB          glGetVertexAttribfv;
extern PFNglGetVertexAttribivARB          glGetVertexAttribiv;
extern PFNglGetVertexAttribPointervARB    glGetVertexAttribPointerv;
extern PFNglIsProgramARB                  glIsProgram;
//Shader object functions
extern PFNglDeleteObjectARB               glDeleteObject;
extern PFNglGetHandleARB                  glGetHandle;
extern PFNglDetachObjectARB               glDetachObject;
extern PFNglCreateShaderObjectARB         glCreateShaderObject;
extern PFNglShaderSourceARB               glShaderSource;
extern PFNglCompileShaderARB              glCompileShader;
extern PFNglCreateProgramObjectARB        glCreateProgramObject;
extern PFNglAttachObjectARB               glAttachObject;
extern PFNglLinkProgramARB                glLinkProgram;
extern PFNglUseProgramObjectARB           glUseProgramObject;
extern PFNglValidateProgramARB            glValidateProgram;
extern PFNglUniform1fARB                  glUniform1f;
extern PFNglUniform2fARB                  glUniform2f;
extern PFNglUniform3fARB                  glUniform3f;
extern PFNglUniform4fARB                  glUniform4f;
extern PFNglUniform1iARB                  glUniform1i;
extern PFNglUniform2iARB                  glUniform2i;
extern PFNglUniform3iARB                  glUniform3i;
extern PFNglUniform4iARB                  glUniform4i;
extern PFNglUniform1fvARB                 glUniform1fv;
extern PFNglUniform2fvARB                 glUniform2fv;
extern PFNglUniform3fvARB                 glUniform3fv;
extern PFNglUniform4fvARB                 glUniform4fv;
extern PFNglUniform1ivARB                 glUniform1iv;
extern PFNglUniform2ivARB                 glUniform2iv;
extern PFNglUniform3ivARB                 glUniform3iv;
extern PFNglUniform4ivARB                 glUniform4iv;
extern PFNglUniformMatrix2fvARB           glUniformMatrix2fv;
extern PFNglUniformMatrix3fvARB           glUniformMatrix3fv;
extern PFNglUniformMatrix4fvARB           glUniformMatrix4fv;
extern PFNglGetObjectParameterfvARB       glGetObjectParameterfv;
extern PFNglGetObjectParameterivARB       glGetObjectParameteriv;
extern PFNglGetInfoLogARB                 glGetInfoLog;
extern PFNglGetAttachedObjectsARB         glGetAttachedObjects;
extern PFNglGetUniformLocationARB         glGetUniformLocation;
extern PFNglGetActiveUniformARB           glGetActiveUniform;
extern PFNglGetUniformfvARB               glGetUniformfv;
extern PFNglGetUniformivARB               glGetUniformiv;
extern PFNglGetShaderSourceARB            glGetShaderSource;
//Vertex shader functions
extern PFNglGetShaderInfoLogARB           glGetShaderInfoLog;
extern PFNglGetShaderivARB                glGetShaderiv;
extern PFNglBindAttribLocationARB         glBindAttribLocation;
extern PFNglBindFragDataLocationARB		  glBindFragDataLocation;
extern PFNglGetActiveAttribARB            glGetActiveAttrib;
extern PFNglGetAttribLocationARB          glGetAttribLocation;
//Function pointers
extern FARPROC* ARBVertexProgramProcPtr[];
extern FARPROC* ARBShaderObjectProcPtr[];
extern FARPROC* ARBVertexShaderProcPtr[];










typedef GLuint (APIENTRY * PFNglCreateShaderARB)(GLenum shaderType);
typedef void (APIENTRY * PFNglCompileShaderARB)(GLuint shader);
typedef void (APIENTRY * PFNglDeleteShaderARB)(GLuint shader);

typedef GLuint (APIENTRY * PFNglCreateProgramARB)();
typedef void (APIENTRY * PFNglAttachShaderARB)(GLuint program, GLuint shader);
typedef void (APIENTRY * PFNglDetachShaderARB)(GLuint program, GLuint shader);
typedef void (APIENTRY * PFNglLinkProgramARB)(GLuint program);
typedef void (APIENTRY * PFNglUseProgramARB)(GLuint program);
typedef void (APIENTRY * PFNglDeleteProgramARB)(GLuint program);

extern PFNglCreateShaderARB 			glCreateShader;
extern PFNglCompileShaderARB 			glCompileShaderABC;
extern PFNglDeleteShaderARB 			glDeleteShader;

extern PFNglCreateProgramARB 			glCreateProgram;
extern PFNglAttachShaderARB 			glAttachShader;
extern PFNglDetachShaderARB 			glDetachShader;
extern PFNglLinkProgramARB 				glLinkProgramABC;
extern PFNglUseProgramARB 				glUseProgram;
extern PFNglDeleteProgramARB 			glDeleteProgram;























//-----------------------------------------------------------------------------
// FRAME BUFFER OBJECT EXTENSION
//-----------------------------------------------------------------------------

#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55






typedef void (APIENTRY * PFNGLBINDFRAMEBUFFEREXTPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRY * PFNGLBINDRENDERBUFFEREXTPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRY * PFNGLGENFRAMEBUFFERSEXTPROC) (GLsizei n, GLuint* framebuffers);
typedef void (APIENTRY * PFNGLGENRENDERBUFFERSEXTPROC) (GLsizei n, GLuint* renderbuffers);
typedef void (APIENTRY * PFNGLRENDERBUFFERSTORAGEEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRY * PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRY * PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRY * PFNGLDELETEFRAMEBUFFERSEXTPROC) (GLsizei n, const GLuint* framebuffers);
typedef void (APIENTRY * PFNGLDELETERENDERBUFFERSEXTPROC) (GLsizei n, const GLuint* renderbuffers);
typedef GLenum (APIENTRY * PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) (GLenum target);
typedef void (APIENTRY * PFNGLGENERATEMIPMAPEXTPROC) (GLenum target);

extern PFNGLBINDFRAMEBUFFEREXTPROC              glBindFramebufferEXT;
extern PFNGLBINDRENDERBUFFEREXTPROC             glBindRenderbufferEXT;
extern PFNGLGENRENDERBUFFERSEXTPROC             glGenRenderbuffersEXT;
extern PFNGLGENFRAMEBUFFERSEXTPROC              glGenFramebuffersEXT;
extern PFNGLRENDERBUFFERSTORAGEEXTPROC          glRenderbufferStorageEXT;
extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC         glFramebufferTexture2DEXT;
extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC      glFramebufferRenderbufferEXT;
extern PFNGLDELETEFRAMEBUFFERSEXTPROC           glDeleteFramebuffersEXT;
extern PFNGLDELETERENDERBUFFERSEXTPROC          glDeleteRenderbuffersEXT;
extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC       glCheckFramebufferStatusEXT;
extern PFNGLGENERATEMIPMAPEXTPROC               glGenerateMipmapEXT;













//-----------------------------------------------------------------------------
// Buffer Object Extensions
//-----------------------------------------------------------------------------

#define BUFFER_OFFSET(i) ((char*)NULL + (i))

typedef void (APIENTRY * PFNglGenBuffersARB)(GLsizei n, GLuint* buffers);
typedef void (APIENTRY * PFNglBindBufferARB)(GLenum target, GLuint buffer);
typedef void (APIENTRY * PFNglBufferDataARB)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (APIENTRY * PFNglBufferSubDataARB)(GLenum target, GLint first, GLsizei size, const GLvoid *data);
typedef void (APIENTRY * PFNglDeleteBuffersARB)(GLsizei n, const GLuint* buffers);
extern PFNglGenBuffersARB                   glGenBuffers;
extern PFNglBindBufferARB                   glBindBuffer;
extern PFNglBufferDataARB                   glBufferData;
extern PFNglBufferSubDataARB                glBufferSubData;
extern PFNglDeleteBuffersARB                glDeleteBuffers;














//-----------------------------------------------------------------------------
// Point Sprite
//-----------------------------------------------------------------------------
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129

typedef void (APIENTRY * PFNglPointParameterfARB) (GLenum pname, GLfloat param);
typedef void (APIENTRY * PFNglPointParameterfvARB) (GLenum pname, GLfloat* param);

extern PFNglPointParameterfARB      glPointParameterf;
extern PFNglPointParameterfvARB     glPointParameterfv;



#ifdef L3E_WIN

//-----------------------------------------------------------------------------
// MULTI TEXTURING
//-----------------------------------------------------------------------------

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF

typedef void (APIENTRY * PFNglMultiTexCoord2fARB)(GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRY * PFNglActiveTextureARB)(GLenum texture);
typedef void (APIENTRY * PFNglClientActiveTextureARB)(GLenum texture);
typedef void (APIENTRY * PFNglCompressedTexImage2DARB)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);

extern PFNglMultiTexCoord2fARB              glMultiTexCoord2f;
extern PFNglActiveTextureARB                glActiveTexture;
extern PFNglClientActiveTextureARB          glClientActiveTexture;
extern PFNglCompressedTexImage2DARB         glCompressedTexImage2D;


//-----------------------------------------------------------------------------
// Texture3D
//-----------------------------------------------------------------------------
#define GL_TEXTURE_3D 									0x806F
#define PROXY_TEXTURE_3D 									0x8070
#define TEXTURE_DEPTH_EXT 									0x8071
#define TEXTURE_WRAP_R_EXT 									0x8072
#define MAX_3D_TEXTURE_SIZE_EXT 							0x8073

typedef void (APIENTRY * PFNglTexImage3DEXT) (GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (APIENTRY * PFNglTexSubImage3DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data);

extern PFNglTexImage3DEXT     glTexImage3D;
extern PFNglTexSubImage3DEXT     glTexSubImage3D;

#endif


//-----------------------------------------------------------------------------
// TextureArray
//-----------------------------------------------------------------------------
#define GL_TEXTURE_1D_ARRAY 								0x8C18
#define GL_TEXTURE_2D_ARRAY 								0x8C1A
#define PROXY_TEXTURE_2D_ARRAY_EXT 							0x8C1B
#define PROXY_TEXTURE_1D_ARRAY_EXT 							0x8C19
#define TEXTURE_BINDING_1D_ARRAY_EXT 						0x8C1C
#define TEXTURE_BINDING_2D_ARRAY_EXT 						0x8C1D
#define MAX_ARRAY_TEXTURE_LAYERS_EXT 						0x88FF
#define COMPARE_REF_DEPTH_TO_TEXTURE_EXT 					0x884E
#define FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 			0x8CD4
#define SAMPLER_1D_ARRAY_EXT                             	0x8DC0
#define SAMPLER_2D_ARRAY_EXT                            	0x8DC1
#define SAMPLER_1D_ARRAY_SHADOW_EXT                      	0x8DC3
#define SAMPLER_2D_ARRAY_SHADOW_EXT                      	0x8DC4

#endif


#include <vector>

namespace srl {

	namespace gl {
    
		class SRLAPI Ext {
			public :
			
				enum ExtensionName {
					// ARB Extensions
						  VertexProgram_ARB,
						   ShaderObject_ARB,
						   VertexShader_ARB,
						 FragmentShader_ARB,
					 VertexBufferObject_ARB,
							PointSprite_ARB,
						   MultiTexture_ARB,
					
					// EXT Extensions
							FrameBuffer_EXT,
							  Texture3D_EXT,
						   TextureArray_EXT,
						   
									Program
				};
					
			
				Error initAvailableExtensions();
				Error initExtension( ExtensionName name );
				
				bool isSupported( ExtensionName name );
				
				static Ext* getInstance();
				
			private:
				Ext();
				~Ext();
				
				bool isSupportedArray[10];
		};
    
	};
	
};

#endif
