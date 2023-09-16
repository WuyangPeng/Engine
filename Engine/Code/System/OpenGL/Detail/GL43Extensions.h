///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:19)

#ifndef SYSTEM_OPENGL_GL_43_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_43_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.3

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL43() noexcept;

    void InitOpenGL43() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDispatchComputeIndirect(GLintptr indirect) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferParameteri(GLenum target, GLenum pname, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateTexImage(GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateBufferData(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawArraysIndirect(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMultiDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLuint GLGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribBinding(GLuint attribindex, GLuint bindingindex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexBindingDivisor(GLuint bindingindex, GLuint divisor) noexcept;
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
