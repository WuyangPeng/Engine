// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:44)

#include "System/SystemExport.h"

#include "GL30Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL30ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 3.0

namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL30{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL30() noexcept
{
	return g_ExistsOpenGL30;
}

System::PgglColorMaski System::gglColorMaski{ nullptr };
System::PgglGetBooleani_v System::gglGetBooleani_v{ nullptr };
System::PgglGetIntegeri_v System::gglGetIntegeri_v{ nullptr };
System::PgglEnablei System::gglEnablei{ nullptr };
System::PgglDisablei System::gglDisablei{ nullptr };
System::PgglIsEnabledi System::gglIsEnabledi{ nullptr };
System::PgglBeginTransformFeedback System::gglBeginTransformFeedback{ nullptr };
System::PgglEndTransformFeedback System::gglEndTransformFeedback{ nullptr };
System::PgglBindBufferRange System::gglBindBufferRange{ nullptr };
System::PgglBindBufferBase System::gglBindBufferBase{ nullptr };
System::PgglTransformFeedbackVaryings System::gglTransformFeedbackVaryings{ nullptr };
System::PgglGetTransformFeedbackVarying System::gglGetTransformFeedbackVarying{ nullptr };
System::PgglClampColor System::gglClampColor{ nullptr };
System::PgglBeginConditionalRender System::gglBeginConditionalRender{ nullptr };
System::PgglEndConditionalRender System::gglEndConditionalRender{ nullptr };
System::PgglVertexAttribIPointer System::gglVertexAttribIPointer{ nullptr };
System::PgglGetVertexAttribIiv System::gglGetVertexAttribIiv{ nullptr };
System::PgglGetVertexAttribIuiv System::gglGetVertexAttribIuiv{ nullptr };
System::PgglVertexAttribI1i System::gglVertexAttribI1i{ nullptr };
System::PgglVertexAttribI2i System::gglVertexAttribI2i{ nullptr };
System::PgglVertexAttribI3i System::gglVertexAttribI3i{ nullptr };
System::PgglVertexAttribI4i System::gglVertexAttribI4i{ nullptr };
System::PgglVertexAttribI1ui System::gglVertexAttribI1ui{ nullptr };
System::PgglVertexAttribI2ui System::gglVertexAttribI2ui{ nullptr };
System::PgglVertexAttribI3ui System::gglVertexAttribI3ui{ nullptr };
System::PgglVertexAttribI4ui System::gglVertexAttribI4ui{ nullptr };
System::PgglVertexAttribI1iv System::gglVertexAttribI1iv{ nullptr };
System::PgglVertexAttribI2iv System::gglVertexAttribI2iv{ nullptr };
System::PgglVertexAttribI3iv System::gglVertexAttribI3iv{ nullptr };
System::PgglVertexAttribI4iv System::gglVertexAttribI4iv{ nullptr };
System::PgglVertexAttribI1uiv System::gglVertexAttribI1uiv{ nullptr };
System::PgglVertexAttribI2uiv System::gglVertexAttribI2uiv{ nullptr };
System::PgglVertexAttribI3uiv System::gglVertexAttribI3uiv{ nullptr };
System::PgglVertexAttribI4uiv System::gglVertexAttribI4uiv{ nullptr };
System::PgglVertexAttribI4bv System::gglVertexAttribI4bv{ nullptr };
System::PgglVertexAttribI4sv System::gglVertexAttribI4sv{ nullptr };
System::PgglVertexAttribI4ubv System::gglVertexAttribI4ubv{ nullptr };
System::PgglVertexAttribI4usv System::gglVertexAttribI4usv{ nullptr };
System::PgglGetUniformuiv System::gglGetUniformuiv{ nullptr };
System::PgglBindFragDataLocation System::gglBindFragDataLocation{ nullptr };
System::PgglGetFragDataLocation System::gglGetFragDataLocation{ nullptr };
System::PgglUniform1ui System::gglUniform1ui{ nullptr };
System::PgglUniform2ui System::gglUniform2ui{ nullptr };
System::PgglUniform3ui System::gglUniform3ui{ nullptr };
System::PgglUniform4ui System::gglUniform4ui{ nullptr };
System::PgglUniform1uiv System::gglUniform1uiv{ nullptr };
System::PgglUniform2uiv System::gglUniform2uiv{ nullptr };
System::PgglUniform3uiv System::gglUniform3uiv{ nullptr };
System::PgglUniform4uiv System::gglUniform4uiv{ nullptr };
System::PgglTexParameterIiv System::gglTexParameterIiv{ nullptr };
System::PgglTexParameterIuiv System::gglTexParameterIuiv{ nullptr };
System::PgglGetTexParameterIiv System::gglGetTexParameterIiv{ nullptr };
System::PgglGetTexParameterIuiv System::gglGetTexParameterIuiv{ nullptr };
System::PgglClearBufferiv System::gglClearBufferiv{ nullptr };
System::PgglClearBufferuiv System::gglClearBufferuiv{ nullptr };
System::PgglClearBufferfv System::gglClearBufferfv{ nullptr };
System::PgglClearBufferfi System::gglClearBufferfi{ nullptr };
System::PgglGetStringi System::gglGetStringi{ nullptr };

void System
	::GlColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept
{
	SYSTEM_BODY_5(gglColorMaski, index, r, g, b, a);
}

void System
	::GlGetBooleani_v(GLenum target, GLuint index, GLboolean* data) noexcept
{
	SYSTEM_BODY_3(gglGetBooleani_v, target, index, data);
}

void System
	::GlGetIntegeri_v(GLenum target, GLuint index, GLint* data) noexcept
{
	SYSTEM_BODY_3(gglGetIntegeri_v, target, index, data);
}

void System
	::GlEnablei(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEnablei, target, index);
}

