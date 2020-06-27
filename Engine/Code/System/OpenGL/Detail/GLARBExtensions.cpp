// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GLARBExtensions.h" 
#include "GL13Extensions.h"
#include "GL14Extensions.h"
#include "GL15Extensions.h"
#include "GL20Extensions.h"
#include "GL40Extensions.h" 
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GLARBExtensionsUsing.h"
#include "System/OpenGL/Using/GL13ExtensionsUsing.h"
#include "System/OpenGL/Using/GL14ExtensionsUsing.h"
#include "System/OpenGL/Using/GL40ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// ARB ¿©’π

// (ARB 01) GL_ARB_multitexture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMultitexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMultitexture() noexcept
{
	return g_ExistsGlArbMultitexture;
}

namespace System
{
	PgglActiveTexture gglActiveTextureARB{ nullptr };
	PgglClientActiveTexture gglClientActiveTextureARB{ nullptr };
	PgglMultiTexCoord1d gglMultiTexCoord1dARB{ nullptr };
	PgglMultiTexCoord1dv gglMultiTexCoord1dvARB{ nullptr };
	PgglMultiTexCoord1f gglMultiTexCoord1fARB{ nullptr };
	PgglMultiTexCoord1fv gglMultiTexCoord1fvARB{ nullptr };
	PgglMultiTexCoord1i gglMultiTexCoord1iARB{ nullptr };
	PgglMultiTexCoord1iv gglMultiTexCoord1ivARB{ nullptr };
	PgglMultiTexCoord1s gglMultiTexCoord1sARB{ nullptr };
	PgglMultiTexCoord1sv gglMultiTexCoord1svARB{ nullptr };
	PgglMultiTexCoord2d gglMultiTexCoord2dARB{ nullptr };
	PgglMultiTexCoord2dv gglMultiTexCoord2dvARB{ nullptr };
	PgglMultiTexCoord2f gglMultiTexCoord2fARB{ nullptr };
	PgglMultiTexCoord2fv gglMultiTexCoord2fvARB{ nullptr };
	PgglMultiTexCoord2i gglMultiTexCoord2iARB{ nullptr };
	PgglMultiTexCoord2iv gglMultiTexCoord2ivARB{ nullptr };
	PgglMultiTexCoord2s gglMultiTexCoord2sARB{ nullptr };
	PgglMultiTexCoord2sv gglMultiTexCoord2svARB{ nullptr };
	PgglMultiTexCoord3d gglMultiTexCoord3dARB{ nullptr };
	PgglMultiTexCoord3dv gglMultiTexCoord3dvARB{ nullptr };
	PgglMultiTexCoord3f gglMultiTexCoord3fARB{ nullptr };
	PgglMultiTexCoord3fv gglMultiTexCoord3fvARB{ nullptr };
	PgglMultiTexCoord3i gglMultiTexCoord3iARB{ nullptr };
	PgglMultiTexCoord3iv gglMultiTexCoord3ivARB{ nullptr };
	PgglMultiTexCoord3s gglMultiTexCoord3sARB{ nullptr };
	PgglMultiTexCoord3sv gglMultiTexCoord3svARB{ nullptr };
	PgglMultiTexCoord4d gglMultiTexCoord4dARB{ nullptr };
	PgglMultiTexCoord4dv gglMultiTexCoord4dvARB{ nullptr };
	PgglMultiTexCoord4f gglMultiTexCoord4fARB{ nullptr };
	PgglMultiTexCoord4fv gglMultiTexCoord4fvARB{ nullptr };
	PgglMultiTexCoord4i gglMultiTexCoord4iARB{ nullptr };
	PgglMultiTexCoord4iv gglMultiTexCoord4ivARB{ nullptr };
	PgglMultiTexCoord4s gglMultiTexCoord4sARB{ nullptr };
	PgglMultiTexCoord4sv gglMultiTexCoord4svARB{ nullptr };
}

void System
	::GlActiveTextureARB(GLenum texture) noexcept
{
	SYSTEM_BODY_1(gglActiveTextureARB, texture);
}

void System
	::GlClientActiveTextureARB(GLenum texture) noexcept
{
	SYSTEM_BODY_1(gglClientActiveTextureARB, texture);
}

void System
	::GlMultiTexCoord1dARB(GLenum target, GLdouble s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1dARB, target, s);
}

void System
	::GlMultiTexCoord1dvARB(GLenum target, const GLdouble* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1dvARB, target, s);
}

void System
	::GlMultiTexCoord1fARB(GLenum target, GLfloat s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1fARB, target, s);
}

void System
	::GlMultiTexCoord1fvARB(GLenum target, const GLfloat* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1fvARB, target, s);
}

void System
	::GlMultiTexCoord1iARB(GLenum target, GLint s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1iARB, target, s);
}

void System
	::GlMultiTexCoord1ivARB(GLenum target, const GLint* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1ivARB, target, s);
}

void System
	::GlMultiTexCoord1sARB(GLenum target, GLshort s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1sARB, target, s);
}

void System
	::GlMultiTexCoord1svARB(GLenum target, const GLshort* s) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord1svARB, target, s);
}

void System
	::GlMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2dARB, target, s, t);
}

void System
	::GlMultiTexCoord2dvARB(GLenum target, const GLdouble* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2dvARB, target, st);
}

void System
	::GlMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2fARB, target, s, t);
}

void System
	::GlMultiTexCoord2fvARB(GLenum target, const GLfloat* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2fvARB, target, st);
}

void System
	::GlMultiTexCoord2iARB(GLenum target, GLint s, GLint t) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2iARB, target, s, t);
}

void System
	::GlMultiTexCoord2ivARB(GLenum target, const GLint* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2ivARB, target, st);
}

void System
	::GlMultiTexCoord2sARB(GLenum target, GLshort s, GLshort st) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoord2sARB, target, s, st);
}

void System
	::GlMultiTexCoord2svARB(GLenum target, const GLshort* st) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord2svARB, target, st);
}

void System
	::GlMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3dARB, target, s, t, r);
}

void System
	::GlMultiTexCoord3dvARB(GLenum target, const GLdouble* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3dvARB, target, str);
}

void System
	::GlMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3fARB, target, s, t, r);
}

void System
	::GlMultiTexCoord3fvARB(GLenum target, const GLfloat* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3fvARB, target, str);
}

void System
	::GlMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3iARB, target, s, t, r);
}

void System
	::GlMultiTexCoord3ivARB(GLenum target, const GLint* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3ivARB, target, str);
}

void System
	::GlMultiTexCoord3sARB(GLenum target, GLshort s, GLshort st, GLshort r) noexcept
{
	SYSTEM_BODY_4(gglMultiTexCoord3sARB, target, s, st, r);
}

void System
	::GlMultiTexCoord3svARB(GLenum target, const GLshort* str) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord3svARB, target, str);
}

void System
	::GlMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4dARB, target, s, t, r, q);
}

void System
	::GlMultiTexCoord4dvARB(GLenum target, const GLdouble* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4dvARB, target, strq);
}

void System
	::GlMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4fARB, target, s, t, r, q);
}

void System
	::GlMultiTexCoord4fvARB(GLenum target, const GLfloat* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4fvARB, target, strq);
}

void System
	::GlMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4iARB, target, s, t, r, q);
}

void System
	::GlMultiTexCoord4ivARB(GLenum target, const GLint* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4ivARB, target, strq);
}

void System
	::GlMultiTexCoord4sARB(GLenum target, GLshort s, GLshort st, GLshort r, GLshort q) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoord4sARB, target, s, st, r, q);
}

void System
	::GlMultiTexCoord4svARB(GLenum target, const GLshort* strq) noexcept
{
	SYSTEM_BODY_2(gglMultiTexCoord4svARB, target, strq);
}

void System
	::InitGlArbMultitexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_multitexture"))
	{
		g_ExistsGlArbMultitexture = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglActiveTexture, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglClientActiveTexture, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord1sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord2sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord3sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiTexCoord4sv, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbMultitexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 03) GL_ARB_transpose_matrix

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTransposeMatrix{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTransposeMatrix() noexcept
{
	return g_ExistsGlArbTransposeMatrix;
}

namespace System
{
	PgglLoadTransposeMatrixf gglLoadTransposeMatrixfARB{ nullptr };
	PgglLoadTransposeMatrixd gglLoadTransposeMatrixdARB{ nullptr };
	PgglMultTransposeMatrixf gglMultTransposeMatrixfARB{ nullptr };
	PgglMultTransposeMatrixd gglMultTransposeMatrixdARB{ nullptr };
}

void System
	::GlLoadTransposeMatrixdARB(const GLdouble* matrix) noexcept
{
	SYSTEM_BODY_1(gglLoadTransposeMatrixdARB, matrix);
}

void System
	::GlLoadTransposeMatrixfARB(const GLfloat* matrix) noexcept
{
	SYSTEM_BODY_1(gglLoadTransposeMatrixfARB, matrix);
}

void System
	::GlMultTransposeMatrixdARB(const GLdouble* matrix) noexcept
{
	SYSTEM_BODY_1(gglMultTransposeMatrixdARB, matrix);
}

void System
	::GlMultTransposeMatrixfARB(const GLfloat* matrix) noexcept
{
	SYSTEM_BODY_1(gglMultTransposeMatrixfARB, matrix);
}

void System
	::InitGlArbTransposeMatrix() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_transpose_matrix"))
	{
		g_ExistsGlArbTransposeMatrix = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglLoadTransposeMatrixf, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglLoadTransposeMatrixd, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultTransposeMatrixf, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultTransposeMatrixd, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbTransposeMatrix = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 05) GL_ARB_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMultisample() noexcept
{
	return g_ExistsGlArbMultisample;
}

namespace System
{
	PgglSampleCoverage gglSampleCoverageARB{ nullptr };
}

void System
	::GlSampleCoverageARB(GLclampf value, GLboolean invert) noexcept
{
	SYSTEM_BODY_2(gglSampleCoverageARB, value, invert);
}

void System
	::InitGlArbMultisample() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_multisample"))
	{
		g_ExistsGlArbMultisample = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglSampleCoverage, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbMultisample = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 06) GL_ARB_texture_env_add

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureEnvAdd{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureEnvAdd() noexcept
{
	return g_ExistsGlArbTextureEnvAdd;
}

void System
	::InitGlArbTextureEnvAdd() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_env_add"))
	{
		g_ExistsGlArbTextureEnvAdd = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureEnvAdd = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 07) GL_ARB_texture_cube_map

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureCubeMap{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureCubeMap() noexcept
{
	return g_ExistsGlArbTextureCubeMap;
}

void System
	::InitGlArbTextureCubeMap() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_cube_map"))
	{
		g_ExistsGlArbTextureCubeMap = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureCubeMap = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 12) GL_ARB_texture_compression

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureCompression{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureCompression() noexcept
{
	return g_ExistsGlArbTextureCompression;
}

namespace System
{
	PgglCompressedTexImage3D gglCompressedTexImage3DARB{ nullptr };
	PgglCompressedTexImage2D gglCompressedTexImage2DARB{ nullptr };
	PgglCompressedTexImage1D gglCompressedTexImage1DARB{ nullptr };
	PgglCompressedTexSubImage3D gglCompressedTexSubImage3DARB{ nullptr };
	PgglCompressedTexSubImage2D gglCompressedTexSubImage2DARB{ nullptr };
	PgglCompressedTexSubImage1D gglCompressedTexSubImage1DARB{ nullptr };
	PgglGetCompressedTexImage gglGetCompressedTexImageARB{ nullptr };
}

void System
	::GlCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglCompressedTexImage1DARB, target, level, internalFormat, width, border, imageSize, data);
}

void System
	::GlCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_8(gglCompressedTexImage2DARB, target, level, internalFormat, width, height, border, imageSize, data);
}

void System
	::GlCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedTexImage3DARB, target, level, internalFormat, width, height, depth, border, imageSize, data);
}

void System
	::GlCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglCompressedTexSubImage1DARB, target, level, xOffset, width, format, imageSize, data);
}

void System
	::GlCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedTexSubImage2DARB, target, level, xOffset, yOffset, width, height, format, imageSize, data);
}

void System
	::GlCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data) noexcept
{
	SYSTEM_BODY_11(gglCompressedTexSubImage3DARB, target, level, xOffset, yOffset, zOffset, width, height, depth, format, imageSize, data);
}

void System
	::GlGetCompressedTexImageARB(GLenum target, GLint level, GLvoid* data) noexcept
{
	SYSTEM_BODY_3(gglGetCompressedTexImageARB, target, level, data);
}

void System
	::InitGlArbTextureCompression() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_compression"))
	{
		g_ExistsGlArbTextureCompression = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglCompressedTexImage3D, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCompressedTexImage2D, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCompressedTexImage1D, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCompressedTexSubImage3D, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCompressedTexSubImage2D, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCompressedTexSubImage1D, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetCompressedTexImage, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbTextureCompression = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 13) GL_ARB_texture_border_clamp

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureBorderClamp{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureBorderClamp() noexcept
{
	return g_ExistsGlArbTextureBorderClamp;
}

void System
	::InitGlArbTextureBorderClamp() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_border_clamp"))
	{
		g_ExistsGlArbTextureBorderClamp = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureBorderClamp = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 14) GL_ARB_point_parameters

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbPointParameters{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbPointParameters() noexcept
{
	return g_ExistsGlArbPointParameters;
}

namespace System
{
	PgglPointParameterf gglPointParameterfARB{ nullptr };
	PgglPointParameterfv gglPointParameterfvARB{ nullptr };
}

void System
	::GlPointParameterfARB(GLenum name, GLfloat param) noexcept
{
	SYSTEM_BODY_2(gglPointParameterfARB, name, param);
}

void System
	::GlPointParameterfvARB(GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_BODY_2(gglPointParameterfvARB, name, param);
}

void System
	::InitGlArbPointParameters() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_point_parameters"))
	{
		g_ExistsGlArbPointParameters = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglPointParameterf, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglPointParameterfv, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbPointParameters = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 15) GL_ARB_vertex_blend

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexBlend{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexBlend() noexcept
{
	return g_ExistsGlArbVertexBlend;
}

namespace System
{
	using PgglWeightbvARB = void (OPENGL_STDCALL*) (GLint, const GLbyte*);
	using PgglWeightsvARB = void (OPENGL_STDCALL*) (GLint, const GLshort*);
	using PgglWeightivARB = void (OPENGL_STDCALL*) (GLint, const GLint*);
	using PgglWeightfvARB = void (OPENGL_STDCALL*) (GLint, const GLfloat*);
	using PgglWeightdvARB = void (OPENGL_STDCALL*) (GLint, const GLdouble*);
	using PgglWeightubvARB = void (OPENGL_STDCALL*) (GLint, const GLubyte*);
	using PgglWeightusvARB = void (OPENGL_STDCALL*) (GLint, const GLushort*);
	using PgglWeightuivARB = void (OPENGL_STDCALL*) (GLint, const GLuint*);
	using PgglWeightPointerARB = void (OPENGL_STDCALL*) (GLint, GLenum, GLsizei, const GLvoid*);
	using PgglVertexBlendARB = void (OPENGL_STDCALL*) (GLint);
}

namespace System
{
	PgglWeightbvARB gglWeightbvARB{ nullptr };
	PgglWeightsvARB gglWeightsvARB{ nullptr };
	PgglWeightivARB gglWeightivARB{ nullptr };
	PgglWeightfvARB gglWeightfvARB{ nullptr };
	PgglWeightdvARB gglWeightdvARB{ nullptr };
	PgglWeightubvARB gglWeightubvARB{ nullptr };
	PgglWeightusvARB gglWeightusvARB{ nullptr };
	PgglWeightuivARB gglWeightuivARB{ nullptr };
	PgglWeightPointerARB gglWeightPointerARB{ nullptr };
	PgglVertexBlendARB gglVertexBlendARB{ nullptr };
}

void System
	::GlWeightbvARB(GLint size, const GLbyte* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightbvARB, size, weight);
}

void System
	::GlWeightsvARB(GLint size, const GLshort* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightsvARB, size, weight);
}

void System
	::GlWeightivARB(GLint size, const GLint* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightivARB, size, weight);
}

void System
	::GlWeightfvARB(GLint size, const GLfloat* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightfvARB, size, weight);
}

void System
	::GlWeightdvARB(GLint size, const GLdouble* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightdvARB, size, weight);
}

void System
	::GlWeightubvARB(GLint size, const GLubyte* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightubvARB, size, weight);
}

void System
	::GlWeightusvARB(GLint size, const GLushort* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightusvARB, size, weight);
}

void System
	::GlWeightuivARB(GLint size, const GLuint* weight) noexcept
{
	SYSTEM_BODY_2(gglWeightuivARB, size, weight);
}

void System
	::GlWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_4(gglWeightPointerARB, size, type, stride, pointer);
}

void System
	::GlVertexBlendARB(GLint count) noexcept
{
	SYSTEM_BODY_1(gglVertexBlendARB, count);
}

void System
	::InitGlArbVertexBlend() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_blend"))
	{
		g_ExistsGlArbVertexBlend = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglWeightbvARB);
		SYSTEM_GET_FUNCTION(gglWeightsvARB);
		SYSTEM_GET_FUNCTION(gglWeightivARB);
		SYSTEM_GET_FUNCTION(gglWeightfvARB);
		SYSTEM_GET_FUNCTION(gglWeightdvARB);
		SYSTEM_GET_FUNCTION(gglWeightubvARB);
		SYSTEM_GET_FUNCTION(gglWeightusvARB);
		SYSTEM_GET_FUNCTION(gglWeightuivARB);
		SYSTEM_GET_FUNCTION(gglWeightPointerARB);
		SYSTEM_GET_FUNCTION(gglVertexBlendARB);
	}
	else
	{
		g_ExistsGlArbVertexBlend = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 16) GL_ARB_matrix_palette

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMatrixPalette{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMatrixPalette() noexcept
{
	return g_ExistsGlArbMatrixPalette;
}

namespace System
{
	using PgglCurrentPaletteMatrixARB = void (OPENGL_STDCALL*) (GLint);
	using PgglMatrixIndexubvARB = void (OPENGL_STDCALL*) (GLint, const GLubyte*);
	using PgglMatrixIndexusvARB = void (OPENGL_STDCALL*) (GLint, const GLushort*);
	using PgglMatrixIndexuivARB = void (OPENGL_STDCALL*) (GLint, const GLuint*);
	using PgglMatrixIndexPointerARB = void (OPENGL_STDCALL*) (GLint, GLenum, GLsizei, const GLvoid*);
}

namespace System
{
	PgglCurrentPaletteMatrixARB gglCurrentPaletteMatrixARB{ nullptr };
	PgglMatrixIndexubvARB gglMatrixIndexubvARB{ nullptr };
	PgglMatrixIndexusvARB gglMatrixIndexusvARB{ nullptr };
	PgglMatrixIndexuivARB gglMatrixIndexuivARB{ nullptr };
	PgglMatrixIndexPointerARB gglMatrixIndexPointerARB{ nullptr };
}

void System
	::GlCurrentPaletteMatrixARB(GLint index) noexcept
{
	SYSTEM_BODY_1(gglCurrentPaletteMatrixARB, index);
}

void System
	::GlMatrixIndexubvARB(GLint size, const GLubyte* index) noexcept
{
	SYSTEM_BODY_2(gglMatrixIndexubvARB, size, index);
}

void System
	::GlMatrixIndexusvARB(GLint size, const GLushort* index) noexcept
{
	SYSTEM_BODY_2(gglMatrixIndexusvARB, size, index);
}

void System
	::GlMatrixIndexuivARB(GLint size, const GLuint* index) noexcept
{
	SYSTEM_BODY_2(gglMatrixIndexuivARB, size, index);
}

void System
	::GlMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_4(gglMatrixIndexPointerARB, size, type, stride, pointer);
}

void System
	::InitGlArbMatrixPalette() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_matrix_palette"))
	{
		g_ExistsGlArbMatrixPalette = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCurrentPaletteMatrixARB);
		SYSTEM_GET_FUNCTION(gglMatrixIndexubvARB);
		SYSTEM_GET_FUNCTION(gglMatrixIndexusvARB);
		SYSTEM_GET_FUNCTION(gglMatrixIndexuivARB);
		SYSTEM_GET_FUNCTION(gglMatrixIndexPointerARB);
	}
	else
	{
		g_ExistsGlArbMatrixPalette = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 17) GL_ARB_texture_env_combine

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureEnvCombine{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureEnvCombine() noexcept
{
	return g_ExistsGlArbTextureEnvCombine;
}

void System
	::InitGlArbTextureEnvCombine() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_env_combine"))
	{
		g_ExistsGlArbTextureEnvCombine = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureEnvCombine = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 18) GL_ARB_texture_env_crossbar

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureEnvCrossbar{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureEnvCrossbar() noexcept
{
	return g_ExistsGlArbTextureEnvCrossbar;
}

void System
	::InitGlArbTextureEnvCrossbar() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_env_crossbar"))
	{
		g_ExistsGlArbTextureEnvCrossbar = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureEnvCrossbar = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 19) GL_ARB_texture_env_dot3

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureEnvDot3{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureEnvDot3() noexcept
{
	return g_ExistsGlArbTextureEnvDot3;
}

void System
	::InitGlArbTextureEnvDot3() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_env_dot3"))
	{
		g_ExistsGlArbTextureEnvDot3 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureEnvDot3 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 21) GL_ARB_texture_mirrored_repeat

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureMirroredRepeat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureMirroredRepeat() noexcept
{
	return g_ExistsGlArbTextureMirroredRepeat;
}

void System
	::InitGlArbTextureMirroredRepeat() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_mirrored_repeat"))
	{
		g_ExistsGlArbTextureMirroredRepeat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureMirroredRepeat = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 22) GL_ARB_depth_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDepthTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDepthTexture() noexcept
{
	return g_ExistsGlArbDepthTexture;
}

void System
	::InitGlArbDepthTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_depth_texture"))
	{
		g_ExistsGlArbDepthTexture = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbDepthTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 23) GL_ARB_shadow

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShadow{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShadow() noexcept
{
	return g_ExistsGlArbShadow;
}

void System
	::InitGlArbShadow() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shadow"))
	{
		g_ExistsGlArbShadow = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShadow = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 24) GL_ARB_shadow_ambient

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShadowAmbient{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShadowAmbient() noexcept
{
	return g_ExistsGlArbShadowAmbient;
}

void System
	::InitGlArbShadowAmbient() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shadow_ambient"))
	{
		g_ExistsGlArbShadowAmbient = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShadowAmbient = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 25) GL_ARB_window_pos

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbWindowPos{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbWindowPos() noexcept
{
	return g_ExistsGlArbWindowPos;
}

namespace System
{
	PgglWindowPos2d gglWindowPos2dARB{ nullptr };
	PgglWindowPos2dv gglWindowPos2dvARB{ nullptr };
	PgglWindowPos2f gglWindowPos2fARB{ nullptr };
	PgglWindowPos2fv gglWindowPos2fvARB{ nullptr };
	PgglWindowPos2i gglWindowPos2iARB{ nullptr };
	PgglWindowPos2iv gglWindowPos2ivARB{ nullptr };
	PgglWindowPos2s gglWindowPos2sARB{ nullptr };
	PgglWindowPos2sv gglWindowPos2svARB{ nullptr };
	PgglWindowPos3d gglWindowPos3dARB{ nullptr };
	PgglWindowPos3dv gglWindowPos3dvARB{ nullptr };
	PgglWindowPos3f gglWindowPos3fARB{ nullptr };
	PgglWindowPos3fv gglWindowPos3fvARB{ nullptr };
	PgglWindowPos3i gglWindowPos3iARB{ nullptr };
	PgglWindowPos3iv gglWindowPos3ivARB{ nullptr };
	PgglWindowPos3s gglWindowPos3sARB{ nullptr };
	PgglWindowPos3sv gglWindowPos3svARB{ nullptr };
}

void System
	::GlWindowPos2dARB(GLdouble x, GLdouble y) noexcept
{
	SYSTEM_BODY_2(gglWindowPos2dARB, x, y);
}

void System
	::GlWindowPos2dvARB(const GLdouble* xy) noexcept
{
	SYSTEM_BODY_1(gglWindowPos2dvARB, xy);
}

void System
	::GlWindowPos2fARB(GLfloat x, GLfloat y) noexcept
{
	SYSTEM_BODY_2(gglWindowPos2fARB, x, y);
}

void System
	::GlWindowPos2fvARB(const GLfloat* xy) noexcept
{
	SYSTEM_BODY_1(gglWindowPos2fvARB, xy);
}

void System
	::GlWindowPos2iARB(GLint x, GLint y) noexcept
{
	SYSTEM_BODY_2(gglWindowPos2iARB, x, y);
}

void System
	::GlWindowPos2ivARB(const GLint* xy) noexcept
{
	SYSTEM_BODY_1(gglWindowPos2ivARB, xy);
}

void System
	::GlWindowPos2sARB(GLshort x, GLshort y) noexcept
{
	SYSTEM_BODY_2(gglWindowPos2sARB, x, y);
}

void System
	::GlWindowPos2svARB(const GLshort* xy) noexcept
{
	SYSTEM_BODY_1(gglWindowPos2svARB, xy);
}

void System
	::GlWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_3(gglWindowPos3dARB, x, y, z);
}

void System
	::GlWindowPos3dvARB(const GLdouble* xyz) noexcept
{
	SYSTEM_BODY_1(gglWindowPos3dvARB, xyz);
}

void System
	::GlWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_3(gglWindowPos3fARB, x, y, z);
}

void System
	::GlWindowPos3fvARB(const GLfloat* xyz) noexcept
{
	SYSTEM_BODY_1(gglWindowPos3fvARB, xyz);
}

void System
	::GlWindowPos3iARB(GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_BODY_3(gglWindowPos3iARB, x, y, z);
}

void System
	::GlWindowPos3ivARB(const GLint* xyz) noexcept
{
	SYSTEM_BODY_1(gglWindowPos3ivARB, xyz);
}

void System
	::GlWindowPos3sARB(GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_BODY_3(gglWindowPos3sARB, x, y, z);
}

void System
	::GlWindowPos3svARB(const GLshort* xyz) noexcept
{
	SYSTEM_BODY_1(gglWindowPos3svARB, xyz);
}

void System
	::InitGlArbWindowPos() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_window_pos"))
	{
		g_ExistsGlArbWindowPos = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos2sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglWindowPos3sv, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbWindowPos = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 26) GL_ARB_vertex_program

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexProgram{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexProgram() noexcept
{
	return g_ExistsGlArbVertexProgram;
}

namespace System
{
	using PgglBindProgramARB = void (OPENGL_STDCALL*) (GLenum, GLuint);
	using PgglDeleteProgramsARB = void (OPENGL_STDCALL*) (GLsizei, const GLuint*);
	using PgglGenProgramsARB = void (OPENGL_STDCALL*) (GLsizei, GLuint*);
	using PgglGetProgramEnvParameterdvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLdouble*);
	using PgglGetProgramEnvParameterfvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLfloat*);
	using PgglGetProgramLocalParameterdvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLdouble*);
	using PgglGetProgramLocalParameterfvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLfloat*);
	using PgglGetProgramStringARB = void (OPENGL_STDCALL*) (GLenum, GLenum, GLvoid*);
	using PgglProgramEnvParameter4dARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	using PgglProgramEnvParameter4dvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, const GLdouble*);
	using PgglProgramEnvParameter4fARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	using PgglProgramEnvParameter4fvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, const GLfloat*);
	using PgglProgramLocalParameter4dARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
	using PgglProgramLocalParameter4dvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, const GLdouble*);
	using PgglProgramLocalParameter4fARB = void (OPENGL_STDCALL*) (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
	using PgglProgramLocalParameter4fvARB = void (OPENGL_STDCALL*) (GLenum, GLuint, const GLfloat*);
	using PgglProgramStringARB = void (OPENGL_STDCALL*) (GLenum, GLenum, GLsizei, const GLvoid*);
}

namespace System
{
	PgglBindProgramARB gglBindProgramARB{ nullptr };
	PgglDeleteProgramsARB gglDeleteProgramsARB{ nullptr };
	PgglGenProgramsARB gglGenProgramsARB{ nullptr };
	PgglGetProgramEnvParameterdvARB gglGetProgramEnvParameterdvARB{ nullptr };
	PgglGetProgramEnvParameterfvARB gglGetProgramEnvParameterfvARB{ nullptr };
	PgglGetProgramLocalParameterdvARB gglGetProgramLocalParameterdvARB{ nullptr };
	PgglGetProgramLocalParameterfvARB gglGetProgramLocalParameterfvARB{ nullptr };
	PgglGetProgramStringARB gglGetProgramStringARB{ nullptr };
	PgglProgramEnvParameter4dARB gglProgramEnvParameter4dARB{ nullptr };
	PgglProgramEnvParameter4dvARB gglProgramEnvParameter4dvARB{ nullptr };
	PgglProgramEnvParameter4fARB gglProgramEnvParameter4fARB{ nullptr };
	PgglProgramEnvParameter4fvARB gglProgramEnvParameter4fvARB{ nullptr };
	PgglProgramLocalParameter4dARB gglProgramLocalParameter4dARB{ nullptr };
	PgglProgramLocalParameter4dvARB gglProgramLocalParameter4dvARB{ nullptr };
	PgglProgramLocalParameter4fARB gglProgramLocalParameter4fARB{ nullptr };
	PgglProgramLocalParameter4fvARB gglProgramLocalParameter4fvARB{ nullptr };
	PgglProgramStringARB gglProgramStringARB{ nullptr };

	PgglDisableVertexAttribArray gglDisableVertexAttribArrayARB{ nullptr };
	PgglEnableVertexAttribArray gglEnableVertexAttribArrayARB{ nullptr };
	PgglGetProgramiv gglGetProgramivARB{ nullptr };
	PgglGetVertexAttribdv gglGetVertexAttribdvARB{ nullptr };
	PgglGetVertexAttribfv gglGetVertexAttribfvARB{ nullptr };
	PgglGetVertexAttribiv gglGetVertexAttribivARB{ nullptr };
	PgglGetVertexAttribPointerv gglGetVertexAttribPointervARB{ nullptr };
	PgglIsProgram gglIsProgramARB{ nullptr };
	PgglVertexAttrib1d gglVertexAttrib1dARB{ nullptr };
	PgglVertexAttrib1dv gglVertexAttrib1dvARB{ nullptr };
	PgglVertexAttrib1f gglVertexAttrib1fARB{ nullptr };
	PgglVertexAttrib1fv gglVertexAttrib1fvARB{ nullptr };
	PgglVertexAttrib1s gglVertexAttrib1sARB{ nullptr };
	PgglVertexAttrib1sv gglVertexAttrib1svARB{ nullptr };
	PgglVertexAttrib2d gglVertexAttrib2dARB{ nullptr };
	PgglVertexAttrib2dv gglVertexAttrib2dvARB{ nullptr };
	PgglVertexAttrib2f gglVertexAttrib2fARB{ nullptr };
	PgglVertexAttrib2fv gglVertexAttrib2fvARB{ nullptr };
	PgglVertexAttrib2s gglVertexAttrib2sARB{ nullptr };
	PgglVertexAttrib2sv gglVertexAttrib2svARB{ nullptr };
	PgglVertexAttrib3d gglVertexAttrib3dARB{ nullptr };
	PgglVertexAttrib3dv gglVertexAttrib3dvARB{ nullptr };
	PgglVertexAttrib3f gglVertexAttrib3fARB{ nullptr };
	PgglVertexAttrib3fv gglVertexAttrib3fvARB{ nullptr };
	PgglVertexAttrib3s gglVertexAttrib3sARB{ nullptr };
	PgglVertexAttrib3sv gglVertexAttrib3svARB{ nullptr };
	PgglVertexAttrib4Nbv gglVertexAttrib4NbvARB{ nullptr };
	PgglVertexAttrib4Niv gglVertexAttrib4NivARB{ nullptr };
	PgglVertexAttrib4Nsv gglVertexAttrib4NsvARB{ nullptr };
	PgglVertexAttrib4Nub gglVertexAttrib4NubARB{ nullptr };
	PgglVertexAttrib4Nubv gglVertexAttrib4NubvARB{ nullptr };
	PgglVertexAttrib4Nuiv gglVertexAttrib4NuivARB{ nullptr };
	PgglVertexAttrib4Nusv gglVertexAttrib4NusvARB{ nullptr };
	PgglVertexAttrib4bv gglVertexAttrib4bvARB{ nullptr };
	PgglVertexAttrib4d gglVertexAttrib4dARB{ nullptr };
	PgglVertexAttrib4dv gglVertexAttrib4dvARB{ nullptr };
	PgglVertexAttrib4f gglVertexAttrib4fARB{ nullptr };
	PgglVertexAttrib4fv gglVertexAttrib4fvARB{ nullptr };
	PgglVertexAttrib4iv gglVertexAttrib4ivARB{ nullptr };
	PgglVertexAttrib4s gglVertexAttrib4sARB{ nullptr };
	PgglVertexAttrib4sv gglVertexAttrib4svARB{ nullptr };
	PgglVertexAttrib4ubv gglVertexAttrib4ubvARB{ nullptr };
	PgglVertexAttrib4uiv gglVertexAttrib4uivARB{ nullptr };
	PgglVertexAttrib4usv gglVertexAttrib4usvARB{ nullptr };
	PgglVertexAttribPointer gglVertexAttribPointerARB{ nullptr };
}

void System
	::GlBindProgramARB(GLenum target, GLuint program) noexcept
{
	SYSTEM_BODY_2(gglBindProgramARB, target, program);
}

void System
	::GlDeleteProgramsARB(GLsizei numPrograms, const GLuint* programs) noexcept
{
	SYSTEM_BODY_2(gglDeleteProgramsARB, numPrograms, programs);
}

void System
	::GlDisableVertexAttribArrayARB(GLuint index) noexcept
{
	SYSTEM_BODY_1(gglDisableVertexAttribArrayARB, index);
}

void System
	::GlEnableVertexAttribArrayARB(GLuint index) noexcept
{
	SYSTEM_BODY_1(gglEnableVertexAttribArrayARB, index);
}

void System
	::GlGenProgramsARB(GLsizei numPrograms, GLuint* programs) noexcept
{
	SYSTEM_BODY_2(gglGenProgramsARB, numPrograms, programs);
}

void System
	::GlGetProgramivARB(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetProgramivARB, target, name, param);
}

void System
	::GlGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble* param) noexcept
{
	SYSTEM_BODY_3(gglGetProgramEnvParameterdvARB, target, index, param);
}

void System
	::GlGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetProgramEnvParameterfvARB, target, index, param);
}

void System
	::GlGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble* param) noexcept
{
	SYSTEM_BODY_3(gglGetProgramLocalParameterdvARB, target, index, param);
}

void System
	::GlGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetProgramLocalParameterfvARB, target, index, param);
}

void System
	::GlGetProgramStringARB(GLenum target, GLenum name, GLvoid* programString) noexcept
{
	SYSTEM_BODY_3(gglGetProgramStringARB, target, name, programString);
}

void System
	::GlGetVertexAttribdvARB(GLuint index, GLenum name, GLdouble* param) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribdvARB, index, name, param);
}

void System
	::GlGetVertexAttribfvARB(GLuint index, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribfvARB, index, name, param);
}

