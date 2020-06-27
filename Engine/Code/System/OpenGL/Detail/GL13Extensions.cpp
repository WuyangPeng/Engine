// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:40)

#include "System/SystemExport.h"

#include "GL13Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL13ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 1.3
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL13{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL13() noexcept
{
	return g_ExistsOpenGL13;
}

System::PgglActiveTexture System::gglActiveTexture{ nullptr };
System::PgglClientActiveTexture System::gglClientActiveTexture{ nullptr };
System::PgglMultiTexCoord1d System::gglMultiTexCoord1d{ nullptr };
System::PgglMultiTexCoord1dv System::gglMultiTexCoord1dv{ nullptr };
System::PgglMultiTexCoord1f System::gglMultiTexCoord1f{ nullptr };
System::PgglMultiTexCoord1fv System::gglMultiTexCoord1fv{ nullptr };
System::PgglMultiTexCoord1i System::gglMultiTexCoord1i{ nullptr };
System::PgglMultiTexCoord1iv System::gglMultiTexCoord1iv{ nullptr };
System::PgglMultiTexCoord1s System::gglMultiTexCoord1s{ nullptr };
System::PgglMultiTexCoord1sv System::gglMultiTexCoord1sv{ nullptr };
System::PgglMultiTexCoord2d System::gglMultiTexCoord2d{ nullptr };
System::PgglMultiTexCoord2dv System::gglMultiTexCoord2dv{ nullptr };
System::PgglMultiTexCoord2f System::gglMultiTexCoord2f{ nullptr };
System::PgglMultiTexCoord2fv System::gglMultiTexCoord2fv{ nullptr };
System::PgglMultiTexCoord2i System::gglMultiTexCoord2i{ nullptr };
System::PgglMultiTexCoord2iv System::gglMultiTexCoord2iv{ nullptr };
System::PgglMultiTexCoord2s System::gglMultiTexCoord2s{ nullptr };
System::PgglMultiTexCoord2sv System::gglMultiTexCoord2sv{ nullptr };
System::PgglMultiTexCoord3d System::gglMultiTexCoord3d{ nullptr };
System::PgglMultiTexCoord3dv System::gglMultiTexCoord3dv{ nullptr };
System::PgglMultiTexCoord3f System::gglMultiTexCoord3f{ nullptr };
System::PgglMultiTexCoord3fv System::gglMultiTexCoord3fv{ nullptr };
System::PgglMultiTexCoord3i System::gglMultiTexCoord3i{ nullptr };
System::PgglMultiTexCoord3iv System::gglMultiTexCoord3iv{ nullptr };
System::PgglMultiTexCoord3s System::gglMultiTexCoord3s{ nullptr };
System::PgglMultiTexCoord3sv System::gglMultiTexCoord3sv{ nullptr };
System::PgglMultiTexCoord4d System::gglMultiTexCoord4d{ nullptr };
System::PgglMultiTexCoord4dv System::gglMultiTexCoord4dv{ nullptr };
System::PgglMultiTexCoord4f System::gglMultiTexCoord4f{ nullptr };
System::PgglMultiTexCoord4fv System::gglMultiTexCoord4fv{ nullptr };
System::PgglMultiTexCoord4i System::gglMultiTexCoord4i{ nullptr };
System::PgglMultiTexCoord4iv System::gglMultiTexCoord4iv{ nullptr };
System::PgglMultiTexCoord4s System::gglMultiTexCoord4s{ nullptr };
System::PgglMultiTexCoord4sv System::gglMultiTexCoord4sv{ nullptr };
System::PgglLoadTransposeMatrixf System::gglLoadTransposeMatrixf{ nullptr };
System::PgglLoadTransposeMatrixd System::gglLoadTransposeMatrixd{ nullptr };
System::PgglMultTransposeMatrixf System::gglMultTransposeMatrixf{ nullptr };
System::PgglMultTransposeMatrixd System::gglMultTransposeMatrixd{ nullptr };
System::PgglSampleCoverage System::gglSampleCoverage{ nullptr };
System::PgglCompressedTexImage3D System::gglCompressedTexImage3D{ nullptr };
System::PgglCompressedTexImage2D System::gglCompressedTexImage2D{ nullptr };
System::PgglCompressedTexImage1D System::gglCompressedTexImage1D{ nullptr };
System::PgglCompressedTexSubImage3D System::gglCompressedTexSubImage3D{ nullptr };
System::PgglCompressedTexSubImage2D System::gglCompressedTexSubImage2D{ nullptr };
System::PgglCompressedTexSubImage1D System::gglCompressedTexSubImage1D{ nullptr };
System::PgglGetCompressedTexImage System::gglGetCompressedTexImage{ nullptr };

void System
	::GlActiveTexture(GLenum texture) noexcept
{
	SYSTEM_BODY_1(gglActiveTexture, texture);
}

void System
	::GlClientActiveTexture(GLenum texture) noexcept
{
	SYSTEM_BODY_1(gglClientActiveTexture, texture);
}

void System
	::GlMultiTexCoord1d(GLenum target, GLdouble s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1d, target, s);
}

