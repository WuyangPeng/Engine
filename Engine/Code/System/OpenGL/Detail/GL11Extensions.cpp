/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:04)

#include "System/SystemExport.h"

#include "GL11Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

/// OpenGL 1.1
namespace System
{
    auto existsOpenGL11 = ExistsOpenGLExtensions::Exists;

#ifdef SYSTEM_PLATFORM_WIN32

    extern "C"
    {
        OPENGL_EXTERN void OPENGL_STDCALL glDrawArrays(GLenum mode, GLint first, GLsizei count);
        OPENGL_EXTERN void OPENGL_STDCALL glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices);
        OPENGL_EXTERN void OPENGL_STDCALL glGetPointerv(GLenum pName, void** params);
        OPENGL_EXTERN void OPENGL_STDCALL glPolygonOffset(GLfloat factor, GLfloat units);
        OPENGL_EXTERN void OPENGL_STDCALL glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
        OPENGL_EXTERN void OPENGL_STDCALL glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
        OPENGL_EXTERN void OPENGL_STDCALL glCopyTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width);
        OPENGL_EXTERN void OPENGL_STDCALL glCopyTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height);
        OPENGL_EXTERN void OPENGL_STDCALL glTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
        OPENGL_EXTERN void OPENGL_STDCALL glTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
        OPENGL_EXTERN void OPENGL_STDCALL glBindTexture(GLenum target, GLuint texture);
        OPENGL_EXTERN void OPENGL_STDCALL glDeleteTextures(GLsizei n, const GLuint* textures);
        OPENGL_EXTERN void OPENGL_STDCALL glGenTextures(GLsizei n, GLuint* textures);
        OPENGL_EXTERN GLboolean OPENGL_STDCALL glIsTexture(GLuint texture);
    }

#else  // !SYSTEM_PLATFORM_WIN32

    PFNGLDRAWARRAYSPROC glDrawArrays{ nullptr };
    PFNGLDRAWELEMENTSPROC glDrawElements{ nullptr };
    PFNGLGETPOINTERVPROC glGetPointerv{ nullptr };
    PFNGLPOLYGONOFFSETPROC glPolygonOffset{ nullptr };
    PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D{ nullptr };
    PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D{ nullptr };
    PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D{ nullptr };
    PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D{ nullptr };
    PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D{ nullptr };
    PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D{ nullptr };
    PFNGLBINDTEXTUREPROC glBindTexture{ nullptr };
    PFNGLDELETETEXTURESPROC glDeleteTextures{ nullptr };
    PFNGLGENTEXTURESPROC glGenTextures{ nullptr };
    PFNGLISTEXTUREPROC glIsTexture{ nullptr };

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL11() noexcept
{
    return existsOpenGL11;
}

void System::InitOpenGL11() noexcept
{
    if (OpenGLSystemVersion::Version11 <= GetOpenGLVersion())
    {
        existsOpenGL11 = ExistsOpenGLExtensions::Exists;

#ifndef SYSTEM_PLATFORM_WIN32

        SYSTEM_GET_FUNCTION(glDrawArrays);
        SYSTEM_GET_FUNCTION(glDrawElements);
        SYSTEM_GET_FUNCTION(glGetPointerv);
        SYSTEM_GET_FUNCTION(glPolygonOffset);
        SYSTEM_GET_FUNCTION(glCopyTexImage1D);
        SYSTEM_GET_FUNCTION(glCopyTexImage2D);
        SYSTEM_GET_FUNCTION(glCopyTexSubImage1D);
        SYSTEM_GET_FUNCTION(glCopyTexSubImage2D);
        SYSTEM_GET_FUNCTION(glTexSubImage1D);
        SYSTEM_GET_FUNCTION(glTexSubImage2D);
        SYSTEM_GET_FUNCTION(glBindTexture);
        SYSTEM_GET_FUNCTION(glDeleteTextures);
        SYSTEM_GET_FUNCTION(glGenTextures);
        SYSTEM_GET_FUNCTION(glIsTexture);

#endif  // SYSTEM_PLATFORM_WIN32
    }
    else
    {
        existsOpenGL11 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLDrawArrays(GLenum mode, GLint first, GLsizei count) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_3(glDrawArrays, mode, first, count);
}

void System::GLDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_4(glDrawElements, mode, count, type, indices);
}

void System::GLGetPointerV(GLenum pName, void** params) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glGetPointerv, pName, params);
}

void System::GLPolygonOffset(GLfloat factor, GLfloat units) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glPolygonOffset, factor, units);
}

void System::GLCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_7(glCopyTexImage1D, target, level, internalFormat, x, y, width, border);
}

void System::GLCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_8(glCopyTexImage2D, target, level, internalFormat, x, y, width, height, border);
}

void System::GLCopyTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_6(glCopyTexSubImage1D, target, level, xOffset, x, y, width);
}

void System::GLCopyTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_8(glCopyTexSubImage2D, target, level, xOffset, yOffset, x, y, width, height);
}

void System::GLTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_7(glTexSubImage1D, target, level, xOffset, width, format, type, pixels);
}

void System::GLTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_9(glTexSubImage2D, target, level, xOffset, yOffset, width, height, format, type, pixels);
}

void System::GLBindTexture(GLenum target, GLuint texture) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glBindTexture, target, texture);
}

void System::GLDeleteTextures(GLsizei n, const GLuint* textures) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glDeleteTextures, n, textures);
}

void System::GLGenTextures(GLsizei n, GLuint* textures) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_2(glGenTextures, n, textures);
}

GLboolean System::GLIsTexture(GLuint texture) noexcept
{
    SYSTEM_PREVIOUSLY_BODY_1_RESULT(glIsTexture, texture, GL_FALSE);
}