void System
	::GlDisablei(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglDisablei, target, index);
}

GLboolean System
	::GlIsEnabledi(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2_RESULT(gglIsEnabledi, target, index, GLboolean, GL_FALSE);
}

void System
	::GlBeginTransformFeedback(GLenum primitiveMode) noexcept
{
	SYSTEM_BODY_1(gglBeginTransformFeedback, primitiveMode);
}

void System
	::GlEndTransformFeedback(void) noexcept
{
	SYSTEM_BODY_0(gglEndTransformFeedback);
}

void System
	::GlBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglBindBufferRange, target, index, buffer, offset, size);
}

void System
	::GlBindBufferBase(GLenum target, GLuint index, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglBindBufferBase, target, index, buffer);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode) noexcept
{
	SYSTEM_BODY_4(gglTransformFeedbackVaryings, program, count, varyings, bufferMode);
}
#include STSTEM_WARNING_POP

void System
	::GlGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) noexcept
{
	SYSTEM_BODY_7(gglGetTransformFeedbackVarying, program, index, bufSize, length, size, type, name);
}

void System
	::GlClampColor(GLenum target, GLenum clamp) noexcept
{
	SYSTEM_BODY_2(gglClampColor, target, clamp);
}

void System
	::GlBeginConditionalRender(GLuint id, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglBeginConditionalRender, id, mode);
}

void System
	::GlEndConditionalRender(void) noexcept
{
	SYSTEM_BODY_0(gglEndConditionalRender);
}

void System
	::GlVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribIPointer, index, size, type, stride, pointer);
}

void System
	::GlGetVertexAttribIiv(GLuint index, GLenum name, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribIiv, index, name, params);
}

void System
	::GlGetVertexAttribIuiv(GLuint index, GLenum name, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribIuiv, index, name, params);
}

void System
	::GlVertexAttribI1i(GLuint index, GLint x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1i, index, x);
}

void System
	::GlVertexAttribI2i(GLuint index, GLint x, GLint y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttribI2i, index, x, y);
}

void System
	::GlVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribI3i, index, x, y, z);
}

void System
	::GlVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribI4i, index, x, y, z, w);
}

void System
	::GlVertexAttribI1ui(GLuint index, GLuint x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1ui, index, x);
}

void System
	::GlVertexAttribI2ui(GLuint index, GLuint x, GLuint y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttribI2ui, index, x, y);
}

void System
	::GlVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribI3ui, index, x, y, z);
}

void System
	::GlVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribI4ui, index, x, y, z, w);
}

void System
	::GlVertexAttribI1iv(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1iv, index, v);
}

void System
	::GlVertexAttribI2iv(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI2iv, index, v);
}

void System
	::GlVertexAttribI3iv(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI3iv, index, v);
}

void System
	::GlVertexAttribI4iv(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4iv, index, v);
}

void System
	::GlVertexAttribI1uiv(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1uiv, index, v);
}

void System
	::GlVertexAttribI2uiv(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI2uiv, index, v);
}

void System
	::GlVertexAttribI3uiv(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI3uiv, index, v);
}

void System
	::GlVertexAttribI4uiv(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4uiv, index, v);
}

void System
	::GlVertexAttribI4bv(GLuint index, const GLbyte* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4bv, index, v);
}

void System
	::GlVertexAttribI4sv(GLuint index, const GLshort* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4sv, index, v);
}

void System
	::GlVertexAttribI4ubv(GLuint index, const GLubyte* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4ubv, index, v);
}

void System
	::GlVertexAttribI4usv(GLuint index, const GLushort* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4usv, index, v);
}

void System
	::GlGetUniformuiv(GLuint program, GLint location, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetUniformuiv, program, location, params);
}

void System
	::GlBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) noexcept
{
	SYSTEM_BODY_3(gglBindFragDataLocation, program, color, name);
}

GLint System
	::GlGetFragDataLocation(GLuint program, const GLchar* name) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetFragDataLocation, program, name, GLint, -1);
}

void System
	::GlUniform1ui(GLint location, GLuint v0) noexcept
{
	SYSTEM_BODY_2(gglUniform1ui, location, v0);
}

