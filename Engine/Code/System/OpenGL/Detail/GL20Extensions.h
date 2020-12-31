//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:34)

#ifndef SYSTEM_OPENGL_GL_20_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_20_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL20ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL20ExtensionsUsing.h"

namespace System
{
    // OpenGL 2.0

    extern PgglBlendEquationSeparate gglBlendEquationSeparate;
    extern PgglDrawBuffers gglDrawBuffers;
    extern PgglStencilOpSeparate gglStencilOpSeparate;
    extern PgglStencilFuncSeparate gglStencilFuncSeparate;
    extern PgglStencilMaskSeparate gglStencilMaskSeparate;
    extern PgglAttachShader gglAttachShader;
    extern PgglBindAttribLocation gglBindAttribLocation;
    extern PgglCompileShader gglCompileShader;
    extern PgglCreateProgram gglCreateProgram;
    extern PgglCreateShader gglCreateShader;
    extern PgglDeleteProgram gglDeleteProgram;
    extern PgglDeleteShader gglDeleteShader;
    extern PgglDetachShader gglDetachShader;
    extern PgglDisableVertexAttribArray gglDisableVertexAttribArray;
    extern PgglEnableVertexAttribArray gglEnableVertexAttribArray;
    extern PgglGetActiveAttrib gglGetActiveAttrib;
    extern PgglGetActiveUniform gglGetActiveUniform;
    extern PgglGetAttachedShaders gglGetAttachedShaders;
    extern PgglGetAttribLocation gglGetAttribLocation;
    extern PgglGetProgramiv gglGetProgramiv;
    extern PgglGetProgramInfoLog gglGetProgramInfoLog;
    extern PgglGetShaderiv gglGetShaderiv;
    extern PgglGetShaderInfoLog gglGetShaderInfoLog;
    extern PgglGetShaderSource gglGetShaderSource;
    extern PgglGetUniformLocation gglGetUniformLocation;
    extern PgglGetUniformfv gglGetUniformfv;
    extern PgglGetUniformiv gglGetUniformiv;
    extern PgglGetVertexAttribdv gglGetVertexAttribdv;
    extern PgglGetVertexAttribfv gglGetVertexAttribfv;
    extern PgglGetVertexAttribiv gglGetVertexAttribiv;
    extern PgglGetVertexAttribPointerv gglGetVertexAttribPointerv;
    extern PgglIsProgram gglIsProgram;
    extern PgglIsShader gglIsShader;
    extern PgglLinkProgram gglLinkProgram;
    extern PgglShaderSource gglShaderSource;
    extern PgglUseProgram gglUseProgram;
    extern PgglUniform1f gglUniform1f;
    extern PgglUniform2f gglUniform2f;
    extern PgglUniform3f gglUniform3f;
    extern PgglUniform4f gglUniform4f;
    extern PgglUniform1i gglUniform1i;
    extern PgglUniform2i gglUniform2i;
    extern PgglUniform3i gglUniform3i;
    extern PgglUniform4i gglUniform4i;
    extern PgglUniform1fv gglUniform1fv;
    extern PgglUniform2fv gglUniform2fv;
    extern PgglUniform3fv gglUniform3fv;
    extern PgglUniform4fv gglUniform4fv;
    extern PgglUniform1iv gglUniform1iv;
    extern PgglUniform2iv gglUniform2iv;
    extern PgglUniform3iv gglUniform3iv;
    extern PgglUniform4iv gglUniform4iv;
    extern PgglUniformMatrix2fv gglUniformMatrix2fv;
    extern PgglUniformMatrix3fv gglUniformMatrix3fv;
    extern PgglUniformMatrix4fv gglUniformMatrix4fv;
    extern PgglValidateProgram gglValidateProgram;
    extern PgglVertexAttrib1d gglVertexAttrib1d;
    extern PgglVertexAttrib1dv gglVertexAttrib1dv;
    extern PgglVertexAttrib1f gglVertexAttrib1f;
    extern PgglVertexAttrib1fv gglVertexAttrib1fv;
    extern PgglVertexAttrib1s gglVertexAttrib1s;
    extern PgglVertexAttrib1sv gglVertexAttrib1sv;
    extern PgglVertexAttrib2d gglVertexAttrib2d;
    extern PgglVertexAttrib2dv gglVertexAttrib2dv;
    extern PgglVertexAttrib2f gglVertexAttrib2f;
    extern PgglVertexAttrib2fv gglVertexAttrib2fv;
    extern PgglVertexAttrib2s gglVertexAttrib2s;
    extern PgglVertexAttrib2sv gglVertexAttrib2sv;
    extern PgglVertexAttrib3d gglVertexAttrib3d;
    extern PgglVertexAttrib3dv gglVertexAttrib3dv;
    extern PgglVertexAttrib3f gglVertexAttrib3f;
    extern PgglVertexAttrib3fv gglVertexAttrib3fv;
    extern PgglVertexAttrib3s gglVertexAttrib3s;
    extern PgglVertexAttrib3sv gglVertexAttrib3sv;
    extern PgglVertexAttrib4Nbv gglVertexAttrib4Nbv;
    extern PgglVertexAttrib4Niv gglVertexAttrib4Niv;
    extern PgglVertexAttrib4Nsv gglVertexAttrib4Nsv;
    extern PgglVertexAttrib4Nub gglVertexAttrib4Nub;
    extern PgglVertexAttrib4Nubv gglVertexAttrib4Nubv;
    extern PgglVertexAttrib4Nuiv gglVertexAttrib4Nuiv;
    extern PgglVertexAttrib4Nusv gglVertexAttrib4Nusv;
    extern PgglVertexAttrib4bv gglVertexAttrib4bv;
    extern PgglVertexAttrib4d gglVertexAttrib4d;
    extern PgglVertexAttrib4dv gglVertexAttrib4dv;
    extern PgglVertexAttrib4f gglVertexAttrib4f;
    extern PgglVertexAttrib4fv gglVertexAttrib4fv;
    extern PgglVertexAttrib4iv gglVertexAttrib4iv;
    extern PgglVertexAttrib4s gglVertexAttrib4s;
    extern PgglVertexAttrib4sv gglVertexAttrib4sv;
    extern PgglVertexAttrib4ubv gglVertexAttrib4ubv;
    extern PgglVertexAttrib4uiv gglVertexAttrib4uiv;
    extern PgglVertexAttrib4usv gglVertexAttrib4usv;
    extern PgglVertexAttribPointer gglVertexAttribPointer;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL20() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDrawBuffers(GLsizei numBuffers, const GLenum* buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlStencilOpSeparate(GLenum face, GLenum sFail, GLenum dpFail, GLenum dpPass) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlStencilFuncSeparate(GLenum frontFunc, GLenum backFunc, GLint reference, GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlStencilMaskSeparate(GLenum face, GLuint mask) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlAttachShader(GLuint program, GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindAttribLocation(GLuint program, GLuint index, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlCompileShader(GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlCreateProgram() noexcept;
    SYSTEM_HIDDEN_DECLARE GLuint GlCreateShader(GLenum type) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDeleteShader(GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDetachShader(GLuint program, GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisableVertexAttribArray(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnableVertexAttribArray(GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* obj) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetAttribLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramiv(GLuint program, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetShaderiv(GLuint shader, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetUniformLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformfv(GLuint program, GLint location, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformiv(GLuint program, GLint location, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribdv(GLuint index, GLenum name, GLdouble* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribfv(GLuint index, GLenum name, GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribiv(GLuint index, GLenum name, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribPointerv(GLuint index, GLenum name, GLvoid** param) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsShader(GLuint shader) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlLinkProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlShaderSource(GLuint shader, GLsizei count, const GLchar** shaderString, const GLint* length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUseProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1f(GLint location, GLfloat v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2f(GLint location, GLfloat v0, GLfloat v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1i(GLint location, GLint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2i(GLint location, GLint v0, GLint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3i(GLint location, GLint v0, GLint v1, GLint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4fv(GLint location, GLsizei count, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4iv(GLint location, GLsizei count, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlValidateProgram(GLuint program) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1d(GLuint index, GLdouble x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1dv(GLuint index, const GLdouble* x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1f(GLuint index, GLfloat x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1fv(GLuint index, const GLfloat* x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1s(GLuint index, GLshort x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib1sv(GLuint index, const GLshort* x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2dv(GLuint index, const GLdouble* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2fv(GLuint index, const GLfloat* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2s(GLuint index, GLshort x, GLshort y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib2sv(GLuint index, const GLshort* xy) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3dv(GLuint index, const GLdouble* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3fv(GLuint index, const GLfloat* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib3sv(GLuint index, const GLshort* xyz) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Nbv(GLuint index, const GLbyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Niv(GLuint index, const GLint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Nsv(GLuint index, const GLshort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Nubv(GLuint index, const GLubyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Nuiv(GLuint index, const GLuint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4Nusv(GLuint index, const GLushort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4bv(GLuint index, const GLbyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4dv(GLuint index, const GLdouble* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4fv(GLuint index, const GLfloat* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4iv(GLuint index, const GLint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4sv(GLuint index, const GLshort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4ubv(GLuint index, const GLubyte* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4uiv(GLuint index, const GLuint* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttrib4usv(GLuint index, const GLushort* xyzw) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) noexcept;

    void InitOpenGL20();
}

#endif  // SYSTEM_OPENGL_GL_20_EXTENSIONS_H
