/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:20)

#include "System/SystemExport.h"

#include "GL43Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.3
namespace System
{
    auto existsOpenGL43 = ExistsOpenGLExtensions::Unknown;

    PFNGLCLEARBUFFERDATAPROC glClearBufferData{ nullptr };
    PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData{ nullptr };
    PFNGLDISPATCHCOMPUTEPROC glDispatchCompute{ nullptr };
    PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect{ nullptr };
    PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData{ nullptr };
    PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri{ nullptr };
    PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv{ nullptr };
    PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v{ nullptr };
    PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage{ nullptr };
    PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage{ nullptr };
    PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData{ nullptr };
    PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData{ nullptr };
    PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer{ nullptr };
    PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer{ nullptr };
    PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect{ nullptr };
    PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect{ nullptr };
    PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv{ nullptr };
    PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex{ nullptr };
    PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName{ nullptr };
    PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv{ nullptr };
    PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation{ nullptr };
    PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex{ nullptr };
    PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding{ nullptr };
    PFNGLTEXBUFFERRANGEPROC glTexBufferRange{ nullptr };
    PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample{ nullptr };
    PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample{ nullptr };
    PFNGLTEXTUREVIEWPROC glTextureView{ nullptr };
    PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer{ nullptr };
    PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat{ nullptr };
    PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat{ nullptr };
    PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat{ nullptr };
    PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding{ nullptr };
    PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor{ nullptr };
    PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl{ nullptr };
    PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert{ nullptr };
    PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback{ nullptr };
    PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog{ nullptr };
    PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup{ nullptr };
    PFNGLPOPDEBUGGROUPPROC glPopDebugGroup{ nullptr };
    PFNGLOBJECTLABELPROC glObjectLabel{ nullptr };
    PFNGLGETOBJECTLABELPROC glGetObjectLabel{ nullptr };
    PFNGLOBJECTPTRLABELPROC glObjectPtrLabel{ nullptr };
    PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL43() noexcept
{
    return existsOpenGL43;
}

void System::InitOpenGL43() noexcept
{
    if (OpenGLSystemVersion::Version43 <= System::GetOpenGLVersion())
    {
        existsOpenGL43 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glClearBufferData);
        SYSTEM_GET_FUNCTION(glClearBufferSubData);
        SYSTEM_GET_FUNCTION(glDispatchCompute);
        SYSTEM_GET_FUNCTION(glDispatchComputeIndirect);
        SYSTEM_GET_FUNCTION(glCopyImageSubData);
        SYSTEM_GET_FUNCTION(glFramebufferParameteri);
        SYSTEM_GET_FUNCTION(glGetFramebufferParameteriv);
        SYSTEM_GET_FUNCTION(glGetInternalformati64v);
        SYSTEM_GET_FUNCTION(glInvalidateTexSubImage);
        SYSTEM_GET_FUNCTION(glInvalidateTexImage);
        SYSTEM_GET_FUNCTION(glInvalidateBufferSubData);
        SYSTEM_GET_FUNCTION(glInvalidateBufferData);
        SYSTEM_GET_FUNCTION(glInvalidateFramebuffer);
        SYSTEM_GET_FUNCTION(glInvalidateSubFramebuffer);
        SYSTEM_GET_FUNCTION(glMultiDrawArraysIndirect);
        SYSTEM_GET_FUNCTION(glMultiDrawElementsIndirect);
        SYSTEM_GET_FUNCTION(glGetProgramInterfaceiv);
        SYSTEM_GET_FUNCTION(glGetProgramResourceIndex);
        SYSTEM_GET_FUNCTION(glGetProgramResourceName);
        SYSTEM_GET_FUNCTION(glGetProgramResourceiv);
        SYSTEM_GET_FUNCTION(glGetProgramResourceLocation);
        SYSTEM_GET_FUNCTION(glGetProgramResourceLocationIndex);
        SYSTEM_GET_FUNCTION(glShaderStorageBlockBinding);
        SYSTEM_GET_FUNCTION(glTexBufferRange);
        SYSTEM_GET_FUNCTION(glTexStorage2DMultisample);
        SYSTEM_GET_FUNCTION(glTexStorage3DMultisample);
        SYSTEM_GET_FUNCTION(glTextureView);
        SYSTEM_GET_FUNCTION(glBindVertexBuffer);
        SYSTEM_GET_FUNCTION(glVertexAttribFormat);
        SYSTEM_GET_FUNCTION(glVertexAttribIFormat);
        SYSTEM_GET_FUNCTION(glVertexAttribLFormat);
        SYSTEM_GET_FUNCTION(glVertexAttribBinding);
        SYSTEM_GET_FUNCTION(glVertexBindingDivisor);
        SYSTEM_GET_FUNCTION(glDebugMessageControl);
        SYSTEM_GET_FUNCTION(glDebugMessageInsert);
        SYSTEM_GET_FUNCTION(glDebugMessageCallback);
        SYSTEM_GET_FUNCTION(glGetDebugMessageLog);
        SYSTEM_GET_FUNCTION(glPushDebugGroup);
        SYSTEM_GET_FUNCTION(glPopDebugGroup);
        SYSTEM_GET_FUNCTION(glObjectLabel);
        SYSTEM_GET_FUNCTION(glGetObjectLabel);
        SYSTEM_GET_FUNCTION(glObjectPtrLabel);
        SYSTEM_GET_FUNCTION(glGetObjectPtrLabel);
    }
    else
    {
        existsOpenGL43 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLClearBufferData(GLenum target, GLenum internalFormat, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_5(glClearBufferData, target, internalFormat, format, type, data);
}

void System::GLClearBufferSubData(GLenum target, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_7(glClearBufferSubData, target, internalFormat, offset, size, format, type, data);
}

void System::GLDispatchCompute(GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ) noexcept
{
    SYSTEM_BODY_3(glDispatchCompute, numGroupsX, numGroupsY, numGroupsZ);
}

void System::GLDispatchComputeIndirect(GLintptr indirect) noexcept
{
    SYSTEM_BODY_1(glDispatchComputeIndirect, indirect);
}

void System::GLCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) noexcept
{
    SYSTEM_BODY_15(glCopyImageSubData, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

void System::GLFrameBufferParameterI(GLenum target, GLenum pName, GLint param) noexcept
{
    SYSTEM_BODY_3(glFramebufferParameteri, target, pName, param);
}

void System::GLGetFrameBufferParameterIv(GLenum target, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetFramebufferParameteriv, target, pName, params);
}

void System::GLGetInternalFormatI64V(GLenum target, GLenum internalFormat, GLenum pName, GLsizei count, GLint64* params) noexcept
{
    SYSTEM_BODY_5(glGetInternalformati64v, target, internalFormat, pName, count, params);
}

void System::GLInvalidateTexSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
    SYSTEM_BODY_8(glInvalidateTexSubImage, texture, level, xOffset, yOffset, zOffset, width, height, depth);
}

void System::GLInvalidateTexImage(GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_2(glInvalidateTexImage, texture, level);
}

void System::GLInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept
{
    SYSTEM_BODY_3(glInvalidateBufferSubData, buffer, offset, length);
}

void System::GLInvalidateBufferData(GLuint buffer) noexcept
{
    SYSTEM_BODY_1(glInvalidateBufferData, buffer);
}

void System::GLInvalidateFrameBuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) noexcept
{
    SYSTEM_BODY_3(glInvalidateFramebuffer, target, numAttachments, attachments);
}

void System::GLInvalidateSubFrameBuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_7(glInvalidateSubFramebuffer, target, numAttachments, attachments, x, y, width, height);
}

void System::GLMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawCount, GLsizei stride) noexcept
{
    SYSTEM_BODY_4(glMultiDrawArraysIndirect, mode, indirect, drawCount, stride);
}

void System::GLMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei stride) noexcept
{
    SYSTEM_BODY_5(glMultiDrawElementsIndirect, mode, type, indirect, drawCount, stride);
}

void System::GLGetProgramInterfaceIv(GLuint program, GLenum programInterface, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetProgramInterfaceiv, program, programInterface, pName, params);
}

GLuint System::GLGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept
{
    SYSTEM_BODY_3_RESULT(glGetProgramResourceIndex, program, programInterface, name, 0u);
}

void System::GLGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept
{
    SYSTEM_BODY_6(glGetProgramResourceName, program, programInterface, index, bufSize, length, name);
}

void System::GLGetProgramResourceIv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params) noexcept
{
    SYSTEM_BODY_8(glGetProgramResourceiv, program, programInterface, index, propCount, props, count, length, params);
}

GLint System::GLGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) noexcept
{
    SYSTEM_BODY_3_RESULT(glGetProgramResourceLocation, program, programInterface, name, 0);
}

