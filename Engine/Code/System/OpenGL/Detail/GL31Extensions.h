///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/12 18:43)

#ifndef SYSTEM_OPENGL_GL_31_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_31_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 3.1

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL31() noexcept;

    void InitOpenGL31() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPrimitiveRestartIndex(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_31_EXTENSIONS_H
