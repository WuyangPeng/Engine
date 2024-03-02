/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:20)

#include "System/SystemExport.h"

#include "GL32Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 3.2
namespace System
{
    auto existsOpenGL32 = ExistsOpenGLExtensions::Unknown;

    PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex{ nullptr };
    PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex{ nullptr };
    PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex{ nullptr };
    PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex{ nullptr };
    PFNGLPROVOKINGVERTEXPROC glProvokingVertex{ nullptr };
    PFNGLFENCESYNCPROC glFenceSync{ nullptr };
    PFNGLISSYNCPROC glIsSync{ nullptr };
    PFNGLDELETESYNCPROC glDeleteSync{ nullptr };
    PFNGLCLIENTWAITSYNCPROC glClientWaitSync{ nullptr };
    PFNGLWAITSYNCPROC glWaitSync{ nullptr };
    PFNGLGETINTEGER64VPROC glGetInteger64v{ nullptr };
    PFNGLGETSYNCIVPROC glGetSynciv{ nullptr };
    PFNGLGETINTEGER64I_VPROC glGetInteger64i_v{ nullptr };
    PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v{ nullptr };
    PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture{ nullptr };
    PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample{ nullptr };
    PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample{ nullptr };
    PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv{ nullptr };
    PFNGLSAMPLEMASKIPROC glSampleMaski{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL32() noexcept
{
    return existsOpenGL32;
}

void System::InitOpenGL32() noexcept
{
    if (OpenGLSystemVersion::Version32 <= System::GetOpenGLVersion())
    {
        existsOpenGL32 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glDrawElementsBaseVertex);
        SYSTEM_GET_FUNCTION(glDrawRangeElementsBaseVertex);
        SYSTEM_GET_FUNCTION(glDrawElementsInstancedBaseVertex);
        SYSTEM_GET_FUNCTION(glMultiDrawElementsBaseVertex);
        SYSTEM_GET_FUNCTION(glProvokingVertex);
        SYSTEM_GET_FUNCTION(glFenceSync);
        SYSTEM_GET_FUNCTION(glIsSync);
        SYSTEM_GET_FUNCTION(glDeleteSync);
        SYSTEM_GET_FUNCTION(glClientWaitSync);
        SYSTEM_GET_FUNCTION(glWaitSync);
        SYSTEM_GET_FUNCTION(glGetInteger64v);
        SYSTEM_GET_FUNCTION(glGetSynciv);
        SYSTEM_GET_FUNCTION(glGetInteger64i_v);
        SYSTEM_GET_FUNCTION(glGetBufferParameteri64v);
        SYSTEM_GET_FUNCTION(glFramebufferTexture);
        SYSTEM_GET_FUNCTION(glTexImage2DMultisample);
        SYSTEM_GET_FUNCTION(glTexImage3DMultisample);
        SYSTEM_GET_FUNCTION(glGetMultisamplefv);
        SYSTEM_GET_FUNCTION(glSampleMaski);
    }
    else
    {
        existsOpenGL32 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint baseVertex) noexcept
{
    SYSTEM_BODY_5(glDrawElementsBaseVertex, mode, count, type, indices, baseVertex);
}

void System::GLDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint baseVertex) noexcept
{
    SYSTEM_BODY_7(glDrawRangeElementsBaseVertex, mode, start, end, count, type, indices, baseVertex);
}

void System::GLDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instanceCount, GLint baseVertex) noexcept
{
    SYSTEM_BODY_6(glDrawElementsInstancedBaseVertex, mode, count, type, indices, instanceCount, baseVertex);
}

void System::GLMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawCount, const GLint* baseVertex) noexcept
{
    SYSTEM_BODY_6(glMultiDrawElementsBaseVertex, mode, count, type, indices, drawCount, baseVertex);
}

void System::GLProvokingVertex(GLenum mode) noexcept
{
    SYSTEM_BODY_1(glProvokingVertex, mode);
}

GLsync System::GLFenceSync(GLenum condition, GLbitfield flags) noexcept
{
    SYSTEM_BODY_2_RESULT(glFenceSync, condition, flags, nullptr);
}

GLboolean System::GLIsSync(GLsync sync) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsSync, sync, GL_FALSE);
}

void System::GLDeleteSync(GLsync sync) noexcept
{
    SYSTEM_BODY_1(glDeleteSync, sync);
}

GLenum System::GLClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) noexcept
{
    SYSTEM_BODY_3_RESULT(glClientWaitSync, sync, flags, timeout, GL_WAIT_FAILED);
}

void System::GLWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) noexcept
{
    SYSTEM_BODY_3(glWaitSync, sync, flags, timeout);
}

void System::GLGetInteger64V(GLenum pName, GLint64* data) noexcept
{
    SYSTEM_BODY_2(glGetInteger64v, pName, data);
}

void System::GLGetSyncIv(GLsync sync, GLenum pName, GLsizei count, GLsizei* length, GLint* values) noexcept
{
    SYSTEM_BODY_5(glGetSynciv, sync, pName, count, length, values);
}

void System::GLGetInteger64Iv(GLenum target, GLuint index, GLint64* data) noexcept
{
    SYSTEM_BODY_3(glGetInteger64i_v, target, index, data);
}

void System::GLGetBufferParameterI64V(GLenum target, GLenum pName, GLint64* params) noexcept
{
    SYSTEM_BODY_3(glGetBufferParameteri64v, target, pName, params);
}

void System::GLFrameBufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_4(glFramebufferTexture, target, attachment, texture, level);
}

void System::GLTexImage2DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) noexcept
{
    SYSTEM_BODY_6(glTexImage2DMultisample, target, samples, internalFormat, width, height, fixedSampleLocations);
}

void System::GLTexImage3DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) noexcept
{
    SYSTEM_BODY_7(glTexImage3DMultisample, target, samples, internalFormat, width, height, depth, fixedSampleLocations);
}

void System::GLGetMultiSampleFv(GLenum pName, GLuint index, GLfloat* val) noexcept
{
    SYSTEM_BODY_3(glGetMultisamplefv, pName, index, val);
}

void System::GLSampleMaskI(GLuint maskNumber, GLbitfield mask) noexcept
{
    SYSTEM_BODY_2(glSampleMaski, maskNumber, mask);
}
