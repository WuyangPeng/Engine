//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:38)

#ifndef SYSTEM_OPENGL_GL_33_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_33_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL33ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL33ExtensionsUsing.h"

namespace System
{
    // OpenGL 3.3

    extern PgglVertexAttribDivisor gglVertexAttribDivisor;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL33() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlVertexAttribDivisor(GLuint index, GLuint divisor) noexcept;

    void InitOpenGL33();
}

#endif  // SYSTEM_OPENGL_GL_33_EXTENSIONS_H
