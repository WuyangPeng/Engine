// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:38)

#ifndef SYSTEM_OPENGL_GL_31_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_31_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
	// OpenGL 3.1

	using PgglDrawArraysInstanced = void (OPENGL_STDCALL*)(GLenum, GLint, GLsizei, GLsizei);
	using PgglDrawElementsInstanced = void (OPENGL_STDCALL*)(GLenum, GLsizei, GLenum, const GLvoid*, GLsizei);
	using PgglTexBuffer = void (OPENGL_STDCALL*)(GLenum, GLenum, GLuint);
	using PgglPrimitiveRestartIndex = void (OPENGL_STDCALL*)(GLuint);
}

#endif // SYSTEM_OPENGL_GL_31_EXTENSIONS_USING_H
