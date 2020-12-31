//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:35)

#ifndef SYSTEM_OPENGL_GL_21_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_21_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL21ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL21ExtensionsUsing.h"

namespace System
{
    // OpenGL 2.1

    extern PgglUniformMatrix2x3fv gglUniformMatrix2x3fv;
    extern PgglUniformMatrix3x2fv gglUniformMatrix3x2fv;
    extern PgglUniformMatrix2x4fv gglUniformMatrix2x4fv;
    extern PgglUniformMatrix4x2fv gglUniformMatrix4x2fv;
    extern PgglUniformMatrix3x4fv gglUniformMatrix3x4fv;
    extern PgglUniformMatrix4x3fv gglUniformMatrix4x3fv;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL21() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;

    void InitOpenGL21();
}

#endif  // SYSTEM_OPENGL_GL_21_EXTENSIONS_H
