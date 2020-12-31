//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:13)

#ifndef SYSTEM_OPENGL_GL_20_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_20_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

extern "C"
{
    using GLchar = char;
}

namespace System
{
    // OpenGL 2.0

    using PgglBlendEquationSeparate = void(OPENGL_STDCALL*)(GLenum, GLenum);
    using PgglDrawBuffers = void(OPENGL_STDCALL*)(GLsizei, const GLenum*);
    using PgglStencilOpSeparate = void(OPENGL_STDCALL*)(GLenum, GLenum, GLenum, GLenum);
    using PgglStencilFuncSeparate = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint, GLuint);
    using PgglStencilMaskSeparate = void(OPENGL_STDCALL*)(GLenum, GLuint);
    using PgglAttachShader = void(OPENGL_STDCALL*)(GLuint, GLuint);
    using PgglBindAttribLocation = void(OPENGL_STDCALL*)(GLuint, GLuint, const GLchar*);
    using PgglCompileShader = void(OPENGL_STDCALL*)(GLuint);
    using PgglCreateProgram = GLuint(OPENGL_STDCALL*)();
    using PgglCreateShader = GLuint(OPENGL_STDCALL*)(GLenum);
    using PgglDeleteProgram = void(OPENGL_STDCALL*)(GLuint);
    using PgglDeleteShader = void(OPENGL_STDCALL*)(GLuint);
    using PgglDetachShader = void(OPENGL_STDCALL*)(GLuint, GLuint);
    using PgglDisableVertexAttribArray = void(OPENGL_STDCALL*)(GLuint);
    using PgglEnableVertexAttribArray = void(OPENGL_STDCALL*)(GLuint);
    using PgglGetActiveAttrib = void(OPENGL_STDCALL*)(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
    using PgglGetActiveUniform = void(OPENGL_STDCALL*)(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
    using PgglGetAttachedShaders = void(OPENGL_STDCALL*)(GLuint, GLsizei, GLsizei*, GLuint*);
    using PgglGetAttribLocation = GLint(OPENGL_STDCALL*)(GLuint, const GLchar*);
    using PgglGetProgramiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLint*);
    using PgglGetProgramInfoLog = void(OPENGL_STDCALL*)(GLuint, GLsizei, GLsizei*, GLchar*);
    using PgglGetShaderiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLint*);
    using PgglGetShaderInfoLog = void(OPENGL_STDCALL*)(GLuint, GLsizei, GLsizei*, GLchar*);
    using PgglGetShaderSource = void(OPENGL_STDCALL*)(GLuint, GLsizei, GLsizei*, GLchar*);
    using PgglGetUniformLocation = GLint(OPENGL_STDCALL*)(GLuint, const GLchar*);
    using PgglGetUniformfv = void(OPENGL_STDCALL*)(GLuint, GLint, GLfloat*);
    using PgglGetUniformiv = void(OPENGL_STDCALL*)(GLuint, GLint, GLint*);
    using PgglGetVertexAttribdv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLdouble*);
    using PgglGetVertexAttribfv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLfloat*);
    using PgglGetVertexAttribiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLint*);
    using PgglGetVertexAttribPointerv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLvoid**);
    using PgglIsProgram = GLboolean(OPENGL_STDCALL*)(GLuint);
    using PgglIsShader = GLboolean(OPENGL_STDCALL*)(GLuint);
    using PgglLinkProgram = void(OPENGL_STDCALL*)(GLuint);
    using PgglShaderSource = void(OPENGL_STDCALL*)(GLuint, GLsizei, const GLchar**, const GLint*);
    using PgglUseProgram = void(OPENGL_STDCALL*)(GLuint);
    using PgglUniform1f = void(OPENGL_STDCALL*)(GLint, GLfloat);
    using PgglUniform2f = void(OPENGL_STDCALL*)(GLint, GLfloat, GLfloat);
    using PgglUniform3f = void(OPENGL_STDCALL*)(GLint, GLfloat, GLfloat, GLfloat);
    using PgglUniform4f = void(OPENGL_STDCALL*)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
    using PgglUniform1i = void(OPENGL_STDCALL*)(GLint, GLint);
    using PgglUniform2i = void(OPENGL_STDCALL*)(GLint, GLint, GLint);
    using PgglUniform3i = void(OPENGL_STDCALL*)(GLint, GLint, GLint, GLint);
    using PgglUniform4i = void(OPENGL_STDCALL*)(GLint, GLint, GLint, GLint, GLint);
    using PgglUniform1fv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLfloat*);
    using PgglUniform2fv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLfloat*);
    using PgglUniform3fv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLfloat*);
    using PgglUniform4fv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLfloat*);
    using PgglUniform1iv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLint*);
    using PgglUniform2iv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLint*);
    using PgglUniform3iv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLint*);
    using PgglUniform4iv = void(OPENGL_STDCALL*)(GLint, GLsizei, const GLint*);
    using PgglUniformMatrix2fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix3fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix4fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglValidateProgram = void(OPENGL_STDCALL*)(GLuint);
    using PgglVertexAttrib1d = void(OPENGL_STDCALL*)(GLuint, GLdouble);
    using PgglVertexAttrib1dv = void(OPENGL_STDCALL*)(GLuint, const GLdouble*);
    using PgglVertexAttrib1f = void(OPENGL_STDCALL*)(GLuint, GLfloat);
    using PgglVertexAttrib1fv = void(OPENGL_STDCALL*)(GLuint, const GLfloat*);
    using PgglVertexAttrib1s = void(OPENGL_STDCALL*)(GLuint, GLshort);
    using PgglVertexAttrib1sv = void(OPENGL_STDCALL*)(GLuint, const GLshort*);
    using PgglVertexAttrib2d = void(OPENGL_STDCALL*)(GLuint, GLdouble, GLdouble);
    using PgglVertexAttrib2dv = void(OPENGL_STDCALL*)(GLuint, const GLdouble*);
    using PgglVertexAttrib2f = void(OPENGL_STDCALL*)(GLuint, GLfloat, GLfloat);
    using PgglVertexAttrib2fv = void(OPENGL_STDCALL*)(GLuint, const GLfloat*);
    using PgglVertexAttrib2s = void(OPENGL_STDCALL*)(GLuint, GLshort, GLshort);
    using PgglVertexAttrib2sv = void(OPENGL_STDCALL*)(GLuint, const GLshort*);
    using PgglVertexAttrib3d = void(OPENGL_STDCALL*)(GLuint, GLdouble, GLdouble, GLdouble);
    using PgglVertexAttrib3dv = void(OPENGL_STDCALL*)(GLuint, const GLdouble*);
    using PgglVertexAttrib3f = void(OPENGL_STDCALL*)(GLuint, GLfloat, GLfloat, GLfloat);
    using PgglVertexAttrib3fv = void(OPENGL_STDCALL*)(GLuint, const GLfloat*);
    using PgglVertexAttrib3s = void(OPENGL_STDCALL*)(GLuint, GLshort, GLshort, GLshort);
    using PgglVertexAttrib3sv = void(OPENGL_STDCALL*)(GLuint, const GLshort*);
    using PgglVertexAttrib4Nbv = void(OPENGL_STDCALL*)(GLuint, const GLbyte*);
    using PgglVertexAttrib4Niv = void(OPENGL_STDCALL*)(GLuint, const GLint*);
    using PgglVertexAttrib4Nsv = void(OPENGL_STDCALL*)(GLuint, const GLshort*);
    using PgglVertexAttrib4Nub = void(OPENGL_STDCALL*)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
    using PgglVertexAttrib4Nubv = void(OPENGL_STDCALL*)(GLuint, const GLubyte*);
    using PgglVertexAttrib4Nuiv = void(OPENGL_STDCALL*)(GLuint, const GLuint*);
    using PgglVertexAttrib4Nusv = void(OPENGL_STDCALL*)(GLuint, const GLushort*);
    using PgglVertexAttrib4bv = void(OPENGL_STDCALL*)(GLuint, const GLbyte*);
    using PgglVertexAttrib4d = void(OPENGL_STDCALL*)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
    using PgglVertexAttrib4dv = void(OPENGL_STDCALL*)(GLuint, const GLdouble*);
    using PgglVertexAttrib4f = void(OPENGL_STDCALL*)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
    using PgglVertexAttrib4fv = void(OPENGL_STDCALL*)(GLuint, const GLfloat*);
    using PgglVertexAttrib4iv = void(OPENGL_STDCALL*)(GLuint, const GLint*);
    using PgglVertexAttrib4s = void(OPENGL_STDCALL*)(GLuint, GLshort, GLshort, GLshort, GLshort);
    using PgglVertexAttrib4sv = void(OPENGL_STDCALL*)(GLuint, const GLshort*);
    using PgglVertexAttrib4ubv = void(OPENGL_STDCALL*)(GLuint, const GLubyte*);
    using PgglVertexAttrib4uiv = void(OPENGL_STDCALL*)(GLuint, const GLuint*);
    using PgglVertexAttrib4usv = void(OPENGL_STDCALL*)(GLuint, const GLushort*);
    using PgglVertexAttribPointer = void(OPENGL_STDCALL*)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);
}

#endif  // SYSTEM_OPENGL_GL_20_EXTENSIONS_USING_H
