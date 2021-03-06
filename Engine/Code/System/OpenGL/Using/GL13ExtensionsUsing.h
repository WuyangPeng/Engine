//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:13)

#ifndef SYSTEM_OPENGL_GL_13_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_13_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    // OpenGL 1.3

    using PgglActiveTexture = void(OPENGL_STDCALL*)(GLenum);
    using PgglClientActiveTexture = void(OPENGL_STDCALL*)(GLenum);
    using PgglMultiTexCoord1d = void(OPENGL_STDCALL*)(GLenum, GLdouble);
    using PgglMultiTexCoord1dv = void(OPENGL_STDCALL*)(GLenum, const GLdouble*);
    using PgglMultiTexCoord1f = void(OPENGL_STDCALL*)(GLenum, GLfloat);
    using PgglMultiTexCoord1fv = void(OPENGL_STDCALL*)(GLenum, const GLfloat*);
    using PgglMultiTexCoord1i = void(OPENGL_STDCALL*)(GLenum, int);
    using PgglMultiTexCoord1iv = void(OPENGL_STDCALL*)(GLenum, const GLint*);
    using PgglMultiTexCoord1s = void(OPENGL_STDCALL*)(GLenum, GLshort);
    using PgglMultiTexCoord1sv = void(OPENGL_STDCALL*)(GLenum, const GLshort*);
    using PgglMultiTexCoord2d = void(OPENGL_STDCALL*)(GLenum, GLdouble, GLdouble);
    using PgglMultiTexCoord2dv = void(OPENGL_STDCALL*)(GLenum, const GLdouble*);
    using PgglMultiTexCoord2f = void(OPENGL_STDCALL*)(GLenum, GLfloat, GLfloat);
    using PgglMultiTexCoord2fv = void(OPENGL_STDCALL*)(GLenum, const GLfloat*);
    using PgglMultiTexCoord2i = void(OPENGL_STDCALL*)(GLenum, GLint, GLint);
    using PgglMultiTexCoord2iv = void(OPENGL_STDCALL*)(GLenum, const GLint*);
    using PgglMultiTexCoord2s = void(OPENGL_STDCALL*)(GLenum, GLshort, GLshort);
    using PgglMultiTexCoord2sv = void(OPENGL_STDCALL*)(GLenum, const GLshort*);
    using PgglMultiTexCoord3d = void(OPENGL_STDCALL*)(GLenum, GLdouble, GLdouble, GLdouble);
    using PgglMultiTexCoord3dv = void(OPENGL_STDCALL*)(GLenum, const GLdouble*);
    using PgglMultiTexCoord3f = void(OPENGL_STDCALL*)(GLenum, GLfloat, GLfloat, GLfloat);
    using PgglMultiTexCoord3fv = void(OPENGL_STDCALL*)(GLenum, const GLfloat*);
    using PgglMultiTexCoord3i = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLint);
    using PgglMultiTexCoord3iv = void(OPENGL_STDCALL*)(GLenum, const GLint*);
    using PgglMultiTexCoord3s = void(OPENGL_STDCALL*)(GLenum, GLshort, GLshort, GLshort);
    using PgglMultiTexCoord3sv = void(OPENGL_STDCALL*)(GLenum, const GLshort*);
    using PgglMultiTexCoord4d = void(OPENGL_STDCALL*)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
    using PgglMultiTexCoord4dv = void(OPENGL_STDCALL*)(GLenum, const GLdouble*);
    using PgglMultiTexCoord4f = void(OPENGL_STDCALL*)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
    using PgglMultiTexCoord4fv = void(OPENGL_STDCALL*)(GLenum, const GLfloat*);
    using PgglMultiTexCoord4i = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLint, GLint);
    using PgglMultiTexCoord4iv = void(OPENGL_STDCALL*)(GLenum, const int*);
    using PgglMultiTexCoord4s = void(OPENGL_STDCALL*)(GLenum, GLshort, GLshort, GLshort, GLshort);
    using PgglMultiTexCoord4sv = void(OPENGL_STDCALL*)(GLenum, const GLshort*);
    using PgglLoadTransposeMatrixd = void(OPENGL_STDCALL*)(const GLdouble*);
    using PgglLoadTransposeMatrixf = void(OPENGL_STDCALL*)(const GLfloat*);
    using PgglMultTransposeMatrixd = void(OPENGL_STDCALL*)(const GLdouble*);
    using PgglMultTransposeMatrixf = void(OPENGL_STDCALL*)(const GLfloat*);
    using PgglSampleCoverage = void(OPENGL_STDCALL*)(GLclampf, GLboolean);
    using PgglCompressedTexImage1D = void(OPENGL_STDCALL*)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid*);
    using PgglCompressedTexImage2D = void(OPENGL_STDCALL*)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
    using PgglCompressedTexImage3D = void(OPENGL_STDCALL*)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
    using PgglCompressedTexSubImage1D = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid*);
    using PgglCompressedTexSubImage2D = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
    using PgglCompressedTexSubImage3D = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
    using PgglGetCompressedTexImage = void(OPENGL_STDCALL*)(GLenum, GLint, GLvoid*);
}

#endif  // SYSTEM_OPENGL_GL_13_EXTENSIONS_USING_H
