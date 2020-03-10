// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:37)

#ifndef SYSTEM_OPENGL_GL_12_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_12_EXTENSIONS_USING_H

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "GL11ExtensionsUsing.h"

namespace System
{
	// OpenGL 1.2
	using PgglCopyTexSubImage3D = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	using PgglDrawRangeElements = void (OPENGL_STDCALL*) (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
	using PgglTexImage3D = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	using PgglTexSubImage3D = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
}

#endif // SYSTEM_OPENGL_GL_12_EXTENSIONS_USING_H
