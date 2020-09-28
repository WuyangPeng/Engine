//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:12)

#ifndef SYSTEM_OPENGL_GL_12_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_12_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    // OpenGL 1.2
    using PgglCopyTexSubImage3D = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
    using PgglDrawRangeElements = void(OPENGL_STDCALL*)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
    using PgglTexImage3D = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
    using PgglTexSubImage3D = void(OPENGL_STDCALL*)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
}

#endif  // SYSTEM_OPENGL_GL_12_EXTENSIONS_USING_H
