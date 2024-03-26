/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:05)

#include "System/SystemExport.h"

#include "GL12Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

/// OpenGL 1.2
namespace System
{
    auto existsOpenGL12 = ExistsOpenGLExtensions::Unknown;

    PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements{ nullptr };
    PFNGLTEXIMAGE3DPROC glTexImage3D{ nullptr };
    PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D{ nullptr };
    PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL12() noexcept
{
    return existsOpenGL12;
}

void System::InitOpenGL12() noexcept
{
    if (OpenGLSystemVersion::Version12 <= GetOpenGLVersion())
    {
        existsOpenGL12 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glCopyTexSubImage3D);

        SYSTEM_GET_FUNCTION(glDrawRangeElements);

        SYSTEM_GET_FUNCTION(glTexImage3D);
        SYSTEM_GET_FUNCTION(glTexSubImage3D);
    }
    else
    {
        existsOpenGL12 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices) noexcept
{
    SYSTEM_BODY_6(glDrawRangeElements, mode, start, end, count, type, indices);
}

void System::GLTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_10(glTexImage3D, target, level, internalFormat, width, height, depth, border, format, type, pixels);
}

void System::GLTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_11(glTexSubImage3D, target, level, xOffset, yOffset, zOffset, width, height, depth, format, type, pixels);
}

void System::GLCopyTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_9(glCopyTexSubImage3D, target, level, xOffset, yOffset, zOffset, x, y, width, height);
}