void System
	::GlMultiTexCoord1dv(GLenum target, const GLdouble* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1dv, target, s);
}

void System
	::GlMultiTexCoord1f(GLenum target, GLfloat s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1f, target, s);
}

void System
	::GlMultiTexCoord1fv(GLenum target, const GLfloat* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1fv, target, s);
}

void System
	::GlMultiTexCoord1i(GLenum target, GLint s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1i, target, s);
}

void System
	::GlMultiTexCoord1iv(GLenum target, const GLint* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1iv, target, s);
}

void System
	::GlMultiTexCoord1s(GLenum target, GLshort s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1s, target, s);
}

void System
	::GlMultiTexCoord1sv(GLenum target, const GLshort* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1sv, target, s);
}

void System
	::GlMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2d, target, s, t);
}

void System
	::GlMultiTexCoord2dv(GLenum target, const GLdouble* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2dv, target, st);
}

void System
	::GlMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2f, target, s, t);
}

void System
	::GlMultiTexCoord2fv(GLenum target, const GLfloat* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2fv, target, st);
}

void System
	::GlMultiTexCoord2i(GLenum target, GLint s, GLint t) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2i, target, s, t);
}

void System
	::GlMultiTexCoord2iv(GLenum target, const GLint* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2iv, target, st);
}

void System
	::GlMultiTexCoord2s(GLenum target, GLshort s, GLshort st) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2s, target, s, st);
}

void System
	::GlMultiTexCoord2sv(GLenum target, const GLshort* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2sv, target, st);
}

void System
	::GlMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3d, target, s, t, r);
}

void System
	::GlMultiTexCoord3dv(GLenum target, const GLdouble* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3dv, target, str);
}

void System
	::GlMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3f, target, s, t, r);
}

void System
	::GlMultiTexCoord3fv(GLenum target, const GLfloat* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3fv, target, str);
}

void System
	::GlMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3i, target, s, t, r);
}

void System
	::GlMultiTexCoord3iv(GLenum target, const GLint* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3iv, target, str);
}

void System
	::GlMultiTexCoord3s(GLenum target, GLshort s, GLshort st, GLshort r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3s, target, s, st, r);
}

void System
	::GlMultiTexCoord3sv(GLenum target, const GLshort* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3sv, target, str);
}

void System
	::GlMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4d, target, s, t, r, q);
}

void System
	::GlMultiTexCoord4dv(GLenum target, const GLdouble* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4dv, target, strq);
}

void System
	::GlMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4f, target, s, t, r, q);
}

void System
	::GlMultiTexCoord4fv(GLenum target, const GLfloat* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4fv, target, strq);
}

void System
	::GlMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4i, target, s, t, r, q);
}

void System
	::GlMultiTexCoord4iv(GLenum target, const GLint* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4iv, target, strq);
}

void System
	::GlMultiTexCoord4s(GLenum target, GLshort s, GLshort st, GLshort r, GLshort q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4s, target, s, st, r, q);
}

void System
	::GlMultiTexCoord4sv(GLenum target, const GLshort* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4sv, target, strq);
}

