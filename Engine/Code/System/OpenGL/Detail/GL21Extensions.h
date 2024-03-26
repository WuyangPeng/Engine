/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 17:37)

#ifndef SYSTEM_OPENGL_GL_21_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_21_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 2.1
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL21() noexcept;

    void InitOpenGL21() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2X3Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3X2Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2X4Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4X2Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3X4Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4X3Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_21_EXTENSIONS_H
