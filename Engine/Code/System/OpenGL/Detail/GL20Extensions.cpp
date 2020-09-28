//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:34)

#include "System/SystemExport.h"

#include "GL20Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL20ExtensionsUsing.h"

// OpenGL 2.0
namespace System
{
    auto g_ExistsOpenGL20 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL20() noexcept
{
    return g_ExistsOpenGL20;
}

System::PgglBlendEquationSeparate System::gglBlendEquationSeparate{ nullptr };
System::PgglDrawBuffers System::gglDrawBuffers{ nullptr };
System::PgglStencilOpSeparate System::gglStencilOpSeparate{ nullptr };
System::PgglStencilFuncSeparate System::gglStencilFuncSeparate{ nullptr };
System::PgglStencilMaskSeparate System::gglStencilMaskSeparate{ nullptr };
System::PgglAttachShader System::gglAttachShader{ nullptr };
System::PgglBindAttribLocation System::gglBindAttribLocation{ nullptr };
System::PgglCompileShader System::gglCompileShader{ nullptr };
System::PgglCreateProgram System::gglCreateProgram{ nullptr };
System::PgglCreateShader System::gglCreateShader{ nullptr };
System::PgglDeleteProgram System::gglDeleteProgram{ nullptr };
System::PgglDeleteShader System::gglDeleteShader{ nullptr };
System::PgglDetachShader System::gglDetachShader{ nullptr };
System::PgglDisableVertexAttribArray System::gglDisableVertexAttribArray{ nullptr };
System::PgglEnableVertexAttribArray System::gglEnableVertexAttribArray{ nullptr };
System::PgglGetActiveAttrib System::gglGetActiveAttrib{ nullptr };
System::PgglGetActiveUniform System::gglGetActiveUniform{ nullptr };
System::PgglGetAttachedShaders System::gglGetAttachedShaders{ nullptr };
System::PgglGetAttribLocation System::gglGetAttribLocation{ nullptr };
System::PgglGetProgramiv System::gglGetProgramiv{ nullptr };
System::PgglGetProgramInfoLog System::gglGetProgramInfoLog{ nullptr };
System::PgglGetShaderiv System::gglGetShaderiv{ nullptr };
System::PgglGetShaderInfoLog System::gglGetShaderInfoLog{ nullptr };
System::PgglGetShaderSource System::gglGetShaderSource{ nullptr };
System::PgglGetUniformLocation System::gglGetUniformLocation{ nullptr };
System::PgglGetUniformfv System::gglGetUniformfv{ nullptr };
System::PgglGetUniformiv System::gglGetUniformiv{ nullptr };
System::PgglGetVertexAttribdv System::gglGetVertexAttribdv{ nullptr };
System::PgglGetVertexAttribfv System::gglGetVertexAttribfv{ nullptr };
System::PgglGetVertexAttribiv System::gglGetVertexAttribiv{ nullptr };
System::PgglGetVertexAttribPointerv System::gglGetVertexAttribPointerv{ nullptr };
System::PgglIsProgram System::gglIsProgram{ nullptr };
System::PgglIsShader System::gglIsShader{ nullptr };
System::PgglLinkProgram System::gglLinkProgram{ nullptr };
System::PgglShaderSource System::gglShaderSource{ nullptr };
System::PgglUseProgram System::gglUseProgram{ nullptr };
System::PgglUniform1f System::gglUniform1f{ nullptr };
System::PgglUniform2f System::gglUniform2f{ nullptr };
System::PgglUniform3f System::gglUniform3f{ nullptr };
System::PgglUniform4f System::gglUniform4f{ nullptr };
System::PgglUniform1i System::gglUniform1i{ nullptr };
System::PgglUniform2i System::gglUniform2i{ nullptr };
System::PgglUniform3i System::gglUniform3i{ nullptr };
System::PgglUniform4i System::gglUniform4i{ nullptr };
System::PgglUniform1fv System::gglUniform1fv{ nullptr };
System::PgglUniform2fv System::gglUniform2fv{ nullptr };
System::PgglUniform3fv System::gglUniform3fv{ nullptr };
System::PgglUniform4fv System::gglUniform4fv{ nullptr };
System::PgglUniform1iv System::gglUniform1iv{ nullptr };
System::PgglUniform2iv System::gglUniform2iv{ nullptr };
System::PgglUniform3iv System::gglUniform3iv{ nullptr };
System::PgglUniform4iv System::gglUniform4iv{ nullptr };
System::PgglUniformMatrix2fv System::gglUniformMatrix2fv{ nullptr };
System::PgglUniformMatrix3fv System::gglUniformMatrix3fv{ nullptr };
System::PgglUniformMatrix4fv System::gglUniformMatrix4fv{ nullptr };
System::PgglValidateProgram System::gglValidateProgram{ nullptr };
System::PgglVertexAttrib1d System::gglVertexAttrib1d{ nullptr };
System::PgglVertexAttrib1dv System::gglVertexAttrib1dv{ nullptr };
System::PgglVertexAttrib1f System::gglVertexAttrib1f{ nullptr };
System::PgglVertexAttrib1fv System::gglVertexAttrib1fv{ nullptr };
System::PgglVertexAttrib1s System::gglVertexAttrib1s{ nullptr };
System::PgglVertexAttrib1sv System::gglVertexAttrib1sv{ nullptr };
System::PgglVertexAttrib2d System::gglVertexAttrib2d{ nullptr };
System::PgglVertexAttrib2dv System::gglVertexAttrib2dv{ nullptr };
System::PgglVertexAttrib2f System::gglVertexAttrib2f{ nullptr };
System::PgglVertexAttrib2fv System::gglVertexAttrib2fv{ nullptr };
System::PgglVertexAttrib2s System::gglVertexAttrib2s{ nullptr };
System::PgglVertexAttrib2sv System::gglVertexAttrib2sv{ nullptr };
System::PgglVertexAttrib3d System::gglVertexAttrib3d{ nullptr };
System::PgglVertexAttrib3dv System::gglVertexAttrib3dv{ nullptr };
System::PgglVertexAttrib3f System::gglVertexAttrib3f{ nullptr };
System::PgglVertexAttrib3fv System::gglVertexAttrib3fv{ nullptr };
System::PgglVertexAttrib3s System::gglVertexAttrib3s{ nullptr };
System::PgglVertexAttrib3sv System::gglVertexAttrib3sv{ nullptr };
System::PgglVertexAttrib4Nbv System::gglVertexAttrib4Nbv{ nullptr };
System::PgglVertexAttrib4Niv System::gglVertexAttrib4Niv{ nullptr };
System::PgglVertexAttrib4Nsv System::gglVertexAttrib4Nsv{ nullptr };
System::PgglVertexAttrib4Nub System::gglVertexAttrib4Nub{ nullptr };
System::PgglVertexAttrib4Nubv System::gglVertexAttrib4Nubv{ nullptr };
System::PgglVertexAttrib4Nuiv System::gglVertexAttrib4Nuiv{ nullptr };
System::PgglVertexAttrib4Nusv System::gglVertexAttrib4Nusv{ nullptr };
System::PgglVertexAttrib4bv System::gglVertexAttrib4bv{ nullptr };
System::PgglVertexAttrib4d System::gglVertexAttrib4d{ nullptr };
System::PgglVertexAttrib4dv System::gglVertexAttrib4dv{ nullptr };
System::PgglVertexAttrib4f System::gglVertexAttrib4f{ nullptr };
System::PgglVertexAttrib4fv System::gglVertexAttrib4fv{ nullptr };
System::PgglVertexAttrib4iv System::gglVertexAttrib4iv{ nullptr };
System::PgglVertexAttrib4s System::gglVertexAttrib4s{ nullptr };
System::PgglVertexAttrib4sv System::gglVertexAttrib4sv{ nullptr };
System::PgglVertexAttrib4ubv System::gglVertexAttrib4ubv{ nullptr };
System::PgglVertexAttrib4uiv System::gglVertexAttrib4uiv{ nullptr };
System::PgglVertexAttrib4usv System::gglVertexAttrib4usv{ nullptr };
System::PgglVertexAttribPointer System::gglVertexAttribPointer{ nullptr };

void System::GlBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) noexcept
{
    SYSTEM_BODY_2(gglBlendEquationSeparate, modeRGB, modeAlpha);
}

