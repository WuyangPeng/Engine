// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:33)

#ifndef SYSTEM_OPENGL_GL_33_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_33_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL33ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL33ExtensionsMacro.h"

namespace System
{
	// OpenGL 3.3
	enum class ExistsOpenGLExtensions;

	extern PgglVertexAttribDivisor gglVertexAttribDivisor;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL33() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlVertexAttribDivisor(GLuint index, GLuint divisor) noexcept;

	void InitOpenGL33() noexcept;
}

#endif // SYSTEM_OPENGL_GL_33_EXTENSIONS_H