GLint System::GLGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept
{
    SYSTEM_BODY_3_RESULT(glGetProgramResourceLocationIndex, program, programInterface, name, 0);
}

void System::GLShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) noexcept
{
    SYSTEM_BODY_3(glShaderStorageBlockBinding, program, storageBlockIndex, storageBlockBinding);
}

void System::GLTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glTexBufferRange, target, internalFormat, buffer, offset, size);
}

void System::GLTexStorage2DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) noexcept
{
    SYSTEM_BODY_6(glTexStorage2DMultisample, target, samples, internalFormat, width, height, fixedSampleLocations);
}

void System::GLTexStorage3DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) noexcept
{
    SYSTEM_BODY_7(glTexStorage3DMultisample, target, samples, internalFormat, width, height, depth, fixedSampleLocations);
}

void System::GLTextureView(GLuint texture, GLenum target, GLuint origTexture, GLenum internalFormat, GLuint minLevel, GLuint numLevels, GLuint minLayer, GLuint numLayers) noexcept
{
    SYSTEM_BODY_8(glTextureView, texture, target, origTexture, internalFormat, minLevel, numLevels, minLayer, numLayers);
}

void System::GLBindVertexBuffer(GLuint bindingIndex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept
{
    SYSTEM_BODY_4(glBindVertexBuffer, bindingIndex, buffer, offset, stride);
}

void System::GLVertexAttribFormat(GLuint attribIndex, GLint size, GLenum type, GLboolean normalized, GLuint relativeOffset) noexcept
{
    SYSTEM_BODY_5(glVertexAttribFormat, attribIndex, size, type, normalized, relativeOffset);
}

void System::GLVertexAttribIFormat(GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept
{
    SYSTEM_BODY_4(glVertexAttribIFormat, attribIndex, size, type, relativeOffset);
}

void System::GLVertexAttribLFormat(GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept
{
    SYSTEM_BODY_4(glVertexAttribLFormat, attribIndex, size, type, relativeOffset);
}

void System::GLVertexAttribBinding(GLuint attribIndex, GLuint bindingIndex) noexcept
{
    SYSTEM_BODY_2(glVertexAttribBinding, attribIndex, bindingIndex);
}

void System::GLVertexBindingDivisor(GLuint bindingIndex, GLuint divisor) noexcept
{
    SYSTEM_BODY_2(glVertexBindingDivisor, bindingIndex, divisor);
}

void System::GLDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) noexcept
{
    SYSTEM_BODY_6(glDebugMessageControl, source, type, severity, count, ids, enabled);
}

void System::GLDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) noexcept
{
    SYSTEM_BODY_6(glDebugMessageInsert, source, type, id, severity, length, buf);
}

void System::GLDebugMessageCallback(GLDEBUGPROC callback, const void* userParam) noexcept
{
    SYSTEM_BODY_2(glDebugMessageCallback, callback, userParam);
}

GLuint System::GLGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) noexcept
{
    SYSTEM_BODY_8_RESULT(glGetDebugMessageLog, count, bufSize, sources, types, ids, severities, lengths, messageLog, 0u);
}

void System::GLPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message) noexcept
{
    SYSTEM_BODY_4(glPushDebugGroup, source, id, length, message);
}

void System::GLPopDebugGroup() noexcept
{
    SYSTEM_BODY_0(glPopDebugGroup);
}

void System::GLObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label) noexcept
{
    SYSTEM_BODY_4(glObjectLabel, identifier, name, length, label);
}

void System::GLGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label) noexcept
{
    SYSTEM_BODY_5(glGetObjectLabel, identifier, name, bufSize, length, label);
}

void System::GLObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label) noexcept
{
    SYSTEM_BODY_3(glObjectPtrLabel, ptr, length, label);
}

void System::GLGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label) noexcept
{
    SYSTEM_BODY_4(glGetObjectPtrLabel, ptr, bufSize, length, label);
}
