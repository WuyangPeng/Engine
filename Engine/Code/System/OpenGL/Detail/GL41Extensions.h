///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:16)

#ifndef SYSTEM_OPENGL_GL_41_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_41_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.1

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL41() noexcept;

    void InitOpenGL41() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLReleaseShaderCompiler() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthRangef(GLfloat n, GLfloat f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearDepthf(GLfloat d) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramParameteri(GLuint program, GLenum pname, GLint value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLActiveShaderProgram(GLuint pipeline, GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* const* strings) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindProgramPipeline(GLuint pipeline) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteProgramPipelines(GLsizei n, const GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenProgramPipelines(GLsizei n, GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsProgramPipeline(GLuint pipeline) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1i(GLuint program, GLint location, GLint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1f(GLuint program, GLint location, GLfloat v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1d(GLuint program, GLint location, GLdouble v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1ui(GLuint program, GLint location, GLuint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLValidateProgramPipeline(GLuint pipeline) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL1d(GLuint index, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL1dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL2dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL3dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribL4dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLViewportArrayv(GLuint first, GLsizei count, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLViewportIndexedfv(GLuint index, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLScissorArrayv(GLuint first, GLsizei count, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLScissorIndexedv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFloati_v(GLenum target, GLuint index, GLfloat* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetDoublei_v(GLenum target, GLuint index, GLdouble* data) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_41_EXTENSIONS_H
