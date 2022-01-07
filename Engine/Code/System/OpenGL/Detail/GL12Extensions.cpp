///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:37)

#include "System/SystemExport.h"

#include "GL12Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 1.2
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
    if (System::OpenGLSystemVersion::Version12 <= GetOpenGLVersion())
    {
        existsOpenGL12 = ExistsOpenGLExtensions::Exists;

        // GL_ARB_imaging
        // GL_EXT_blend_color
        // GL_EXT_blend_minmax
        // GL_EXT_color_subtable
        // GL_EXT_convolution
        // GL_EXT_histogram
        // GL_EXT_paletted_texture
        // GL_SGI_color_table

        // GL_EXT_copy_texture
        SYSTEM_GET_FUNCTION(glCopyTexSubImage3D);

        // GL_EXT_draw_range_elements
        SYSTEM_GET_FUNCTION(glDrawRangeElements);

        // GL_EXT_texture3D
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

void System::GLTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_10(glTexImage3D, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void System::GLTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_11(glTexSubImage3D, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void System::GLCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_9(glCopyTexSubImage3D, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
