// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:38)

#ifndef SYSTEM_OPENGL_GL_45_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_45_EXTENSIONS_USING_H

#include "GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"

namespace System
{
	using PgglGetGraphicsResetStatus = GLenum(OPENGL_STDCALL*) ();
	using PgglGetnCompressedTexImage = void (OPENGL_STDCALL*) (GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels);
	using PgglGetnTexImage = void (OPENGL_STDCALL*) (GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
	using PgglGetnUniformdv = void (OPENGL_STDCALL*) (GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels);
}

#endif // SYSTEM_OPENGL_GL_45_EXTENSIONS_USING_H
