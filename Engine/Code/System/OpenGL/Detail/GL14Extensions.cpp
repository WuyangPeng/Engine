/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:19)

#include "System/SystemExport.h"

#include "GL14Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 1.4

namespace System
{
    auto existsOpenGL14 = ExistsOpenGLExtensions::Unknown;

    PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate{ nullptr };
    PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays{ nullptr };
    PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements{ nullptr };
    PFNGLPOINTPARAMETERFPROC glPointParameterf{ nullptr };
    PFNGLPOINTPARAMETERFVPROC glPointParameterfv{ nullptr };
    PFNGLPOINTPARAMETERIPROC glPointParameteri{ nullptr };
    PFNGLPOINTPARAMETERIVPROC glPointParameteriv{ nullptr };
    PFNGLBLENDCOLORPROC glBlendColor{ nullptr };
    PFNGLBLENDEQUATIONPROC glBlendEquation{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL14() noexcept
{
    return existsOpenGL14;
}

void System::InitOpenGL14() noexcept
{
    if (OpenGLSystemVersion::Version14 <= GetOpenGLVersion())
    {
        existsOpenGL14 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glBlendFuncSeparate);

        SYSTEM_GET_FUNCTION(glMultiDrawArrays);
        SYSTEM_GET_FUNCTION(glMultiDrawElements);

        SYSTEM_GET_FUNCTION(glPointParameterf);
        SYSTEM_GET_FUNCTION(glPointParameterfv);

        SYSTEM_GET_FUNCTION(glPointParameteri);
        SYSTEM_GET_FUNCTION(glPointParameteriv);

        SYSTEM_GET_FUNCTION(glBlendColor);
        SYSTEM_GET_FUNCTION(glBlendEquation);
    }
    else
    {
        existsOpenGL14 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLBlendFuncSeparate(GLenum sFactorRGB, GLenum dFactorRGB, GLenum sFactorAlpha, GLenum dFactorAlpha) noexcept
{
    SYSTEM_BODY_4(glBlendFuncSeparate, sFactorRGB, dFactorRGB, sFactorAlpha, dFactorAlpha);
}

void System::GLMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawCount) noexcept
{
    SYSTEM_BODY_4(glMultiDrawArrays, mode, first, count, drawCount);
}

void System::GLMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawCount) noexcept
{
    SYSTEM_BODY_5(glMultiDrawElements, mode, count, type, indices, drawCount);
}

void System::GLPointParameterF(GLenum pName, GLfloat param) noexcept
{
    SYSTEM_BODY_2(glPointParameterf, pName, param);
}

void System::GLPointParameterFv(GLenum pName, const GLfloat* params) noexcept
{
    SYSTEM_BODY_2(glPointParameterfv, pName, params);
}

void System::GLPointParameterI(GLenum pName, GLint param) noexcept
{
    SYSTEM_BODY_2(glPointParameteri, pName, param);
}

void System::GLPointParameterIv(GLenum pName, const GLint* params) noexcept
{
    SYSTEM_BODY_2(glPointParameteriv, pName, params);
}

void System::GLBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept
{
    SYSTEM_BODY_4(glBlendColor, red, green, blue, alpha);
}

void System::GLBlendEquation(GLenum mode) noexcept
{
    SYSTEM_BODY_1(glBlendEquation, mode);
}
