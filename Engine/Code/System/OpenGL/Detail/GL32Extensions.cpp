//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:51)

#include "System/SystemExport.h"

#include "GL32Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL32ExtensionsUsing.h"

// OpenGL 3.2
namespace System
{
    auto g_ExistsOpenGL32 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL32() noexcept
{
    return g_ExistsOpenGL32;
}

System::PgglGetInteger64i_v System::gglGetInteger64i_v{ nullptr };
System::PgglGetBufferParameteri64v System::gglGetBufferParameteri64v{ nullptr };
System::PgglProgramParameteri System::gglProgramParameteri{ nullptr };
System::PgglFramebufferTexture System::gglFramebufferTexture{ nullptr };

void System::GlGetInteger64i_v(GLenum target, GLuint index, GLint64* data) noexcept
{
    SYSTEM_BODY_3(gglGetInteger64i_v, target, index, data);
}

void System::GlGetBufferParameteri64v(GLenum target, GLenum name, GLint64* params) noexcept
{
    SYSTEM_BODY_3(gglGetBufferParameteri64v, target, name, params);
}

void System::GlProgramParameteri(GLuint program, GLenum name, GLint value) noexcept
{
    SYSTEM_BODY_3(gglProgramParameteri, program, name, value);
}

void System::GlFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_4(gglFramebufferTexture, target, attachment, texture, level);
}

void System::InitOpenGL32()
{
    if (System::OpenGLSystemVersion::Version32 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL32 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglGetInteger64i_v);
        SYSTEM_GET_FUNCTION(gglGetBufferParameteri64v);
        SYSTEM_GET_FUNCTION(gglProgramParameteri);
        SYSTEM_GET_FUNCTION(gglFramebufferTexture);
    }
    else
    {
        g_ExistsOpenGL32 = ExistsOpenGLExtensions::NotExist;
    }
}