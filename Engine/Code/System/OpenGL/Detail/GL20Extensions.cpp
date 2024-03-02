/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:19)

#include "System/SystemExport.h"

#include "GL20Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 2.0
namespace System
{
    auto existsOpenGL20 = ExistsOpenGLExtensions::Unknown;

    PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate{ nullptr };
    PFNGLDRAWBUFFERSPROC glDrawBuffers{ nullptr };
    PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate{ nullptr };
    PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate{ nullptr };
    PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate{ nullptr };
    PFNGLATTACHSHADERPROC glAttachShader{ nullptr };
    PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation{ nullptr };
    PFNGLCOMPILESHADERPROC glCompileShader{ nullptr };
    PFNGLCREATEPROGRAMPROC glCreateProgram{ nullptr };
    PFNGLCREATESHADERPROC glCreateShader{ nullptr };
    PFNGLDELETEPROGRAMPROC glDeleteProgram{ nullptr };
    PFNGLDELETESHADERPROC glDeleteShader{ nullptr };
    PFNGLDETACHSHADERPROC glDetachShader{ nullptr };
    PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray{ nullptr };
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray{ nullptr };
    PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib{ nullptr };
    PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform{ nullptr };
    PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders{ nullptr };
    PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation{ nullptr };
    PFNGLGETPROGRAMIVPROC glGetProgramiv{ nullptr };
    PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog{ nullptr };
    PFNGLGETSHADERIVPROC glGetShaderiv{ nullptr };
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog{ nullptr };
    PFNGLGETSHADERSOURCEPROC glGetShaderSource{ nullptr };
    PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation{ nullptr };
    PFNGLGETUNIFORMFVPROC glGetUniformfv{ nullptr };
    PFNGLGETUNIFORMIVPROC glGetUniformiv{ nullptr };
    PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv{ nullptr };
    PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv{ nullptr };
    PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv{ nullptr };
    PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv{ nullptr };
    PFNGLISPROGRAMPROC glIsProgram{ nullptr };
    PFNGLISSHADERPROC glIsShader{ nullptr };
    PFNGLLINKPROGRAMPROC glLinkProgram{ nullptr };
    PFNGLSHADERSOURCEPROC glShaderSource{ nullptr };
    PFNGLUSEPROGRAMPROC glUseProgram{ nullptr };
    PFNGLUNIFORM1FPROC glUniform1f{ nullptr };
    PFNGLUNIFORM2FPROC glUniform2f{ nullptr };
    PFNGLUNIFORM3FPROC glUniform3f{ nullptr };
    PFNGLUNIFORM4FPROC glUniform4f{ nullptr };
    PFNGLUNIFORM1IPROC glUniform1i{ nullptr };
    PFNGLUNIFORM2IPROC glUniform2i{ nullptr };
    PFNGLUNIFORM3IPROC glUniform3i{ nullptr };
    PFNGLUNIFORM4IPROC glUniform4i{ nullptr };
    PFNGLUNIFORM1FVPROC glUniform1fv{ nullptr };
    PFNGLUNIFORM2FVPROC glUniform2fv{ nullptr };
    PFNGLUNIFORM3FVPROC glUniform3fv{ nullptr };
    PFNGLUNIFORM4FVPROC glUniform4fv{ nullptr };
    PFNGLUNIFORM1IVPROC glUniform1iv{ nullptr };
    PFNGLUNIFORM2IVPROC glUniform2iv{ nullptr };
    PFNGLUNIFORM3IVPROC glUniform3iv{ nullptr };
    PFNGLUNIFORM4IVPROC glUniform4iv{ nullptr };
    PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv{ nullptr };
    PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv{ nullptr };
    PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv{ nullptr };
    PFNGLVALIDATEPROGRAMPROC glValidateProgram{ nullptr };
    PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d{ nullptr };
    PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv{ nullptr };
    PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f{ nullptr };
    PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv{ nullptr };
    PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s{ nullptr };
    PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv{ nullptr };
    PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d{ nullptr };
    PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv{ nullptr };
    PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f{ nullptr };
    PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv{ nullptr };
    PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s{ nullptr };
    PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv{ nullptr };
    PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d{ nullptr };
    PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv{ nullptr };
    PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f{ nullptr };
    PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv{ nullptr };
    PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s{ nullptr };
    PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv{ nullptr };
    PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv{ nullptr };
    PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv{ nullptr };
    PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv{ nullptr };
    PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub{ nullptr };
    PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv{ nullptr };
    PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv{ nullptr };
    PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv{ nullptr };
    PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv{ nullptr };
    PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d{ nullptr };
    PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv{ nullptr };
    PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f{ nullptr };
    PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv{ nullptr };
    PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv{ nullptr };
    PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s{ nullptr };
    PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv{ nullptr };
    PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv{ nullptr };
    PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv{ nullptr };
    PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv{ nullptr };
    PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL20() noexcept
{
    return existsOpenGL20;
}

void System::InitOpenGL20() noexcept
{
    if (OpenGLSystemVersion::Version20 <= System::GetOpenGLVersion())
    {
        existsOpenGL20 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glGetShaderiv);
        SYSTEM_GET_FUNCTION(glIsShader);
        SYSTEM_GET_FUNCTION(glStencilMaskSeparate);

        SYSTEM_GET_FUNCTION(glDrawBuffers);

        SYSTEM_GET_FUNCTION(glAttachShader);
        SYSTEM_GET_FUNCTION(glCompileShader);
        SYSTEM_GET_FUNCTION(glCreateProgram);
        SYSTEM_GET_FUNCTION(glCreateShader);
        SYSTEM_GET_FUNCTION(glDeleteProgram);
        SYSTEM_GET_FUNCTION(glDeleteShader);
        SYSTEM_GET_FUNCTION(glDetachShader);
        SYSTEM_GET_FUNCTION(glGetActiveUniform);
        SYSTEM_GET_FUNCTION(glGetAttachedShaders);
        SYSTEM_GET_FUNCTION(glGetProgramInfoLog);
        SYSTEM_GET_FUNCTION(glGetShaderInfoLog);
        SYSTEM_GET_FUNCTION(glGetShaderSource);
        SYSTEM_GET_FUNCTION(glGetUniformfv);
        SYSTEM_GET_FUNCTION(glGetUniformiv);
        SYSTEM_GET_FUNCTION(glGetUniformLocation);
        SYSTEM_GET_FUNCTION(glLinkProgram);
        SYSTEM_GET_FUNCTION(glShaderSource);
        SYSTEM_GET_FUNCTION(glUniform1f);
        SYSTEM_GET_FUNCTION(glUniform2f);
        SYSTEM_GET_FUNCTION(glUniform3f);
        SYSTEM_GET_FUNCTION(glUniform4f);
        SYSTEM_GET_FUNCTION(glUniform1i);
        SYSTEM_GET_FUNCTION(glUniform2i);
        SYSTEM_GET_FUNCTION(glUniform3i);
        SYSTEM_GET_FUNCTION(glUniform4i);
        SYSTEM_GET_FUNCTION(glUniform1fv);
        SYSTEM_GET_FUNCTION(glUniform2fv);
        SYSTEM_GET_FUNCTION(glUniform3fv);
        SYSTEM_GET_FUNCTION(glUniform4fv);
        SYSTEM_GET_FUNCTION(glUniform1iv);
        SYSTEM_GET_FUNCTION(glUniform2iv);
        SYSTEM_GET_FUNCTION(glUniform3iv);
        SYSTEM_GET_FUNCTION(glUniform4iv);
        SYSTEM_GET_FUNCTION(glUniformMatrix2fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix3fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix4fv);
        SYSTEM_GET_FUNCTION(glUseProgram);
        SYSTEM_GET_FUNCTION(glValidateProgram);

        SYSTEM_GET_FUNCTION(glDisableVertexAttribArray);
        SYSTEM_GET_FUNCTION(glEnableVertexAttribArray);
        SYSTEM_GET_FUNCTION(glGetProgramiv);
        SYSTEM_GET_FUNCTION(glGetVertexAttribdv);
        SYSTEM_GET_FUNCTION(glGetVertexAttribfv);
        SYSTEM_GET_FUNCTION(glGetVertexAttribiv);
        SYSTEM_GET_FUNCTION(glGetVertexAttribPointerv);
        SYSTEM_GET_FUNCTION(glIsProgram);
        SYSTEM_GET_FUNCTION(glVertexAttrib1d);
        SYSTEM_GET_FUNCTION(glVertexAttrib1dv);
        SYSTEM_GET_FUNCTION(glVertexAttrib1f);
        SYSTEM_GET_FUNCTION(glVertexAttrib1fv);
        SYSTEM_GET_FUNCTION(glVertexAttrib1s);
        SYSTEM_GET_FUNCTION(glVertexAttrib1sv);
        SYSTEM_GET_FUNCTION(glVertexAttrib2d);
        SYSTEM_GET_FUNCTION(glVertexAttrib2dv);
        SYSTEM_GET_FUNCTION(glVertexAttrib2f);
        SYSTEM_GET_FUNCTION(glVertexAttrib2fv);
        SYSTEM_GET_FUNCTION(glVertexAttrib2s);
        SYSTEM_GET_FUNCTION(glVertexAttrib2sv);
        SYSTEM_GET_FUNCTION(glVertexAttrib3d);
        SYSTEM_GET_FUNCTION(glVertexAttrib3dv);
        SYSTEM_GET_FUNCTION(glVertexAttrib3f);
        SYSTEM_GET_FUNCTION(glVertexAttrib3fv);
        SYSTEM_GET_FUNCTION(glVertexAttrib3s);
        SYSTEM_GET_FUNCTION(glVertexAttrib3sv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Nbv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Niv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Nsv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Nub);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Nubv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Nuiv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4Nusv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4bv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4d);
        SYSTEM_GET_FUNCTION(glVertexAttrib4dv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4f);
        SYSTEM_GET_FUNCTION(glVertexAttrib4fv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4iv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4s);
        SYSTEM_GET_FUNCTION(glVertexAttrib4sv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4ubv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4uiv);
        SYSTEM_GET_FUNCTION(glVertexAttrib4usv);
        SYSTEM_GET_FUNCTION(glVertexAttribPointer);

