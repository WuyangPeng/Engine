///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:16)

#ifndef SYSTEM_OPENGL_GL_40_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_40_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.0

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL40() noexcept;

    void InitOpenGL40() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLMinSampleShading(GLfloat value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendEquationi(GLuint buf, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendFunci(GLuint buf, GLenum src, GLenum dst) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept;
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
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformdv(GLuint program, GLint location, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPatchParameteri(GLenum pname, GLint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPatchParameterfv(GLenum pname, const GLfloat* values) noexcept;
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
    SYSTEM_HIDDEN_DECLARE void GLGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_40_EXTENSIONS_H
