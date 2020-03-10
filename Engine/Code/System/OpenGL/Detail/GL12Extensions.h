// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:32)

#ifndef SYSTEM_OPENGL_GL_12_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_12_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/OpenGL/Using/GL12ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL12ExtensionsMacro.h"

namespace System
{
	// OpenGL 1.2

	enum class ExistsOpenGLExtensions;

	extern PgglCopyTexSubImage3D gglCopyTexSubImage3D;
	extern PgglDrawRangeElements gglDrawRangeElements;
	extern PgglTexImage3D gglTexImage3D;
	extern PgglTexSubImage3D gglTexSubImage3D;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL12() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height,
											GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* data) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width,
											   GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlCopyTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;

	void InitOpenGL12() noexcept;
}

#endif // SYSTEM_OPENGL_GL_12_EXTENSIONS_H
