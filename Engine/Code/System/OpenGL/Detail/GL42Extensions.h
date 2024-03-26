/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 22:19)

#ifndef SYSTEM_OPENGL_GL_42_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_42_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 4.2
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL42() noexcept;

    void InitOpenGL42() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instanceCount, GLuint baseInstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instanceCount, GLuint baseInstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instanceCount, GLint baseVertex, GLuint baseInstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInternalFormatIv(GLenum target, GLenum internalFormat, GLenum pName, GLsizei count, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveAtomicCounterBufferIv(GLuint program, GLuint bufferIndex, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMemoryBarrier(GLbitfield barriers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage1D(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage2D(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage3D(GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instanceCount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instanceCount) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_42_EXTENSIONS_H
