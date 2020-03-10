// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:33)

#ifndef SYSTEM_OPENGL_GL_32_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_32_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL32ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL32ExtensionsMacro.h"

namespace System
{
	// OpenGL 3.2

	enum class ExistsOpenGLExtensions;

	extern PgglGetInteger64i_v gglGetInteger64i_v;
	extern PgglGetBufferParameteri64v gglGetBufferParameteri64v;
	extern PgglProgramParameteri gglProgramParameteri;
	extern PgglFramebufferTexture gglFramebufferTexture;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL32() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlGetInteger64i_v(GLenum target, GLuint index, GLint64* data) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetBufferParameteri64v(GLenum target, GLenum name, GLint64* params) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlProgramParameteri(GLuint program, GLenum name, GLint value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept;

	void InitOpenGL32() noexcept;
}

#endif // SYSTEM_OPENGL_GL_32_EXTENSIONS_H