        SYSTEM_GET_FUNCTION(glBindAttribLocation);
        SYSTEM_GET_FUNCTION(glGetActiveAttrib);
        SYSTEM_GET_FUNCTION(glGetAttribLocation);

        SYSTEM_GET_FUNCTION(glBlendEquationSeparate);

        SYSTEM_GET_FUNCTION(glStencilOpSeparate);
        SYSTEM_GET_FUNCTION(glStencilFuncSeparate);
    }
    else
    {
        existsOpenGL20 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) noexcept
{
    SYSTEM_BODY_2(glBlendEquationSeparate, modeRGB, modeAlpha);
}

void System::GLDrawBuffers(GLsizei n, const GLenum* buffers) noexcept
{
    SYSTEM_BODY_2(glDrawBuffers, n, buffers);
}

void System::GLStencilOpSeparate(GLenum face, GLenum sFail, GLenum dpFail, GLenum dpPass) noexcept
{
    SYSTEM_BODY_4(glStencilOpSeparate, face, sFail, dpFail, dpPass);
}

void System::GLStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) noexcept
{
    SYSTEM_BODY_4(glStencilFuncSeparate, face, func, ref, mask);
}

void System::GLStencilMaskSeparate(GLenum face, GLuint mask) noexcept
{
    SYSTEM_BODY_2(glStencilMaskSeparate, face, mask);
}

