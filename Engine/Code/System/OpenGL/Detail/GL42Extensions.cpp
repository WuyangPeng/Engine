///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:44)

#include "System/SystemExport.h"

#include "GL42Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.2
namespace System
{
    auto existsOpenGL42 = ExistsOpenGLExtensions::Unknown;

    PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance{ nullptr };
    PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance{ nullptr };
    PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance{ nullptr };
    PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ{ nullptr };
    PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv{ nullptr };
    PFNGLBINDIMAGETEXTUREPROC glBindImageTexture{ nullptr };
    PFNGLMEMORYBARRIERPROC glMemoryBarrier{ nullptr };
    PFNGLTEXSTORAGE1DPROC glTexStorage1D{ nullptr };
    PFNGLTEXSTORAGE2DPROC glTexStorage2D{ nullptr };
    PFNGLTEXSTORAGE3DPROC glTexStorage3D{ nullptr };
    PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced{ nullptr };
    PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL42() noexcept
{
    return existsOpenGL42;
}

void System::InitOpenGL42() noexcept
{
    if (System::OpenGLSystemVersion::Version42 <= System::GetOpenGLVersion())
    {
        existsOpenGL42 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glDrawArraysInstancedBaseInstance);
        SYSTEM_GET_FUNCTION(glDrawElementsInstancedBaseInstance);
        SYSTEM_GET_FUNCTION(glDrawElementsInstancedBaseVertexBaseInstance);
        SYSTEM_GET_FUNCTION(glGetInternalformativ);
        SYSTEM_GET_FUNCTION(glGetActiveAtomicCounterBufferiv);
        SYSTEM_GET_FUNCTION(glBindImageTexture);
        SYSTEM_GET_FUNCTION(glMemoryBarrier);
        SYSTEM_GET_FUNCTION(glTexStorage1D);
        SYSTEM_GET_FUNCTION(glTexStorage2D);
        SYSTEM_GET_FUNCTION(glTexStorage3D);
        SYSTEM_GET_FUNCTION(glDrawTransformFeedbackInstanced);
        SYSTEM_GET_FUNCTION(glDrawTransformFeedbackStreamInstanced);
    }
    else
    {
        existsOpenGL42 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) noexcept
{
    SYSTEM_BODY_5(glDrawArraysInstancedBaseInstance, mode, first, count, instancecount, baseinstance);
}

void System::GLDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance) noexcept
{
    SYSTEM_BODY_6(glDrawElementsInstancedBaseInstance, mode, count, type, indices, instancecount, baseinstance);
}

void System::GLDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) noexcept
{
    SYSTEM_BODY_7(glDrawElementsInstancedBaseVertexBaseInstance, mode, count, type, indices, instancecount, basevertex, baseinstance);
}

void System::GLGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params) noexcept
{
    SYSTEM_BODY_5(glGetInternalformativ, target, internalformat, pname, count, params);
}

void System::GLGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetActiveAtomicCounterBufferiv, program, bufferIndex, pname, params);
}

void System::GLBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) noexcept
{
    SYSTEM_BODY_7(glBindImageTexture, unit, texture, level, layered, layer, access, format);
}

void System::GLMemoryBarrier(GLbitfield barriers) noexcept
{
    SYSTEM_BODY_1(glMemoryBarrier, barriers);
}

void System::GLTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) noexcept
{
    SYSTEM_BODY_4(glTexStorage1D, target, levels, internalformat, width);
}

void System::GLTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glTexStorage2D, target, levels, internalformat, width, height);
}

void System::GLTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
    SYSTEM_BODY_6(glTexStorage3D, target, levels, internalformat, width, height, depth);
}

void System::GLDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) noexcept
{
    SYSTEM_BODY_3(glDrawTransformFeedbackInstanced, mode, id, instancecount);
}

void System::GLDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) noexcept
{
    SYSTEM_BODY_4(glDrawTransformFeedbackStreamInstanced, mode, id, stream, instancecount);
}
