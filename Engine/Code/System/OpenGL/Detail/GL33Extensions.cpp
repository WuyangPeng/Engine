/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:20)

#include "System/SystemExport.h"

#include "GL33Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 3.3
namespace System
{
    auto existsOpenGL33 = ExistsOpenGLExtensions::Unknown;

    PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed{ nullptr };
    PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex{ nullptr };
    PFNGLGENSAMPLERSPROC glGenSamplers{ nullptr };
    PFNGLDELETESAMPLERSPROC glDeleteSamplers{ nullptr };
    PFNGLISSAMPLERPROC glIsSampler{ nullptr };
    PFNGLBINDSAMPLERPROC glBindSampler{ nullptr };
    PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri{ nullptr };
    PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv{ nullptr };
    PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf{ nullptr };
    PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv{ nullptr };
    PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv{ nullptr };
    PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv{ nullptr };
    PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv{ nullptr };
    PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv{ nullptr };
    PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv{ nullptr };
    PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv{ nullptr };
    PFNGLQUERYCOUNTERPROC glQueryCounter{ nullptr };
    PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v{ nullptr };
    PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v{ nullptr };
    PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor{ nullptr };
    PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui{ nullptr };
    PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv{ nullptr };
    PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui{ nullptr };
    PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv{ nullptr };
    PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui{ nullptr };
    PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv{ nullptr };
    PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui{ nullptr };
    PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL33() noexcept
{
    return existsOpenGL33;
}

void System::InitOpenGL33() noexcept
{
    if (OpenGLSystemVersion::Version33 <= System::GetOpenGLVersion())
    {
        existsOpenGL33 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glBindFragDataLocationIndexed);
        SYSTEM_GET_FUNCTION(glGetFragDataIndex);
        SYSTEM_GET_FUNCTION(glGenSamplers);
        SYSTEM_GET_FUNCTION(glDeleteSamplers);
        SYSTEM_GET_FUNCTION(glIsSampler);
        SYSTEM_GET_FUNCTION(glBindSampler);
        SYSTEM_GET_FUNCTION(glSamplerParameteri);
        SYSTEM_GET_FUNCTION(glSamplerParameteriv);
        SYSTEM_GET_FUNCTION(glSamplerParameterf);
        SYSTEM_GET_FUNCTION(glSamplerParameterfv);
        SYSTEM_GET_FUNCTION(glSamplerParameterIiv);
        SYSTEM_GET_FUNCTION(glSamplerParameterIuiv);
        SYSTEM_GET_FUNCTION(glGetSamplerParameteriv);
        SYSTEM_GET_FUNCTION(glGetSamplerParameterIiv);
        SYSTEM_GET_FUNCTION(glGetSamplerParameterfv);
        SYSTEM_GET_FUNCTION(glGetSamplerParameterIuiv);
        SYSTEM_GET_FUNCTION(glQueryCounter);
        SYSTEM_GET_FUNCTION(glGetQueryObjecti64v);
        SYSTEM_GET_FUNCTION(glGetQueryObjectui64v);
        SYSTEM_GET_FUNCTION(glVertexAttribDivisor);
        SYSTEM_GET_FUNCTION(glVertexAttribP1ui);
        SYSTEM_GET_FUNCTION(glVertexAttribP1uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribP2ui);
        SYSTEM_GET_FUNCTION(glVertexAttribP2uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribP3ui);
        SYSTEM_GET_FUNCTION(glVertexAttribP3uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribP4ui);
        SYSTEM_GET_FUNCTION(glVertexAttribP4uiv);
    }
    else
    {
        existsOpenGL33 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) noexcept
{
    SYSTEM_BODY_4(glBindFragDataLocationIndexed, program, colorNumber, index, name);
}

GLint System::GLGetFragDataIndex(GLuint program, const GLchar* name) noexcept
{
    SYSTEM_BODY_2_RESULT(glGetFragDataIndex, program, name, 0);
}

void System::GLGenSamplers(GLsizei count, GLuint* samplers) noexcept
{
    SYSTEM_BODY_2(glGenSamplers, count, samplers);
}

void System::GLDeleteSamplers(GLsizei count, const GLuint* samplers) noexcept
{
    SYSTEM_BODY_2(glDeleteSamplers, count, samplers);
}

GLboolean System::GLIsSampler(GLuint sampler) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsSampler, sampler, GL_FALSE);
}

