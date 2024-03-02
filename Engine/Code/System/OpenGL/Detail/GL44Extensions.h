/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/28 22:36)

#ifndef SYSTEM_OPENGL_GL_44_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_44_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 4.4

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL44() noexcept;

    void InitOpenGL44() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLBufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearTexSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindSamplers(GLuint first, GLsizei count, const GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindImageTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_44_EXTENSIONS_H
