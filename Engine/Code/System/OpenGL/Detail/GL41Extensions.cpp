/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:09)

#include "System/SystemExport.h"

#include "GL41Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

/// OpenGL 4.1
namespace System
{
    auto existsOpenGL41 = ExistsOpenGLExtensions::Unknown;

    PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler{ nullptr };
    PFNGLSHADERBINARYPROC glShaderBinary{ nullptr };
    PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat{ nullptr };
    PFNGLDEPTHRANGEFPROC glDepthRangef{ nullptr };
    PFNGLCLEARDEPTHFPROC glClearDepthf{ nullptr };
    PFNGLGETPROGRAMBINARYPROC glGetProgramBinary{ nullptr };
    PFNGLPROGRAMBINARYPROC glProgramBinary{ nullptr };
    PFNGLPROGRAMPARAMETERIPROC glProgramParameteri{ nullptr };
    PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages{ nullptr };
    PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram{ nullptr };
    PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv{ nullptr };
    PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline{ nullptr };
    PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines{ nullptr };
    PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines{ nullptr };
    PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline{ nullptr };
    PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv{ nullptr };
    PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i{ nullptr };
    PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv{ nullptr };
    PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f{ nullptr };
    PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv{ nullptr };
    PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d{ nullptr };
    PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv{ nullptr };
    PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui{ nullptr };
    PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv{ nullptr };
    PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i{ nullptr };
    PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv{ nullptr };
    PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f{ nullptr };
    PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv{ nullptr };
    PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d{ nullptr };
    PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv{ nullptr };
    PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui{ nullptr };
    PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv{ nullptr };
    PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i{ nullptr };
    PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv{ nullptr };
    PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f{ nullptr };
    PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv{ nullptr };
    PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d{ nullptr };
    PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv{ nullptr };
    PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui{ nullptr };
    PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv{ nullptr };
    PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i{ nullptr };
    PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv{ nullptr };
    PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f{ nullptr };
    PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv{ nullptr };
    PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d{ nullptr };
    PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv{ nullptr };
    PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui{ nullptr };
    PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv{ nullptr };
    PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv{ nullptr };
    PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline{ nullptr };
    PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog{ nullptr };
    PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d{ nullptr };
    PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d{ nullptr };
    PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d{ nullptr };
    PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d{ nullptr };
    PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv{ nullptr };
    PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv{ nullptr };
    PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv{ nullptr };
    PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv{ nullptr };
    PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer{ nullptr };
    PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv{ nullptr };
    PFNGLVIEWPORTARRAYVPROC glViewportArrayv{ nullptr };
    PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf{ nullptr };
    PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv{ nullptr };
    PFNGLSCISSORARRAYVPROC glScissorArrayv{ nullptr };
    PFNGLSCISSORINDEXEDPROC glScissorIndexed{ nullptr };
    PFNGLSCISSORINDEXEDVPROC glScissorIndexedv{ nullptr };
    PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv{ nullptr };
    PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed{ nullptr };
    PFNGLGETFLOATI_VPROC glGetFloati_v{ nullptr };
    PFNGLGETDOUBLEI_VPROC glGetDoublei_v{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL41() noexcept
{
    return existsOpenGL41;
}

void System::InitOpenGL41() noexcept
{
    if (OpenGLSystemVersion::Version41 <= GetOpenGLVersion())
    {
        existsOpenGL41 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glReleaseShaderCompiler);
        SYSTEM_GET_FUNCTION(glShaderBinary);
        SYSTEM_GET_FUNCTION(glGetShaderPrecisionFormat);
        SYSTEM_GET_FUNCTION(glDepthRangef);
        SYSTEM_GET_FUNCTION(glClearDepthf);
        SYSTEM_GET_FUNCTION(glGetProgramBinary);
        SYSTEM_GET_FUNCTION(glProgramBinary);
        SYSTEM_GET_FUNCTION(glProgramParameteri);
        SYSTEM_GET_FUNCTION(glUseProgramStages);
        SYSTEM_GET_FUNCTION(glActiveShaderProgram);
        SYSTEM_GET_FUNCTION(glCreateShaderProgramv);
        SYSTEM_GET_FUNCTION(glBindProgramPipeline);
        SYSTEM_GET_FUNCTION(glDeleteProgramPipelines);
        SYSTEM_GET_FUNCTION(glGenProgramPipelines);
        SYSTEM_GET_FUNCTION(glIsProgramPipeline);
        SYSTEM_GET_FUNCTION(glGetProgramPipelineiv);
        SYSTEM_GET_FUNCTION(glProgramUniform1i);
        SYSTEM_GET_FUNCTION(glProgramUniform1iv);
        SYSTEM_GET_FUNCTION(glProgramUniform1f);
        SYSTEM_GET_FUNCTION(glProgramUniform1fv);
        SYSTEM_GET_FUNCTION(glProgramUniform1d);
        SYSTEM_GET_FUNCTION(glProgramUniform1dv);
        SYSTEM_GET_FUNCTION(glProgramUniform1ui);
        SYSTEM_GET_FUNCTION(glProgramUniform1uiv);
        SYSTEM_GET_FUNCTION(glProgramUniform2i);
        SYSTEM_GET_FUNCTION(glProgramUniform2iv);
        SYSTEM_GET_FUNCTION(glProgramUniform2f);
        SYSTEM_GET_FUNCTION(glProgramUniform2fv);
        SYSTEM_GET_FUNCTION(glProgramUniform2d);
        SYSTEM_GET_FUNCTION(glProgramUniform2dv);
        SYSTEM_GET_FUNCTION(glProgramUniform2ui);
        SYSTEM_GET_FUNCTION(glProgramUniform2uiv);
        SYSTEM_GET_FUNCTION(glProgramUniform3i);
        SYSTEM_GET_FUNCTION(glProgramUniform3iv);
        SYSTEM_GET_FUNCTION(glProgramUniform3f);
        SYSTEM_GET_FUNCTION(glProgramUniform3fv);
        SYSTEM_GET_FUNCTION(glProgramUniform3d);
        SYSTEM_GET_FUNCTION(glProgramUniform3dv);
        SYSTEM_GET_FUNCTION(glProgramUniform3ui);
        SYSTEM_GET_FUNCTION(glProgramUniform3uiv);
        SYSTEM_GET_FUNCTION(glProgramUniform4i);
        SYSTEM_GET_FUNCTION(glProgramUniform4iv);
        SYSTEM_GET_FUNCTION(glProgramUniform4f);
        SYSTEM_GET_FUNCTION(glProgramUniform4fv);
        SYSTEM_GET_FUNCTION(glProgramUniform4d);
        SYSTEM_GET_FUNCTION(glProgramUniform4dv);
        SYSTEM_GET_FUNCTION(glProgramUniform4ui);
        SYSTEM_GET_FUNCTION(glProgramUniform4uiv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix2fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix3fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix4fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix2dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix3dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix4dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix2x3fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix3x2fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix2x4fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix4x2fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix3x4fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix4x3fv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix2x3dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix3x2dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix2x4dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix4x2dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix3x4dv);
        SYSTEM_GET_FUNCTION(glProgramUniformMatrix4x3dv);
        SYSTEM_GET_FUNCTION(glValidateProgramPipeline);
        SYSTEM_GET_FUNCTION(glGetProgramPipelineInfoLog);
        SYSTEM_GET_FUNCTION(glVertexAttribL1d);
        SYSTEM_GET_FUNCTION(glVertexAttribL2d);
        SYSTEM_GET_FUNCTION(glVertexAttribL3d);
        SYSTEM_GET_FUNCTION(glVertexAttribL4d);
        SYSTEM_GET_FUNCTION(glVertexAttribL1dv);
        SYSTEM_GET_FUNCTION(glVertexAttribL2dv);
        SYSTEM_GET_FUNCTION(glVertexAttribL3dv);
        SYSTEM_GET_FUNCTION(glVertexAttribL4dv);
        SYSTEM_GET_FUNCTION(glVertexAttribLPointer);
        SYSTEM_GET_FUNCTION(glGetVertexAttribLdv);
        SYSTEM_GET_FUNCTION(glViewportArrayv);
        SYSTEM_GET_FUNCTION(glViewportIndexedf);
        SYSTEM_GET_FUNCTION(glViewportIndexedfv);
        SYSTEM_GET_FUNCTION(glScissorArrayv);
        SYSTEM_GET_FUNCTION(glScissorIndexed);
        SYSTEM_GET_FUNCTION(glScissorIndexedv);
        SYSTEM_GET_FUNCTION(glDepthRangeArrayv);
        SYSTEM_GET_FUNCTION(glDepthRangeIndexed);
        SYSTEM_GET_FUNCTION(glGetFloati_v);
        SYSTEM_GET_FUNCTION(glGetDoublei_v);
    }
    else
    {
        existsOpenGL41 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLReleaseShaderCompiler() noexcept
{
    SYSTEM_BODY_0(glReleaseShaderCompiler);
}

void System::GLShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length) noexcept
{
    SYSTEM_BODY_5(glShaderBinary, count, shaders, binaryFormat, binary, length);
}

void System::GLGetShaderPrecisionFormat(GLenum shaderType, GLenum precisionType, GLint* range, GLint* precision) noexcept
{
    SYSTEM_BODY_4(glGetShaderPrecisionFormat, shaderType, precisionType, range, precision);
}

void System::GLDepthRangeF(GLfloat n, GLfloat f) noexcept
{
    SYSTEM_BODY_2(glDepthRangef, n, f);
}

void System::GLClearDepthF(GLfloat d) noexcept
{
    SYSTEM_BODY_1(glClearDepthf, d);
}

void System::GLGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary) noexcept
{
    SYSTEM_BODY_5(glGetProgramBinary, program, bufSize, length, binaryFormat, binary);
}

void System::GLProgramBinary(GLuint program, GLenum binaryFormat, const void* binary, GLsizei length) noexcept
{
    SYSTEM_BODY_4(glProgramBinary, program, binaryFormat, binary, length);
}

void System::GLProgramParameterI(GLuint program, GLenum pName, GLint value) noexcept
{
    SYSTEM_BODY_3(glProgramParameteri, program, pName, value);
}

void System::GLUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) noexcept
{
    SYSTEM_BODY_3(glUseProgramStages, pipeline, stages, program);
}

