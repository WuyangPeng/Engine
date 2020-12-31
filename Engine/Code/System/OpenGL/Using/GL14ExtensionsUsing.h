//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:13)

#ifndef SYSTEM_OPENGL_GL_14_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_14_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    // OpenGL 1.4

    using PgglBlendFuncSeparate = void(OPENGL_STDCALL*)(GLenum, GLenum, GLenum, GLenum);
    using PgglFogCoordd = void(OPENGL_STDCALL*)(GLdouble);
    using PgglFogCoorddv = void(OPENGL_STDCALL*)(const GLdouble*);
    using PgglFogCoordf = void(OPENGL_STDCALL*)(GLfloat);
    using PgglFogCoordfv = void(OPENGL_STDCALL*)(const GLfloat*);
    using PgglFogCoordPointer = void(OPENGL_STDCALL*)(GLenum, GLsizei, const GLvoid*);
    using PgglMultiDrawArrays = void(OPENGL_STDCALL*)(GLenum, GLint*, GLsizei*, GLsizei);
    using PgglMultiDrawElements = void(OPENGL_STDCALL*)(GLenum, const GLsizei*, GLenum, const GLvoid**, GLsizei);
    using PgglPointParameterf = void(OPENGL_STDCALL*)(GLenum, GLfloat);
    using PgglPointParameterfv = void(OPENGL_STDCALL*)(GLenum, const GLfloat*);
    using PgglPointParameteri = void(OPENGL_STDCALL*)(GLenum, GLint);
    using PgglPointParameteriv = void(OPENGL_STDCALL*)(GLenum, const GLint*);
    using PgglSecondaryColor3b = void(OPENGL_STDCALL*)(GLbyte, GLbyte, GLbyte);
    using PgglSecondaryColor3bv = void(OPENGL_STDCALL*)(const GLbyte*);
    using PgglSecondaryColor3d = void(OPENGL_STDCALL*)(GLdouble, GLdouble, GLdouble);
    using PgglSecondaryColor3dv = void(OPENGL_STDCALL*)(const GLdouble*);
    using PgglSecondaryColor3f = void(OPENGL_STDCALL*)(GLfloat, GLfloat, GLfloat);
    using PgglSecondaryColor3fv = void(OPENGL_STDCALL*)(const GLfloat*);
    using PgglSecondaryColor3i = void(OPENGL_STDCALL*)(GLint, GLint, GLint);
    using PgglSecondaryColor3iv = void(OPENGL_STDCALL*)(const GLint*);
    using PgglSecondaryColor3s = void(OPENGL_STDCALL*)(GLshort, GLshort, GLshort);
    using PgglSecondaryColor3sv = void(OPENGL_STDCALL*)(const GLshort*);
    using PgglSecondaryColor3ub = void(OPENGL_STDCALL*)(GLubyte, GLubyte, GLubyte);
    using PgglSecondaryColor3ubv = void(OPENGL_STDCALL*)(const GLubyte*);
    using PgglSecondaryColor3ui = void(OPENGL_STDCALL*)(GLuint, GLuint, GLuint);
    using PgglSecondaryColor3uiv = void(OPENGL_STDCALL*)(const GLuint*);
    using PgglSecondaryColor3us = void(OPENGL_STDCALL*)(GLushort, GLushort, GLushort);
    using PgglSecondaryColor3usv = void(OPENGL_STDCALL*)(const GLushort*);
    using PgglSecondaryColorPointer = void(OPENGL_STDCALL*)(GLint, GLenum, GLsizei, const GLvoid*);
    using PgglWindowPos2d = void(OPENGL_STDCALL*)(GLdouble, GLdouble);
    using PgglWindowPos2dv = void(OPENGL_STDCALL*)(const GLdouble*);
    using PgglWindowPos2f = void(OPENGL_STDCALL*)(GLfloat, GLfloat);
    using PgglWindowPos2fv = void(OPENGL_STDCALL*)(const GLfloat*);
    using PgglWindowPos2i = void(OPENGL_STDCALL*)(GLint, GLint);
    using PgglWindowPos2iv = void(OPENGL_STDCALL*)(const GLint*);
    using PgglWindowPos2s = void(OPENGL_STDCALL*)(GLshort, GLshort);
    using PgglWindowPos2sv = void(OPENGL_STDCALL*)(const GLshort*);
    using PgglWindowPos3d = void(OPENGL_STDCALL*)(GLdouble, GLdouble, GLdouble);
    using PgglWindowPos3dv = void(OPENGL_STDCALL*)(const GLdouble*);
    using PgglWindowPos3f = void(OPENGL_STDCALL*)(GLfloat, GLfloat, GLfloat);
    using PgglWindowPos3fv = void(OPENGL_STDCALL*)(const GLfloat*);
    using PgglWindowPos3i = void(OPENGL_STDCALL*)(GLint, GLint, GLint);
    using PgglWindowPos3iv = void(OPENGL_STDCALL*)(const GLint*);
    using PgglWindowPos3s = void(OPENGL_STDCALL*)(GLshort, GLshort, GLshort);
    using PgglWindowPos3sv = void(OPENGL_STDCALL*)(const GLshort*);
}

#endif  // SYSTEM_OPENGL_GL_14_EXTENSIONS_USING_H
