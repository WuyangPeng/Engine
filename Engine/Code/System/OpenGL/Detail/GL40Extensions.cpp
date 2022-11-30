///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:37)

#include "System/SystemExport.h"

#include "GL40Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.0
namespace System
{
    auto existsOpenGL40 = ExistsOpenGLExtensions::Unknown;

    PFNGLMINSAMPLESHADINGPROC glMinSampleShading{ nullptr };
    PFNGLBLENDEQUATIONIPROC glBlendEquationi{ nullptr };
    PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei{ nullptr };
    PFNGLBLENDFUNCIPROC glBlendFunci{ nullptr };
    PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei{ nullptr };
    PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect{ nullptr };
    PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect{ nullptr };
    PFNGLUNIFORM1DPROC glUniform1d{ nullptr };
    PFNGLUNIFORM2DPROC glUniform2d{ nullptr };
    PFNGLUNIFORM3DPROC glUniform3d{ nullptr };
    PFNGLUNIFORM4DPROC glUniform4d{ nullptr };
    PFNGLUNIFORM1DVPROC glUniform1dv{ nullptr };
    PFNGLUNIFORM2DVPROC glUniform2dv{ nullptr };
    PFNGLUNIFORM3DVPROC glUniform3dv{ nullptr };
    PFNGLUNIFORM4DVPROC glUniform4dv{ nullptr };
    PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv{ nullptr };
    PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv{ nullptr };
    PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv{ nullptr };
    PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv{ nullptr };
    PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv{ nullptr };
    PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv{ nullptr };
    PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv{ nullptr };
    PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv{ nullptr };
    PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv{ nullptr };
    PFNGLGETUNIFORMDVPROC glGetUniformdv{ nullptr };
    PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation{ nullptr };
    PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex{ nullptr };
    PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv{ nullptr };
    PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName{ nullptr };
    PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName{ nullptr };
    PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv{ nullptr };
    PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv{ nullptr };
    PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv{ nullptr };
    PFNGLPATCHPARAMETERIPROC glPatchParameteri{ nullptr };
    PFNGLPATCHPARAMETERFVPROC glPatchParameterfv{ nullptr };
    PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback{ nullptr };
    PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks{ nullptr };
    PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks{ nullptr };
    PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback{ nullptr };
    PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback{ nullptr };
    PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback{ nullptr };
    PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback{ nullptr };
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream{ nullptr };
    PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed{ nullptr };
    PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed{ nullptr };
    PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL40() noexcept
{
    return existsOpenGL40;
}

void System::InitOpenGL40() noexcept
{
    if (System::OpenGLSystemVersion::Version40 <= System::GetOpenGLVersion())
    {
        existsOpenGL40 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glMinSampleShading);
        SYSTEM_GET_FUNCTION(glBlendEquationi);
        SYSTEM_GET_FUNCTION(glBlendEquationSeparatei);
        SYSTEM_GET_FUNCTION(glBlendFunci);
        SYSTEM_GET_FUNCTION(glBlendFuncSeparatei);
        SYSTEM_GET_FUNCTION(glDrawArraysIndirect);
        SYSTEM_GET_FUNCTION(glDrawElementsIndirect);
        SYSTEM_GET_FUNCTION(glUniform1d);
        SYSTEM_GET_FUNCTION(glUniform2d);
        SYSTEM_GET_FUNCTION(glUniform3d);
        SYSTEM_GET_FUNCTION(glUniform4d);
        SYSTEM_GET_FUNCTION(glUniform1dv);
        SYSTEM_GET_FUNCTION(glUniform2dv);
        SYSTEM_GET_FUNCTION(glUniform3dv);
        SYSTEM_GET_FUNCTION(glUniform4dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix2dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix3dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix4dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix2x3dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix2x4dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix3x2dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix3x4dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix4x2dv);
        SYSTEM_GET_FUNCTION(glUniformMatrix4x3dv);
        SYSTEM_GET_FUNCTION(glGetUniformdv);
        SYSTEM_GET_FUNCTION(glGetSubroutineUniformLocation);
        SYSTEM_GET_FUNCTION(glGetSubroutineIndex);
        SYSTEM_GET_FUNCTION(glGetActiveSubroutineUniformiv);
        SYSTEM_GET_FUNCTION(glGetActiveSubroutineUniformName);
        SYSTEM_GET_FUNCTION(glGetActiveSubroutineName);
        SYSTEM_GET_FUNCTION(glUniformSubroutinesuiv);
        SYSTEM_GET_FUNCTION(glGetUniformSubroutineuiv);
        SYSTEM_GET_FUNCTION(glGetProgramStageiv);
        SYSTEM_GET_FUNCTION(glPatchParameteri);
        SYSTEM_GET_FUNCTION(glPatchParameterfv);
        SYSTEM_GET_FUNCTION(glBindTransformFeedback);
        SYSTEM_GET_FUNCTION(glDeleteTransformFeedbacks);
        SYSTEM_GET_FUNCTION(glGenTransformFeedbacks);
        SYSTEM_GET_FUNCTION(glIsTransformFeedback);
        SYSTEM_GET_FUNCTION(glPauseTransformFeedback);
        SYSTEM_GET_FUNCTION(glResumeTransformFeedback);
        SYSTEM_GET_FUNCTION(glDrawTransformFeedback);
        SYSTEM_GET_FUNCTION(glDrawTransformFeedbackStream);
        SYSTEM_GET_FUNCTION(glBeginQueryIndexed);
        SYSTEM_GET_FUNCTION(glEndQueryIndexed);
        SYSTEM_GET_FUNCTION(glGetQueryIndexediv);
    }
    else
    {
        existsOpenGL40 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLMinSampleShading(GLfloat value) noexcept
{
    SYSTEM_BODY_1(glMinSampleShading, value);
}

void System::GLBlendEquationi(GLuint buf, GLenum mode) noexcept
{
    SYSTEM_BODY_2(glBlendEquationi, buf, mode);
}

void System::GLBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept
{
    SYSTEM_BODY_3(glBlendEquationSeparatei, buf, modeRGB, modeAlpha);
}

void System::GLBlendFunci(GLuint buf, GLenum src, GLenum dst) noexcept
{
    SYSTEM_BODY_3(glBlendFunci, buf, src, dst);
}

void System::GLBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept
{
    SYSTEM_BODY_5(glBlendFuncSeparatei, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void System::GLDrawArraysIndirect(GLenum mode, const void* indirect) noexcept
{
    SYSTEM_BODY_2(glDrawArraysIndirect, mode, indirect);
}

void System::GLDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) noexcept
{
    SYSTEM_BODY_3(glDrawElementsIndirect, mode, type, indirect);
}

void System::GLUniform1d(GLint location, GLdouble x) noexcept
{
    SYSTEM_BODY_2(glUniform1d, location, x);
}

void System::GLUniform2d(GLint location, GLdouble x, GLdouble y) noexcept
{
    SYSTEM_BODY_3(glUniform2d, location, x, y);
}

void System::GLUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) noexcept
{
    SYSTEM_BODY_4(glUniform3d, location, x, y, z);
}

void System::GLUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
    SYSTEM_BODY_5(glUniform4d, location, x, y, z, w);
}

void System::GLUniform1dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_3(glUniform1dv, location, count, value);
}