void System::GLActiveShaderProgram(GLuint pipeline, GLuint program) noexcept
{
    SYSTEM_BODY_2(glActiveShaderProgram, pipeline, program);
}

GLuint System::GLCreateShaderProgramV(GLenum type, GLsizei count, const GLchar* const* strings) noexcept
{
    SYSTEM_BODY_3_RESULT(glCreateShaderProgramv, type, count, strings, 0u);
}

void System::GLBindProgramPipeline(GLuint pipeline) noexcept
{
    SYSTEM_BODY_1(glBindProgramPipeline, pipeline);
}

void System::GLDeleteProgramPipelines(GLsizei n, const GLuint* pipelines) noexcept
{
    SYSTEM_BODY_2(glDeleteProgramPipelines, n, pipelines);
}

void System::GLGenProgramPipelines(GLsizei n, GLuint* pipelines) noexcept
{
    SYSTEM_BODY_2(glGenProgramPipelines, n, pipelines);
}

GLboolean System::GLIsProgramPipeline(GLuint pipeline) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsProgramPipeline, pipeline, GL_FALSE);
}

void System::GLGetProgramPipelineIv(GLuint pipeline, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetProgramPipelineiv, pipeline, pName, params);
}

void System::GLProgramUniform1I(GLuint program, GLint location, GLint v0) noexcept
{
    SYSTEM_BODY_3(glProgramUniform1i, program, location, v0);
}