void System::GlDrawBuffers(GLsizei numBuffers, const GLenum* buffer) noexcept
{
    SYSTEM_BODY_2(gglDrawBuffers, numBuffers, buffer);
}

void System::GlStencilOpSeparate(GLenum face, GLenum sFail, GLenum dpFail, GLenum dpPass) noexcept
{
    SYSTEM_BODY_4(gglStencilOpSeparate, face, sFail, dpFail, dpPass);
}

void System::GlStencilFuncSeparate(GLenum frontFunc, GLenum backFunc, GLint reference, GLuint mask) noexcept
{
    SYSTEM_BODY_4(gglStencilFuncSeparate, frontFunc, backFunc, reference, mask);
}

void System::GlStencilMaskSeparate(GLenum face, GLuint mask) noexcept
{
    SYSTEM_BODY_2(gglStencilMaskSeparate, face, mask);
}

void System::GlAttachShader(GLuint program, GLuint shader) noexcept
{
    SYSTEM_BODY_2(gglAttachShader, program, shader);
}

void System::GlBindAttribLocation(GLuint program, GLuint index, const GLchar* name) noexcept
{
    SYSTEM_BODY_3(gglBindAttribLocation, program, index, name);
}

void System::GlCompileShader(GLuint shader) noexcept
{
    SYSTEM_BODY_1(gglCompileShader, shader);
}