void System
	::GlGetVertexAttribivARB(GLuint index, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribivARB, index, name, param);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetVertexAttribPointervARB(GLuint index, GLenum name, GLvoid** pointer) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribPointervARB, index, name, pointer);
}
#include STSTEM_WARNING_POP

GLboolean System
	::GlIsProgramARB(GLuint program) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsProgramARB, program, GLboolean, GL_FALSE);
}

void System
	::GlProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_6(gglProgramEnvParameter4dARB, target, index, x, y, z, w);
}

void System
	::GlProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble* xyzw) noexcept
{
	SYSTEM_BODY_3(gglProgramEnvParameter4dvARB, target, index, xyzw);
}

void System
	::GlProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_BODY_6(gglProgramEnvParameter4fARB, target, index, x, y, z, w);
}

void System
	::GlProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat* xyzw) noexcept
{
	SYSTEM_BODY_3(gglProgramEnvParameter4fvARB, target, index, xyzw);
}

void System
	::GlProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_6(gglProgramLocalParameter4dARB, target, index, x, y, z, w);
}

void System
	::GlProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble* xyzw) noexcept
{
	SYSTEM_BODY_3(gglProgramLocalParameter4dvARB, target, index, xyzw);
}

void System
	::GlProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_BODY_6(gglProgramLocalParameter4fARB, target, index, x, y, z, w);
}

void System
	::GlProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat* xyzw) noexcept
{
	SYSTEM_BODY_3(gglProgramLocalParameter4fvARB, target, index, xyzw);
}

void System
	::GlProgramStringARB(GLenum target, GLenum format, GLsizei length, const GLvoid* programString) noexcept
{
	SYSTEM_BODY_4(gglProgramStringARB, target, format, length, programString);
}

void System
	::GlVertexAttrib1dARB(GLuint index, GLdouble x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib1dARB, index, x);
}

void System
	::GlVertexAttrib1dvARB(GLuint index, const GLdouble* x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib1dvARB, index, x);
}

void System
	::GlVertexAttrib1fARB(GLuint index, GLfloat x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib1fARB, index, x);
}

void System
	::GlVertexAttrib1fvARB(GLuint index, const GLfloat* x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib1fvARB, index, x);
}

void System
	::GlVertexAttrib1sARB(GLuint index, GLshort x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib1sARB, index, x);
}

void System
	::GlVertexAttrib1svARB(GLuint index, const GLshort* x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib1svARB, index, x);
}

void System
	::GlVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttrib2dARB, index, x, y);
}

void System
	::GlVertexAttrib2dvARB(GLuint index, const GLdouble* xy) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib2dvARB, index, xy);
}

void System
	::GlVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttrib2fARB, index, x, y);
}

void System
	::GlVertexAttrib2fvARB(GLuint index, const GLfloat* xy) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib2fvARB, index, xy);
}

void System
	::GlVertexAttrib2sARB(GLuint index, GLshort x, GLshort y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttrib2sARB, index, x, y);
}

void System
	::GlVertexAttrib2svARB(GLuint index, const GLshort* xy) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib2svARB, index, xy);
}

void System
	::GlVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttrib3dARB, index, x, y, z);
}

void System
	::GlVertexAttrib3dvARB(GLuint index, const GLdouble* xyz) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib3dvARB, index, xyz);
}

void System
	::GlVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttrib3fARB, index, x, y, z);
}

void System
	::GlVertexAttrib3fvARB(GLuint index, const GLfloat* xyz) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib3fvARB, index, xyz);
}

void System
	::GlVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttrib3sARB, index, x, y, z);
}

void System
	::GlVertexAttrib3svARB(GLuint index, const GLshort* xyz) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib3svARB, index, xyz);
}

void System
	::GlVertexAttrib4NbvARB(GLuint index, const GLbyte* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4NbvARB, index, xyzw);
}

void System
	::GlVertexAttrib4NivARB(GLuint index, const GLint* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4NivARB, index, xyzw);
}

void System
	::GlVertexAttrib4NsvARB(GLuint index, const GLshort* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4NsvARB, index, xyzw);
}

void System
	::GlVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttrib4NubARB, index, x, y, z, w);
}

void System
	::GlVertexAttrib4NubvARB(GLuint index, const GLubyte* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4NubvARB, index, xyzw);
}

void System
	::GlVertexAttrib4NuivARB(GLuint index, const GLuint* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4NuivARB, index, xyzw);
}

void System
	::GlVertexAttrib4NusvARB(GLuint index, const GLushort* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4NusvARB, index, xyzw);
}

void System
	::GlVertexAttrib4bvARB(GLuint index, const GLbyte* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4bvARB, index, xyzw);
}

void System
	::GlVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttrib4dARB, index, x, y, z, w);
}

void System
	::GlVertexAttrib4dvARB(GLuint index, const GLdouble* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4dvARB, index, xyzw);
}

void System
	::GlVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttrib4fARB, index, x, y, z, w);
}

void System
	::GlVertexAttrib4fvARB(GLuint index, const GLfloat* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4fvARB, index, xyzw);
}

void System
	::GlVertexAttrib4ivARB(GLuint index, const GLint* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4ivARB, index, xyzw);
}

void System
	::GlVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttrib4sARB, index, x, y, z, w);
}

void System
	::GlVertexAttrib4svARB(GLuint index, const GLshort* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4svARB, index, xyzw);
}

void System
	::GlVertexAttrib4ubvARB(GLuint index, const GLubyte* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4ubvARB, index, xyzw);
}

void System
	::GlVertexAttrib4uivARB(GLuint index, const GLuint* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4uivARB, index, xyzw);
}

void System
	::GlVertexAttrib4usvARB(GLuint index, const GLushort* xyzw) noexcept
{
	SYSTEM_BODY_2(gglVertexAttrib4usvARB, index, xyzw);
}

void System
	::GlVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_6(gglVertexAttribPointerARB, index, size, type, normalized, stride, pointer);
}

void System
	::InitGlArbVertexProgram() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_program"))
	{
		g_ExistsGlArbVertexProgram = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindProgramARB);
		SYSTEM_GET_FUNCTION(gglDeleteProgramsARB);
		SYSTEM_GET_FUNCTION(gglGenProgramsARB);
		SYSTEM_GET_FUNCTION(gglGetProgramEnvParameterdvARB);
		SYSTEM_GET_FUNCTION(gglGetProgramEnvParameterfvARB);
		SYSTEM_GET_FUNCTION(gglGetProgramLocalParameterdvARB);
		SYSTEM_GET_FUNCTION(gglGetProgramLocalParameterfvARB);
		SYSTEM_GET_FUNCTION(gglGetProgramStringARB);
		SYSTEM_GET_FUNCTION(gglProgramEnvParameter4dARB);
		SYSTEM_GET_FUNCTION(gglProgramEnvParameter4dvARB);
		SYSTEM_GET_FUNCTION(gglProgramEnvParameter4fARB);
		SYSTEM_GET_FUNCTION(gglProgramEnvParameter4fvARB);
		SYSTEM_GET_FUNCTION(gglProgramLocalParameter4dARB);
		SYSTEM_GET_FUNCTION(gglProgramLocalParameter4dvARB);
		SYSTEM_GET_FUNCTION(gglProgramLocalParameter4fARB);
		SYSTEM_GET_FUNCTION(gglProgramLocalParameter4fvARB);
		SYSTEM_GET_FUNCTION(gglProgramStringARB);

		SYSTEM_GET_FUNCTION_SUFFIX(gglDisableVertexAttribArray, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglEnableVertexAttribArray, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetProgramiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetVertexAttribdv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetVertexAttribfv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetVertexAttribiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetVertexAttribPointerv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglIsProgram, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib1d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib1dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib1f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib1fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib1s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib1sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib2d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib2dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib2f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib2fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib2s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib2sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib3d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib3dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib3f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib3fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib3s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib3sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Nbv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Niv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Nsv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Nub, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Nubv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Nuiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4Nusv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4bv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4d, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4dv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4s, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4sv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4ubv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4uiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttrib4usv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglVertexAttribPointer, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbVertexProgram = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 27) GL_ARB_fragment_program

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFragmentProgram{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFragmentProgram() noexcept
{
	return g_ExistsGlArbFragmentProgram;
}

void System
	::InitGlArbFragmentProgram() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_fragment_program"))
	{
		g_ExistsGlArbFragmentProgram = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbFragmentProgram = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 28) GL_ARB_vertex_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexBufferObject() noexcept
{
	return g_ExistsGlArbVertexBufferObject;
}

namespace System
{
	PgglBindBuffer gglBindBufferARB{ nullptr };
	PgglDeleteBuffers gglDeleteBuffersARB{ nullptr };
	PgglGenBuffers gglGenBuffersARB{ nullptr };
	PgglIsBuffer gglIsBufferARB{ nullptr };
	PgglBufferData gglBufferDataARB{ nullptr };
	PgglBufferSubData gglBufferSubDataARB{ nullptr };
	PgglGetBufferSubData gglGetBufferSubDataARB{ nullptr };
	PgglMapBuffer gglMapBufferARB{ nullptr };
	PgglUnmapBuffer gglUnmapBufferARB{ nullptr };
	PgglGetBufferParameteriv gglGetBufferParameterivARB{ nullptr };
	PgglGetBufferPointerv gglGetBufferPointervARB{ nullptr };
}

void System
	::GlBindBufferARB(GLenum target, GLuint buffer) noexcept
{
	SYSTEM_BODY_2(gglBindBufferARB, target, buffer);
}

void System
	::GlDeleteBuffersARB(GLsizei numBuffers, const GLuint* buffer) noexcept
{
	SYSTEM_BODY_2(gglDeleteBuffersARB, numBuffers, buffer);
}

void System
	::GlGenBuffersARB(GLsizei numBuffers, GLuint* buffer) noexcept
{
	SYSTEM_BODY_2(gglGenBuffersARB, numBuffers, buffer);
}

GLboolean System
	::GlIsBufferARB(GLuint buffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsBufferARB, buffer, GLboolean, GL_FALSE);
}

void System
	::GlBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid* data, GLenum usage) noexcept
{
	SYSTEM_BODY_4(gglBufferDataARB, target, size, data, usage);
}

void System
	::GlBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid* data) noexcept
{
	SYSTEM_BODY_4(gglBufferSubDataARB, target, offset, size, data);
}

void System
	::GlGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid* data) noexcept
{
	SYSTEM_BODY_4(gglGetBufferSubDataARB, target, offset, size, data);
}

GLvoid* System
	::GlMapBufferARB(GLenum target, GLenum access) noexcept
{
	SYSTEM_BODY_2_RESULT(gglMapBufferARB, target, access, GLvoid*, nullptr);
}

GLboolean System
	::GlUnmapBufferARB(GLenum target) noexcept
{
	SYSTEM_BODY_1_RESULT(gglUnmapBufferARB, target, GLboolean, GL_FALSE);
}

void System
	::GlGetBufferParameterivARB(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetBufferParameterivARB, target, name, param);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetBufferPointervARB(GLenum target, GLenum name, GLvoid** param) noexcept
{
	SYSTEM_BODY_3(gglGetBufferPointervARB, target, name, param);
}
#include STSTEM_WARNING_POP

void System
	::InitGlArbVertexBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_buffer_object"))
	{
		g_ExistsGlArbVertexBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBindBuffer, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglDeleteBuffers, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGenBuffers, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglIsBuffer, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglBufferData, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglBufferSubData, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetBufferSubData, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMapBuffer, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUnmapBuffer, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetBufferParameteriv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetBufferPointerv, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbVertexBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 29) GL_ARB_occlusion_query

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbOcclusionQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbOcclusionQuery() noexcept
{
	return g_ExistsGlArbOcclusionQuery;
}

namespace System
{
	PgglGenQueries gglGenQueriesARB{ nullptr };
	PgglDeleteQueries gglDeleteQueriesARB{ nullptr };
	PgglIsQuery gglIsQueryARB{ nullptr };
	PgglBeginQuery gglBeginQueryARB{ nullptr };
	PgglEndQuery gglEndQueryARB{ nullptr };
	PgglGetQueryiv gglGetQueryivARB{ nullptr };
	PgglGetQueryObjectiv gglGetQueryObjectivARB{ nullptr };
	PgglGetQueryObjectuiv gglGetQueryObjectuivARB{ nullptr };
}

void System
	::GlGenQueriesARB(GLsizei numQueries, GLuint* id) noexcept
{
	SYSTEM_BODY_2(gglGenQueriesARB, numQueries, id);
}

void System
	::GlDeleteQueriesARB(GLsizei numQueries, const GLuint* id) noexcept
{
	SYSTEM_BODY_2(gglDeleteQueriesARB, numQueries, id);
}

GLboolean System
	::GlIsQueryARB(GLuint id) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsQueryARB, id, GLboolean, GL_FALSE);
}

void System
	::GlBeginQueryARB(GLenum target, GLuint id) noexcept
{
	SYSTEM_BODY_2(gglBeginQueryARB, target, id);
}

void System
	::GlEndQueryARB(GLenum target) noexcept
{
	SYSTEM_BODY_1(gglEndQueryARB, target);
}

void System
	::GlGetQueryivARB(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetQueryivARB, target, name, param);
}

void System
	::GlGetQueryObjectivARB(GLuint id, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetQueryObjectivARB, id, name, param);
}

void System
	::GlGetQueryObjectuivARB(GLuint id, GLenum name, GLuint* param) noexcept
{
	SYSTEM_BODY_3(gglGetQueryObjectuivARB, id, name, param);
}

void System
	::InitGlArbOcclusionQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_occlusion_query"))
	{
		g_ExistsGlArbOcclusionQuery = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglGenQueries, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglDeleteQueries, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglIsQuery, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglBeginQuery, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglEndQuery, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetQueryiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetQueryObjectiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetQueryObjectuiv, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbOcclusionQuery = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 29) GL_ARB_shader_objects

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderObjects{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderObjects() noexcept
{
	return g_ExistsGlArbShaderObjects;
}

namespace System
{
	using PgglGetHandleARB = GLhandleARB(OPENGL_STDCALL*) (GLenum);
	using PgglGetObjectParameterfvARB = void (OPENGL_STDCALL*) (GLhandleARB, GLenum, GLfloat*);
	using PgglGetObjectParameterivARB = void (OPENGL_STDCALL*) (GLhandleARB, GLenum, GLint*);
	using PgglAttachObject = void (OPENGL_STDCALL*) (GLhandleARB, GLhandleARB);
	using PgglCreateProgramObject = GLhandleARB(OPENGL_STDCALL*) ();
	using PgglCreateShaderObject = GLhandleARB(OPENGL_STDCALL*) (GLenum);
	using PgglDeleteObject = void (OPENGL_STDCALL*) (GLhandleARB);
	using PgglDetachObject = void (OPENGL_STDCALL*) (GLhandleARB, GLhandleARB);
	using PgglGetInfoLog = void (OPENGL_STDCALL*) (GLhandleARB, GLsizei, GLsizei*, GLcharARB*);
	using PgglGetAttachedObjects = void (OPENGL_STDCALL*) (GLhandleARB, GLsizei, GLsizei*, GLhandleARB*);
	using PgglUseProgramObject = void (OPENGL_STDCALL*) (GLhandleARB);
}

namespace System
{
	PgglGetHandleARB gglGetHandleARB{ nullptr };
	PgglGetObjectParameterfvARB gglGetObjectParameterfvARB{ nullptr };
	PgglGetObjectParameterivARB gglGetObjectParameterivARB{ nullptr };

	PgglAttachObject gglAttachObjectARB{ nullptr };
	PgglCreateProgramObject gglCreateProgramObjectARB{ nullptr };
	PgglCreateShaderObject gglCreateShaderObjectARB{ nullptr };
	PgglDeleteObject gglDeleteObjectARB{ nullptr };
	PgglDetachObject gglDetachObjectARB{ nullptr };
	PgglGetInfoLog gglGetInfoLogARB{ nullptr };
	PgglGetAttachedObjects gglGetAttachedObjectsARB{ nullptr };
	PgglUseProgramObject gglUseProgramObjectARB{ nullptr };

	PgglCompileShader gglCompileShaderARB{ nullptr };
	PgglGetActiveUniform gglGetActiveUniformARB{ nullptr };
	PgglGetUniformfv gglGetUniformfvARB{ nullptr };
	PgglGetUniformiv gglGetUniformivARB{ nullptr };
	PgglGetUniformLocation gglGetUniformLocationARB{ nullptr };
	PgglGetShaderSource gglGetShaderSourceARB{ nullptr };
	PgglLinkProgram gglLinkProgramARB{ nullptr };
	PgglShaderSource gglShaderSourceARB{ nullptr };
	PgglUniform1f gglUniform1fARB{ nullptr };
	PgglUniform2f gglUniform2fARB{ nullptr };
	PgglUniform3f gglUniform3fARB{ nullptr };
	PgglUniform4f gglUniform4fARB{ nullptr };
	PgglUniform1i gglUniform1iARB{ nullptr };
	PgglUniform2i gglUniform2iARB{ nullptr };
	PgglUniform3i gglUniform3iARB{ nullptr };
	PgglUniform4i gglUniform4iARB{ nullptr };
	PgglUniform1fv gglUniform1fvARB{ nullptr };
	PgglUniform2fv gglUniform2fvARB{ nullptr };
	PgglUniform3fv gglUniform3fvARB{ nullptr };
	PgglUniform4fv gglUniform4fvARB{ nullptr };
	PgglUniform1iv gglUniform1ivARB{ nullptr };
	PgglUniform2iv gglUniform2ivARB{ nullptr };
	PgglUniform3iv gglUniform3ivARB{ nullptr };
	PgglUniform4iv gglUniform4ivARB{ nullptr };
	PgglUniformMatrix2fv gglUniformMatrix2fvARB{ nullptr };
	PgglUniformMatrix3fv gglUniformMatrix3fvARB{ nullptr };
	PgglUniformMatrix4fv gglUniformMatrix4fvARB{ nullptr };
	PgglValidateProgram gglValidateProgramARB{ nullptr };
}

void System
	::GlAttachObjectARB(GLhandleARB container, GLhandleARB object) noexcept
{
	SYSTEM_BODY_2(gglAttachObjectARB, container, object);
}

void System
	::GlCompileShaderARB(GLhandleARB shader) noexcept
{
	SYSTEM_BODY_1(gglCompileShaderARB, shader);
}

GLhandleARB System
	::GlCreateProgramObjectARB() noexcept
{
	SYSTEM_BODY_0_RESULT(gglCreateProgramObjectARB, GLhandleARB, 0);
}

GLhandleARB System
	::GlCreateShaderObjectARB(GLenum type) noexcept
{
	SYSTEM_BODY_1_RESULT(gglCreateShaderObjectARB, type, GLhandleARB, 0);
}

void System
	::GlDeleteObjectARB(GLhandleARB object) noexcept
{
	SYSTEM_BODY_1(gglDeleteObjectARB, object);
}

void System
	::GlDetachObjectARB(GLhandleARB container, GLhandleARB object) noexcept
{
	SYSTEM_BODY_2(gglDetachObjectARB, container, object);
}

void System
	::GlGetActiveUniformARB(GLhandleARB program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name) noexcept
{
	SYSTEM_BODY_7(gglGetActiveUniformARB, program, index, maxLength, length, size, type, name);
}

void System
	::GlGetAttachedObjectsARB(GLhandleARB container, GLsizei maxCount, GLsizei* count, GLhandleARB* object) noexcept
{
	SYSTEM_BODY_4(gglGetAttachedObjectsARB, container, maxCount, count, object);
}

GLhandleARB System
	::GlGetHandleARB(GLenum name) noexcept
{
	SYSTEM_BODY_1_RESULT(gglGetHandleARB, name, GLhandleARB, 0);
}

void System
	::GlGetInfoLogARB(GLhandleARB object, GLsizei maxLength, GLsizei* length, GLcharARB* infoLog) noexcept
{
	SYSTEM_BODY_4(gglGetInfoLogARB, object, maxLength, length, infoLog);
}

void System
	::GlGetObjectParameterfvARB(GLhandleARB object, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetObjectParameterfvARB, object, name, param);
}

void System
	::GlGetObjectParameterivARB(GLhandleARB object, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetObjectParameterivARB, object, name, param);
}

void System
	::GlGetShaderSourceARB(GLhandleARB object, GLsizei maxLength, GLsizei* length, GLcharARB* source) noexcept
{
	SYSTEM_BODY_4(gglGetShaderSourceARB, object, maxLength, length, source);
}

GLint System
	::GlGetUniformLocationARB(GLhandleARB program, const GLcharARB* name) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetUniformLocationARB, program, name, GLint, -1);
}

void System
	::GlGetUniformfvARB(GLhandleARB program, GLint location, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetUniformfvARB, program, location, param);
}

void System
	::GlGetUniformivARB(GLhandleARB program, GLint location, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetUniformivARB, program, location, param);
}

void System
	::GlLinkProgramARB(GLhandleARB program) noexcept
{
	SYSTEM_BODY_1(gglLinkProgramARB, program);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlShaderSourceARB(GLhandleARB shader, GLsizei count, const GLcharARB** shaderString, const GLint* length) noexcept
{
	SYSTEM_BODY_4(gglShaderSourceARB, shader, count, shaderString, length);
}
#include STSTEM_WARNING_POP

void System
	::GlUniform1fARB(GLint location, GLfloat v0) noexcept
{
	SYSTEM_BODY_2(gglUniform1fARB, location, v0);
}

void System
	::GlUniform2fARB(GLint location, GLfloat v0, GLfloat v1) noexcept
{
	SYSTEM_BODY_3(gglUniform2fARB, location, v0, v1);
}

void System
	::GlUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept
{
	SYSTEM_BODY_4(gglUniform3fARB, location, v0, v1, v2);
}

void System
	::GlUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept
{
	SYSTEM_BODY_5(gglUniform4fARB, location, v0, v1, v2, v3);
}

void System
	::GlUniform1iARB(GLint location, GLint v0) noexcept
{
	SYSTEM_BODY_2(gglUniform1iARB, location, v0);
}

void System
	::GlUniform2iARB(GLint location, GLint v0, GLint v1) noexcept
{
	SYSTEM_BODY_3(gglUniform2iARB, location, v0, v1);
}

void System
	::GlUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) noexcept
{
	SYSTEM_BODY_4(gglUniform3iARB, location, v0, v1, v2);
}

void System
	::GlUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept
{
	SYSTEM_BODY_5(gglUniform4iARB, location, v0, v1, v2, v3);
}

void System
	::GlUniform1fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_3(gglUniform1fvARB, location, count, value);
}

void System
	::GlUniform2fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_3(gglUniform2fvARB, location, count, value);
}

void System
	::GlUniform3fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_3(gglUniform3fvARB, location, count, value);
}

void System
	::GlUniform4fvARB(GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_3(gglUniform4fvARB, location, count, value);
}

void System
	::GlUniform1ivARB(GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform1ivARB, location, count, value);
}

void System
	::GlUniform2ivARB(GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform2ivARB, location, count, value);
}

void System
	::GlUniform3ivARB(GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform3ivARB, location, count, value);
}

void System
	::GlUniform4ivARB(GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform4ivARB, location, count, value);
}

void System
	::GlUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix2fvARB, location, count, transpose, value);
}

void System
	::GlUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix3fvARB, location, count, transpose, value);
}

void System
	::GlUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix4fvARB, location, count, transpose, value);
}

void System
	::GlUseProgramObjectARB(GLhandleARB program) noexcept
{
	SYSTEM_BODY_1(gglUseProgramObjectARB, program);
}

void System
	::GlValidateProgramARB(GLhandleARB program) noexcept
{
	SYSTEM_BODY_1(gglValidateProgramARB, program);
}

void System
	::InitGlArbShaderObjects() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_objects"))
	{
		g_ExistsGlArbShaderObjects = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetHandleARB);
		SYSTEM_GET_FUNCTION(gglGetObjectParameterfvARB);
		SYSTEM_GET_FUNCTION(gglGetObjectParameterivARB);

		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglAttachObject, gglAttachShader, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglCreateProgramObject, gglCreateProgram, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglCreateShaderObject, gglCreateShader, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglDeleteObject, gglDeleteProgram, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglDeleteObject, gglDeleteShader, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglDetachObject, gglDetachShader, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglGetAttachedObjects, gglGetAttachedShaders, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglGetInfoLog, gglGetProgramInfoLog, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglGetInfoLog, gglGetShaderInfoLog, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX_ALT(gglUseProgramObject, gglUseProgram, ARB, g_SystemArbOverride);

		SYSTEM_GET_FUNCTION_SUFFIX(gglCompileShader, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetActiveUniform, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetShaderSource, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetUniformfv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetUniformiv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetUniformLocation, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglLinkProgram, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglShaderSource, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform1f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform2f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform3f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform4f, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform1i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform2i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform3i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform4i, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform1fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform2fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform3fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform4fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform1iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform2iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform3iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniform4iv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniformMatrix2fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniformMatrix3fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglUniformMatrix4fv, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglValidateProgram, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbShaderObjects = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 31) GL_ARB_vertex_shader

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexShader{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexShader() noexcept
{
	return g_ExistsGlArbVertexShader;
}

namespace System
{
	PgglBindAttribLocation gglBindAttribLocationARB{ nullptr };
	PgglGetActiveAttrib gglGetActiveAttribARB{ nullptr };
	PgglGetAttribLocation gglGetAttribLocationARB{ nullptr };
}

void System
	::GlBindAttribLocationARB(GLhandleARB program, GLuint index, const GLcharARB* name) noexcept
{
	SYSTEM_BODY_3(gglBindAttribLocationARB, program, index, name);
}

void System
	::GlGetActiveAttribARB(GLhandleARB program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLcharARB* name) noexcept
{
	SYSTEM_BODY_7(gglGetActiveAttribARB, program, index, maxLength, length, size, type, name);
}

GLint System
	::GlGetAttribLocationARB(GLhandleARB program, const GLcharARB* name) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetAttribLocationARB, program, name, GLint, -1);
}

void System
	::InitGlArbVertexShader() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_shader"))
	{
		g_ExistsGlArbVertexShader = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBindAttribLocation, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetActiveAttrib, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetAttribLocation, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbVertexShader = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 32) GL_ARB_fragment_shader

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFragmentShader{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFragmentShader() noexcept
{
	return g_ExistsGlArbFragmentShader;
}

void System
	::InitGlArbFragmentShader() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_fragment_shader"))
	{
		g_ExistsGlArbFragmentShader = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbFragmentShader = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 33) GL_ARB_shading_language_100

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShadingLanguage100{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShadingLanguage100() noexcept
{
	return g_ExistsGlArbShadingLanguage100;
}

void System
	::InitGlArbShadingLanguage100() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shading_language_100"))
	{
		g_ExistsGlArbShadingLanguage100 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShadingLanguage100 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 34) GL_ARB_texture_non_power_of_two

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureNonpowerOfTwo{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureNonpowerOfTwo() noexcept
{
	return g_ExistsGlArbTextureNonpowerOfTwo;
}

void System
	::InitGlArbTextureNonpowerOfTwo() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_non_power_of_two"))
	{
		g_ExistsGlArbTextureNonpowerOfTwo = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureNonpowerOfTwo = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 35) GL_ARB_point_sprite

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbPointSprite{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbPointSprite() noexcept
{
	return g_ExistsGlArbPointSprite;
}

void System
	::InitGlArbPointSprite() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_point_sprite"))
	{
		g_ExistsGlArbPointSprite = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbPointSprite = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 36) GL_ARB_fragment_program_shadow

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFragmentProgramShadow{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFragmentProgramShadow() noexcept
{
	return g_ExistsGlArbFragmentProgramShadow;
}

void System
	::InitGlArbFragmentProgramShadow() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_fragment_program_shadow"))
	{
		g_ExistsGlArbFragmentProgramShadow = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbFragmentProgramShadow = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 37) GL_ARB_draw_buffers

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDrawBuffers{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDrawBuffers() noexcept
{
	return g_ExistsGlArbDrawBuffers;
}

namespace System
{
	PgglDrawBuffers gglDrawBuffersARB{ nullptr };
}

void System
	::GlDrawBuffersARB(GLsizei numBuffers, const GLenum* buffer) noexcept
{
	SYSTEM_BODY_2(gglDrawBuffersARB, numBuffers, buffer);
}

void System
	::InitGlArbDrawBuffers() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_draw_buffers"))
	{
		g_ExistsGlArbDrawBuffers = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglDrawBuffers, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbDrawBuffers = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 38) GL_ARB_texture_rectangle

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureRectangle{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureRectangle() noexcept
{
	return g_ExistsGlArbTextureRectangle;
}

void System
	::InitGlArbTextureRectangle() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_rectangle"))
	{
		g_ExistsGlArbTextureRectangle = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureRectangle = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 39) GL_ARB_color_buffer_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbColorBufferFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbColorBufferFloat() noexcept
{
	return g_ExistsGlArbColorBufferFloat;
}

namespace System
{
	using PgglClampColorARB = void (OPENGL_STDCALL*) (GLenum, GLenum);
}

namespace System
{
	PgglClampColorARB gglClampColorARB{ nullptr };
}

void System
	::GlClampColorARB(GLenum target, GLenum clamp) noexcept
{
	SYSTEM_BODY_2(gglClampColorARB, target, clamp);
}

void System
	::InitGlArbColorBufferFloat() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_color_buffer_float"))
	{
		g_ExistsGlArbColorBufferFloat = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglClampColorARB);
	}
	else
	{
		g_ExistsGlArbColorBufferFloat = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 40) GL_ARB_half_float_pixel

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbHalfFloatPixel{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbHalfFloatPixel() noexcept
{
	return g_ExistsGlArbHalfFloatPixel;
}

void System
	::InitGlArbHalfFloatPixel() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_half_float_pixel"))
	{
		g_ExistsGlArbHalfFloatPixel = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbHalfFloatPixel = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 41) GL_ARB_texture_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureFloat() noexcept
{
	return g_ExistsGlArbTextureFloat;
}

void System
	::InitGlArbTextureFloat() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_float"))
	{
		g_ExistsGlArbTextureFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureFloat = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 42) GL_ARB_pixel_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbPixelBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbPixelBufferObject() noexcept
{
	return g_ExistsGlArbPixelBufferObject;
}

void System
	::InitGlArbPixelBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_pixel_buffer_object"))
	{
		g_ExistsGlArbPixelBufferObject = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbPixelBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 43) GL_ARB_depth_buffer_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDepthBufferFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDepthBufferFloat() noexcept
{
	return g_ExistsGlArbDepthBufferFloat;
}

void System
	::InitGlArbDepthBufferFloat() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_depth_buffer_float"))
	{
		g_ExistsGlArbDepthBufferFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbDepthBufferFloat = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 44) GL_ARB_draw_instanced

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDrawInstanced{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDrawInstanced() noexcept
{
	return g_ExistsGlArbDrawInstanced;
}

void System
	::InitGlArbDrawInstanced() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_draw_instanced"))
	{
		g_ExistsGlArbDrawInstanced = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbDrawInstanced = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 45) GL_ARB_framebuffer_object
namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFramebufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFramebufferObject() noexcept
{
	return g_ExistsGlArbFramebufferObject;
}

namespace System
{
	using PgglBindFramebuffer = void (OPENGL_STDCALL*) (GLenum target, GLuint framebuffer);
	using PgglBindRenderbuffer = void (OPENGL_STDCALL*) (GLenum target, GLuint renderbuffer);
	using PgglBlitFramebuffer = void (OPENGL_STDCALL*) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0,
		GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	using PgglCheckFramebufferStatus = GLenum(OPENGL_STDCALL*) (GLenum target);
	using PgglDeleteFramebuffers = void (OPENGL_STDCALL*) (GLsizei n, const GLuint* framebuffers);
	using PgglDeleteRenderbuffers = void (OPENGL_STDCALL*) (GLsizei n, const GLuint* renderbuffers);
	using PgglFramebufferRenderbuffer = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	using PgglFramebufferTexture1D = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PgglFramebufferTexture2D = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PgglFramebufferTexture3D = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);
	using PgglFramebufferTextureLayer = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	using PgglGenFramebuffers = void (OPENGL_STDCALL*) (GLsizei n, GLuint* framebuffers);
	using PgglGenRenderbuffers = void (OPENGL_STDCALL*) (GLsizei n, GLuint* renderbuffers);
	using PgglGenerateMipmap = void (OPENGL_STDCALL*) (GLenum target);
	using PgglGetFramebufferAttachmentParameteriv = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLenum parameterName, GLint* params);
	using PgglGetRenderbufferParameteriv = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, GLint* params);
	using PgglIsFramebuffer = GLboolean(OPENGL_STDCALL*) (GLuint framebuffer);
	using PgglIsRenderbuffer = GLboolean(OPENGL_STDCALL*) (GLuint renderbuffer);
	using PgglRenderbufferStorage = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglRenderbufferStorageMultisample = void (OPENGL_STDCALL*) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
}

namespace System
{
	PgglBindFramebuffer gglBindFramebuffer{ nullptr };
	PgglBindRenderbuffer gglBindRenderbuffer{ nullptr };
	PgglBlitFramebuffer gglBlitFramebuffer{ nullptr };
	PgglCheckFramebufferStatus gglCheckFramebufferStatus{ nullptr };
	PgglDeleteFramebuffers gglDeleteFramebuffers{ nullptr };
	PgglDeleteRenderbuffers gglDeleteRenderbuffers{ nullptr };
	PgglFramebufferRenderbuffer gglFramebufferRenderbuffer{ nullptr };
	PgglFramebufferTexture1D gglFramebufferTexture1D{ nullptr };
	PgglFramebufferTexture2D gglFramebufferTexture2D{ nullptr };
	PgglFramebufferTexture3D gglFramebufferTexture3D{ nullptr };
	PgglFramebufferTextureLayer gglFramebufferTextureLayer{ nullptr };
	PgglGenFramebuffers gglGenFramebuffers{ nullptr };
	PgglGenRenderbuffers gglGenRenderbuffers{ nullptr };
	PgglGenerateMipmap gglGenerateMipmap{ nullptr };
	PgglGetFramebufferAttachmentParameteriv gglGetFramebufferAttachmentParameteriv{ nullptr };
	PgglGetRenderbufferParameteriv gglGetRenderbufferParameteriv{ nullptr };
	PgglIsFramebuffer gglIsFramebuffer{ nullptr };
	PgglIsRenderbuffer gglIsRenderbuffer{ nullptr };
	PgglRenderbufferStorage gglRenderbufferStorage{ nullptr };
	PgglRenderbufferStorageMultisample gglRenderbufferStorageMultisample{ nullptr };
}

void System
	::GlBindFramebuffer(GLenum target, GLuint framebuffer) noexcept
{
	SYSTEM_BODY_2(gglBindFramebuffer, target, framebuffer);
}

void System
	::GlBindRenderbuffer(GLenum target, GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_2(gglBindRenderbuffer, target, renderbuffer);
}

void System
	::GlBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
	SYSTEM_BODY_10(gglBlitFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLenum System
	::GlCheckFramebufferStatus(GLenum target) noexcept
{
	SYSTEM_BODY_1_RESULT(gglCheckFramebufferStatus, target, GLenum, 0);
}

void System
	::GlDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) noexcept
{
	SYSTEM_BODY_2(gglDeleteFramebuffers, n, framebuffers);
}

void System
	::GlDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) noexcept
{
	SYSTEM_BODY_2(gglDeleteRenderbuffers, n, renderbuffers);
}

void System
	::GlFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_4(gglFramebufferRenderbuffer, target, attachment, renderbuffertarget, renderbuffer);
}

void System
	::GlFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTexture1D, target, attachment, textarget, texture, level);
}

void System
	::GlFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTexture2D, target, attachment, textarget, texture, level);
}

