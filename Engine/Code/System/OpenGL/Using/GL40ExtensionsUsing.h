//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:14)

#ifndef SYSTEM_OPENGL_GL_40_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_40_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    using PgglBlendEquationSeparatei = void(OPENGL_STDCALL*)(GLuint, GLenum, GLenum);
    using PgglBlendEquationi = void(OPENGL_STDCALL*)(GLuint, GLenum);
    using PgglBlendFuncSeparatei = void(OPENGL_STDCALL*)(GLuint, GLenum, GLenum, GLenum, GLenum);
    using PgglBlendFunci = void(OPENGL_STDCALL*)(GLuint, GLenum, GLenum);
    using PgglMinSampleShading = void(OPENGL_STDCALL*)(GLclampf);
}

#endif  // SYSTEM_OPENGL_GL_40_EXTENSIONS_USING_H