void System::GLProgramUniform1Iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform1iv, program, location, count, value);
}

void System::GLProgramUniform1F(GLuint program, GLint location, GLfloat v0) noexcept
{
    SYSTEM_BODY_3(glProgramUniform1f, program, location, v0);
}

void System::GLProgramUniform1Fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform1fv, program, location, count, value);
}

void System::GLProgramUniform1d(GLuint program, GLint location, GLdouble v0) noexcept
{
    SYSTEM_BODY_3(glProgramUniform1d, program, location, v0);
}

void System::GLProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform1dv, program, location, count, value);
}

void System::GLProgramUniform1Ui(GLuint program, GLint location, GLuint v0) noexcept
{
    SYSTEM_BODY_3(glProgramUniform1ui, program, location, v0);
}

void System::GLProgramUniform1Uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform1uiv, program, location, count, value);
}

void System::GLProgramUniform2I(GLuint program, GLint location, GLint v0, GLint v1) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2i, program, location, v0, v1);
}

void System::GLProgramUniform2Iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2iv, program, location, count, value);
}

void System::GLProgramUniform2F(GLuint program, GLint location, GLfloat v0, GLfloat v1) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2f, program, location, v0, v1);
}

void System::GLProgramUniform2Fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2fv, program, location, count, value);
}

void System::GLProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2d, program, location, v0, v1);
}

void System::GLProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2dv, program, location, count, value);
}

void System::GLProgramUniform2Ui(GLuint program, GLint location, GLuint v0, GLuint v1) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2ui, program, location, v0, v1);
}

void System::GLProgramUniform2Uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform2uiv, program, location, count, value);
}

void System::GLProgramUniform3I(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) noexcept
{
    SYSTEM_BODY_5(glProgramUniform3i, program, location, v0, v1, v2);
}

void System::GLProgramUniform3Iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform3iv, program, location, count, value);
}

void System::GLProgramUniform3F(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept
{
    SYSTEM_BODY_5(glProgramUniform3f, program, location, v0, v1, v2);
}

void System::GLProgramUniform3Fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform3fv, program, location, count, value);
}

void System::GLProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) noexcept
{
    SYSTEM_BODY_5(glProgramUniform3d, program, location, v0, v1, v2);
}

void System::GLProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform3dv, program, location, count, value);
}

void System::GLProgramUniform3Ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept
{
    SYSTEM_BODY_5(glProgramUniform3ui, program, location, v0, v1, v2);
}

