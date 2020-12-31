//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 15:38)

#ifndef SYSTEM_OPENGL_GL_30_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_30_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/GL30ExtensionsMacro.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL30ExtensionsUsing.h"

namespace System
{
    // OpenGL 3.0

    extern PgglColorMaski gglColorMaski;
    extern PgglGetBooleani_v gglGetBooleani_v;
    extern PgglGetIntegeri_v gglGetIntegeri_v;
    extern PgglEnablei gglEnablei;
    extern PgglDisablei gglDisablei;
    extern PgglIsEnabledi gglIsEnabledi;
    extern PgglBeginTransformFeedback gglBeginTransformFeedback;
    extern PgglEndTransformFeedback gglEndTransformFeedback;
    extern PgglBindBufferRange gglBindBufferRange;
    extern PgglBindBufferBase gglBindBufferBase;
    extern PgglTransformFeedbackVaryings gglTransformFeedbackVaryings;
    extern PgglGetTransformFeedbackVarying gglGetTransformFeedbackVarying;
    extern PgglClampColor gglClampColor;
    extern PgglBeginConditionalRender gglBeginConditionalRender;
    extern PgglEndConditionalRender gglEndConditionalRender;
    extern PgglVertexAttribIPointer gglVertexAttribIPointer;
    extern PgglGetVertexAttribIiv gglGetVertexAttribIiv;
    extern PgglGetVertexAttribIuiv gglGetVertexAttribIuiv;
    extern PgglVertexAttribI1i gglVertexAttribI1i;
    extern PgglVertexAttribI2i gglVertexAttribI2i;
    extern PgglVertexAttribI3i gglVertexAttribI3i;
    extern PgglVertexAttribI4i gglVertexAttribI4i;
    extern PgglVertexAttribI1ui gglVertexAttribI1ui;
    extern PgglVertexAttribI2ui gglVertexAttribI2ui;
    extern PgglVertexAttribI3ui gglVertexAttribI3ui;
    extern PgglVertexAttribI4ui gglVertexAttribI4ui;
    extern PgglVertexAttribI1iv gglVertexAttribI1iv;
    extern PgglVertexAttribI2iv gglVertexAttribI2iv;
    extern PgglVertexAttribI3iv gglVertexAttribI3iv;
    extern PgglVertexAttribI4iv gglVertexAttribI4iv;
    extern PgglVertexAttribI1uiv gglVertexAttribI1uiv;
    extern PgglVertexAttribI2uiv gglVertexAttribI2uiv;
    extern PgglVertexAttribI3uiv gglVertexAttribI3uiv;
    extern PgglVertexAttribI4uiv gglVertexAttribI4uiv;
    extern PgglVertexAttribI4bv gglVertexAttribI4bv;
    extern PgglVertexAttribI4sv gglVertexAttribI4sv;
    extern PgglVertexAttribI4ubv gglVertexAttribI4ubv;
    extern PgglVertexAttribI4usv gglVertexAttribI4usv;
    extern PgglGetUniformuiv gglGetUniformuiv;
    extern PgglBindFragDataLocation gglBindFragDataLocation;
    extern PgglGetFragDataLocation gglGetFragDataLocation;
    extern PgglUniform1ui gglUniform1ui;
    extern PgglUniform2ui gglUniform2ui;
    extern PgglUniform3ui gglUniform3ui;
    extern PgglUniform4ui gglUniform4ui;
    extern PgglUniform1uiv gglUniform1uiv;
    extern PgglUniform2uiv gglUniform2uiv;
    extern PgglUniform3uiv gglUniform3uiv;
    extern PgglUniform4uiv gglUniform4uiv;
    extern PgglTexParameterIiv gglTexParameterIiv;
    extern PgglTexParameterIuiv gglTexParameterIuiv;
    extern PgglGetTexParameterIiv gglGetTexParameterIiv;
    extern PgglGetTexParameterIuiv gglGetTexParameterIuiv;
    extern PgglClearBufferiv gglClearBufferiv;
    extern PgglClearBufferuiv gglClearBufferuiv;
    extern PgglClearBufferfv gglClearBufferfv;
    extern PgglClearBufferfi gglClearBufferfi;
    extern PgglGetStringi gglGetStringi;

    SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL30() noexcept;

    SYSTEM_HIDDEN_DECLARE void GlColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetBooleani_v(GLenum target, GLuint index, GLboolean* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetIntegeri_v(GLenum target, GLuint index, GLint* data) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEnablei(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlDisablei(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE GLboolean GlIsEnabledi(GLenum target, GLuint index) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBeginTransformFeedback(GLenum primitiveMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndTransformFeedback() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindBufferBase(GLenum target, GLuint index, GLuint buffer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClampColor(GLenum target, GLenum clamp) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBeginConditionalRender(GLuint id, GLenum mode) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlEndConditionalRender() noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribIiv(GLuint index, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetVertexAttribIuiv(GLuint index, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1i(GLuint index, GLint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2i(GLuint index, GLint x, GLint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1ui(GLuint index, GLuint x) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2ui(GLuint index, GLuint x, GLuint y) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4iv(GLuint index, const GLint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI1uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI2uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI3uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4uiv(GLuint index, const GLuint* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4bv(GLuint index, const GLbyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4sv(GLuint index, const GLshort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4ubv(GLuint index, const GLubyte* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlVertexAttribI4usv(GLuint index, const GLushort* v) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetUniformuiv(GLuint program, GLint location, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE GLint GlGetFragDataLocation(GLuint program, const GLchar* name) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1ui(GLint location, GLuint v0) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2ui(GLint location, GLuint v0, GLuint v1) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform1uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform2uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform3uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlUniform4uiv(GLint location, GLsizei count, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexParameterIiv(GLenum target, GLenum parameterName, const GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlTexParameterIuiv(GLenum target, GLenum parameterName, const GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTexParameterIiv(GLenum target, GLenum parameterName, GLint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlGetTexParameterIuiv(GLenum target, GLenum parameterName, GLuint* params) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept;
    SYSTEM_HIDDEN_DECLARE void GlClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) noexcept;
    SYSTEM_HIDDEN_DECLARE const GLubyte* GlGetStringi(GLenum name, GLuint index) noexcept;

    void InitOpenGL30();
}

#endif  // SYSTEM_OPENGL_GL_30_EXTENSIONS_H
