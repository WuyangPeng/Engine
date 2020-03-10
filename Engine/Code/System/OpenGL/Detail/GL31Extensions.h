// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:33)

#ifndef SYSTEM_OPENGL_GL_31_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_31_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL31ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL31ExtensionsMacro.h"

namespace System
{
	// OpenGL 3.1

	enum class ExistsOpenGLExtensions;

	extern PgglDrawArraysInstanced gglDrawArraysInstanced;
	extern PgglDrawElementsInstanced gglDrawElementsInstanced;
	extern PgglTexBuffer gglTexBuffer;
	extern PgglPrimitiveRestartIndex gglPrimitiveRestartIndex;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL31() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlPrimitiveRestartIndex(GLuint index) noexcept;

	void InitOpenGL31() noexcept;
}

#endif // SYSTEM_OPENGL_GL_31_EXTENSIONS_H