void System::GLUniform2dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_3(glUniform2dv, location, count, value);
}

void System::GLUniform3dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_3(glUniform3dv, location, count, value);
}

void System::GLUniform4dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_3(glUniform4dv, location, count, value);
}

void System::GLUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix2dv, location, count, transpose, value);
}

void System::GLUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix3dv, location, count, transpose, value);
}

void System::GLUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix4dv, location, count, transpose, value);
}

void System::GLUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix2x3dv, location, count, transpose, value);
}

void System::GLUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix2x4dv, location, count, transpose, value);
}

void System::GLUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix3x2dv, location, count, transpose, value);
}

void System::GLUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix3x4dv, location, count, transpose, value);
}

void System::GLUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix4x2dv, location, count, transpose, value);
}

void System::GLUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix4x3dv, location, count, transpose, value);
}

void System::GLGetUniformdv(GLuint program, GLint location, GLdouble* params) noexcept
{
    SYSTEM_BODY_3(glGetUniformdv, program, location, params);
}

GLint System::GLGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) noexcept
{
    SYSTEM_BODY_3_RESULT(glGetSubroutineUniformLocation, program, shadertype, name, 0);
}

GLuint System::GLGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) noexcept
{
    SYSTEM_BODY_3_RESULT(glGetSubroutineIndex, program, shadertype, name, 0u);
}

void System::GLGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values) noexcept
{
    SYSTEM_BODY_5(glGetActiveSubroutineUniformiv, program, shadertype, index, pname, values);
}

void System::GLGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept
{
    SYSTEM_BODY_6(glGetActiveSubroutineUniformName, program, shadertype, index, bufSize, length, name);
}

void System::GLGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept
{
    SYSTEM_BODY_6(glGetActiveSubroutineName, program, shadertype, index, bufSize, length, name);
}

void System::GLUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) noexcept
{
    SYSTEM_BODY_3(glUniformSubroutinesuiv, shadertype, count, indices);
}

void System::GLGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetUniformSubroutineuiv, shadertype, location, params);
}

void System::GLGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint* values) noexcept
{
    SYSTEM_BODY_4(glGetProgramStageiv, program, shadertype, pname, values);
}

void System::GLPatchParameteri(GLenum pname, GLint value) noexcept
{
    SYSTEM_BODY_2(glPatchParameteri, pname, value);
}

void System::GLPatchParameterfv(GLenum pname, const GLfloat* values) noexcept
{
    SYSTEM_BODY_2(glPatchParameterfv, pname, values);
}

void System::GLBindTransformFeedback(GLenum target, GLuint id) noexcept
{
    SYSTEM_BODY_2(glBindTransformFeedback, target, id);
}

void System::GLDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) noexcept
{
    SYSTEM_BODY_2(glDeleteTransformFeedbacks, n, ids);
}

void System::GLGenTransformFeedbacks(GLsizei n, GLuint* ids) noexcept
{
    SYSTEM_BODY_2(glGenTransformFeedbacks, n, ids);
}

GLboolean System::GLIsTransformFeedback(GLuint id) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsTransformFeedback, id, GL_FALSE);
}

void System::GLPauseTransformFeedback() noexcept
{
    SYSTEM_BODY_0(glPauseTransformFeedback);
}

void System::GLResumeTransformFeedback() noexcept
{
    SYSTEM_BODY_0(glResumeTransformFeedback);
}

void System::GLDrawTransformFeedback(GLenum mode, GLuint id) noexcept
{
    SYSTEM_BODY_2(glDrawTransformFeedback, mode, id);
}

void System::GLDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) noexcept
{
    SYSTEM_BODY_3(glDrawTransformFeedbackStream, mode, id, stream);
}

void System::GLBeginQueryIndexed(GLenum target, GLuint index, GLuint id) noexcept
{
    SYSTEM_BODY_3(glBeginQueryIndexed, target, index, id);
}

void System::GLEndQueryIndexed(GLenum target, GLuint index) noexcept
{
    SYSTEM_BODY_2(glEndQueryIndexed, target, index);
}

void System::GLGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetQueryIndexediv, target, index, pname, params);
}
