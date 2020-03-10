// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:38)

#ifndef SYSTEM_OPENGL_GL_40_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_40_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
	using PgglBlendEquationSeparatei = void (OPENGL_STDCALL*) (GLuint, GLenum, GLenum);
	using PgglBlendEquationi = void (OPENGL_STDCALL*) (GLuint, GLenum);
	using PgglBlendFuncSeparatei = void (OPENGL_STDCALL*) (GLuint, GLenum, GLenum, GLenum, GLenum);
	using PgglBlendFunci = void (OPENGL_STDCALL*) (GLuint, GLenum, GLenum);
	using PgglMinSampleShading = void (OPENGL_STDCALL*) (GLclampf);
}

#endif // SYSTEM_OPENGL_GL_40_EXTENSIONS_USING_H
