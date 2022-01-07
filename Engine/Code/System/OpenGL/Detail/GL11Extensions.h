///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:21)

#ifndef SYSTEM_OPENGL_GL_11_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_11_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h" 
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 1.1
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL11() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitOpenGL11() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawArrays(GLenum mode, GLint first, GLsizei count) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetPointerv(GLenum pname, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPolygonOffset(GLfloat factor, GLfloat units) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindTexture(GLenum target, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteTextures(GLsizei n, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenTextures(GLsizei n, GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsTexture(GLuint texture) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_11_EXTENSIONS_H