void System
	::GlFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer) noexcept
{
	SYSTEM_BODY_6(gglFramebufferTexture3D, target, attachment, textarget, texture, level, layer);
}

void System
	::GlFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTextureLayer, target, attachment, texture, level, layer);
}

void System
	::GlGenFramebuffers(GLsizei n, GLuint* framebuffers) noexcept
{
	SYSTEM_BODY_2(gglGenFramebuffers, n, framebuffers);
}

void System
	::GlGenRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept
{
	SYSTEM_BODY_2(gglGenRenderbuffers, n, renderbuffers);
}

void System
	::GlGenerateMipmap(GLenum target) noexcept
{
	SYSTEM_BODY_1(gglGenerateMipmap, target);
}

void System
	::GlGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetFramebufferAttachmentParameteriv, target, attachment, parameterName, params);
}

void System
	::GlGetRenderbufferParameteriv(GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetRenderbufferParameteriv, target, parameterName, params);
}

GLboolean System
	::GlIsFramebuffer(GLuint framebuffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsFramebuffer, framebuffer, GLboolean, GL_FALSE);
}

GLboolean System
	::GlIsRenderbuffer(GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsRenderbuffer, renderbuffer, GLboolean, GL_FALSE);
}

void System
	::GlRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_4(gglRenderbufferStorage, target, internalformat, width, height);
}

void System
	::GlRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglRenderbufferStorageMultisample, target, samples, internalformat, width, height);
}

void System
	::InitGlArbFramebufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_framebuffer_object"))
	{
		g_ExistsGlArbFramebufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindFramebuffer);
		SYSTEM_GET_FUNCTION(gglBindRenderbuffer);
		SYSTEM_GET_FUNCTION(gglBlitFramebuffer);
		SYSTEM_GET_FUNCTION(gglCheckFramebufferStatus);
		SYSTEM_GET_FUNCTION(gglDeleteFramebuffers);
		SYSTEM_GET_FUNCTION(gglDeleteRenderbuffers);
		SYSTEM_GET_FUNCTION(gglFramebufferRenderbuffer);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture1D);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture2D);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture3D);
		SYSTEM_GET_FUNCTION(gglFramebufferTextureLayer);
		SYSTEM_GET_FUNCTION(gglGenFramebuffers);
		SYSTEM_GET_FUNCTION(gglGenRenderbuffers);
		SYSTEM_GET_FUNCTION(gglGenerateMipmap);
		SYSTEM_GET_FUNCTION(gglGetFramebufferAttachmentParameteriv);
		SYSTEM_GET_FUNCTION(gglGetRenderbufferParameteriv);
		SYSTEM_GET_FUNCTION(gglIsFramebuffer);
		SYSTEM_GET_FUNCTION(gglIsRenderbuffer);
		SYSTEM_GET_FUNCTION(gglRenderbufferStorage);
		SYSTEM_GET_FUNCTION(gglRenderbufferStorageMultisample);
	}
	else
	{
		g_ExistsGlArbFramebufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 46) GL_ARB_framebuffer_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFramebufferSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFramebufferSRGB() noexcept
{
	return g_ExistsGlArbFramebufferSRGB;
}

void System
	::InitGlArbFramebufferSRGB() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_framebuffer_sRGB"))
	{
		g_ExistsGlArbFramebufferSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 47) GL_ARB_geometry_shader4

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbGeometryShader4{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbGeometryShader4() noexcept
{
	return g_ExistsGlArbGeometryShader4;
}

namespace System
{
	using PgglFramebufferTextureARB = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	using PgglFramebufferTextureFaceARB = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
	using PgglFramebufferTextureLayerARB = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	using PgglProgramParameteriARB = void (OPENGL_STDCALL*) (GLuint program, GLenum parameterName, GLint value);
}

namespace System
{
	PgglFramebufferTextureARB gglFramebufferTextureARB{ nullptr };
	PgglFramebufferTextureFaceARB gglFramebufferTextureFaceARB{ nullptr };
	PgglFramebufferTextureLayerARB gglFramebufferTextureLayerARB{ nullptr };
	PgglProgramParameteriARB gglProgramParameteriARB{ nullptr };
}

void System
	::GlFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_4(gglFramebufferTextureARB, target, attachment, texture, level);
}

void System
	::GlFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTextureFaceARB, target, attachment, texture, level, face);
}

void System
	::GlFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTextureLayerARB, target, attachment, texture, level, layer);
}

void System
	::GlProgramParameteriARB(GLuint program, GLenum parameterName, GLint value) noexcept
{
	SYSTEM_BODY_3(gglProgramParameteriARB, program, parameterName, value);
}

void System
	::InitGlArbGeometryShader4() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_geometry_shader4"))
	{
		g_ExistsGlArbGeometryShader4 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglFramebufferTextureARB);
		SYSTEM_GET_FUNCTION(gglFramebufferTextureFaceARB);
		SYSTEM_GET_FUNCTION(gglFramebufferTextureLayerARB);
		SYSTEM_GET_FUNCTION(gglProgramParameteriARB);
	}
	else
	{
		g_ExistsGlArbGeometryShader4 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 48) GL_ARB_half_float_vertex

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbHalfFloatVertex{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbHalfFloatVertex() noexcept
{
	return g_ExistsGlArbHalfFloatVertex;
}

void System
	::InitGlArbHalfFloatVertex() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_half_float_vertex"))
	{
		g_ExistsGlArbHalfFloatVertex = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbHalfFloatVertex = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 49) GL_ARB_instanced_arrays

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbInstancedArrays{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbInstancedArrays() noexcept
{
	return g_ExistsGlArbInstancedArrays;
}

namespace System
{
	using PgglDrawArraysInstancedARB = void (OPENGL_STDCALL*) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	using PgglDrawElementsInstancedARB = void (OPENGL_STDCALL*) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
	using PgglVertexAttribDivisorARB = void (OPENGL_STDCALL*) (GLuint index, GLuint divisor);
}

namespace System
{
	PgglDrawArraysInstancedARB gglDrawArraysInstancedARB{ nullptr };
	PgglDrawElementsInstancedARB gglDrawElementsInstancedARB{ nullptr };
	PgglVertexAttribDivisorARB gglVertexAttribDivisorARB{ nullptr };
}

void System
	::GlDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount) noexcept
{
	SYSTEM_BODY_4(gglDrawArraysInstancedARB, mode, first, count, primcount);
}

void System
	::GlDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount) noexcept
{
	SYSTEM_BODY_5(gglDrawElementsInstancedARB, mode, count, type, indices, primcount);
}

void System
	::GlVertexAttribDivisorARB(GLuint index, GLuint divisor) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribDivisorARB, index, divisor);
}

void System
	::InitGlArbInstancedArrays() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_instanced_arrays"))
	{
		g_ExistsGlArbInstancedArrays = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawArraysInstancedARB);
		SYSTEM_GET_FUNCTION(gglDrawElementsInstancedARB);
		SYSTEM_GET_FUNCTION(gglVertexAttribDivisorARB);
	}
	else
	{
		g_ExistsGlArbInstancedArrays = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 50) GL_ARB_map_buffer_range

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMapBufferRange{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMapBufferRange() noexcept
{
	return g_ExistsGlArbMapBufferRange;
}

namespace System
{
	using PgglMapBufferRange = void* (OPENGL_STDCALL*)(GLenum, GLintptr, GLsizeiptr, GLbitfield);
	using PgglFlushMappedBufferRange = void (OPENGL_STDCALL*) (GLenum, GLintptr, GLsizeiptr);
}

namespace System
{
	PgglMapBufferRange gglMapBufferRange{ nullptr };
	PgglFlushMappedBufferRange gglFlushMappedBufferRange{ nullptr };
}

GLvoid* System
	::GlMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept
{
	SYSTEM_BODY_4_RESULT(gglMapBufferRange, target, offset, length, access, GLvoid*, nullptr);
}

void System
	::GlFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) noexcept
{
	SYSTEM_BODY_3(gglFlushMappedBufferRange, target, offset, length);
}

void System
	::InitGlArbMapBufferRange() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_map_buffer_range"))
	{
		g_ExistsGlArbMapBufferRange = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglMapBufferRange);
		SYSTEM_GET_FUNCTION(gglFlushMappedBufferRange);
	}
	else
	{
		g_ExistsGlArbMapBufferRange = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 51) GL_ARB_texture_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureBufferObject() noexcept
{
	return g_ExistsGlArbTextureBufferObject;
}

namespace System
{
	using PgglTexBufferARB = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLuint buffer);
}

namespace System
{
	PgglTexBufferARB gglTexBufferARB{ nullptr };
}

void System
	::GlTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglTexBufferARB, target, internalformat, buffer);
}

void System
	::InitGlArbTextureBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_buffer_object"))
	{
		g_ExistsGlArbTextureBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTexBufferARB);
	}
	else
	{
		g_ExistsGlArbTextureBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 52) GL_ARB_texture_compression_rgtc

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureCompressionRgtc{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureCompressionRgtc() noexcept
{
	return g_ExistsGlArbTextureCompressionRgtc;
}

void System
	::InitGlArbTextureCompressionRgtc() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_compression_rgtc"))
	{
		g_ExistsGlArbTextureCompressionRgtc = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureCompressionRgtc = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 53) GL_ARB_texture_rg

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureRg{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureRg() noexcept
{
	return g_ExistsGlArbTextureRg;
}

void System
	::InitGlArbTextureRg() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_rg"))
	{
		g_ExistsGlArbTextureRg = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureRg = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 54) GL_ARB_vertex_array_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexArrayObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexArrayObject() noexcept
{
	return g_ExistsGlArbVertexArrayObject;
}

namespace System
{
	using PgglBindVertexArray = void (OPENGL_STDCALL*) (GLuint array);
	using PgglDeleteVertexArrays = void (OPENGL_STDCALL*) (GLsizei n, const GLuint* arrays);
	using PgglGenVertexArrays = void (OPENGL_STDCALL*) (GLsizei n, GLuint* arrays);
	using PgglIsVertexArray = GLboolean(OPENGL_STDCALL*) (GLuint array);
}

namespace System
{
	PgglBindVertexArray gglBindVertexArray{ nullptr };
	PgglDeleteVertexArrays gglDeleteVertexArrays{ nullptr };
	PgglGenVertexArrays gglGenVertexArrays{ nullptr };
	PgglIsVertexArray gglIsVertexArray{ nullptr };
}

void System
	::GlBindVertexArray(GLuint array) noexcept
{
	SYSTEM_BODY_1(gglBindVertexArray, array);
}

void System
	::GlDeleteVertexArrays(GLsizei n, const GLuint* arrays) noexcept
{
	SYSTEM_BODY_2(gglDeleteVertexArrays, n, arrays);
}

void System
	::GlGenVertexArrays(GLsizei n, GLuint* arrays) noexcept
{
	SYSTEM_BODY_2(gglGenVertexArrays, n, arrays);
}

GLboolean System
	::GlIsVertexArray(GLuint array) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsVertexArray, array, GLboolean, GL_FALSE);
}

void System
	::InitGlArbVertexArrayObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_array_object"))
	{
		g_ExistsGlArbVertexArrayObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindVertexArray);
		SYSTEM_GET_FUNCTION(gglDeleteVertexArrays);
		SYSTEM_GET_FUNCTION(gglGenVertexArrays);
		SYSTEM_GET_FUNCTION(gglIsVertexArray);
	}
	else
	{
		g_ExistsGlArbVertexArrayObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 57) GL_ARB_uniform_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbUniformBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbUniformBufferObject() noexcept
{
	return g_ExistsGlArbUniformBufferObject;
}

namespace System
{
	using PgglGetActiveUniformBlockName = void (OPENGL_STDCALL*) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
	using PgglGetActiveUniformBlockiv = void (OPENGL_STDCALL*) (GLuint program, GLuint uniformBlockIndex, GLenum parameterName, GLint* params);
	using PgglGetActiveUniformName = void (OPENGL_STDCALL*) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
	using PgglGetActiveUniformsiv = void (OPENGL_STDCALL*) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum parameterName, GLint* params);
	using PgglGetUniformBlockIndex = GLuint(OPENGL_STDCALL*) (GLuint program, const GLchar* uniformBlockName);
	using PgglGetUniformIndices = void (OPENGL_STDCALL*) (GLuint program, GLsizei uniformCount, const GLchar* const * uniformNames, GLuint* uniformIndices);
	using PgglUniformBlockBinding = void (OPENGL_STDCALL*) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
}

namespace System
{
	PgglGetActiveUniformBlockName gglGetActiveUniformBlockName{ nullptr };
	PgglGetActiveUniformBlockiv gglGetActiveUniformBlockiv{ nullptr };
	PgglGetActiveUniformName gglGetActiveUniformName{ nullptr };
	PgglGetActiveUniformsiv gglGetActiveUniformsiv{ nullptr };
	PgglGetUniformBlockIndex gglGetUniformBlockIndex{ nullptr };
	PgglGetUniformIndices gglGetUniformIndices{ nullptr };
	PgglUniformBlockBinding gglUniformBlockBinding{ nullptr };
}

void System
	::GlGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName) noexcept
{
	SYSTEM_BODY_5(gglGetActiveUniformBlockName, program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void System
	::GlGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetActiveUniformBlockiv, program, uniformBlockIndex, parameterName, params);
}

void System
	::GlGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName) noexcept
{
	SYSTEM_BODY_5(gglGetActiveUniformName, program, uniformIndex, bufSize, length, uniformName);
}

void System
	::GlGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_5(gglGetActiveUniformsiv, program, uniformCount, uniformIndices, parameterName, params);
}

GLuint System
	::GlGetUniformBlockIndex(GLuint program, const GLchar* uniformBlockName) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetUniformBlockIndex, program, uniformBlockName, GLuint, 0);
}

void System
	::GlGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* const * uniformNames, GLuint* uniformIndices) noexcept
{
	SYSTEM_BODY_4(gglGetUniformIndices, program, uniformCount, uniformNames, uniformIndices);
}

void System
	::GlUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) noexcept
{
	SYSTEM_BODY_3(gglUniformBlockBinding, program, uniformBlockIndex, uniformBlockBinding);
}

void System
	::InitGlArbUniformBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_uniform_buffer_object"))
	{
		g_ExistsGlArbUniformBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetActiveUniformBlockName);
		SYSTEM_GET_FUNCTION(gglGetActiveUniformBlockiv);
		SYSTEM_GET_FUNCTION(gglGetActiveUniformName);
		SYSTEM_GET_FUNCTION(gglGetActiveUniformsiv);
		SYSTEM_GET_FUNCTION(gglGetUniformBlockIndex);
		SYSTEM_GET_FUNCTION(gglGetUniformIndices);
		SYSTEM_GET_FUNCTION(gglUniformBlockBinding);
	}
	else
	{
		g_ExistsGlArbUniformBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 58) GL_ARB_compatibility

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbCompatibility{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbCompatibility() noexcept
{
	return g_ExistsGlArbCompatibility;
}

void System
	::InitGlArbCompatibility() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_compatibility"))
	{
		g_ExistsGlArbCompatibility = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbCompatibility = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 59) GL_ARB_copy_buffer

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbCopyBuffer{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbCopyBuffer() noexcept
{
	return g_ExistsGlArbCopyBuffer;
}

namespace System
{
	using PgglCopyBufferSubData = void (OPENGL_STDCALL*) (GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
}

namespace System
{
	PgglCopyBufferSubData gglCopyBufferSubData{ nullptr };
}

void System
	::GlCopyBufferSubData(GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglCopyBufferSubData, readtarget, writetarget, readoffset, writeoffset, size);
}

void System
	::InitGlArbCopyBuffer() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_copy_buffer"))
	{
		g_ExistsGlArbCopyBuffer = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCopyBufferSubData);
	}
	else
	{
		g_ExistsGlArbCopyBuffer = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 60) GL_ARB_shader_texture_lod

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderTextureLod{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderTextureLod() noexcept
{
	return g_ExistsGlArbShaderTextureLod;
}

void System
	::InitGlArbShaderTextureLod() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_texture_lod"))
	{
		g_ExistsGlArbShaderTextureLod = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShaderTextureLod = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 61) GL_ARB_depth_clamp

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDepthClamp{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDepthClamp() noexcept
{
	return g_ExistsGlArbDepthClamp;
}

void System
	::InitGlArbDepthClamp() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_depth_clamp"))
	{
		g_ExistsGlArbDepthClamp = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbDepthClamp = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 62) GL_ARB_draw_elements_base_vertex

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDrawElementsBaseVertex{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDrawElementsBaseVertex() noexcept
{
	return g_ExistsGlArbDrawElementsBaseVertex;
}

namespace System
{
	using PgglDrawElementsBaseVertex = void (OPENGL_STDCALL*) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
	using PgglDrawElementsInstancedBaseVertex = void (OPENGL_STDCALL*) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex);
	using PgglDrawRangeElementsBaseVertex = void (OPENGL_STDCALL*) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
	using PgglMultiDrawElementsBaseVertex = void (OPENGL_STDCALL*) (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount, const GLint* basevertex);
}

namespace System
{
	PgglDrawElementsBaseVertex gglDrawElementsBaseVertex{ nullptr };
	PgglDrawElementsInstancedBaseVertex gglDrawElementsInstancedBaseVertex{ nullptr };
	PgglDrawRangeElementsBaseVertex gglDrawRangeElementsBaseVertex{ nullptr };
	PgglMultiDrawElementsBaseVertex gglMultiDrawElementsBaseVertex{ nullptr };
}

void System
	::GlDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex) noexcept
{
	SYSTEM_BODY_5(gglDrawElementsBaseVertex, mode, count, type, indices, basevertex);
}

void System
	::GlDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex) noexcept
{
	SYSTEM_BODY_6(gglDrawElementsInstancedBaseVertex, mode, count, type, indices, primcount, basevertex);
}

void System
	::GlDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex) noexcept
{
	SYSTEM_BODY_7(gglDrawRangeElementsBaseVertex, mode, start, end, count, type, indices, basevertex);
}

void System
	::GlMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei primcount, const GLint* basevertex) noexcept
{
	SYSTEM_BODY_6(gglMultiDrawElementsBaseVertex, mode, count, type, indices, primcount, basevertex);
}

void System
	::InitGlArbDrawElementsBaseVertex() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_draw_elements_base_vertex"))
	{
		g_ExistsGlArbDrawElementsBaseVertex = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawElementsBaseVertex);
		SYSTEM_GET_FUNCTION(gglDrawElementsInstancedBaseVertex);
		SYSTEM_GET_FUNCTION(gglDrawRangeElementsBaseVertex);
		SYSTEM_GET_FUNCTION(gglMultiDrawElementsBaseVertex);
	}
	else
	{
		g_ExistsGlArbDrawElementsBaseVertex = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 63) GL_ARB_fragment_coord_conventions

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFragmentCoordConventions{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFragmentCoordConventions() noexcept
{
	return g_ExistsGlArbFragmentCoordConventions;
}

void System
	::InitGlArbFragmentCoordConventions() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_fragment_coord_conventions"))
	{
		g_ExistsGlArbFragmentCoordConventions = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbFragmentCoordConventions = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 64) GL_ARB_provoking_vertex

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbProvokingVertex{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbProvokingVertex() noexcept
{
	return g_ExistsGlArbProvokingVertex;
}

namespace System
{
	using PgglProvokingVertex = void (OPENGL_STDCALL*) (GLenum mode);
}

namespace System
{
	PgglProvokingVertex gglProvokingVertex{ nullptr };
}

void System
	::GlProvokingVertex(GLenum mode) noexcept
{
	SYSTEM_BODY_1(gglProvokingVertex, mode);
}

void System
	::InitGlArbProvokingVertex() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_provoking_vertex"))
	{
		g_ExistsGlArbProvokingVertex = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglProvokingVertex);
	}
	else
	{
		g_ExistsGlArbProvokingVertex = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 65) GL_ARB_seamless_cube_map

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSeamlessCubeMap{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSeamlessCubeMap() noexcept
{
	return g_ExistsGlArbSeamlessCubeMap;
}

void System
	::InitGlArbSeamlessCubeMap() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_seamless_cube_map"))
	{
		g_ExistsGlArbSeamlessCubeMap = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbSeamlessCubeMap = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 66) GL_ARB_sync

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSync{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSync() noexcept
{
	return g_ExistsGlArbSync;
}

namespace System
{
	using PgglClientWaitSync = GLenum(OPENGL_STDCALL*) (GLsync GLsync, GLbitfield flags, GLuint64 timeout);
	using PgglDeleteSync = void (OPENGL_STDCALL*) (GLsync GLsync);
	using PgglFenceSync = GLsync(OPENGL_STDCALL*) (GLenum condition, GLbitfield flags);
	using PgglGetInteger64v = void (OPENGL_STDCALL*) (GLenum parameterName, GLint64* params);
	using PgglGetSynciv = void (OPENGL_STDCALL*) (GLsync GLsync, GLenum parameterName, GLsizei bufSize, GLsizei* length, GLint* values);
	using PgglIsSync = GLboolean(OPENGL_STDCALL*) (GLsync GLsync);
	using PgglWaitSync = void (OPENGL_STDCALL*) (GLsync GLsync, GLbitfield flags, GLuint64 timeout);
}

namespace System
{
	PgglClientWaitSync gglClientWaitSync{ nullptr };
	PgglDeleteSync gglDeleteSync{ nullptr };
	PgglFenceSync gglFenceSync{ nullptr };
	PgglGetInteger64v gglGetInteger64v{ nullptr };
	PgglGetSynciv gglGetSynciv{ nullptr };
	PgglIsSync gglIsSync{ nullptr };
	PgglWaitSync gglWaitSync{ nullptr };
}

GLenum System
	::GlClientWaitSync(GLsync glSync, GLbitfield flags, GLuint64 timeout) noexcept
{
	SYSTEM_BODY_3_RESULT(gglClientWaitSync, glSync, flags, timeout, GLenum, 0);
}

void  System
	::GlDeleteSync(GLsync glSync) noexcept
{
	SYSTEM_BODY_1(gglDeleteSync, glSync);
}

GLsync System
	::GlFenceSync(GLenum condition, GLbitfield flags) noexcept
{
	SYSTEM_BODY_2_RESULT(gglFenceSync, condition, flags, GLsync, nullptr);
}

void System
	::GlGetInteger64v(GLenum parameterName, GLint64* params) noexcept
{
	SYSTEM_BODY_2(gglGetInteger64v, parameterName, params);
}

void System
	::GlGetSynciv(GLsync glSync, GLenum parameterName, GLsizei bufSize, GLsizei* length, GLint* values) noexcept
{
	SYSTEM_BODY_5(gglGetSynciv, glSync, parameterName, bufSize, length, values);
}

GLboolean System
	::GlIsSync(GLsync glSync) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsSync, glSync, GLboolean, GL_FALSE);
}

void System
	::GlWaitSync(GLsync glSync, GLbitfield flags, GLuint64 timeout) noexcept
{
	SYSTEM_BODY_3(gglWaitSync, glSync, flags, timeout);
}

void System
	::InitGlArbSync() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_sync"))
	{
		g_ExistsGlArbSync = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglClientWaitSync);
		SYSTEM_GET_FUNCTION(gglDeleteSync);
		SYSTEM_GET_FUNCTION(gglFenceSync);
		SYSTEM_GET_FUNCTION(gglGetInteger64v);
		SYSTEM_GET_FUNCTION(gglGetSynciv);
		SYSTEM_GET_FUNCTION(gglIsSync);
		SYSTEM_GET_FUNCTION(gglWaitSync);
	}
	else
	{
		g_ExistsGlArbSync = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 67) GL_ARB_texture_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureMultisample() noexcept
{
	return g_ExistsGlArbTextureMultisample;
}

namespace System
{
	using PgglGetMultisamplefv = void (OPENGL_STDCALL*) (GLenum parameterName, GLuint index, GLfloat* val);
	using PgglSampleMaski = void (OPENGL_STDCALL*) (GLuint index, GLbitfield mask);
	using PgglTexImage2DMultisample = void (OPENGL_STDCALL*) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	using PgglTexImage3DMultisample = void (OPENGL_STDCALL*) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
}

namespace System
{
	PgglGetMultisamplefv gglGetMultisamplefv{ nullptr };
	PgglSampleMaski gglSampleMaski{ nullptr };
	PgglTexImage2DMultisample gglTexImage2DMultisample{ nullptr };
	PgglTexImage3DMultisample gglTexImage3DMultisample{ nullptr };
}

void System
	::GlGetMultisamplefv(GLenum parameterName, GLuint index, GLfloat* val) noexcept
{
	SYSTEM_BODY_3(gglGetMultisamplefv, parameterName, index, val);
}

void System
	::GlSampleMaski(GLuint index, GLbitfield mask) noexcept
{
	SYSTEM_BODY_2(gglSampleMaski, index, mask);
}

void System
	::GlTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_6(gglTexImage2DMultisample, target, samples, internalformat, width, height, fixedsamplelocations);
}

void System
	::GlTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_7(gglTexImage3DMultisample, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void System
	::InitGlArbTextureMultisample() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_multisample"))
	{
		g_ExistsGlArbTextureMultisample = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetMultisamplefv);
		SYSTEM_GET_FUNCTION(gglSampleMaski);
		SYSTEM_GET_FUNCTION(gglTexImage2DMultisample);
		SYSTEM_GET_FUNCTION(gglTexImage3DMultisample);
	}
	else
	{
		g_ExistsGlArbTextureMultisample = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 68) GL_ARB_vertex_array_bgra

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexArrayBgra{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexArrayBgra() noexcept
{
	return g_ExistsGlArbVertexArrayBgra;
}

void System
	::InitGlArbVertexArrayBgra() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_array_bgra"))
	{
		g_ExistsGlArbVertexArrayBgra = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbVertexArrayBgra = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 69) GL_ARB_draw_buffers_blend

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDrawBuffersBlend{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDrawBuffersBlend() noexcept
{
	return g_ExistsGlArbDrawBuffersBlend;
}

namespace System
{
	PgglBlendEquationSeparatei gglBlendEquationSeparateiARB{ nullptr };
	PgglBlendEquationi gglBlendEquationiARB{ nullptr };
	PgglBlendFuncSeparatei gglBlendFuncSeparateiARB{ nullptr };
	PgglBlendFunci gglBlendFunciARB{ nullptr };
}

void System
	::GlBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept
{
	SYSTEM_BODY_3(gglBlendEquationSeparateiARB, buf, modeRGB, modeAlpha);
}

void System
	::GlBlendEquationiARB(GLuint buf, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglBlendEquationiARB, buf, mode);
}

void System
	::GlBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept
{
	SYSTEM_BODY_5(gglBlendFuncSeparateiARB, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void System
	::GlBlendFunciARB(GLuint buf, GLenum src, GLenum dst) noexcept
{
	SYSTEM_BODY_3(gglBlendFunciARB, buf, src, dst);
}

void System
	::InitGlArbDrawBuffersBlend() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_draw_buffers_blend"))
	{
		g_ExistsGlArbDrawBuffersBlend = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendEquationSeparatei, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendEquationi, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendFuncSeparatei, ARB, g_SystemArbOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendFunci, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbDrawBuffersBlend = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 70) GL_ARB_sample_shading

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSampleShading{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSampleShading() noexcept
{
	return g_ExistsGlArbSampleShading;
}

namespace System
{
	PgglMinSampleShading gglMinSampleShadingARB{ nullptr };
}

void System
	::GlMinSampleShadingARB(GLclampf value) noexcept
{
	SYSTEM_BODY_1(gglMinSampleShadingARB, value);
}

void System
	::InitGlArbSampleShading() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_sample_shading"))
	{
		g_ExistsGlArbSampleShading = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglMinSampleShading, ARB, g_SystemArbOverride);
	}
	else
	{
		g_ExistsGlArbSampleShading = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 71) GL_ARB_texture_cube_map_array

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureCubeMapArray{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureCubeMapArray() noexcept
{
	return g_ExistsGlArbTextureCubeMapArray;
}

void System
	::InitGlArbTextureCubeMapArray() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_cube_map_array"))
	{
		g_ExistsGlArbTextureCubeMapArray = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureCubeMapArray = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 72) GL_ARB_texture_gather

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureGather{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureGather() noexcept
{
	return g_ExistsGlArbTextureGather;
}

void System
	::InitGlArbTextureGather() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_gather"))
	{
		g_ExistsGlArbTextureGather = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureGather = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 73) GL_ARB_texture_query_lod

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureQueryLod{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureQueryLod() noexcept
{
	return g_ExistsGlArbTextureQueryLod;
}

void System
	::InitGlArbTextureQueryLod() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_query_lod"))
	{
		g_ExistsGlArbTextureQueryLod = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureQueryLod = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 76) GL_ARB_shading_language_include

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShadingLanguageInclude{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShadingLanguageInclude() noexcept
{
	return g_ExistsGlArbShadingLanguageInclude;
}

namespace System
{
	using PgglCompileShaderIncludeARB = void (OPENGL_STDCALL*) (GLuint shader, GLsizei count, const GLchar* const* path, const GLint *length);
	using PgglDeleteNamedStringARB = void (OPENGL_STDCALL*) (GLint namelen, const GLchar* name);
	using PgglGetNamedStringARB = void (OPENGL_STDCALL*) (GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
	using PgglGetNamedStringivARB = void (OPENGL_STDCALL*) (GLint namelen, const GLchar* name, GLenum parameterName, GLint* params);
	using PgglIsNamedStringARB = GLboolean(OPENGL_STDCALL*) (GLint namelen, const GLchar* name);
	using PgglNamedStringARB = void (OPENGL_STDCALL*) (GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
}

namespace System
{
	PgglCompileShaderIncludeARB gglCompileShaderIncludeARB{ nullptr };
	PgglDeleteNamedStringARB gglDeleteNamedStringARB{ nullptr };
	PgglGetNamedStringARB gglGetNamedStringARB{ nullptr };
	PgglGetNamedStringivARB gglGetNamedStringivARB{ nullptr };
	PgglIsNamedStringARB gglIsNamedStringARB{ nullptr };
	PgglNamedStringARB gglNamedStringARB{ nullptr };
}

void System
	::GlCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length) noexcept
{
	SYSTEM_BODY_4(gglCompileShaderIncludeARB, shader, count, path, length);
}

void System
	::GlDeleteNamedStringARB(GLint namelen, const GLchar* name) noexcept
{
	SYSTEM_BODY_2(gglDeleteNamedStringARB, namelen, name);
}

void System
	::GlGetNamedStringARB(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* namedString) noexcept
{
	SYSTEM_BODY_5(gglGetNamedStringARB, namelen, name, bufSize, stringlen, namedString);
}

void System
	::GlGetNamedStringivARB(GLint namelen, const GLchar* name, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedStringivARB, namelen, name, parameterName, params);
}

GLboolean System
	::GlIsNamedStringARB(GLint namelen, const GLchar* name) noexcept
{
	SYSTEM_BODY_2_RESULT(gglIsNamedStringARB, namelen, name, GLboolean, GL_FALSE);
}

void System
	::GlNamedStringARB(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* namedString) noexcept
{
	SYSTEM_BODY_5(gglNamedStringARB, type, namelen, name, stringlen, namedString);
}

void System
	::InitGlArbShadingLanguageInclude() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shading_language_include"))
	{
		g_ExistsGlArbShadingLanguageInclude = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCompileShaderIncludeARB);
		SYSTEM_GET_FUNCTION(gglDeleteNamedStringARB);
		SYSTEM_GET_FUNCTION(gglGetNamedStringARB);
		SYSTEM_GET_FUNCTION(gglGetNamedStringivARB);
		SYSTEM_GET_FUNCTION(gglIsNamedStringARB);
		SYSTEM_GET_FUNCTION(gglNamedStringARB);
	}
	else
	{
		g_ExistsGlArbShadingLanguageInclude = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 77) GL_ARB_texture_compression_bptc

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureCompressionBptc{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureCompressionBptc() noexcept
{
	return g_ExistsGlArbTextureCompressionBptc;
}

void System
	::InitGlArbTextureCompressionBptc() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_compression_bptc"))
	{
		g_ExistsGlArbTextureCompressionBptc = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureCompressionBptc = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 78) GL_ARB_blend_func_extended

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbBlendFuncExtended{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbBlendFuncExtended() noexcept
{
	return g_ExistsGlArbBlendFuncExtended;
}

namespace System
{
	using PgglBindFragDataLocationIndexed = void (OPENGL_STDCALL*) (GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
	using PgglGetFragDataIndex = GLint(OPENGL_STDCALL*) (GLuint program, const GLchar* name);
}

namespace System
{
	PgglBindFragDataLocationIndexed gglBindFragDataLocationIndexed{ nullptr };
	PgglGetFragDataIndex gglGetFragDataIndex{ nullptr };
}

void System
	::GlBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name) noexcept
{
	SYSTEM_BODY_4(gglBindFragDataLocationIndexed, program, colorNumber, index, name);
}

GLint System
	::GlGetFragDataIndex(GLuint program, const GLchar* name) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetFragDataIndex, program, name, GLint, 0);
}

void System
	::InitGlArbBlendFuncExtended() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_blend_func_extended"))
	{
		g_ExistsGlArbBlendFuncExtended = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindFragDataLocationIndexed);
		SYSTEM_GET_FUNCTION(gglGetFragDataIndex);
	}
	else
	{
		g_ExistsGlArbBlendFuncExtended = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 79) GL_ARB_explicit_attrib_location

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbExplicitAttribLocation{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbExplicitAttribLocation() noexcept
{
	return g_ExistsGlArbExplicitAttribLocation;
}

void System
	::InitGlArbExplicitAttribLocation() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_explicit_attrib_location"))
	{
		g_ExistsGlArbExplicitAttribLocation = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbExplicitAttribLocation = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 80) GL_ARB_occlusion_query2

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbOcclusionQuery2{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbOcclusionQuery2() noexcept
{
	return g_ExistsGlArbOcclusionQuery2;
}

void System
	::InitGlArbOcclusionQuery2() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_occlusion_query2"))
	{
		g_ExistsGlArbOcclusionQuery2 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbOcclusionQuery2 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 81) GL_ARB_sampler_objects

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSamplerObjects{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSamplerObjects() noexcept
{
	return g_ExistsGlArbSamplerObjects;
}

namespace System
{
	using PgglBindSampler = void (OPENGL_STDCALL*) (GLuint unit, GLuint sampler);
	using PgglDeleteSamplers = void (OPENGL_STDCALL*) (GLsizei count, const GLuint * samplers);
	using PgglGenSamplers = void (OPENGL_STDCALL*) (GLsizei count, GLuint* samplers);
	using PgglGetSamplerParameterIiv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, GLint* params);
	using PgglGetSamplerParameterIuiv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, GLuint* params);
	using PgglGetSamplerParameterfv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, GLfloat* params);
	using PgglGetSamplerParameteriv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, GLint* params);
	using PgglIsSampler = GLboolean(OPENGL_STDCALL*) (GLuint sampler);
	using PgglSamplerParameterIiv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, const GLint* params);
	using PgglSamplerParameterIuiv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, const GLuint* params);
	using PgglSamplerParameterf = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, GLfloat param);
	using PgglSamplerParameterfv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, const GLfloat* params);
	using PgglSamplerParameteri = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, GLint param);
	using PgglSamplerParameteriv = void (OPENGL_STDCALL*) (GLuint sampler, GLenum parameterName, const GLint* params);
}