void System::GLAttachShader(GLuint program, GLuint shader) noexcept
{
    SYSTEM_BODY_2(glAttachShader, program, shader);
}

void System::GLBindAttribLocation(GLuint program, GLuint index, const GLchar* name) noexcept
{
    SYSTEM_BODY_3(glBindAttribLocation, program, index, name);
}

void System::GLCompileShader(GLuint shader) noexcept
{
    SYSTEM_BODY_1(glCompileShader, shader);
}

GLuint System::GLCreateProgram() noexcept
{
    SYSTEM_BODY_0_RESULT(glCreateProgram, 0u);
}

GLuint System::GLCreateShader(GLenum type) noexcept
{
    SYSTEM_BODY_1_RESULT(glCreateShader, type, 0u);
}

void System::GLDeleteProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(glDeleteProgram, program);
}

void System::GLDeleteShader(GLuint shader) noexcept
{
    SYSTEM_BODY_1(glDeleteShader, shader);
}

void System::GLDetachShader(GLuint program, GLuint shader) noexcept
{
    SYSTEM_BODY_2(glDetachShader, program, shader);
}

void System::GLDisableVertexAttribArray(GLuint index) noexcept
{
    SYSTEM_BODY_1(glDisableVertexAttribArray, index);
}

void System::GLEnableVertexAttribArray(GLuint index) noexcept
{
    SYSTEM_BODY_1(glEnableVertexAttribArray, index);
}

void System::GLGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept
{
    SYSTEM_BODY_7(glGetActiveAttrib, program, index, bufSize, length, size, type, name);
}

void System::GLGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) noexcept
{
    SYSTEM_BODY_7(glGetActiveUniform, program, index, bufSize, length, size, type, name);
}

