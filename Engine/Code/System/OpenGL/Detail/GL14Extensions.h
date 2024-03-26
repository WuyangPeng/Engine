/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 15:59)

#ifndef SYSTEM_OPENGL_GL_14_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_14_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 1.4
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL14() noexcept;

    void InitOpenGL14() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLBlendFuncSeparate(GLenum sFactorRGB, GLenum dFactorRGB, GLenum sFactorAlpha, GLenum dFactorAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawCount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawCount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPointParameterF(GLenum pName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPointParameterFv(GLenum pName, const GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPointParameterI(GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPointParameterIv(GLenum pName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendEquation(GLenum mode) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_14_EXTENSIONS_H
