//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:38)

#ifndef SYSTEM_OPENGL_GL_31_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_31_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL31ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL31ExtensionsUsing.h"

namespace System
{
    // OpenGL 3.1

    extern PgglDrawArraysInstanced gglDrawArraysInstanced;
    extern PgglDrawElementsInstanced gglDrawElementsInstanced;
    extern PgglTexBuffer gglTexBuffer;
    extern PgglPrimitiveRestartIndex gglPrimitiveRestartIndex;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL31() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlPrimitiveRestartIndex(GLuint index) noexcept;

    void InitOpenGL31();
}

#endif  // SYSTEM_OPENGL_GL_31_EXTENSIONS_H
