//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 16:27)

#include "System/SystemExport.h"

#include "GL12Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL12ExtensionsUsing.h"

// OpenGL 1.2
namespace System
{
    auto g_ExistsOpenGL12 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL12() noexcept
{
    return g_ExistsOpenGL12;
}

System::PgglCopyTexSubImage3D System::gglCopyTexSubImage3D{ nullptr };
System::PgglDrawRangeElements System::gglDrawRangeElements{ nullptr };
System::PgglTexImage3D System::gglTexImage3D{ nullptr };
System::PgglTexSubImage3D System::gglTexSubImage3D{ nullptr };

void System::GlDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices) noexcept
{
    SYSTEM_BODY_6(gglDrawRangeElements, mode, start, end, count, type, indices);
}

void System::GlTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* data) noexcept
{
    SYSTEM_BODY_10(gglTexImage3D, target, level, internalFormat, width, height, depth, border, format, type, data);
}

void System::GlTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data) noexcept
{
    SYSTEM_BODY_11(gglTexSubImage3D, target, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data);
}

void System::GlCopyTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_9(gglCopyTexSubImage3D, target, level, xOffset, yOffset, zOffset, x, y, width, height);
}

void System::InitOpenGL12()
{
    if (System::OpenGLSystemVersion::Version12 <= GetOpenGLVersion())
    {
        g_ExistsOpenGL12 = ExistsOpenGLExtensions::Exists;

        // GL_ARB_imaging
        // GL_EXT_blend_color
        // GL_EXT_blend_minmax
        // GL_EXT_color_subtable
        // GL_EXT_convolution
        // GL_EXT_histogram
        // GL_EXT_paletted_texture
        // GL_SGI_color_table

        // GL_EXT_copy_texture
        SYSTEM_GET_FUNCTION(gglCopyTexSubImage3D);

        // GL_EXT_draw_range_elements
        SYSTEM_GET_FUNCTION(gglDrawRangeElements);

        // GL_EXT_texture3D
        SYSTEM_GET_FUNCTION(gglTexImage3D);
        SYSTEM_GET_FUNCTION(gglTexSubImage3D);
    }
    else
    {
        g_ExistsOpenGL12 = ExistsOpenGLExtensions::NotExist;
    }
}