namespace System
{
	PgglBindSampler gglBindSampler{ nullptr };
	PgglDeleteSamplers gglDeleteSamplers{ nullptr };
	PgglGenSamplers gglGenSamplers{ nullptr };
	PgglGetSamplerParameterIiv gglGetSamplerParameterIiv{ nullptr };
	PgglGetSamplerParameterIuiv gglGetSamplerParameterIuiv{ nullptr };
	PgglGetSamplerParameterfv gglGetSamplerParameterfv{ nullptr };
	PgglGetSamplerParameteriv gglGetSamplerParameteriv{ nullptr };
	PgglIsSampler gglIsSampler{ nullptr };
	PgglSamplerParameterIiv gglSamplerParameterIiv{ nullptr };
	PgglSamplerParameterIuiv gglSamplerParameterIuiv{ nullptr };
	PgglSamplerParameterf gglSamplerParameterf{ nullptr };
	PgglSamplerParameterfv gglSamplerParameterfv{ nullptr };
	PgglSamplerParameteri gglSamplerParameteri{ nullptr };
	PgglSamplerParameteriv gglSamplerParameteriv{ nullptr };
}

void System
	::GlBindSampler(GLuint unit, GLuint sampler) noexcept
{
	SYSTEM_BODY_2(gglBindSampler, unit, sampler);
}

void System
	::GlDeleteSamplers(GLsizei count, const GLuint * samplers) noexcept
{
	SYSTEM_BODY_2(gglDeleteSamplers, count, samplers);
}

void System
	::GlGenSamplers(GLsizei count, GLuint* samplers) noexcept
{
	SYSTEM_BODY_2(gglGenSamplers, count, samplers);
}

void System
	::GlGetSamplerParameterIiv(GLuint sampler, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetSamplerParameterIiv, sampler, parameterName, params);
}

void System
	::GlGetSamplerParameterIuiv(GLuint sampler, GLenum parameterName, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetSamplerParameterIuiv, sampler, parameterName, params);
}

void System
	::GlGetSamplerParameterfv(GLuint sampler, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglGetSamplerParameterfv, sampler, parameterName, params);
}

void System
	::GlGetSamplerParameteriv(GLuint sampler, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetSamplerParameteriv, sampler, parameterName, params);
}

GLboolean System
	::GlIsSampler(GLuint sampler) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsSampler, sampler, GLboolean, GL_FALSE);
}

void System
	::GlSamplerParameterIiv(GLuint sampler, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglSamplerParameterIiv, sampler, parameterName, params);
}

void System
	::GlSamplerParameterIuiv(GLuint sampler, GLenum parameterName, const GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglSamplerParameterIuiv, sampler, parameterName, params);
}

void System
	::GlSamplerParameterf(GLuint sampler, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_3(gglSamplerParameterf, sampler, parameterName, param);
}

void System
	::GlSamplerParameterfv(GLuint sampler, GLenum parameterName, const GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglSamplerParameterfv, sampler, parameterName, params);
}

void System
	::GlSamplerParameteri(GLuint sampler, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_3(gglSamplerParameteri, sampler, parameterName, param);
}

void System
	::GlSamplerParameteriv(GLuint sampler, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglSamplerParameteriv, sampler, parameterName, params);
}

void System
	::InitGlArbSamplerObjects() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_sampler_objects"))
	{
		g_ExistsGlArbSamplerObjects = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindSampler);
		SYSTEM_GET_FUNCTION(gglDeleteSamplers);
		SYSTEM_GET_FUNCTION(gglGenSamplers);
		SYSTEM_GET_FUNCTION(gglGetSamplerParameterIiv);
		SYSTEM_GET_FUNCTION(gglGetSamplerParameterIuiv);
		SYSTEM_GET_FUNCTION(gglGetSamplerParameterfv);
		SYSTEM_GET_FUNCTION(gglGetSamplerParameteriv);
		SYSTEM_GET_FUNCTION(gglIsSampler);
		SYSTEM_GET_FUNCTION(gglSamplerParameterIiv);
		SYSTEM_GET_FUNCTION(gglSamplerParameterIuiv);
		SYSTEM_GET_FUNCTION(gglSamplerParameterf);
		SYSTEM_GET_FUNCTION(gglSamplerParameterfv);
		SYSTEM_GET_FUNCTION(gglSamplerParameteri);
		SYSTEM_GET_FUNCTION(gglSamplerParameteriv);
	}
	else
	{
		g_ExistsGlArbSamplerObjects = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 82) GL_ARB_shader_bit_encoding

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderBitEncoding{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderBitEncoding() noexcept
{
	return g_ExistsGlArbShaderBitEncoding;
}

void System
	::InitGlArbShaderBitEncoding() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_bit_encoding"))
	{
		g_ExistsGlArbShaderBitEncoding = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShaderBitEncoding = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 83) GL_ARB_texture_rgb10_a2ui

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureRgb10A2ui{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureRgb10A2ui() noexcept
{
	return g_ExistsGlArbTextureRgb10A2ui;
}

void System
	::InitGlArbTextureRgb10A2ui() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_rgb10_a2ui"))
	{
		g_ExistsGlArbTextureRgb10A2ui = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureRgb10A2ui = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 84) GL_ARB_texture_swizzle

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureSwizzle{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureSwizzle() noexcept
{
	return g_ExistsGlArbTextureSwizzle;
}

void System
	::InitGlArbTextureSwizzle() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_swizzle"))
	{
		g_ExistsGlArbTextureSwizzle = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureSwizzle = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 85) GL_ARB_timer_query

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTimerQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTimerQuery() noexcept
{
	return g_ExistsGlArbTimerQuery;
}

namespace System
{
	using PgglGetQueryObjecti64v = void (OPENGL_STDCALL*) (GLuint id, GLenum parameterName, GLint64* params);
	using PgglGetQueryObjectui64v = void (OPENGL_STDCALL*) (GLuint id, GLenum parameterName, GLuint64* params);
	using PgglQueryCounter = void (OPENGL_STDCALL*) (GLuint id, GLenum target);
}

namespace System
{
	PgglGetQueryObjecti64v gglGetQueryObjecti64v{ nullptr };
	PgglGetQueryObjectui64v gglGetQueryObjectui64v{ nullptr };
	PgglQueryCounter gglQueryCounter{ nullptr };
}

void System
	::GlGetQueryObjecti64v(GLuint id, GLenum parameterName, GLint64* params) noexcept
{
	SYSTEM_BODY_3(gglGetQueryObjecti64v, id, parameterName, params);
}

void System
	::GlGetQueryObjectui64v(GLuint id, GLenum parameterName, GLuint64* params) noexcept
{
	SYSTEM_BODY_3(gglGetQueryObjectui64v, id, parameterName, params);
}

void System
	::GlQueryCounter(GLuint id, GLenum target) noexcept
{
	SYSTEM_BODY_2(gglQueryCounter, id, target);
}

void System
	::InitGlArbTimerQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_timer_query"))
	{
		g_ExistsGlArbTimerQuery = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetQueryObjecti64v);
		SYSTEM_GET_FUNCTION(gglGetQueryObjectui64v);
		SYSTEM_GET_FUNCTION(gglQueryCounter);
	}
	else
	{
		g_ExistsGlArbTimerQuery = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 86) GL_ARB_vertex_type_2_10_10_10_rev  

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexType2_10_10_10Rev{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexType2_10_10_10Rev() noexcept
{
	return g_ExistsGlArbVertexType2_10_10_10Rev;
}

namespace System
{
	using PgglColorP3ui = void (OPENGL_STDCALL*) (GLenum type, GLuint color);
	using PgglColorP3uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* color);
	using PgglColorP4ui = void (OPENGL_STDCALL*) (GLenum type, GLuint color);
	using PgglColorP4uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* color);
	using PgglMultiTexCoordP1ui = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, GLuint coords);
	using PgglMultiTexCoordP1uiv = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, const GLuint* coords);
	using PgglMultiTexCoordP2ui = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, GLuint coords);
	using PgglMultiTexCoordP2uiv = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, const GLuint* coords);
	using PgglMultiTexCoordP3ui = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, GLuint coords);
	using PgglMultiTexCoordP3uiv = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, const GLuint* coords);
	using PgglMultiTexCoordP4ui = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, GLuint coords);
	using PgglMultiTexCoordP4uiv = void (OPENGL_STDCALL*) (GLenum texture, GLenum type, const GLuint* coords);
	using PgglNormalP3ui = void (OPENGL_STDCALL*) (GLenum type, GLuint coords);
	using PgglNormalP3uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* coords);
	using PgglSecondaryColorP3ui = void (OPENGL_STDCALL*) (GLenum type, GLuint color);
	using PgglSecondaryColorP3uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* color);
	using PgglTexCoordP1ui = void (OPENGL_STDCALL*) (GLenum type, GLuint coords);
	using PgglTexCoordP1uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* coords);
	using PgglTexCoordP2ui = void (OPENGL_STDCALL*) (GLenum type, GLuint coords);
	using PgglTexCoordP2uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* coords);
	using PgglTexCoordP3ui = void (OPENGL_STDCALL*) (GLenum type, GLuint coords);
	using PgglTexCoordP3uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* coords);
	using PgglTexCoordP4ui = void (OPENGL_STDCALL*) (GLenum type, GLuint coords);
	using PgglTexCoordP4uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* coords);
	using PgglVertexAttribP1ui = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PgglVertexAttribP1uiv = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PgglVertexAttribP2ui = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PgglVertexAttribP2uiv = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PgglVertexAttribP3ui = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PgglVertexAttribP3uiv = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PgglVertexAttribP4ui = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	using PgglVertexAttribP4uiv = void (OPENGL_STDCALL*) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
	using PgglVertexP2ui = void (OPENGL_STDCALL*) (GLenum type, GLuint value);
	using PgglVertexP2uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* value);
	using PgglVertexP3ui = void (OPENGL_STDCALL*) (GLenum type, GLuint value);
	using PgglVertexP3uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* value);
	using PgglVertexP4ui = void (OPENGL_STDCALL*) (GLenum type, GLuint value);
	using PgglVertexP4uiv = void (OPENGL_STDCALL*) (GLenum type, const GLuint* value);
}

namespace System
{
	PgglColorP3ui gglColorP3ui{ nullptr };
	PgglColorP3uiv gglColorP3uiv{ nullptr };
	PgglColorP4ui gglColorP4ui{ nullptr };
	PgglColorP4uiv gglColorP4uiv{ nullptr };
	PgglMultiTexCoordP1ui gglMultiTexCoordP1ui{ nullptr };
	PgglMultiTexCoordP1uiv gglMultiTexCoordP1uiv{ nullptr };
	PgglMultiTexCoordP2ui gglMultiTexCoordP2ui{ nullptr };
	PgglMultiTexCoordP2uiv gglMultiTexCoordP2uiv{ nullptr };
	PgglMultiTexCoordP3ui gglMultiTexCoordP3ui{ nullptr };
	PgglMultiTexCoordP3uiv gglMultiTexCoordP3uiv{ nullptr };
	PgglMultiTexCoordP4ui gglMultiTexCoordP4ui{ nullptr };
	PgglMultiTexCoordP4uiv gglMultiTexCoordP4uiv{ nullptr };
	PgglNormalP3ui gglNormalP3ui{ nullptr };
	PgglNormalP3uiv gglNormalP3uiv{ nullptr };
	PgglSecondaryColorP3ui gglSecondaryColorP3ui{ nullptr };
	PgglSecondaryColorP3uiv gglSecondaryColorP3uiv{ nullptr };
	PgglTexCoordP1ui gglTexCoordP1ui{ nullptr };
	PgglTexCoordP1uiv gglTexCoordP1uiv{ nullptr };
	PgglTexCoordP2ui gglTexCoordP2ui{ nullptr };
	PgglTexCoordP2uiv gglTexCoordP2uiv{ nullptr };
	PgglTexCoordP3ui gglTexCoordP3ui{ nullptr };
	PgglTexCoordP3uiv gglTexCoordP3uiv{ nullptr };
	PgglTexCoordP4ui gglTexCoordP4ui{ nullptr };
	PgglTexCoordP4uiv gglTexCoordP4uiv{ nullptr };
	PgglVertexAttribP1ui gglVertexAttribP1ui{ nullptr };
	PgglVertexAttribP1uiv gglVertexAttribP1uiv{ nullptr };
	PgglVertexAttribP2ui gglVertexAttribP2ui{ nullptr };
	PgglVertexAttribP2uiv gglVertexAttribP2uiv{ nullptr };
	PgglVertexAttribP3ui gglVertexAttribP3ui{ nullptr };
	PgglVertexAttribP3uiv gglVertexAttribP3uiv{ nullptr };
	PgglVertexAttribP4ui gglVertexAttribP4ui{ nullptr };
	PgglVertexAttribP4uiv gglVertexAttribP4uiv{ nullptr };
	PgglVertexP2ui gglVertexP2ui{ nullptr };
	PgglVertexP2uiv gglVertexP2uiv{ nullptr };
	PgglVertexP3ui gglVertexP3ui{ nullptr };
	PgglVertexP3uiv gglVertexP3uiv{ nullptr };
	PgglVertexP4ui gglVertexP4ui{ nullptr };
	PgglVertexP4uiv gglVertexP4uiv{ nullptr };
}

void System
	::GlColorP3ui(GLenum type, GLuint color) noexcept
{
	SYSTEM_BODY_2(gglColorP3ui, type, color);
}

void System
	::GlColorP3uiv(GLenum type, const GLuint* color) noexcept
{
	SYSTEM_BODY_2(gglColorP3uiv, type, color);
}

void System
	::GlColorP4ui(GLenum type, GLuint color) noexcept
{
	SYSTEM_BODY_2(gglColorP4ui, type, color);
}

void System
	::GlColorP4uiv(GLenum type, const GLuint* color) noexcept
{
	SYSTEM_BODY_2(gglColorP4uiv, type, color);
}

void System
	::GlMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP1ui, texture, type, coords);
}

void System
	::GlMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP1uiv, texture, type, coords);
}

void System
	::GlMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP2ui, texture, type, coords);
}

void System
	::GlMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP2uiv, texture, type, coords);
}

void System
	::GlMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP3ui, texture, type, coords);
}

void System
	::GlMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP3uiv, texture, type, coords);
}

void System
	::GlMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP4ui, texture, type, coords);
}

void System
	::GlMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_3(gglMultiTexCoordP4uiv, texture, type, coords);
}

void System
	::GlNormalP3ui(GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_2(gglNormalP3ui, type, coords);
}

void System
::GlNormalP3uiv(GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_2(gglNormalP3uiv, type, coords);
}

void System
	::GlSecondaryColorP3ui(GLenum type, GLuint color) noexcept
{
	SYSTEM_BODY_2(gglSecondaryColorP3ui, type, color);
}

void System
	::GlSecondaryColorP3uiv(GLenum type, const GLuint* color) noexcept
{
	SYSTEM_BODY_2(gglSecondaryColorP3uiv, type, color);
}

void System
	::GlTexCoordP1ui(GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP1ui, type, coords);
}

void System
	::GlTexCoordP1uiv(GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP1uiv, type, coords);
}

void System
	::GlTexCoordP2ui(GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP2ui, type, coords);
}

void System
	::GlTexCoordP2uiv(GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP2uiv, type, coords);
}

void System
	::GlTexCoordP3ui(GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP3ui, type, coords);
}

void System
	::GlTexCoordP3uiv(GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP3uiv, type, coords);
}

void System
	::GlTexCoordP4ui(GLenum type, GLuint coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP4ui, type, coords);
}

void System
	::GlTexCoordP4uiv(GLenum type, const GLuint* coords) noexcept
{
	SYSTEM_BODY_2(gglTexCoordP4uiv, type, coords);
}

void System
	::GlVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP1ui, index, type, normalized, value);
}

void System
	::GlVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP1uiv, index, type, normalized, value);
}

void System
	::GlVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP2ui, index, type, normalized, value);
}

void System
	::GlVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP2uiv, index, type, normalized, value);
}

void System
	::GlVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP3ui, index, type, normalized, value);
}

void System
	::GlVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP3uiv, index, type, normalized, value);
}

void System
	::GlVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP4ui, index, type, normalized, value);
}

void System
	::GlVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribP4uiv, index, type, normalized, value);
}

void System
	::GlVertexP2ui(GLenum type, GLuint value) noexcept
{
	SYSTEM_BODY_2(gglVertexP2ui, type, value);
}

void System
	::GlVertexP2uiv(GLenum type, const GLuint* value) noexcept
{
	SYSTEM_BODY_2(gglVertexP2uiv, type, value);
}

void System
	::GlVertexP3ui(GLenum type, GLuint value) noexcept
{
	SYSTEM_BODY_2(gglVertexP3ui, type, value);
}

void System
	::GlVertexP3uiv(GLenum type, const GLuint* value) noexcept
{
	SYSTEM_BODY_2(gglVertexP3uiv, type, value);
}

void System
	::GlVertexP4ui(GLenum type, GLuint value) noexcept
{
	SYSTEM_BODY_2(gglVertexP4ui, type, value);
}

void System
	::GlVertexP4uiv(GLenum type, const GLuint* value) noexcept
{
	SYSTEM_BODY_2(gglVertexP4uiv, type, value);
}

void System
	::InitGlArbVertexType2_10_10_10Rev() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_type_2_10_10_10_rev"))
	{
		g_ExistsGlArbVertexType2_10_10_10Rev = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglColorP3ui);
		SYSTEM_GET_FUNCTION(gglColorP3uiv);
		SYSTEM_GET_FUNCTION(gglColorP4ui);
		SYSTEM_GET_FUNCTION(gglColorP4uiv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP1ui);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP1uiv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP2ui);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP2uiv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP3ui);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP3uiv);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP4ui);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordP4uiv);
		SYSTEM_GET_FUNCTION(gglNormalP3ui);
		SYSTEM_GET_FUNCTION(gglNormalP3uiv);
		SYSTEM_GET_FUNCTION(gglSecondaryColorP3ui);
		SYSTEM_GET_FUNCTION(gglSecondaryColorP3uiv);
		SYSTEM_GET_FUNCTION(gglTexCoordP1ui);
		SYSTEM_GET_FUNCTION(gglTexCoordP1uiv);
		SYSTEM_GET_FUNCTION(gglTexCoordP2ui);
		SYSTEM_GET_FUNCTION(gglTexCoordP2uiv);
		SYSTEM_GET_FUNCTION(gglTexCoordP3ui);
		SYSTEM_GET_FUNCTION(gglTexCoordP3uiv);
		SYSTEM_GET_FUNCTION(gglTexCoordP4ui);
		SYSTEM_GET_FUNCTION(gglTexCoordP4uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribP1ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribP1uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribP2ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribP2uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribP3ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribP3uiv);
		SYSTEM_GET_FUNCTION(gglVertexAttribP4ui);
		SYSTEM_GET_FUNCTION(gglVertexAttribP4uiv);
		SYSTEM_GET_FUNCTION(gglVertexP2ui);
		SYSTEM_GET_FUNCTION(gglVertexP2uiv);
		SYSTEM_GET_FUNCTION(gglVertexP3ui);
		SYSTEM_GET_FUNCTION(gglVertexP3uiv);
		SYSTEM_GET_FUNCTION(gglVertexP4ui);
		SYSTEM_GET_FUNCTION(gglVertexP4uiv);
	}
	else
	{
		g_ExistsGlArbVertexType2_10_10_10Rev = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 87) GL_ARB_draw_indirect

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDrawIndirect{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDrawIndirect() noexcept
{
	return g_ExistsGlArbDrawIndirect;
}

namespace System
{
	using PgglDrawArraysIndirect = void (OPENGL_STDCALL*) (GLenum mode, const void* indirect);
	using PgglDrawElementsIndirect = void (OPENGL_STDCALL*) (GLenum mode, GLenum type, const void* indirect);
}

namespace System
{
	PgglDrawArraysIndirect gglDrawArraysIndirect{ nullptr };
	PgglDrawElementsIndirect gglDrawElementsIndirect{ nullptr };
}

void System
	::GlDrawArraysIndirect(GLenum mode, const void* indirect) noexcept
{
	SYSTEM_BODY_2(gglDrawArraysIndirect, mode, indirect);
}

void System
	::GlDrawElementsIndirect(GLenum mode, GLenum type, const void* indirect) noexcept
{
	SYSTEM_BODY_3(gglDrawElementsIndirect, mode, type, indirect);
}

void System
	::InitGlArbDrawIndirect() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_draw_indirect"))
	{
		g_ExistsGlArbDrawIndirect = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawArraysIndirect);
		SYSTEM_GET_FUNCTION(gglDrawElementsIndirect);
	}
	else
	{
		g_ExistsGlArbDrawIndirect = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 88) GL_ARB_gpu_shader5

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbGpuShader5{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbGpuShader5() noexcept
{
	return g_ExistsGlArbGpuShader5;
}

void System
	::InitGlArbGpuShader5() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_gpu_shader5"))
	{
		g_ExistsGlArbGpuShader5 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbGpuShader5 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 89) GL_ARB_gpu_shader_fp64

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbGpuShaderFp64{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbGpuShaderFp64() noexcept
{
	return g_ExistsGlArbGpuShaderFp64;
}

namespace System
{
	using PgglGetUniformdv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLdouble* params);
	using PgglUniform1d = void (OPENGL_STDCALL*) (GLint location, GLdouble x);
	using PgglUniform1dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLdouble* value);
	using PgglUniform2d = void (OPENGL_STDCALL*) (GLint location, GLdouble x, GLdouble y);
	using PgglUniform2dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLdouble* value);
	using PgglUniform3d = void (OPENGL_STDCALL*) (GLint location, GLdouble x, GLdouble y, GLdouble z);
	using PgglUniform3dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLdouble* value);
	using PgglUniform4d = void (OPENGL_STDCALL*) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PgglUniform4dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLdouble* value);
	using PgglUniformMatrix2dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix2x3dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix2x4dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix3dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix3x2dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix3x4dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix4dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix4x2dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglUniformMatrix4x3dv = void (OPENGL_STDCALL*) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
}

namespace System
{
	PgglGetUniformdv gglGetUniformdv{ nullptr };
	PgglUniform1d gglUniform1d{ nullptr };
	PgglUniform1dv gglUniform1dv{ nullptr };
	PgglUniform2d gglUniform2d{ nullptr };
	PgglUniform2dv gglUniform2dv{ nullptr };
	PgglUniform3d gglUniform3d{ nullptr };
	PgglUniform3dv gglUniform3dv{ nullptr };
	PgglUniform4d gglUniform4d{ nullptr };
	PgglUniform4dv gglUniform4dv{ nullptr };
	PgglUniformMatrix2dv gglUniformMatrix2dv{ nullptr };
	PgglUniformMatrix2x3dv gglUniformMatrix2x3dv{ nullptr };
	PgglUniformMatrix2x4dv gglUniformMatrix2x4dv{ nullptr };
	PgglUniformMatrix3dv gglUniformMatrix3dv{ nullptr };
	PgglUniformMatrix3x2dv gglUniformMatrix3x2dv{ nullptr };
	PgglUniformMatrix3x4dv gglUniformMatrix3x4dv{ nullptr };
	PgglUniformMatrix4dv gglUniformMatrix4dv{ nullptr };
	PgglUniformMatrix4x2dv gglUniformMatrix4x2dv{ nullptr };
	PgglUniformMatrix4x3dv gglUniformMatrix4x3dv{ nullptr };
}

void System
	::GlGetUniformdv(GLuint program, GLint location, GLdouble* params) noexcept
{
	SYSTEM_BODY_3(gglGetUniformdv, program, location, params);
}

void System
	::GlUniform1d(GLint location, GLdouble x) noexcept
{
	SYSTEM_BODY_2(gglUniform1d, location, x);
}

void System
	::GlUniform1dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_3(gglUniform1dv, location, count, value);
}

void System
	::GlUniform2d(GLint location, GLdouble x, GLdouble y) noexcept
{
	SYSTEM_BODY_3(gglUniform2d, location, x, y);
}

void System
	::GlUniform2dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_3(gglUniform2dv, location, count, value);
}

void System
	::GlUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_4(gglUniform3d, location, x, y, z);
}

void System
	::GlUniform3dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_3(gglUniform3dv, location, count, value);
}

void System
	::GlUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_5(gglUniform4d, location, x, y, z, w);
}

void System
	::GlUniform4dv(GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_3(gglUniform4dv, location, count, value);
}

void System
	::GlUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix2dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix2x3dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix2x4dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix3dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix3x2dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix3x4dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix4dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix4x2dv, location, count, transpose, value);
}

void System
	::GlUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglUniformMatrix4x3dv, location, count, transpose, value);
}

void System
	::InitGlArbGpuShaderFp64() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_gpu_shader_fp64"))
	{
		g_ExistsGlArbGpuShaderFp64 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetUniformdv);
		SYSTEM_GET_FUNCTION(gglUniform1d);
		SYSTEM_GET_FUNCTION(gglUniform1dv);
		SYSTEM_GET_FUNCTION(gglUniform2d);
		SYSTEM_GET_FUNCTION(gglUniform2dv);
		SYSTEM_GET_FUNCTION(gglUniform3d);
		SYSTEM_GET_FUNCTION(gglUniform3dv);
		SYSTEM_GET_FUNCTION(gglUniform4d);
		SYSTEM_GET_FUNCTION(gglUniform4dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix2dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix2x3dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix2x4dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix3dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix3x2dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix3x4dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix4dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix4x2dv);
		SYSTEM_GET_FUNCTION(gglUniformMatrix4x3dv);
	}
	else
	{
		g_ExistsGlArbGpuShaderFp64 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 90) GL_ARB_shader_subroutine

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderSubroutin{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderSubroutin() noexcept
{
	return g_ExistsGlArbShaderSubroutin;
}

namespace System
{
	using PgglGetActiveSubroutineName = void (OPENGL_STDCALL*) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar *name);
	using PgglGetActiveSubroutineUniformName = void (OPENGL_STDCALL*) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar *name);
	using PgglGetActiveSubroutineUniformiv = void (OPENGL_STDCALL*) (GLuint program, GLenum shadertype, GLuint index, GLenum parameterName, GLint* values);
	using PgglGetProgramStageiv = void (OPENGL_STDCALL*) (GLuint program, GLenum shadertype, GLenum parameterName, GLint* values);
	using PgglGetSubroutineIndex = GLuint(OPENGL_STDCALL*) (GLuint program, GLenum shadertype, const GLchar* name);
	using PgglGetSubroutineUniformLocation = GLint(OPENGL_STDCALL*) (GLuint program, GLenum shadertype, const GLchar* name);
	using PgglGetUniformSubroutineuiv = void (OPENGL_STDCALL*) (GLenum shadertype, GLint location, GLuint* params);
	using PgglUniformSubroutinesuiv = void (OPENGL_STDCALL*) (GLenum shadertype, GLsizei count, const GLuint* indices);
}

namespace System
{
	PgglGetActiveSubroutineName gglGetActiveSubroutineName{ nullptr };
	PgglGetActiveSubroutineUniformName gglGetActiveSubroutineUniformName{ nullptr };
	PgglGetActiveSubroutineUniformiv gglGetActiveSubroutineUniformiv{ nullptr };
	PgglGetProgramStageiv gglGetProgramStageiv{ nullptr };
	PgglGetSubroutineIndex gglGetSubroutineIndex{ nullptr };
	PgglGetSubroutineUniformLocation gglGetSubroutineUniformLocation{ nullptr };
	PgglGetUniformSubroutineuiv gglGetUniformSubroutineuiv{ nullptr };
	PgglUniformSubroutinesuiv gglUniformSubroutinesuiv{ nullptr };
}

void System
	::GlGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name) noexcept
{
	SYSTEM_BODY_6(gglGetActiveSubroutineName, program, shadertype, index, bufsize, length, name);
}

void System
	::GlGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar* name) noexcept
{
	SYSTEM_BODY_6(gglGetActiveSubroutineUniformName, program, shadertype, index, bufsize, length, name);
}

void System
	::GlGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum parameterName, GLint* values) noexcept
{
	SYSTEM_BODY_5(gglGetActiveSubroutineUniformiv, program, shadertype, index, parameterName, values);
}

void System
	::GlGetProgramStageiv(GLuint program, GLenum shadertype, GLenum parameterName, GLint* values) noexcept
{
	SYSTEM_BODY_4(gglGetProgramStageiv, program, shadertype, parameterName, values);
}

GLuint System
	::GlGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar* name) noexcept
{
	SYSTEM_BODY_3_RESULT(gglGetSubroutineIndex, program, shadertype, name, GLuint, 0);
}

GLint System
	::GlGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar* name) noexcept
{
	SYSTEM_BODY_3_RESULT(gglGetSubroutineUniformLocation, program, shadertype, name, GLint, -1);
}

void System
	::GlGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetUniformSubroutineuiv, shadertype, location, params);
}

void System
	::GlUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices) noexcept
{
	SYSTEM_BODY_3(gglUniformSubroutinesuiv, shadertype, count, indices);
}

void System
	::InitGlArbShaderSubroutin() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_subroutine"))
	{
		g_ExistsGlArbShaderSubroutin = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetActiveSubroutineName);
		SYSTEM_GET_FUNCTION(gglGetActiveSubroutineUniformName);
		SYSTEM_GET_FUNCTION(gglGetActiveSubroutineUniformiv);
		SYSTEM_GET_FUNCTION(gglGetProgramStageiv);
		SYSTEM_GET_FUNCTION(gglGetSubroutineIndex);
		SYSTEM_GET_FUNCTION(gglGetSubroutineUniformLocation);
		SYSTEM_GET_FUNCTION(gglGetUniformSubroutineuiv);
		SYSTEM_GET_FUNCTION(gglUniformSubroutinesuiv);
	}
	else
	{
		g_ExistsGlArbShaderSubroutin = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 91) GL_ARB_tessellation_shader

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTessellationShader{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTessellationShader() noexcept
{
	return g_ExistsGlArbTessellationShader;
}

namespace System
{
	using PgglPatchParameterfv = void (OPENGL_STDCALL*) (GLenum parameterName, const GLfloat* values);
	using PgglPatchParameteri = void (OPENGL_STDCALL*) (GLenum parameterName, GLint value);
}

namespace System
{
	PgglPatchParameterfv gglPatchParameterfv{ nullptr };
	PgglPatchParameteri gglPatchParameteri{ nullptr };
}

void System
	::GlPatchParameterfv(GLenum parameterName, const GLfloat* values) noexcept
{
	SYSTEM_BODY_2(gglPatchParameterfv, parameterName, values);
}

void System
	::GlPatchParameteri(GLenum parameterName, GLint value) noexcept
{
	SYSTEM_BODY_2(gglPatchParameteri, parameterName, value);
}

void System
	::InitGlArbTessellationShader() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_tessellation_shader"))
	{
		g_ExistsGlArbTessellationShader = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglPatchParameterfv);
		SYSTEM_GET_FUNCTION(gglPatchParameteri);
	}
	else
	{
		g_ExistsGlArbTessellationShader = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 92) GL_ARB_texture_buffer_object_rgb32

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureBufferObjectRgb32{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureBufferObjectRgb32() noexcept
{
	return g_ExistsGlArbTextureBufferObjectRgb32;
}

void System
	::InitGlArbTextureBufferObjectRgb32() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_buffer_object_rgb32"))
	{
		g_ExistsGlArbTextureBufferObjectRgb32 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureBufferObjectRgb32 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 93) GL_ARB_transform_feedback2

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTransformFeedback2{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTransformFeedback2() noexcept
{
	return g_ExistsGlArbTransformFeedback2;
}

namespace System
{
	using PgglBindTransformFeedback = void (OPENGL_STDCALL*) (GLenum target, GLuint id);
	using PgglDeleteTransformFeedbacks = void (OPENGL_STDCALL*) (GLsizei n, const GLuint* ids);
	using PgglDrawTransformFeedback = void (OPENGL_STDCALL*) (GLenum mode, GLuint id);
	using PgglGenTransformFeedbacks = void (OPENGL_STDCALL*) (GLsizei n, GLuint* ids);
	using PgglIsTransformFeedback = GLboolean(OPENGL_STDCALL*) (GLuint id);
	using PgglPauseTransformFeedback = void (OPENGL_STDCALL*) (void);
	using PgglResumeTransformFeedback = void (OPENGL_STDCALL*) (void);
}

namespace System
{
	PgglBindTransformFeedback gglBindTransformFeedback{ nullptr };
	PgglDeleteTransformFeedbacks gglDeleteTransformFeedbacks{ nullptr };
	PgglDrawTransformFeedback gglDrawTransformFeedback{ nullptr };
	PgglGenTransformFeedbacks gglGenTransformFeedbacks{ nullptr };
	PgglIsTransformFeedback gglIsTransformFeedback{ nullptr };
	PgglPauseTransformFeedback gglPauseTransformFeedback{ nullptr };
	PgglResumeTransformFeedback gglResumeTransformFeedback{ nullptr };
}

void System
	::GlBindTransformFeedback(GLenum target, GLuint id) noexcept
{
	SYSTEM_BODY_2(gglBindTransformFeedback, target, id);
}

void System
	::GlDeleteTransformFeedbacks(GLsizei n, const GLuint* ids) noexcept
{
	SYSTEM_BODY_2(gglDeleteTransformFeedbacks, n, ids);
}

void System
	::GlDrawTransformFeedback(GLenum mode, GLuint id) noexcept
{
	SYSTEM_BODY_2(gglDrawTransformFeedback, mode, id);
}

void System
	::GlGenTransformFeedbacks(GLsizei n, GLuint* ids) noexcept
{
	SYSTEM_BODY_2(gglGenTransformFeedbacks, n, ids);
}

GLboolean System
	::GlIsTransformFeedback(GLuint id) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsTransformFeedback, id, GLboolean, GL_FALSE);
}

void System
	::GlPauseTransformFeedback(void) noexcept
{
	SYSTEM_BODY_0(gglPauseTransformFeedback);
}

void System
	::GlResumeTransformFeedback(void) noexcept
{
	SYSTEM_BODY_0(gglResumeTransformFeedback);
}

