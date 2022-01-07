///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 11:45)

#include "System/SystemExport.h"

#include "GL46Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.6
namespace System
{
    auto existsOpenGL46 = ExistsOpenGLExtensions::Unknown;

    PFNGLSPECIALIZESHADERPROC glSpecializeShader{ nullptr };
    PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount{ nullptr };
    PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount{ nullptr };
    PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL46() noexcept
{
    return existsOpenGL46;
}

void System::InitOpenGL46() noexcept
{
    if (System::OpenGLSystemVersion::Version45 <= System::GetOpenGLVersion())
    {
        SYSTEM_GET_FUNCTION(glSpecializeShader);
        SYSTEM_GET_FUNCTION(glMultiDrawArraysIndirectCount);
        SYSTEM_GET_FUNCTION(glMultiDrawElementsIndirectCount);
        SYSTEM_GET_FUNCTION(glPolygonOffsetClamp);

        existsOpenGL46 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        existsOpenGL46 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLSpecializeShader(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue) noexcept
{
    SYSTEM_BODY_5(glSpecializeShader, shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
}

void System::GLMultiDrawArraysIndirectCount(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) noexcept
{
    SYSTEM_BODY_5(glMultiDrawArraysIndirectCount, mode, indirect, drawcount, maxdrawcount, stride);
}

void System::GLMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) noexcept
{
    SYSTEM_BODY_6(glMultiDrawElementsIndirectCount, mode, type, indirect, drawcount, maxdrawcount, stride);
}

void System::GLPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) noexcept
{
    SYSTEM_BODY_3(glPolygonOffsetClamp, factor, units, clamp);
}
