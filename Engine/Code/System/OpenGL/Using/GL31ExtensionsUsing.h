//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:14)

#ifndef SYSTEM_OPENGL_GL_31_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_31_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    // OpenGL 3.1

    using PgglDrawArraysInstanced = void(OPENGL_STDCALL*)(GLenum, GLint, GLsizei, GLsizei);
    using PgglDrawElementsInstanced = void(OPENGL_STDCALL*)(GLenum, GLsizei, GLenum, const GLvoid*, GLsizei);
    using PgglTexBuffer = void(OPENGL_STDCALL*)(GLenum, GLenum, GLuint);
    using PgglPrimitiveRestartIndex = void(OPENGL_STDCALL*)(GLuint);
}

#endif  // SYSTEM_OPENGL_GL_31_EXTENSIONS_USING_H
