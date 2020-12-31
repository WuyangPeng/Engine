//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:55)

#include "System/SystemExport.h"

#include "GL45Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL45ExtensionsUsing.h"

// OpenGL 4.5
namespace System
{
    auto g_ExistsOpenGL45 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL45() noexcept
{
    return g_ExistsOpenGL45;
}

System::PgglGetGraphicsResetStatus System::gglGetGraphicsResetStatus{ nullptr };
System::PgglGetnCompressedTexImage System::gglGetnCompressedTexImage{ nullptr };
System::PgglGetnTexImage System::gglGetnTexImage{ nullptr };
System::PgglGetnUniformdv System::gglGetnUniformdv{ nullptr };

GLenum System::GlGetGraphicsResetStatus() noexcept
{
    SYSTEM_BODY_0_RESULT(gglGetGraphicsResetStatus, GLenum, EnumCastUnderlying<GLenum>(OpenGLErrorCode::InvalidValue));
}

void System::GlGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels) noexcept
{
    SYSTEM_BODY_4(gglGetnCompressedTexImage, target, lod, bufSize, pixels);
}

void System::GlGetnTexImage(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept
{
    SYSTEM_BODY_6(gglGetnTexImage, tex, level, format, type, bufSize, pixels);
}

void System::GlGetnUniformdv(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept
{
    SYSTEM_BODY_6(gglGetnUniformdv, tex, level, format, type, bufSize, pixels);
}

void System::InitOpenGL45()
{
    if (System::OpenGLSystemVersion::Version45 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL45 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglGetGraphicsResetStatus);
        SYSTEM_GET_FUNCTION(gglGetnCompressedTexImage);
        SYSTEM_GET_FUNCTION(gglGetnTexImage);
        SYSTEM_GET_FUNCTION(gglGetnUniformdv);
    }
    else
    {
        g_ExistsOpenGL45 = ExistsOpenGLExtensions::NotExist;
    }
}