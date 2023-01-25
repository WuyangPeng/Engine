///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 18:43)

#ifndef SYSTEM_OPENGL_GL_33_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_33_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h" 
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 3.3

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL33() noexcept;

    void InitOpenGL33() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetFragDataIndex(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenSamplers(GLsizei count, GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteSamplers(GLsizei count, const GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsSampler(GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindSampler(GLuint unit, GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameteri(GLuint sampler, GLenum pname, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameteriv(GLuint sampler, GLenum pname, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLQueryCounter(GLuint id, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryObjecti64v(GLuint id, GLenum pname, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribDivisor(GLuint index, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_33_EXTENSIONS_H