GLuint System::GlCreateProgram() noexcept
{
    SYSTEM_BODY_0_RESULT(gglCreateProgram, GLuint, 0);
}

GLuint System::GlCreateShader(GLenum type) noexcept
{
    SYSTEM_BODY_1_RESULT(gglCreateShader, type, GLuint, 0);
}

void System::GlDeleteProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(gglDeleteProgram, program);
}

void System::GlDeleteShader(GLuint shader) noexcept
{
    SYSTEM_BODY_1(gglDeleteShader, shader);
}

void System::GlDetachShader(GLuint program, GLuint shader) noexcept
{
    SYSTEM_BODY_2(gglDetachShader, program, shader);
}

void System::GlDisableVertexAttribArray(GLuint index) noexcept
{
    SYSTEM_BODY_1(gglDisableVertexAttribArray, index);
}

void System::GlEnableVertexAttribArray(GLuint index) noexcept
{
    SYSTEM_BODY_1(gglEnableVertexAttribArray, index);
}

void System::GlGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept
{
    SYSTEM_BODY_7(gglGetActiveAttrib, program, index, bufSize, length, size, type, name);
}

void System::GlGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept
{
    SYSTEM_BODY_7(gglGetActiveUniform, program, index, bufSize, length, size, type, name);
}

void System::GlGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* obj) noexcept
{
    SYSTEM_BODY_4(gglGetAttachedShaders, program, maxCount, count, obj);
}

GLint System::GlGetAttribLocation(GLuint program, const GLchar* name) noexcept
{
    SYSTEM_BODY_2_RESULT(gglGetAttribLocation, program, name, GLint, -1);
}

void System::GlGetProgramiv(GLuint program, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetProgramiv, program, name, param);
}

void System::GlGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept
{
    SYSTEM_BODY_4(gglGetProgramInfoLog, program, bufSize, length, infoLog);
}

void System::GlGetShaderiv(GLuint shader, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetShaderiv, shader, name, param);
}

void System::GlGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept
{
    SYSTEM_BODY_4(gglGetShaderInfoLog, shader, bufSize, length, infoLog);
}

void System::GlGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) noexcept
{
    SYSTEM_BODY_4(gglGetShaderSource, shader, bufSize, length, source);
}

GLint System::GlGetUniformLocation(GLuint program, const GLchar* name) noexcept
{
    SYSTEM_BODY_2_RESULT(gglGetUniformLocation, program, name, GLint, -1);
}

void System::GlGetUniformfv(GLuint program, GLint location, GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglGetUniformfv, program, location, param);
}

void System::GlGetUniformiv(GLuint program, GLint location, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetUniformiv, program, location, param);
}

void System::GlGetVertexAttribdv(GLuint index, GLenum name, GLdouble* param) noexcept
{
    SYSTEM_BODY_3(gglGetVertexAttribdv, index, name, param);
}

void System::GlGetVertexAttribfv(GLuint index, GLenum name, GLfloat* param) noexcept
{
    SYSTEM_BODY_3(gglGetVertexAttribfv, index, name, param);
}

void System::GlGetVertexAttribiv(GLuint index, GLenum name, GLint* param) noexcept
{
    SYSTEM_BODY_3(gglGetVertexAttribiv, index, name, param);
}

void System::GlGetVertexAttribPointerv(GLuint index, GLenum name, GLvoid** param) noexcept
{
    SYSTEM_BODY_3(gglGetVertexAttribPointerv, index, name, param);
}