void System
	::GlLoadTransposeMatrixd(const GLdouble* matrix) noexcept
{
	SYSTEM_BODY_1(gglLoadTransposeMatrixd, matrix);
}

void System
	::GlLoadTransposeMatrixf(const GLfloat* matrix) noexcept
{
	SYSTEM_BODY_1(gglLoadTransposeMatrixf, matrix);
}

void System
	::GlMultTransposeMatrixd(const GLdouble* matrix) noexcept
{
	SYSTEM_BODY_1(gglMultTransposeMatrixd, matrix);
}

void System
	::GlMultTransposeMatrixf(const GLfloat* matrix) noexcept
{
	SYSTEM_BODY_1(gglMultTransposeMatrixf, matrix);
}

void System
	::GlSampleCoverage(GLclampf value, GLboolean invert) noexcept
{
	SYSTEM_BODY_2(gglSampleCoverage, value, invert);
}

void System
	::GlCompressedTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglCompressedTexImage1D, target, level, internalFormat, width, border, imageSize, data);
}

void System
	::GlCompressedTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_8(gglCompressedTexImage2D, target, level, internalFormat, width, height, border, imageSize, data);
}

void System
	::GlCompressedTexImage3D(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedTexImage3D, target, level, internalFormat, width, height, depth, border, imageSize, data);
}

void System
	::GlCompressedTexSubImage1D(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglCompressedTexSubImage1D, target, level, xOffset, width, format, imageSize, data);
}

void System
	::GlCompressedTexSubImage2D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedTexSubImage2D, target, level, xOffset, yOffset, width, height, format, imageSize, data);
}

void System
	::GlCompressedTexSubImage3D(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_11(gglCompressedTexSubImage3D, target, level, xOffset, yOffset, zOffset, width, height, depth, format, imageSize, data);
}

void System
	::GlGetCompressedTexImage(GLenum target, GLint level, GLvoid* data) noexcept
{
	SYSTEM_BODY_3(gglGetCompressedTexImage, target, level, data);
}

void System
	::InitOpenGL13() noexcept
{
	if (System::OpenGLSystemVersion::Version13 <= GetOpenGLVersion())
	{
		g_ExistsOpenGL13 = ExistsOpenGLExtensions::Exists;

		// GL_ARB_multisample

		SYSTEM_GET_FUNCTION(gglSampleCoverage);

		// GL_ARB_multitexture

		SYSTEM_GET_FUNCTION(gglActiveTexture);
		SYSTEM_GET_FUNCTION(gglClientActiveTexture);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1d);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1dv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1f);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1fv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1i);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1iv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1s);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord1sv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2d);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2dv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2f);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2fv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2i);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2iv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2s);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord2sv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3d);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3dv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3f);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3fv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3i);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3iv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3s);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord3sv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4d);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4dv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4f);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4fv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4i);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4iv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4s);
		SYSTEM_GET_FUNCTION(gglMultiTexCoord4sv);

		// GL_ARB_texture_compression

		SYSTEM_GET_FUNCTION(gglCompressedTexImage3D);
		SYSTEM_GET_FUNCTION(gglCompressedTexImage2D);
		SYSTEM_GET_FUNCTION(gglCompressedTexImage1D);
		SYSTEM_GET_FUNCTION(gglCompressedTexSubImage3D);
		SYSTEM_GET_FUNCTION(gglCompressedTexSubImage2D);
		SYSTEM_GET_FUNCTION(gglCompressedTexSubImage1D);
		SYSTEM_GET_FUNCTION(gglGetCompressedTexImage);

		// GL_ARB_transpose_matrix

		SYSTEM_GET_FUNCTION(gglLoadTransposeMatrixf);
		SYSTEM_GET_FUNCTION(gglLoadTransposeMatrixd);
		SYSTEM_GET_FUNCTION(gglMultTransposeMatrixf);
		SYSTEM_GET_FUNCTION(gglMultTransposeMatrixd);
	}
	else
	{
		g_ExistsOpenGL13 = ExistsOpenGLExtensions::NotExist;
	}
}