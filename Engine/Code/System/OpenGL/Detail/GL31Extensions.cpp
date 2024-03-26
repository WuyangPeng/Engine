/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:07)

#include "System/SystemExport.h"

#include "GL31Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

/// OpenGL 3.1
namespace System
{
    auto existsOpenGL31 = ExistsOpenGLExtensions::Unknown;

    PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced{ nullptr };
    PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced{ nullptr };
    PFNGLTEXBUFFERPROC glTexBuffer{ nullptr };
    PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex{ nullptr };
    PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData{ nullptr };
    PFNGLGETUNIFORMINDICESPROC glGetUniformIndices{ nullptr };
    PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv{ nullptr };
    PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName{ nullptr };
    PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex{ nullptr };
    PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv{ nullptr };
    PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName{ nullptr };
    PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL31() noexcept
{
    return existsOpenGL31;
}

void System::InitOpenGL31() noexcept
{
    if (OpenGLSystemVersion::Version31 <= GetOpenGLVersion())
    {
        existsOpenGL31 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glDrawArraysInstanced);
        SYSTEM_GET_FUNCTION(glDrawElementsInstanced);
        SYSTEM_GET_FUNCTION(glTexBuffer);
        SYSTEM_GET_FUNCTION(glPrimitiveRestartIndex);
        SYSTEM_GET_FUNCTION(glCopyBufferSubData);
        SYSTEM_GET_FUNCTION(glGetUniformIndices);
        SYSTEM_GET_FUNCTION(glGetActiveUniformsiv);
        SYSTEM_GET_FUNCTION(glGetActiveUniformName);
        SYSTEM_GET_FUNCTION(glGetUniformBlockIndex);
        SYSTEM_GET_FUNCTION(glGetActiveUniformBlockiv);
        SYSTEM_GET_FUNCTION(glGetActiveUniformBlockName);
        SYSTEM_GET_FUNCTION(glUniformBlockBinding);
    }
    else
    {
        existsOpenGL31 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instanceCount) noexcept
{
    SYSTEM_BODY_4(glDrawArraysInstanced, mode, first, count, instanceCount);
}

void System::GLDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instanceCount) noexcept
{
    SYSTEM_BODY_5(glDrawElementsInstanced, mode, count, type, indices, instanceCount);
}

void System::GLTexBuffer(GLenum target, GLenum internalFormat, GLuint buffer) noexcept
{
    SYSTEM_BODY_3(glTexBuffer, target, internalFormat, buffer);
}

void System::GLPrimitiveRestartIndex(GLuint index) noexcept
{
    SYSTEM_BODY_1(glPrimitiveRestartIndex, index);
}

void System::GLCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glCopyBufferSubData, readTarget, writeTarget, readOffset, writeOffset, size);
}

void System::GLGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices) noexcept
{
    SYSTEM_BODY_4(glGetUniformIndices, program, uniformCount, uniformNames, uniformIndices);
}

void System::GLGetActiveUniformSiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_5(glGetActiveUniformsiv, program, uniformCount, uniformIndices, pName, params);
}

void System::GLGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) noexcept
{
    SYSTEM_BODY_5(glGetActiveUniformName, program, uniformIndex, bufSize, length, uniformName);
}

GLuint System::GLGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) noexcept
{
    SYSTEM_BODY_2_RESULT(glGetUniformBlockIndex, program, uniformBlockName, 0u);
}

void System::GLGetActiveUniformBlockIv(GLuint program, GLuint uniformBlockIndex, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetActiveUniformBlockiv, program, uniformBlockIndex, pName, params);
}

void System::GLGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) noexcept
{
    SYSTEM_BODY_5(glGetActiveUniformBlockName, program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void System::GLUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) noexcept
{
    SYSTEM_BODY_3(glUniformBlockBinding, program, uniformBlockIndex, uniformBlockBinding);
}
