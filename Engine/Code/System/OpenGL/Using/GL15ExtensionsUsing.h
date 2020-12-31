//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:13)

#ifndef SYSTEM_OPENGL_GL_15_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_15_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

extern "C"
{
    using GLintptr = ptrdiff_t;
    using GLsizeiptr = ptrdiff_t;
}

namespace System
{
    // OpenGL 1.5

    using PgglGenQueries = void(OPENGL_STDCALL*)(GLsizei, GLuint*);
    using PgglDeleteQueries = void(OPENGL_STDCALL*)(GLsizei, const GLuint*);
    using PgglIsQuery = unsigned char(OPENGL_STDCALL*)(GLuint);
    using PgglBeginQuery = void(OPENGL_STDCALL*)(GLenum, GLuint);
    using PgglEndQuery = void(OPENGL_STDCALL*)(GLenum);
    using PgglGetQueryiv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglGetQueryObjectiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLint*);
    using PgglGetQueryObjectuiv = void(OPENGL_STDCALL*)(GLuint, GLenum, GLuint*);
    using PgglBindBuffer = void(OPENGL_STDCALL*)(GLenum, GLuint);
    using PgglDeleteBuffers = void(OPENGL_STDCALL*)(GLsizei, const GLuint*);
    using PgglGenBuffers = void(OPENGL_STDCALL*)(GLsizei, GLuint*);
    using PgglIsBuffer = unsigned char(OPENGL_STDCALL*)(GLuint);
    using PgglBufferData = void(OPENGL_STDCALL*)(GLenum, GLsizeiptr, const GLvoid*, GLenum);
    using PgglBufferSubData = void(OPENGL_STDCALL*)(GLenum, GLintptr, GLsizeiptr, const GLvoid*);
    using PgglGetBufferSubData = void(OPENGL_STDCALL*)(GLenum, GLintptr, GLsizeiptr, GLvoid*);
    using PgglMapBuffer = void*(OPENGL_STDCALL*)(GLenum, GLenum);
    using PgglUnmapBuffer = unsigned char(OPENGL_STDCALL*)(GLenum);
    using PgglGetBufferParameteriv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint*);
    using PgglGetBufferPointerv = void(OPENGL_STDCALL*)(GLenum, GLenum, GLvoid**);
}

#endif  // SYSTEM_OPENGL_GL_15_EXTENSIONS_USING_H
