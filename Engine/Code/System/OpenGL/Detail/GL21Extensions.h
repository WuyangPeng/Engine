///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:15)

#ifndef SYSTEM_OPENGL_GL_21_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_21_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 2.1

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL21() noexcept;

    void InitOpenGL21() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_21_EXTENSIONS_H
