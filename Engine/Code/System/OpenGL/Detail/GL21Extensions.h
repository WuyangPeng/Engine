// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:32)

#ifndef SYSTEM_OPENGL_GL_21_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_21_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/OpenGL/Using/GL21ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL21ExtensionsMacro.h"

namespace System
{
	// OpenGL 2.1
	enum class ExistsOpenGLExtensions;

	extern PgglUniformMatrix2x3fv gglUniformMatrix2x3fv;
	extern PgglUniformMatrix3x2fv gglUniformMatrix3x2fv;
	extern PgglUniformMatrix2x4fv gglUniformMatrix2x4fv;
	extern PgglUniformMatrix4x2fv gglUniformMatrix4x2fv;
	extern PgglUniformMatrix3x4fv gglUniformMatrix3x4fv;
	extern PgglUniformMatrix4x3fv gglUniformMatrix4x3fv;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL21() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept;

	void InitOpenGL21() noexcept;
}

#endif // SYSTEM_OPENGL_GL_21_EXTENSIONS_H
