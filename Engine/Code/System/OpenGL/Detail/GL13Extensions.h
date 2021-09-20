///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/09 10:59)

#ifndef SYSTEM_OPENGL_GL_13_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_13_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h" 
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 1.3

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL13() noexcept;

    void InitOpenGL13() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLActiveTexture(GLenum texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSampleCoverage(GLfloat value, GLboolean invert) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetCompressedTexImage(GLenum target, GLint level, void* img) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_13_EXTENSIONS_H