void System::GLGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders) noexcept
{
    SYSTEM_BODY_4(glGetAttachedShaders, program, maxCount, count, shaders);
}

GLint System::GLGetAttribLocation(GLuint program, const GLchar* name) noexcept
{
    SYSTEM_BODY_2_RESULT(glGetAttribLocation, program, name, 0);
}

void System::GLGetProgramIv(GLuint program, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetProgramiv, program, pName, params);
}

void System::GLGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept
{
    SYSTEM_BODY_4(glGetProgramInfoLog, program, bufSize, length, infoLog);
}

void System::GLGetShaderIv(GLuint shader, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetShaderiv, shader, pName, params);
}

void System::GLGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept
{
    SYSTEM_BODY_4(glGetShaderInfoLog, shader, bufSize, length, infoLog);
}

void System::GLGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source) noexcept
{
    SYSTEM_BODY_4(glGetShaderSource, shader, bufSize, length, source);
}

GLint System::GLGetUniformLocation(GLuint program, const GLchar* name) noexcept
{
    SYSTEM_BODY_2_RESULT(glGetUniformLocation, program, name, 0);
}

void System::GLGetUniformFv(GLuint program, GLint location, GLfloat* params) noexcept
{
    SYSTEM_BODY_3(glGetUniformfv, program, location, params);
}

void System::GLGetUniformIv(GLuint program, GLint location, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetUniformiv, program, location, params);
}

void System::GLGetVertexAttribDv(GLuint index, GLenum pName, GLdouble* params) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribdv, index, pName, params);
}

void System::GLGetVertexAttribFv(GLuint index, GLenum pName, GLfloat* params) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribfv, index, pName, params);
}

void System::GLGetVertexAttribIv(GLuint index, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribiv, index, pName, params);
}

void System::GLGetVertexAttribPointerV(GLuint index, GLenum pName, void** pointer) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribPointerv, index, pName, pointer);
}

GLboolean System::GLIsProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsProgram, program, GL_FALSE);
}

GLboolean System::GLIsShader(GLuint shader) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsShader, shader, GL_FALSE);
}

void System::GLLinkProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(glLinkProgram, program);
}

void System::GLShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) noexcept
{
    SYSTEM_BODY_4(glShaderSource, shader, count, string, length);
}

void System::GLUseProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(glUseProgram, program);
}

void System::GLUniform1F(GLint location, GLfloat v0) noexcept
{
    SYSTEM_BODY_2(glUniform1f, location, v0);
}

void System::GLUniform2F(GLint location, GLfloat v0, GLfloat v1) noexcept
{
    SYSTEM_BODY_3(glUniform2f, location, v0, v1);
}

void System::GLUniform3F(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept
{
    SYSTEM_BODY_4(glUniform3f, location, v0, v1, v2);
}

void System::GLUniform4F(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept
{
    SYSTEM_BODY_5(glUniform4f, location, v0, v1, v2, v3);
}

void System::GLUniform1I(GLint location, GLint v0) noexcept
{
    SYSTEM_BODY_2(glUniform1i, location, v0);
}

void System::GLUniform2I(GLint location, GLint v0, GLint v1) noexcept
{
    SYSTEM_BODY_3(glUniform2i, location, v0, v1);
}

void System::GLUniform3I(GLint location, GLint v0, GLint v1, GLint v2) noexcept
{
    SYSTEM_BODY_4(glUniform3i, location, v0, v1, v2);
}

void System::GLUniform4I(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept
{
    SYSTEM_BODY_5(glUniform4i, location, v0, v1, v2, v3);
}

void System::GLUniform1Fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(glUniform1fv, location, count, value);
}

void System::GLUniform2Fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(glUniform2fv, location, count, value);
}

void System::GLUniform3Fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(glUniform3fv, location, count, value);
}

void System::GLUniform4Fv(GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(glUniform4fv, location, count, value);
}

void System::GLUniform1Iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(glUniform1iv, location, count, value);
}

void System::GLUniform2Iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(glUniform2iv, location, count, value);
}

void System::GLUniform3Iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(glUniform3iv, location, count, value);
}

void System::GLUniform4Iv(GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_3(glUniform4iv, location, count, value);
}

void System::GLUniformMatrix2Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix2fv, location, count, transpose, value);
}

void System::GLUniformMatrix3Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix3fv, location, count, transpose, value);
}

void System::GLUniformMatrix4Fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix4fv, location, count, transpose, value);
}

