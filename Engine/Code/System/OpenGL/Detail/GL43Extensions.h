/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 22:20)

#ifndef SYSTEM_OPENGL_GL_43_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_43_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 4.3
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL43() noexcept;

    void InitOpenGL43() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLClearBufferData(GLenum target, GLenum internalFormat, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferSubData(GLenum target, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDispatchCompute(GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDispatchComputeIndirect(GLintptr indirect) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferParameterI(GLenum target, GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFrameBufferParameterIv(GLenum target, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInternalFormatI64V(GLenum target, GLenum internalFormat, GLenum pName, GLsizei count, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateTexSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateTexImage(GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateBufferData(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateFrameBuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateSubFrameBuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawCount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramInterfaceIv(GLuint program, GLenum programInterface, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramResourceIv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexBufferRange(GLenum target, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage2DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage3DMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureView(GLuint texture, GLenum target, GLuint origTexture, GLenum internalFormat, GLuint minLevel, GLuint numLevels, GLuint minLayer, GLuint numLayers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindVertexBuffer(GLuint bindingIndex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribFormat(GLuint attribIndex, GLint size, GLenum type, GLboolean normalized, GLuint relativeOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribIFormat(GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribLFormat(GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribBinding(GLuint attribIndex, GLuint bindingIndex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexBindingDivisor(GLuint bindingIndex, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDebugMessageCallback(GLDEBUGPROC callback, const void* userParam) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar* message) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLPopDebugGroup() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLObjectPtrLabel(const void* ptr, GLsizei length, const GLchar* label) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetObjectPtrLabel(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_43_EXTENSIONS_H
