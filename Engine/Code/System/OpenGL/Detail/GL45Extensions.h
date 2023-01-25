///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 18:48)

#ifndef SYSTEM_OPENGL_GL_45_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_45_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 4.5

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL45() noexcept;

    void InitOpenGL45() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLClipControl(GLenum origin, GLenum depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateTransformFeedbacks(GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateBuffers(GLsizei n, GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapNamedBuffer(GLuint buffer, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLUnmapNamedBuffer(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateFramebuffers(GLsizei n, GLuint* framebuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateTextures(GLenum target, GLsizei n, GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterf(GLuint texture, GLenum pname, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameteri(GLuint texture, GLenum pname, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameteriv(GLuint texture, GLenum pname, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenerateTextureMipmap(GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindTextureUnit(GLuint unit, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateVertexArrays(GLsizei n, GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDisableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEnableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateSamplers(GLsizei n, GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateProgramPipelines(GLsizei n, GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateQueries(GLenum target, GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMemoryBarrierByRegion(GLbitfield barriers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLGetGraphicsResetStatus() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureBarrier() noexcept;
}

#endif  // SYSTEM_OPENGL_GL_45_EXTENSIONS_H