void System::GLBindSampler(GLuint unit, GLuint sampler) noexcept
{
    SYSTEM_BODY_2(glBindSampler, unit, sampler);
}

void System::GLSamplerParameterI(GLuint sampler, GLenum pName, GLint param) noexcept
{
    SYSTEM_BODY_3(glSamplerParameteri, sampler, pName, param);
}

void System::GLSamplerParameterIv(GLuint sampler, GLenum pName, const GLint* param) noexcept
{
    SYSTEM_BODY_3(glSamplerParameteriv, sampler, pName, param);
}

void System::GLSamplerParameterF(GLuint sampler, GLenum pName, GLfloat param) noexcept
{
    SYSTEM_BODY_3(glSamplerParameterf, sampler, pName, param);
}

void System::GLSamplerParameterFv(GLuint sampler, GLenum pName, const GLfloat* param) noexcept
{
    SYSTEM_BODY_3(glSamplerParameterfv, sampler, pName, param);
}

void System::GLSamplerParameterIiv(GLuint sampler, GLenum pName, const GLint* param) noexcept
{
    SYSTEM_BODY_3(glSamplerParameterIiv, sampler, pName, param);
}

void System::GLSamplerParameterIUiv(GLuint sampler, GLenum pName, const GLuint* param) noexcept
{
    SYSTEM_BODY_3(glSamplerParameterIuiv, sampler, pName, param);
}

void System::GLGetSamplerParameterIv(GLuint sampler, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetSamplerParameteriv, sampler, pName, params);
}

void System::GLGetSamplerParameterIiv(GLuint sampler, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetSamplerParameterIiv, sampler, pName, params);
}

void System::GLGetSamplerParameterFv(GLuint sampler, GLenum pName, GLfloat* params) noexcept
{
    SYSTEM_BODY_3(glGetSamplerParameterfv, sampler, pName, params);
}

void System::GLGetSamplerParameterIUiv(GLuint sampler, GLenum pName, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetSamplerParameterIuiv, sampler, pName, params);
}

void System::GLQueryCounter(GLuint id, GLenum target) noexcept
{
    SYSTEM_BODY_2(glQueryCounter, id, target);
}

void System::GLGetQueryObjectI64V(GLuint id, GLenum pName, GLint64* params) noexcept
{
    SYSTEM_BODY_3(glGetQueryObjecti64v, id, pName, params);
}

void System::GLGetQueryObjectUi64V(GLuint id, GLenum pName, GLuint64* params) noexcept
{
    SYSTEM_BODY_3(glGetQueryObjectui64v, id, pName, params);
}

void System::GLVertexAttribDivisor(GLuint index, GLuint divisor) noexcept
{
    SYSTEM_BODY_2(glVertexAttribDivisor, index, divisor);
}

void System::GLVertexAttribP1Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP1ui, index, type, normalized, value);
}

void System::GLVertexAttribP1Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP1uiv, index, type, normalized, value);
}

void System::GLVertexAttribP2Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP2ui, index, type, normalized, value);
}

void System::GLVertexAttribP2Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP2uiv, index, type, normalized, value);
}

void System::GLVertexAttribP3Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP3ui, index, type, normalized, value);
}

void System::GLVertexAttribP3Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP3uiv, index, type, normalized, value);
}

void System::GLVertexAttribP4Ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP4ui, index, type, normalized, value);
}

void System::GLVertexAttribP4Uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glVertexAttribP4uiv, index, type, normalized, value);
}