void System
	::InitGlArbTransformFeedback2() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_transform_feedback2"))
	{
		g_ExistsGlArbTransformFeedback2 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindTransformFeedback);
		SYSTEM_GET_FUNCTION(gglDeleteTransformFeedbacks);
		SYSTEM_GET_FUNCTION(gglDrawTransformFeedback);
		SYSTEM_GET_FUNCTION(gglGenTransformFeedbacks);
		SYSTEM_GET_FUNCTION(gglIsTransformFeedback);
		SYSTEM_GET_FUNCTION(gglPauseTransformFeedback);
		SYSTEM_GET_FUNCTION(gglResumeTransformFeedback);
	}
	else
	{
		g_ExistsGlArbTransformFeedback2 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 94) GL_ARB_transform_feedback3

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTransformFeedback3{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTransformFeedback3() noexcept
{
	return g_ExistsGlArbTransformFeedback3;
}

namespace System
{
	using PgglBeginQueryIndexed = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLuint id);
	using PgglDrawTransformFeedbackStream = void (OPENGL_STDCALL*) (GLenum mode, GLuint id, GLuint stream);
	using PgglEndQueryIndexed = void (OPENGL_STDCALL*) (GLenum target, GLuint index);
	using PgglGetQueryIndexediv = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLenum parameterName, GLint* params);
}

namespace System
{
	PgglBeginQueryIndexed gglBeginQueryIndexed{ nullptr };
	PgglDrawTransformFeedbackStream gglDrawTransformFeedbackStream{ nullptr };
	PgglEndQueryIndexed gglEndQueryIndexed{ nullptr };
	PgglGetQueryIndexediv gglGetQueryIndexediv{ nullptr };
}

void System
	::GlBeginQueryIndexed(GLenum target, GLuint index, GLuint id) noexcept
{
	SYSTEM_BODY_3(gglBeginQueryIndexed, target, index, id);
}

void System
	::GlDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) noexcept
{
	SYSTEM_BODY_3(gglDrawTransformFeedbackStream, mode, id, stream);
}

void System
	::GlEndQueryIndexed(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEndQueryIndexed, target, index);
}

void System
	::GlGetQueryIndexediv(GLenum target, GLuint index, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetQueryIndexediv, target, index, parameterName, params);
}

void System
	::InitGlArbTransformFeedback3() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_transform_feedback3"))
	{
		g_ExistsGlArbTransformFeedback3 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBeginQueryIndexed);
		SYSTEM_GET_FUNCTION(gglDrawTransformFeedbackStream);
		SYSTEM_GET_FUNCTION(gglEndQueryIndexed);
		SYSTEM_GET_FUNCTION(gglGetQueryIndexediv);

	}
	else
	{
		g_ExistsGlArbTransformFeedback3 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 96) GL_ARB_get_program_binary

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbGetProgramBinary{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbGetProgramBinary() noexcept
{
	return g_ExistsGlArbGetProgramBinary;
}

namespace System
{
	using PgglGetProgramBinary = void (OPENGL_STDCALL*) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary);
	using PgglProgramBinary = void (OPENGL_STDCALL*) (GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length);
}

namespace System
{
	PgglGetProgramBinary gglGetProgramBinary{ nullptr };
	PgglProgramBinary gglProgramBinary{ nullptr };
}

void System
	::GlGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, GLvoid* binary) noexcept
{
	SYSTEM_BODY_5(gglGetProgramBinary, program, bufSize, length, binaryFormat, binary);
}

void System
	::GlProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid* binary, GLsizei length) noexcept
{
	SYSTEM_BODY_4(gglProgramBinary, program, binaryFormat, binary, length);
}

void System
	::InitGlArbGetProgramBinary() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_get_program_binary"))
	{
		g_ExistsGlArbGetProgramBinary = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetProgramBinary);
		SYSTEM_GET_FUNCTION(gglProgramBinary);
	}
	else
	{
		g_ExistsGlArbGetProgramBinary = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 97) GL_ARB_separate_shader_objects

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSeparateShaderObjects{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSeparateShaderObjects() noexcept
{
	return g_ExistsGlArbSeparateShaderObjects;
}

namespace System
{
	using PgglActiveShaderProgram = void (OPENGL_STDCALL*) (GLuint pipeline, GLuint program);
	using PgglBindProgramPipeline = void (OPENGL_STDCALL*) (GLuint pipeline);
	using PgglCreateShaderProgramv = GLuint(OPENGL_STDCALL*) (GLenum type, GLsizei count, const GLchar** strings);
	using PgglDeleteProgramPipelines = void (OPENGL_STDCALL*) (GLsizei n, const GLuint* pipelines);
	using PgglGenProgramPipelines = void (OPENGL_STDCALL*) (GLsizei n, GLuint* pipelines);
	using PgglGetProgramPipelineInfoLog = void (OPENGL_STDCALL*) (GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
	using PgglGetProgramPipelineiv = void (OPENGL_STDCALL*) (GLuint pipeline, GLenum parameterName, GLint* params);
	using PgglIsProgramPipeline = GLboolean(OPENGL_STDCALL*) (GLuint pipeline);
	using PgglProgramUniform1d = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLdouble x);
	using PgglProgramUniform1dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
	using PgglProgramUniform1f = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat x);
	using PgglProgramUniform1fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform1i = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint x);
	using PgglProgramUniform1iv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform1ui = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint x);
	using PgglProgramUniform1uiv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniform2d = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLdouble x, GLdouble y);
	using PgglProgramUniform2dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
	using PgglProgramUniform2f = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat x, GLfloat y);
	using PgglProgramUniform2fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform2i = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint x, GLint y);
	using PgglProgramUniform2iv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform2ui = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint x, GLuint y);
	using PgglProgramUniform2uiv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniform3d = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
	using PgglProgramUniform3dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
	using PgglProgramUniform3f = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z);
	using PgglProgramUniform3fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform3i = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint x, GLint y, GLint z);
	using PgglProgramUniform3iv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform3ui = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint x, GLuint y, GLuint z);
	using PgglProgramUniform3uiv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniform4d = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PgglProgramUniform4dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
	using PgglProgramUniform4f = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	using PgglProgramUniform4fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform4i = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w);
	using PgglProgramUniform4iv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform4ui = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w);
	using PgglProgramUniform4uiv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniformMatrix2dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix2fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix2x3dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix2x3fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix2x4dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix2x4fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix3dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix3fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix3x2dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix3x2fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix3x4dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix3x4fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix4dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix4fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix4x2dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix4x2fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix4x3dv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
	using PgglProgramUniformMatrix4x3fv = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglUseProgramStages = void (OPENGL_STDCALL*) (GLuint pipeline, GLbitfield stages, GLuint program);
	using PgglValidateProgramPipeline = void (OPENGL_STDCALL*) (GLuint pipeline);
}

namespace System
{
	PgglActiveShaderProgram gglActiveShaderProgram{ nullptr };
	PgglBindProgramPipeline gglBindProgramPipeline{ nullptr };
	PgglCreateShaderProgramv gglCreateShaderProgramv{ nullptr };
	PgglDeleteProgramPipelines gglDeleteProgramPipelines{ nullptr };
	PgglGenProgramPipelines gglGenProgramPipelines{ nullptr };
	PgglGetProgramPipelineInfoLog gglGetProgramPipelineInfoLog{ nullptr };
	PgglGetProgramPipelineiv gglGetProgramPipelineiv{ nullptr };
	PgglIsProgramPipeline gglIsProgramPipeline{ nullptr };
	PgglProgramUniform1d gglProgramUniform1d{ nullptr };
	PgglProgramUniform1dv gglProgramUniform1dv{ nullptr };
	PgglProgramUniform1f gglProgramUniform1f{ nullptr };
	PgglProgramUniform1fv gglProgramUniform1fv{ nullptr };
	PgglProgramUniform1i gglProgramUniform1i{ nullptr };
	PgglProgramUniform1iv gglProgramUniform1iv{ nullptr };
	PgglProgramUniform1ui gglProgramUniform1ui{ nullptr };
	PgglProgramUniform1uiv gglProgramUniform1uiv{ nullptr };
	PgglProgramUniform2d gglProgramUniform2d{ nullptr };
	PgglProgramUniform2dv gglProgramUniform2dv{ nullptr };
	PgglProgramUniform2f gglProgramUniform2f{ nullptr };
	PgglProgramUniform2fv gglProgramUniform2fv{ nullptr };
	PgglProgramUniform2i gglProgramUniform2i{ nullptr };
	PgglProgramUniform2iv gglProgramUniform2iv{ nullptr };
	PgglProgramUniform2ui gglProgramUniform2ui{ nullptr };
	PgglProgramUniform2uiv gglProgramUniform2uiv{ nullptr };
	PgglProgramUniform3d gglProgramUniform3d{ nullptr };
	PgglProgramUniform3dv gglProgramUniform3dv{ nullptr };
	PgglProgramUniform3f gglProgramUniform3f{ nullptr };
	PgglProgramUniform3fv gglProgramUniform3fv{ nullptr };
	PgglProgramUniform3i gglProgramUniform3i{ nullptr };
	PgglProgramUniform3iv gglProgramUniform3iv{ nullptr };
	PgglProgramUniform3ui gglProgramUniform3ui{ nullptr };
	PgglProgramUniform3uiv gglProgramUniform3uiv{ nullptr };
	PgglProgramUniform4d gglProgramUniform4d{ nullptr };
	PgglProgramUniform4dv gglProgramUniform4dv{ nullptr };
	PgglProgramUniform4f gglProgramUniform4f{ nullptr };
	PgglProgramUniform4fv gglProgramUniform4fv{ nullptr };
	PgglProgramUniform4i gglProgramUniform4i{ nullptr };
	PgglProgramUniform4iv gglProgramUniform4iv{ nullptr };
	PgglProgramUniform4ui gglProgramUniform4ui{ nullptr };
	PgglProgramUniform4uiv gglProgramUniform4uiv{ nullptr };
	PgglProgramUniformMatrix2dv gglProgramUniformMatrix2dv{ nullptr };
	PgglProgramUniformMatrix2fv gglProgramUniformMatrix2fv{ nullptr };
	PgglProgramUniformMatrix2x3dv gglProgramUniformMatrix2x3dv{ nullptr };
	PgglProgramUniformMatrix2x3fv gglProgramUniformMatrix2x3fv{ nullptr };
	PgglProgramUniformMatrix2x4dv gglProgramUniformMatrix2x4dv{ nullptr };
	PgglProgramUniformMatrix2x4fv gglProgramUniformMatrix2x4fv{ nullptr };
	PgglProgramUniformMatrix3dv gglProgramUniformMatrix3dv{ nullptr };
	PgglProgramUniformMatrix3fv gglProgramUniformMatrix3fv{ nullptr };
	PgglProgramUniformMatrix3x2dv gglProgramUniformMatrix3x2dv{ nullptr };
	PgglProgramUniformMatrix3x2fv gglProgramUniformMatrix3x2fv{ nullptr };
	PgglProgramUniformMatrix3x4dv gglProgramUniformMatrix3x4dv{ nullptr };
	PgglProgramUniformMatrix3x4fv gglProgramUniformMatrix3x4fv{ nullptr };
	PgglProgramUniformMatrix4dv gglProgramUniformMatrix4dv{ nullptr };
	PgglProgramUniformMatrix4fv gglProgramUniformMatrix4fv{ nullptr };
	PgglProgramUniformMatrix4x2dv gglProgramUniformMatrix4x2dv{ nullptr };
	PgglProgramUniformMatrix4x2fv gglProgramUniformMatrix4x2fv{ nullptr };
	PgglProgramUniformMatrix4x3dv gglProgramUniformMatrix4x3dv{ nullptr };
	PgglProgramUniformMatrix4x3fv gglProgramUniformMatrix4x3fv{ nullptr };
	PgglUseProgramStages gglUseProgramStages{ nullptr };
	PgglValidateProgramPipeline gglValidateProgramPipeline{ nullptr };
}

void System
	::GlActiveShaderProgram(GLuint pipeline, GLuint program) noexcept
{
	SYSTEM_BODY_2(gglActiveShaderProgram, pipeline, program);
}

void System
	::GlBindProgramPipeline(GLuint pipeline) noexcept
{
	SYSTEM_BODY_1(gglBindProgramPipeline, pipeline);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
GLuint System
	::GlCreateShaderProgramv(GLenum type, GLsizei count, const GLchar** strings) noexcept
{
	SYSTEM_BODY_3_RESULT(gglCreateShaderProgramv, type, count, strings, GLuint, 0);
}
#include STSTEM_WARNING_POP

void System
	::GlDeleteProgramPipelines(GLsizei n, const GLuint* pipelines) noexcept
{
	SYSTEM_BODY_2(gglDeleteProgramPipelines, n, pipelines);
}

void System
	::GlGenProgramPipelines(GLsizei n, GLuint* pipelines) noexcept
{
	SYSTEM_BODY_2(gglGenProgramPipelines, n, pipelines);
}

void System
	::GlGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog) noexcept
{
	SYSTEM_BODY_4(gglGetProgramPipelineInfoLog, pipeline, bufSize, length, infoLog);
}

void System
	::GlGetProgramPipelineiv(GLuint pipeline, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetProgramPipelineiv, pipeline, parameterName, params);
}

GLboolean System
	::GlIsProgramPipeline(GLuint pipeline) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsProgramPipeline, pipeline, GLboolean, GL_FALSE);
}

void System
	::GlProgramUniform1d(GLuint program, GLint location, GLdouble x) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1d, program, location, x);
}

void System
	::GlProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1dv, program, location, count, value);
}

void System
	::GlProgramUniform1f(GLuint program, GLint location, GLfloat x) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1f, program, location, x);
}

void System
	::GlProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1fv, program, location, count, value);
}

void System
	::GlProgramUniform1i(GLuint program, GLint location, GLint x) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1i, program, location, x);
}

void System
	::GlProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1iv, program, location, count, value);
}

void System
	::GlProgramUniform1ui(GLuint program, GLint location, GLuint x) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1ui, program, location, x);
}

void System
	::GlProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1uiv, program, location, count, value);
}

void System
	::GlProgramUniform2d(GLuint program, GLint location, GLdouble x, GLdouble y) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2d, program, location, x, y);
}

void System
	::GlProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2dv, program, location, count, value);
}

void System
	::GlProgramUniform2f(GLuint program, GLint location, GLfloat x, GLfloat y) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2f, program, location, x, y);
}

void System
	::GlProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2fv, program, location, count, value);
}

void System
	::GlProgramUniform2i(GLuint program, GLint location, GLint x, GLint y) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2i, program, location, x, y);
}

void System
	::GlProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2iv, program, location, count, value);
}

void System
	::GlProgramUniform2ui(GLuint program, GLint location, GLuint x, GLuint y) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2ui, program, location, x, y);
}

void System
	::GlProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2uiv, program, location, count, value);
}

void System
	::GlProgramUniform3d(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3d, program, location, x, y, z);
}

void System
	::GlProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3dv, program, location, count, value);
}

void System
	::GlProgramUniform3f(GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3f, program, location, x, y, z);
}

void System
	::GlProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3fv, program, location, count, value);
}

void System
	::GlProgramUniform3i(GLuint program, GLint location, GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3i, program, location, x, y, z);
}

void System
	::GlProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3iv, program, location, count, value);
}

void System
	::GlProgramUniform3ui(GLuint program, GLint location, GLuint x, GLuint y, GLuint z) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3ui, program, location, x, y, z);
}

void System
	::GlProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3uiv, program, location, count, value);
}

void System
	::GlProgramUniform4d(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4d, program, location, x, y, z, w);
}

void System
	::GlProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4dv, program, location, count, value);
}

void System
	::GlProgramUniform4f(GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4f, program, location, x, y, z, w);
}

void System
	::GlProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4fv, program, location, count, value);
}

void System
	::GlProgramUniform4i(GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4i, program, location, x, y, z, w);
}

void System
	::GlProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4iv, program, location, count, value);
}

void System
	::GlProgramUniform4ui(GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4ui, program, location, x, y, z, w);
}

void System
	::GlProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4uiv, program, location, count, value);
}

void System
	::GlProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2x3dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2x3fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2x4dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2x4fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3x2dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3x2fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3x4dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3x4fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4x2dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4x2fv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4x3dv, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4x3fv, program, location, count, transpose, value);
}

void System
	::GlUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) noexcept
{
	SYSTEM_BODY_3(gglUseProgramStages, pipeline, stages, program);
}

void System
	::GlValidateProgramPipeline(GLuint pipeline) noexcept
{
	SYSTEM_BODY_1(gglValidateProgramPipeline, pipeline);
}

void System
	::InitGlArbSeparateShaderObjects() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_separate_shader_objects"))
	{
		g_ExistsGlArbSeparateShaderObjects = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglActiveShaderProgram);
		SYSTEM_GET_FUNCTION(gglBindProgramPipeline);
		SYSTEM_GET_FUNCTION(gglCreateShaderProgramv);
		SYSTEM_GET_FUNCTION(gglDeleteProgramPipelines);
		SYSTEM_GET_FUNCTION(gglGenProgramPipelines);
		SYSTEM_GET_FUNCTION(gglGetProgramPipelineInfoLog);
		SYSTEM_GET_FUNCTION(gglGetProgramPipelineiv);
		SYSTEM_GET_FUNCTION(gglIsProgramPipeline);
		SYSTEM_GET_FUNCTION(gglProgramUniform1d);
		SYSTEM_GET_FUNCTION(gglProgramUniform1dv);
		SYSTEM_GET_FUNCTION(gglProgramUniform1f);
		SYSTEM_GET_FUNCTION(gglProgramUniform1fv);
		SYSTEM_GET_FUNCTION(gglProgramUniform1i);
		SYSTEM_GET_FUNCTION(gglProgramUniform1iv);
		SYSTEM_GET_FUNCTION(gglProgramUniform1ui);
		SYSTEM_GET_FUNCTION(gglProgramUniform1uiv);
		SYSTEM_GET_FUNCTION(gglProgramUniform2d);
		SYSTEM_GET_FUNCTION(gglProgramUniform2dv);
		SYSTEM_GET_FUNCTION(gglProgramUniform2f);
		SYSTEM_GET_FUNCTION(gglProgramUniform2fv);
		SYSTEM_GET_FUNCTION(gglProgramUniform2i);
		SYSTEM_GET_FUNCTION(gglProgramUniform2iv);
		SYSTEM_GET_FUNCTION(gglProgramUniform2ui);
		SYSTEM_GET_FUNCTION(gglProgramUniform2uiv);
		SYSTEM_GET_FUNCTION(gglProgramUniform3d);
		SYSTEM_GET_FUNCTION(gglProgramUniform3dv);
		SYSTEM_GET_FUNCTION(gglProgramUniform3f);
		SYSTEM_GET_FUNCTION(gglProgramUniform3fv);
		SYSTEM_GET_FUNCTION(gglProgramUniform3i);
		SYSTEM_GET_FUNCTION(gglProgramUniform3iv);
		SYSTEM_GET_FUNCTION(gglProgramUniform3ui);
		SYSTEM_GET_FUNCTION(gglProgramUniform3uiv);
		SYSTEM_GET_FUNCTION(gglProgramUniform4d);
		SYSTEM_GET_FUNCTION(gglProgramUniform4dv);
		SYSTEM_GET_FUNCTION(gglProgramUniform4f);
		SYSTEM_GET_FUNCTION(gglProgramUniform4fv);
		SYSTEM_GET_FUNCTION(gglProgramUniform4i);
		SYSTEM_GET_FUNCTION(gglProgramUniform4iv);
		SYSTEM_GET_FUNCTION(gglProgramUniform4ui);
		SYSTEM_GET_FUNCTION(gglProgramUniform4uiv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2x3dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2x3fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2x4dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2x4fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3x2dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3x2fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3x4dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3x4fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4x2dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4x2fv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4x3dv);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4x3fv);
		SYSTEM_GET_FUNCTION(gglUseProgramStages);
		SYSTEM_GET_FUNCTION(gglValidateProgramPipeline);
	}
	else
	{
		g_ExistsGlArbSeparateShaderObjects = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 98) GL_ARB_shader_precision

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderPrecision{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderPrecision() noexcept
{
	return g_ExistsGlArbShaderPrecision;
}

void System
	::InitGlArbShaderPrecision() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_precision"))
	{
		g_ExistsGlArbShaderPrecision = ExistsOpenGLExtensions::Exists;

	}
	else
	{
		g_ExistsGlArbShaderPrecision = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 99) GL_ARB_vertex_attrib_64bit

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexAttrib64bit{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexAttrib64bit() noexcept
{
	return g_ExistsGlArbVertexAttrib64bit;
}

namespace System
{
	using PgglGetVertexAttribLdv = void (OPENGL_STDCALL*) (GLuint index, GLenum parameterName, GLdouble* params);
	using PgglVertexAttribL1d = void (OPENGL_STDCALL*) (GLuint index, GLdouble x);
	using PgglVertexAttribL1dv = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribL2d = void (OPENGL_STDCALL*) (GLuint index, GLdouble x, GLdouble y);
	using PgglVertexAttribL2dv = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribL3d = void (OPENGL_STDCALL*) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	using PgglVertexAttribL3dv = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribL4d = void (OPENGL_STDCALL*) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PgglVertexAttribL4dv = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribLPointer = void (OPENGL_STDCALL*) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
}

namespace System
{
	PgglGetVertexAttribLdv gglGetVertexAttribLdv{ nullptr };
	PgglVertexAttribL1d gglVertexAttribL1d{ nullptr };
	PgglVertexAttribL1dv gglVertexAttribL1dv{ nullptr };
	PgglVertexAttribL2d gglVertexAttribL2d{ nullptr };
	PgglVertexAttribL2dv gglVertexAttribL2dv{ nullptr };
	PgglVertexAttribL3d gglVertexAttribL3d{ nullptr };
	PgglVertexAttribL3dv gglVertexAttribL3dv{ nullptr };
	PgglVertexAttribL4d gglVertexAttribL4d{ nullptr };
	PgglVertexAttribL4dv gglVertexAttribL4dv{ nullptr };
	PgglVertexAttribLPointer gglVertexAttribLPointer{ nullptr };
}

void System
	::GlGetVertexAttribLdv(GLuint index, GLenum parameterName, GLdouble* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribLdv, index, parameterName, params);
}

void System
	::GlVertexAttribL1d(GLuint index, GLdouble x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL1d, index, x);
}

void System
	::GlVertexAttribL1dv(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL1dv, index, v);
}

void System
	::GlVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttribL2d, index, x, y);
}

void System
	::GlVertexAttribL2dv(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL2dv, index, v);
}

void System
	::GlVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribL3d, index, x, y, z);
}

void System
	::GlVertexAttribL3dv(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL3dv, index, v);
}

void System
	::GlVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribL4d, index, x, y, z, w);
}

void System
	::GlVertexAttribL4dv(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL4dv, index, v);
}

void System
	::GlVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribLPointer, index, size, type, stride, pointer);
}

void System
	::InitGlArbVertexAttrib64bit() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_attrib_64bit"))
	{
		g_ExistsGlArbVertexAttrib64bit = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetVertexAttribLdv);
		SYSTEM_GET_FUNCTION(gglVertexAttribL1d);
		SYSTEM_GET_FUNCTION(gglVertexAttribL1dv);
		SYSTEM_GET_FUNCTION(gglVertexAttribL2d);
		SYSTEM_GET_FUNCTION(gglVertexAttribL2dv);
		SYSTEM_GET_FUNCTION(gglVertexAttribL3d);
		SYSTEM_GET_FUNCTION(gglVertexAttribL3dv);
		SYSTEM_GET_FUNCTION(gglVertexAttribL4d);
		SYSTEM_GET_FUNCTION(gglVertexAttribL4dv);
		SYSTEM_GET_FUNCTION(gglVertexAttribLPointer);
	}
	else
	{
		g_ExistsGlArbVertexAttrib64bit = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 100) GL_ARB_viewport_array

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbViewportArray{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbViewportArray() noexcept
{
	return g_ExistsGlArbViewportArray;
}

namespace System
{
	using PgglDepthRangeArrayv = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLclampd* v);
	using PgglDepthRangeIndexed = void (OPENGL_STDCALL*) (GLuint index, GLclampd n, GLclampd f);
	using PgglGetDoublei_v = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLdouble* data);
	using PgglGetFloati_v = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLfloat* data);
	using PgglScissorArrayv = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLint * v);
	using PgglScissorIndexed = void (OPENGL_STDCALL*) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
	using PgglScissorIndexedv = void (OPENGL_STDCALL*) (GLuint index, const GLint* v);
	using PgglViewportArrayv = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLfloat* v);
	using PgglViewportIndexedf = void (OPENGL_STDCALL*) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	using PgglViewportIndexedfv = void (OPENGL_STDCALL*) (GLuint index, const GLfloat* v);
}

namespace System
{
	PgglDepthRangeArrayv gglDepthRangeArrayv{ nullptr };
	PgglDepthRangeIndexed gglDepthRangeIndexed{ nullptr };
	PgglGetDoublei_v gglGetDoublei_v{ nullptr };
	PgglGetFloati_v gglGetFloati_v{ nullptr };
	PgglScissorArrayv gglScissorArrayv{ nullptr };
	PgglScissorIndexed gglScissorIndexed{ nullptr };
	PgglScissorIndexedv gglScissorIndexedv{ nullptr };
	PgglViewportArrayv gglViewportArrayv{ nullptr };
	PgglViewportIndexedf gglViewportIndexedf{ nullptr };
	PgglViewportIndexedfv gglViewportIndexedfv{ nullptr };
}

void System
	::GlDepthRangeArrayv(GLuint first, GLsizei count, const GLclampd* v) noexcept
{
	SYSTEM_BODY_3(gglDepthRangeArrayv, first, count, v);
}

void System
	::GlDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f) noexcept
{
	SYSTEM_BODY_3(gglDepthRangeIndexed, index, n, f);
}

void System
	::GlGetDoublei_v(GLenum target, GLuint index, GLdouble* data) noexcept
{
	SYSTEM_BODY_3(gglGetDoublei_v, target, index, data);
}

void System
	::GlGetFloati_v(GLenum target, GLuint index, GLfloat* data) noexcept
{
	SYSTEM_BODY_3(gglGetFloati_v, target, index, data);
}

void System
	::GlScissorArrayv(GLuint first, GLsizei count, const GLint* v) noexcept
{
	SYSTEM_BODY_3(gglScissorArrayv, first, count, v);
}

void System
	::GlScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglScissorIndexed, index, left, bottom, width, height);
}

void System
	::GlScissorIndexedv(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglScissorIndexedv, index, v);
}

void System
	::GlViewportArrayv(GLuint first, GLsizei count, const GLfloat* v) noexcept
{
	SYSTEM_BODY_3(gglViewportArrayv, first, count, v);
}

void System
	::GlViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) noexcept
{
	SYSTEM_BODY_5(gglViewportIndexedf, index, x, y, w, h);
}

void System
	::GlViewportIndexedfv(GLuint index, const GLfloat* v) noexcept
{
	SYSTEM_BODY_2(gglViewportIndexedfv, index, v);
}

void System
	::InitGlArbViewportArray() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_viewport_array"))
	{
		g_ExistsGlArbViewportArray = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDepthRangeArrayv);
		SYSTEM_GET_FUNCTION(gglDepthRangeIndexed);
		SYSTEM_GET_FUNCTION(gglGetDoublei_v);
		SYSTEM_GET_FUNCTION(gglGetFloati_v);
		SYSTEM_GET_FUNCTION(gglScissorArrayv);
		SYSTEM_GET_FUNCTION(gglScissorIndexed);
		SYSTEM_GET_FUNCTION(gglScissorIndexedv);
		SYSTEM_GET_FUNCTION(gglViewportArrayv);
		SYSTEM_GET_FUNCTION(gglViewportIndexedf);
		SYSTEM_GET_FUNCTION(gglViewportIndexedfv);
	}
	else
	{
		g_ExistsGlArbViewportArray = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 103) GL_ARB_cl_event

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbClEvent{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbClEvent() noexcept
{
	return g_ExistsGlArbClEvent;
}

namespace System
{
	using PgglCreateSyncFromCLeventARB = GLsync(OPENGL_STDCALL*) (cl_context context, cl_event event, GLbitfield flags);
}

namespace System
{
	PgglCreateSyncFromCLeventARB gglCreateSyncFromCLeventARB{ nullptr };
}

GLsync System
	::GlCreateSyncFromCLeventARB(cl_context context, cl_event event, GLbitfield flags) noexcept
{
	SYSTEM_BODY_3_RESULT(gglCreateSyncFromCLeventARB, context, event, flags, GLsync, nullptr);
}

void System
	::InitGlArbClEvent() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_cl_event"))
	{
		g_ExistsGlArbClEvent = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCreateSyncFromCLeventARB);
	}
	else
	{
		g_ExistsGlArbClEvent = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 104) GL_ARB_debug_output

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDebugOutput{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDebugOutput() noexcept
{
	return g_ExistsGlArbDebugOutput;
}

namespace System
{
	using PgglDebugMessageCallbackARB = void (OPENGL_STDCALL*) (GlDebugProcARB callback, const GLvoid *userParam);
	using PgglDebugMessageControlARB = void (OPENGL_STDCALL*) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
	using PgglDebugMessageInsertARB = void (OPENGL_STDCALL*) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
	using PgglGetDebugMessageLogARB = GLuint(OPENGL_STDCALL*) (GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types,
		GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
}

namespace System
{
	PgglDebugMessageCallbackARB gglDebugMessageCallbackARB{ nullptr };
	PgglDebugMessageControlARB gglDebugMessageControlARB{ nullptr };
	PgglDebugMessageInsertARB gglDebugMessageInsertARB{ nullptr };
	PgglGetDebugMessageLogARB gglGetDebugMessageLogARB{ nullptr };
}

void System
	::GlDebugMessageCallbackARB(GlDebugProcARB callback, const GLvoid* userParam) noexcept
{
	SYSTEM_BODY_2(gglDebugMessageCallbackARB, callback, userParam);
}

void System
	::GlDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled) noexcept
{
	SYSTEM_BODY_6(gglDebugMessageControlARB, source, type, severity, count, ids, enabled);
}

void System
	::GlDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf) noexcept
{
	SYSTEM_BODY_6(gglDebugMessageInsertARB, source, type, id, severity, length, buf);
}

GLuint System
	::GlGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog) noexcept
{
	SYSTEM_BODY_8_RESULT(gglGetDebugMessageLogARB, count, bufsize, sources, types, ids, severities, lengths, messageLog, GLuint, 0);
}

void System
	::InitGlArbDebugOutput() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_debug_output"))
	{
		g_ExistsGlArbDebugOutput = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDebugMessageCallbackARB);
		SYSTEM_GET_FUNCTION(gglDebugMessageControlARB);
		SYSTEM_GET_FUNCTION(gglDebugMessageInsertARB);
		SYSTEM_GET_FUNCTION(gglGetDebugMessageLogARB);
	}
	else
	{
		g_ExistsGlArbDebugOutput = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 105) GL_ARB_robustness

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbRobustness{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbRobustness() noexcept
{
	return g_ExistsGlArbRobustness;
}

namespace System
{
	using PgglGetGraphicsResetStatusARB = GLenum(OPENGL_STDCALL*) (void);
	using PgglGetnColorTableARB = void (OPENGL_STDCALL*) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table);
	using PgglGetnCompressedTexImageARB = void (OPENGL_STDCALL*) (GLenum target, GLint lod, GLsizei bufSize, void* img);
	using PgglGetnConvolutionFilterARB = void (OPENGL_STDCALL*) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image);
	using PgglGetnHistogramARB = void (OPENGL_STDCALL*) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
	using PgglGetnMapdvARB = void (OPENGL_STDCALL*) (GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
	using PgglGetnMapfvARB = void (OPENGL_STDCALL*) (GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
	using PgglGetnMapivARB = void (OPENGL_STDCALL*) (GLenum target, GLenum query, GLsizei bufSize, GLint* v);
	using PgglGetnMinmaxARB = void (OPENGL_STDCALL*) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
	using PgglGetnPixelMapfvARB = void (OPENGL_STDCALL*) (GLenum map, GLsizei bufSize, GLfloat* values);
	using PgglGetnPixelMapuivARB = void (OPENGL_STDCALL*) (GLenum map, GLsizei bufSize, GLuint* values);
	using PgglGetnPixelMapusvARB = void (OPENGL_STDCALL*) (GLenum map, GLsizei bufSize, GLushort* values);
	using PgglGetnPolygonStippleARB = void (OPENGL_STDCALL*) (GLsizei bufSize, GLubyte* pattern);
	using PgglGetnSeparableFilterARB = void (OPENGL_STDCALL*) (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize,
		void* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span);
	using PgglGetnTexImageARB = void (OPENGL_STDCALL*) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img);
	using PgglGetnUniformdvARB = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
	using PgglGetnUniformfvARB = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
	using PgglGetnUniformivARB = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei bufSize, GLint* params);
	using PgglGetnUniformuivARB = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei bufSize, GLuint* params);
	using PgglReadnPixelsARB = void (OPENGL_STDCALL*) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data);
}

namespace System
{
	PgglGetGraphicsResetStatusARB gglGetGraphicsResetStatusARB{ nullptr };
	PgglGetnColorTableARB gglGetnColorTableARB{ nullptr };
	PgglGetnCompressedTexImageARB gglGetnCompressedTexImageARB{ nullptr };
	PgglGetnConvolutionFilterARB gglGetnConvolutionFilterARB{ nullptr };
	PgglGetnHistogramARB gglGetnHistogramARB{ nullptr };
	PgglGetnMapdvARB gglGetnMapdvARB{ nullptr };
	PgglGetnMapfvARB gglGetnMapfvARB{ nullptr };
	PgglGetnMapivARB gglGetnMapivARB{ nullptr };
	PgglGetnMinmaxARB gglGetnMinmaxARB{ nullptr };
	PgglGetnPixelMapfvARB gglGetnPixelMapfvARB{ nullptr };
	PgglGetnPixelMapuivARB gglGetnPixelMapuivARB{ nullptr };
	PgglGetnPixelMapusvARB gglGetnPixelMapusvARB{ nullptr };
	PgglGetnPolygonStippleARB gglGetnPolygonStippleARB{ nullptr };
	PgglGetnSeparableFilterARB gglGetnSeparableFilterARB{ nullptr };
	PgglGetnTexImageARB gglGetnTexImageARB{ nullptr };
	PgglGetnUniformdvARB gglGetnUniformdvARB{ nullptr };
	PgglGetnUniformfvARB gglGetnUniformfvARB{ nullptr };
	PgglGetnUniformivARB gglGetnUniformivARB{ nullptr };
	PgglGetnUniformuivARB gglGetnUniformuivARB{ nullptr };
	PgglReadnPixelsARB gglReadnPixelsARB{ nullptr };
}

GLenum System
	::GlGetGraphicsResetStatusARB(void) noexcept
{
	SYSTEM_BODY_0_RESULT(gglGetGraphicsResetStatusARB, GLenum, 0);
}

void System
	::GlGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table) noexcept
{
	SYSTEM_BODY_5(gglGetnColorTableARB, target, format, type, bufSize, table);
}

void System
	::GlGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void* img) noexcept
{
	SYSTEM_BODY_4(gglGetnCompressedTexImageARB, target, lod, bufSize, img);
}

void System
	::GlGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image) noexcept
{
	SYSTEM_BODY_5(gglGetnConvolutionFilterARB, target, format, type, bufSize, image);
}

void System
	::GlGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) noexcept
{
	SYSTEM_BODY_6(gglGetnHistogramARB, target, reset, format, type, bufSize, values);
}

