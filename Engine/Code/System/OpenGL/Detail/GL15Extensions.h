/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 16:08)

#ifndef SYSTEM_OPENGL_GL_15_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_15_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 1.5
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL15() noexcept;

    void InitOpenGL15() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLGenQueries(GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteQueries(GLsizei n, const GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsQuery(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBeginQuery(GLenum target, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEndQuery(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryIv(GLenum target, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryObjectIv(GLuint id, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryObjectUiv(GLuint id, GLenum pName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindBuffer(GLenum target, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteBuffers(GLsizei n, const GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenBuffers(GLsizei n, GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsBuffer(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapBuffer(GLenum target, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLUnmapBuffer(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBufferParameterIv(GLenum target, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBufferPointerV(GLenum target, GLenum pName, void** params) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_15_EXTENSIONS_H
