///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/09 15:35)

#include "System/SystemExport.h"

#include "GL15Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 1.5

namespace System
{
    auto existsOpenGL15 = ExistsOpenGLExtensions::Unknown;

    PFNGLGENQUERIESPROC glGenQueries{ nullptr };
    PFNGLDELETEQUERIESPROC glDeleteQueries{ nullptr };
    PFNGLISQUERYPROC glIsQuery{ nullptr };
    PFNGLBEGINQUERYPROC glBeginQuery{ nullptr };
    PFNGLENDQUERYPROC glEndQuery{ nullptr };
    PFNGLGETQUERYIVPROC glGetQueryiv{ nullptr };
    PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv{ nullptr };
    PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv{ nullptr };
    PFNGLBINDBUFFERPROC glBindBuffer{ nullptr };
    PFNGLDELETEBUFFERSPROC glDeleteBuffers{ nullptr };
    PFNGLGENBUFFERSPROC glGenBuffers{ nullptr };
    PFNGLISBUFFERPROC glIsBuffer{ nullptr };
    PFNGLBUFFERDATAPROC glBufferData{ nullptr };
    PFNGLBUFFERSUBDATAPROC glBufferSubData{ nullptr };
    PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData{ nullptr };
    PFNGLMAPBUFFERPROC glMapBuffer{ nullptr };
    PFNGLUNMAPBUFFERPROC glUnmapBuffer{ nullptr };
    PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv{ nullptr };
    PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL15() noexcept
{
    return existsOpenGL15;
}

void System::InitOpenGL15() noexcept
{
    if (System::OpenGLSystemVersion::Version15 <= System::GetOpenGLVersion())
    {
        existsOpenGL15 = ExistsOpenGLExtensions::Exists;

        // GL_ARB_occlusion_query

        SYSTEM_GET_FUNCTION(glGenQueries);
        SYSTEM_GET_FUNCTION(glDeleteQueries);
        SYSTEM_GET_FUNCTION(glIsQuery);
        SYSTEM_GET_FUNCTION(glBeginQuery);
        SYSTEM_GET_FUNCTION(glEndQuery);
        SYSTEM_GET_FUNCTION(glGetQueryiv);
        SYSTEM_GET_FUNCTION(glGetQueryObjectiv);
        SYSTEM_GET_FUNCTION(glGetQueryObjectuiv);

        // GL_ARB_vertex_buffer_object

        SYSTEM_GET_FUNCTION(glBindBuffer);
        SYSTEM_GET_FUNCTION(glDeleteBuffers);
        SYSTEM_GET_FUNCTION(glGenBuffers);
        SYSTEM_GET_FUNCTION(glIsBuffer);
        SYSTEM_GET_FUNCTION(glBufferData);
        SYSTEM_GET_FUNCTION(glBufferSubData);
        SYSTEM_GET_FUNCTION(glGetBufferSubData);
        SYSTEM_GET_FUNCTION(glMapBuffer);
        SYSTEM_GET_FUNCTION(glUnmapBuffer);
        SYSTEM_GET_FUNCTION(glGetBufferParameteriv);
        SYSTEM_GET_FUNCTION(glGetBufferPointerv);
    }
    else
    {
        existsOpenGL15 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLGenQueries(GLsizei n, GLuint* ids) noexcept
{
    SYSTEM_BODY_2(glGenQueries, n, ids);
}

void System::GLDeleteQueries(GLsizei n, const GLuint* ids) noexcept
{
    SYSTEM_BODY_2(glDeleteQueries, n, ids);
}

GLboolean System::GLIsQuery(GLuint id) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsQuery, id, GL_FALSE);
}

void System::GLBeginQuery(GLenum target, GLuint id) noexcept
{
    SYSTEM_BODY_2(glBeginQuery, target, id);
}

void System::GLEndQuery(GLenum target) noexcept
{
    SYSTEM_BODY_1(glEndQuery, target);
}

void System::GLGetQueryiv(GLenum target, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetQueryiv, target, pname, params);
}

void System::GLGetQueryObjectiv(GLuint id, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetQueryObjectiv, id, pname, params);
}

void System::GLGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetQueryObjectuiv, id, pname, params);
}

void System::GLBindBuffer(GLenum target, GLuint buffer) noexcept
{
    SYSTEM_BODY_2(glBindBuffer, target, buffer);
}

void System::GLDeleteBuffers(GLsizei n, const GLuint* buffers) noexcept
{
    SYSTEM_BODY_2(glDeleteBuffers, n, buffers);
}

void System::GLGenBuffers(GLsizei n, GLuint* buffers) noexcept
{
    SYSTEM_BODY_2(glGenBuffers, n, buffers);
}

GLboolean System::GLIsBuffer(GLuint buffer) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsBuffer, buffer, GL_FALSE);
}

void System::GLBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) noexcept
{
    SYSTEM_BODY_4(glBufferData, target, size, data, usage);
}

void System::GLBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) noexcept
{
    SYSTEM_BODY_4(glBufferSubData, target, offset, size, data);
}

void System::GLGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void* data) noexcept
{
    SYSTEM_BODY_4(glGetBufferSubData, target, offset, size, data);
}

void* System::GLMapBuffer(GLenum target, GLenum access) noexcept
{
    SYSTEM_BODY_2_RESULT(glMapBuffer, target, access, nullptr);
}

GLboolean System::GLUnmapBuffer(GLenum target) noexcept
{
    SYSTEM_BODY_1_RESULT(glUnmapBuffer, target, GL_FALSE);
}

void System::GLGetBufferParameteriv(GLenum target, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetBufferParameteriv, target, pname, params);
}

void System::GLGetBufferPointerv(GLenum target, GLenum pname, void** params) noexcept
{
    SYSTEM_BODY_3(glGetBufferPointerv, target, pname, params);
}
