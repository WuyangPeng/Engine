/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 17:38)

#ifndef SYSTEM_OPENGL_GL_30_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_30_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    /// OpenGL 3.0
    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL30() noexcept;

    void InitOpenGL30() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLColorMaskI(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBooleanIv(GLenum target, GLuint index, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetIntegerIv(GLenum target, GLuint index, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEnableI(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDisableI(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsEnabledI(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBeginTransformFeedback(GLenum primitiveMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEndTransformFeedback() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindBufferBase(GLenum target, GLuint index, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClampColor(GLenum target, GLenum clamp) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBeginConditionalRender(GLuint id, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEndConditionalRender() noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribIiv(GLuint index, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribIUiv(GLuint index, GLenum pName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1I(GLuint index, GLint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2I(GLuint index, GLint x, GLint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3I(GLuint index, GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4I(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1Ui(GLuint index, GLuint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2Ui(GLuint index, GLuint x, GLuint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3Ui(GLuint index, GLuint x, GLuint y, GLuint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1Iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2Iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3Iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1Uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2Uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3Uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Bv(GLuint index, const GLbyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Ubv(GLuint index, const GLubyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4Usv(GLuint index, const GLushort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformUiv(GLuint program, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetFragDataLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1Ui(GLint location, GLuint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2Ui(GLint location, GLuint v0, GLuint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3Ui(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4Ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1Uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2Uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3Uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4Uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterIiv(GLenum target, GLenum pName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterIUiv(GLenum target, GLenum pName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterIiv(GLenum target, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterIUiv(GLenum target, GLenum pName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferIv(GLenum buffer, GLint drawBuffer, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferUiv(GLenum buffer, GLint drawBuffer, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferFv(GLenum buffer, GLint drawBuffer, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferFi(GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const GLubyte* GLGetStringI(GLenum name, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsRenderBuffer(GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindRenderBuffer(GLenum target, GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteRenderBuffers(GLsizei n, const GLuint* renderBuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenRenderBuffers(GLsizei n, GLuint* renderBuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLRenderBufferStorage(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetRenderBufferParameterIv(GLenum target, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsFrameBuffer(GLuint frameBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindFrameBuffer(GLenum target, GLuint frameBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteFrameBuffers(GLsizei n, const GLuint* frameBuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenFrameBuffers(GLsizei n, GLuint* frameBuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLCheckFrameBufferStatus(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferTexture1D(GLenum target, GLenum attachment, GLenum texTarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferTexture2D(GLenum target, GLenum attachment, GLenum texTarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferTexture3D(GLenum target, GLenum attachment, GLenum texTarget, GLuint texture, GLint level, GLint zOffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferRenderBuffer(GLenum target, GLenum attachment, GLenum renderBufferTarget, GLuint renderBuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFrameBufferAttachmentParameterIv(GLenum target, GLenum attachment, GLenum pName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenerateMipmap(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlitFrameBuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLRenderBufferStorageMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFrameBufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindVertexArray(GLuint array) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteVertexArrays(GLsizei n, const GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenVertexArrays(GLsizei n, GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsVertexArray(GLuint array) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_30_EXTENSIONS_H