void System::GLValidateProgram(GLuint program) noexcept
{
    SYSTEM_BODY_1(glValidateProgram, program);
}

void System::GLVertexAttrib1d(GLuint index, GLdouble x) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib1d, index, x);
}

void System::GLVertexAttrib1dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib1dv, index, v);
}

void System::GLVertexAttrib1F(GLuint index, GLfloat x) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib1f, index, x);
}

void System::GLVertexAttrib1Fv(GLuint index, const GLfloat* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib1fv, index, v);
}

void System::GLVertexAttrib1S(GLuint index, GLshort x) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib1s, index, x);
}

void System::GLVertexAttrib1Sv(GLuint index, const GLshort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib1sv, index, v);
}

void System::GLVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) noexcept
{
    SYSTEM_BODY_3(glVertexAttrib2d, index, x, y);
}

void System::GLVertexAttrib2dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib2dv, index, v);
}

void System::GLVertexAttrib2F(GLuint index, GLfloat x, GLfloat y) noexcept
{
    SYSTEM_BODY_3(glVertexAttrib2f, index, x, y);
}

void System::GLVertexAttrib2Fv(GLuint index, const GLfloat* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib2fv, index, v);
}

void System::GLVertexAttrib2S(GLuint index, GLshort x, GLshort y) noexcept
{
    SYSTEM_BODY_3(glVertexAttrib2s, index, x, y);
}

void System::GLVertexAttrib2Sv(GLuint index, const GLshort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib2sv, index, v);
}

void System::GLVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept
{
    SYSTEM_BODY_4(glVertexAttrib3d, index, x, y, z);
}

void System::GLVertexAttrib3dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib3dv, index, v);
}

void System::GLVertexAttrib3F(GLuint index, GLfloat x, GLfloat y, GLfloat z) noexcept
{
    SYSTEM_BODY_4(glVertexAttrib3f, index, x, y, z);
}

void System::GLVertexAttrib3Fv(GLuint index, const GLfloat* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib3fv, index, v);
}

void System::GLVertexAttrib3S(GLuint index, GLshort x, GLshort y, GLshort z) noexcept
{
    SYSTEM_BODY_4(glVertexAttrib3s, index, x, y, z);
}

void System::GLVertexAttrib3Sv(GLuint index, const GLshort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib3sv, index, v);
}

void System::GLVertexAttrib4Nbv(GLuint index, const GLbyte* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4Nbv, index, v);
}

void System::GLVertexAttrib4Niv(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4Niv, index, v);
}

void System::GLVertexAttrib4Nsv(GLuint index, const GLshort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4Nsv, index, v);
}

void System::GLVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) noexcept
{
    SYSTEM_BODY_5(glVertexAttrib4Nub, index, x, y, z, w);
}

void System::GLVertexAttrib4NUbv(GLuint index, const GLubyte* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4Nubv, index, v);
}

void System::GLVertexAttrib4NUiv(GLuint index, const GLuint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4Nuiv, index, v);
}

void System::GLVertexAttrib4NUsv(GLuint index, const GLushort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4Nusv, index, v);
}

void System::GLVertexAttrib4Bv(GLuint index, const GLbyte* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4bv, index, v);
}

void System::GLVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
    SYSTEM_BODY_5(glVertexAttrib4d, index, x, y, z, w);
}

void System::GLVertexAttrib4dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4dv, index, v);
}

void System::GLVertexAttrib4F(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
    SYSTEM_BODY_5(glVertexAttrib4f, index, x, y, z, w);
}

void System::GLVertexAttrib4Fv(GLuint index, const GLfloat* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4fv, index, v);
}

void System::GLVertexAttrib4Iv(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4iv, index, v);
}

void System::GLVertexAttrib4S(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) noexcept
{
    SYSTEM_BODY_5(glVertexAttrib4s, index, x, y, z, w);
}

void System::GLVertexAttrib4Sv(GLuint index, const GLshort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4sv, index, v);
}

void System::GLVertexAttrib4Ubv(GLuint index, const GLubyte* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4ubv, index, v);
}

void System::GLVertexAttrib4Uiv(GLuint index, const GLuint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4uiv, index, v);
}

void System::GLVertexAttrib4Usv(GLuint index, const GLushort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttrib4usv, index, v);
}

void System::GLVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) noexcept
{
    SYSTEM_BODY_6(glVertexAttribPointer, index, size, type, normalized, stride, pointer);
}