void System::GLProgramUniform3Uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform3uiv, program, location, count, value);
}

void System::GLProgramUniform4I(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept
{
    SYSTEM_BODY_6(glProgramUniform4i, program, location, v0, v1, v2, v3);
}

void System::GLProgramUniform4Iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform4iv, program, location, count, value);
}

void System::GLProgramUniform4F(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept
{
    SYSTEM_BODY_6(glProgramUniform4f, program, location, v0, v1, v2, v3);
}

void System::GLProgramUniform4Fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform4fv, program, location, count, value);
}

void System::GLProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) noexcept
{
    SYSTEM_BODY_6(glProgramUniform4d, program, location, v0, v1, v2, v3);
}

void System::GLProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform4dv, program, location, count, value);
}

void System::GLProgramUniform4Ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept
{
    SYSTEM_BODY_6(glProgramUniform4ui, program, location, v0, v1, v2, v3);
}

void System::GLProgramUniform4Uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glProgramUniform4uiv, program, location, count, value);
}

void System::GLProgramUniformMatrix2Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix2fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix3Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix3fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix4Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix4fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix2dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix3dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix4dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix2X3Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix2x3fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix3X2Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix3x2fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix2X4Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix2x4fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix4X2Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix4x2fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix3X4Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix3x4fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix4X3Fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix4x3fv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix2X3Dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix2x3dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix3X2Dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix3x2dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix2X4Dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix2x4dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix4X2Dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix4x2dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix3X4Dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix3x4dv, program, location, count, transpose, value);
}

void System::GLProgramUniformMatrix4X3Dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
    SYSTEM_BODY_5(glProgramUniformMatrix4x3dv, program, location, count, transpose, value);
}

void System::GLValidateProgramPipeline(GLuint pipeline) noexcept
{
    SYSTEM_BODY_1(glValidateProgramPipeline, pipeline);
}

void System::GLGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept
{
    SYSTEM_BODY_4(glGetProgramPipelineInfoLog, pipeline, bufSize, length, infoLog);
}

void System::GLVertexAttribL1d(GLuint index, GLdouble x) noexcept
{
    SYSTEM_BODY_2(glVertexAttribL1d, index, x);
}

void System::GLVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) noexcept
{
    SYSTEM_BODY_3(glVertexAttribL2d, index, x, y);
}

void System::GLVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept
{
    SYSTEM_BODY_4(glVertexAttribL3d, index, x, y, z);
}

void System::GLVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
    SYSTEM_BODY_5(glVertexAttribL4d, index, x, y, z, w);
}

void System::GLVertexAttribL1dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribL1dv, index, v);
}

void System::GLVertexAttribL2dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribL2dv, index, v);
}

void System::GLVertexAttribL3dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribL3dv, index, v);
}

void System::GLVertexAttribL4dv(GLuint index, const GLdouble* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribL4dv, index, v);
}

void System::GLVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept
{
    SYSTEM_BODY_5(glVertexAttribLPointer, index, size, type, stride, pointer);
}

void System::GLGetVertexAttribLdv(GLuint index, GLenum pName, GLdouble* params) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribLdv, index, pName, params);
}

void System::GLViewportArrayV(GLuint first, GLsizei count, const GLfloat* v) noexcept
{
    SYSTEM_BODY_3(glViewportArrayv, first, count, v);
}

void System::GLViewportIndexedF(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) noexcept
{
    SYSTEM_BODY_5(glViewportIndexedf, index, x, y, w, h);
}

void System::GLViewportIndexedFv(GLuint index, const GLfloat* v) noexcept
{
    SYSTEM_BODY_2(glViewportIndexedfv, index, v);
}

void System::GLScissorArrayV(GLuint first, GLsizei count, const GLint* v) noexcept
{
    SYSTEM_BODY_3(glScissorArrayv, first, count, v);
}

void System::GLScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glScissorIndexed, index, left, bottom, width, height);
}

void System::GLScissorIndexedV(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glScissorIndexedv, index, v);
}

void System::GLDepthRangeArrayV(GLuint first, GLsizei count, const GLdouble* v) noexcept
{
    SYSTEM_BODY_3(glDepthRangeArrayv, first, count, v);
}

void System::GLDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) noexcept
{
    SYSTEM_BODY_3(glDepthRangeIndexed, index, n, f);
}

void System::GLGetFloatIv(GLenum target, GLuint index, GLfloat* data) noexcept
{
    SYSTEM_BODY_3(glGetFloati_v, target, index, data);
}

void System::GLGetDoubleIv(GLenum target, GLuint index, GLdouble* data) noexcept
{
    SYSTEM_BODY_3(glGetDoublei_v, target, index, data);
}
