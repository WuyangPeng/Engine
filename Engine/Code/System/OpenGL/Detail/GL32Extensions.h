///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:16)

#ifndef SYSTEM_OPENGL_GL_32_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_32_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 3.2

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL32() noexcept;

    void InitOpenGL32() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProvokingVertex(GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLsync GLFenceSync(GLenum condition, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsSync(GLsync sync) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteSync(GLsync sync) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInteger64v(GLenum pname, GLint64* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInteger64i_v(GLenum target, GLuint index, GLint64* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSampleMaski(GLuint maskNumber, GLbitfield mask) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_32_EXTENSIONS_H
