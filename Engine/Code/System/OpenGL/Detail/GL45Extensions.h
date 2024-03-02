/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 22:37)

#ifndef SYSTEM_OPENGL_GL_45_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_45_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 4.5

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL45() noexcept;

    void InitOpenGL45() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLClipControl(GLenum origin, GLenum depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateTransformFeedbacks(GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbackIv(GLuint xfb, GLenum pName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbackIv(GLuint xfb, GLenum pName, GLuint index, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbackI64V(GLuint xfb, GLenum pName, GLuint index, GLint64* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateBuffers(GLsizei n, GLuint* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedBufferData(GLuint buffer, GLenum internalFormat, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedBufferSubData(GLuint buffer, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapNamedBuffer(GLuint buffer, GLenum access) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLUnmapNamedBuffer(GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferParameterIv(GLuint buffer, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferParameterI64v(GLuint buffer, GLenum pName, GLint64* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferPointerV(GLuint buffer, GLenum pName, void** params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateFrameBuffers(GLsizei n, GLuint* frameBuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferRenderBuffer(GLuint frameBuffer, GLenum attachment, GLenum renderBufferTarget, GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferParameterI(GLuint frameBuffer, GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferTexture(GLuint frameBuffer, GLenum attachment, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferTextureLayer(GLuint frameBuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferDrawBuffer(GLuint frameBuffer, GLenum buf) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferDrawBuffers(GLuint frameBuffer, GLsizei n, const GLenum* buffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedFrameBufferReadBuffer(GLuint frameBuffer, GLenum src) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateNamedFrameBufferData(GLuint frameBuffer, GLsizei numAttachments, const GLenum* attachments) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLInvalidateNamedFrameBufferSubData(GLuint frameBuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFrameBufferIv(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFrameBufferUiv(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFrameBufferFv(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearNamedFrameBufferFi(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlitNamedFrameBuffer(GLuint readFrameBuffer, GLuint drawFrameBuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLCheckNamedFrameBufferStatus(GLuint frameBuffer, GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedFrameBufferParameterIv(GLuint frameBuffer, GLenum pName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedFrameBufferAttachmentParameterIv(GLuint frameBuffer, GLenum attachment, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateRenderBuffers(GLsizei n, GLuint* renderBuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedRenderBufferStorage(GLuint renderBuffer, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLNamedRenderBufferStorageMultiSample(GLuint renderBuffer, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNamedRenderBufferParameterIv(GLuint renderBuffer, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateTextures(GLenum target, GLsizei n, GLuint* textures) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureBuffer(GLuint texture, GLenum internalFormat, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureBufferRange(GLuint texture, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage2DMultiSample(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureStorage3DMultiSample(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureSubImage1D(GLuint texture, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureSubImage2D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureSubImage3D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTextureSubImage1D(GLuint texture, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTextureSubImage2D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCopyTextureSubImage3D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterF(GLuint texture, GLenum pName, GLfloat param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterFv(GLuint texture, GLenum pName, const GLfloat* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterI(GLuint texture, GLenum pName, GLint param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterIiv(GLuint texture, GLenum pName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterIUiv(GLuint texture, GLenum pName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureParameterIv(GLuint texture, GLenum pName, const GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenerateTextureMipmap(GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindTextureUnit(GLuint unit, GLuint texture) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureLevelParameterFv(GLuint texture, GLint level, GLenum pName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureLevelParameterIv(GLuint texture, GLint level, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterFv(GLuint texture, GLenum pName, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterIiv(GLuint texture, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterIUiv(GLuint texture, GLenum pName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureParameterIv(GLuint texture, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateVertexArrays(GLsizei n, GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDisableVertexArrayAttrib(GLuint vaObj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEnableVertexArrayAttrib(GLuint vaObj, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayElementBuffer(GLuint vaObj, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayVertexBuffer(GLuint vaObj, GLuint bindingIndex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayVertexBuffers(GLuint vaObj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribBinding(GLuint vaObj, GLuint attribIndex, GLuint bindingIndex) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribFormat(GLuint vaObj, GLuint attribIndex, GLint size, GLenum type, GLboolean normalized, GLuint relativeOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribIFormat(GLuint vaObj, GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayAttribLFormat(GLuint vaObj, GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexArrayBindingDivisor(GLuint vaObj, GLuint attribIndex, GLuint divisor) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexArrayIv(GLuint vaObj, GLenum pName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexArrayIndexedIv(GLuint vaObj, GLuint index, GLenum pName, GLint* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexArrayIndexed64Iv(GLuint vaObj, GLuint index, GLenum pName, GLint64* param) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateSamplers(GLsizei n, GLuint* samplers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateProgramPipelines(GLsizei n, GLuint* pipelines) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLCreateQueries(GLenum target, GLsizei n, GLuint* ids) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectI64V(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectIv(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectUi64V(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetQueryBufferObjectUiv(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLMemoryBarrierByRegion(GLbitfield barriers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTextureSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLGetGraphicsResetStatus() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNUniformDv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNUniformFv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNUniformIv(GLuint program, GLint location, GLsizei bufSize, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetNUniformUiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLReadNPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTextureBarrier() noexcept;
}

#endif  // SYSTEM_OPENGL_GL_45_EXTENSIONS_H