void System
	::GlGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v) noexcept
{
	SYSTEM_BODY_4(gglGetnMapdvARB, target, query, bufSize, v);
}

void System
	::GlGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v) noexcept
{
	SYSTEM_BODY_4(gglGetnMapfvARB, target, query, bufSize, v);
}

void System
	::GlGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint* v) noexcept
{
	SYSTEM_BODY_4(gglGetnMapivARB, target, query, bufSize, v);
}

void System
	::GlGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values) noexcept
{
	SYSTEM_BODY_6(gglGetnMinmaxARB, target, reset, format, type, bufSize, values);
}

void System
	::GlGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat* values) noexcept
{
	SYSTEM_BODY_3(gglGetnPixelMapfvARB, map, bufSize, values);
}

void System
	::GlGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint* values) noexcept
{
	SYSTEM_BODY_3(gglGetnPixelMapuivARB, map, bufSize, values);
}

void System
	::GlGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort* values) noexcept
{
	SYSTEM_BODY_3(gglGetnPixelMapusvARB, map, bufSize, values);
}

void System
	::GlGetnPolygonStippleARB(GLsizei bufSize, GLubyte* pattern) noexcept
{
	SYSTEM_BODY_2(gglGetnPolygonStippleARB, bufSize, pattern);
}

void System
	::GlGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, GLvoid* column, GLvoid* span) noexcept
{
	SYSTEM_BODY_8(gglGetnSeparableFilterARB, target, format, type, rowBufSize, row, columnBufSize, column, span);
}

void System
	::GlGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img) noexcept
{
	SYSTEM_BODY_6(gglGetnTexImageARB, target, level, format, type, bufSize, img);
}

void System
	::GlGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) noexcept
{
	SYSTEM_BODY_4(gglGetnUniformdvARB, program, location, bufSize, params);
}

void System
	::GlGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetnUniformfvARB, program, location, bufSize, params);
}

void System
	::GlGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetnUniformivARB, program, location, bufSize, params);
}

void System
	::GlGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglGetnUniformuivARB, program, location, bufSize, params);
}

void System
	::GlReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) noexcept
{
	SYSTEM_BODY_8(gglReadnPixelsARB, x, y, width, height, format, type, bufSize, data);
}

void System
	::InitGlArbRobustness() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_robustness"))
	{
		g_ExistsGlArbRobustness = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetGraphicsResetStatusARB);
		SYSTEM_GET_FUNCTION(gglGetnColorTableARB);
		SYSTEM_GET_FUNCTION(gglGetnCompressedTexImageARB);
		SYSTEM_GET_FUNCTION(gglGetnConvolutionFilterARB);
		SYSTEM_GET_FUNCTION(gglGetnHistogramARB);
		SYSTEM_GET_FUNCTION(gglGetnMapdvARB);
		SYSTEM_GET_FUNCTION(gglGetnMapfvARB);
		SYSTEM_GET_FUNCTION(gglGetnMapivARB);
		SYSTEM_GET_FUNCTION(gglGetnMinmaxARB);
		SYSTEM_GET_FUNCTION(gglGetnPixelMapfvARB);
		SYSTEM_GET_FUNCTION(gglGetnPixelMapuivARB);
		SYSTEM_GET_FUNCTION(gglGetnPixelMapusvARB);
		SYSTEM_GET_FUNCTION(gglGetnPolygonStippleARB);
		SYSTEM_GET_FUNCTION(gglGetnSeparableFilterARB);
		SYSTEM_GET_FUNCTION(gglGetnTexImageARB);
		SYSTEM_GET_FUNCTION(gglGetnUniformdvARB);
		SYSTEM_GET_FUNCTION(gglGetnUniformfvARB);
		SYSTEM_GET_FUNCTION(gglGetnUniformivARB);
		SYSTEM_GET_FUNCTION(gglGetnUniformuivARB);
		SYSTEM_GET_FUNCTION(gglReadnPixelsARB);
	}
	else
	{
		g_ExistsGlArbRobustness = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 106) GL_ARB_shader_stencil_export

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderStencilExport{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderStencilExport() noexcept
{
	return g_ExistsGlArbShaderStencilExport;
}

void System
	::InitGlArbShaderStencilExport() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_stencil_export"))
	{
		g_ExistsGlArbShaderStencilExport = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShaderStencilExport = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 107) GL_ARB_base_instance

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbBaseInstance{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbBaseInstance() noexcept
{
	return g_ExistsGlArbBaseInstance;
}

namespace System
{
	using PgglDrawArraysInstancedBaseInstance = void (OPENGL_STDCALL*)(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
	using PgglDrawElementsInstancedBaseInstance = void (OPENGL_STDCALL*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLuint baseinstance);
	using PgglDrawElementsInstancedBaseVertexBaseInstance = void (OPENGL_STDCALL*)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);
}

namespace System
{
	PgglDrawArraysInstancedBaseInstance gglDrawArraysInstancedBaseInstance{ nullptr };
	PgglDrawElementsInstancedBaseInstance gglDrawElementsInstancedBaseInstance{ nullptr };
	PgglDrawElementsInstancedBaseVertexBaseInstance gglDrawElementsInstancedBaseVertexBaseInstance{ nullptr };
}

void System
	::GlDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance) noexcept
{
	SYSTEM_BODY_5(gglDrawArraysInstancedBaseInstance, mode, first, count, primcount, baseinstance);
}

void System
	::GlDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLuint baseinstance) noexcept
{
	SYSTEM_BODY_6(gglDrawElementsInstancedBaseInstance, mode, count, type, indices, primcount, baseinstance);
}

void System
	::GlDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex, GLuint baseinstance) noexcept
{
	SYSTEM_BODY_7(gglDrawElementsInstancedBaseVertexBaseInstance, mode, count, type, indices, primcount, basevertex, baseinstance);
}

void System
	::InitGlArbBaseInstance() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_base_instance"))
	{
		g_ExistsGlArbBaseInstance = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawArraysInstancedBaseInstance);
		SYSTEM_GET_FUNCTION(gglDrawElementsInstancedBaseInstance);
		SYSTEM_GET_FUNCTION(gglDrawElementsInstancedBaseVertexBaseInstance);
	}
	else
	{
		g_ExistsGlArbBaseInstance = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 108) GL_ARB_shading_language_420pack

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShadingLanguage420pack{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShadingLanguage420pack() noexcept
{
	return g_ExistsGlArbShadingLanguage420pack;
}

void System
	::InitGlArbShadingLanguage420pack() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shading_language_420pack"))
	{
		g_ExistsGlArbShadingLanguage420pack = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShadingLanguage420pack = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 109) GL_ARB_transform_feedback_instanced

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTransformFeedbackInstanced{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTransformFeedbackInstanced() noexcept
{
	return g_ExistsGlArbTransformFeedbackInstanced;
}

namespace System
{
	using PgglDrawTransformFeedbackInstanced = void (OPENGL_STDCALL*) (GLenum mode, GLuint id, GLsizei primcount);
	using PgglDrawTransformFeedbackStreamInstanced = void (OPENGL_STDCALL*) (GLenum mode, GLuint id, GLuint stream, GLsizei primcount);
}

namespace System
{
	PgglDrawTransformFeedbackInstanced gglDrawTransformFeedbackInstanced{ nullptr };
	PgglDrawTransformFeedbackStreamInstanced gglDrawTransformFeedbackStreamInstanced{ nullptr };
}

void System
	::GlDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount) noexcept
{
	SYSTEM_BODY_3(gglDrawTransformFeedbackInstanced, mode, id, primcount);
}

void System
	::GlDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount) noexcept
{
	SYSTEM_BODY_4(gglDrawTransformFeedbackStreamInstanced, mode, id, stream, primcount);
}

void System
	::InitGlArbTransformFeedbackInstanced() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_transform_feedback_instanced"))
	{
		g_ExistsGlArbTransformFeedbackInstanced = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawTransformFeedbackInstanced);
		SYSTEM_GET_FUNCTION(gglDrawTransformFeedbackStreamInstanced);
	}
	else
	{
		g_ExistsGlArbTransformFeedbackInstanced = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 110) GL_ARB_compressed_texture_pixel_storage

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbCompressedTexturePixelStorage{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbCompressedTexturePixelStorage() noexcept
{
	return g_ExistsGlArbCompressedTexturePixelStorage;
}

void System
	::InitGlArbCompressedTexturePixelStorage() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_compressed_texture_pixel_storage"))
	{
		g_ExistsGlArbCompressedTexturePixelStorage = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbCompressedTexturePixelStorage = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 111) GL_ARB_conservative_depth

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbConservativeDepth{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbConservativeDepth() noexcept
{
	return g_ExistsGlArbConservativeDepth;
}

void System
	::InitGlArbConservativeDepth() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_conservative_depth"))
	{
		g_ExistsGlArbConservativeDepth = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbConservativeDepth = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 112) GL_ARB_internalformat_query

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbInternalformatQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbInternalformatQuery() noexcept
{
	return g_ExistsGlArbInternalformatQuery;
}

namespace System
{
	using PgglGetInternalformativ = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLenum parameterName, GLsizei bufSize, GLint* params);
}

namespace System
{
	PgglGetInternalformativ gglGetInternalformativ{ nullptr };
}

void System
	::GlGetInternalformativ(GLenum target, GLenum internalformat, GLenum parameterName, GLsizei bufSize, GLint* params) noexcept
{
	SYSTEM_BODY_5(gglGetInternalformativ, target, internalformat, parameterName, bufSize, params);
}

void System
	::InitGlArbInternalformatQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_internalformat_query"))
	{
		g_ExistsGlArbInternalformatQuery = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetInternalformativ);
	}
	else
	{
		g_ExistsGlArbInternalformatQuery = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 113) GL_ARB_map_buffer_alignment

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMapBufferAlignment{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMapBufferAlignment() noexcept
{
	return g_ExistsGlArbMapBufferAlignment;
}

void System
	::InitGlArbMapBufferAlignment() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_map_buffer_alignment"))
	{
		g_ExistsGlArbMapBufferAlignment = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbMapBufferAlignment = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 114) GL_ARB_shader_atomic_counters

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderAtomicCounters{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderAtomicCounters() noexcept
{
	return g_ExistsGlArbShaderAtomicCounters;
}

namespace System
{
	using PgglGetActiveAtomicCounterBufferiv = void (OPENGL_STDCALL*)(GLuint program, GLuint bufferIndex, GLenum parameterName, GLint* params);
}

namespace System
{
	PgglGetActiveAtomicCounterBufferiv gglGetActiveAtomicCounterBufferiv{ nullptr };
}

void System
	::GlGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetActiveAtomicCounterBufferiv, program, bufferIndex, parameterName, params);
}

void System
	::InitGlArbShaderAtomicCounters() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_atomic_counters"))
	{
		g_ExistsGlArbShaderAtomicCounters = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetActiveAtomicCounterBufferiv);
	}
	else
	{
		g_ExistsGlArbShaderAtomicCounters = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 115) GL_ARB_shader_image_load_store

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderImageLoadStore{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderImageLoadStore() noexcept
{
	return g_ExistsGlArbShaderImageLoadStore;
}

namespace System
{
	using PgglBindImageTexture = void (OPENGL_STDCALL*)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	using PgglMemoryBarrier = void (OPENGL_STDCALL*)(GLbitfield barriers);
}

namespace System
{
	PgglBindImageTexture gglBindImageTexture{ nullptr };
	PgglMemoryBarrier gglMemoryBarrier{ nullptr };
}

void System
	::GlBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) noexcept
{
	SYSTEM_BODY_7(gglBindImageTexture, unit, texture, level, layered, layer, access, format);
}

void System
	::GlMemoryBarrier(GLbitfield barriers) noexcept
{
	SYSTEM_BODY_1(gglMemoryBarrier, barriers);
}

void System
	::InitGlArbShaderImageLoadStore() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_image_load_store"))
	{
		g_ExistsGlArbShaderImageLoadStore = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindImageTexture);
		SYSTEM_GET_FUNCTION(gglMemoryBarrier);
	}
	else
	{
		g_ExistsGlArbShaderImageLoadStore = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 116) GL_ARB_shading_language_packing

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShadingLanguagePacking{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShadingLanguagePacking() noexcept
{
	return g_ExistsGlArbShadingLanguagePacking;
}

void System
	::InitGlArbShadingLanguagePacking() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shading_language_packing"))
	{
		g_ExistsGlArbShadingLanguagePacking = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShadingLanguagePacking = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 117) GL_ARB_texture_storage

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureStorage{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureStorage() noexcept
{
	return g_ExistsGlArbTextureStorage;
}

namespace System
{
	using PgglTexStorage1D = void (OPENGL_STDCALL*) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	using PgglTexStorage2D = void (OPENGL_STDCALL*) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglTexStorage3D = void (OPENGL_STDCALL*) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	using PgglTextureStorage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	using PgglTextureStorage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglTextureStorage3DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
}

namespace System
{
	PgglTexStorage1D gglTexStorage1D{ nullptr };
	PgglTexStorage2D gglTexStorage2D{ nullptr };
	PgglTexStorage3D gglTexStorage3D{ nullptr };
	PgglTextureStorage1DEXT gglTextureStorage1DEXT{ nullptr };
	PgglTextureStorage2DEXT gglTextureStorage2DEXT{ nullptr };
	PgglTextureStorage3DEXT gglTextureStorage3DEXT{ nullptr };
}

void System
	::GlTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) noexcept
{
	SYSTEM_BODY_4(gglTexStorage1D, target, levels, internalformat, width);
}

void System
	::GlTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglTexStorage2D, target, levels, internalformat, width, height);
}

void System
	::GlTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
	SYSTEM_BODY_6(gglTexStorage3D, target, levels, internalformat, width, height, depth);
}

void System
	::GlTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) noexcept
{
	SYSTEM_BODY_5(gglTextureStorage1DEXT, texture, target, levels, internalformat, width);
}

void System
	::GlTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_6(gglTextureStorage2DEXT, texture, target, levels, internalformat, width, height);
}

void System
	::GlTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
	SYSTEM_BODY_7(gglTextureStorage3DEXT, texture, target, levels, internalformat, width, height, depth);
}

void System
	::InitGlArbTextureStorage() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_storage"))
	{
		g_ExistsGlArbTextureStorage = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTexStorage1D);
		SYSTEM_GET_FUNCTION(gglTexStorage2D);
		SYSTEM_GET_FUNCTION(gglTexStorage3D);
		SYSTEM_GET_FUNCTION(gglTextureStorage1DEXT);
		SYSTEM_GET_FUNCTION(gglTextureStorage2DEXT);
		SYSTEM_GET_FUNCTION(gglTextureStorage3DEXT);
	}
	else
	{
		g_ExistsGlArbTextureStorage = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 120) GL_ARB_arrays_of_arrays

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbArraysOfArrays{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbArraysOfArrays() noexcept
{
	return g_ExistsGlArbArraysOfArrays;
}

void System
	::InitGlArbArraysOfArrays() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_arrays_of_arrays"))
	{
		g_ExistsGlArbArraysOfArrays = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbArraysOfArrays = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 121) GL_ARB_clear_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbClearBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbClearBufferObject() noexcept
{
	return g_ExistsGlArbClearBufferObject;
}

namespace System
{
	using PgglClearBufferData = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data);
	using PgglClearBufferSubData = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
	using PgglClearNamedBufferDataEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data);
	using PgglClearNamedBufferSubDataEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
}

namespace System
{
	PgglClearBufferData gglClearBufferData{ nullptr };
	PgglClearBufferSubData gglClearBufferSubData{ nullptr };
	PgglClearNamedBufferDataEXT gglClearNamedBufferDataEXT{ nullptr };
	PgglClearNamedBufferSubDataEXT gglClearNamedBufferSubDataEXT{ nullptr };
}

void System
	::GlClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_5(gglClearBufferData, target, internalformat, format, type, data);
}

void System
	::GlClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglClearBufferSubData, target, internalformat, offset, size, format, type, data);
}

void System
	::GlClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_5(gglClearNamedBufferDataEXT, buffer, internalformat, format, type, data);
}

void System
	::GlClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglClearNamedBufferSubDataEXT, buffer, internalformat, offset, size, format, type, data);
}

void System
	::InitGlArbClearBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_clear_buffer_object"))
	{
		g_ExistsGlArbClearBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglClearBufferData);
		SYSTEM_GET_FUNCTION(gglClearBufferSubData);
		SYSTEM_GET_FUNCTION(gglClearNamedBufferDataEXT);
		SYSTEM_GET_FUNCTION(gglClearNamedBufferSubDataEXT);
	}
	else
	{
		g_ExistsGlArbClearBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 122) GL_ARB_compute_shader

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbComputeShader{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbComputeShader() noexcept
{
	return g_ExistsGlArbComputeShader;
}

namespace System
{
	using PgglDispatchCompute = void (OPENGL_STDCALL*) (GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ);
	using PgglDispatchComputeIndirect = void (OPENGL_STDCALL*) (GLintptr indirect);
}

namespace System
{
	PgglDispatchCompute gglDispatchCompute{ nullptr };
	PgglDispatchComputeIndirect gglDispatchComputeIndirect{ nullptr };
}

void System
	::GlDispatchCompute(GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ) noexcept
{
	SYSTEM_BODY_3(gglDispatchCompute, numGroupsX, numGroupsY, numGroupsZ);
}

void System
	::GlDispatchComputeIndirect(GLintptr indirect) noexcept
{
	SYSTEM_BODY_1(gglDispatchComputeIndirect, indirect);
}

void System
	::InitGlArbComputeShader() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_compute_shader"))
	{
		g_ExistsGlArbComputeShader = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDispatchCompute);
		SYSTEM_GET_FUNCTION(gglDispatchComputeIndirect);
	}
	else
	{
		g_ExistsGlArbComputeShader = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 123) GL_ARB_copy_image

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbCopyImage{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbCopyImage() noexcept
{
	return g_ExistsGlArbCopyImage;
}

namespace System
{
	using PgglCopyImageSubData = void (OPENGL_STDCALL*) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName,
														 GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
}

namespace System
{
	PgglCopyImageSubData gglCopyImageSubData{ nullptr };
}

void System
	::GlCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget,
						 GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) noexcept
{
	SYSTEM_BODY_15(gglCopyImageSubData, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
}

void System
	::InitGlArbCopyImage() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_copy_image"))
	{
		g_ExistsGlArbCopyImage = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCopyImageSubData);
	}
	else
	{
		g_ExistsGlArbCopyImage = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 124) GL_ARB_texture_view

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureView{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureView() noexcept
{
	return g_ExistsGlArbTextureView;
}

namespace System
{
	using PgglTextureView = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
}

namespace System
{
	PgglTextureView  gglTextureView{ nullptr };
}

void System
	::GlTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) noexcept
{
	SYSTEM_BODY_8(gglTextureView, texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
}

void System
	::InitGlArbTextureView() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_view"))
	{
		g_ExistsGlArbTextureView = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTextureView);
	}
	else
	{
		g_ExistsGlArbTextureView = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 125) GL_ARB_vertex_attrib_binding

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexAttribBinding{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexAttribBinding() noexcept
{
	return g_ExistsGlArbVertexAttribBinding;
}

namespace System
{
	using PgglBindVertexBuffer = void (OPENGL_STDCALL*) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
	using PgglVertexAttribBinding = void (OPENGL_STDCALL*) (GLuint attribindex, GLuint bindingindex);
	using PgglVertexAttribFormat = void (OPENGL_STDCALL*) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	using PgglVertexAttribIFormat = void (OPENGL_STDCALL*) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	using PgglVertexAttribLFormat = void (OPENGL_STDCALL*) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	using PgglVertexBindingDivisor = void (OPENGL_STDCALL*) (GLuint bindingindex, GLuint divisor);
}

namespace System
{
	PgglBindVertexBuffer gglBindVertexBuffer{ nullptr };
	PgglVertexAttribBinding gglVertexAttribBinding{ nullptr };
	PgglVertexAttribFormat gglVertexAttribFormat{ nullptr };
	PgglVertexAttribIFormat gglVertexAttribIFormat{ nullptr };
	PgglVertexAttribLFormat gglVertexAttribLFormat{ nullptr };
	PgglVertexBindingDivisor gglVertexBindingDivisor{ nullptr };
}

void System
	::GlBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept
{
	SYSTEM_BODY_4(gglBindVertexBuffer, bindingindex, buffer, offset, stride);
}

void System
	::GlVertexAttribBinding(GLuint attribindex, GLuint bindingindex) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribBinding, attribindex, bindingindex);
}

void System
	::GlVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribFormat, attribindex, size, type, normalized, relativeoffset);
}

void System
	::GlVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribIFormat, attribindex, size, type, relativeoffset);
}

void System
	::GlVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribLFormat, attribindex, size, type, relativeoffset);
}

void System
	::GlVertexBindingDivisor(GLuint bindingindex, GLuint divisor) noexcept
{
	SYSTEM_BODY_2(gglVertexBindingDivisor, bindingindex, divisor);
}

void System
	::InitGlArbVertexAttribBinding() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_attrib_binding"))
	{
		g_ExistsGlArbVertexAttribBinding = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindVertexBuffer);
		SYSTEM_GET_FUNCTION(gglVertexAttribBinding);
		SYSTEM_GET_FUNCTION(gglVertexAttribFormat);
		SYSTEM_GET_FUNCTION(gglVertexAttribIFormat);
		SYSTEM_GET_FUNCTION(gglVertexAttribLFormat);
		SYSTEM_GET_FUNCTION(gglVertexBindingDivisor);
	}
	else
	{
		g_ExistsGlArbVertexAttribBinding = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 128) GL_ARB_explicit_uniform_location

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbExplicitUniformLocation{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbExplicitUniformLocation() noexcept
{
	return g_ExistsGlArbExplicitUniformLocation;
}

void System
	::InitGlArbExplicitUniformLocation() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_explicit_uniform_location"))
	{
		g_ExistsGlArbExplicitUniformLocation = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbExplicitUniformLocation = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 129) GL_ARB_fragment_layer_viewport

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFragmentLayerViewport{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFragmentLayerViewport() noexcept
{
	return g_ExistsGlArbFragmentLayerViewport;
}

void System
	::InitGlArbFragmentLayerViewport() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_fragment_layer_viewport"))
	{
		g_ExistsGlArbFragmentLayerViewport = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbFragmentLayerViewport = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 130) GL_ARB_framebuffer_no_attachments

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbFramebufferNoAttachments{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbFramebufferNoAttachments() noexcept
{
	return g_ExistsGlArbFramebufferNoAttachments;
}

namespace System
{
	using PgglFramebufferParameteri = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, GLint param);
	using PgglGetFramebufferParameteriv = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, GLint* params);
	using PgglGetNamedFramebufferParameterivEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum parameterName, GLint* params);
	using PgglNamedFramebufferParameteriEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum parameterName, GLint param);
}

namespace System
{
	PgglFramebufferParameteri gglFramebufferParameteri{ nullptr };
	PgglGetFramebufferParameteriv gglGetFramebufferParameteriv{ nullptr };
	PgglGetNamedFramebufferParameterivEXT gglGetNamedFramebufferParameterivEXT{ nullptr };
	PgglNamedFramebufferParameteriEXT gglNamedFramebufferParameteriEXT{ nullptr };
}

void System
	::GlFramebufferParameteri(GLenum target, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_3(gglFramebufferParameteri, target, parameterName, param);
}

void System
	::GlGetFramebufferParameteriv(GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetFramebufferParameteriv, target, parameterName, params);
}

void System
	::GlGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedFramebufferParameterivEXT, framebuffer, parameterName, params);
}

void System
	::GlNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_3(gglNamedFramebufferParameteriEXT, framebuffer, parameterName, param);
}

void System
	::InitGlArbFramebufferNoAttachments() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_framebuffer_no_attachments"))
	{
		g_ExistsGlArbFramebufferNoAttachments = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglFramebufferParameteri);
		SYSTEM_GET_FUNCTION(gglGetFramebufferParameteriv);
		SYSTEM_GET_FUNCTION(gglGetNamedFramebufferParameterivEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferParameteriEXT);
	}
	else
	{
		g_ExistsGlArbFramebufferNoAttachments = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 131) GL_ARB_internalformat_query2

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbInternalformatQuery2{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbInternalformatQuery2() noexcept
{
	return g_ExistsGlArbInternalformatQuery2;
}

namespace System
{
	typedef void (OPENGL_STDCALL* PgglGetInternalformati64v) (GLenum target, GLenum internalformat, GLenum parameterName, GLsizei bufSize, GLint64* params);
}

namespace System
{
	PgglGetInternalformati64v gglGetInternalformati64v{ nullptr };
}

void System
	::GlGetInternalformati64v(GLenum target, GLenum internalformat, GLenum parameterName, GLsizei bufSize, GLint64* params) noexcept
{
	SYSTEM_BODY_5(gglGetInternalformati64v, target, internalformat, parameterName, bufSize, params);
}

void System
	::InitGlArbInternalformatQuery2() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_internalformat_query2"))
	{
		g_ExistsGlArbInternalformatQuery2 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetInternalformati64v);
	}
	else
	{
		g_ExistsGlArbInternalformatQuery2 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 132) GL_ARB_invalidate_subdata

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbInvalidateSubdata{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbInvalidateSubdata() noexcept
{
	return g_ExistsGlArbInvalidateSubdata;
}

namespace System
{
	using PgglInvalidateBufferData = void (OPENGL_STDCALL*) (GLuint buffer);
	using PgglInvalidateBufferSubData = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr length);
	using PgglInvalidateFramebuffer = void (OPENGL_STDCALL*) (GLenum target, GLsizei numAttachments, const GLenum* attachments);
	using PgglInvalidateSubFramebuffer = void (OPENGL_STDCALL*) (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglInvalidateTexImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level);
	using PgglInvalidateTexSubImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
}

namespace System
{
	PgglInvalidateBufferData gglInvalidateBufferData{ nullptr };
	PgglInvalidateBufferSubData gglInvalidateBufferSubData{ nullptr };
	PgglInvalidateFramebuffer gglInvalidateFramebuffer{ nullptr };
	PgglInvalidateSubFramebuffer gglInvalidateSubFramebuffer{ nullptr };
	PgglInvalidateTexImage gglInvalidateTexImage{ nullptr };
	PgglInvalidateTexSubImage gglInvalidateTexSubImage{ nullptr };
}

void System
	::GlInvalidateBufferData(GLuint buffer) noexcept
{
	SYSTEM_BODY_1(gglInvalidateBufferData, buffer);
}

void System
	::GlInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept
{
	SYSTEM_BODY_3(gglInvalidateBufferSubData, buffer, offset, length);
}

void System
	::GlInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments) noexcept
{
	SYSTEM_BODY_3(gglInvalidateFramebuffer, target, numAttachments, attachments);
}

void System
	::GlInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_7(gglInvalidateSubFramebuffer, target, numAttachments, attachments, x, y, width, height);
}

void System
	::GlInvalidateTexImage(GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_2(gglInvalidateTexImage, texture, level);
}

void System
	::GlInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
	SYSTEM_BODY_8(gglInvalidateTexSubImage, texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

void System
	::InitGlArbInvalidateSubdata() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_invalidate_subdata"))
	{
		g_ExistsGlArbInvalidateSubdata = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglInvalidateBufferData);
		SYSTEM_GET_FUNCTION(gglInvalidateBufferSubData);
		SYSTEM_GET_FUNCTION(gglInvalidateFramebuffer);
		SYSTEM_GET_FUNCTION(gglInvalidateSubFramebuffer);
		SYSTEM_GET_FUNCTION(gglInvalidateTexImage);
		SYSTEM_GET_FUNCTION(gglInvalidateTexSubImage);
	}
	else
	{
		g_ExistsGlArbInvalidateSubdata = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 133) GL_ARB_multi_draw_indirect

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMultiDrawIndirect{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMultiDrawIndirect() noexcept
{
	return g_ExistsGlArbMultiDrawIndirect;
}

namespace System
{
	using PgglMultiDrawArraysIndirect = void (OPENGL_STDCALL*) (GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
	using PgglMultiDrawElementsIndirect = void (OPENGL_STDCALL*) (GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride);
}

namespace System
{
	PgglMultiDrawArraysIndirect gglMultiDrawArraysIndirect{ nullptr };
	PgglMultiDrawElementsIndirect gglMultiDrawElementsIndirect{ nullptr };
}

void System
	::GlMultiDrawArraysIndirect(GLenum mode, const GLvoid* indirect, GLsizei primcount, GLsizei stride) noexcept
{
	SYSTEM_BODY_4(gglMultiDrawArraysIndirect, mode, indirect, primcount, stride);
}

void System
	::GlMultiDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid* indirect, GLsizei primcount, GLsizei stride) noexcept
{
	SYSTEM_BODY_5(gglMultiDrawElementsIndirect, mode, type, indirect, primcount, stride);
}

void System
	::InitGlArbMultiDrawIndirect() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_multi_draw_indirect"))
	{
		g_ExistsGlArbMultiDrawIndirect = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglMultiDrawArraysIndirect);
		SYSTEM_GET_FUNCTION(gglMultiDrawElementsIndirect);
	}
	else
	{
		g_ExistsGlArbMultiDrawIndirect = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 134) GL_ARB_program_interface_query

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbProgramInterfaceQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbProgramInterfaceQuery() noexcept
{
	return g_ExistsGlArbProgramInterfaceQuery;
}

namespace System
{
	using PgglGetProgramInterfaceiv = void (OPENGL_STDCALL*) (GLuint program, GLenum programInterface, GLenum parameterName, GLint* params);
	using PgglGetProgramResourceIndex = GLuint(OPENGL_STDCALL*) (GLuint program, GLenum programInterface, const GLchar* name);
	using PgglGetProgramResourceLocation = GLint(OPENGL_STDCALL*)(GLuint program, GLenum programInterface, const GLchar* name);
	using PgglGetProgramResourceLocationIndex = GLint(OPENGL_STDCALL*)(GLuint program, GLenum programInterface, const GLchar* name);
	using PgglGetProgramResourceName = void (OPENGL_STDCALL*) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
	using PgglGetProgramResourceiv = void (OPENGL_STDCALL*) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params);
}

namespace System
{
	PgglGetProgramInterfaceiv gglGetProgramInterfaceiv{ nullptr };
	PgglGetProgramResourceIndex gglGetProgramResourceIndex{ nullptr };
	PgglGetProgramResourceLocation gglGetProgramResourceLocation{ nullptr };
	PgglGetProgramResourceLocationIndex gglGetProgramResourceLocationIndex{ nullptr };
	PgglGetProgramResourceName gglGetProgramResourceName{ nullptr };
	PgglGetProgramResourceiv gglGetProgramResourceiv{ nullptr };
}

void System
	::GlGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetProgramInterfaceiv, program, programInterface, parameterName, params);
}

GLuint System
	::GlGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept
{
	SYSTEM_BODY_3_RESULT(gglGetProgramResourceIndex, program, programInterface, name, GLuint, 0);
}

GLint System
	::GlGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar* name) noexcept
{
	SYSTEM_BODY_3_RESULT(gglGetProgramResourceLocation, program, programInterface, name, GLint, -1);
}

GLint System
	::GlGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar* name) noexcept
{
	SYSTEM_BODY_3_RESULT(gglGetProgramResourceLocationIndex, program, programInterface, name, GLint, -1);
}


void System
	::GlGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name) noexcept
{
	SYSTEM_BODY_6(gglGetProgramResourceName, program, programInterface, index, bufSize, length, name);
}

void System
	::GlGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params) noexcept
{
	SYSTEM_BODY_8(gglGetProgramResourceiv, program, programInterface, index, propCount, props, bufSize, length, params);
}

void System
	::InitGlArbProgramInterfaceQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_program_interface_query"))
	{
		g_ExistsGlArbProgramInterfaceQuery = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetProgramInterfaceiv);
		SYSTEM_GET_FUNCTION(gglGetProgramResourceIndex);
		SYSTEM_GET_FUNCTION(gglGetProgramResourceLocation);
		SYSTEM_GET_FUNCTION(gglGetProgramResourceLocationIndex);
		SYSTEM_GET_FUNCTION(gglGetProgramResourceName);
		SYSTEM_GET_FUNCTION(gglGetProgramResourceiv);
	}
	else
	{
		g_ExistsGlArbProgramInterfaceQuery = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 135) GL_ARB_robust_buffer_access_behavior

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbRobustBufferAccessBehavior{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbRobustBufferAccessBehavior() noexcept
{
	return g_ExistsGlArbRobustBufferAccessBehavior;
}

void System
	::InitGlArbRobustBufferAccessBehavior() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_robust_buffer_access_behavior"))
	{
		g_ExistsGlArbRobustBufferAccessBehavior = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbRobustBufferAccessBehavior = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 136) GL_ARB_shader_image_size

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderImageSize{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderImageSize() noexcept
{
	return g_ExistsGlArbShaderImageSize;
}

void System
	::InitGlArbShaderImageSize() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_image_size"))
	{
		g_ExistsGlArbShaderImageSize = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShaderImageSize = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 137) GL_ARB_shader_storage_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderStorageBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderStorageBufferObject() noexcept
{
	return g_ExistsGlArbShaderStorageBufferObject;
}

namespace System
{
	using PgglShaderStorageBlockBinding = void (OPENGL_STDCALL*) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
}

namespace System
{
	PgglShaderStorageBlockBinding gglShaderStorageBlockBinding{ nullptr };
}

void System
	::GlShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) noexcept
{
	SYSTEM_BODY_3(gglShaderStorageBlockBinding, program, storageBlockIndex, storageBlockBinding);
}

void System
	::InitGlArbShaderStorageBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_storage_buffer_object"))
	{
		g_ExistsGlArbShaderStorageBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglShaderStorageBlockBinding);
	}
	else
	{
		g_ExistsGlArbShaderStorageBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 138) GL_ARB_stencil_texturing

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbStencilTexturing{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbStencilTexturing() noexcept
{
	return g_ExistsGlArbStencilTexturing;
}

void System
	::InitGlArbStencilTexturing() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_stencil_texturing"))
	{
		g_ExistsGlArbStencilTexturing = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbStencilTexturing = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 139) GL_ARB_texture_buffer_range

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureBufferRange{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureBufferRange() noexcept
{
	return g_ExistsGlArbTextureBufferRange;
}

namespace System
{
	using PgglTexBufferRange = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);

	typedef void (OPENGL_STDCALL* PgglTextureBufferRangeEXT) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
}

namespace System
{
	PgglTexBufferRange gglTexBufferRange{ nullptr };
	PgglTextureBufferRangeEXT gglTextureBufferRangeEXT{ nullptr };
}

void System
	::GlTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglTexBufferRange, target, internalformat, buffer, offset, size);
}

void System
	::GlTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_6(gglTextureBufferRangeEXT, texture, target, internalformat, buffer, offset, size);
}

