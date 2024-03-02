/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 17:53)

#ifndef SYSTEM_OPENGL_GL_32_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_32_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 3.2

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL32() noexcept;

    void InitOpenGL32() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint baseVertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint baseVertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instanceCount, GLint baseVertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawCount, const GLint* baseVertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProvokingVertex(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLsync GLFenceSync(GLenum condition, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsSync(GLsync sync) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteSync(GLsync sync) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInteger64V(GLenum pName, GLint64* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSyncIv(GLsync sync, GLenum pName, GLsizei count, GLsizei* length, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInteger64Iv(GLenum target, GLuint index, GLint64* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBufferParameterI64V(GLenum target, GLenum pName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage2DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage3DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetMultiSampleFv(GLenum pName, GLuint index, GLfloat* val) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSampleMaskI(GLuint maskNumber, GLbitfield mask) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_32_EXTENSIONS_H
