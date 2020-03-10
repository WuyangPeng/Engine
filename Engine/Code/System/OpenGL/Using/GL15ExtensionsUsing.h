// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:37)

#ifndef SYSTEM_OPENGL_GL_15_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_15_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

extern "C"
{
	using GLintptr = ptrdiff_t;
	using GLsizeiptr = ptrdiff_t;
}

namespace System
{
	// OpenGL 1.5

	using PgglGenQueries = void (OPENGL_STDCALL*) (GLsizei, GLuint*);
	using PgglDeleteQueries = void (OPENGL_STDCALL*) (GLsizei, const GLuint*);
	using PgglIsQuery = unsigned char (OPENGL_STDCALL*) (GLuint);
	using PgglBeginQuery = void (OPENGL_STDCALL*) (GLenum, GLuint);
	using PgglEndQuery = void (OPENGL_STDCALL*) (GLenum);
	using PgglGetQueryiv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglGetQueryObjectiv = void (OPENGL_STDCALL*) (GLuint, GLenum, GLint*);
	using PgglGetQueryObjectuiv = void (OPENGL_STDCALL*) (GLuint, GLenum, GLuint*);
	using PgglBindBuffer = void (OPENGL_STDCALL*) (GLenum, GLuint);
	using PgglDeleteBuffers = void (OPENGL_STDCALL*) (GLsizei, const GLuint*);
	using PgglGenBuffers = void (OPENGL_STDCALL*) (GLsizei, GLuint*);
	using PgglIsBuffer = unsigned char (OPENGL_STDCALL*) (GLuint);
	using PgglBufferData = void (OPENGL_STDCALL*) (GLenum, GLsizeiptr, const GLvoid*, GLenum);
	using PgglBufferSubData = void (OPENGL_STDCALL*) (GLenum, GLintptr, GLsizeiptr, const GLvoid*);
	using PgglGetBufferSubData = void (OPENGL_STDCALL*) (GLenum, GLintptr, GLsizeiptr, GLvoid*);
	using PgglMapBuffer = void* (OPENGL_STDCALL*)(GLenum, GLenum);
	using PgglUnmapBuffer = unsigned char (OPENGL_STDCALL*) (GLenum);
	using PgglGetBufferParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglGetBufferPointerv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLvoid**);
}

#endif // SYSTEM_OPENGL_GL_15_EXTENSIONS_USING_H
