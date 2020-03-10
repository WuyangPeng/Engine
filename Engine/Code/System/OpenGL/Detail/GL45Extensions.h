// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_OPENGL_GL_45_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_45_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL45ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL45ExtensionsMacro.h"

namespace System
{
	// OpenGL 4.5
	enum class ExistsOpenGLExtensions;

	extern PgglGetGraphicsResetStatus gglGetGraphicsResetStatus;
	extern PgglGetnCompressedTexImage gglGetnCompressedTexImage;
	extern PgglGetnTexImage gglGetnTexImage;
	extern PgglGetnUniformdv gglGetnUniformdv;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL45() noexcept;

	SYSTEM_HIDDEN_DECLARE GLenum GlGetGraphicsResetStatus() noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetnTexImage(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetnUniformdv(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept;

	void InitOpenGL45() noexcept;
}

#endif // SYSTEM_OPENGL_GL_45_EXTENSIONS_H
