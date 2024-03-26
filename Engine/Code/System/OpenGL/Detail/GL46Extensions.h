/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 22:37)

#ifndef SYSTEM_OPENGL_GL_46_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_46_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 4.6
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL46() noexcept;

    void InitOpenGL46() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLSpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_45_EXTENSIONS_H
