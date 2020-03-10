// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_OPENGL_GL_40_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_40_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL40ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL40ExtensionsMacro.h"

namespace System
{
	// OpenGL 4.0
	enum class ExistsOpenGLExtensions;

	extern PgglBlendEquationSeparatei gglBlendEquationSeparatei;
	extern PgglBlendEquationi gglBlendEquationi;
	extern PgglBlendFuncSeparatei gglBlendFuncSeparatei;
	extern PgglBlendFunci gglBlendFunci;
	extern PgglMinSampleShading gglMinSampleShading;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL40() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBlendEquationi(GLuint buf, GLenum mode) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBlendFunci(GLuint buf, GLenum src, GLenum dst) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlMinSampleShading(GLclampf value) noexcept;

	void InitOpenGL40() noexcept;
}

#endif // SYSTEM_OPENGL_GL_40_EXTENSIONS_H