void System
	::GlUniform2ui(GLint location, GLuint v0, GLuint v1) noexcept
{
	SYSTEM_BODY_3(gglUniform2ui, location, v0, v1);
}

void System
	::GlUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept
{
	SYSTEM_BODY_4(gglUniform3ui, location, v0, v1, v2);
}

void System
	::GlUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept
{
	SYSTEM_BODY_5(gglUniform4ui, location, v0, v1, v2, v3);
}

void System
	::GlUniform1uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform1uiv, location, count, value);
}

void System
	::GlUniform2uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform2uiv, location, count, value);
}

void System
	::GlUniform3uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform3uiv, location, count, value);
}

void System
	::GlUniform4uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform3uiv, location, count, value);
}

void System
	::GlTexParameterIiv(GLenum target, GLenum name, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglTexParameterIiv, target, name, params);
}

void System
	::GlTexParameterIuiv(GLenum target, GLenum name, const GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglTexParameterIuiv, target, name, params);
}

void System
	::GlGetTexParameterIiv(GLenum target, GLenum name, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTexParameterIiv, target, name, params);
}

void System
	::GlGetTexParameterIuiv(GLenum target, GLenum name, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTexParameterIuiv, target, name, params);
}

void System
	::GlClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint* value) noexcept
{
	SYSTEM_BODY_3(gglClearBufferiv, buffer, drawbuffer, value);
}

void System
	::GlClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglClearBufferuiv, buffer, drawbuffer, value);
}

void System
	::GlClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept
{
	SYSTEM_BODY_3(gglClearBufferfv, buffer, drawbuffer, value);
}

void System
	::GlClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) noexcept
{
	SYSTEM_BODY_4(gglClearBufferfi, buffer, drawbuffer, depth, stencil);
}

const GLubyte* System
	::GlGetStringi(GLenum name, GLuint index) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetStringi, name, index, const GLubyte*, nullptr);
}

void System
	::InitOpenGL30() noexcept
{
	if (System::OpenGLSystemVersion::Version30 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL30 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglColorMaski);
		SYSTEM_GET_FUNCTION(gglGetBooleani_v);
		SYSTEM_GET_FUNCTION(gglGetIntegeri_v);
		SYSTEM_GET_FUNCTION(gglEnablei);
		SYSTEM_GET_FUNCTION(gglDisablei);
		SYSTEM_GET_FUNCTION(gglIsEnabledi);
		SYSTEM_GET_FUNCTION(gglBeginTransformFeedback);
		SYSTEM_GET_FUNCTION(gglEndTransformFeedback);
		SYSTEM_GET_FUNCTION(gglBindBufferRange);
		SYSTEM_GET_FUNCTION(gglBindBufferBase);
		SYSTEM_GET_FUNCTION(gglTransformFeedbackVaryings);
		SYSTEM_GET_FUNCTION(gglGetTransformFeedbackVarying);
		SYSTEM_GET_FUNCTION(gglClampColor);
		SYSTEM_GET_FUNCTION(gglBeginConditionalRender);
		SYSTEM_GET_FUNCTION(gglEndConditionalRender);
		SYSTEM_GET_FUNCTION(gglVertexAttribIPointer);
		SYSTEM_GET_FUNCTION(gglGetVertexAttribIiv);
		SYSTEM_GET_FUNCTION(gglGetVertexAttribIuiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1i);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2i);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3i);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4i);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1iv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2iv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3iv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4iv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4bv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4sv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4ubv);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4usv);
		SYSTEM_GET_FUNCTION(gglGetUniformuiv);
		SYSTEM_GET_FUNCTION(gglBindFragDataLocation);
		SYSTEM_GET_FUNCTION(gglGetFragDataLocation);
		SYSTEM_GET_FUNCTION(gglUniform1ui);
		SYSTEM_GET_FUNCTION(gglUniform2ui);
		SYSTEM_GET_FUNCTION(gglUniform3ui);
		SYSTEM_GET_FUNCTION(gglUniform4ui);
		SYSTEM_GET_FUNCTION(gglUniform1uiv);
		SYSTEM_GET_FUNCTION(gglUniform2uiv);
		SYSTEM_GET_FUNCTION(gglUniform3uiv);
		SYSTEM_GET_FUNCTION(gglUniform4uiv);
		SYSTEM_GET_FUNCTION(gglTexParameterIiv);
		SYSTEM_GET_FUNCTION(gglTexParameterIuiv);
		SYSTEM_GET_FUNCTION(gglGetTexParameterIiv);
		SYSTEM_GET_FUNCTION(gglGetTexParameterIuiv);
		SYSTEM_GET_FUNCTION(gglClearBufferiv);
		SYSTEM_GET_FUNCTION(gglClearBufferuiv);
		SYSTEM_GET_FUNCTION(gglClearBufferfv);
		SYSTEM_GET_FUNCTION(gglClearBufferfi);
		SYSTEM_GET_FUNCTION(gglGetStringi);
	}
	else
	{
		g_ExistsOpenGL30 = ExistsOpenGLExtensions::NotExist;
	}
}
