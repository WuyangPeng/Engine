///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 18:41)

#ifndef SYSTEM_OPENGL_GL_12_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_12_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 1.2

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL12() noexcept;

    void InitOpenGL12() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_12_EXTENSIONS_H