GLboolean System::GlIsProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1_RESULT(gglIsProgram, program, GLboolean, GL_FALSE);
}

GLboolean System::GlIsShader(GLuint shader) noexcept
{
    SYSTEM_BODY_1_RESULT(gglIsShader, shader, GLboolean, GL_FALSE);
}

void System::GlLinkProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(gglLinkProgram, program);
}

void System::GlShaderSource(GLuint shader, GLsizei count, const GLchar** shaderString, const GLint* length) noexcept
{
    SYSTEM_BODY_4(gglShaderSource, shader, count, shaderString, length);
}

void System::GlUseProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(gglUseProgram, program);
}

void System::GlUniform1f(GLint location, GLfloat v0) noexcept
{
    SYSTEM_BODY_2(gglUniform1f, location, v0);
}

void System::GlUniform2f(GLint location, GLfloat v0, GLfloat v1) noexcept
{
    SYSTEM_BODY_3(gglUniform2f, location, v0, v1);
}

void System::GlUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept
{
    SYSTEM_BODY_4(gglUniform3f, location, v0, v1, v2);
}

void System::GlUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept
{
    SYSTEM_BODY_5(gglUniform4f, location, v0, v1, v2, v3);
}

void System::GlUniform1i(GLint location, GLint v0) noexcept
{
    SYSTEM_BODY_2(gglUniform1i, location, v0);
}

void System::GlUniform2i(GLint location, GLint v0, GLint v1) noexcept
{
    SYSTEM_BODY_3(gglUniform2i, location, v0, v1);
}

void System::GlUniform3i(GLint location, GLint v0, GLint v1, GLint v2) noexcept
{
    SYSTEM_BODY_4(gglUniform3i, location, v0, v1, v2);
}

void System::GlUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept
{
    SYSTEM_BODY_5(gglUniform4i, location, v0, v1, v2, v3);
}

void System::GlUniform1fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(gglUniform1fv, location, count, value);
}

void System::GlUniform2fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(gglUniform2fv, location, count, value);
}

void System::GlUniform3fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(gglUniform3fv, location, count, value);
}

void System::GlUniform4fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(gglUniform4fv, location, count, value);
}

void System::GlUniform1iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(gglUniform1iv, location, count, value);
}

void System::GlUniform2iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(gglUniform2iv, location, count, value);
}

void System::GlUniform3iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(gglUniform3iv, location, count, value);
}

void System::GlUniform4iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(gglUniform4iv, location, count, value);
}

void System::GlUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix2fv, location, count, transpose, value);
}

void System::GlUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix3fv, location, count, transpose, value);
}

void System::GlUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix4fv, location, count, transpose, value);
}

void System::GlValidateProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(gglValidateProgram, program);
}

void System::GlVertexAttrib1d(GLuint index, GLdouble x) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib1d, index, x);
}

void System::GlVertexAttrib1dv(GLuint index, const GLdouble* x) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib1dv, index, x);
}

void System::GlVertexAttrib1f(GLuint index, GLfloat x) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib1f, index, x);
}

void System::GlVertexAttrib1fv(GLuint index, const GLfloat* x) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib1fv, index, x);
}

void System::GlVertexAttrib1s(GLuint index, GLshort x) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib1s, index, x);
}

void System::GlVertexAttrib1sv(GLuint index, const GLshort* x) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib1sv, index, x);
}

void System::GlVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) noexcept
{
    SYSTEM_BODY_3(gglVertexAttrib2d, index, x, y);
}

void System::GlVertexAttrib2dv(GLuint index, const GLdouble* xy) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib2dv, index, xy);
}

void System::GlVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) noexcept
{
    SYSTEM_BODY_3(gglVertexAttrib2f, index, x, y);
}

void System::GlVertexAttrib2fv(GLuint index, const GLfloat* xy) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib2fv, index, xy);
}

void System::GlVertexAttrib2s(GLuint index, GLshort x, GLshort y) noexcept
{
    SYSTEM_BODY_3(gglVertexAttrib2s, index, x, y);
}

void System::GlVertexAttrib2sv(GLuint index, const GLshort* xy) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib2sv, index, xy);
}

void System::GlVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept
{
    SYSTEM_BODY_4(gglVertexAttrib3d, index, x, y, z);
}

void System::GlVertexAttrib3dv(GLuint index, const GLdouble* xyz) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib3dv, index, xyz);
}

