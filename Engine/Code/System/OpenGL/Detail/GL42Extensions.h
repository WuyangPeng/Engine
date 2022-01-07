///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 11:23)

#ifndef SYSTEM_OPENGL_GL_42_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_42_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.2

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL42() noexcept;

    void InitOpenGL42() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMemoryBarrier(GLbitfield barriers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_42_EXTENSIONS_H