void System
	::InitGlArbTextureBufferRange() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_buffer_range"))
	{
		g_ExistsGlArbTextureBufferRange = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTexBufferRange);
		SYSTEM_GET_FUNCTION(gglTextureBufferRangeEXT);
	}
	else
	{
		g_ExistsGlArbTextureBufferRange = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 140) GL_ARB_texture_query_levels

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureQueryLevels{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureQueryLevels() noexcept
{
	return g_ExistsGlArbTextureQueryLevels;
}

void System
	::InitGlArbTextureQueryLevels() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_query_levels"))
	{
		g_ExistsGlArbTextureQueryLevels = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureQueryLevels = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 141) GL_ARB_texture_storage_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureStorageMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureStorageMultisample() noexcept
{
	return g_ExistsGlArbTextureStorageMultisample;
}

namespace System
{
	using PgglTexStorage2DMultisample = void (OPENGL_STDCALL*) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	using PgglTexStorage3DMultisample = void (OPENGL_STDCALL*) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
																GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	using PgglTextureStorage2DMultisampleEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat,
																	   GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	using PgglTextureStorage3DMultisampleEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat,
																	   GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
}

namespace System
{
	PgglTexStorage2DMultisample gglTexStorage2DMultisample{ nullptr };
	PgglTexStorage3DMultisample gglTexStorage3DMultisample{ nullptr };
	PgglTextureStorage2DMultisampleEXT gglTextureStorage2DMultisampleEXT{ nullptr };
	PgglTextureStorage3DMultisampleEXT gglTextureStorage3DMultisampleEXT{ nullptr };
}

void System
	::GlTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_6(gglTexStorage2DMultisample, target, samples, internalformat, width, height, fixedsamplelocations);
}

void System
	::GlTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_7(gglTexStorage3DMultisample, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void System
	::GlTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_7(gglTextureStorage2DMultisampleEXT, texture, target, samples, internalformat, width, height, fixedsamplelocations);
}

void System
	::GlTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_8(gglTextureStorage3DMultisampleEXT, texture, target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void System
	::InitGlArbTextureStorageMultisample() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_storage_multisample"))
	{
		g_ExistsGlArbTextureStorageMultisample = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTexStorage2DMultisample);
		SYSTEM_GET_FUNCTION(gglTexStorage3DMultisample);
		SYSTEM_GET_FUNCTION(gglTextureStorage2DMultisampleEXT);
		SYSTEM_GET_FUNCTION(gglTextureStorage3DMultisampleEXT);
	}
	else
	{
		g_ExistsGlArbTextureStorageMultisample = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 144) GL_ARB_buffer_storage

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbBufferStorage{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbBufferStorage() noexcept
{
	return g_ExistsGlArbBufferStorage;
}

namespace System
{
	using PgglBufferStorage = void (OPENGL_STDCALL*) (GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
	using PgglNamedBufferStorageEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
}

namespace System
{
	PgglBufferStorage gglBufferStorage{ nullptr };
	PgglNamedBufferStorageEXT gglNamedBufferStorageEXT{ nullptr };
}

void System
	::GlBufferStorage(GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags) noexcept
{
	SYSTEM_BODY_4(gglBufferStorage, target, size, data, flags);
}

void System
	::GlNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags) noexcept
{
	SYSTEM_BODY_4(gglNamedBufferStorageEXT, buffer, size, data, flags);
}

void System
	::InitGlArbBufferStorage() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_buffer_storage"))
	{
		g_ExistsGlArbBufferStorage = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBufferStorage);
		SYSTEM_GET_FUNCTION(gglNamedBufferStorageEXT);
	}
	else
	{
		g_ExistsGlArbBufferStorage = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 145) GL_ARB_clear_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbClearTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbClearTexture() noexcept
{
	return g_ExistsGlArbClearTexture;
}

namespace System
{
	using PgglClearTexImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data);
	using PgglClearTexSubImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
														 GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data);
}

namespace System
{
	PgglClearTexImage gglClearTexImage{ nullptr };
	PgglClearTexSubImage gglClearTexSubImage{ nullptr };
}

void System
	::GlClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_5(gglClearTexImage, texture, level, format, type, data);
}

void System
	::GlClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_11(gglClearTexSubImage, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
}

void System
	::InitGlArbClearTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_clear_texture"))
	{
		g_ExistsGlArbClearTexture = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglClearTexImage);
		SYSTEM_GET_FUNCTION(gglClearTexSubImage);
	}
	else
	{
		g_ExistsGlArbClearTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 146) GL_ARB_enhanced_layouts

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbEnhancedLayouts{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbEnhancedLayouts() noexcept
{
	return g_ExistsGlArbEnhancedLayouts;
}

void System
	::InitGlArbEnhancedLayouts() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_enhanced_layouts"))
	{
		g_ExistsGlArbEnhancedLayouts = ExistsOpenGLExtensions::Exists;

	}
	else
	{
		g_ExistsGlArbEnhancedLayouts = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 147) GL_ARB_multi_bind

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbMultiBind{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbMultiBind() noexcept
{
	return g_ExistsGlArbMultiBind;
}

namespace System
{
	using PgglBindBuffersBase = void (OPENGL_STDCALL*) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
	using PgglBindBuffersRange = void (OPENGL_STDCALL*) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
	using PgglBindImageTextures = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLuint* textures);
	using PgglBindSamplers = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLuint* samplers);
	using PgglBindTextures = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLuint* textures);
	using PgglBindVertexBuffers = void (OPENGL_STDCALL*) (GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizei *strides);
}

namespace System
{
	PgglBindBuffersBase gglBindBuffersBase{ nullptr };
	PgglBindBuffersRange gglBindBuffersRange{ nullptr };
	PgglBindImageTextures gglBindImageTextures{ nullptr };
	PgglBindSamplers gglBindSamplers{ nullptr };
	PgglBindTextures gglBindTextures{ nullptr };
	PgglBindVertexBuffers gglBindVertexBuffers{ nullptr };
}

void System
	::GlBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers) noexcept
{
	SYSTEM_BODY_4(gglBindBuffersBase, target, first, count, buffers);
}

void System
	::GlBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes) noexcept
{
	SYSTEM_BODY_6(gglBindBuffersRange, target, first, count, buffers, offsets, sizes);
}

void System
	::GlBindImageTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept
{
	SYSTEM_BODY_3(gglBindImageTextures, first, count, textures);
}

void System
	::GlBindSamplers(GLuint first, GLsizei count, const GLuint* samplers) noexcept
{
	SYSTEM_BODY_3(gglBindSamplers, first, count, samplers);
}

void System
	::GlBindTextures(GLuint first, GLsizei count, const GLuint* textures) noexcept
{
	SYSTEM_BODY_3(gglBindTextures, first, count, textures);
}

void System
	::GlBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept
{
	SYSTEM_BODY_5(gglBindVertexBuffers, first, count, buffers, offsets, strides);
}

void System
	::InitGlArbMultiBind() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_multi_bind"))
	{
		g_ExistsGlArbMultiBind = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindBuffersBase);
		SYSTEM_GET_FUNCTION(gglBindBuffersRange);
		SYSTEM_GET_FUNCTION(gglBindImageTextures);
		SYSTEM_GET_FUNCTION(gglBindSamplers);
		SYSTEM_GET_FUNCTION(gglBindTextures);
		SYSTEM_GET_FUNCTION(gglBindVertexBuffers);
	}
	else
	{
		g_ExistsGlArbMultiBind = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 148) GL_ARB_query_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbQueryBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbQueryBufferObject() noexcept
{
	return g_ExistsGlArbQueryBufferObject;
}

void System
	::InitGlArbQueryBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_query_buffer_object"))
	{
		g_ExistsGlArbQueryBufferObject = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbQueryBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 149) GL_ARB_texture_mirror_clamp_to_edge

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureMirrorClampToEdge{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureMirrorClampToEdge() noexcept
{
	return g_ExistsGlArbTextureMirrorClampToEdge;
}

void System
	::InitGlArbTextureMirrorClampToEdge() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_mirror_clamp_to_edge"))
	{
		g_ExistsGlArbTextureMirrorClampToEdge = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureMirrorClampToEdge = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 150) GL_ARB_texture_stencil8

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureStencil8{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureStencil8() noexcept
{
	return g_ExistsGlArbTextureStencil8;
}

void System
	::InitGlArbTextureStencil8() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_stencil8"))
	{
		g_ExistsGlArbTextureStencil8 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureStencil8 = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 151) GL_ARB_vertex_type_10f_11f_11f_rev

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbVertexType10f11f11fRev{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbVertexType10f11f11fRev() noexcept
{
	return g_ExistsGlArbVertexType10f11f11fRev;
}

void System
	::InitGlArbVertexType10f11f11fRev() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_vertex_type_10f_11f_11f_rev"))
	{
		g_ExistsGlArbVertexType10f11f11fRev = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbVertexType10f11f11fRev = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 152) GL_ARB_bindless_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbBindlessTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbBindlessTexture() noexcept
{
	return g_ExistsGlArbBindlessTexture;
}

namespace System
{
	using PgglGetImageHandleARB = GLuint64(OPENGL_STDCALL*) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
	using PgglGetTextureHandleARB = GLuint64(OPENGL_STDCALL*) (GLuint texture);
	using PgglGetTextureSamplerHandleARB = GLuint64(OPENGL_STDCALL*) (GLuint texture, GLuint sampler);
	using PgglGetVertexAttribLui64vARB = void (OPENGL_STDCALL*) (GLuint index, GLenum parameterName, GLuint64* params);
	using PgglIsImageHandleResidentARB = GLboolean(OPENGL_STDCALL*) (GLuint64 handle);
	using PgglIsTextureHandleResidentARB = GLboolean(OPENGL_STDCALL*) (GLuint64 handle);
	using PgglMakeImageHandleNonResidentARB = void (OPENGL_STDCALL*) (GLuint64 handle);
	using PgglMakeImageHandleResidentARB = void (OPENGL_STDCALL*) (GLuint64 handle, GLenum access);
	using PgglMakeTextureHandleNonResidentARB = void (OPENGL_STDCALL*) (GLuint64 handle);
	using PgglMakeTextureHandleResidentARB = void (OPENGL_STDCALL*) (GLuint64 handle);
	using PgglProgramUniformHandleui64ARB = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint64 value);
	using PgglProgramUniformHandleui64vARB = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint64* values);
	using PgglUniformHandleui64ARB = void (OPENGL_STDCALL*) (GLint location, GLuint64 value);
	using PgglUniformHandleui64vARB = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLuint64* value);
	using PgglVertexAttribL1ui64ARB = void (OPENGL_STDCALL*) (GLuint index, GLuint64 x);
	using PgglVertexAttribL1ui64vARB = void (OPENGL_STDCALL*) (GLuint index, const GLuint64* v);
}

namespace System
{
	PgglGetImageHandleARB gglGetImageHandleARB{ nullptr };
	PgglGetTextureHandleARB gglGetTextureHandleARB{ nullptr };
	PgglGetTextureSamplerHandleARB gglGetTextureSamplerHandleARB{ nullptr };
	PgglGetVertexAttribLui64vARB gglGetVertexAttribLui64vARB{ nullptr };
	PgglIsImageHandleResidentARB gglIsImageHandleResidentARB{ nullptr };
	PgglIsTextureHandleResidentARB gglIsTextureHandleResidentARB{ nullptr };
	PgglMakeImageHandleNonResidentARB gglMakeImageHandleNonResidentARB{ nullptr };
	PgglMakeImageHandleResidentARB gglMakeImageHandleResidentARB{ nullptr };
	PgglMakeTextureHandleNonResidentARB gglMakeTextureHandleNonResidentARB{ nullptr };
	PgglMakeTextureHandleResidentARB gglMakeTextureHandleResidentARB{ nullptr };
	PgglProgramUniformHandleui64ARB gglProgramUniformHandleui64ARB{ nullptr };
	PgglProgramUniformHandleui64vARB gglProgramUniformHandleui64vARB{ nullptr };
	PgglUniformHandleui64ARB gglUniformHandleui64ARB{ nullptr };
	PgglUniformHandleui64vARB gglUniformHandleui64vARB{ nullptr };
	PgglVertexAttribL1ui64ARB gglVertexAttribL1ui64ARB{ nullptr };
	PgglVertexAttribL1ui64vARB gglVertexAttribL1ui64vARB{ nullptr };
}

GLuint64 System
	::GlGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) noexcept
{
	SYSTEM_BODY_5_RESULT(gglGetImageHandleARB, texture, level, layered, layer, format, GLuint64, 0);
}

GLuint64 System
	::GlGetTextureHandleARB(GLuint texture) noexcept
{
	SYSTEM_BODY_1_RESULT(gglGetTextureHandleARB, texture, GLuint64, 0);
}

GLuint64 System
	::GlGetTextureSamplerHandleARB(GLuint texture, GLuint sampler) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetTextureSamplerHandleARB, texture, sampler, GLuint64, 0);
}

void System
	::GlGetVertexAttribLui64vARB(GLuint index, GLenum parameterName, GLuint64* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribLui64vARB, index, parameterName, params);
}

GLboolean System
	::GlIsImageHandleResidentARB(GLuint64 handle) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsImageHandleResidentARB, handle, GLboolean, GL_FALSE);
}

GLboolean System
	::GlIsTextureHandleResidentARB(GLuint64 handle) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsTextureHandleResidentARB, handle, GLboolean, GL_FALSE);
}

void System
	::GlMakeImageHandleNonResidentARB(GLuint64 handle) noexcept
{
	SYSTEM_BODY_1(gglMakeImageHandleNonResidentARB, handle);
}

void System
	::GlMakeImageHandleResidentARB(GLuint64 handle, GLenum access) noexcept
{
	SYSTEM_BODY_2(gglMakeImageHandleResidentARB, handle, access);
}

void System
	::GlMakeTextureHandleNonResidentARB(GLuint64 handle) noexcept
{
	SYSTEM_BODY_1(gglMakeTextureHandleNonResidentARB, handle);
}

void System
	::GlMakeTextureHandleResidentARB(GLuint64 handle) noexcept
{
	SYSTEM_BODY_1(gglMakeTextureHandleResidentARB, handle);
}

void System
	::GlProgramUniformHandleui64ARB(GLuint program, GLint location, GLuint64 value) noexcept
{
	SYSTEM_BODY_3(gglProgramUniformHandleui64ARB, program, location, value);
}

void System
	::GlProgramUniformHandleui64vARB(GLuint program, GLint location, GLsizei count, const GLuint64* values) noexcept
{
	SYSTEM_BODY_4(gglProgramUniformHandleui64vARB, program, location, count, values);
}

void System
	::GlUniformHandleui64ARB(GLint location, GLuint64 value) noexcept
{
	SYSTEM_BODY_2(gglUniformHandleui64ARB, location, value);
}

void System
	::GlUniformHandleui64vARB(GLint location, GLsizei count, const GLuint64* value) noexcept
{
	SYSTEM_BODY_3(gglUniformHandleui64vARB, location, count, value);
}

void System
	::GlVertexAttribL1ui64ARB(GLuint index, GLuint64 x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL1ui64ARB, index, x);
}

void System
	::GlVertexAttribL1ui64vARB(GLuint index, const GLuint64* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL1ui64vARB, index, v);
}

void System
	::InitGlArbBindlessTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_bindless_texture"))
	{
		g_ExistsGlArbBindlessTexture = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetImageHandleARB);
		SYSTEM_GET_FUNCTION(gglGetTextureHandleARB);
		SYSTEM_GET_FUNCTION(gglGetTextureSamplerHandleARB);
		SYSTEM_GET_FUNCTION(gglGetVertexAttribLui64vARB);
		SYSTEM_GET_FUNCTION(gglIsImageHandleResidentARB);
		SYSTEM_GET_FUNCTION(gglIsTextureHandleResidentARB);
		SYSTEM_GET_FUNCTION(gglMakeImageHandleNonResidentARB);
		SYSTEM_GET_FUNCTION(gglMakeImageHandleResidentARB);
		SYSTEM_GET_FUNCTION(gglMakeTextureHandleNonResidentARB);
		SYSTEM_GET_FUNCTION(gglMakeTextureHandleResidentARB);
		SYSTEM_GET_FUNCTION(gglProgramUniformHandleui64ARB);
		SYSTEM_GET_FUNCTION(gglProgramUniformHandleui64vARB);
		SYSTEM_GET_FUNCTION(gglUniformHandleui64ARB);
		SYSTEM_GET_FUNCTION(gglUniformHandleui64vARB);
		SYSTEM_GET_FUNCTION(gglVertexAttribL1ui64ARB);
		SYSTEM_GET_FUNCTION(gglVertexAttribL1ui64vARB);
	}
	else
	{
		g_ExistsGlArbBindlessTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 153) GL_ARB_compute_variable_group_size

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbComputeCariableGroupSize{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbComputeCariableGroupSize() noexcept
{
	return g_ExistsGlArbComputeCariableGroupSize;
}

namespace System
{
	using PgglDispatchComputeGroupSizeARB = void (OPENGL_STDCALL*) (GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ, GLuint groupSizeX, GLuint groupSizeY, GLuint groupSizeZ);
}

namespace System
{
	PgglDispatchComputeGroupSizeARB gglDispatchComputeGroupSizeARB{ nullptr };
}

void System
	::GlDispatchComputeGroupSizeARB(GLuint numGroupsX, GLuint numGroupsY, GLuint numGroupsZ, GLuint groupSizeX, GLuint groupSizeY, GLuint groupSizeZ) noexcept
{
	SYSTEM_BODY_6(gglDispatchComputeGroupSizeARB, numGroupsX, numGroupsY, numGroupsZ, groupSizeX, groupSizeY, groupSizeZ);
}

void System
	::InitGlArbComputeCariableGroupSize() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_compute_variable_group_size"))
	{
		g_ExistsGlArbComputeCariableGroupSize = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDispatchComputeGroupSizeARB);
	}
	else
	{
		g_ExistsGlArbComputeCariableGroupSize = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 154) GL_ARB_indirect_parameters

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbIndirectParameters{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbIndirectParameters() noexcept
{
	return g_ExistsGlArbIndirectParameters;
}

namespace System
{
	using PgglMultiDrawArraysIndirectCountARB = void (OPENGL_STDCALL*) (GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
	using PgglMultiDrawElementsIndirectCountARB = void (OPENGL_STDCALL*) (GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
}

namespace System
{
	PgglMultiDrawArraysIndirectCountARB gglMultiDrawArraysIndirectCountARB{ nullptr };
	PgglMultiDrawElementsIndirectCountARB gglMultiDrawElementsIndirectCountARB{ nullptr };
}

void System
	::GlMultiDrawArraysIndirectCountARB(GLenum mode, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) noexcept
{
	SYSTEM_BODY_5(gglMultiDrawArraysIndirectCountARB, mode, indirect, drawcount, maxdrawcount, stride);
}

void System
	::GlMultiDrawElementsIndirectCountARB(GLenum mode, GLenum type, const GLvoid* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) noexcept
{
	SYSTEM_BODY_6(gglMultiDrawElementsIndirectCountARB, mode, type, indirect, drawcount, maxdrawcount, stride);
}

void System
	::InitGlArbIndirectParameters() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_indirect_parameters"))
	{
		g_ExistsGlArbIndirectParameters = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglMultiDrawArraysIndirectCountARB);
		SYSTEM_GET_FUNCTION(gglMultiDrawElementsIndirectCountARB);
	}
	else
	{
		g_ExistsGlArbIndirectParameters = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 155) GL_ARB_seamless_cubemap_per_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSeamlessCubemapPerTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSeamlessCubemapPerTexture() noexcept
{
	return g_ExistsGlArbSeamlessCubemapPerTexture;
}

void System
	::InitGlArbSeamlessCubemapPerTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_seamless_cubemap_per_texture"))
	{
		g_ExistsGlArbSeamlessCubemapPerTexture = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbSeamlessCubemapPerTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 156) GL_ARB_shader_draw_parameters

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderDrawParameters{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderDrawParameters() noexcept
{
	return g_ExistsGlArbShaderDrawParameters;
}

void System
	::InitGlArbShaderDrawParameters() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_draw_parameters"))
	{
		g_ExistsGlArbShaderDrawParameters = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShaderDrawParameters = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 157) GL_ARB_shader_group_vote

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderGroupVote{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderGroupVote() noexcept
{
	return g_ExistsGlArbShaderGroupVote;
}

void System
	::InitGlArbShaderGroupVote() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_group_vote"))
	{
		g_ExistsGlArbShaderGroupVote = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbShaderGroupVote = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 158) GL_ARB_sparse_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSparseTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSparseTexture() noexcept
{
	return g_ExistsGlArbSparseTexture;
}

namespace System
{
	using PgglTexPageCommitmentARB = void (OPENGL_STDCALL*) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
	using PgglTexturePageCommitmentEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
}

namespace System
{
	PgglTexPageCommitmentARB gglTexPageCommitmentARB{ nullptr };
	PgglTexturePageCommitmentEXT gglTexturePageCommitmentEXT{ nullptr };
}


void System
	::GlTexPageCommitmentARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) noexcept
{
	SYSTEM_BODY_9(gglTexPageCommitmentARB, target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

void System
	::GlTexturePageCommitmentEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) noexcept
{
	SYSTEM_BODY_10(gglTexturePageCommitmentEXT, texture, target, level, xoffset, yoffset, zoffset, width, height, depth, commit);
}

void System
	::InitGlArbSparseTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_sparse_texture"))
	{
		g_ExistsGlArbSparseTexture = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTexPageCommitmentARB);
		SYSTEM_GET_FUNCTION(gglTexturePageCommitmentEXT);
	}
	else
	{
		g_ExistsGlArbSparseTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 160) GL_ARB_clip_control

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbClipControl{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbClipControl() noexcept
{
	return g_ExistsGlArbClipControl;
}

namespace System
{
	using PgglClipControl = void (OPENGL_STDCALL*) (GLenum origin, GLenum depth);
}

namespace System
{
	PgglClipControl gglClipControl{ nullptr };
}

void System
	::GlClipControl(GLenum origin, GLenum depth) noexcept
{
	SYSTEM_BODY_2(gglClipControl, origin, depth);
}

void System
	::InitGlArbClipControl() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_clip_control"))
	{
		g_ExistsGlArbClipControl = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglClipControl);
	}
	else
	{
		g_ExistsGlArbClipControl = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 161) GL_ARB_conditional_render_inverted

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbConditionalRenderInverted{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbConditionalRenderInverted() noexcept
{
	return g_ExistsGlArbConditionalRenderInverted;
}

void System
	::InitGlArbConditionalRenderInverted() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_conditional_render_inverted"))
	{
		g_ExistsGlArbConditionalRenderInverted = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbConditionalRenderInverted = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 162) GL_ARB_cull_distance

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbCullDistance{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbCullDistance() noexcept
{
	return g_ExistsGlArbCullDistance;
}

void System
	::InitGlArbCullDistance() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_cull_distance"))
	{
		g_ExistsGlArbCullDistance = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbCullDistance = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 163) GL_ARB_derivative_control

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDerivativeControl{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDerivativeControl() noexcept
{
	return g_ExistsGlArbDerivativeControl;
}

void System
	::InitGlArbDerivativeControl() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_derivative_control"))
	{
		g_ExistsGlArbDerivativeControl = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbDerivativeControl = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 164) GL_ARB_direct_state_access

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbDirectStateAccess{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbDirectStateAccess() noexcept
{
	return g_ExistsGlArbDirectStateAccess;
}

namespace System
{
	using PgglBindTextureUnit = void (OPENGL_STDCALL*) (GLuint unit, GLuint texture);
	using PgglBlitNamedFramebuffer = void (OPENGL_STDCALL*) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1,
															 GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	using PgglCheckNamedFramebufferStatus = GLenum(OPENGL_STDCALL*) (GLuint framebuffer, GLenum target);
	using PgglClearNamedBufferData = void (OPENGL_STDCALL*)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
	using PgglClearNamedBufferSubData = void (OPENGL_STDCALL*) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
	using PgglClearNamedFramebufferfi = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum buffer, GLfloat depth, GLint stencil);
	using PgglClearNamedFramebufferfv = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
	using PgglClearNamedFramebufferiv = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
	using PgglClearNamedFramebufferuiv = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
	using PgglCompressedTextureSubImage1D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedTextureSubImage2D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
																	GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedTextureSubImage3D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
																	GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	using PgglCopyNamedBufferSubData = void (OPENGL_STDCALL*) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	using PgglCopyTextureSubImage1D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	using PgglCopyTextureSubImage2D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglCopyTextureSubImage3D = void (OPENGL_STDCALL*)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglCreateBuffers = void (OPENGL_STDCALL*) (GLsizei n, GLuint* buffers);
	using PgglCreateFramebuffers = void (OPENGL_STDCALL*) (GLsizei n, GLuint* framebuffers);
	using PgglCreateProgramPipelines = void (OPENGL_STDCALL*) (GLsizei n, GLuint* pipelines);
	using PgglCreateQueries = void (OPENGL_STDCALL*) (GLenum target, GLsizei n, GLuint* ids);
	using PgglCreateRenderbuffers = void (OPENGL_STDCALL*)(GLsizei n, GLuint* renderbuffers);
	using PgglCreateSamplers = void (OPENGL_STDCALL*) (GLsizei n, GLuint* samplers);
	using PgglCreateTextures = void (OPENGL_STDCALL*) (GLenum target, GLsizei n, GLuint* textures);
	using PgglCreateTransformFeedbacks = void (OPENGL_STDCALL*)(GLsizei n, GLuint* ids);
	using PgglCreateVertexArrays = void (OPENGL_STDCALL*)(GLsizei n, GLuint* arrays);
	using PgglDisableVertexArrayAttrib = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index);
	using PgglEnableVertexArrayAttrib = void (OPENGL_STDCALL*)(GLuint vaobj, GLuint index);
	using PgglFlushMappedNamedBufferRange = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr length);
	using PgglGenerateTextureMipmap = void (OPENGL_STDCALL*) (GLuint texture);
	using PgglGetCompressedTextureImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLsizei bufSize, void* pixels);
	using PgglGetNamedBufferParameteri64v = void (OPENGL_STDCALL*) (GLuint buffer, GLenum parameterName, GLint64* params);
	using PgglGetNamedBufferParameteriv = void (OPENGL_STDCALL*) (GLuint buffer, GLenum parameterName, GLint* params);
	using PgglGetNamedBufferPointerv = void (OPENGL_STDCALL*)(GLuint buffer, GLenum parameterName, void** params);
	using PgglGetNamedBufferSubData = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
	using PgglGetNamedFramebufferAttachmentParameteriv = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum attachment, GLenum parameterName, GLint* params);
	using PgglGetNamedFramebufferParameteriv = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum parameterName, GLint* param);
	using PgglGetNamedRenderbufferParameteriv = void (OPENGL_STDCALL*)(GLuint renderbuffer, GLenum parameterName, GLint* params);
	using PgglGetQueryBufferObjecti64v = void (OPENGL_STDCALL*)(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset);
	using PgglGetQueryBufferObjectiv = void (OPENGL_STDCALL*) (GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset);
	using PgglGetQueryBufferObjectui64v = void (OPENGL_STDCALL*)(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset);
	using PgglGetQueryBufferObjectuiv = void (OPENGL_STDCALL*) (GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset);
	using PgglGetTextureImage = void (OPENGL_STDCALL*)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
	using PgglGetTextureLevelParameterfv = void (OPENGL_STDCALL*)(GLuint texture, GLint level, GLenum parameterName, GLfloat* params);
	using PgglGetTextureLevelParameteriv = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLenum parameterName, GLint* params);
	using PgglGetTextureParameterIiv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, GLint* params);
	using PgglGetTextureParameterIuiv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, GLuint* params);
	using PgglGetTextureParameterfv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, GLfloat* params);
	using PgglGetTextureParameteriv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, GLint* params);
	using PgglGetTransformFeedbacki64_v = void (OPENGL_STDCALL*) (GLuint xfb, GLenum parameterName, GLuint index, GLint64* param);
	using PgglGetTransformFeedbacki_v = void (OPENGL_STDCALL*) (GLuint xfb, GLenum parameterName, GLuint index, GLint* param);
	using PgglGetTransformFeedbackiv = void (OPENGL_STDCALL*)(GLuint xfb, GLenum parameterName, GLint* param);
	using PgglGetVertexArrayIndexed64iv = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index, GLenum parameterName, GLint64* param);
	using PgglGetVertexArrayIndexediv = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index, GLenum parameterName, GLint* param);
	using PgglGetVertexArrayiv = void (OPENGL_STDCALL*) (GLuint vaobj, GLenum parameterName, GLint* param);
	using PgglInvalidateNamedFramebufferData = void (OPENGL_STDCALL*) (GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
	using PgglInvalidateNamedFramebufferSubData = void (OPENGL_STDCALL*) (GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x,
																		  GLint y, GLsizei width, GLsizei height);
	using PgglMapNamedBuffer = void (OPENGL_STDCALL*) (GLuint buffer, GLenum access);
	using PgglMapNamedBufferRange = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
	using PgglNamedBufferData = void (OPENGL_STDCALL*) (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
	using PgglNamedBufferStorage = void (OPENGL_STDCALL*) (GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
	using PgglNamedBufferSubData = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
	using PgglNamedFramebufferDrawBuffer = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum mode);
	using PgglNamedFramebufferDrawBuffers = void (OPENGL_STDCALL*) (GLuint framebuffer, GLsizei n, const GLenum* bufs);
	using PgglNamedFramebufferParameteri = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum parameterName, GLint param);
	using PgglNamedFramebufferReadBuffer = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum mode);
	using PgglNamedFramebufferRenderbuffer = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	using PgglNamedFramebufferTexture = void (OPENGL_STDCALL*)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
	using PgglNamedFramebufferTextureLayer = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
	using PgglNamedRenderbufferStorage = void (OPENGL_STDCALL*) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglNamedRenderbufferStorageMultisample = void (OPENGL_STDCALL*)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglTextureBuffer = void (OPENGL_STDCALL*)(GLuint texture, GLenum internalformat, GLuint buffer);
	using PgglTextureBufferRange = void (OPENGL_STDCALL*) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
	using PgglTextureParameterIiv = void (OPENGL_STDCALL*)(GLuint texture, GLenum parameterName, const GLint* params);
	using PgglTextureParameterIuiv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, const GLuint* params);
	using PgglTextureParameterf = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, GLfloat param);
	using PgglTextureParameterfv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, const GLfloat* param);
	using PgglTextureParameteri = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, GLint param);
	using PgglTextureParameteriv = void (OPENGL_STDCALL*) (GLuint texture, GLenum parameterName, const GLint* param);
	using PgglTextureStorage1D = void (OPENGL_STDCALL*) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
	using PgglTextureStorage2D = void (OPENGL_STDCALL*) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglTextureStorage2DMultisample = void (OPENGL_STDCALL*) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	using PgglTextureStorage3D = void (OPENGL_STDCALL*) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	using PgglTextureStorage3DMultisample = void (OPENGL_STDCALL*)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width,
																   GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	using PgglTextureSubImage1D = void (OPENGL_STDCALL*)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	using PgglTextureSubImage2D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
														  GLsizei height, GLenum format, GLenum type, const void* pixels);
	using PgglTextureSubImage3D = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
														  GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	using PgglTransformFeedbackBufferBase = void (OPENGL_STDCALL*) (GLuint xfb, GLuint index, GLuint buffer);
	using PgglTransformFeedbackBufferRange = void (OPENGL_STDCALL*) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	using PgglUnmapNamedBuffer = GLboolean(OPENGL_STDCALL*) (GLuint buffer);
	using PgglVertexArrayAttribBinding = void (OPENGL_STDCALL*)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
	using PgglVertexArrayAttribFormat = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	using PgglVertexArrayAttribIFormat = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	using PgglVertexArrayAttribLFormat = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	using PgglVertexArrayBindingDivisor = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
	using PgglVertexArrayElementBuffer = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer);
	using PgglVertexArrayVertexBuffer = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
	using PgglVertexArrayVertexBuffers = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
}

