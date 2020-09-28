//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:14)

#ifndef SYSTEM_OPENGL_GL_32_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_32_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

extern "C"
{
    using GLint64 = int64_t;
    using GLuint64 = uint64_t;
}

namespace System
{
    using PgglGetInteger64i_v = void(OPENGL_STDCALL*)(GLenum, GLuint, GLint64*);
    using PgglGetBufferParameteri64v = void(OPENGL_STDCALL*)(GLenum, GLenum, GLint64*);
    using PgglProgramParameteri = void(OPENGL_STDCALL*)(GLuint, GLenum, GLint);
    using PgglFramebufferTexture = void(OPENGL_STDCALL*)(GLenum, GLenum, GLuint, GLint);
}

#endif  // SYSTEM_OPENGL_GL_32_EXTENSIONS_USING_H
