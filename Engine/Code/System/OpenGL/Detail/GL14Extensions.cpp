///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 18:55)

#include "System/SystemExport.h"

#include "GL14Extensions.h"
#include "GLUtility.h"
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
    if (System::OpenGLSystemVersion::Version14 <= GetOpenGLVersion())
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

void System::GLBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) noexcept
{
    SYSTEM_BODY_4(glBlendFuncSeparate, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void System::GLMultiDrawArrays(GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount) noexcept
{
    SYSTEM_BODY_4(glMultiDrawArrays, mode, first, count, drawcount);
}

void System::GLMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount) noexcept
{
    SYSTEM_BODY_5(glMultiDrawElements, mode, count, type, indices, drawcount);
}

void System::GLPointParameterf(GLenum pname, GLfloat param) noexcept
{
    SYSTEM_BODY_2(glPointParameterf, pname, param);
}

void System::GLPointParameterfv(GLenum pname, const GLfloat* params) noexcept
{
    SYSTEM_BODY_2(glPointParameterfv, pname, params);
}

void System::GLPointParameteri(GLenum pname, GLint param) noexcept
{
    SYSTEM_BODY_2(glPointParameteri, pname, param);
}

void System::GLPointParameteriv(GLenum pname, const GLint* params) noexcept
{
    SYSTEM_BODY_2(glPointParameteriv, pname, params);
}

void System::GLBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) noexcept
{
    SYSTEM_BODY_4(glBlendColor, red, green, blue, alpha);
}

void System::GLBlendEquation(GLenum mode) noexcept
{
    SYSTEM_BODY_1(glBlendEquation, mode);
}