void System::GlVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) noexcept
{
    SYSTEM_BODY_4(gglVertexAttrib3f, index, x, y, z);
}

void System::GlVertexAttrib3fv(GLuint index, const GLfloat* xyz) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib3fv, index, xyz);
}

void System::GlVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) noexcept
{
    SYSTEM_BODY_4(gglVertexAttrib3s, index, x, y, z);
}

void System::GlVertexAttrib3sv(GLuint index, const GLshort* xyz) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib3sv, index, xyz);
}

void System::GlVertexAttrib4Nbv(GLuint index, const GLbyte* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4Nbv, index, xyzw);
}

void System::GlVertexAttrib4Niv(GLuint index, const GLint* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4Niv, index, xyzw);
}

void System::GlVertexAttrib4Nsv(GLuint index, const GLshort* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4Nsv, index, xyzw);
}

void System::GlVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) noexcept
{
    SYSTEM_BODY_5(gglVertexAttrib4Nub, index, x, y, z, w);
}

void System::GlVertexAttrib4Nubv(GLuint index, const GLubyte* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4Nubv, index, xyzw);
}

void System::GlVertexAttrib4Nuiv(GLuint index, const GLuint* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4Nuiv, index, xyzw);
}

void System::GlVertexAttrib4Nusv(GLuint index, const GLushort* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4Nusv, index, xyzw);
}

void System::GlVertexAttrib4bv(GLuint index, const GLbyte* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4bv, index, xyzw);
}

void System::GlVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
    SYSTEM_BODY_5(gglVertexAttrib4d, index, x, y, z, w);
}

void System::GlVertexAttrib4dv(GLuint index, const GLdouble* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4dv, index, xyzw);
}

void System::GlVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
    SYSTEM_BODY_5(gglVertexAttrib4f, index, x, y, z, w);
}

void System::GlVertexAttrib4fv(GLuint index, const GLfloat* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4fv, index, xyzw);
}

void System::GlVertexAttrib4iv(GLuint index, const GLint* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4iv, index, xyzw);
}

void System::GlVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) noexcept
{
    SYSTEM_BODY_5(gglVertexAttrib4s, index, x, y, z, w);
}

void System::GlVertexAttrib4sv(GLuint index, const GLshort* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4sv, index, xyzw);
}

void System::GlVertexAttrib4ubv(GLuint index, const GLubyte* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4ubv, index, xyzw);
}

void System::GlVertexAttrib4uiv(GLuint index, const GLuint* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4uiv, index, xyzw);
}

void System::GlVertexAttrib4usv(GLuint index, const GLushort* xyzw) noexcept
{
    SYSTEM_BODY_2(gglVertexAttrib4usv, index, xyzw);
}

void System::GlVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) noexcept
{
    SYSTEM_BODY_6(gglVertexAttribPointer, index, size, type, normalized, stride, pointer);
}

