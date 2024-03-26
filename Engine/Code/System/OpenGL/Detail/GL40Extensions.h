/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 22:12)

#ifndef SYSTEM_OPENGL_GL_40_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_40_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 4.0
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL40() noexcept;

    void InitOpenGL40() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLMinSampleShading(GLfloat value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendEquationI(GLuint buf, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendEquationSeparateI(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendFuncI(GLuint buf, GLenum src, GLenum dst) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendFuncSeparateI(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawArraysIndirect(GLenum mode, const void* indirect) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1d(GLint location, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2d(GLint location, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4dv(GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2X3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2X4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3X2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3X4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4X2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4X3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformDv(GLuint program, GLint location, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetSubroutineUniformLocation(GLuint program, GLenum shaderType, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLGetSubroutineIndex(GLuint program, GLenum shaderType, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveSubroutineUniformIv(GLuint program, GLenum shaderType, GLuint index, GLenum pName, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveSubroutineUniformName(GLuint program, GLenum shaderType, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveSubroutineName(GLuint program, GLenum shaderType, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformSubroutinesUiv(GLenum shaderType, GLsizei count, const GLuint* indices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformSubroutineUiv(GLenum shaderType, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramStageIv(GLuint program, GLenum shaderType, GLenum pName, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPatchParameterI(GLenum pName, GLint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPatchParameterFv(GLenum pName, const GLfloat* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindTransformFeedback(GLenum target, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenTransformFeedbacks(GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsTransformFeedback(GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPauseTransformFeedback() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLResumeTransformFeedback() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawTransformFeedback(GLenum mode, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBeginQueryIndexed(GLenum target, GLuint index, GLuint id) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEndQueryIndexed(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryIndexedIv(GLenum target, GLuint index, GLenum pName, GLint* params) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_40_EXTENSIONS_H
