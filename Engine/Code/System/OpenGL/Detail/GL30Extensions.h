/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:06)

#ifndef SYSTEM_OPENGL_GL_30_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_30_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace System
{
    // OpenGL 3.0

    SYSTEM_HIDDEN_DECLARE NODISCARD ExistsOpenGLExtensions IsExistsOpenGL30() noexcept;

    void InitOpenGL30() noexcept;

    SYSTEM_HIDDEN_DECLARE void GLColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetBooleani_v(GLenum target, GLuint index, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetIntegeri_v(GLenum target, GLuint index, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLEnablei(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDisablei(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsEnabledi(GLenum target, GLuint index) noexcept;
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
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1i(GLuint index, GLint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2i(GLuint index, GLint x, GLint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1ui(GLuint index, GLuint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2ui(GLuint index, GLuint x, GLuint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI1uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI2uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI3uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4bv(GLuint index, const GLbyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4ubv(GLuint index, const GLubyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLVertexAttribI4usv(GLuint index, const GLushort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetUniformuiv(GLuint program, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLint GLGetFragDataLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1ui(GLint location, GLuint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2ui(GLint location, GLuint v0, GLuint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform1uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform2uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform3uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLUniform4uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterIiv(GLenum target, GLenum pname, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterIiv(GLenum target, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetTexParameterIuiv(GLenum target, GLenum pname, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR const GLubyte* GLGetStringi(GLenum name, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsRenderbuffer(GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindRenderbuffer(GLenum target, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsFramebuffer(GLuint framebuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindFramebuffer(GLenum target, GLuint framebuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenFramebuffers(GLsizei n, GLuint* framebuffers) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLenum GLCheckFramebufferStatus(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenerateMipmap(GLenum target) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept;
    SYSTEM_HIDDEN_DECLARE MAYBE_NULLPTR void* GLMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLBindVertexArray(GLuint array) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLDeleteVertexArrays(GLsizei n, const GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE void GLGenVertexArrays(GLsizei n, GLuint* arrays) noexcept;
    SYSTEM_HIDDEN_DECLARE NODISCARD GLboolean GLIsVertexArray(GLuint array) noexcept;
}

#endif  // SYSTEM_OPENGL_GL_30_EXTENSIONS_H