void System::InitOpenGL20()
{
    if (System::OpenGLSystemVersion::Version20 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL20 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglGetShaderiv);
        SYSTEM_GET_FUNCTION(gglIsShader);
        SYSTEM_GET_FUNCTION(gglStencilMaskSeparate);

        // GL_ARB_draw_buffers
        SYSTEM_GET_FUNCTION(gglDrawBuffers);

        // GL_ARB_shader_objects
        SYSTEM_GET_FUNCTION(gglAttachShader);  // glAttachObjectARB
        SYSTEM_GET_FUNCTION(gglCompileShader);
        SYSTEM_GET_FUNCTION(gglCreateProgram);  // glCreateProgramObjectARB
        SYSTEM_GET_FUNCTION(gglCreateShader);  // glCreateShaderObjectARB
        SYSTEM_GET_FUNCTION(gglDeleteProgram);  // glDeleteProgramObjectARB
        SYSTEM_GET_FUNCTION(gglDeleteShader);  // glDeleteProgramObjectARB
        SYSTEM_GET_FUNCTION(gglDetachShader);  // glDetachObjectARB
        SYSTEM_GET_FUNCTION(gglGetActiveUniform);
        SYSTEM_GET_FUNCTION(gglGetAttachedShaders);  // glGetAttachObjectsARB
        SYSTEM_GET_FUNCTION(gglGetProgramInfoLog);  // glGetInfoLogARB
        SYSTEM_GET_FUNCTION(gglGetShaderInfoLog);  // glGetInfoLogARB
        SYSTEM_GET_FUNCTION(gglGetShaderSource);
        SYSTEM_GET_FUNCTION(gglGetUniformfv);
        SYSTEM_GET_FUNCTION(gglGetUniformiv);
        SYSTEM_GET_FUNCTION(gglGetUniformLocation);
        SYSTEM_GET_FUNCTION(gglLinkProgram);
        SYSTEM_GET_FUNCTION(gglShaderSource);
        SYSTEM_GET_FUNCTION(gglUniform1f);
        SYSTEM_GET_FUNCTION(gglUniform2f);
        SYSTEM_GET_FUNCTION(gglUniform3f);
        SYSTEM_GET_FUNCTION(gglUniform4f);
        SYSTEM_GET_FUNCTION(gglUniform1i);
        SYSTEM_GET_FUNCTION(gglUniform2i);
        SYSTEM_GET_FUNCTION(gglUniform3i);
        SYSTEM_GET_FUNCTION(gglUniform4i);
        SYSTEM_GET_FUNCTION(gglUniform1fv);
        SYSTEM_GET_FUNCTION(gglUniform2fv);
        SYSTEM_GET_FUNCTION(gglUniform3fv);
        SYSTEM_GET_FUNCTION(gglUniform4fv);
        SYSTEM_GET_FUNCTION(gglUniform1iv);
        SYSTEM_GET_FUNCTION(gglUniform2iv);
        SYSTEM_GET_FUNCTION(gglUniform3iv);
        SYSTEM_GET_FUNCTION(gglUniform4iv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix2fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix3fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix4fv);
        SYSTEM_GET_FUNCTION(gglUseProgram);  // glUseProgramObjectARB
        SYSTEM_GET_FUNCTION(gglValidateProgram);

        // GL_ARB_fragment_program and GL_ARB_vertex_program
        SYSTEM_GET_FUNCTION(gglDisableVertexAttribArray);
        SYSTEM_GET_FUNCTION(gglEnableVertexAttribArray);
        SYSTEM_GET_FUNCTION(gglGetProgramiv);
        SYSTEM_GET_FUNCTION(gglGetVertexAttribdv);
        SYSTEM_GET_FUNCTION(gglGetVertexAttribfv);
        SYSTEM_GET_FUNCTION(gglGetVertexAttribiv);
        SYSTEM_GET_FUNCTION(gglGetVertexAttribPointerv);
        SYSTEM_GET_FUNCTION(gglIsProgram);
        SYSTEM_GET_FUNCTION(gglVertexAttrib1d);
        SYSTEM_GET_FUNCTION(gglVertexAttrib1dv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib1f);
        SYSTEM_GET_FUNCTION(gglVertexAttrib1fv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib1s);
        SYSTEM_GET_FUNCTION(gglVertexAttrib1sv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib2d);
        SYSTEM_GET_FUNCTION(gglVertexAttrib2dv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib2f);
        SYSTEM_GET_FUNCTION(gglVertexAttrib2fv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib2s);
        SYSTEM_GET_FUNCTION(gglVertexAttrib2sv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib3d);
        SYSTEM_GET_FUNCTION(gglVertexAttrib3dv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib3f);
        SYSTEM_GET_FUNCTION(gglVertexAttrib3fv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib3s);
        SYSTEM_GET_FUNCTION(gglVertexAttrib3sv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Nbv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Niv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Nsv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Nub);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Nubv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Nuiv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4Nusv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4bv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4d);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4dv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4f);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4fv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4iv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4s);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4sv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4ubv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4uiv);
        SYSTEM_GET_FUNCTION(gglVertexAttrib4usv);
        SYSTEM_GET_FUNCTION(gglVertexAttribPointer);

        // GL_ARB_vertex_shader
        SYSTEM_GET_FUNCTION(gglBindAttribLocation);
        SYSTEM_GET_FUNCTION(gglGetActiveAttrib);
        SYSTEM_GET_FUNCTION(gglGetAttribLocation);

        // GL_EXT_blend_equation_separate
        SYSTEM_GET_FUNCTION(gglBlendEquationSeparate);

        // GL_ATI_separate_stencil
        SYSTEM_GET_FUNCTION(gglStencilOpSeparate);
        SYSTEM_GET_FUNCTION(gglStencilFuncSeparate);
    }
    else
    {
        g_ExistsOpenGL20 = ExistsOpenGLExtensions::NotExist;
    }
}