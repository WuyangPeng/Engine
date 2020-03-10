// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:37)

#ifndef SYSTEM_OPENGL_GL_21_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_21_EXTENSIONS_USING_H

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "GL11ExtensionsUsing.h"

namespace System
{
	// OpenGL 2.1

	using PgglUniformMatrix2x3fv = void (OPENGL_STDCALL*) (GLint, GLsizei, GLboolean, const GLfloat*);
	using PgglUniformMatrix3x2fv = void (OPENGL_STDCALL*) (GLint, GLsizei, GLboolean, const GLfloat*);
	using PgglUniformMatrix2x4fv = void (OPENGL_STDCALL*) (GLint, GLsizei, GLboolean, const GLfloat*);
	using PgglUniformMatrix4x2fv = void (OPENGL_STDCALL*) (GLint, GLsizei, GLboolean, const GLfloat*);
	using PgglUniformMatrix3x4fv = void (OPENGL_STDCALL*) (GLint, GLsizei, GLboolean, const GLfloat*);
	using PgglUniformMatrix4x3fv = void (OPENGL_STDCALL*) (GLint, GLsizei, GLboolean, const GLfloat*);
}

#endif // SYSTEM_OPENGL_GL_21_EXTENSIONS_USING_H
