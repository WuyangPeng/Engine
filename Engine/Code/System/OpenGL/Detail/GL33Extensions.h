/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 17:56)

#ifndef SYSTEM_OPENGL_GL_33_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_33_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 3.3
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL33() noexcept;

    void InitOpenGL33() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetFragDataIndex(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenSamplers(GLsizei count, GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteSamplers(GLsizei count, const GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsSampler(GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindSampler(GLuint unit, GLuint sampler) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterI(GLuint sampler, GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterIv(GLuint sampler, GLenum pName, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterF(GLuint sampler, GLenum pName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterFv(GLuint sampler, GLenum pName, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterIiv(GLuint sampler, GLenum pName, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLSamplerParameterIUiv(GLuint sampler, GLenum pName, const GLuint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterIv(GLuint sampler, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterIiv(GLuint sampler, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterFv(GLuint sampler, GLenum pName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetSamplerParameterIUiv(GLuint sampler, GLenum pName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLQueryCounter(GLuint id, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryObjectI64V(GLuint id, GLenum pName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryObjectUi64V(GLuint id, GLenum pName, GLuint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribDivisor(GLuint index, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP1Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP1Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP2Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP2Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP3Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP3Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP4Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribP4Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_33_EXTENSIONS_H
