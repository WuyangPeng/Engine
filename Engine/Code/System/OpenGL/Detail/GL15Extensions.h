// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:32)

#ifndef SYSTEM_OPENGL_GL_15_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_15_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL15ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL15ExtensionsMacro.h"

namespace System
{
	// OpenGL 1.5
	enum class ExistsOpenGLExtensions;

	extern PgglGenQueries gglGenQueries;
	extern PgglDeleteQueries gglDeleteQueries;
	extern PgglIsQuery gglIsQuery;
	extern PgglBeginQuery gglBeginQuery;
	extern PgglEndQuery gglEndQuery;
	extern PgglGetQueryiv gglGetQueryiv;
	extern PgglGetQueryObjectiv gglGetQueryObjectiv;
	extern PgglGetQueryObjectuiv gglGetQueryObjectuiv;
	extern PgglBindBuffer gglBindBuffer;
	extern PgglDeleteBuffers gglDeleteBuffers;
	extern PgglGenBuffers gglGenBuffers;
	extern PgglIsBuffer gglIsBuffer;
	extern PgglBufferData gglBufferData;
	extern PgglBufferSubData gglBufferSubData;
	extern PgglGetBufferSubData gglGetBufferSubData;
	extern PgglMapBuffer gglMapBuffer;
	extern PgglUnmapBuffer gglUnmapBuffer;
	extern PgglGetBufferParameteriv gglGetBufferParameteriv;
	extern PgglGetBufferPointerv gglGetBufferPointerv;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL15() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlGenQueries(GLsizei numQueries, GLuint* id) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlDeleteQueries(GLsizei numQueries, const GLuint* id) noexcept;
	SYSTEM_HIDDEN_DECLARE GLboolean GlIsQuery(GLuint id) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBeginQuery(GLenum target, GLuint id) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlEndQuery(GLenum target) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetQueryiv(GLenum target, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetQueryObjectiv(GLuint id, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetQueryObjectuiv(GLuint id, GLenum name, GLuint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBindBuffer(GLenum target, GLuint buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlDeleteBuffers(GLsizei numBuffers, const GLuint* buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGenBuffers(GLsizei numBuffers, GLuint* buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE GLboolean GlIsBuffer(GLuint buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data) noexcept;
	SYSTEM_HIDDEN_DECLARE GLvoid* GlMapBuffer(GLenum target, GLenum access) noexcept;
	SYSTEM_HIDDEN_DECLARE GLboolean GlUnmapBuffer(GLenum target) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetBufferParameteriv(GLenum target, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetBufferPointerv(GLenum target, GLenum name, GLvoid** param) noexcept;

	void InitOpenGL15() noexcept;
}

#endif // SYSTEM_OPENGL_GL_15_EXTENSIONS_H
