//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:14)

#ifndef SYSTEM_OPENGL_GL_21_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_21_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
    // OpenGL 2.1

    using PgglUniformMatrix2x3fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix3x2fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix2x4fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix4x2fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix3x4fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
    using PgglUniformMatrix4x3fv = void(OPENGL_STDCALL*)(GLint, GLsizei, GLboolean, const GLfloat*);
}

#endif  // SYSTEM_OPENGL_GL_21_EXTENSIONS_USING_H
