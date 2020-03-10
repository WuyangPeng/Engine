// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:38)

#ifndef SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_USING_H

#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "GL11ExtensionsUsing.h"

namespace System
{
	// ≥…œÒ◊”ºØ (GL_ARB_imaging)

	using PgglBlendColor = void (OPENGL_STDCALL*) (GLclampf, GLclampf, GLclampf, GLclampf);
	using PgglBlendEquation = void (OPENGL_STDCALL*) (GLenum);
	using PgglColorTable = void (OPENGL_STDCALL*) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	using PgglColorTableParameterfv = void (OPENGL_STDCALL*) (GLenum, GLenum, const GLfloat*);
	using PgglColorTableParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, const GLint*);
	using PgglCopyColorTable = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint, GLint, GLsizei);
	using PgglGetColorTable = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLvoid*);
	using PgglGetColorTableParameterfv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLfloat*);
	using PgglGetColorTableParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglColorSubTable = void (OPENGL_STDCALL*) (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	using PgglCopyColorSubTable = void (OPENGL_STDCALL*) (GLenum, GLsizei, GLint, GLint, GLsizei);
	using PgglConvolutionFilter1D = void (OPENGL_STDCALL*) (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	using PgglConvolutionFilter2D = void (OPENGL_STDCALL*) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	using PgglConvolutionParameterf = void (OPENGL_STDCALL*) (GLenum, GLenum, GLfloat);
	using PgglConvolutionParameterfv = void (OPENGL_STDCALL*) (GLenum, GLenum, const GLfloat*);
	using PgglConvolutionParameteri = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint);
	using PgglConvolutionParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, const GLint*);
	using PgglCopyConvolutionFilter1D = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint, GLint, GLsizei);
	using PgglCopyConvolutionFilter2D = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
	using PgglGetConvolutionFilter = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLvoid*);
	using PgglGetConvolutionParameterfv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLfloat*);
	using PgglGetConvolutionParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglGetSeparableFilter = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLvoid*, GLvoid*, GLvoid*);
	using PgglSeparableFilter2D = void (OPENGL_STDCALL*) (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*, const GLvoid*);
	using PgglGetHistogram = void (OPENGL_STDCALL*) (GLenum, GLboolean, GLenum, GLenum, GLvoid*);
	using PgglGetHistogramParameterfv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLfloat*);
	using PgglGetHistogramParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglGetMinmax = void (OPENGL_STDCALL*) (GLenum, GLboolean, GLenum, GLenum, GLvoid*);
	using PgglGetMinmaxParameterfv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLfloat*);
	using PgglGetMinmaxParameteriv = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglHistogram = void (OPENGL_STDCALL*) (GLenum, GLsizei, GLenum, GLboolean);
	using PgglMinmax = void (OPENGL_STDCALL*) (GLenum, GLenum, GLboolean);
	using PgglResetHistogram = void (OPENGL_STDCALL*) (GLenum);
	using PgglResetMinmax = void (OPENGL_STDCALL*) (GLenum);
}

#endif // SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_USING_H
