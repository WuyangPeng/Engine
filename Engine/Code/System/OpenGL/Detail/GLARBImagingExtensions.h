// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:34)

#ifndef SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_H

#include "System/SystemDll.h"

#include "System/Helper/GLExtensionsMacro.h" 
#include "System/OpenGL/Using/GLARBImagingExtensionsUsing.h"

namespace System
{
	enum class ExistsOpenGLExtensions;

	extern PgglBlendColor gglBlendColor;
	extern PgglBlendEquation gglBlendEquation;
	extern PgglColorTable gglColorTable;
	extern PgglColorTableParameterfv gglColorTableParameterfv;
	extern PgglColorTableParameteriv gglColorTableParameteriv;
	extern PgglCopyColorTable gglCopyColorTable;
	extern PgglGetColorTable gglGetColorTable;
	extern PgglGetColorTableParameterfv gglGetColorTableParameterfv;
	extern PgglGetColorTableParameteriv gglGetColorTableParameteriv;
	extern PgglColorSubTable gglColorSubTable;
	extern PgglCopyColorSubTable gglCopyColorSubTable;
	extern PgglConvolutionFilter1D gglConvolutionFilter1D;
	extern PgglConvolutionFilter2D gglConvolutionFilter2D;
	extern PgglConvolutionParameterf gglConvolutionParameterf;
	extern PgglConvolutionParameterfv gglConvolutionParameterfv;
	extern PgglConvolutionParameteri gglConvolutionParameteri;
	extern PgglConvolutionParameteriv gglConvolutionParameteriv;
	extern PgglCopyConvolutionFilter1D gglCopyConvolutionFilter1D;
	extern PgglCopyConvolutionFilter2D gglCopyConvolutionFilter2D;
	extern PgglGetConvolutionFilter gglGetConvolutionFilter;
	extern PgglGetConvolutionParameterfv gglGetConvolutionParameterfv;
	extern PgglGetConvolutionParameteriv gglGetConvolutionParameteriv;
	extern PgglGetSeparableFilter gglGetSeparableFilter;
	extern PgglSeparableFilter2D gglSeparableFilter2D;
	extern PgglGetHistogram gglGetHistogram;
	extern PgglGetHistogramParameterfv gglGetHistogramParameterfv;
	extern PgglGetHistogramParameteriv gglGetHistogramParameteriv;
	extern PgglGetMinmax gglGetMinmax;
	extern PgglGetMinmaxParameterfv gglGetMinmaxParameterfv;
	extern PgglGetMinmaxParameteriv gglGetMinmaxParameteriv;
	extern PgglHistogram gglHistogram;
	extern PgglMinmax gglMinmax;
	extern PgglResetHistogram gglResetHistogram;
	extern PgglResetMinmax gglResetMinmax;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsGlArbImaging() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlBlendEquation(GLenum mode) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlColorTable(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* table) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlColorTableParameterfv(GLenum target, GLenum name, const GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlColorTableParameteriv(GLenum target, GLenum name, const GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlCopyColorTable(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid* table) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetColorTableParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetColorTableParameteriv(GLenum target, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlConvolutionFilter1D(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* image) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlConvolutionFilter2D(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlConvolutionParameterf(GLenum target, GLenum name, GLfloat param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlConvolutionParameterfv(GLenum target, GLenum name, const GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlConvolutionParameteri(GLenum target, GLenum name, GLint param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlConvolutionParameteriv(GLenum target, GLenum name, const GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlCopyConvolutionFilter1D(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlCopyConvolutionFilter2D(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid* image) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetConvolutionParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetConvolutionParameteriv(GLenum target, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSeparableFilter2D(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height,
												   GLenum format, GLenum type, const GLvoid* row, const GLvoid* column) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetHistogramParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetHistogramParameteriv(GLenum target, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetMinmaxParameterfv(GLenum target, GLenum name, GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlGetMinmaxParameteriv(GLenum target, GLenum name, GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlHistogram(GLenum target, GLsizei width, GLenum internalFormat, GLboolean sink) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlMinmax(GLenum target, GLenum internalFormat, GLboolean sink) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlResetHistogram(GLenum target) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlResetMinmax(GLenum target) noexcept;

	void InitGlArbImaging() noexcept;
}

#endif // SYSTEM_OPENGL_GL_ARB_IMAGING_EXTENSIONS_H
