// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:32)

#ifndef SYSTEM_OPENGL_GL_14_EXTENSIONS_H
#define SYSTEM_OPENGL_GL_14_EXTENSIONS_H

#include "System/SystemDll.h" 

#include "System/OpenGL/Using/GL14ExtensionsUsing.h"
#include "System/OpenGL/Using/GL11ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GL14ExtensionsMacro.h"

namespace System
{
	// OpenGL 1.4
	enum class ExistsOpenGLExtensions;

	extern PgglBlendFuncSeparate gglBlendFuncSeparate;
	extern PgglFogCoordf gglFogCoordf;
	extern PgglFogCoordfv gglFogCoordfv;
	extern PgglFogCoordd gglFogCoordd;
	extern PgglFogCoorddv gglFogCoorddv;
	extern PgglFogCoordPointer gglFogCoordPointer;
	extern PgglMultiDrawArrays gglMultiDrawArrays;
	extern PgglMultiDrawElements gglMultiDrawElements;
	extern PgglPointParameterf gglPointParameterf;
	extern PgglPointParameterfv gglPointParameterfv;
	extern PgglPointParameteri gglPointParameteri;
	extern PgglPointParameteriv gglPointParameteriv;
	extern PgglSecondaryColor3b gglSecondaryColor3b;
	extern PgglSecondaryColor3bv gglSecondaryColor3bv;
	extern PgglSecondaryColor3d gglSecondaryColor3d;
	extern PgglSecondaryColor3dv gglSecondaryColor3dv;
	extern PgglSecondaryColor3f gglSecondaryColor3f;
	extern PgglSecondaryColor3fv gglSecondaryColor3fv;
	extern PgglSecondaryColor3i gglSecondaryColor3i;
	extern PgglSecondaryColor3iv gglSecondaryColor3iv;
	extern PgglSecondaryColor3s gglSecondaryColor3s;
	extern PgglSecondaryColor3sv gglSecondaryColor3sv;
	extern PgglSecondaryColor3ub gglSecondaryColor3ub;
	extern PgglSecondaryColor3ubv gglSecondaryColor3ubv;
	extern PgglSecondaryColor3ui gglSecondaryColor3ui;
	extern PgglSecondaryColor3uiv gglSecondaryColor3uiv;
	extern PgglSecondaryColor3us gglSecondaryColor3us;
	extern PgglSecondaryColor3usv gglSecondaryColor3usv;
	extern PgglSecondaryColorPointer gglSecondaryColorPointer;
	extern PgglWindowPos2d gglWindowPos2d;
	extern PgglWindowPos2dv gglWindowPos2dv;
	extern PgglWindowPos2f gglWindowPos2f;
	extern PgglWindowPos2fv gglWindowPos2fv;
	extern PgglWindowPos2i gglWindowPos2i;
	extern PgglWindowPos2iv gglWindowPos2iv;
	extern PgglWindowPos2s gglWindowPos2s;
	extern PgglWindowPos2sv gglWindowPos2sv;
	extern PgglWindowPos3d gglWindowPos3d;
	extern PgglWindowPos3dv gglWindowPos3dv;
	extern PgglWindowPos3f gglWindowPos3f;
	extern PgglWindowPos3fv gglWindowPos3fv;
	extern PgglWindowPos3i gglWindowPos3i;
	extern PgglWindowPos3iv gglWindowPos3iv;
	extern PgglWindowPos3s gglWindowPos3s;
	extern PgglWindowPos3sv gglWindowPos3sv;

	SYSTEM_HIDDEN_DECLARE ExistsOpenGLExtensions IsExistsOpenGL14() noexcept;

	SYSTEM_HIDDEN_DECLARE void GlBlendFuncSeparate(GLenum srcFactorRGB, GLenum dstFactorRGB, GLenum srcFactorA, GLenum dstFactorA) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlFogCoordd(GLdouble coord) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlFogCoorddv(const GLdouble* coord) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlFogCoordf(GLfloat coord) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlFogCoordfv(const GLfloat* coord) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlFogCoordPointer(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlMultiDrawArrays(GLenum mode, GLint* first, GLsizei* count, GLsizei primitiveCount) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlMultiDrawElements(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primitiveCount) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlPointParameterf(GLenum name, GLfloat param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlPointParameterfv(GLenum name, const GLfloat* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlPointParameteri(GLenum name, int param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlPointParameteriv(GLenum name, const GLint* param) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3b(GLbyte r, GLbyte g, GLbyte b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3bv(const GLbyte* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3d(GLdouble r, GLdouble g, GLdouble b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3dv(const GLdouble* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3fv(const GLfloat* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3i(GLint r, GLint g, GLint b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3iv(const GLint* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3s(GLshort r, GLshort g, GLshort b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3sv(const GLshort* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3ub(GLubyte ucR, GLubyte g, GLubyte b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3ubv(const GLubyte* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3ui(GLuint uiR, GLuint g, GLuint b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3uiv(const GLuint* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3us(GLushort usR, GLushort g, GLushort b) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColor3usv(const GLushort* rgb) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2d(GLdouble x, GLdouble y) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2dv(const GLdouble* xy) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2f(GLfloat x, GLfloat y) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2fv(const GLfloat* xy) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2i(GLint x, GLint y) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2iv(const GLint* xy) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2s(GLshort x, GLshort y) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos2sv(const GLshort* xy) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3d(GLdouble x, GLdouble y, GLdouble z) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3dv(const GLdouble* xyz) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3f(GLfloat x, GLfloat y, GLfloat z) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3fv(const GLfloat* xyz) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3i(GLint x, GLint y, GLint z) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3iv(const GLint* xyz) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3s(GLshort x, GLshort y, GLshort z) noexcept;
	SYSTEM_HIDDEN_DECLARE void GlWindowPos3sv(const GLshort* xyz) noexcept;

	void InitOpenGL14() noexcept;
}

#endif // SYSTEM_OPENGL_GL_14_EXTENSIONS_H
