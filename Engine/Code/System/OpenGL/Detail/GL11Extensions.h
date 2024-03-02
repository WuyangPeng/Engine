/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/28 14:54)

#ifndef SYSTEM_OPENGL_GL_11_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_11_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 1.1
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL11() noexcept;

    SYSTEM_HIDDEN_DECLARE void InitOpenGL11() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawArrays(GLenum mode, GLint first, GLsizei count) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetPointerV(GLenum pName, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPolygonOffset(GLfloat factor, GLfloat units) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindTexture(GLenum target, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteTextures(GLsizei n, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenTextures(GLsizei n, GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsTexture(GLuint texture) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_11_EXTENSIONS_H