namespace System
{
	PgglBindTextureUnit gglBindTextureUnit{ nullptr };
	PgglBlitNamedFramebuffer gglBlitNamedFramebuffer{ nullptr };
	PgglCheckNamedFramebufferStatus gglCheckNamedFramebufferStatus{ nullptr };
	PgglClearNamedBufferData gglClearNamedBufferData{ nullptr };
	PgglClearNamedBufferSubData gglClearNamedBufferSubData{ nullptr };
	PgglClearNamedFramebufferfi gglClearNamedFramebufferfi{ nullptr };
	PgglClearNamedFramebufferfv gglClearNamedFramebufferfv{ nullptr };
	PgglClearNamedFramebufferiv gglClearNamedFramebufferiv{ nullptr };
	PgglClearNamedFramebufferuiv gglClearNamedFramebufferuiv{ nullptr };
	PgglCompressedTextureSubImage1D gglCompressedTextureSubImage1D{ nullptr };
	PgglCompressedTextureSubImage2D gglCompressedTextureSubImage2D{ nullptr };
	PgglCompressedTextureSubImage3D gglCompressedTextureSubImage3D{ nullptr };
	PgglCopyNamedBufferSubData gglCopyNamedBufferSubData{ nullptr };
	PgglCopyTextureSubImage1D gglCopyTextureSubImage1D{ nullptr };
	PgglCopyTextureSubImage2D gglCopyTextureSubImage2D{ nullptr };
	PgglCopyTextureSubImage3D gglCopyTextureSubImage3D{ nullptr };
	PgglCreateBuffers gglCreateBuffers{ nullptr };
	PgglCreateFramebuffers gglCreateFramebuffers{ nullptr };
	PgglCreateProgramPipelines gglCreateProgramPipelines{ nullptr };
	PgglCreateQueries gglCreateQueries{ nullptr };
	PgglCreateRenderbuffers gglCreateRenderbuffers{ nullptr };
	PgglCreateSamplers gglCreateSamplers{ nullptr };
	PgglCreateTextures gglCreateTextures{ nullptr };
	PgglCreateTransformFeedbacks gglCreateTransformFeedbacks{ nullptr };
	PgglCreateVertexArrays gglCreateVertexArrays{ nullptr };
	PgglDisableVertexArrayAttrib gglDisableVertexArrayAttrib{ nullptr };
	PgglEnableVertexArrayAttrib gglEnableVertexArrayAttrib{ nullptr };
	PgglFlushMappedNamedBufferRange gglFlushMappedNamedBufferRange{ nullptr };
	PgglGenerateTextureMipmap gglGenerateTextureMipmap{ nullptr };
	PgglGetCompressedTextureImage gglGetCompressedTextureImage{ nullptr };
	PgglGetNamedBufferParameteri64v gglGetNamedBufferParameteri64v{ nullptr };
	PgglGetNamedBufferParameteriv gglGetNamedBufferParameteriv{ nullptr };
	PgglGetNamedBufferPointerv gglGetNamedBufferPointerv{ nullptr };
	PgglGetNamedBufferSubData gglGetNamedBufferSubData{ nullptr };
	PgglGetNamedFramebufferAttachmentParameteriv gglGetNamedFramebufferAttachmentParameteriv{ nullptr };
	PgglGetNamedFramebufferParameteriv gglGetNamedFramebufferParameteriv{ nullptr };
	PgglGetNamedRenderbufferParameteriv gglGetNamedRenderbufferParameteriv{ nullptr };
	PgglGetQueryBufferObjecti64v gglGetQueryBufferObjecti64v{ nullptr };
	PgglGetQueryBufferObjectiv gglGetQueryBufferObjectiv{ nullptr };
	PgglGetQueryBufferObjectui64v gglGetQueryBufferObjectui64v{ nullptr };
	PgglGetQueryBufferObjectuiv gglGetQueryBufferObjectuiv{ nullptr };
	PgglGetTextureImage gglGetTextureImage{ nullptr };
	PgglGetTextureLevelParameterfv gglGetTextureLevelParameterfv{ nullptr };
	PgglGetTextureLevelParameteriv gglGetTextureLevelParameteriv{ nullptr };
	PgglGetTextureParameterIiv gglGetTextureParameterIiv{ nullptr };
	PgglGetTextureParameterIuiv gglGetTextureParameterIuiv{ nullptr };
	PgglGetTextureParameterfv gglGetTextureParameterfv{ nullptr };
	PgglGetTextureParameteriv gglGetTextureParameteriv{ nullptr };
	PgglGetTransformFeedbacki64_v gglGetTransformFeedbacki64_v{ nullptr };
	PgglGetTransformFeedbacki_v gglGetTransformFeedbacki_v{ nullptr };
	PgglGetTransformFeedbackiv gglGetTransformFeedbackiv{ nullptr };
	PgglGetVertexArrayIndexed64iv gglGetVertexArrayIndexed64iv{ nullptr };
	PgglGetVertexArrayIndexediv gglGetVertexArrayIndexediv{ nullptr };
	PgglGetVertexArrayiv gglGetVertexArrayiv{ nullptr };
	PgglInvalidateNamedFramebufferData gglInvalidateNamedFramebufferData{ nullptr };
	PgglInvalidateNamedFramebufferSubData gglInvalidateNamedFramebufferSubData{ nullptr };
	PgglMapNamedBuffer gglMapNamedBuffer{ nullptr };
	PgglMapNamedBufferRange gglMapNamedBufferRange{ nullptr };
	PgglNamedBufferData gglNamedBufferData{ nullptr };
	PgglNamedBufferStorage gglNamedBufferStorage{ nullptr };
	PgglNamedBufferSubData gglNamedBufferSubData{ nullptr };
	PgglNamedFramebufferDrawBuffer gglNamedFramebufferDrawBuffer{ nullptr };
	PgglNamedFramebufferDrawBuffers gglNamedFramebufferDrawBuffers{ nullptr };
	PgglNamedFramebufferParameteri gglNamedFramebufferParameteri{ nullptr };
	PgglNamedFramebufferReadBuffer gglNamedFramebufferReadBuffer{ nullptr };
	PgglNamedFramebufferRenderbuffer gglNamedFramebufferRenderbuffer{ nullptr };
	PgglNamedFramebufferTexture gglNamedFramebufferTexture{ nullptr };
	PgglNamedFramebufferTextureLayer gglNamedFramebufferTextureLayer{ nullptr };
	PgglNamedRenderbufferStorage gglNamedRenderbufferStorage{ nullptr };
	PgglNamedRenderbufferStorageMultisample gglNamedRenderbufferStorageMultisample{ nullptr };
	PgglTextureBuffer gglTextureBuffer{ nullptr };
	PgglTextureBufferRange gglTextureBufferRange{ nullptr };
	PgglTextureParameterIiv gglTextureParameterIiv{ nullptr };
	PgglTextureParameterIuiv gglTextureParameterIuiv{ nullptr };
	PgglTextureParameterf gglTextureParameterf{ nullptr };
	PgglTextureParameterfv gglTextureParameterfv{ nullptr };
	PgglTextureParameteri gglTextureParameteri{ nullptr };
	PgglTextureParameteriv gglTextureParameteriv{ nullptr };
	PgglTextureStorage1D gglTextureStorage1D{ nullptr };
	PgglTextureStorage2D gglTextureStorage2D{ nullptr };
	PgglTextureStorage2DMultisample gglTextureStorage2DMultisample{ nullptr };
	PgglTextureStorage3D gglTextureStorage3D{ nullptr };
	PgglTextureStorage3DMultisample gglTextureStorage3DMultisample{ nullptr };
	PgglTextureSubImage1D gglTextureSubImage1D{ nullptr };
	PgglTextureSubImage2D gglTextureSubImage2D{ nullptr };
	PgglTextureSubImage3D gglTextureSubImage3D{ nullptr };
	PgglTransformFeedbackBufferBase gglTransformFeedbackBufferBase{ nullptr };
	PgglTransformFeedbackBufferRange gglTransformFeedbackBufferRange{ nullptr };
	PgglUnmapNamedBuffer gglUnmapNamedBuffer{ nullptr };
	PgglVertexArrayAttribBinding gglVertexArrayAttribBinding{ nullptr };
	PgglVertexArrayAttribFormat gglVertexArrayAttribFormat{ nullptr };
	PgglVertexArrayAttribIFormat gglVertexArrayAttribIFormat{ nullptr };
	PgglVertexArrayAttribLFormat gglVertexArrayAttribLFormat{ nullptr };
	PgglVertexArrayBindingDivisor gglVertexArrayBindingDivisor{ nullptr };
	PgglVertexArrayElementBuffer gglVertexArrayElementBuffer{ nullptr };
	PgglVertexArrayVertexBuffer gglVertexArrayVertexBuffer{ nullptr };
	PgglVertexArrayVertexBuffers gglVertexArrayVertexBuffers{ nullptr };
}

void System
	::GlBindTextureUnit(GLuint unit, GLuint texture) noexcept
{
	SYSTEM_BODY_2(gglBindTextureUnit, unit, texture);
}

void System
	::GlBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1,
							 GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
	SYSTEM_BODY_12(gglBlitNamedFramebuffer, readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLenum System
	::GlCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) noexcept
{
	SYSTEM_BODY_2_RESULT(gglCheckNamedFramebufferStatus, framebuffer, target, GLenum, 0);
}

void System
	::GlClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data) noexcept
{
	SYSTEM_BODY_5(gglClearNamedBufferData, buffer, internalformat, format, type, data);
}

void System
	::GlClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept
{
	SYSTEM_BODY_7(gglClearNamedBufferSubData, buffer, internalformat, offset, size, format, type, data);
}

void System
	::GlClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLfloat depth, GLint stencil) noexcept
{
	SYSTEM_BODY_4(gglClearNamedFramebufferfi, framebuffer, buffer, depth, stencil);
}

void System
	::GlClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglClearNamedFramebufferfv, framebuffer, buffer, drawbuffer, value);
}

void System
	::GlClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglClearNamedFramebufferiv, framebuffer, buffer, drawbuffer, value);
}

void System
	::GlClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglClearNamedFramebufferuiv, framebuffer, buffer, drawbuffer, value);
}

void System
	::GlCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_7(gglCompressedTextureSubImage1D, texture, level, xoffset, width, format, imageSize, data);
}

void System
	::GlCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedTextureSubImage2D, texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void System
	::GlCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
									GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_11(gglCompressedTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void System
	::GlCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglCopyNamedBufferSubData, readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void System
	::GlCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_BODY_6(gglCopyTextureSubImage1D, texture, level, xoffset, x, y, width);
}

void System
	::GlCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_8(gglCopyTextureSubImage2D, texture, level, xoffset, yoffset, x, y, width, height);
}

void System
	::GlCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_9(gglCopyTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void System
	::GlCreateBuffers(GLsizei n, GLuint* buffers) noexcept
{
	SYSTEM_BODY_2(gglCreateBuffers, n, buffers);
}

void System
	::GlCreateFramebuffers(GLsizei n, GLuint* framebuffers) noexcept
{
	SYSTEM_BODY_2(gglCreateFramebuffers, n, framebuffers);
}

void System
	::GlCreateProgramPipelines(GLsizei n, GLuint* pipelines) noexcept
{
	SYSTEM_BODY_2(gglCreateProgramPipelines, n, pipelines);
}

void System
	::GlCreateQueries(GLenum target, GLsizei n, GLuint* ids) noexcept
{
	SYSTEM_BODY_3(gglCreateQueries, target, n, ids);
}

void System
	::GlCreateRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept
{
	SYSTEM_BODY_2(gglCreateRenderbuffers, n, renderbuffers);
}

void System
	::GlCreateSamplers(GLsizei n, GLuint* samplers) noexcept
{
	SYSTEM_BODY_2(gglCreateSamplers, n, samplers);
}

void System
	::GlCreateTextures(GLenum target, GLsizei n, GLuint* textures) noexcept
{
	SYSTEM_BODY_3(gglCreateTextures, target, n, textures);
}

void System
	::GlCreateTransformFeedbacks(GLsizei n, GLuint* ids) noexcept
{
	SYSTEM_BODY_2(gglCreateTransformFeedbacks, n, ids);
}

void System
	::GlCreateVertexArrays(GLsizei n, GLuint* arrays) noexcept
{
	SYSTEM_BODY_2(gglCreateVertexArrays, n, arrays);
}

void System
	::GlDisableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglDisableVertexArrayAttrib, vaobj, index);
}

void System
	::GlEnableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEnableVertexArrayAttrib, vaobj, index);
}

void System
	::GlFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept
{
	SYSTEM_BODY_3(gglFlushMappedNamedBufferRange, buffer, offset, length);
}

void System
	::GlGenerateTextureMipmap(GLuint texture) noexcept
{
	SYSTEM_BODY_1(gglGenerateTextureMipmap, texture);
}

void System
	::GlGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels) noexcept
{
	SYSTEM_BODY_4(gglGetCompressedTextureImage, texture, level, bufSize, pixels);
}

void System
	::GlGetNamedBufferParameteri64v(GLuint buffer, GLenum parameterName, GLint64* params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedBufferParameteri64v, buffer, parameterName, params);
}

void System
	::GlGetNamedBufferParameteriv(GLuint buffer, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedBufferParameteriv, buffer, parameterName, params);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetNamedBufferPointerv(GLuint buffer, GLenum parameterName, void** params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedBufferPointerv, buffer, parameterName, params);
}
#include STSTEM_WARNING_POP

void System
	::GlGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept
{
	SYSTEM_BODY_4(gglGetNamedBufferSubData, buffer, offset, size, data);
}

void System
	::GlGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedFramebufferAttachmentParameteriv, framebuffer, attachment, parameterName, params);
}

void System
	::GlGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetNamedFramebufferParameteriv, framebuffer, parameterName, param);
}

void System
	::GlGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedRenderbufferParameteriv, renderbuffer, parameterName, params);
}

void System
	::GlGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept
{
	SYSTEM_BODY_4(gglGetQueryBufferObjecti64v, id, buffer, parameterName, offset);
}

void System
	::GlGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept
{
	SYSTEM_BODY_4(gglGetQueryBufferObjectiv, id, buffer, parameterName, offset);
}

void System
	::GlGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept
{
	SYSTEM_BODY_4(gglGetQueryBufferObjectui64v, id, buffer, parameterName, offset);
}

void System
	::GlGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum parameterName, GLintptr offset) noexcept
{
	SYSTEM_BODY_4(gglGetQueryBufferObjectuiv, id, buffer, parameterName, offset);
}

void System
	::GlGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
	SYSTEM_BODY_6(gglGetTextureImage, texture, level, format, type, bufSize, pixels);
}

void System
	::GlGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetTextureLevelParameterfv, texture, level, parameterName, params);
}

void System
	::GlGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetTextureLevelParameteriv, texture, level, parameterName, params);
}

void System
	::GlGetTextureParameterIiv(GLuint texture, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTextureParameterIiv, texture, parameterName, params);
}

void System
	::GlGetTextureParameterIuiv(GLuint texture, GLenum parameterName, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTextureParameterIuiv, texture, parameterName, params);
}

void System
	::GlGetTextureParameterfv(GLuint texture, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglGetTextureParameterfv, texture, parameterName, params);
}

void System
	::GlGetTextureParameteriv(GLuint texture, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTextureParameteriv, texture, parameterName, params);
}

void System
	::GlGetTransformFeedbacki64_v(GLuint xfb, GLenum parameterName, GLuint index, GLint64* param) noexcept
{
	SYSTEM_BODY_4(gglGetTransformFeedbacki64_v, xfb, parameterName, index, param);
}

void System
	::GlGetTransformFeedbacki_v(GLuint xfb, GLenum parameterName, GLuint index, GLint* param) noexcept
{
	SYSTEM_BODY_4(gglGetTransformFeedbacki_v, xfb, parameterName, index, param);
}

void System
	::GlGetTransformFeedbackiv(GLuint xfb, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetTransformFeedbackiv, xfb, parameterName, param);
}

void System
	::GlGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum parameterName, GLint64* param) noexcept
{
	SYSTEM_BODY_4(gglGetVertexArrayIndexed64iv, vaobj, index, parameterName, param);
}

void System
	::GlGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_4(gglGetVertexArrayIndexediv, vaobj, index, parameterName, param);
}

void System
	::GlGetVertexArrayiv(GLuint vaobj, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetVertexArrayiv, vaobj, parameterName, param);
}

void System
	::GlInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments) noexcept
{
	SYSTEM_BODY_3(gglInvalidateNamedFramebufferData, framebuffer, numAttachments, attachments);
}

void System
	::GlInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_7(gglInvalidateNamedFramebufferSubData, framebuffer, numAttachments, attachments, x, y, width, height);
}

void System
	::GlMapNamedBuffer(GLuint buffer, GLenum access) noexcept
{
	SYSTEM_BODY_2(gglMapNamedBuffer, buffer, access);
}

void System
	::GlMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept
{
	SYSTEM_BODY_4(gglMapNamedBufferRange, buffer, offset, length, access);
}

void System
	::GlNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept
{
	SYSTEM_BODY_4(gglNamedBufferData, buffer, size, data, usage);
}

void System
	::GlNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) noexcept
{
	SYSTEM_BODY_4(gglNamedBufferStorage, buffer, size, data, flags);
}

void System
	::GlNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept
{
	SYSTEM_BODY_4(gglNamedBufferSubData, buffer, offset, size, data);
}

void System
	::GlNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglNamedFramebufferDrawBuffer, framebuffer, mode);
}

void System
	::GlNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs) noexcept
{
	SYSTEM_BODY_3(gglNamedFramebufferDrawBuffers, framebuffer, n, bufs);
}

void System
	::GlNamedFramebufferParameteri(GLuint framebuffer, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_3(gglNamedFramebufferParameteri, framebuffer, parameterName, param);
}

void System
	::GlNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglNamedFramebufferReadBuffer, framebuffer, mode);
}

void System
	::GlNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_4(gglNamedFramebufferRenderbuffer, framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void System
	::GlNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_4(gglNamedFramebufferTexture, framebuffer, attachment, texture, level);
}

void System
	::GlNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
	SYSTEM_BODY_5(gglNamedFramebufferTextureLayer, framebuffer, attachment, texture, level, layer);
}

void System
	::GlNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_4(gglNamedRenderbufferStorage, renderbuffer, internalformat, width, height);
}

void System
	::GlNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglNamedRenderbufferStorageMultisample, renderbuffer, samples, internalformat, width, height);
}

void System
	::GlTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglTextureBuffer, texture, internalformat, buffer);
}

void System
	::GlTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglTextureBufferRange, texture, internalformat, buffer, offset, size);
}

void System
	::GlTextureParameterIiv(GLuint texture, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglTextureParameterIiv, texture, parameterName, params);
}

void System
	::GlTextureParameterIuiv(GLuint texture, GLenum parameterName, const GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglTextureParameterIuiv, texture, parameterName, params);
}

void System
	::GlTextureParameterf(GLuint texture, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_3(gglTextureParameterf, texture, parameterName, param);
}

void System
	::GlTextureParameterfv(GLuint texture, GLenum parameterName, const GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglTextureParameterfv, texture, parameterName, param);
}

void System
	::GlTextureParameteri(GLuint texture, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_3(gglTextureParameteri, texture, parameterName, param);
}

void System
	::GlTextureParameteriv(GLuint texture, GLenum parameterName, const GLint* param) noexcept
{
	SYSTEM_BODY_3(gglTextureParameteriv, texture, parameterName, param);
}

void System
	::GlTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) noexcept
{
	SYSTEM_BODY_4(gglTextureStorage1D, texture, levels, internalformat, width);
}

void System
	::GlTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglTextureStorage2D, texture, levels, internalformat, width, height);
}

void System
	::GlTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_6(gglTextureStorage2DMultisample, texture, samples, internalformat, width, height, fixedsamplelocations);
}

void System
	::GlTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
	SYSTEM_BODY_6(gglTextureStorage3D, texture, levels, internalformat, width, height, depth);
}

void System
	::GlTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_7(gglTextureStorage3DMultisample, texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void System
	::GlTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_7(gglTextureSubImage1D, texture, level, xoffset, width, format, type, pixels);
}

void System
	::GlTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_9(gglTextureSubImage2D, texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void System
	::GlTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
						  GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_11(gglTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void System
	::GlTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglTransformFeedbackBufferBase, xfb, index, buffer);
}

void System
	::GlTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglTransformFeedbackBufferRange, xfb, index, buffer, offset, size);
}

GLboolean System
	::GlUnmapNamedBuffer(GLuint buffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglUnmapNamedBuffer, buffer, GLboolean, GL_FALSE);
}

void System
	::GlVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) noexcept
{
	SYSTEM_BODY_3(gglVertexArrayAttribBinding, vaobj, attribindex, bindingindex);
}

void System
	::GlVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept
{
	SYSTEM_BODY_6(gglVertexArrayAttribFormat, vaobj, attribindex, size, type, normalized, relativeoffset);
}

void System
	::GlVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept
{
	SYSTEM_BODY_5(gglVertexArrayAttribIFormat, vaobj, attribindex, size, type, relativeoffset);
}

void System
	::GlVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept
{
	SYSTEM_BODY_5(gglVertexArrayAttribLFormat, vaobj, attribindex, size, type, relativeoffset);
}

void System
	::GlVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) noexcept
{
	SYSTEM_BODY_3(gglVertexArrayBindingDivisor, vaobj, bindingindex, divisor);
}

void System
	::GlVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) noexcept
{
	SYSTEM_BODY_2(gglVertexArrayElementBuffer, vaobj, buffer);
}

void System
	::GlVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept
{
	SYSTEM_BODY_5(gglVertexArrayVertexBuffer, vaobj, bindingindex, buffer, offset, stride);
}

void System
	::GlVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept
{
	SYSTEM_BODY_6(gglVertexArrayVertexBuffers, vaobj, first, count, buffers, offsets, strides);
}

void System
	::InitGlArbDirectStateAccess() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_direct_state_access"))
	{
		g_ExistsGlArbDirectStateAccess = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindTextureUnit);
		SYSTEM_GET_FUNCTION(gglBlitNamedFramebuffer);
		SYSTEM_GET_FUNCTION(gglCheckNamedFramebufferStatus);
		SYSTEM_GET_FUNCTION(gglClearNamedBufferData);
		SYSTEM_GET_FUNCTION(gglClearNamedBufferSubData);
		SYSTEM_GET_FUNCTION(gglClearNamedFramebufferfi);
		SYSTEM_GET_FUNCTION(gglClearNamedFramebufferfv);
		SYSTEM_GET_FUNCTION(gglClearNamedFramebufferiv);
		SYSTEM_GET_FUNCTION(gglClearNamedFramebufferuiv);
		SYSTEM_GET_FUNCTION(gglCompressedTextureSubImage1D);
		SYSTEM_GET_FUNCTION(gglCompressedTextureSubImage2D);
		SYSTEM_GET_FUNCTION(gglCompressedTextureSubImage3D);
		SYSTEM_GET_FUNCTION(gglCopyNamedBufferSubData);
		SYSTEM_GET_FUNCTION(gglCopyTextureSubImage1D);
		SYSTEM_GET_FUNCTION(gglCopyTextureSubImage2D);
		SYSTEM_GET_FUNCTION(gglCopyTextureSubImage3D);
		SYSTEM_GET_FUNCTION(gglCreateBuffers);
		SYSTEM_GET_FUNCTION(gglCreateFramebuffers);
		SYSTEM_GET_FUNCTION(gglCreateProgramPipelines);
		SYSTEM_GET_FUNCTION(gglCreateQueries);
		SYSTEM_GET_FUNCTION(gglCreateRenderbuffers);
		SYSTEM_GET_FUNCTION(gglCreateSamplers);
		SYSTEM_GET_FUNCTION(gglCreateTextures);
		SYSTEM_GET_FUNCTION(gglCreateTransformFeedbacks);
		SYSTEM_GET_FUNCTION(gglCreateVertexArrays);
		SYSTEM_GET_FUNCTION(gglDisableVertexArrayAttrib);
		SYSTEM_GET_FUNCTION(gglEnableVertexArrayAttrib);
		SYSTEM_GET_FUNCTION(gglFlushMappedNamedBufferRange);
		SYSTEM_GET_FUNCTION(gglGenerateTextureMipmap);
		SYSTEM_GET_FUNCTION(gglGetCompressedTextureImage);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferParameteri64v);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferParameteriv);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferPointerv);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferSubData);
		SYSTEM_GET_FUNCTION(gglGetNamedFramebufferAttachmentParameteriv);
		SYSTEM_GET_FUNCTION(gglGetNamedFramebufferParameteriv);
		SYSTEM_GET_FUNCTION(gglGetNamedRenderbufferParameteriv);
		SYSTEM_GET_FUNCTION(gglGetQueryBufferObjecti64v);
		SYSTEM_GET_FUNCTION(gglGetQueryBufferObjectiv);
		SYSTEM_GET_FUNCTION(gglGetQueryBufferObjectui64v);
		SYSTEM_GET_FUNCTION(gglGetQueryBufferObjectuiv);
		SYSTEM_GET_FUNCTION(gglGetTextureImage);
		SYSTEM_GET_FUNCTION(gglGetTextureLevelParameterfv);
		SYSTEM_GET_FUNCTION(gglGetTextureLevelParameteriv);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterIiv);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterIuiv);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterfv);
		SYSTEM_GET_FUNCTION(gglGetTextureParameteriv);
		SYSTEM_GET_FUNCTION(gglGetTransformFeedbacki64_v);
		SYSTEM_GET_FUNCTION(gglGetTransformFeedbacki_v);
		SYSTEM_GET_FUNCTION(gglGetTransformFeedbackiv);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayIndexed64iv);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayIndexediv);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayiv);
		SYSTEM_GET_FUNCTION(gglInvalidateNamedFramebufferData);
		SYSTEM_GET_FUNCTION(gglInvalidateNamedFramebufferSubData);
		SYSTEM_GET_FUNCTION(gglMapNamedBuffer);
		SYSTEM_GET_FUNCTION(gglMapNamedBufferRange);
		SYSTEM_GET_FUNCTION(gglNamedBufferData);
		SYSTEM_GET_FUNCTION(gglNamedBufferStorage);
		SYSTEM_GET_FUNCTION(gglNamedBufferSubData);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferDrawBuffer);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferDrawBuffers);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferParameteri);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferReadBuffer);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferRenderbuffer);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTexture);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTextureLayer);
		SYSTEM_GET_FUNCTION(gglNamedRenderbufferStorage);
		SYSTEM_GET_FUNCTION(gglNamedRenderbufferStorageMultisample);
		SYSTEM_GET_FUNCTION(gglTextureBuffer);
		SYSTEM_GET_FUNCTION(gglTextureBufferRange);
		SYSTEM_GET_FUNCTION(gglTextureParameterIiv);
		SYSTEM_GET_FUNCTION(gglTextureParameterIuiv);
		SYSTEM_GET_FUNCTION(gglTextureParameterf);
		SYSTEM_GET_FUNCTION(gglTextureParameterfv);
		SYSTEM_GET_FUNCTION(gglTextureParameteri);
		SYSTEM_GET_FUNCTION(gglTextureParameteriv);
		SYSTEM_GET_FUNCTION(gglTextureStorage1D);
		SYSTEM_GET_FUNCTION(gglTextureStorage2D);
		SYSTEM_GET_FUNCTION(gglTextureStorage2DMultisample);
		SYSTEM_GET_FUNCTION(gglTextureStorage3D);
		SYSTEM_GET_FUNCTION(gglTextureStorage3DMultisample);
		SYSTEM_GET_FUNCTION(gglTextureSubImage1D);
		SYSTEM_GET_FUNCTION(gglTextureSubImage2D);
		SYSTEM_GET_FUNCTION(gglTextureSubImage3D);
		SYSTEM_GET_FUNCTION(gglTransformFeedbackBufferBase);
		SYSTEM_GET_FUNCTION(gglTransformFeedbackBufferRange);
		SYSTEM_GET_FUNCTION(gglUnmapNamedBuffer);
		SYSTEM_GET_FUNCTION(gglVertexArrayAttribBinding);
		SYSTEM_GET_FUNCTION(gglVertexArrayAttribFormat);
		SYSTEM_GET_FUNCTION(gglVertexArrayAttribIFormat);
		SYSTEM_GET_FUNCTION(gglVertexArrayAttribLFormat);
		SYSTEM_GET_FUNCTION(gglVertexArrayBindingDivisor);
		SYSTEM_GET_FUNCTION(gglVertexArrayElementBuffer);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexBuffer);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexBuffers);
	}
	else
	{
		g_ExistsGlArbDirectStateAccess = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 165) GL_ARB_get_texture_sub_image

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbGetTextureSubImage{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbGetTextureSubImage() noexcept
{
	return g_ExistsGlArbGetTextureSubImage;
}

namespace System
{
	using PgglGetCompressedTextureSubImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
																	 GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels);
	using PgglGetTextureSubImage = void (OPENGL_STDCALL*) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
														   GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
}

namespace System
{
	PgglGetCompressedTextureSubImage gglGetCompressedTextureSubImage{ nullptr };
	PgglGetTextureSubImage gglGetTextureSubImage{ nullptr };
}

void System
	::GlGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
									 GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) noexcept
{
	SYSTEM_BODY_10(gglGetCompressedTextureSubImage, texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

void System
	::GlGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
						   GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
	SYSTEM_BODY_12(gglGetTextureSubImage, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

void System
	::InitGlArbGetTextureSubImage() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_get_texture_sub_image"))
	{
		g_ExistsGlArbGetTextureSubImage = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetCompressedTextureSubImage);
		SYSTEM_GET_FUNCTION(gglGetTextureSubImage);
	}
	else
	{
		g_ExistsGlArbGetTextureSubImage = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 166) GL_ARB_shader_texture_image_samples

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbShaderTextureImageSamples{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbShaderTextureImageSamples() noexcept
{
	return g_ExistsGlArbShaderTextureImageSamples;
}

namespace System
{
	typedef void (OPENGL_STDCALL* PgglTextureBarrier) (void);
}

namespace System
{
	PgglTextureBarrier gglTextureBarrier{ nullptr };
}

void System
	::GlTextureBarrier(void) noexcept
{
	SYSTEM_BODY_0(gglTextureBarrier);
}

void System
	::InitGlArbShaderTextureImageSamples() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_shader_texture_image_samples"))
	{
		g_ExistsGlArbShaderTextureImageSamples = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTextureBarrier);
	}
	else
	{
		g_ExistsGlArbShaderTextureImageSamples = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 167) GL_ARB_texture_barrier

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTextureBarrier{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTextureBarrier() noexcept
{
	return g_ExistsGlArbTextureBarrier;
}

void System
	::InitGlArbTextureBarrier() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_texture_barrier"))
	{
		g_ExistsGlArbTextureBarrier = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTextureBarrier = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 171) GL_ARB_pipeline_statistics_query 

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbPipelineStatisticsQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbPipelineStatisticsQuery() noexcept
{
	return g_ExistsGlArbPipelineStatisticsQuery;
}

void System
	::InitGlArbPipelineStatisticsQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_pipeline_statistics_query"))
	{
		g_ExistsGlArbPipelineStatisticsQuery = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbPipelineStatisticsQuery = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 172) GL_ARB_sparse_buffer 

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbSparseBuffer{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbSparseBuffer() noexcept
{
	return g_ExistsGlArbSparseBuffer;
}

namespace System
{
	using PgglBufferPageCommitmentARB = void (OPENGL_STDCALL*) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
}

namespace System
{
	PgglBufferPageCommitmentARB gglBufferPageCommitmentARB{ nullptr };
}

void System
	::GlBufferPageCommitmentARB(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) noexcept
{
	SYSTEM_BODY_4(gglBufferPageCommitmentARB, target, offset, size, commit);
}

void System
	::InitGlArbSparseBuffer() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_sparse_buffer"))
	{
		g_ExistsGlArbSparseBuffer = ExistsOpenGLExtensions::Exists;
		SYSTEM_GET_FUNCTION(gglBufferPageCommitmentARB);
	}
	else
	{
		g_ExistsGlArbSparseBuffer = ExistsOpenGLExtensions::NotExist;
	}
}

// (ARB 173) GL_ARB_transform_feedback_overflow_query 

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlArbTransformFeedbackOverflowQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlArbTransformFeedbackOverflowQuery() noexcept
{
	return g_ExistsGlArbTransformFeedbackOverflowQuery;
}

void System
	::InitGlArbTransformFeedbackOverflowQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_ARB_transform_feedback_overflow_query"))
	{
		g_ExistsGlArbTransformFeedbackOverflowQuery = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlArbTransformFeedbackOverflowQuery = ExistsOpenGLExtensions::NotExist;
	}
}

void System
	::InitGlArb() noexcept
{
	InitGlArbMultitexture();
	InitGlArbTransposeMatrix();
	InitGlArbMultisample();
	InitGlArbTextureEnvAdd();
	InitGlArbTextureCubeMap();
	InitGlArbTextureCompression();
	InitGlArbTextureBorderClamp();
	InitGlArbPointParameters();
	InitGlArbVertexBlend();
	InitGlArbMatrixPalette();
	InitGlArbTextureEnvCombine();
	InitGlArbTextureEnvCrossbar();
	InitGlArbTextureEnvDot3();
	InitGlArbTextureMirroredRepeat();
	InitGlArbDepthTexture();
	InitGlArbShadow();
	InitGlArbShadowAmbient();
	InitGlArbWindowPos();
	InitGlArbVertexProgram();
	InitGlArbFragmentProgram();
	InitGlArbVertexBufferObject();
	InitGlArbOcclusionQuery();
	InitGlArbShaderObjects();
	InitGlArbVertexShader();
	InitGlArbFragmentShader();
	InitGlArbShadingLanguage100();
	InitGlArbTextureNonpowerOfTwo();
	InitGlArbPointSprite();
	InitGlArbFragmentProgramShadow();
	InitGlArbDrawBuffers();
	InitGlArbTextureRectangle();
	InitGlArbColorBufferFloat();
	InitGlArbHalfFloatPixel();
	InitGlArbTextureFloat();
	InitGlArbPixelBufferObject();
	InitGlArbDepthBufferFloat();
	InitGlArbDrawInstanced();
	InitGlArbFramebufferObject();
	InitGlArbFramebufferSRGB();
	InitGlArbGeometryShader4();
	InitGlArbHalfFloatVertex();
	InitGlArbInstancedArrays();
	InitGlArbMapBufferRange();
	InitGlArbTextureBufferObject();
	InitGlArbTextureCompressionRgtc();
	InitGlArbTextureRg();
	InitGlArbVertexArrayObject();
	InitGlArbUniformBufferObject();
	InitGlArbCompatibility();
	InitGlArbCopyBuffer();
	InitGlArbShaderTextureLod();
	InitGlArbDepthClamp();
	InitGlArbDrawElementsBaseVertex();
	InitGlArbFragmentCoordConventions();
	InitGlArbProvokingVertex();
	InitGlArbSeamlessCubeMap();
	InitGlArbSync();
	InitGlArbTextureMultisample();
	InitGlArbVertexArrayBgra();
	InitGlArbDrawBuffersBlend();
	InitGlArbSampleShading();
	InitGlArbTextureCubeMapArray();
	InitGlArbTextureGather();
	InitGlArbTextureQueryLod();
	InitGlArbShadingLanguageInclude();
	InitGlArbTextureCompressionBptc();
	InitGlArbBlendFuncExtended();
	InitGlArbExplicitAttribLocation();
	InitGlArbOcclusionQuery2();
	InitGlArbSamplerObjects();
	InitGlArbShaderBitEncoding();
	InitGlArbTextureRgb10A2ui();
	InitGlArbTextureSwizzle();
	InitGlArbTimerQuery();
	InitGlArbVertexType2_10_10_10Rev();
	InitGlArbDrawIndirect();
	InitGlArbGpuShader5();
	InitGlArbGpuShaderFp64();
	InitGlArbShaderSubroutin();
	InitGlArbTessellationShader();
	InitGlArbTextureBufferObjectRgb32();
	InitGlArbTransformFeedback2();
	InitGlArbTransformFeedback3();
	InitGlArbGetProgramBinary();
	InitGlArbSeparateShaderObjects();
	InitGlArbShaderPrecision();
	InitGlArbVertexAttrib64bit();
	InitGlArbViewportArray();
	InitGlArbClEvent();
	InitGlArbDebugOutput();
	InitGlArbRobustness();
	InitGlArbShaderStencilExport();
	InitGlArbBaseInstance();
	InitGlArbShadingLanguage420pack();
	InitGlArbTransformFeedbackInstanced();
	InitGlArbCompressedTexturePixelStorage();
	InitGlArbConservativeDepth();
	InitGlArbInternalformatQuery();
	InitGlArbMapBufferAlignment();
	InitGlArbShaderAtomicCounters();
	InitGlArbShaderImageLoadStore();
	InitGlArbShadingLanguagePacking();
	InitGlArbTextureStorage();
	InitGlArbArraysOfArrays();
	InitGlArbClearBufferObject();
	InitGlArbComputeShader();
	InitGlArbCopyImage();
	InitGlArbTextureView();
	InitGlArbVertexAttribBinding();
	InitGlArbExplicitUniformLocation();
	InitGlArbFragmentLayerViewport();
	InitGlArbFramebufferNoAttachments();
	InitGlArbInternalformatQuery2();
	InitGlArbInvalidateSubdata();
	InitGlArbMultiDrawIndirect();
	InitGlArbProgramInterfaceQuery();
	InitGlArbRobustBufferAccessBehavior();
	InitGlArbShaderImageSize();
	InitGlArbShaderStorageBufferObject();
	InitGlArbStencilTexturing();
	InitGlArbTextureBufferRange();
	InitGlArbTextureQueryLevels();
	InitGlArbTextureStorageMultisample();
	InitGlArbBufferStorage();
	InitGlArbClearTexture();
	InitGlArbEnhancedLayouts();
	InitGlArbMultiBind();
	InitGlArbQueryBufferObject();
	InitGlArbTextureMirrorClampToEdge();
	InitGlArbTextureStencil8();
	InitGlArbVertexType10f11f11fRev();
	InitGlArbBindlessTexture();
	InitGlArbComputeCariableGroupSize();
	InitGlArbIndirectParameters();
	InitGlArbSeamlessCubemapPerTexture();
	InitGlArbShaderDrawParameters();
	InitGlArbShaderGroupVote();
	InitGlArbSparseTexture();
	InitGlArbClipControl();
	InitGlArbConditionalRenderInverted();
	InitGlArbCullDistance();
	InitGlArbDerivativeControl();
	InitGlArbDirectStateAccess();
	InitGlArbGetTextureSubImage();
	InitGlArbShaderTextureImageSamples();
	InitGlArbTextureBarrier();
	InitGlArbPipelineStatisticsQuery();
	InitGlArbSparseBuffer();
	InitGlArbTransformFeedbackOverflowQuery();
}
