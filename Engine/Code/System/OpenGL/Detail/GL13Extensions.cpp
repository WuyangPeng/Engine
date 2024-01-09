/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:19)

#include "System/SystemExport.h"

#include "GL13Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 1.3
namespace System
{
    auto existsOpenGL13 = ExistsOpenGLExtensions::Unknown;

    PFNGLACTIVETEXTUREPROC glActiveTexture{ nullptr };
    PFNGLSAMPLECOVERAGEPROC glSampleCoverage{ nullptr };
    PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D{ nullptr };
    PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D{ nullptr };
    PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D{ nullptr };
    PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D{ nullptr };
    PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D{ nullptr };
    PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D{ nullptr };
    PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL13() noexcept
{
    return existsOpenGL13;
}

void System::InitOpenGL13() noexcept
{
    if (OpenGLSystemVersion::Version13 <= GetOpenGLVersion())
    {
        existsOpenGL13 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glSampleCoverage);

        SYSTEM_GET_FUNCTION(glActiveTexture);

        SYSTEM_GET_FUNCTION(glCompressedTexImage3D);
        SYSTEM_GET_FUNCTION(glCompressedTexImage2D);
        SYSTEM_GET_FUNCTION(glCompressedTexImage1D);
        SYSTEM_GET_FUNCTION(glCompressedTexSubImage3D);
        SYSTEM_GET_FUNCTION(glCompressedTexSubImage2D);
        SYSTEM_GET_FUNCTION(glCompressedTexSubImage1D);
        SYSTEM_GET_FUNCTION(glGetCompressedTexImage);
    }
    else
    {
        existsOpenGL13 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLActiveTexture(GLenum texture) noexcept
{
    SYSTEM_BODY_1(glActiveTexture, texture);
}

void System::GLSampleCoverage(GLfloat value, GLboolean invert) noexcept
{
    SYSTEM_BODY_2(glSampleCoverage, value, invert);
}

void System::GLCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_9(glCompressedTexImage3D, target, level, internalformat, width, height, depth, border, imageSize, data);
}

void System::GLCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_8(glCompressedTexImage2D, target, level, internalformat, width, height, border, imageSize, data);
}

void System::GLCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_7(glCompressedTexImage1D, target, level, internalformat, width, border, imageSize, data);
}

void System::GLCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_11(glCompressedTexSubImage3D, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void System::GLCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_9(glCompressedTexSubImage2D, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void System::GLCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_7(glCompressedTexSubImage1D, target, level, xoffset, width, format, imageSize, data);
}

void System::GLGetCompressedTexImage(GLenum target, GLint level, void* img) noexcept
{
    SYSTEM_BODY_3(glGetCompressedTexImage, target, level, img);
}
