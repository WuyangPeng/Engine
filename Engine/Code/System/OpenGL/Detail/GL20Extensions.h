/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 16:10)

#ifndef SYSTEM_OPENGL_GL_20_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_20_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 2.0

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL20() noexcept;

    void InitOpenGL20() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDrawBuffers(GLsizei n, const GLenum* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilOpSeparate(GLenum face, GLenum sFail, GLenum dpFail, GLenum dpPass) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLStencilMaskSeparate(GLenum face, GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLAttachShader(GLuint program, GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindAttribLocation(GLuint program, GLuint index, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompileShader(GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLCreateProgram() noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLCreateShader(GLenum type) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteShader(GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDetachShader(GLuint program, GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDisableVertexAttribArray(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEnableVertexAttribArray(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetAttribLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramIv(GLuint program, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetShaderIv(GLuint shader, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetUniformLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformFv(GLuint program, GLint location, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformIv(GLuint program, GLint location, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribDv(GLuint index, GLenum pName, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribFv(GLuint index, GLenum pName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribIv(GLuint index, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribPointerV(GLuint index, GLenum pName, void** pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsShader(GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLLinkProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUseProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1F(GLint location, GLfloat v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2F(GLint location, GLfloat v0, GLfloat v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3F(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4F(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1I(GLint location, GLint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2I(GLint location, GLint v0, GLint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3I(GLint location, GLint v0, GLint v1, GLint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4I(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1Fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2Fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3Fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4Fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1Iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2Iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3Iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4Iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix2Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix3Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniformMatrix4Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLValidateProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib1d(GLuint index, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib1dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib1F(GLuint index, GLfloat x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib1Fv(GLuint index, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib1S(GLuint index, GLshort x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib1Sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib2dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib2F(GLuint index, GLfloat x, GLfloat y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib2Fv(GLuint index, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib2S(GLuint index, GLshort x, GLshort y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib2Sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib3dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib3F(GLuint index, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib3Fv(GLuint index, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib3S(GLuint index, GLshort x, GLshort y, GLshort z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib3Sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Nbv(GLuint index, const GLbyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Niv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Nsv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4NUbv(GLuint index, const GLubyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4NUiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4NUsv(GLuint index, const GLushort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Bv(GLuint index, const GLbyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4dv(GLuint index, const GLdouble* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4F(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Fv(GLuint index, const GLfloat* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4S(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Ubv(GLuint index, const GLubyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttrib4Usv(GLuint index, const GLushort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_20_EXTENSIONS_H
