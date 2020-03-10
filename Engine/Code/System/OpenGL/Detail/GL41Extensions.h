// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_OPENGL_GL_41_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_41_EXTENSIONS_H

#include "System/SystemDll.h" 

#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
	// OpenGL 4.1
	enum class ExistsOpenGLExtensions;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL41() noexcept;

	void InitOpenGL41() noexcept;
}

#endif // SYSTEM_OPENGL_GL_41_EXTENSIONS_H
