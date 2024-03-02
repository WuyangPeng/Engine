/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:21)

#include "System/SystemExport.h"

#include "GL44Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.4
namespace System
{
    auto existsOpenGL44 = ExistsOpenGLExtensions::Unknown;

    PFNGLBUFFERSTORAGEPROC glBufferStorage{ nullptr };
    PFNGLCLEARTEXIMAGEPROC glClearTexImage{ nullptr };
    PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage{ nullptr };
    PFNGLBINDBUFFERSBASEPROC glBindBuffersBase{ nullptr };
    PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange{ nullptr };
    PFNGLBINDTEXTURESPROC glBindTextures{ nullptr };
    PFNGLBINDSAMPLERSPROC glBindSamplers{ nullptr };
    PFNGLBINDIMAGETEXTURESPROC glBindImageTextures{ nullptr };
    PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL44() noexcept
{
    return existsOpenGL44;
}

void System::InitOpenGL44() noexcept
{
    if (OpenGLSystemVersion::Version44 <= System::GetOpenGLVersion())
    {
        existsOpenGL44 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glBufferStorage);
        SYSTEM_GET_FUNCTION(glClearTexImage);
        SYSTEM_GET_FUNCTION(glClearTexSubImage);
        SYSTEM_GET_FUNCTION(glBindBuffersBase);
        SYSTEM_GET_FUNCTION(glBindBuffersRange);
        SYSTEM_GET_FUNCTION(glBindTextures);
        SYSTEM_GET_FUNCTION(glBindSamplers);
        SYSTEM_GET_FUNCTION(glBindImageTextures);
        SYSTEM_GET_FUNCTION(glBindVertexBuffers);
    }
    else
    {
        existsOpenGL44 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLBufferStorage(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags) noexcept
{
    SYSTEM_BODY_4(glBufferStorage, target, size, data, flags);
}

void System::GLClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_5(glClearTexImage, texture, level, format, type, data);
}

void System::GLClearTexSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_11(glClearTexSubImage, texture, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data);
}

void System::GLBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers) noexcept
{
    SYSTEM_BODY_4(glBindBuffersBase, target, first, count, buffers);
}

void System::GLBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes) noexcept
{
    SYSTEM_BODY_6(glBindBuffersRange, target, first, count, buffers, offsets, sizes);
}

void System::GLBindTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept
{
    SYSTEM_BODY_3(glBindTextures, first, count, textures);
}

void System::GLBindSamplers(GLuint first, GLsizei count, const GLuint* samplers) noexcept
{
    SYSTEM_BODY_3(glBindSamplers, first, count, samplers);
}

void System::GLBindImageTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept
{
    SYSTEM_BODY_3(glBindImageTextures, first, count, textures);
}

void System::GLBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept
{
    SYSTEM_BODY_5(glBindVertexBuffers, first, count, buffers, offsets, strides);
}
