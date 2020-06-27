// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:46)

#include "System/SystemExport.h"

#include "GLEXTExtensions.h"
#include "GLUtility.h" 
#include "GLARBImagingExtensions.h"
#include "GL12Extensions.h"
#include "GL14Extensions.h"
#include "GL20Extensions.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h" 
#include "System/Helper/Detail/OpenGL/GLEXTExtensionsMacro.h" 

//  EXT 扩展

// (EXT 001) GL_EXT_abgr

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtABGR{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtABGR() noexcept
{
	return g_ExistsGlExtABGR;
}

void System
	::InitGlExtABGR() noexcept
{
	if (System::IsOpenGLSupportsExtension("GL_EXT_abgr"))
	{
		g_ExistsGlExtABGR = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtABGR = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 002) GL_EXT_blend_color

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBlendColor{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBlendColor() noexcept
{
	return g_ExistsGlExtBlendColor;
}

namespace System
{
	PgglBlendColor gglBlendColorEXT{ nullptr };
}

void System
	::GlBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) noexcept
{
	SYSTEM_BODY_4(gglBlendColorEXT, red, green, blue, alpha);
}

void System
	::InitGlExtBlendColor() noexcept
{
	if (System::IsOpenGLSupportsExtension("GL_EXT_blend_color"))
	{
		g_ExistsGlExtBlendColor = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendColor, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtBlendColor = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 003) GL_EXT_polygon_offset

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPolygonOffset{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPolygonOffset() noexcept
{
	return g_ExistsGlExtPolygonOffset;
}

namespace System
{
	typedef void (OPENGL_STDCALL* PgglPolygonOffsetEXT) (GLfloat, GLfloat);
}

namespace System
{
	PgglPolygonOffsetEXT gglPolygonOffsetEXT{ nullptr };
}

void System
	::GlPolygonOffsetEXT(GLfloat scale, GLfloat bias) noexcept
{
	SYSTEM_BODY_2(gglPolygonOffsetEXT, scale, bias);
}

void System
	::InitGlExtPolygonOffset() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_polygon_offset"))
	{
		g_ExistsGlExtPolygonOffset = ExistsOpenGLExtensions::Exists;

		// 这个函数是OpenGL 1.1的一部分,所以它不应该被覆盖。
		SYSTEM_GET_FUNCTION(gglPolygonOffsetEXT);
	}
	else
	{
		g_ExistsGlExtPolygonOffset = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 004) GL_EXT_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTexture() noexcept
{
	return g_ExistsGlExtTexture;
}

void System
	::InitGlExtTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture"))
	{
		g_ExistsGlExtTexture = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 006) GL_EXT_texture3D

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTexture3D{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTexture3D() noexcept
{
	return g_ExistsGlExtTexture3D;
}

namespace System
{
	PgglTexImage3D gglTexImage3DEXT{ nullptr };
	PgglTexSubImage3D gglTexSubImage3DEXT{ nullptr };
}

void System
	::GlTexImage3DEXT(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_10(gglTexImage3DEXT, target, level, internalFormat, width, height, depth, border, format, type, data);
}

void System
	::GlTexSubImage3DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width,
						 GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_11(gglTexSubImage3DEXT, target, level, xOffset, yOffset, zOffset, width, height, depth, format, type, data);
}

void System
	::InitGlExtTexture3D() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture3D"))
	{
		g_ExistsGlExtTexture3D = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglTexImage3D, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglTexSubImage3D, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtTexture3D = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 009) GL_EXT_subtexture
namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSubtexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSubtexture() noexcept
{
	return g_ExistsGlExtSubtexture;
}

namespace System
{
	using PgglTexSubImage1DEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*);
	using PgglTexSubImage2DEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
}

namespace System
{
	PgglTexSubImage1DEXT gglTexSubImage1DEXT{ nullptr };
	PgglTexSubImage2DEXT gglTexSubImage2DEXT{ nullptr };
}

void System
	::GlTexSubImage1DEXT(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_7(gglTexSubImage1DEXT, target, level, xOffset, width, format, type, data);
}

void System
	::GlTexSubImage2DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_9(gglTexSubImage2DEXT, target, level, xOffset, yOffset, width, height, format, type, data);
}

void System
	::InitGlExtSubtexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_subtexture"))
	{
		g_ExistsGlExtSubtexture = ExistsOpenGLExtensions::Exists;

		// 这些函数是OpenGL 1.1的一部分,所以它们不应该被覆盖。
		SYSTEM_GET_FUNCTION(gglTexSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglTexSubImage2DEXT);
	}
	else
	{
		g_ExistsGlExtSubtexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 010) GL_EXT_copy_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtCopyTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtCopyTexture() noexcept
{
	return g_ExistsGlExtCopyTexture;
}

namespace System
{
	using PgglCopyTexImage1DEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	using PgglCopyTexImage2DEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	using PgglCopyTexSubImage1DEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLint, GLint, GLsizei);
	using PgglCopyTexSubImage2DEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
}

namespace System
{
	PgglCopyTexImage1DEXT gglCopyTexImage1DEXT{ nullptr };
	PgglCopyTexImage2DEXT gglCopyTexImage2DEXT{ nullptr };
	PgglCopyTexSubImage1DEXT gglCopyTexSubImage1DEXT{ nullptr };
	PgglCopyTexSubImage2DEXT gglCopyTexSubImage2DEXT{ nullptr };
	PgglCopyTexSubImage3D gglCopyTexSubImage3DEXT{ nullptr };
}

void System
	::GlCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) noexcept
{
	SYSTEM_BODY_7(gglCopyTexImage1DEXT, target, level, internalFormat, x, y, width, border);
}

void System
	::GlCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept
{
	SYSTEM_BODY_8(gglCopyTexImage2DEXT, target, level, internalFormat, x, y, width, height, border);
}

void System
	::GlCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_BODY_6(gglCopyTexSubImage1DEXT, target, level, xOffset, x, y, width);
}

void System
	::GlCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_8(gglCopyTexSubImage2DEXT, target, level, xOffset, yOffset, x, y, width, height);
}

void System
	::GlCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_9(gglCopyTexSubImage3DEXT, target, level, xOffset, yOffset, zOffset, x, y, width, height);
}

void System
	::InitGlExtCopyTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_copy_texture"))
	{
		g_ExistsGlExtCopyTexture = ExistsOpenGLExtensions::Exists;

		// 这些函数是OpenGL 1.1的一部分,所以它们不应该被覆盖。
		SYSTEM_GET_FUNCTION(gglCopyTexImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTexImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTexSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTexSubImage2DEXT);

		SYSTEM_GET_FUNCTION_SUFFIX(gglCopyTexSubImage3D, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtCopyTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 011) GL_EXT_histogram

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtHistogram{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtHistogram() noexcept
{
	return g_ExistsGlExtHistogram;
}

namespace System
{
	PgglGetHistogram gglGetHistogramEXT{ nullptr };
	PgglGetHistogramParameterfv gglGetHistogramParameterfvEXT{ nullptr };
	PgglGetHistogramParameteriv gglGetHistogramParameterivEXT{ nullptr };
	PgglGetMinmax gglGetMinmaxEXT{ nullptr };
	PgglGetMinmaxParameterfv gglGetMinmaxParameterfvEXT{ nullptr };
	PgglGetMinmaxParameteriv gglGetMinmaxParameterivEXT{ nullptr };
	PgglHistogram gglHistogramEXT{ nullptr };
	PgglMinmax gglMinmaxEXT{ nullptr };
	PgglResetHistogram gglResetHistogramEXT{ nullptr };
	PgglResetMinmax gglResetMinmaxEXT{ nullptr };
}

void System
	::GlGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept
{
	SYSTEM_BODY_5(gglGetHistogramEXT, target, reset, format, type, values);
}

void System
	::GlGetHistogramParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetHistogramParameterfvEXT, target, name, param);
}

void System
	::GlGetHistogramParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetHistogramParameterivEXT, target, name, param);
}

void System
	::GlGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values) noexcept
{
	SYSTEM_BODY_5(gglGetMinmaxEXT, target, reset, format, type, values);
}

void System
	::GlGetMinmaxParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetMinmaxParameterfvEXT, target, name, param);
}

void System
	::GlGetMinmaxParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetMinmaxParameterivEXT, target, name, param);
}

void System
	::GlHistogramEXT(GLenum target, GLsizei width, GLenum internalFormat, GLboolean sink) noexcept
{
	SYSTEM_BODY_4(gglHistogramEXT, target, width, internalFormat, sink);
}

void System
	::GlMinmaxEXT(GLenum target, GLenum internalFormat, GLboolean sink) noexcept
{
	SYSTEM_BODY_3(gglMinmaxEXT, target, internalFormat, sink);
}

void System
	::GlResetHistogramEXT(GLenum target) noexcept
{
	SYSTEM_BODY_1(gglResetHistogramEXT, target);
}

void System
	::GlResetMinmaxEXT(GLenum target) noexcept
{
	SYSTEM_BODY_1(gglResetMinmaxEXT, target);
}

void System
	::InitGlExtHistogram() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_histogram"))
	{
		g_ExistsGlExtHistogram = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglGetHistogram, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetHistogramParameterfv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetHistogramParameteriv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetMinmax, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetMinmaxParameterfv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetMinmaxParameteriv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglHistogram, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMinmax, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglResetHistogram, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglResetMinmax, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtHistogram = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 012) GL_EXT_convolution

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtConvolution{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtConvolution() noexcept
{
	return g_ExistsGlExtConvolution;
}

namespace System
{
	PgglConvolutionFilter1D gglConvolutionFilter1DEXT{ nullptr };
	PgglConvolutionFilter2D gglConvolutionFilter2DEXT{ nullptr };
	PgglConvolutionParameterf gglConvolutionParameterfEXT{ nullptr };
	PgglConvolutionParameterfv gglConvolutionParameterfvEXT{ nullptr };
	PgglConvolutionParameteri gglConvolutionParameteriEXT{ nullptr };
	PgglConvolutionParameteriv gglConvolutionParameterivEXT{ nullptr };
	PgglCopyConvolutionFilter1D gglCopyConvolutionFilter1DEXT{ nullptr };
	PgglCopyConvolutionFilter2D gglCopyConvolutionFilter2DEXT{ nullptr };
	PgglGetConvolutionFilter gglGetConvolutionFilterEXT{ nullptr };
	PgglGetConvolutionParameterfv gglGetConvolutionParameterfvEXT{ nullptr };
	PgglGetConvolutionParameteriv gglGetConvolutionParameterivEXT{ nullptr };
	PgglGetSeparableFilter gglGetSeparableFilterEXT{ nullptr };
	PgglSeparableFilter2D gglSeparableFilter2DEXT{ nullptr };
}

void System
	::GlConvolutionFilter1DEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* image) noexcept
{
	SYSTEM_BODY_6(gglConvolutionFilter1DEXT, target, internalFormat, width, format, type, image);
}

void System
	::GlConvolutionFilter2DEXT(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image) noexcept
{
	SYSTEM_BODY_7(gglConvolutionFilter2DEXT, target, internalFormat, width, height, format, type, image);
}

void System
	::GlConvolutionParameterfEXT(GLenum target, GLenum name, GLfloat param) noexcept
{
	SYSTEM_BODY_3(gglConvolutionParameterfEXT, target, name, param);
}

void System
	::GlConvolutionParameterfvEXT(GLenum target, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglConvolutionParameterfvEXT, target, name, param);
}

void System
	::GlConvolutionParameteriEXT(GLenum target, GLenum name, GLint param) noexcept
{
	SYSTEM_BODY_3(gglConvolutionParameteriEXT, target, name, param);
}

void System
	::GlConvolutionParameterivEXT(GLenum target, GLenum name, const GLint* param) noexcept
{
	SYSTEM_BODY_3(gglConvolutionParameterivEXT, target, name, param);
}

void System
	::GlCopyConvolutionFilter1DEXT(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_BODY_5(gglCopyConvolutionFilter1DEXT, target, internalFormat, x, y, width);
}

void System
	::GlCopyConvolutionFilter2DEXT(GLenum target, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_6(gglCopyConvolutionFilter2DEXT, target, internalFormat, x, y, width, height);
}

void System
	::GlGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid* image) noexcept
{
	SYSTEM_BODY_4(gglGetConvolutionFilterEXT, target, format, type, image);
}

void System
	::GlGetConvolutionParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetConvolutionParameterfvEXT, target, name, param);
}

void System
	::GlGetConvolutionParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetConvolutionParameterivEXT, target, name, param);
}

void System
	::GlGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span) noexcept
{
	SYSTEM_BODY_6(gglGetSeparableFilterEXT, target, format, type, row, column, span);
}

void System
	::GlSeparableFilter2DEXT(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column) noexcept
{
	SYSTEM_BODY_8(gglSeparableFilter2DEXT, target, internalFormat, width, height, format, type, row, column);
}

void System
	::InitGlExtConvolution() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_convolution"))
	{
		g_ExistsGlExtConvolution = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglConvolutionFilter1D, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglConvolutionFilter2D, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglConvolutionParameterf, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglConvolutionParameterfv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglConvolutionParameteri, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglConvolutionParameteriv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCopyConvolutionFilter1D, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCopyConvolutionFilter2D, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetConvolutionFilter, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetConvolutionParameterfv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetConvolutionParameteriv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetSeparableFilter, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSeparableFilter2D, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtConvolution = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 018) GL_EXT_cmyka

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtCMYKA{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtCMYKA() noexcept
{
	return g_ExistsGlExtCMYKA;
}

void System
	::InitGlExtCMYKA() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_cmyka"))
	{
		g_ExistsGlExtCMYKA = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtCMYKA = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 020) GL_EXT_texture_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureObject() noexcept
{
	return g_ExistsGlExtTextureObject;
}

namespace System
{
	using PgglAreTexturesResidentEXT = GLboolean(OPENGL_STDCALL*) (GLsizei, const GLuint*, GLboolean*);
	using PgglBindTextureEXT = void (OPENGL_STDCALL*) (GLenum, GLuint);
	using PgglDeleteTexturesEXT = void (OPENGL_STDCALL*) (GLsizei, const GLuint*);
	using PgglGenTexturesEXT = void (OPENGL_STDCALL*) (GLsizei, GLuint*);
	using PgglIsTextureEXT = GLboolean(OPENGL_STDCALL*) (GLuint);
	using PgglPrioritizeTexturesEXT = void (OPENGL_STDCALL*) (GLsizei, const GLuint*, const GLclampf*);
}

namespace System
{
	PgglAreTexturesResidentEXT gglAreTexturesResidentEXT{ nullptr };
	PgglBindTextureEXT gglBindTextureEXT{ nullptr };
	PgglDeleteTexturesEXT gglDeleteTexturesEXT{ nullptr };
	PgglGenTexturesEXT gglGenTexturesEXT{ nullptr };
	PgglIsTextureEXT gglIsTextureEXT{ nullptr };
	PgglPrioritizeTexturesEXT gglPrioritizeTexturesEXT{ nullptr };
}

GLboolean System
	::GlAreTexturesResidentEXT(GLsizei numTextures, const GLuint* textures, GLboolean* residences) noexcept
{
	SYSTEM_BODY_3_RESULT(gglAreTexturesResidentEXT, numTextures, textures, residences, GLboolean, GL_FALSE);
}

void System
	::GlBindTextureEXT(GLenum target, GLuint texture) noexcept
{
	SYSTEM_BODY_2(gglBindTextureEXT, target, texture);
}

void System
	::GlDeleteTexturesEXT(GLsizei numTextures, const GLuint* textures) noexcept
{
	SYSTEM_BODY_2(gglDeleteTexturesEXT, numTextures, textures);
}

void System
	::GlGenTexturesEXT(GLsizei numTextures, GLuint* texture) noexcept
{
	SYSTEM_BODY_2(gglGenTexturesEXT, numTextures, texture);
}

GLboolean System
	::GlIsTextureEXT(GLuint texture) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsTextureEXT, texture, GLboolean, 0);
}

void System
	::GlPrioritizeTexturesEXT(GLsizei numTextures, const GLuint* textures, const GLclampf* priorities) noexcept
{
	SYSTEM_BODY_3(gglPrioritizeTexturesEXT, numTextures, textures, priorities);
}

void System
	::InitGlExtTextureObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_object"))
	{
		g_ExistsGlExtTextureObject = ExistsOpenGLExtensions::Exists;

		// 这些函数是OpenGL 1.1的一部分,所以它们不应该被覆盖。
		SYSTEM_GET_FUNCTION(gglAreTexturesResidentEXT);
		SYSTEM_GET_FUNCTION(gglBindTextureEXT);
		SYSTEM_GET_FUNCTION(gglDeleteTexturesEXT);
		SYSTEM_GET_FUNCTION(gglGenTexturesEXT);
		SYSTEM_GET_FUNCTION(gglIsTextureEXT);
		SYSTEM_GET_FUNCTION(gglPrioritizeTexturesEXT);
	}
	else
	{
		g_ExistsGlExtTextureObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 023) GL_EXT_packed_pixels

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPackedPixels{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPackedPixels() noexcept
{
	return g_ExistsGlExtPackedPixels;
}

void System
	::InitGlExtPackedPixels() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_packed_pixels"))
	{
		g_ExistsGlExtPackedPixels = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtPackedPixels = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 027) GL_EXT_rescale_normal

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtRescaleNormal{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtRescaleNormal() noexcept
{
	return g_ExistsGlExtRescaleNormal;
}

void System
	::InitGlExtRescaleNormal() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_rescale_normal"))
	{
		g_ExistsGlExtRescaleNormal = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtRescaleNormal = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 030) GL_EXT_vertex_array

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtVertexArray{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtVertexArray() noexcept
{
	return g_ExistsGlExtVertexArray;
}

namespace System
{
	using PgglArrayElementEXT = void (OPENGL_STDCALL*) (GLint);
	using PgglDrawArraysEXT = void (OPENGL_STDCALL*) (GLenum, GLint, GLsizei);
	using PgglGetPointervEXT = void (OPENGL_STDCALL*) (GLenum, GLvoid**);
	using PgglColorPointerEXT = void (OPENGL_STDCALL*) (GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
	using PgglEdgeFlagPointerEXT = void (OPENGL_STDCALL*) (GLsizei, GLsizei, const GLboolean*);
	using PgglIndexPointerEXT = void (OPENGL_STDCALL*) (GLenum, GLsizei, GLsizei, const GLvoid*);
	using PgglNormalPointerEXT = void (OPENGL_STDCALL*) (GLenum, GLsizei, GLsizei, const GLvoid*);
	using PgglTexCoordPointerEXT = void (OPENGL_STDCALL*) (GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
	using PgglVertexPointerEXT = void (OPENGL_STDCALL*) (GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
}

namespace System
{
	PgglArrayElementEXT gglArrayElementEXT{ nullptr };
	PgglDrawArraysEXT gglDrawArraysEXT{ nullptr };
	PgglGetPointervEXT gglGetPointervEXT{ nullptr };
	PgglColorPointerEXT gglColorPointerEXT{ nullptr };
	PgglEdgeFlagPointerEXT gglEdgeFlagPointerEXT{ nullptr };
	PgglIndexPointerEXT gglIndexPointerEXT{ nullptr };
	PgglNormalPointerEXT gglNormalPointerEXT{ nullptr };
	PgglTexCoordPointerEXT gglTexCoordPointerEXT{ nullptr };
	PgglVertexPointerEXT gglVertexPointerEXT{ nullptr };
}

void System
	::GlArrayElementEXT(GLint i) noexcept
{
	SYSTEM_BODY_1(gglArrayElementEXT, i);
}

void System
	::GlColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_5(gglColorPointerEXT, size, type, stride, count, pointer);
}

void System
	::GlDrawArraysEXT(GLenum mode, GLint first, GLsizei count) noexcept
{
	SYSTEM_BODY_3(gglDrawArraysEXT, mode, first, count);
}

void System
	::GlEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean* pointer) noexcept
{
	SYSTEM_BODY_3(gglEdgeFlagPointerEXT, stride, count, pointer);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetPointervEXT(GLenum name, GLvoid** param) noexcept
{
	SYSTEM_BODY_2(gglGetPointervEXT, name, param);
}
#include STSTEM_WARNING_POP

void System
	::GlIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_4(gglIndexPointerEXT, type, stride, count, pointer);
}

void System
	::GlNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_4(gglNormalPointerEXT, type, stride, count, pointer);
}

void System
	::GlTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_5(gglTexCoordPointerEXT, size, type, stride, count, pointer);
}

void System
	::GlVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_5(gglVertexPointerEXT, size, type, stride, count, pointer);
}

void System
	::InitGlExtVertexArray() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_vertex_array"))
	{
		g_ExistsGlExtVertexArray = ExistsOpenGLExtensions::Exists;

		// 这些函数是OpenGL 1.1的一部分,所以它们不应该被覆盖。
		SYSTEM_GET_FUNCTION(gglArrayElementEXT);
		SYSTEM_GET_FUNCTION(gglDrawArraysEXT);
		SYSTEM_GET_FUNCTION(gglGetPointervEXT);

		SYSTEM_GET_FUNCTION(gglColorPointerEXT);
		SYSTEM_GET_FUNCTION(gglEdgeFlagPointerEXT);
		SYSTEM_GET_FUNCTION(gglIndexPointerEXT);
		SYSTEM_GET_FUNCTION(gglNormalPointerEXT);
		SYSTEM_GET_FUNCTION(gglTexCoordPointerEXT);
		SYSTEM_GET_FUNCTION(gglVertexPointerEXT);
	}
	else
	{
		g_ExistsGlExtVertexArray = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 031) GL_EXT_misc_attribute

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtMiscAttribute{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtMiscAttribute() noexcept
{
	return g_ExistsGlExtMiscAttribute;
}

void System
	::InitGlExtMiscAttribute() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_misc_attribute"))
	{
		g_ExistsGlExtMiscAttribute = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtMiscAttribute = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 035) GL_EXT_texture_edge_clamp

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureEdgeClamp{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureEdgeClamp() noexcept
{
	return g_ExistsGlExtTextureEdgeClamp;
}

void System
	::InitGlExtTextureEdgeClamp() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_edge_clamp"))
	{
		g_ExistsGlExtTextureEdgeClamp = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureEdgeClamp = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 037) GL_EXT_blend_minmax

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBlendMinMax{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBlendMinMax() noexcept
{
	return g_ExistsGlExtBlendMinMax;
}

namespace System
{
	PgglBlendEquation gglBlendEquationEXT{ nullptr };
}

void System
	::GlBlendEquationEXT(GLenum mode) noexcept
{
	SYSTEM_BODY_1(gglBlendEquationEXT, mode);
}

void System
	::InitGlExtBlendMinMax() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_blend_minmax"))
	{
		g_ExistsGlExtBlendMinMax = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendEquation, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtBlendMinMax = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 038) GL_EXT_blend_subtract

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBlendSubtract{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBlendSubtract() noexcept
{
	return g_ExistsGlExtBlendSubtract;
}

void System
	::InitGlExtBlendSubtract() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_blend_subtract"))
	{
		g_ExistsGlExtBlendSubtract = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtBlendSubtract = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 039) GL_EXT_blend_logic_op

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBlendLogicOp{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBlendLogicOp() noexcept
{
	return g_ExistsGlExtBlendLogicOp;
}

void System
	::InitGlExtBlendLogicOp() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_blend_logic_op"))
	{
		g_ExistsGlExtBlendLogicOp = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtBlendLogicOp = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 054) GL_EXT_point_parameters

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPointParameters{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPointParameters() noexcept
{
	return g_ExistsGlExtPointParameters;
}

namespace System
{
	PgglPointParameterf gglPointParameterfEXT{ nullptr };
	PgglPointParameterfv gglPointParameterfvEXT{ nullptr };
}

void System
	::GlPointParameterfEXT(GLenum name, GLfloat param) noexcept
{
	SYSTEM_BODY_2(gglPointParameterfEXT, name, param);
}

void System
	::GlPointParameterfvEXT(GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_BODY_2(gglPointParameterfvEXT, name, param);
}

void System
	::InitGlExtPointParameters() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_point_parameters"))
	{
		g_ExistsGlExtPointParameters = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglPointParameterf, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglPointParameterfv, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtPointParameters = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 074) GL_EXT_color_subtable

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtColorSubtable{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtColorSubtable() noexcept
{
	return g_ExistsGlExtColorSubtable;
}

namespace System
{
	PgglColorSubTable gglColorSubTableEXT{ nullptr };
	PgglCopyColorSubTable gglCopyColorSubTableEXT{ nullptr };
}

void System
	::GlColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data) noexcept
{
	SYSTEM_BODY_6(gglColorSubTableEXT, target, start, count, format, type, data);
}

void System
	::GlCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_BODY_5(gglCopyColorSubTableEXT, target, start, x, y, width);
}

void System
	::InitGlExtColorSubtable() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_color_subtable"))
	{
		g_ExistsGlExtColorSubtable = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglColorSubTable, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglCopyColorSubTable, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtColorSubtable = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 078) GL_EXT_paletted_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPalettedTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPalettedTexture() noexcept
{
	return g_ExistsGlExtPalettedTexture;
}

namespace System
{
	PgglColorTable gglColorTableEXT{ nullptr };
	PgglGetColorTable gglGetColorTableEXT{ nullptr };
	PgglGetColorTableParameterfv gglGetColorTableParameterfvEXT{ nullptr };
	PgglGetColorTableParameteriv gglGetColorTableParameterivEXT{ nullptr };
}

void System
	::GlColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* table) noexcept
{
	SYSTEM_BODY_6(gglColorTableEXT, target, internalFormat, width, format, type, table);
}

void System
	::GlGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid* table) noexcept
{
	SYSTEM_BODY_4(gglGetColorTableEXT, target, format, type, table);
}

void System
	::GlGetColorTableParameterfvEXT(GLenum target, GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglGetColorTableParameterfvEXT, target, name, param);
}

void System
	::GlGetColorTableParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetColorTableParameterivEXT, target, name, param);
}

void System
	::InitGlExtPalettedTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_paletted_texture"))
	{
		g_ExistsGlExtPalettedTexture = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglColorTable, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetColorTable, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetColorTableParameterfv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglGetColorTableParameteriv, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtPalettedTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 079) GL_EXT_clip_volume_hint

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtClipVolumeHint{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtClipVolumeHint() noexcept
{
	return g_ExistsGlExtClipVolumeHint;
}

void System
	::InitGlExtClipVolumeHint() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_clip_volume_hint"))
	{
		g_ExistsGlExtClipVolumeHint = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtClipVolumeHint = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 093) GL_EXT_index_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtIndexTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtIndexTexture() noexcept
{
	return g_ExistsGlExtIndexTexture;
}

void System
	::InitGlExtIndexTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_index_texture"))
	{
		g_ExistsGlExtIndexTexture = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtIndexTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 094) GL_EXT_index_material

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtIndexMaterial{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtIndexMaterial() noexcept
{
	return g_ExistsGlExtIndexMaterial;
}

namespace System
{
	using PgglIndexMaterialEXT = void (OPENGL_STDCALL*) (GLenum, GLenum);
}

namespace System
{
	PgglIndexMaterialEXT gglIndexMaterialEXT{ nullptr };
}

void System
	::GlIndexMaterialEXT(GLenum face, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglIndexMaterialEXT, face, mode);
}

void System
	::InitGlExtIndexMaterial() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_index_material"))
	{
		g_ExistsGlExtIndexMaterial = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglIndexMaterialEXT);
	}
	else
	{
		g_ExistsGlExtIndexMaterial = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 095) GL_EXT_index_func

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtIndexFunc{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtIndexFunc() noexcept
{
	return g_ExistsGlExtIndexFunc;
}

namespace System
{
	using PgglIndexFuncEXT = void (OPENGL_STDCALL*) (GLenum, GLclampf);
}

namespace System
{
	PgglIndexFuncEXT gglIndexFuncEXT{ nullptr };
}

void System
	::GlIndexFuncEXT(GLenum eFunction, GLclampf fReference) noexcept
{
	SYSTEM_BODY_2(gglIndexFuncEXT, eFunction, fReference);
}

void System
	::InitGlExtIndexFunc() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_index_func"))
	{
		g_ExistsGlExtIndexFunc = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglIndexFuncEXT);
	}
	else
	{
		g_ExistsGlExtIndexFunc = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 096) GL_EXT_index_array_formats

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtIndexArrayFormats{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtIndexArrayFormats() noexcept
{
	return g_ExistsGlExtIndexArrayFormats;
}

void System
	::InitGlExtIndexArrayFormats() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_index_array_formats"))
	{
		g_ExistsGlExtIndexArrayFormats = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtIndexArrayFormats = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 097) GL_EXT_compiled_vertex_array

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtCompiledVertexArray{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtCompiledVertexArray() noexcept
{
	return g_ExistsGlExtCompiledVertexArray;
}

namespace System
{
	using PgglLockArraysEXT = void (OPENGL_STDCALL*) (GLint, GLsizei);
	using PgglUnlockArraysEXT = void (OPENGL_STDCALL*) ();
}

namespace System
{
	PgglLockArraysEXT gglLockArraysEXT{ nullptr };
	PgglUnlockArraysEXT gglUnlockArraysEXT{ nullptr };
}

void System
	::GlLockArraysEXT(GLint first, GLsizei count) noexcept
{
	SYSTEM_BODY_2(gglLockArraysEXT, first, count);
}

void System
	::GlUnlockArraysEXT() noexcept
{
	SYSTEM_BODY_0(gglUnlockArraysEXT);
}

void System
	::InitGlExtCompiledVertexArray() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_compiled_vertex_array"))
	{
		g_ExistsGlExtCompiledVertexArray = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglLockArraysEXT);
		SYSTEM_GET_FUNCTION(gglUnlockArraysEXT);
	}
	else
	{
		g_ExistsGlExtCompiledVertexArray = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 098) GL_EXT_cull_vertex

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtCullVertex{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtCullVertex() noexcept
{
	return g_ExistsGlExtCullVertex;
}

namespace System
{
	using PgglCullParameterdvEXT = void (OPENGL_STDCALL*) (GLenum, GLdouble*);
	using PgglCullParameterfvEXT = void (OPENGL_STDCALL*) (GLenum, GLfloat*);
}

namespace System
{
	PgglCullParameterdvEXT gglCullParameterdvEXT{ nullptr };
	PgglCullParameterfvEXT gglCullParameterfvEXT{ nullptr };
}

void System
	::GlCullParameterdvEXT(GLenum name, GLdouble* param) noexcept
{
	SYSTEM_BODY_2(gglCullParameterdvEXT, name, param);
}

void System
	::GlCullParameterfvEXT(GLenum name, GLfloat* param) noexcept
{
	SYSTEM_BODY_2(gglCullParameterfvEXT, name, param);
}

void System
	::InitGlExtCullVertex() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_cull_vertex"))
	{
		g_ExistsGlExtCullVertex = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCullParameterdvEXT);
		SYSTEM_GET_FUNCTION(gglCullParameterfvEXT);
	}
	else
	{
		g_ExistsGlExtCullVertex = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 102) GL_EXT_fragment_lighting

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFragmentLighting{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFragmentLighting() noexcept
{
	return g_ExistsGlExtFragmentLighting;
}

namespace System
{
	using PgglFragmentColorMaterialEXT = void (OPENGL_STDCALL*) (GLenum face, GLenum mode);
	using PgglFragmentLightModelfEXT = void (OPENGL_STDCALL*)(GLenum parameterName, GLfloat param);
	using PgglFragmentLightModelfvEXT = void (OPENGL_STDCALL*) (GLenum parameterName, GLfloat* params);
	using PgglFragmentLightModeliEXT = void (OPENGL_STDCALL*)(GLenum parameterName, GLint param);
	using PgglFragmentLightModelivEXT = void (OPENGL_STDCALL*) (GLenum parameterName, GLint* params);
	using PgglFragmentLightfEXT = void (OPENGL_STDCALL*) (GLenum light, GLenum parameterName, GLfloat param);
	using PgglFragmentLightfvEXT = void (OPENGL_STDCALL*) (GLenum light, GLenum parameterName, GLfloat* params);
	using PgglFragmentLightiEXT = void (OPENGL_STDCALL*) (GLenum light, GLenum parameterName, GLint param);
	using PgglFragmentLightivEXT = void (OPENGL_STDCALL*) (GLenum light, GLenum parameterName, GLint* params);
	using PgglFragmentMaterialfEXT = void (OPENGL_STDCALL*) (GLenum face, GLenum parameterName, const GLfloat param);
	using PgglFragmentMaterialfvEXT = void (OPENGL_STDCALL*) (GLenum face, GLenum parameterName, const GLfloat* params);
	using PgglFragmentMaterialiEXT = void (OPENGL_STDCALL*) (GLenum face, GLenum parameterName, const GLint param);
	using PgglFragmentMaterialivEXT = void (OPENGL_STDCALL*)(GLenum face, GLenum parameterName, const GLint* params);
	using PgglGetFragmentLightfvEXT = void (OPENGL_STDCALL*) (GLenum light, GLenum parameterName, GLfloat* params);
	using PgglGetFragmentLightivEXT = void (OPENGL_STDCALL*) (GLenum light, GLenum parameterName, GLint* params);
	using PgglGetFragmentMaterialfvEXT = void (OPENGL_STDCALL*)(GLenum face, GLenum parameterName, const GLfloat* params);
	using PgglGetFragmentMaterialivEXT = void (OPENGL_STDCALL*) (GLenum face, GLenum parameterName, const GLint* params);
	using PgglLightEnviEXT = void (OPENGL_STDCALL*) (GLenum parameterName, GLint param);
}

namespace System
{
	PgglFragmentColorMaterialEXT gglFragmentColorMaterialEXT{ nullptr };
	PgglFragmentLightModelfEXT gglFragmentLightModelfEXT{ nullptr };
	PgglFragmentLightModelfvEXT gglFragmentLightModelfvEXT{ nullptr };
	PgglFragmentLightModeliEXT gglFragmentLightModeliEXT{ nullptr };
	PgglFragmentLightModelivEXT gglFragmentLightModelivEXT{ nullptr };
	PgglFragmentLightfEXT gglFragmentLightfEXT{ nullptr };
	PgglFragmentLightfvEXT gglFragmentLightfvEXT{ nullptr };
	PgglFragmentLightiEXT gglFragmentLightiEXT{ nullptr };
	PgglFragmentLightivEXT gglFragmentLightivEXT{ nullptr };
	PgglFragmentMaterialfEXT gglFragmentMaterialfEXT{ nullptr };
	PgglFragmentMaterialfvEXT gglFragmentMaterialfvEXT{ nullptr };
	PgglFragmentMaterialiEXT gglFragmentMaterialiEXT{ nullptr };
	PgglFragmentMaterialivEXT gglFragmentMaterialivEXT{ nullptr };
	PgglGetFragmentLightfvEXT gglGetFragmentLightfvEXT{ nullptr };
	PgglGetFragmentLightivEXT gglGetFragmentLightivEXT{ nullptr };
	PgglGetFragmentMaterialfvEXT gglGetFragmentMaterialfvEXT{ nullptr };
	PgglGetFragmentMaterialivEXT gglGetFragmentMaterialivEXT{ nullptr };
	PgglLightEnviEXT gglLightEnviEXT{ nullptr };
}

void System
	::GlFragmentColorMaterialEXT(GLenum face, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglFragmentColorMaterialEXT, face, mode);
}

void System
	::GlFragmentLightModelfEXT(GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_2(gglFragmentLightModelfEXT, parameterName, param);
}

void System
	::GlFragmentLightModelfvEXT(GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_2(gglFragmentLightModelfvEXT, parameterName, params);
}

void System
	::GlFragmentLightModeliEXT(GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_2(gglFragmentLightModeliEXT, parameterName, param);
}

void System
	::GlFragmentLightModelivEXT(GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_2(gglFragmentLightModelivEXT, parameterName, params);
}

void System
	::GlFragmentLightfEXT(GLenum light, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_3(gglFragmentLightfEXT, light, parameterName, param);
}

void System
	::GlFragmentLightfvEXT(GLenum light, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglFragmentLightfvEXT, light, parameterName, params);
}

void System
	::GlFragmentLightiEXT(GLenum light, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_3(gglFragmentLightiEXT, light, parameterName, param);
}

void System
	::GlFragmentLightivEXT(GLenum light, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglFragmentLightivEXT, light, parameterName, params);
}

void System
	::GlFragmentMaterialfEXT(GLenum face, GLenum parameterName, const GLfloat param) noexcept
{
	SYSTEM_BODY_3(gglFragmentMaterialfEXT, face, parameterName, param);
}

void System
	::GlFragmentMaterialfvEXT(GLenum face, GLenum parameterName, const GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglFragmentMaterialfvEXT, face, parameterName, params);
}

void System
	::GlFragmentMaterialiEXT(GLenum face, GLenum parameterName, const GLint param) noexcept
{
	SYSTEM_BODY_3(gglFragmentMaterialiEXT, face, parameterName, param);
}

void System
	::GlFragmentMaterialivEXT(GLenum face, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglFragmentMaterialivEXT, face, parameterName, params);
}

void System
	::GlGetFragmentLightfvEXT(GLenum light, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglGetFragmentLightfvEXT, light, parameterName, params);
}

void System
	::GlGetFragmentLightivEXT(GLenum light, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetFragmentLightivEXT, light, parameterName, params);
}

void System
	::GlGetFragmentMaterialfvEXT(GLenum face, GLenum parameterName, const GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglGetFragmentMaterialfvEXT, face, parameterName, params);
}

void System
	::GlGetFragmentMaterialivEXT(GLenum face, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetFragmentMaterialivEXT, face, parameterName, params);
}

void System
	::GlLightEnviEXT(GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_2(gglLightEnviEXT, parameterName, param);
}

void System
	::InitGlExtFragmentLighting() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_fragment_lighting"))
	{
		g_ExistsGlExtFragmentLighting = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglFragmentColorMaterialEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightModelfEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightModelfvEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightModeliEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightModelivEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightfEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightfvEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightiEXT);
		SYSTEM_GET_FUNCTION(gglFragmentLightivEXT);
		SYSTEM_GET_FUNCTION(gglFragmentMaterialfEXT);
		SYSTEM_GET_FUNCTION(gglFragmentMaterialfvEXT);
		SYSTEM_GET_FUNCTION(gglFragmentMaterialiEXT);
		SYSTEM_GET_FUNCTION(gglFragmentMaterialivEXT);
		SYSTEM_GET_FUNCTION(gglGetFragmentLightfvEXT);
		SYSTEM_GET_FUNCTION(gglGetFragmentLightivEXT);
		SYSTEM_GET_FUNCTION(gglGetFragmentMaterialfvEXT);
		SYSTEM_GET_FUNCTION(gglGetFragmentMaterialivEXT);
		SYSTEM_GET_FUNCTION(gglLightEnviEXT);
	}
	else
	{
		g_ExistsGlExtFragmentLighting = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 112) GL_EXT_draw_range_elements

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDrawRangeElements{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDrawRangeElements() noexcept
{
	return g_ExistsGlExtDrawRangeElements;
}

namespace System
{
	PgglDrawRangeElements gglDrawRangeElementsEXT{ nullptr };
}

void System
	::GlDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices) noexcept
{
	SYSTEM_BODY_6(gglDrawRangeElementsEXT, mode, start, end, count, type, indices);
}

void System
	::InitGlExtDrawRangeElements() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_draw_range_elements"))
	{
		g_ExistsGlExtDrawRangeElements = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglDrawRangeElements, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtDrawRangeElements = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 117) GL_EXT_light_texture

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtLightTexture{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtLightTexture() noexcept
{
	return g_ExistsGlExtLightTexture;
}

namespace System
{
	using PgglApplyTextureEXT = void (OPENGL_STDCALL*) (GLenum);
	using PgglTextureLightEXT = void (OPENGL_STDCALL*) (GLenum);
	using PgglTextureMaterialEXT = void (OPENGL_STDCALL*) (GLenum, GLenum);
}

namespace System
{
	PgglApplyTextureEXT gglApplyTextureEXT{ nullptr };
	PgglTextureLightEXT gglTextureLightEXT{ nullptr };
	PgglTextureMaterialEXT gglTextureMaterialEXT{ nullptr };
}

void System
	::GlApplyTextureEXT(GLenum mode) noexcept
{
	SYSTEM_BODY_1(gglApplyTextureEXT, mode);
}

void System
	::GlTextureLightEXT(GLenum name) noexcept
{
	SYSTEM_BODY_1(gglTextureLightEXT, name);
}

void System
	::GlTextureMaterialEXT(GLenum face, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglTextureMaterialEXT, face, mode);
}

void System
	::InitGlExtLightTexture() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_light_texture"))
	{
		g_ExistsGlExtLightTexture = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglApplyTextureEXT);
		SYSTEM_GET_FUNCTION(gglTextureLightEXT);
		SYSTEM_GET_FUNCTION(gglTextureMaterialEXT);
	}
	else
	{
		g_ExistsGlExtLightTexture = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 120) GL_EXT_scene_marker

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSceneMarker{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSceneMarker() noexcept
{
	return g_ExistsGlExtSceneMarker;
}

namespace System
{
	using PgglBeginSceneEXT = void (OPENGL_STDCALL*) (void);
	using PgglEndSceneEXT = void (OPENGL_STDCALL*) (void);
}

namespace System
{
	PgglBeginSceneEXT gglBeginSceneEXT{ nullptr };
	PgglEndSceneEXT gglEndSceneEXT{ nullptr };
}

void System
	::GlBeginSceneEXT(void) noexcept
{
	SYSTEM_BODY_0(gglBeginSceneEXT);
}

void System
	::GlEndSceneEXT(void) noexcept
{
	SYSTEM_BODY_0(gglEndSceneEXT);
}

void System
	::InitGlExtSceneMarker() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_scene_marker"))
	{
		g_ExistsGlExtSceneMarker = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBeginSceneEXT);
		SYSTEM_GET_FUNCTION(gglEndSceneEXT);
	}
	else
	{
		g_ExistsGlExtSceneMarker = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 129) GL_EXT_bgra

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBGRA{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBGRA() noexcept
{
	return g_ExistsGlExtBGRA;
}

void System
	::InitGlExtBGRA() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_bgra"))
	{
		g_ExistsGlExtBGRA = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtBGRA = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 138) GL_EXT_pixel_transform

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPixelTransform{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPixelTransform() noexcept
{
	return g_ExistsGlExtPixelTransform;
}

namespace System
{
	using PgglPixelTransformParameteriEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint);
	using PgglPixelTransformParameterfEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLfloat);
	using PgglPixelTransformParameterivEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, const GLint*);
	using PgglPixelTransformParameterfvEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, const GLfloat*);
}

namespace System
{
	PgglPixelTransformParameteriEXT gglPixelTransformParameteriEXT{ nullptr };
	PgglPixelTransformParameterfEXT gglPixelTransformParameterfEXT{ nullptr };
	PgglPixelTransformParameterivEXT gglPixelTransformParameterivEXT{ nullptr };
	PgglPixelTransformParameterfvEXT gglPixelTransformParameterfvEXT{ nullptr };
}

void System
	::GlPixelTransformParameteriEXT(GLenum target, GLenum name, GLint param) noexcept
{
	SYSTEM_BODY_3(gglPixelTransformParameteriEXT, target, name, param);
}

void System
	::GlPixelTransformParameterfEXT(GLenum target, GLenum name, GLfloat param) noexcept
{
	SYSTEM_BODY_3(gglPixelTransformParameterfEXT, target, name, param);
}

void System
	::GlPixelTransformParameterivEXT(GLenum target, GLenum name, const GLint* param) noexcept
{
	SYSTEM_BODY_3(gglPixelTransformParameterivEXT, target, name, param);
}

void System
	::GlPixelTransformParameterfvEXT(GLenum target, GLenum name, const GLfloat* param) noexcept
{
	SYSTEM_BODY_3(gglPixelTransformParameterfvEXT, target, name, param);
}

void System
	::InitGlExtPixelTransform() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_pixel_transform"))
	{
		g_ExistsGlExtPixelTransform = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglPixelTransformParameteriEXT);
		SYSTEM_GET_FUNCTION(gglPixelTransformParameterfEXT);
		SYSTEM_GET_FUNCTION(gglPixelTransformParameterivEXT);
		SYSTEM_GET_FUNCTION(gglPixelTransformParameterfvEXT);
	}
	else
	{
		g_ExistsGlExtPixelTransform = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 139) GL_EXT_pixel_transform_color_table

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPixelTransformColorTable{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPixelTransformColorTable() noexcept
{
	return g_ExistsGlExtPixelTransformColorTable;
}

void System
	::InitGlExtPixelTransformColorTable() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_pixel_transform_color_table"))
	{
		g_ExistsGlExtPixelTransformColorTable = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtPixelTransformColorTable = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 141) GL_EXT_shared_texture_palette

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSharedTexturePalette{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSharedTexturePalette() noexcept
{
	return g_ExistsGlExtSharedTexturePalette;
}

void System
	::InitGlExtSharedTexturePalette() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_shared_texture_palette"))
	{
		g_ExistsGlExtSharedTexturePalette = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtSharedTexturePalette = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 144) GL_EXT_separate_specular_color

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSeparateSpecularColor{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSeparateSpecularColor() noexcept
{
	return g_ExistsGlExtSeparateSpecularColor;
}

void System
	::InitGlExtSeparateSpecularColor() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_separate_specular_color"))
	{
		g_ExistsGlExtSeparateSpecularColor = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtSeparateSpecularColor = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 145) GL_EXT_secondary_color

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSecondaryColor{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSecondaryColor() noexcept
{
	return g_ExistsGlExtSecondaryColor;
}

namespace System
{
	PgglSecondaryColor3b gglSecondaryColor3bEXT{ nullptr };
	PgglSecondaryColor3bv gglSecondaryColor3bvEXT{ nullptr };
	PgglSecondaryColor3d gglSecondaryColor3dEXT{ nullptr };
	PgglSecondaryColor3dv gglSecondaryColor3dvEXT{ nullptr };
	PgglSecondaryColor3f gglSecondaryColor3fEXT{ nullptr };
	PgglSecondaryColor3fv gglSecondaryColor3fvEXT{ nullptr };
	PgglSecondaryColor3i gglSecondaryColor3iEXT{ nullptr };
	PgglSecondaryColor3iv gglSecondaryColor3ivEXT{ nullptr };
	PgglSecondaryColor3s gglSecondaryColor3sEXT{ nullptr };
	PgglSecondaryColor3sv gglSecondaryColor3svEXT{ nullptr };
	PgglSecondaryColor3ub gglSecondaryColor3ubEXT{ nullptr };
	PgglSecondaryColor3ubv gglSecondaryColor3ubvEXT{ nullptr };
	PgglSecondaryColor3ui gglSecondaryColor3uiEXT{ nullptr };
	PgglSecondaryColor3uiv gglSecondaryColor3uivEXT{ nullptr };
	PgglSecondaryColor3us gglSecondaryColor3usEXT{ nullptr };
	PgglSecondaryColor3usv gglSecondaryColor3usvEXT{ nullptr };
	PgglSecondaryColorPointer gglSecondaryColorPointerEXT{ nullptr };
}

void System
	::GlSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3bEXT, red, green, blue);
}

void System
	::GlSecondaryColor3bvEXT(const GLbyte* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3bvEXT, rgb);
}

void System
	::GlSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3dEXT, red, green, blue);
}

void System
	::GlSecondaryColor3dvEXT(const GLdouble* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3dvEXT, rgb);
}

void System
	::GlSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3fEXT, red, green, blue);
}

void System
	::GlSecondaryColor3fvEXT(const GLfloat* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3fvEXT, rgb);
}

void System
	::GlSecondaryColor3iEXT(GLint red, GLint green, GLint blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3iEXT, red, green, blue);
}

void System
	::GlSecondaryColor3ivEXT(const GLint* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3ivEXT, rgb);
}

void System
	::GlSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3sEXT, red, green, blue);
}

void System
	::GlSecondaryColor3svEXT(const GLshort* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3svEXT, rgb);
}

void System
	::GlSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3ubEXT, red, green, blue);
}

void System
	::GlSecondaryColor3ubvEXT(const GLubyte* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3ubvEXT, rgb);
}

void System
	::GlSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3uiEXT, red, green, blue);
}

void System
	::GlSecondaryColor3uivEXT(const GLuint* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3uivEXT, rgb);
}

void System
	::GlSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue) noexcept
{
	SYSTEM_BODY_3(gglSecondaryColor3usEXT, red, green, blue);
}

void System
	::GlSecondaryColor3usvEXT(const GLushort* rgb) noexcept
{
	SYSTEM_BODY_1(gglSecondaryColor3usvEXT, rgb);
}

void System
	::GlSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_4(gglSecondaryColorPointerEXT, size, type, stride, pointer);
}

void System
	::InitGlExtSecondaryColor() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_secondary_color"))
	{
		g_ExistsGlExtSecondaryColor = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3b, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3bv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3d, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3dv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3f, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3fv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3i, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3iv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3s, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3sv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3ub, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3ubv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3ui, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3uiv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3us, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColor3usv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglSecondaryColorPointer, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtSecondaryColor = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 146) GL_EXT_texture_env

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureEnv{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureEnv() noexcept
{
	return g_ExistsGlExtTextureEnv;
}

void System
	::InitGlExtTextureEnv() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_env"))
	{
		g_ExistsGlExtTextureEnv = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureEnv = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 147) GL_EXT_texture_perturb_normal

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTexturePerturbNormal{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTexturePerturbNormal() noexcept
{
	return g_ExistsGlExtTexturePerturbNormal;
}

namespace System
{
	using PgglTextureNormalEXT = void (OPENGL_STDCALL*) (GLenum);
}

namespace System
{
	PgglTextureNormalEXT gglTextureNormalEXT{ nullptr };
}

void System
	::GlTextureNormalEXT(GLenum mode) noexcept
{
	SYSTEM_BODY_1(gglTextureNormalEXT, mode);
}

void System
	::InitGlExtTexturePerturbNormal() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_perturb_normal"))
	{
		g_ExistsGlExtTexturePerturbNormal = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTextureNormalEXT);
	}
	else
	{
		g_ExistsGlExtTexturePerturbNormal = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 148) GL_EXT_multi_draw_arrays

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtMultidrawArrays{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtMultidrawArrays() noexcept
{
	return g_ExistsGlExtMultidrawArrays;
}

namespace System
{
	PgglMultiDrawArrays gglMultiDrawArraysEXT{ nullptr };
	PgglMultiDrawElements gglMultiDrawElementsEXT{ nullptr };
}

void System
	::GlMultiDrawArraysEXT(GLenum mode, GLint* first, GLsizei* count, GLsizei primitiveCount) noexcept
{
	SYSTEM_BODY_4(gglMultiDrawArraysEXT, mode, first, count, primitiveCount);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlMultiDrawElementsEXT(GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primitiveCount) noexcept
{
	SYSTEM_BODY_5(gglMultiDrawElementsEXT, mode, count, type, indices, primitiveCount);
}
#include STSTEM_WARNING_POP

void System
	::InitGlExtMultidrawArrays() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_multi_draw_arrays"))
	{
		g_ExistsGlExtMultidrawArrays = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiDrawArrays, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglMultiDrawElements, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtMultidrawArrays = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 149) GL_EXT_fog_coord

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFogCoord{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFogCoord() noexcept
{
	return g_ExistsGlExtFogCoord;
}

namespace System
{
	PgglFogCoordf gglFogCoordfEXT{ nullptr };
	PgglFogCoordfv gglFogCoordfvEXT{ nullptr };
	PgglFogCoordd gglFogCoorddEXT{ nullptr };
	PgglFogCoorddv gglFogCoorddvEXT{ nullptr };
	PgglFogCoordPointer gglFogCoordPointerEXT{ nullptr };
}

void System
	::GlFogCoorddEXT(GLdouble coord) noexcept
{
	SYSTEM_BODY_1(gglFogCoorddEXT, coord);
}

void System
	::GlFogCoorddvEXT(const GLdouble* coord) noexcept
{
	SYSTEM_BODY_1(gglFogCoorddvEXT, coord);
}

void System
	::GlFogCoordfEXT(GLfloat coord) noexcept
{
	SYSTEM_BODY_1(gglFogCoordfEXT, coord);
}

void System
	::GlFogCoordfvEXT(const GLfloat* coord) noexcept
{
	SYSTEM_BODY_1(gglFogCoordfvEXT, coord);
}

void System
	::GlFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_3(gglFogCoordPointerEXT, type, stride, pointer);
}

void System
	::InitGlExtFogCoord() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_fog_coord"))
	{
		g_ExistsGlExtFogCoord = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglFogCoordf, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglFogCoordfv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglFogCoordd, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglFogCoorddv, EXT, g_SystemExtOverride);
		SYSTEM_GET_FUNCTION_SUFFIX(gglFogCoordPointer, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtFogCoord = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 156) GL_EXT_coordinate_frame

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtCoordinateFrame{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtCoordinateFrame() noexcept
{
	return g_ExistsGlExtCoordinateFrame;
}

namespace System
{
	using PgglTangent3bEXT = void (OPENGL_STDCALL*) (GLbyte, GLbyte, GLbyte);
	using PgglTangent3bvEXT = void (OPENGL_STDCALL*) (const GLbyte*);
	using PgglTangent3dEXT = void (OPENGL_STDCALL*) (GLdouble, GLdouble, GLdouble);
	using PgglTangent3dvEXT = void (OPENGL_STDCALL*) (const GLdouble*);
	using PgglTangent3fEXT = void (OPENGL_STDCALL*) (GLfloat, GLfloat, GLfloat);
	using PgglTangent3fvEXT = void (OPENGL_STDCALL*) (const GLfloat*);
	using PgglTangent3iEXT = void (OPENGL_STDCALL*) (GLint, GLint, GLint);
	using PgglTangent3ivEXT = void (OPENGL_STDCALL*) (const GLint*);
	using PgglTangent3sEXT = void (OPENGL_STDCALL*) (GLshort, GLshort, GLshort);
	using PgglTangent3svEXT = void (OPENGL_STDCALL*) (const GLshort*);
	using PgglBinormal3bEXT = void (OPENGL_STDCALL*) (GLbyte, GLbyte, GLbyte);
	using PgglBinormal3bvEXT = void (OPENGL_STDCALL*) (const GLbyte*);
	using PgglBinormal3dEXT = void (OPENGL_STDCALL*) (GLdouble, GLdouble, GLdouble);
	using PgglBinormal3dvEXT = void (OPENGL_STDCALL*) (const GLdouble*);
	using PgglBinormal3fEXT = void (OPENGL_STDCALL*) (GLfloat, GLfloat, GLfloat);
	using PgglBinormal3fvEXT = void (OPENGL_STDCALL*) (const GLfloat*);
	using PgglBinormal3iEXT = void (OPENGL_STDCALL*) (GLint, GLint, GLint);
	using PgglBinormal3ivEXT = void (OPENGL_STDCALL*) (const GLint*);
	using PgglBinormal3sEXT = void (OPENGL_STDCALL*) (GLshort, GLshort, GLshort);
	using PgglBinormal3svEXT = void (OPENGL_STDCALL*) (const GLshort*);
	using PgglTangentPointerEXT = void (OPENGL_STDCALL*) (GLenum, GLsizei, const GLvoid*);
	using PgglBinormalPointerEXT = void (OPENGL_STDCALL*) (GLenum, GLsizei, const GLvoid*);
}

namespace System
{
	PgglTangent3bEXT gglTangent3bEXT{ nullptr };
	PgglTangent3bvEXT gglTangent3bvEXT{ nullptr };
	PgglTangent3dEXT gglTangent3dEXT{ nullptr };
	PgglTangent3dvEXT gglTangent3dvEXT{ nullptr };
	PgglTangent3fEXT gglTangent3fEXT{ nullptr };
	PgglTangent3fvEXT gglTangent3fvEXT{ nullptr };
	PgglTangent3iEXT gglTangent3iEXT{ nullptr };
	PgglTangent3ivEXT gglTangent3ivEXT{ nullptr };
	PgglTangent3sEXT gglTangent3sEXT{ nullptr };
	PgglTangent3svEXT gglTangent3svEXT{ nullptr };
	PgglBinormal3bEXT gglBinormal3bEXT{ nullptr };
	PgglBinormal3bvEXT gglBinormal3bvEXT{ nullptr };
	PgglBinormal3dEXT gglBinormal3dEXT{ nullptr };
	PgglBinormal3dvEXT gglBinormal3dvEXT{ nullptr };
	PgglBinormal3fEXT gglBinormal3fEXT{ nullptr };
	PgglBinormal3fvEXT gglBinormal3fvEXT{ nullptr };
	PgglBinormal3iEXT gglBinormal3iEXT{ nullptr };
	PgglBinormal3ivEXT gglBinormal3ivEXT{ nullptr };
	PgglBinormal3sEXT gglBinormal3sEXT{ nullptr };
	PgglBinormal3svEXT gglBinormal3svEXT{ nullptr };
	PgglTangentPointerEXT gglTangentPointerEXT{ nullptr };
	PgglBinormalPointerEXT gglBinormalPointerEXT{ nullptr };
}

void System
	::GlTangent3bEXT(GLbyte x, GLbyte y, GLbyte z) noexcept
{
	SYSTEM_BODY_3(gglTangent3bEXT, x, y, z);
}

void System
	::GlTangent3bvEXT(const GLbyte* xyz) noexcept
{
	SYSTEM_BODY_1(gglTangent3bvEXT, xyz);
}

void System
	::GlTangent3dEXT(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_3(gglTangent3dEXT, x, y, z);
}

void System
	::GlTangent3dvEXT(const GLdouble* xyz) noexcept
{
	SYSTEM_BODY_1(gglTangent3dvEXT, xyz);
}

void System
	::GlTangent3fEXT(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_3(gglTangent3fEXT, x, y, z);
}

void System
	::GlTangent3fvEXT(const GLfloat* xyz) noexcept
{
	SYSTEM_BODY_1(gglTangent3fvEXT, xyz);
}

void System
	::GlTangent3iEXT(GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_BODY_3(gglTangent3iEXT, x, y, z);
}

void System
	::GlTangent3ivEXT(const GLint* xyz) noexcept
{
	SYSTEM_BODY_1(gglTangent3ivEXT, xyz);
}

void System
	::GlTangent3sEXT(GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_BODY_3(gglTangent3sEXT, x, y, z);
}

void System
	::GlTangent3svEXT(const GLshort* xyz) noexcept
{
	SYSTEM_BODY_1(gglTangent3svEXT, xyz);
}

void System
	::GlBinormal3bEXT(GLbyte x, GLbyte y, GLbyte z) noexcept
{
	SYSTEM_BODY_3(gglBinormal3bEXT, x, y, z);
}

void System
	::GlBinormal3bvEXT(const GLbyte* xyz) noexcept
{
	SYSTEM_BODY_1(gglBinormal3bvEXT, xyz);
}

void System
	::GlBinormal3dEXT(GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_3(gglBinormal3dEXT, x, y, z);
}

void System
	::GlBinormal3dvEXT(const GLdouble* xyz) noexcept
{
	SYSTEM_BODY_1(gglBinormal3dvEXT, xyz);
}

void System
	::GlBinormal3fEXT(GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_3(gglBinormal3fEXT, x, y, z);
}

void System
	::GlBinormal3fvEXT(const GLfloat* xyz) noexcept
{
	SYSTEM_BODY_1(gglBinormal3fvEXT, xyz);
}

void System
	::GlBinormal3iEXT(GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_BODY_3(gglBinormal3iEXT, x, y, z);
}

void System
	::GlBinormal3ivEXT(const GLint* xyz) noexcept
{
	SYSTEM_BODY_1(gglBinormal3ivEXT, xyz);
}

void System
	::GlBinormal3sEXT(GLshort x, GLshort y, GLshort z) noexcept
{
	SYSTEM_BODY_3(gglBinormal3sEXT, x, y, z);
}

void System
	::GlBinormal3svEXT(const GLshort* xyz) noexcept
{
	SYSTEM_BODY_1(gglBinormal3svEXT, xyz);
}

void System
	::GlTangentPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_3(gglTangentPointerEXT, type, stride, pointer);
}

void System
	::GlBinormalPointerEXT(GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_3(gglBinormalPointerEXT, type, stride, pointer);
}

void System
	::InitGlExtCoordinateFrame() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_coordinate_frame"))
	{
		g_ExistsGlExtCoordinateFrame = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTangent3bEXT);
		SYSTEM_GET_FUNCTION(gglTangent3bvEXT);
		SYSTEM_GET_FUNCTION(gglTangent3dEXT);
		SYSTEM_GET_FUNCTION(gglTangent3dvEXT);
		SYSTEM_GET_FUNCTION(gglTangent3fEXT);
		SYSTEM_GET_FUNCTION(gglTangent3fvEXT);
		SYSTEM_GET_FUNCTION(gglTangent3iEXT);
		SYSTEM_GET_FUNCTION(gglTangent3ivEXT);
		SYSTEM_GET_FUNCTION(gglTangent3sEXT);
		SYSTEM_GET_FUNCTION(gglTangent3svEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3bEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3bvEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3dEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3dvEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3fEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3fvEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3iEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3ivEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3sEXT);
		SYSTEM_GET_FUNCTION(gglBinormal3svEXT);
		SYSTEM_GET_FUNCTION(gglTangentPointerEXT);
		SYSTEM_GET_FUNCTION(gglBinormalPointerEXT);
	}
	else
	{
		g_ExistsGlExtCoordinateFrame = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 158) GL_EXT_texture_env_combine

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureEnvCombine{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureEnvCombine() noexcept
{
	return g_ExistsGlExtTextureEnvCombine;
}

void System
	::InitGlExtTextureEnvCombine() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_env_combine"))
	{
		g_ExistsGlExtTextureEnvCombine = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureEnvCombine = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 173) GL_EXT_blend_func_separate

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBlendFuncSeparate{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBlendFuncSeparate() noexcept
{
	return g_ExistsGlExtBlendFuncSeparate;
}

namespace System
{
	PgglBlendFuncSeparate gglBlendFuncSeparateEXT{ nullptr };
}

void System
	::GlBlendFuncSeparateEXT(GLenum srcFactorRGB, GLenum dstFactorRGB, GLenum srcFactorA, GLenum dstFactorA) noexcept
{
	SYSTEM_BODY_4(gglBlendFuncSeparateEXT, srcFactorRGB, dstFactorRGB, srcFactorA, dstFactorA);
}

void System
	::InitGlExtBlendFuncSeparate() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_blend_func_separate"))
	{
		g_ExistsGlExtBlendFuncSeparate = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendFuncSeparate, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtBlendFuncSeparate = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 176) GL_EXT_stencil_wrap

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtStencilWrap{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtStencilWrap() noexcept
{
	return g_ExistsGlExtStencilWrap;
}

void System
	::InitGlExtStencilWrap() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_stencil_wrap"))
	{
		g_ExistsGlExtStencilWrap = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtStencilWrap = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 178) GL_EXT_422_pixels

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExt422Pixels{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExt422Pixels() noexcept
{
	return g_ExistsGlExt422Pixels;
}

void System
	::InitGlExt422Pixels() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_422_pixels"))
	{
		g_ExistsGlExt422Pixels = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExt422Pixels = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 179) GL_EXT_texture_cube_map

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureCubeMap{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureCubeMap() noexcept
{
	return g_ExistsGlExtTextureCubeMap;
}

void System
	::InitGlExtTextureCubeMap() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_cube_map"))
	{
		g_ExistsGlExtTextureCubeMap = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureCubeMap = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 185) GL_EXT_texture_env_add

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureEnvAdd{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureEnvAdd() noexcept
{
	return g_ExistsGlExtTextureEnvAdd;
}

void System
	::InitGlExtTextureEnvAdd() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_env_add"))
	{
		g_ExistsGlExtTextureEnvAdd = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureEnvAdd = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 186) GL_EXT_texture_lod_bias

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureLodBias{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureLodBias() noexcept
{
	return g_ExistsGlExtTextureLodBias;
}

void System
	::InitGlExtTextureLodBias() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_lod_bias"))
	{
		g_ExistsGlExtTextureLodBias = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureLodBias = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 187) GL_EXT_texture_filter_anisotropic

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureFilterAnisotropic{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureFilterAnisotropic() noexcept
{
	return g_ExistsGlExtTextureFilterAnisotropic;
}

void System
	::InitGlExtTextureFilterAnisotropic() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_filter_anisotropic"))
	{
		g_ExistsGlExtTextureFilterAnisotropic = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureFilterAnisotropic = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 188) GL_EXT_vertex_weighting

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtVertexWeighting{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtVertexWeighting() noexcept
{
	return g_ExistsGlExtVertexWeighting;
}

namespace System
{
	using PgglVertexWeightfEXT = void (OPENGL_STDCALL*) (GLfloat);
	using PgglVertexWeightfvEXT = void (OPENGL_STDCALL*) (const GLfloat*);
	using PgglVertexWeightPointerEXT = void (OPENGL_STDCALL*) (GLsizei, GLenum, GLsizei, const GLvoid*);
}

namespace System
{
	PgglVertexWeightfEXT gglVertexWeightfEXT{ nullptr };
	PgglVertexWeightfvEXT gglVertexWeightfvEXT{ nullptr };
	PgglVertexWeightPointerEXT gglVertexWeightPointerEXT{ nullptr };
}

void System
	::GlVertexWeightfEXT(GLfloat weight) noexcept
{
	SYSTEM_BODY_1(gglVertexWeightfEXT, weight);
}

void System
	::GlVertexWeightfvEXT(const GLfloat* weight) noexcept
{
	SYSTEM_BODY_1(gglVertexWeightfvEXT, weight);
}

void System
	::GlVertexWeightPointerEXT(GLsizei size, GLenum type, GLsizei stride, const GLvoid* pointer) noexcept
{
	SYSTEM_BODY_4(gglVertexWeightPointerEXT, size, type, stride, pointer);
}

void System
	::InitGlExtVertexWeighting() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_vertex_weighting"))
	{
		g_ExistsGlExtVertexWeighting = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglVertexWeightfEXT);
		SYSTEM_GET_FUNCTION(gglVertexWeightfvEXT);
		SYSTEM_GET_FUNCTION(gglVertexWeightPointerEXT);
	}
	else
	{
		g_ExistsGlExtVertexWeighting = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 198) GL_EXT_texture_compression_s3tc

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureCompressionS3TC{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureCompressionS3TC() noexcept
{
	return g_ExistsGlExtTextureCompressionS3TC;
}

void System
	::InitGlExtTextureCompressionS3TC() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_compression_s3tc"))
	{
		g_ExistsGlExtTextureCompressionS3TC = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureCompressionS3TC = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 209) GL_EXT_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtMultisample() noexcept
{
	return g_ExistsGlExtMultisample;
}

namespace System
{
	using PgglSampleMaskEXT = void (OPENGL_STDCALL*) (GLclampf, GLboolean);
	using PgglSamplePatternEXT = void (OPENGL_STDCALL*) (GLenum);
}

namespace System
{
	PgglSampleMaskEXT gglSampleMaskEXT{ nullptr };
	PgglSamplePatternEXT gglSamplePatternEXT{ nullptr };
}

void System
	::GlSampleMaskEXT(GLclampf value, GLboolean invert) noexcept
{
	SYSTEM_BODY_2(gglSampleMaskEXT, value, invert);
}

void System
	::GlSamplePatternEXT(GLenum pattern) noexcept
{
	SYSTEM_BODY_1(gglSamplePatternEXT, pattern);
}

void System
	::InitGlExtMultisample() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_multisample"))
	{
		g_ExistsGlExtMultisample = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglSampleMaskEXT);
		SYSTEM_GET_FUNCTION(gglSamplePatternEXT);
	}
	else
	{
		g_ExistsGlExtMultisample = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 220) GL_EXT_texture_env_dot3

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureEnvDot3{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureEnvDot3() noexcept
{
	return g_ExistsGlExtTextureEnvDot3;
}

void System
	::InitGlExtTextureEnvDot3() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_env_dot3"))
	{
		g_ExistsGlExtTextureEnvDot3 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureEnvDot3 = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 229) GL_EXT_texture_rectangle

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureRectangle{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureRectangle() noexcept
{
	return g_ExistsGlExtTextureRectangle;
}

void System
	::InitGlExtTextureRectangle() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_rectangle"))
	{
		g_ExistsGlExtTextureRectangle = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureRectangle = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 248) GL_EXT_vertex_shader

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtVertexShader{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtVertexShader() noexcept
{
	return g_ExistsGlExtVertexShader;
}

namespace System
{
	using PgglBeginVertexShaderEXT = void (OPENGL_STDCALL*)(void);
	using PgglBindLightParameterEXT = GLuint(OPENGL_STDCALL*)(GLenum light, GLenum value);
	using PgglBindMaterialParameterEXT = GLuint(OPENGL_STDCALL*) (GLenum face, GLenum value);
	using PgglBindParameterEXT = GLuint(OPENGL_STDCALL*) (GLenum value);
	using PgglBindTexGenParameterEXT = GLuint(OPENGL_STDCALL*) (GLenum unit, GLenum coord, GLenum value);
	using PgglBindTextureUnitParameterEXT = GLuint(OPENGL_STDCALL*) (GLenum unit, GLenum value);
	using PgglBindVertexShaderEXT = void (OPENGL_STDCALL*) (GLuint id);
	using PgglDeleteVertexShaderEXT = void (OPENGL_STDCALL*) (GLuint id);
	using PgglDisableVariantClientStateEXT = void (OPENGL_STDCALL*) (GLuint id);
	using PgglEnableVariantClientStateEXT = void (OPENGL_STDCALL*) (GLuint id);
	using PgglEndVertexShaderEXT = void (OPENGL_STDCALL*) (void);
	using PgglExtractComponentEXT = void (OPENGL_STDCALL*) (GLuint res, GLuint src, GLuint num);
	using PgglGenSymbolsEXT = GLuint(OPENGL_STDCALL*) (GLenum dataType, GLenum storageType, GLenum range, GLuint components);
	using PgglGenVertexShadersEXT = GLuint(OPENGL_STDCALL*) (GLuint range);
	using PgglGetInvariantBooleanvEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLboolean *data);
	using PgglGetInvariantFloatvEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLfloat* data);
	using PgglGetInvariantIntegervEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLint* data);
	using PgglGetLocalConstantBooleanvEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLboolean* data);
	using PgglGetLocalConstantFloatvEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLfloat* data);
	using PgglGetLocalConstantIntegervEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLint* data);
	using PgglGetVariantBooleanvEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLboolean* data);
	using PgglGetVariantFloatvEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLfloat* data);
	using PgglGetVariantIntegervEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, GLint* data);
	using PgglGetVariantPointervEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum value, void** data);
	using PgglInsertComponentEXT = void (OPENGL_STDCALL*) (GLuint res, GLuint src, GLuint num);
	using PgglIsVariantEnabledEXT = GLboolean(OPENGL_STDCALL*) (GLuint id, GLenum cap);
	using PgglSetInvariantEXT = void (OPENGL_STDCALL*)(GLuint id, GLenum type, void* addr);
	using PgglSetLocalConstantEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum type, void* addr);
	using PgglShaderOp1EXT = void (OPENGL_STDCALL*) (GLenum op, GLuint res, GLuint arg1);
	using PgglShaderOp2EXT = void (OPENGL_STDCALL*) (GLenum op, GLuint res, GLuint arg1, GLuint arg2);
	using PgglShaderOp3EXT = void (OPENGL_STDCALL*) (GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
	using PgglSwizzleEXT = void (OPENGL_STDCALL*) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
	using PgglVariantPointerEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum type, GLuint stride, void* addr);
	using PgglVariantbvEXT = void (OPENGL_STDCALL*) (GLuint id, GLbyte* addr);
	using PgglVariantdvEXT = void (OPENGL_STDCALL*) (GLuint id, GLdouble* addr);
	using PgglVariantfvEXT = void (OPENGL_STDCALL*) (GLuint id, GLfloat* addr);
	using PgglVariantivEXT = void (OPENGL_STDCALL*) (GLuint id, GLint* addr);
	using PgglVariantsvEXT = void (OPENGL_STDCALL*) (GLuint id, GLshort* addr);
	using PgglVariantubvEXT = void (OPENGL_STDCALL*) (GLuint id, GLubyte* addr);
	using PgglVariantuivEXT = void (OPENGL_STDCALL*) (GLuint id, GLuint* addr);
	using PgglVariantusvEXT = void (OPENGL_STDCALL*) (GLuint id, GLushort* addr);
	using PgglWriteMaskEXT = void (OPENGL_STDCALL*) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
}

namespace System
{
	PgglBeginVertexShaderEXT gglBeginVertexShaderEXT{ nullptr };
	PgglBindLightParameterEXT gglBindLightParameterEXT{ nullptr };
	PgglBindMaterialParameterEXT gglBindMaterialParameterEXT{ nullptr };
	PgglBindParameterEXT gglBindParameterEXT{ nullptr };
	PgglBindTexGenParameterEXT gglBindTexGenParameterEXT{ nullptr };
	PgglBindTextureUnitParameterEXT gglBindTextureUnitParameterEXT{ nullptr };
	PgglBindVertexShaderEXT gglBindVertexShaderEXT{ nullptr };
	PgglDeleteVertexShaderEXT gglDeleteVertexShaderEXT{ nullptr };
	PgglDisableVariantClientStateEXT gglDisableVariantClientStateEXT{ nullptr };
	PgglEnableVariantClientStateEXT gglEnableVariantClientStateEXT{ nullptr };
	PgglEndVertexShaderEXT gglEndVertexShaderEXT{ nullptr };
	PgglExtractComponentEXT gglExtractComponentEXT{ nullptr };
	PgglGenSymbolsEXT gglGenSymbolsEXT{ nullptr };
	PgglGenVertexShadersEXT gglGenVertexShadersEXT{ nullptr };
	PgglGetInvariantBooleanvEXT gglGetInvariantBooleanvEXT{ nullptr };
	PgglGetInvariantFloatvEXT gglGetInvariantFloatvEXT{ nullptr };
	PgglGetInvariantIntegervEXT gglGetInvariantIntegervEXT{ nullptr };
	PgglGetLocalConstantBooleanvEXT gglGetLocalConstantBooleanvEXT{ nullptr };
	PgglGetLocalConstantFloatvEXT gglGetLocalConstantFloatvEXT{ nullptr };
	PgglGetLocalConstantIntegervEXT gglGetLocalConstantIntegervEXT{ nullptr };
	PgglGetVariantBooleanvEXT gglGetVariantBooleanvEXT{ nullptr };
	PgglGetVariantFloatvEXT gglGetVariantFloatvEXT{ nullptr };
	PgglGetVariantIntegervEXT gglGetVariantIntegervEXT{ nullptr };
	PgglGetVariantPointervEXT gglGetVariantPointervEXT{ nullptr };
	PgglInsertComponentEXT gglInsertComponentEXT{ nullptr };
	PgglIsVariantEnabledEXT gglIsVariantEnabledEXT{ nullptr };
	PgglSetInvariantEXT gglSetInvariantEXT{ nullptr };
	PgglSetLocalConstantEXT gglSetLocalConstantEXT{ nullptr };
	PgglShaderOp1EXT gglShaderOp1EXT{ nullptr };
	PgglShaderOp2EXT gglShaderOp2EXT{ nullptr };
	PgglShaderOp3EXT gglShaderOp3EXT{ nullptr };
	PgglSwizzleEXT gglSwizzleEXT{ nullptr };
	PgglVariantPointerEXT gglVariantPointerEXT{ nullptr };
	PgglVariantbvEXT gglVariantbvEXT{ nullptr };
	PgglVariantdvEXT gglVariantdvEXT{ nullptr };
	PgglVariantfvEXT gglVariantfvEXT{ nullptr };
	PgglVariantivEXT gglVariantivEXT{ nullptr };
	PgglVariantsvEXT gglVariantsvEXT{ nullptr };
	PgglVariantubvEXT gglVariantubvEXT{ nullptr };
	PgglVariantuivEXT gglVariantuivEXT{ nullptr };
	PgglVariantusvEXT gglVariantusvEXT{ nullptr };
	PgglWriteMaskEXT gglWriteMaskEXT{ nullptr };
}

void System
	::GlBeginVertexShaderEXT(void) noexcept
{
	SYSTEM_BODY_0(gglBeginVertexShaderEXT);
}

GLuint System
	::GlBindLightParameterEXT(GLenum light, GLenum value) noexcept
{
	SYSTEM_BODY_2_RESULT(gglBindLightParameterEXT, light, value, GLuint, 0);
}

GLuint System
	::GlBindMaterialParameterEXT(GLenum face, GLenum value) noexcept
{
	SYSTEM_BODY_2_RESULT(gglBindMaterialParameterEXT, face, value, GLuint, 0);
}

GLuint System
	::GlBindParameterEXT(GLenum value) noexcept
{
	SYSTEM_BODY_1_RESULT(gglBindParameterEXT, value, GLuint, 0);
}

GLuint System
	::GlBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value) noexcept
{
	SYSTEM_BODY_3_RESULT(gglBindTexGenParameterEXT, unit, coord, value, GLuint, 0);
}

GLuint System
	::GlBindTextureUnitParameterEXT(GLenum unit, GLenum value) noexcept
{
	SYSTEM_BODY_2_RESULT(gglBindTextureUnitParameterEXT, unit, value, GLuint, 0);
}

void System
	::GlBindVertexShaderEXT(GLuint id) noexcept
{
	SYSTEM_BODY_1(gglBindVertexShaderEXT, id);
}

void System
	::GlDeleteVertexShaderEXT(GLuint id) noexcept
{
	SYSTEM_BODY_1(gglDeleteVertexShaderEXT, id);
}

void System
	::GlDisableVariantClientStateEXT(GLuint id) noexcept
{
	SYSTEM_BODY_1(gglDisableVariantClientStateEXT, id);
}

void System
	::GlEnableVariantClientStateEXT(GLuint id) noexcept
{
	SYSTEM_BODY_1(gglEnableVariantClientStateEXT, id);
}

void System
	::GlEndVertexShaderEXT(void) noexcept
{
	SYSTEM_BODY_0(gglEndVertexShaderEXT);
}

void System
	::GlExtractComponentEXT(GLuint res, GLuint src, GLuint num) noexcept
{
	SYSTEM_BODY_3(gglExtractComponentEXT, res, src, num);
}

GLuint System
	::GlGenSymbolsEXT(GLenum dataType, GLenum storageType, GLenum range, GLuint components) noexcept
{
	SYSTEM_BODY_4_RESULT(gglGenSymbolsEXT, dataType, storageType, range, components, GLuint, 0);
}

GLuint System
	::GlGenVertexShadersEXT(GLuint range) noexcept
{
	SYSTEM_BODY_1_RESULT(gglGenVertexShadersEXT, range, GLuint, 0);
}

void System
	::GlGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) noexcept
{
	SYSTEM_BODY_3(gglGetInvariantBooleanvEXT, id, value, data);
}

void System
	::GlGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat* data) noexcept
{
	SYSTEM_BODY_3(gglGetInvariantFloatvEXT, id, value, data);
}

void System
	::GlGetInvariantIntegervEXT(GLuint id, GLenum value, GLint* data) noexcept
{
	SYSTEM_BODY_3(gglGetInvariantIntegervEXT, id, value, data);
}

void System
	::GlGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) noexcept
{
	SYSTEM_BODY_3(gglGetLocalConstantBooleanvEXT, id, value, data);
}

void System
	::GlGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat* data) noexcept
{
	SYSTEM_BODY_3(gglGetLocalConstantFloatvEXT, id, value, data);
}

void System
	::GlGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint* data) noexcept
{
	SYSTEM_BODY_3(gglGetLocalConstantIntegervEXT, id, value, data);
}

void System
	::GlGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean* data) noexcept
{
	SYSTEM_BODY_3(gglGetVariantBooleanvEXT, id, value, data);
}

void System
	::GlGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat* data) noexcept
{
	SYSTEM_BODY_3(gglGetVariantFloatvEXT, id, value, data);
}

void System
	::GlGetVariantIntegervEXT(GLuint id, GLenum value, GLint* data) noexcept
{
	SYSTEM_BODY_3(gglGetVariantIntegervEXT, id, value, data);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetVariantPointervEXT(GLuint id, GLenum value, void** data) noexcept
{
	SYSTEM_BODY_3(gglGetVariantPointervEXT, id, value, data);
}
#include STSTEM_WARNING_POP

void System
	::GlInsertComponentEXT(GLuint res, GLuint src, GLuint num) noexcept
{
	SYSTEM_BODY_3(gglInsertComponentEXT, res, src, num);
}

GLboolean System
	::GlIsVariantEnabledEXT(GLuint id, GLenum cap) noexcept
{
	SYSTEM_BODY_2_RESULT(gglIsVariantEnabledEXT, id, cap, GLboolean, GL_FALSE);
}

void System
	::GlSetInvariantEXT(GLuint id, GLenum type, void* addr) noexcept
{
	SYSTEM_BODY_3(gglSetInvariantEXT, id, type, addr);
}

void System
	::GlSetLocalConstantEXT(GLuint id, GLenum type, void* addr) noexcept
{
	SYSTEM_BODY_3(gglSetLocalConstantEXT, id, type, addr);
}

void System
	::GlShaderOp1EXT(GLenum op, GLuint res, GLuint arg1) noexcept
{
	SYSTEM_BODY_3(gglShaderOp1EXT, op, res, arg1);
}

void System
	::GlShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2) noexcept
{
	SYSTEM_BODY_4(gglShaderOp2EXT, op, res, arg1, arg2);
}

void System
	::GlShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) noexcept
{
	SYSTEM_BODY_5(gglShaderOp3EXT, op, res, arg1, arg2, arg3);
}

void System
	::GlSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) noexcept
{
	SYSTEM_BODY_6(gglSwizzleEXT, res, in, outX, outY, outZ, outW);
}

void System
	::GlVariantPointerEXT(GLuint id, GLenum type, GLuint stride, void* addr) noexcept
{
	SYSTEM_BODY_4(gglVariantPointerEXT, id, type, stride, addr);
}

void System
	::GlVariantbvEXT(GLuint id, GLbyte* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantbvEXT, id, addr);
}

void System
	::GlVariantdvEXT(GLuint id, GLdouble* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantdvEXT, id, addr);
}

void System
	::GlVariantfvEXT(GLuint id, GLfloat* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantfvEXT, id, addr);
}

void System
	::GlVariantivEXT(GLuint id, GLint* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantivEXT, id, addr);
}

void System
	::GlVariantsvEXT(GLuint id, GLshort* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantsvEXT, id, addr);
}

void System
	::GlVariantubvEXT(GLuint id, GLubyte* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantubvEXT, id, addr);
}

void System
	::GlVariantuivEXT(GLuint id, GLuint* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantuivEXT, id, addr);
}

void System
	::GlVariantusvEXT(GLuint id, GLushort* addr) noexcept
{
	SYSTEM_BODY_2(gglVariantusvEXT, id, addr);
}

void System
	::GlWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) noexcept
{
	SYSTEM_BODY_6(gglWriteMaskEXT, res, in, outX, outY, outZ, outW);
}

void System
	::InitGlExtVertexShader() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_vertex_shader"))
	{
		g_ExistsGlExtVertexShader = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBeginVertexShaderEXT);
		SYSTEM_GET_FUNCTION(gglBindLightParameterEXT);
		SYSTEM_GET_FUNCTION(gglBindMaterialParameterEXT);
		SYSTEM_GET_FUNCTION(gglBindParameterEXT);
		SYSTEM_GET_FUNCTION(gglBindTexGenParameterEXT);
		SYSTEM_GET_FUNCTION(gglBindTextureUnitParameterEXT);
		SYSTEM_GET_FUNCTION(gglBindVertexShaderEXT);
		SYSTEM_GET_FUNCTION(gglDeleteVertexShaderEXT);
		SYSTEM_GET_FUNCTION(gglDisableVariantClientStateEXT);
		SYSTEM_GET_FUNCTION(gglEnableVariantClientStateEXT);
		SYSTEM_GET_FUNCTION(gglEndVertexShaderEXT);
		SYSTEM_GET_FUNCTION(gglExtractComponentEXT);
		SYSTEM_GET_FUNCTION(gglGenSymbolsEXT);
		SYSTEM_GET_FUNCTION(gglGenVertexShadersEXT);
		SYSTEM_GET_FUNCTION(gglGetInvariantBooleanvEXT);
		SYSTEM_GET_FUNCTION(gglGetInvariantFloatvEXT);
		SYSTEM_GET_FUNCTION(gglGetInvariantIntegervEXT);
		SYSTEM_GET_FUNCTION(gglGetLocalConstantBooleanvEXT);
		SYSTEM_GET_FUNCTION(gglGetLocalConstantFloatvEXT);
		SYSTEM_GET_FUNCTION(gglGetLocalConstantIntegervEXT);
		SYSTEM_GET_FUNCTION(gglGetVariantBooleanvEXT);
		SYSTEM_GET_FUNCTION(gglGetVariantFloatvEXT);
		SYSTEM_GET_FUNCTION(gglGetVariantIntegervEXT);
		SYSTEM_GET_FUNCTION(gglGetVariantPointervEXT);
		SYSTEM_GET_FUNCTION(gglInsertComponentEXT);
		SYSTEM_GET_FUNCTION(gglIsVariantEnabledEXT);
		SYSTEM_GET_FUNCTION(gglSetInvariantEXT);
		SYSTEM_GET_FUNCTION(gglSetLocalConstantEXT);
		SYSTEM_GET_FUNCTION(gglShaderOp1EXT);
		SYSTEM_GET_FUNCTION(gglShaderOp2EXT);
		SYSTEM_GET_FUNCTION(gglShaderOp3EXT);
		SYSTEM_GET_FUNCTION(gglSwizzleEXT);
		SYSTEM_GET_FUNCTION(gglVariantPointerEXT);
		SYSTEM_GET_FUNCTION(gglVariantbvEXT);
		SYSTEM_GET_FUNCTION(gglVariantdvEXT);
		SYSTEM_GET_FUNCTION(gglVariantfvEXT);
		SYSTEM_GET_FUNCTION(gglVariantivEXT);
		SYSTEM_GET_FUNCTION(gglVariantsvEXT);
		SYSTEM_GET_FUNCTION(gglVariantubvEXT);
		SYSTEM_GET_FUNCTION(gglVariantuivEXT);
		SYSTEM_GET_FUNCTION(gglVariantusvEXT);
		SYSTEM_GET_FUNCTION(gglWriteMaskEXT);
	}
	else
	{
		g_ExistsGlExtVertexShader = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 267) GL_EXT_shadow_funcs

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtShadowFuncs{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtShadowFuncs() noexcept
{
	return g_ExistsGlExtShadowFuncs;
}

void System
	::InitGlExtShadowFuncs() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_shadow_funcs"))
	{
		g_ExistsGlExtShadowFuncs = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtShadowFuncs = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 268) GL_EXT_stencil_two_side

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtStencilTwoSide{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtStencilTwoSide() noexcept
{
	return g_ExistsGlExtStencilTwoSide;
}

namespace System
{
	using PgglActiveStencilFaceEXT = void (OPENGL_STDCALL*) (GLenum);
}

namespace System
{
	PgglActiveStencilFaceEXT gglActiveStencilFaceEXT{ nullptr };
}

void System
	::GlActiveStencilFaceEXT(GLenum face) noexcept
{
	SYSTEM_BODY_1(gglActiveStencilFaceEXT, face);
}

void System
	::InitGlExtStencilTwoSide() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_stencil_two_side"))
	{
		g_ExistsGlExtStencilTwoSide = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglActiveStencilFaceEXT);
	}
	else
	{
		g_ExistsGlExtStencilTwoSide = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 297) GL_EXT_depth_bounds_test

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDepthBoundsTest{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDepthBoundsTest() noexcept
{
	return g_ExistsGlExtDepthBoundsTest;
}

namespace System
{
	using PgglDepthBoundsEXT = void (OPENGL_STDCALL*) (GLclampd, GLclampd);
}

namespace System
{
	PgglDepthBoundsEXT gglDepthBoundsEXT{ nullptr };
}

void System
	::GlDepthBoundsEXT(GLclampd min, GLclampd max) noexcept
{
	SYSTEM_BODY_2(gglDepthBoundsEXT, min, max);
}

void System
	::InitGlExtDepthBoundsTest() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_depth_bounds_test"))
	{
		g_ExistsGlExtDepthBoundsTest = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDepthBoundsEXT);
	}
	else
	{
		g_ExistsGlExtDepthBoundsTest = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 298) GL_EXT_texture_mirror_clamp

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureMirrorClamp{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureMirrorClamp() noexcept
{
	return g_ExistsGlExtTextureMirrorClamp;
}

void System
	::InitGlExtTextureMirrorClamp() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_mirror_clamp"))
	{
		g_ExistsGlExtTextureMirrorClamp = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureMirrorClamp = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 299) GL_EXT_blend_equation_separate

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBlendEquationSeparate{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBlendEquationSeparate() noexcept
{
	return g_ExistsGlExtBlendEquationSeparate;
}

namespace System
{
	PgglBlendEquationSeparate gglBlendEquationSeparateEXT{ nullptr };
}

void System
	::GlBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) noexcept
{
	SYSTEM_BODY_2(gglBlendEquationSeparateEXT, modeRGB, modeAlpha);
}

void System
	::InitGlExtBlendEquationSeparate() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_blend_equation_separate"))
	{
		g_ExistsGlExtBlendEquationSeparate = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION_SUFFIX(gglBlendEquationSeparate, EXT, g_SystemExtOverride);
	}
	else
	{
		g_ExistsGlExtBlendEquationSeparate = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 302) GL_EXT_pixel_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPixelBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPixelBufferObject() noexcept
{
	return g_ExistsGlExtPixelBufferObject;
}

void System
	::InitGlExtPixelBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_pixel_buffer_object"))
	{
		g_ExistsGlExtPixelBufferObject = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtPixelBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 309) GL_EXT_texture_compression_dxt1

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureCompressionDXT1{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureCompressionDXT1() noexcept
{
	return g_ExistsGlExtTextureCompressionDXT1;
}

void System
	::InitGlExtTextureCompressionDXT1() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_compression_dxt1"))
	{
		g_ExistsGlExtTextureCompressionDXT1 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureCompressionDXT1 = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 310) GL_EXT_framebuffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFrameBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFrameBufferObject() noexcept
{
	return g_ExistsGlExtFrameBufferObject;
}

namespace System
{
	using PgglIsRenderbufferEXT = GLboolean(OPENGL_STDCALL*) (GLuint);
	using PgglBindRenderbufferEXT = void (OPENGL_STDCALL*) (GLenum, GLuint);
	using PgglDeleteRenderbuffersEXT = void (OPENGL_STDCALL*) (GLsizei, const GLuint*);
	using PgglGenRenderbuffersEXT = void (OPENGL_STDCALL*) (GLsizei, GLuint*);
	using PgglRenderbufferStorageEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLsizei, GLsizei);
	using PgglGetRenderbufferParameterivEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLint*);
	using PgglIsFramebufferEXT = GLboolean(OPENGL_STDCALL*) (GLuint);
	using PgglBindFramebufferEXT = void (OPENGL_STDCALL*) (GLenum, GLuint);
	using PgglDeleteFramebuffersEXT = void (OPENGL_STDCALL*) (GLsizei, const GLuint*);
	using PgglGenFramebuffersEXT = void (OPENGL_STDCALL*) (GLsizei, GLuint*);
	using PgglCheckFramebufferStatusEXT = GLenum(OPENGL_STDCALL*) (GLenum);
	using PgglFramebufferTexture1DEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLuint, GLint);
	using PgglFramebufferTexture2DEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLuint, GLint);
	using PgglFramebufferTexture3DEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLuint, GLint, GLint);
	using PgglFramebufferRenderbufferEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLuint);
	using PgglGetFramebufferAttachmentParameterivEXT = void (OPENGL_STDCALL*) (GLenum, GLenum, GLenum, GLint*);
	using PgglGenerateMipmapEXT = void (OPENGL_STDCALL*) (GLenum);
}

namespace System
{
	PgglIsRenderbufferEXT gglIsRenderbufferEXT{ nullptr };
	PgglBindRenderbufferEXT gglBindRenderbufferEXT{ nullptr };
	PgglDeleteRenderbuffersEXT gglDeleteRenderbuffersEXT{ nullptr };
	PgglGenRenderbuffersEXT gglGenRenderbuffersEXT{ nullptr };
	PgglRenderbufferStorageEXT gglRenderbufferStorageEXT{ nullptr };
	PgglGetRenderbufferParameterivEXT gglGetRenderbufferParameterivEXT{ nullptr };
	PgglIsFramebufferEXT gglIsFramebufferEXT{ nullptr };
	PgglBindFramebufferEXT gglBindFramebufferEXT{ nullptr };
	PgglDeleteFramebuffersEXT gglDeleteFramebuffersEXT{ nullptr };
	PgglGenFramebuffersEXT gglGenFramebuffersEXT{ nullptr };
	PgglCheckFramebufferStatusEXT gglCheckFramebufferStatusEXT{ nullptr };
	PgglFramebufferTexture1DEXT gglFramebufferTexture1DEXT{ nullptr };
	PgglFramebufferTexture2DEXT gglFramebufferTexture2DEXT{ nullptr };
	PgglFramebufferTexture3DEXT gglFramebufferTexture3DEXT{ nullptr };
	PgglFramebufferRenderbufferEXT gglFramebufferRenderbufferEXT{ nullptr };
	PgglGetFramebufferAttachmentParameterivEXT gglGetFramebufferAttachmentParameterivEXT{ nullptr };
	PgglGenerateMipmapEXT gglGenerateMipmapEXT{ nullptr };
}

GLboolean System
	::GlIsRenderbufferEXT(GLuint renderBuffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsRenderbufferEXT, renderBuffer, GLboolean, GL_FALSE);
}

void System
	::GlBindRenderbufferEXT(GLenum target, GLuint renderBuffer) noexcept
{
	SYSTEM_BODY_2(gglBindRenderbufferEXT, target, renderBuffer);
}

void System
	::GlDeleteRenderbuffersEXT(GLsizei numBuffers, const GLuint* renderBuffer) noexcept
{
	SYSTEM_BODY_2(gglDeleteRenderbuffersEXT, numBuffers, renderBuffer);
}

void System
	::GlGenRenderbuffersEXT(GLsizei numBuffers, GLuint* renderBuffer) noexcept
{
	SYSTEM_BODY_2(gglGenRenderbuffersEXT, numBuffers, renderBuffer);
}

void System
	::GlRenderbufferStorageEXT(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_4(gglRenderbufferStorageEXT, target, internalFormat, width, height);
}

void System
	::GlGetRenderbufferParameterivEXT(GLenum target, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetRenderbufferParameterivEXT, target, name, param);
}

GLboolean System
	::GlIsFramebufferEXT(GLuint frameBuffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglIsFramebufferEXT, frameBuffer, GLboolean, GL_FALSE);
}

void System
	::GlBindFramebufferEXT(GLenum target, GLuint frameBuffer) noexcept
{
	SYSTEM_BODY_2(gglBindFramebufferEXT, target, frameBuffer);
}

void System
	::GlDeleteFramebuffersEXT(GLsizei numBuffers, const GLuint* frameBuffer) noexcept
{
	SYSTEM_BODY_2(gglDeleteFramebuffersEXT, numBuffers, frameBuffer);
}

void System
	::GlGenFramebuffersEXT(GLsizei numBuffers, GLuint* frameBuffer) noexcept
{
	SYSTEM_BODY_2(gglGenFramebuffersEXT, numBuffers, frameBuffer);
}

GLenum System
	::GlCheckFramebufferStatusEXT(GLenum target) noexcept
{
	SYSTEM_BODY_1_RESULT(gglCheckFramebufferStatusEXT, target, GLenum, GL_FRAMEBUFFER_UNSUPPORTED_EXT);
}

void System
	::GlFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textureTarget, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTexture1DEXT, target, attachment, textureTarget, texture, level);
}

void System
	::GlFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textureTarget, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTexture2DEXT, target, attachment, textureTarget, texture, level);
}

void System
	::GlFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textureTarget, GLuint texture, GLint level, GLint zOffset) noexcept
{
	SYSTEM_BODY_6(gglFramebufferTexture3DEXT, target, attachment, textureTarget, texture, level, zOffset);
}

void System
	::GlFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderBufferTarget, GLuint renderBuffer) noexcept
{
	SYSTEM_BODY_4(gglFramebufferRenderbufferEXT, target, attachment, renderBufferTarget, renderBuffer);
}

void System
	::GlGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum name, GLint* param) noexcept
{
	SYSTEM_BODY_4(gglGetFramebufferAttachmentParameterivEXT, target, attachment, name, param);
}

void System
	::GlGenerateMipmapEXT(GLenum target) noexcept
{
	SYSTEM_BODY_1(gglGenerateMipmapEXT, target);
}

void System
	::InitGlExtFrameBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_framebuffer_object"))
	{
		g_ExistsGlExtFrameBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglIsRenderbufferEXT);
		SYSTEM_GET_FUNCTION(gglBindRenderbufferEXT);
		SYSTEM_GET_FUNCTION(gglDeleteRenderbuffersEXT);
		SYSTEM_GET_FUNCTION(gglGenRenderbuffersEXT);
		SYSTEM_GET_FUNCTION(gglRenderbufferStorageEXT);
		SYSTEM_GET_FUNCTION(gglGetRenderbufferParameterivEXT);
		SYSTEM_GET_FUNCTION(gglIsFramebufferEXT);
		SYSTEM_GET_FUNCTION(gglBindFramebufferEXT);
		SYSTEM_GET_FUNCTION(gglDeleteFramebuffersEXT);
		SYSTEM_GET_FUNCTION(gglGenFramebuffersEXT);
		SYSTEM_GET_FUNCTION(gglCheckFramebufferStatusEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture1DEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture2DEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture3DEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferRenderbufferEXT);
		SYSTEM_GET_FUNCTION(gglGetFramebufferAttachmentParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGenerateMipmapEXT);
	}
	else
	{
		g_ExistsGlExtFrameBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 312) GL_EXT_packed_depth_stencil

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPackedDepthStencil{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPackedDepthStencil() noexcept
{
	return g_ExistsGlExtPackedDepthStencil;
}

void System
	::InitGlExtPackedDepthStencil() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_packed_depth_stencil"))
	{
		g_ExistsGlExtPackedDepthStencil = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtPackedDepthStencil = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 314) GL_EXT_stencil_clear_tag

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtStencilClearTag{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtStencilClearTag() noexcept
{
	return g_ExistsGlExtStencilClearTag;
}

namespace System
{
	using PgglStencilClearTagEXT = void (OPENGL_STDCALL*) (GLsizei, GLuint);
}

namespace System
{
	PgglStencilClearTagEXT gglStencilClearTagEXT{ nullptr };
}

void System
	::GlStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag) noexcept
{
	SYSTEM_BODY_2(gglStencilClearTagEXT, stencilTagBits, stencilClearTag);
}

void System
	::InitGlExtStencilClearTag() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_stencil_clear_tag"))
	{
		g_ExistsGlExtStencilClearTag = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglStencilClearTagEXT);
	}
	else
	{
		g_ExistsGlExtStencilClearTag = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 315) GL_EXT_texture_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureSRGB() noexcept
{
	return g_ExistsGlExtTextureSRGB;
}

void System
	::InitGlExtTextureSRGB() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_sRGB"))
	{
		g_ExistsGlExtTextureSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureSRGB = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 316) GL_EXT_framebuffer_blit

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFrameBufferBlit{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFrameBufferBlit() noexcept
{
	return g_ExistsGlExtFrameBufferBlit;
}

namespace System
{
	using PgglBlitFramebufferEXT = void (OPENGL_STDCALL*) (GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
}

namespace System
{
	PgglBlitFramebufferEXT gglBlitFramebufferEXT{ nullptr };
}

void System
	::GlBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
	SYSTEM_BODY_10(gglBlitFramebufferEXT, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void System
	::InitGlExtFrameBufferBlit() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_framebuffer_blit"))
	{
		g_ExistsGlExtFrameBufferBlit = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBlitFramebufferEXT);
	}
	else
	{
		g_ExistsGlExtFrameBufferBlit = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 317) GL_EXT_framebuffer_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFrameBufferMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFrameBufferMultisample() noexcept
{
	return g_ExistsGlExtFrameBufferMultisample;
}

namespace System
{
	using PgglRenderbufferStorageMultisampleEXT = void (OPENGL_STDCALL*) (GLenum, GLsizei, GLenum, GLsizei, GLsizei);
}

namespace System
{
	PgglRenderbufferStorageMultisampleEXT gglRenderbufferStorageMultisampleEXT{ nullptr };
}

void System
	::GlRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglRenderbufferStorageMultisampleEXT, target, samples, internalFormat, width, height);
}

void System
	::InitGlExtFrameBufferMultisample() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_framebuffer_multisample"))
	{
		g_ExistsGlExtFrameBufferMultisample = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglRenderbufferStorageMultisampleEXT);
	}
	else
	{
		g_ExistsGlExtFrameBufferMultisample = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 319) GL_EXT_timer_query

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTimerQuery{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTimerQuery() noexcept
{
	return g_ExistsGlExtTimerQuery;
}

namespace System
{
	using PgglGetQueryObjecti64vEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum parameterName, GLint64* params);
	using PgglGetQueryObjectui64vEXT = void (OPENGL_STDCALL*) (GLuint id, GLenum parameterName, GLuint64* params);
}

namespace System
{
	PgglGetQueryObjecti64vEXT gglGetQueryObjecti64vEXT{ nullptr };
	PgglGetQueryObjectui64vEXT gglGetQueryObjectui64vEXT{ nullptr };
}

void System
	::GlGetQueryObjecti64vEXT(GLuint id, GLenum parameterName, GLint64* params) noexcept
{
	SYSTEM_BODY_3(gglGetQueryObjecti64vEXT, id, parameterName, params);
}

void System
	::GlGetQueryObjectui64vEXT(GLuint id, GLenum parameterName, GLuint64* params) noexcept
{
	SYSTEM_BODY_3(gglGetQueryObjectui64vEXT, id, parameterName, params);
}

void System
	::InitGlExtTimerQuery() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_timer_query"))
	{
		g_ExistsGlExtTimerQuery = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetQueryObjecti64vEXT);
		SYSTEM_GET_FUNCTION(gglGetQueryObjectui64vEXT);
	}
	else
	{
		g_ExistsGlExtTimerQuery = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 320) GL_EXT_gpu_program_parameters

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtGpuProgramParameters{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtGpuProgramParameters() noexcept
{
	return g_ExistsGlExtGpuProgramParameters;
}

namespace System
{
	using PgglProgramEnvParameters4fvEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLsizei count, const GLfloat* params);
	using PgglProgramLocalParameters4fvEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLsizei count, const GLfloat* params);
}

namespace System
{
	PgglProgramEnvParameters4fvEXT gglProgramEnvParameters4fvEXT{ nullptr };
	PgglProgramLocalParameters4fvEXT gglProgramLocalParameters4fvEXT{ nullptr };
}

void System
	::GlProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglProgramEnvParameters4fvEXT, target, index, count, params);
}

void System
	::GlProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglProgramLocalParameters4fvEXT, target, index, count, params);
}

void System
	::InitGlExtGpuProgramParameters() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_gpu_program_parameters"))
	{
		g_ExistsGlExtGpuProgramParameters = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglProgramEnvParameters4fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramLocalParameters4fvEXT);
	}
	else
	{
		g_ExistsGlExtGpuProgramParameters = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 324) GL_EXT_geometry_shader4

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtGeometryShader4{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtGeometryShader4() noexcept
{
	return g_ExistsGlExtGeometryShader4;
}

namespace System
{
	using PgglFramebufferTextureEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	using PgglFramebufferTextureFaceEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
	using PgglProgramParameteriEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum parameterName, GLint value);
}

namespace System
{
	PgglFramebufferTextureEXT gglFramebufferTextureEXT{ nullptr };
	PgglFramebufferTextureFaceEXT gglFramebufferTextureFaceEXT{ nullptr };
	PgglProgramParameteriEXT gglProgramParameteriEXT{ nullptr };
}

void System
	::GlFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_4(gglFramebufferTextureEXT, target, attachment, texture, level);
}

void System
	::GlFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTextureFaceEXT, target, attachment, texture, level, face);
}

void System
	::GlProgramParameteriEXT(GLuint program, GLenum parameterName, GLint value) noexcept
{
	SYSTEM_BODY_3(gglProgramParameteriEXT, program, parameterName, value);
}

void System
	::InitGlExtGeometryShader4() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_geometry_shader4"))
	{
		g_ExistsGlExtGeometryShader4 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglFramebufferTextureEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferTextureFaceEXT);
		SYSTEM_GET_FUNCTION(gglProgramParameteriEXT);
	}
	else
	{
		g_ExistsGlExtGeometryShader4 = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 326) GL_EXT_gpu_shader4

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtGpuShader4{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtGpuShader4() noexcept
{
	return g_ExistsGlExtGpuShader4;
}

namespace System
{
	using PgglBindFragDataLocationEXT = void (OPENGL_STDCALL*)(GLuint program, GLuint color, const GLchar* name);
	using PgglGetFragDataLocationEXT = GLint(OPENGL_STDCALL*) (GLuint program, const GLchar* name);
	using PgglGetUniformuivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint* params);
	using PgglGetVertexAttribIivEXT = void (OPENGL_STDCALL*) (GLuint index, GLenum parameterName, GLint* params);
	using PgglGetVertexAttribIuivEXT = void (OPENGL_STDCALL*) (GLuint index, GLenum parameterName, GLuint* params);
	using PgglUniform1uiEXT = void (OPENGL_STDCALL*) (GLint location, GLuint v0);
	using PgglUniform1uivEXT = void (OPENGL_STDCALL*)(GLint location, GLsizei count, const GLuint* value);
	using PgglUniform2uiEXT = void (OPENGL_STDCALL*)(GLint location, GLuint v0, GLuint v1);
	using PgglUniform2uivEXT = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLuint* value);
	using PgglUniform3uiEXT = void (OPENGL_STDCALL*)(GLint location, GLuint v0, GLuint v1, GLuint v2);
	using PgglUniform3uivEXT = void (OPENGL_STDCALL*)(GLint location, GLsizei count, const GLuint* value);
	using PgglUniform4uiEXT = void (OPENGL_STDCALL*)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	using PgglUniform4uivEXT = void (OPENGL_STDCALL*) (GLint location, GLsizei count, const GLuint* value);
	using PgglVertexAttribI1iEXT = void (OPENGL_STDCALL*)(GLuint index, GLint x);
	using PgglVertexAttribI1ivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLint* v);
	using PgglVertexAttribI1uiEXT = void (OPENGL_STDCALL*) (GLuint index, GLuint x);
	using PgglVertexAttribI1uivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLuint* v);
	using PgglVertexAttribI2iEXT = void (OPENGL_STDCALL*) (GLuint index, GLint x, GLint y);
	using PgglVertexAttribI2ivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLint* v);
	using PgglVertexAttribI2uiEXT = void (OPENGL_STDCALL*) (GLuint index, GLuint x, GLuint y);
	using PgglVertexAttribI2uivEXT = void (OPENGL_STDCALL*)(GLuint index, const GLuint* v);
	using PgglVertexAttribI3iEXT = void (OPENGL_STDCALL*)(GLuint index, GLint x, GLint y, GLint z);
	using PgglVertexAttribI3ivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLint* v);
	using PgglVertexAttribI3uiEXT = void (OPENGL_STDCALL*) (GLuint index, GLuint x, GLuint y, GLuint z);
	using PgglVertexAttribI3uivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLuint* v);
	using PgglVertexAttribI4bvEXT = void (OPENGL_STDCALL*) (GLuint index, const GLbyte* v);
	using PgglVertexAttribI4iEXT = void (OPENGL_STDCALL*) (GLuint index, GLint x, GLint y, GLint z, GLint w);
	using PgglVertexAttribI4ivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLint* v);
	using PgglVertexAttribI4svEXT = void (OPENGL_STDCALL*)(GLuint index, const GLshort* v);
	using PgglVertexAttribI4ubvEXT = void (OPENGL_STDCALL*) (GLuint index, const GLubyte* v);
	using PgglVertexAttribI4uiEXT = void (OPENGL_STDCALL*) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	using PgglVertexAttribI4uivEXT = void (OPENGL_STDCALL*) (GLuint index, const GLuint* v);
	using PgglVertexAttribI4usvEXT = void (OPENGL_STDCALL*)(GLuint index, const GLushort* v);
	using PgglVertexAttribIPointerEXT = void (OPENGL_STDCALL*) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
}

namespace System
{
	PgglBindFragDataLocationEXT gglBindFragDataLocationEXT{ nullptr };
	PgglGetFragDataLocationEXT gglGetFragDataLocationEXT{ nullptr };
	PgglGetUniformuivEXT gglGetUniformuivEXT{ nullptr };
	PgglGetVertexAttribIivEXT gglGetVertexAttribIivEXT{ nullptr };
	PgglGetVertexAttribIuivEXT gglGetVertexAttribIuivEXT{ nullptr };
	PgglUniform1uiEXT gglUniform1uiEXT{ nullptr };
	PgglUniform1uivEXT gglUniform1uivEXT{ nullptr };
	PgglUniform2uiEXT gglUniform2uiEXT{ nullptr };
	PgglUniform2uivEXT gglUniform2uivEXT{ nullptr };
	PgglUniform3uiEXT gglUniform3uiEXT{ nullptr };
	PgglUniform3uivEXT gglUniform3uivEXT{ nullptr };
	PgglUniform4uiEXT gglUniform4uiEXT{ nullptr };
	PgglUniform4uivEXT gglUniform4uivEXT{ nullptr };
	PgglVertexAttribI1iEXT gglVertexAttribI1iEXT{ nullptr };
	PgglVertexAttribI1ivEXT gglVertexAttribI1ivEXT{ nullptr };
	PgglVertexAttribI1uiEXT gglVertexAttribI1uiEXT{ nullptr };
	PgglVertexAttribI1uivEXT gglVertexAttribI1uivEXT{ nullptr };
	PgglVertexAttribI2iEXT gglVertexAttribI2iEXT{ nullptr };
	PgglVertexAttribI2ivEXT gglVertexAttribI2ivEXT{ nullptr };
	PgglVertexAttribI2uiEXT gglVertexAttribI2uiEXT{ nullptr };
	PgglVertexAttribI2uivEXT gglVertexAttribI2uivEXT{ nullptr };
	PgglVertexAttribI3iEXT gglVertexAttribI3iEXT{ nullptr };
	PgglVertexAttribI3ivEXT gglVertexAttribI3ivEXT{ nullptr };
	PgglVertexAttribI3uiEXT gglVertexAttribI3uiEXT{ nullptr };
	PgglVertexAttribI3uivEXT gglVertexAttribI3uivEXT{ nullptr };
	PgglVertexAttribI4bvEXT gglVertexAttribI4bvEXT{ nullptr };
	PgglVertexAttribI4iEXT gglVertexAttribI4iEXT{ nullptr };
	PgglVertexAttribI4ivEXT gglVertexAttribI4ivEXT{ nullptr };
	PgglVertexAttribI4svEXT gglVertexAttribI4svEXT{ nullptr };
	PgglVertexAttribI4ubvEXT gglVertexAttribI4ubvEXT{ nullptr };
	PgglVertexAttribI4uiEXT gglVertexAttribI4uiEXT{ nullptr };
	PgglVertexAttribI4uivEXT gglVertexAttribI4uivEXT{ nullptr };
	PgglVertexAttribI4usvEXT gglVertexAttribI4usvEXT{ nullptr };
	PgglVertexAttribIPointerEXT gglVertexAttribIPointerEXT{ nullptr };
}

void System
	::GlBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar* name) noexcept
{
	SYSTEM_BODY_3(gglBindFragDataLocationEXT, program, color, name);
}

GLint System
	::GlGetFragDataLocationEXT(GLuint program, const GLchar* name) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetFragDataLocationEXT, program, name, GLint, 0);
}

void System
	::GlGetUniformuivEXT(GLuint program, GLint location, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetUniformuivEXT, program, location, params);
}

void System
	::GlGetVertexAttribIivEXT(GLuint index, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribIivEXT, index, parameterName, params);
}

void System
	::GlGetVertexAttribIuivEXT(GLuint index, GLenum parameterName, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribIuivEXT, index, parameterName, params);
}

void System
	::GlUniform1uiEXT(GLint location, GLuint v0) noexcept
{
	SYSTEM_BODY_2(gglUniform1uiEXT, location, v0);
}

void System
	::GlUniform1uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform1uivEXT, location, count, value);
}

void System
	::GlUniform2uiEXT(GLint location, GLuint v0, GLuint v1) noexcept
{
	SYSTEM_BODY_3(gglUniform2uiEXT, location, v0, v1);
}

void System
	::GlUniform2uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform2uivEXT, location, count, value);
}

void System
	::GlUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept
{
	SYSTEM_BODY_4(gglUniform3uiEXT, location, v0, v1, v2);
}

void System
	::GlUniform3uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform3uivEXT, location, count, value);
}

void System
	::GlUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept
{
	SYSTEM_BODY_5(gglUniform4uiEXT, location, v0, v1, v2, v3);
}

void System
	::GlUniform4uivEXT(GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_3(gglUniform4uivEXT, location, count, value);
}

void System
	::GlVertexAttribI1iEXT(GLuint index, GLint x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1iEXT, index, x);
}

void System
	::GlVertexAttribI1ivEXT(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1ivEXT, index, v);
}

void System
	::GlVertexAttribI1uiEXT(GLuint index, GLuint x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1uiEXT, index, x);
}

void System
	::GlVertexAttribI1uivEXT(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI1uivEXT, index, v);
}

void System
	::GlVertexAttribI2iEXT(GLuint index, GLint x, GLint y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttribI2iEXT, index, x, y);
}

void System
	::GlVertexAttribI2ivEXT(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI2ivEXT, index, v);
}

void System
	::GlVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttribI2uiEXT, index, x, y);
}

void System
	::GlVertexAttribI2uivEXT(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI2uivEXT, index, v);
}

void System
	::GlVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribI3iEXT, index, x, y, z);
}

void System
	::GlVertexAttribI3ivEXT(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI3ivEXT, index, v);
}

void System
	::GlVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribI3uiEXT, index, x, y, z);
}

void System
	::GlVertexAttribI3uivEXT(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI3uivEXT, index, v);
}

void System
	::GlVertexAttribI4bvEXT(GLuint index, const GLbyte* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4bvEXT, index, v);
}

void System
	::GlVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribI4iEXT, index, x, y, z, w);
}

void System
	::GlVertexAttribI4ivEXT(GLuint index, const GLint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4ivEXT, index, v);
}

void System
	::GlVertexAttribI4svEXT(GLuint index, const GLshort* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4svEXT, index, v);
}

void System
	::GlVertexAttribI4ubvEXT(GLuint index, const GLubyte* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4ubvEXT, index, v);
}

void System
	::GlVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribI4uiEXT, index, x, y, z, w);
}

void System
	::GlVertexAttribI4uivEXT(GLuint index, const GLuint* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4uivEXT, index, v);
}

void System
	::GlVertexAttribI4usvEXT(GLuint index, const GLushort* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribI4usvEXT, index, v);
}

void System
	::GlVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribIPointerEXT, index, size, type, stride, pointer);
}

void System
	::InitGlExtGpuShader4() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_gpu_shader4"))
	{
		g_ExistsGlExtGpuShader4 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindFragDataLocationEXT);
		SYSTEM_GET_FUNCTION(gglGetFragDataLocationEXT);
		SYSTEM_GET_FUNCTION(gglGetUniformuivEXT);
		SYSTEM_GET_FUNCTION(gglGetVertexAttribIivEXT);
		SYSTEM_GET_FUNCTION(gglGetVertexAttribIuivEXT);
		SYSTEM_GET_FUNCTION(gglUniform1uiEXT);
		SYSTEM_GET_FUNCTION(gglUniform1uivEXT);
		SYSTEM_GET_FUNCTION(gglUniform2uiEXT);
		SYSTEM_GET_FUNCTION(gglUniform2uivEXT);
		SYSTEM_GET_FUNCTION(gglUniform3uiEXT);
		SYSTEM_GET_FUNCTION(gglUniform3uivEXT);
		SYSTEM_GET_FUNCTION(gglUniform4uiEXT);
		SYSTEM_GET_FUNCTION(gglUniform4uivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1iEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1ivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1uiEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI1uivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2iEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2ivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2uiEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI2uivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3iEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3ivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3uiEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI3uivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4bvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4iEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4ivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4svEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4ubvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4uiEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4uivEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribI4usvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribIPointerEXT);
	}
	else
	{
		g_ExistsGlExtGpuShader4 = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 327) GL_EXT_draw_instanced

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDrawInstanced{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDrawInstanced() noexcept
{
	return g_ExistsGlExtDrawInstanced;
}

namespace System
{
	using PgglDrawArraysInstancedEXT = void (OPENGL_STDCALL*) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
	using PgglDrawElementsInstancedEXT = void (OPENGL_STDCALL*) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
}

namespace System
{
	PgglDrawArraysInstancedEXT gglDrawArraysInstancedEXT{ nullptr };
	PgglDrawElementsInstancedEXT gglDrawElementsInstancedEXT{ nullptr };
}

void System
	::GlDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) noexcept
{
	SYSTEM_BODY_4(gglDrawArraysInstancedEXT, mode, start, count, primcount);
}

void System
	::GlDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount) noexcept
{
	SYSTEM_BODY_5(gglDrawElementsInstancedEXT, mode, count, type, indices, primcount);
}

void System
	::InitGlExtDrawInstanced() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_draw_instanced"))
	{
		g_ExistsGlExtDrawInstanced = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawArraysInstancedEXT);
		SYSTEM_GET_FUNCTION(gglDrawElementsInstancedEXT);
	}
	else
	{
		g_ExistsGlExtDrawInstanced = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 328) GL_EXT_packed_float

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPackedFloat{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPackedFloat() noexcept
{
	return g_ExistsGlExtPackedFloat;
}

void System
	::InitGlExtPackedFloat() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_packed_float"))
	{
		g_ExistsGlExtPackedFloat = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtPackedFloat = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 329) GL_EXT_texture_array

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureArray{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureArray() noexcept
{
	return g_ExistsGlExtTextureArray;
}

namespace System
{
	using PgglFramebufferTextureLayerEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
}

namespace System
{
	PgglFramebufferTextureLayerEXT gglFramebufferTextureLayerEXT{ nullptr };
}

void System
	::GlFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
	SYSTEM_BODY_5(gglFramebufferTextureLayerEXT, target, attachment, texture, level, layer);
}

void System
	::InitGlExtTextureArray() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_array"))
	{
		g_ExistsGlExtTextureArray = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglFramebufferTextureLayerEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferTextureLayerEXT);
	}
	else
	{
		g_ExistsGlExtTextureArray = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 330) GL_EXT_texture_buffer_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureBufferObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureBufferObject() noexcept
{
	return g_ExistsGlExtTextureBufferObject;
}

namespace System
{
	using PgglTexBufferEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum internalformat, GLuint buffer);
}

namespace System
{
	PgglTexBufferEXT gglTexBufferEXT{ nullptr };
}

void System
	::GlTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglTexBufferEXT, target, internalformat, buffer);
}

void System
	::InitGlExtTextureBufferObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_buffer_object"))
	{
		g_ExistsGlExtTextureBufferObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglTexBufferEXT);

	}
	else
	{
		g_ExistsGlExtTextureBufferObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 331) GL_EXT_texture_compression_latc

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureCompressionLatc{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureCompressionLatc() noexcept
{
	return g_ExistsGlExtTextureCompressionLatc;
}

void System
	::InitGlExtTextureCompressionLatc() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_compression_latc"))
	{
		g_ExistsGlExtTextureCompressionLatc = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureCompressionLatc = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 332) GL_EXT_texture_compression_rgtc

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureCompressionRgtc{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureCompressionRgtc() noexcept
{
	return g_ExistsGlExtTextureCompressionRgtc;
}

void System
	::InitGlExtTextureCompressionRgtc() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_compression_rgtc"))
	{
		g_ExistsGlExtTextureCompressionRgtc = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureCompressionRgtc = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 333) GL_EXT_texture_shared_exponent

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureSharedExponent{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureSharedExponent() noexcept
{
	return g_ExistsGlExtTextureSharedExponent;
}

void System
	::InitGlExtTextureSharedExponent() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_shared_exponent"))
	{
		g_ExistsGlExtTextureSharedExponent = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureSharedExponent = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 337) GL_EXT_framebuffer_sRGB

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFramebufferSRGB{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFramebufferSRGB() noexcept
{
	return g_ExistsGlExtFramebufferSRGB;
}

void System
	::InitGlExtFramebufferSRGB() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_framebuffer_sRGB"))
	{
		g_ExistsGlExtFramebufferSRGB = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtFramebufferSRGB = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 340) GL_EXT_draw_buffers2

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDrawBuffers2{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDrawBuffers2() noexcept
{
	return g_ExistsGlExtDrawBuffers2;
}

namespace System
{
	using PgglColorMaskIndexedEXT = void (OPENGL_STDCALL*) (GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	using PgglDisableIndexedEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index);
	using PgglEnableIndexedEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index);
	using PgglGetBooleanIndexedvEXT = void (OPENGL_STDCALL*) (GLenum value, GLuint index, GLboolean* data);
	using PgglGetIntegerIndexedvEXT = void (OPENGL_STDCALL*) (GLenum value, GLuint index, GLint* data);
	using PgglIsEnabledIndexedEXT = GLboolean(OPENGL_STDCALL*) (GLenum target, GLuint index);
}

namespace System
{
	PgglColorMaskIndexedEXT gglColorMaskIndexedEXT{ nullptr };
	PgglDisableIndexedEXT gglDisableIndexedEXT{ nullptr };
	PgglEnableIndexedEXT gglEnableIndexedEXT{ nullptr };
	PgglGetBooleanIndexedvEXT gglGetBooleanIndexedvEXT{ nullptr };
	PgglGetIntegerIndexedvEXT gglGetIntegerIndexedvEXT{ nullptr };
	PgglIsEnabledIndexedEXT gglIsEnabledIndexedEXT{ nullptr };
}

void System
	::GlColorMaskIndexedEXT(GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept
{
	SYSTEM_BODY_5(gglColorMaskIndexedEXT, buf, r, g, b, a);
}

void System
	::GlDisableIndexedEXT(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglDisableIndexedEXT, target, index);
}

void System
	::GlEnableIndexedEXT(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEnableIndexedEXT, target, index);
}

void System
	::GlGetBooleanIndexedvEXT(GLenum value, GLuint index, GLboolean* data) noexcept
{
	SYSTEM_BODY_3(gglGetBooleanIndexedvEXT, value, index, data);
}

void System
	::GlGetIntegerIndexedvEXT(GLenum value, GLuint index, GLint* data) noexcept
{
	SYSTEM_BODY_3(gglGetIntegerIndexedvEXT, value, index, data);
}

GLboolean System
	::GlIsEnabledIndexedEXT(GLenum target, GLuint index) noexcept
{
	SYSTEM_BODY_2_RESULT(gglIsEnabledIndexedEXT, target, index, GLboolean, GL_FALSE);
}

void System
	::InitGlExtDrawBuffers2() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_draw_buffers2"))
	{
		g_ExistsGlExtDrawBuffers2 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglColorMaskIndexedEXT);
		SYSTEM_GET_FUNCTION(gglDisableIndexedEXT);
		SYSTEM_GET_FUNCTION(gglEnableIndexedEXT);
		SYSTEM_GET_FUNCTION(gglGetBooleanIndexedvEXT);
		SYSTEM_GET_FUNCTION(gglGetIntegerIndexedvEXT);
		SYSTEM_GET_FUNCTION(gglIsEnabledIndexedEXT);
	}
	else
	{
		g_ExistsGlExtDrawBuffers2 = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 342) GL_EXT_bindable_uniform

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtBindableUniform{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtBindableUniform() noexcept
{
	return g_ExistsGlExtBindableUniform;
}

namespace System
{
	using PgglGetUniformBufferSizeEXT = GLint(OPENGL_STDCALL*) (GLuint program, GLint location);
	using PgglGetUniformOffsetEXT = GLintptr(OPENGL_STDCALL*) (GLuint program, GLint location);
	using PgglUniformBufferEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint buffer);
}

namespace System
{
	PgglGetUniformBufferSizeEXT gglGetUniformBufferSizeEXT{ nullptr };
	PgglGetUniformOffsetEXT gglGetUniformOffsetEXT{ nullptr };
	PgglUniformBufferEXT gglUniformBufferEXT{ nullptr };
}

GLint System
	::GlGetUniformBufferSizeEXT(GLuint program, GLint location) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetUniformBufferSizeEXT, program, location, GLint, -1);
}

GLintptr System
	::GlGetUniformOffsetEXT(GLuint program, GLint location) noexcept
{
	SYSTEM_BODY_2_RESULT(gglGetUniformOffsetEXT, program, location, GLintptr, -1);
}

void System
	::GlUniformBufferEXT(GLuint program, GLint location, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglUniformBufferEXT, program, location, buffer);
}

void System
	::InitGlExtBindableUniform() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_bindable_uniform"))
	{
		g_ExistsGlExtBindableUniform = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetUniformBufferSizeEXT);
		SYSTEM_GET_FUNCTION(gglGetUniformOffsetEXT);
		SYSTEM_GET_FUNCTION(gglUniformBufferEXT);

	}
	else
	{
		g_ExistsGlExtBindableUniform = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 343) GL_EXT_texture_integer

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureInteger{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureInteger() noexcept
{
	return g_ExistsGlExtTextureInteger;
}

namespace System
{
	using PgglClearColorIiEXT = void (OPENGL_STDCALL*) (GLint red, GLint green, GLint blue, GLint alpha);
	using PgglClearColorIuiEXT = void (OPENGL_STDCALL*) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
	using PgglGetTexParameterIivEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, GLint* params);
	using PgglGetTexParameterIuivEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, GLuint* params);
	using PgglTexParameterIivEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, const GLint* params);
	using PgglTexParameterIuivEXT = void (OPENGL_STDCALL*) (GLenum target, GLenum parameterName, const GLuint* params);
}

namespace System
{
	PgglClearColorIiEXT gglClearColorIiEXT{ nullptr };
	PgglClearColorIuiEXT gglClearColorIuiEXT{ nullptr };
	PgglGetTexParameterIivEXT gglGetTexParameterIivEXT{ nullptr };
	PgglGetTexParameterIuivEXT gglGetTexParameterIuivEXT{ nullptr };
	PgglTexParameterIivEXT gglTexParameterIivEXT{ nullptr };
	PgglTexParameterIuivEXT gglTexParameterIuivEXT{ nullptr };
}

void System
	::GlClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha) noexcept
{
	SYSTEM_BODY_4(gglClearColorIiEXT, red, green, blue, alpha);
}

void System
	::GlClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha) noexcept
{
	SYSTEM_BODY_4(gglClearColorIuiEXT, red, green, blue, alpha);
}

void System
	::GlGetTexParameterIivEXT(GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTexParameterIivEXT, target, parameterName, params);
}

void System
	::GlGetTexParameterIuivEXT(GLenum target, GLenum parameterName, GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglGetTexParameterIuivEXT, target, parameterName, params);
}

void System
	::GlTexParameterIivEXT(GLenum target, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_3(gglTexParameterIivEXT, target, parameterName, params);
}

void System
	::GlTexParameterIuivEXT(GLenum target, GLenum parameterName, const GLuint* params) noexcept
{
	SYSTEM_BODY_3(gglTexParameterIuivEXT, target, parameterName, params);
}

void System
	::InitGlExtTextureInteger() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_integer"))
	{
		g_ExistsGlExtTextureInteger = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglClearColorIiEXT);
		SYSTEM_GET_FUNCTION(gglClearColorIuiEXT);
		SYSTEM_GET_FUNCTION(gglGetTexParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglGetTexParameterIuivEXT);
		SYSTEM_GET_FUNCTION(gglTexParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglTexParameterIuivEXT);
	}
	else
	{
		g_ExistsGlExtTextureInteger = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 352) GL_EXT_transform_feedback

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTransformFeedback{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTransformFeedback() noexcept
{
	return g_ExistsGlExtTransformFeedback;
}

namespace System
{
	using PgglBeginTransformFeedbackEXT = void (OPENGL_STDCALL*) (GLenum primitiveMode);
	using PgglBindBufferBaseEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLuint buffer);
	using PgglBindBufferOffsetEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLuint buffer, GLintptr offset);
	using PgglBindBufferRangeEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	using PgglEndTransformFeedbackEXT = void (OPENGL_STDCALL*) (void);
	using PgglGetTransformFeedbackVaryingEXT = void (OPENGL_STDCALL*) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum *type, GLchar *name);
	using PgglTransformFeedbackVaryingsEXT = void (OPENGL_STDCALL*) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
}

namespace System
{
	PgglBeginTransformFeedbackEXT gglBeginTransformFeedbackEXT{ nullptr };
	PgglBindBufferBaseEXT gglBindBufferBaseEXT{ nullptr };
	PgglBindBufferOffsetEXT gglBindBufferOffsetEXT{ nullptr };
	PgglBindBufferRangeEXT gglBindBufferRangeEXT{ nullptr };
	PgglEndTransformFeedbackEXT gglEndTransformFeedbackEXT{ nullptr };
	PgglGetTransformFeedbackVaryingEXT gglGetTransformFeedbackVaryingEXT{ nullptr };
	PgglTransformFeedbackVaryingsEXT gglTransformFeedbackVaryingsEXT{ nullptr };
}

void System
	::GlBeginTransformFeedbackEXT(GLenum primitiveMode) noexcept
{
	SYSTEM_BODY_1(gglBeginTransformFeedbackEXT, primitiveMode);
}

void System
	::GlBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglBindBufferBaseEXT, target, index, buffer);
}

void System
	::GlBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset) noexcept
{
	SYSTEM_BODY_4(gglBindBufferOffsetEXT, target, index, buffer, offset);
}

void System
	::GlBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglBindBufferRangeEXT, target, index, buffer, offset, size);
}

void System
	::GlEndTransformFeedbackEXT(void) noexcept
{
	SYSTEM_BODY_0(gglEndTransformFeedbackEXT);
}

void System
	::GlGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) noexcept
{
	SYSTEM_BODY_7(gglGetTransformFeedbackVaryingEXT, program, index, bufSize, length, size, type, name);
}

void System
	::GlTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) noexcept
{
	SYSTEM_BODY_4(gglTransformFeedbackVaryingsEXT, program, count, varyings, bufferMode);
}

void System
	::InitGlExtTransformFeedback() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_transform_feedback"))
	{
		g_ExistsGlExtTransformFeedback = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBeginTransformFeedbackEXT);
		SYSTEM_GET_FUNCTION(gglBindBufferBaseEXT);
		SYSTEM_GET_FUNCTION(gglBindBufferOffsetEXT);
		SYSTEM_GET_FUNCTION(gglBindBufferRangeEXT);
		SYSTEM_GET_FUNCTION(gglEndTransformFeedbackEXT);
		SYSTEM_GET_FUNCTION(gglGetTransformFeedbackVaryingEXT);
		SYSTEM_GET_FUNCTION(gglTransformFeedbackVaryingsEXT);
	}
	else
	{
		g_ExistsGlExtTransformFeedback = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 353) GL_EXT_direct_state_access

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDirectStateAccess{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDirectStateAccess() noexcept
{
	return g_ExistsGlExtDirectStateAccess;
}

namespace System
{
	using PgglBindMultiTextureEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLuint texture);
	using PgglCheckNamedFramebufferStatusEXT = GLenum(OPENGL_STDCALL*) (GLuint framebuffer, GLenum target);
	using PgglClientAttribDefaultEXT = void (OPENGL_STDCALL*) (GLbitfield mask);
	using PgglCompressedMultiTexImage1DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum internalformat,
																	 GLsizei width, GLint border, GLsizei imageSize, const void* data);
	using PgglCompressedMultiTexImage2DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width,
																	 GLsizei height, GLint border, GLsizei imageSize, const void* data);
	using PgglCompressedMultiTexImage3DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width,
																	 GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	using PgglCompressedMultiTexSubImage1DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset,
																	    GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedMultiTexSubImage2DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
																	    GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedMultiTexSubImage3DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
																		GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedTextureImage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum internalformat,
																	GLsizei width, GLint border, GLsizei imageSize, const void* data);
	using PgglCompressedTextureImage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width,
																	GLsizei height, GLint border, GLsizei imageSize, const void* data);
	using PgglCompressedTextureImage3DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width,
																	GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	using PgglCompressedTextureSubImage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset,
																	   GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedTextureSubImage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
																	   GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	using PgglCompressedTextureSubImage3DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
																	   GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	using PgglCopyMultiTexImage1DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	using PgglCopyMultiTexImage2DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x,
															   GLint y, GLsizei width, GLsizei height, GLint border);
	using PgglCopyMultiTexSubImage1DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	using PgglCopyMultiTexSubImage2DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
																  GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglCopyMultiTexSubImage3DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
																  GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglCopyTextureImage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	using PgglCopyTextureImage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x,
															  GLint y, GLsizei width, GLsizei height, GLint border);
	using PgglCopyTextureSubImage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	using PgglCopyTextureSubImage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglCopyTextureSubImage3DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
																 GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	using PgglDisableClientStateIndexedEXT = void (OPENGL_STDCALL*) (GLenum array, GLuint index);
	using PgglDisableClientStateiEXT = void (OPENGL_STDCALL*) (GLenum array, GLuint index);
	using PgglDisableVertexArrayAttribEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index);
	using PgglDisableVertexArrayEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLenum array);
	using PgglEnableClientStateIndexedEXT = void (OPENGL_STDCALL*) (GLenum array, GLuint index);
	using PgglEnableClientStateiEXT = void (OPENGL_STDCALL*) (GLenum array, GLuint index);
	using PgglEnableVertexArrayAttribEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index);
	using PgglEnableVertexArrayEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLenum array);
	using PgglFlushMappedNamedBufferRangeEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr length);
	using PgglFramebufferDrawBufferEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum mode);
	using PgglFramebufferDrawBuffersEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLsizei n, const GLenum* bufs);
	using PgglFramebufferReadBufferEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum mode);
	using PgglGenerateMultiTexMipmapEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target);
	using PgglGenerateTextureMipmapEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target);
	using PgglGetCompressedMultiTexImageEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, void* img);
	using PgglGetCompressedTextureImageEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, void* img);
	using PgglGetDoubleIndexedvEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLdouble* params);
	using PgglGetDoublei_vEXT = void (OPENGL_STDCALL*) (GLenum parameterName, GLuint index, GLdouble* params);
	using PgglGetFloatIndexedvEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, GLfloat* params);
	using PgglGetFloati_vEXT = void (OPENGL_STDCALL*) (GLenum parameterName, GLuint index, GLfloat* params);
	using PgglGetFramebufferParameterivEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum parameterName, GLint* param);
	using PgglGetMultiTexEnvfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLfloat* params);
	using PgglGetMultiTexEnvivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLint* params);
	using PgglGetMultiTexGendvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, GLdouble* params);
	using PgglGetMultiTexGenfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, GLfloat* params);
	using PgglGetMultiTexGenivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, GLint* params);
	using PgglGetMultiTexImageEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	using PgglGetMultiTexLevelParameterfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum parameterName, GLfloat* params);
	using PgglGetMultiTexLevelParameterivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLenum parameterName, GLint* params);
	using PgglGetMultiTexParameterIivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLint* params);
	using PgglGetMultiTexParameterIuivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLuint* params);
	using PgglGetMultiTexParameterfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLfloat* params);
	using PgglGetMultiTexParameterivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLint* params);
	using PgglGetNamedBufferParameterivEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLenum parameterName, GLint* params);
	using PgglGetNamedBufferPointervEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLenum parameterName, void** params);
	using PgglGetNamedBufferSubDataEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
	using PgglGetNamedFramebufferAttachmentParameterivEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLenum parameterName, GLint* params);
	using PgglGetNamedProgramLocalParameterIivEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLint* params);
	using PgglGetNamedProgramLocalParameterIuivEXT = void (OPENGL_STDCALL*)(GLuint program, GLenum target, GLuint index, GLuint* params);
	using PgglGetNamedProgramLocalParameterdvEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLdouble* params);
	using PgglGetNamedProgramLocalParameterfvEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLfloat* params);
	using PgglGetNamedProgramStringEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLenum parameterName, void* string);
	using PgglGetNamedProgramivEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLenum parameterName, GLint* params);
	using PgglGetNamedRenderbufferParameterivEXT = void (OPENGL_STDCALL*) (GLuint renderbuffer, GLenum parameterName, GLint* params);
	using PgglGetPointerIndexedvEXT = void (OPENGL_STDCALL*) (GLenum target, GLuint index, void** params);
	using PgglGetPointeri_vEXT = void (OPENGL_STDCALL*) (GLenum parameterName, GLuint index, void** params);
	using PgglGetTextureImageEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	using PgglGetTextureLevelParameterfvEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum parameterName, GLfloat* params);
	using PgglGetTextureLevelParameterivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLenum parameterName, GLint* params);
	using PgglGetTextureParameterIivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, GLint* params);
	using PgglGetTextureParameterIuivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, GLuint* params);
	using PgglGetTextureParameterfvEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, GLfloat* params);
	using PgglGetTextureParameterivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, GLint* params);
	using PgglGetVertexArrayIntegeri_vEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index, GLenum parameterName, GLint* param);
	using PgglGetVertexArrayIntegervEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLenum parameterName, GLint* param);
	using PgglGetVertexArrayPointeri_vEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index, GLenum parameterName, void** param);
	using PgglGetVertexArrayPointervEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLenum parameterName, void** param);
	using PgglMapNamedBufferEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLenum access);
	using PgglMapNamedBufferRangeEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
	using PgglMatrixFrustumEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
	using PgglMatrixLoadIdentityEXT = void (OPENGL_STDCALL*) (GLenum matrixMode);
	using PgglMatrixLoadTransposedEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLdouble* m);
	using PgglMatrixLoadTransposefEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLfloat* m);
	using PgglMatrixLoaddEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLdouble* m);
	using PgglMatrixLoadfEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLfloat* m);
	using PgglMatrixMultTransposedEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLdouble* m);
	using PgglMatrixMultTransposefEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLfloat* m);
	using PgglMatrixMultdEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLdouble* m);
	using PgglMatrixMultfEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, const GLfloat* m);
	using PgglMatrixOrthoEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
	using PgglMatrixPopEXT = void (OPENGL_STDCALL*) (GLenum matrixMode);
	using PgglMatrixPushEXT = void (OPENGL_STDCALL*) (GLenum matrixMode);
	using PgglMatrixRotatedEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	using PgglMatrixRotatefEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	using PgglMatrixScaledEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
	using PgglMatrixScalefEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
	using PgglMatrixTranslatedEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
	using PgglMatrixTranslatefEXT = void (OPENGL_STDCALL*) (GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
	using PgglMultiTexBufferEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
	using PgglMultiTexCoordPointerEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer);
	using PgglMultiTexEnvfEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLfloat param);
	using PgglMultiTexEnvfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, const GLfloat* params);
	using PgglMultiTexEnviEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLint param);
	using PgglMultiTexEnvivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, const GLint* params);
	using PgglMultiTexGendEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, GLdouble param);
	using PgglMultiTexGendvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, const GLdouble* params);
	using PgglMultiTexGenfEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, GLfloat param);
	using PgglMultiTexGenfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, const GLfloat* params);
	using PgglMultiTexGeniEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, GLint param);
	using PgglMultiTexGenivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum coord, GLenum parameterName, const GLint* params);
	using PgglMultiTexImage1DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width,
														   GLint border, GLenum format, GLenum type, const void* pixels);
	using PgglMultiTexImage2DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width,
														   GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
	using PgglMultiTexImage3DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
														   GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	using PgglMultiTexParameterIivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, const GLint* params);
	using PgglMultiTexParameterIuivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, const GLuint* params);
	using PgglMultiTexParameterfEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLfloat param);
	using PgglMultiTexParameterfvEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, const GLfloat* param);
	using PgglMultiTexParameteriEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, GLint param);
	using PgglMultiTexParameterivEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLenum parameterName, const GLint* param);
	using PgglMultiTexRenderbufferEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLuint renderbuffer);
	using PgglMultiTexSubImage1DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	using PgglMultiTexSubImage2DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
															  GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	using PgglMultiTexSubImage3DEXT = void (OPENGL_STDCALL*) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
															  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	using PgglNamedBufferDataEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
	using PgglNamedBufferSubDataEXT = void (OPENGL_STDCALL*) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
	using PgglNamedCopyBufferSubDataEXT = void (OPENGL_STDCALL*) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	using PgglNamedFramebufferRenderbufferEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	using PgglNamedFramebufferTexture1DEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PgglNamedFramebufferTexture2DEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	using PgglNamedFramebufferTexture3DEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	using PgglNamedFramebufferTextureEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
	using PgglNamedFramebufferTextureFaceEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
	using PgglNamedFramebufferTextureLayerEXT = void (OPENGL_STDCALL*) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
	using PgglNamedProgramLocalParameter4dEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PgglNamedProgramLocalParameter4dvEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, const GLdouble* params);
	using PgglNamedProgramLocalParameter4fEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	using PgglNamedProgramLocalParameter4fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, const GLfloat* params);
	using PgglNamedProgramLocalParameterI4iEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	using PgglNamedProgramLocalParameterI4ivEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, const GLint* params);
	using PgglNamedProgramLocalParameterI4uiEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	using PgglNamedProgramLocalParameterI4uivEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, const GLuint* params);
	using PgglNamedProgramLocalParameters4fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
	using PgglNamedProgramLocalParametersI4ivEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
	using PgglNamedProgramLocalParametersI4uivEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
	using PgglNamedProgramStringEXT = void (OPENGL_STDCALL*) (GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
	using PgglNamedRenderbufferStorageEXT = void (OPENGL_STDCALL*) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);

	using PgglNamedRenderbufferStorageMultisampleCoverageEXT = void (OPENGL_STDCALL*)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples,
																					  GLenum internalformat, GLsizei width, GLsizei height);
	using PgglNamedRenderbufferStorageMultisampleEXT = void (OPENGL_STDCALL*) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	using PgglProgramUniform1fEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat v0);
	using PgglProgramUniform1fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform1iEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint v0);
	using PgglProgramUniform1ivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform1uiEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint v0);
	using PgglProgramUniform1uivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniform2fEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
	using PgglProgramUniform2fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform2iEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint v0, GLint v1);
	using PgglProgramUniform2ivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform2uiEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint v0, GLuint v1);
	using PgglProgramUniform2uivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniform3fEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	using PgglProgramUniform3fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform3iEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	using PgglProgramUniform3ivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform3uiEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	using PgglProgramUniform3uivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniform4fEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	using PgglProgramUniform4fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
	using PgglProgramUniform4iEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	using PgglProgramUniform4ivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLint* value);
	using PgglProgramUniform4uiEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	using PgglProgramUniform4uivEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, const GLuint* value);
	using PgglProgramUniformMatrix2fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix2x3fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix2x4fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix3fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix3x2fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix3x4fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix4fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix4x2fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglProgramUniformMatrix4x3fvEXT = void (OPENGL_STDCALL*) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	using PgglPushClientAttribDefaultEXT = void (OPENGL_STDCALL*) (GLbitfield mask);
	using PgglTextureBufferEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
	using PgglTextureImage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width,
														  GLint border, GLenum format, GLenum type, const void *pixels);
	using PgglTextureImage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width,
														  GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
	using PgglTextureImage3DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
														  GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	using PgglTextureParameterIivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, const GLint* params);
	using PgglTextureParameterIuivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, const GLuint* params);
	using PgglTextureParameterfEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, GLfloat param);
	using PgglTextureParameterfvEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, const GLfloat* param);
	using PgglTextureParameteriEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, GLint param);
	using PgglTextureParameterivEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLenum parameterName, const GLint* param);
	using PgglTextureRenderbufferEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLuint renderbuffer);
	using PgglTextureSubImage1DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	using PgglTextureSubImage2DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
															 GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	using PgglTextureSubImage3DEXT = void (OPENGL_STDCALL*) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
															 GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	using PgglUnmapNamedBufferEXT = GLboolean(OPENGL_STDCALL*) (GLuint buffer);
	using PgglVertexArrayColorOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayEdgeFlagOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
	using PgglVertexArrayFogCoordOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayIndexOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayMultiTexCoordOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayNormalOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArraySecondaryColorOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayTexCoordOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayVertexAttribDivisorEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint index, GLuint divisor);
	using PgglVertexArrayVertexAttribIOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexArrayVertexAttribOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLuint index, GLint size,
																		 GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
	using PgglVertexArrayVertexOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
}

namespace System
{
	PgglBindMultiTextureEXT gglBindMultiTextureEXT{ nullptr };
	PgglCheckNamedFramebufferStatusEXT gglCheckNamedFramebufferStatusEXT{ nullptr };
	PgglClientAttribDefaultEXT gglClientAttribDefaultEXT{ nullptr };
	PgglCompressedMultiTexImage1DEXT gglCompressedMultiTexImage1DEXT{ nullptr };
	PgglCompressedMultiTexImage2DEXT gglCompressedMultiTexImage2DEXT{ nullptr };
	PgglCompressedMultiTexImage3DEXT gglCompressedMultiTexImage3DEXT{ nullptr };
	PgglCompressedMultiTexSubImage1DEXT gglCompressedMultiTexSubImage1DEXT{ nullptr };
	PgglCompressedMultiTexSubImage2DEXT gglCompressedMultiTexSubImage2DEXT{ nullptr };
	PgglCompressedMultiTexSubImage3DEXT gglCompressedMultiTexSubImage3DEXT{ nullptr };
	PgglCompressedTextureImage1DEXT gglCompressedTextureImage1DEXT{ nullptr };
	PgglCompressedTextureImage2DEXT gglCompressedTextureImage2DEXT{ nullptr };
	PgglCompressedTextureImage3DEXT gglCompressedTextureImage3DEXT{ nullptr };
	PgglCompressedTextureSubImage1DEXT gglCompressedTextureSubImage1DEXT{ nullptr };
	PgglCompressedTextureSubImage2DEXT gglCompressedTextureSubImage2DEXT{ nullptr };
	PgglCompressedTextureSubImage3DEXT gglCompressedTextureSubImage3DEXT{ nullptr };
	PgglCopyMultiTexImage1DEXT gglCopyMultiTexImage1DEXT{ nullptr };
	PgglCopyMultiTexImage2DEXT gglCopyMultiTexImage2DEXT{ nullptr };
	PgglCopyMultiTexSubImage1DEXT gglCopyMultiTexSubImage1DEXT{ nullptr };
	PgglCopyMultiTexSubImage2DEXT gglCopyMultiTexSubImage2DEXT{ nullptr };
	PgglCopyMultiTexSubImage3DEXT gglCopyMultiTexSubImage3DEXT{ nullptr };
	PgglCopyTextureImage1DEXT gglCopyTextureImage1DEXT{ nullptr };
	PgglCopyTextureImage2DEXT gglCopyTextureImage2DEXT{ nullptr };
	PgglCopyTextureSubImage1DEXT gglCopyTextureSubImage1DEXT{ nullptr };
	PgglCopyTextureSubImage2DEXT gglCopyTextureSubImage2DEXT{ nullptr };
	PgglCopyTextureSubImage3DEXT gglCopyTextureSubImage3DEXT{ nullptr };
	PgglDisableClientStateIndexedEXT gglDisableClientStateIndexedEXT{ nullptr };
	PgglDisableClientStateiEXT gglDisableClientStateiEXT{ nullptr };
	PgglDisableVertexArrayAttribEXT gglDisableVertexArrayAttribEXT{ nullptr };
	PgglDisableVertexArrayEXT gglDisableVertexArrayEXT{ nullptr };
	PgglEnableClientStateIndexedEXT gglEnableClientStateIndexedEXT{ nullptr };
	PgglEnableClientStateiEXT gglEnableClientStateiEXT{ nullptr };
	PgglEnableVertexArrayAttribEXT gglEnableVertexArrayAttribEXT{ nullptr };
	PgglEnableVertexArrayEXT gglEnableVertexArrayEXT{ nullptr };
	PgglFlushMappedNamedBufferRangeEXT gglFlushMappedNamedBufferRangeEXT{ nullptr };
	PgglFramebufferDrawBufferEXT gglFramebufferDrawBufferEXT{ nullptr };
	PgglFramebufferDrawBuffersEXT gglFramebufferDrawBuffersEXT{ nullptr };
	PgglFramebufferReadBufferEXT gglFramebufferReadBufferEXT{ nullptr };
	PgglGenerateMultiTexMipmapEXT gglGenerateMultiTexMipmapEXT{ nullptr };
	PgglGenerateTextureMipmapEXT gglGenerateTextureMipmapEXT{ nullptr };
	PgglGetCompressedMultiTexImageEXT gglGetCompressedMultiTexImageEXT{ nullptr };
	PgglGetCompressedTextureImageEXT gglGetCompressedTextureImageEXT{ nullptr };
	PgglGetDoubleIndexedvEXT gglGetDoubleIndexedvEXT{ nullptr };
	PgglGetDoublei_vEXT gglGetDoublei_vEXT{ nullptr };
	PgglGetFloatIndexedvEXT gglGetFloatIndexedvEXT{ nullptr };
	PgglGetFloati_vEXT gglGetFloati_vEXT{ nullptr };
	PgglGetFramebufferParameterivEXT gglGetFramebufferParameterivEXT{ nullptr };
	PgglGetMultiTexEnvfvEXT gglGetMultiTexEnvfvEXT{ nullptr };
	PgglGetMultiTexEnvivEXT gglGetMultiTexEnvivEXT{ nullptr };
	PgglGetMultiTexGendvEXT gglGetMultiTexGendvEXT{ nullptr };
	PgglGetMultiTexGenfvEXT gglGetMultiTexGenfvEXT{ nullptr };
	PgglGetMultiTexGenivEXT gglGetMultiTexGenivEXT{ nullptr };
	PgglGetMultiTexImageEXT gglGetMultiTexImageEXT{ nullptr };
	PgglGetMultiTexLevelParameterfvEXT gglGetMultiTexLevelParameterfvEXT{ nullptr };
	PgglGetMultiTexLevelParameterivEXT gglGetMultiTexLevelParameterivEXT{ nullptr };
	PgglGetMultiTexParameterIivEXT gglGetMultiTexParameterIivEXT{ nullptr };
	PgglGetMultiTexParameterIuivEXT gglGetMultiTexParameterIuivEXT{ nullptr };
	PgglGetMultiTexParameterfvEXT gglGetMultiTexParameterfvEXT{ nullptr };
	PgglGetMultiTexParameterivEXT gglGetMultiTexParameterivEXT{ nullptr };
	PgglGetNamedBufferParameterivEXT gglGetNamedBufferParameterivEXT{ nullptr };
	PgglGetNamedBufferPointervEXT gglGetNamedBufferPointervEXT{ nullptr };
	PgglGetNamedBufferSubDataEXT gglGetNamedBufferSubDataEXT{ nullptr };
	PgglGetNamedFramebufferAttachmentParameterivEXT gglGetNamedFramebufferAttachmentParameterivEXT{ nullptr };
	PgglGetNamedProgramLocalParameterIivEXT gglGetNamedProgramLocalParameterIivEXT{ nullptr };
	PgglGetNamedProgramLocalParameterIuivEXT gglGetNamedProgramLocalParameterIuivEXT{ nullptr };
	PgglGetNamedProgramLocalParameterdvEXT gglGetNamedProgramLocalParameterdvEXT{ nullptr };
	PgglGetNamedProgramLocalParameterfvEXT gglGetNamedProgramLocalParameterfvEXT{ nullptr };
	PgglGetNamedProgramStringEXT gglGetNamedProgramStringEXT{ nullptr };
	PgglGetNamedProgramivEXT gglGetNamedProgramivEXT{ nullptr };
	PgglGetNamedRenderbufferParameterivEXT gglGetNamedRenderbufferParameterivEXT{ nullptr };
	PgglGetPointerIndexedvEXT gglGetPointerIndexedvEXT{ nullptr };
	PgglGetPointeri_vEXT gglGetPointeri_vEXT{ nullptr };
	PgglGetTextureImageEXT gglGetTextureImageEXT{ nullptr };
	PgglGetTextureLevelParameterfvEXT gglGetTextureLevelParameterfvEXT{ nullptr };
	PgglGetTextureLevelParameterivEXT gglGetTextureLevelParameterivEXT{ nullptr };
	PgglGetTextureParameterIivEXT gglGetTextureParameterIivEXT{ nullptr };
	PgglGetTextureParameterIuivEXT gglGetTextureParameterIuivEXT{ nullptr };
	PgglGetTextureParameterfvEXT gglGetTextureParameterfvEXT{ nullptr };
	PgglGetTextureParameterivEXT gglGetTextureParameterivEXT{ nullptr };
	PgglGetVertexArrayIntegeri_vEXT gglGetVertexArrayIntegeri_vEXT{ nullptr };
	PgglGetVertexArrayIntegervEXT gglGetVertexArrayIntegervEXT{ nullptr };
	PgglGetVertexArrayPointeri_vEXT gglGetVertexArrayPointeri_vEXT{ nullptr };
	PgglGetVertexArrayPointervEXT gglGetVertexArrayPointervEXT{ nullptr };
	PgglMapNamedBufferEXT gglMapNamedBufferEXT{ nullptr };
	PgglMapNamedBufferRangeEXT gglMapNamedBufferRangeEXT{ nullptr };
	PgglMatrixFrustumEXT gglMatrixFrustumEXT{ nullptr };
	PgglMatrixLoadIdentityEXT gglMatrixLoadIdentityEXT{ nullptr };
	PgglMatrixLoadTransposedEXT gglMatrixLoadTransposedEXT{ nullptr };
	PgglMatrixLoadTransposefEXT gglMatrixLoadTransposefEXT{ nullptr };
	PgglMatrixLoaddEXT gglMatrixLoaddEXT{ nullptr };
	PgglMatrixLoadfEXT gglMatrixLoadfEXT{ nullptr };
	PgglMatrixMultTransposedEXT gglMatrixMultTransposedEXT{ nullptr };
	PgglMatrixMultTransposefEXT gglMatrixMultTransposefEXT{ nullptr };
	PgglMatrixMultdEXT gglMatrixMultdEXT{ nullptr };
	PgglMatrixMultfEXT gglMatrixMultfEXT{ nullptr };
	PgglMatrixOrthoEXT gglMatrixOrthoEXT{ nullptr };
	PgglMatrixPopEXT gglMatrixPopEXT{ nullptr };
	PgglMatrixPushEXT gglMatrixPushEXT{ nullptr };
	PgglMatrixRotatedEXT gglMatrixRotatedEXT{ nullptr };
	PgglMatrixRotatefEXT gglMatrixRotatefEXT{ nullptr };
	PgglMatrixScaledEXT gglMatrixScaledEXT{ nullptr };
	PgglMatrixScalefEXT gglMatrixScalefEXT{ nullptr };
	PgglMatrixTranslatedEXT gglMatrixTranslatedEXT{ nullptr };
	PgglMatrixTranslatefEXT gglMatrixTranslatefEXT{ nullptr };
	PgglMultiTexBufferEXT gglMultiTexBufferEXT{ nullptr };
	PgglMultiTexCoordPointerEXT gglMultiTexCoordPointerEXT{ nullptr };
	PgglMultiTexEnvfEXT gglMultiTexEnvfEXT{ nullptr };
	PgglMultiTexEnvfvEXT gglMultiTexEnvfvEXT{ nullptr };
	PgglMultiTexEnviEXT gglMultiTexEnviEXT{ nullptr };
	PgglMultiTexEnvivEXT gglMultiTexEnvivEXT{ nullptr };
	PgglMultiTexGendEXT gglMultiTexGendEXT{ nullptr };
	PgglMultiTexGendvEXT gglMultiTexGendvEXT{ nullptr };
	PgglMultiTexGenfEXT gglMultiTexGenfEXT{ nullptr };
	PgglMultiTexGenfvEXT gglMultiTexGenfvEXT{ nullptr };
	PgglMultiTexGeniEXT gglMultiTexGeniEXT{ nullptr };
	PgglMultiTexGenivEXT gglMultiTexGenivEXT{ nullptr };
	PgglMultiTexImage1DEXT gglMultiTexImage1DEXT{ nullptr };
	PgglMultiTexImage2DEXT gglMultiTexImage2DEXT{ nullptr };
	PgglMultiTexImage3DEXT gglMultiTexImage3DEXT{ nullptr };
	PgglMultiTexParameterIivEXT gglMultiTexParameterIivEXT{ nullptr };
	PgglMultiTexParameterIuivEXT gglMultiTexParameterIuivEXT{ nullptr };
	PgglMultiTexParameterfEXT gglMultiTexParameterfEXT{ nullptr };
	PgglMultiTexParameterfvEXT gglMultiTexParameterfvEXT{ nullptr };
	PgglMultiTexParameteriEXT gglMultiTexParameteriEXT{ nullptr };
	PgglMultiTexParameterivEXT gglMultiTexParameterivEXT{ nullptr };
	PgglMultiTexRenderbufferEXT gglMultiTexRenderbufferEXT{ nullptr };
	PgglMultiTexSubImage1DEXT gglMultiTexSubImage1DEXT{ nullptr };
	PgglMultiTexSubImage2DEXT gglMultiTexSubImage2DEXT{ nullptr };
	PgglMultiTexSubImage3DEXT gglMultiTexSubImage3DEXT{ nullptr };
	PgglNamedBufferDataEXT gglNamedBufferDataEXT{ nullptr };
	PgglNamedBufferSubDataEXT gglNamedBufferSubDataEXT{ nullptr };
	PgglNamedCopyBufferSubDataEXT gglNamedCopyBufferSubDataEXT{ nullptr };
	PgglNamedFramebufferRenderbufferEXT gglNamedFramebufferRenderbufferEXT{ nullptr };
	PgglNamedFramebufferTexture1DEXT gglNamedFramebufferTexture1DEXT{ nullptr };
	PgglNamedFramebufferTexture2DEXT gglNamedFramebufferTexture2DEXT{ nullptr };
	PgglNamedFramebufferTexture3DEXT gglNamedFramebufferTexture3DEXT{ nullptr };
	PgglNamedFramebufferTextureEXT gglNamedFramebufferTextureEXT{ nullptr };
	PgglNamedFramebufferTextureFaceEXT gglNamedFramebufferTextureFaceEXT{ nullptr };
	PgglNamedFramebufferTextureLayerEXT gglNamedFramebufferTextureLayerEXT{ nullptr };
	PgglNamedProgramLocalParameter4dEXT gglNamedProgramLocalParameter4dEXT{ nullptr };
	PgglNamedProgramLocalParameter4dvEXT gglNamedProgramLocalParameter4dvEXT{ nullptr };
	PgglNamedProgramLocalParameter4fEXT gglNamedProgramLocalParameter4fEXT{ nullptr };
	PgglNamedProgramLocalParameter4fvEXT gglNamedProgramLocalParameter4fvEXT{ nullptr };
	PgglNamedProgramLocalParameterI4iEXT gglNamedProgramLocalParameterI4iEXT{ nullptr };
	PgglNamedProgramLocalParameterI4ivEXT gglNamedProgramLocalParameterI4ivEXT{ nullptr };
	PgglNamedProgramLocalParameterI4uiEXT gglNamedProgramLocalParameterI4uiEXT{ nullptr };
	PgglNamedProgramLocalParameterI4uivEXT gglNamedProgramLocalParameterI4uivEXT{ nullptr };
	PgglNamedProgramLocalParameters4fvEXT gglNamedProgramLocalParameters4fvEXT{ nullptr };
	PgglNamedProgramLocalParametersI4ivEXT gglNamedProgramLocalParametersI4ivEXT{ nullptr };
	PgglNamedProgramLocalParametersI4uivEXT gglNamedProgramLocalParametersI4uivEXT{ nullptr };
	PgglNamedProgramStringEXT gglNamedProgramStringEXT{ nullptr };
	PgglNamedRenderbufferStorageEXT gglNamedRenderbufferStorageEXT{ nullptr };
	PgglNamedRenderbufferStorageMultisampleCoverageEXT gglNamedRenderbufferStorageMultisampleCoverageEXT{ nullptr };
	PgglNamedRenderbufferStorageMultisampleEXT gglNamedRenderbufferStorageMultisampleEXT{ nullptr };
	PgglProgramUniform1fEXT gglProgramUniform1fEXT{ nullptr };
	PgglProgramUniform1fvEXT gglProgramUniform1fvEXT{ nullptr };
	PgglProgramUniform1iEXT gglProgramUniform1iEXT{ nullptr };
	PgglProgramUniform1ivEXT gglProgramUniform1ivEXT{ nullptr };
	PgglProgramUniform1uiEXT gglProgramUniform1uiEXT{ nullptr };
	PgglProgramUniform1uivEXT gglProgramUniform1uivEXT{ nullptr };
	PgglProgramUniform2fEXT gglProgramUniform2fEXT{ nullptr };
	PgglProgramUniform2fvEXT gglProgramUniform2fvEXT{ nullptr };
	PgglProgramUniform2iEXT gglProgramUniform2iEXT{ nullptr };
	PgglProgramUniform2ivEXT gglProgramUniform2ivEXT{ nullptr };
	PgglProgramUniform2uiEXT gglProgramUniform2uiEXT{ nullptr };
	PgglProgramUniform2uivEXT gglProgramUniform2uivEXT{ nullptr };
	PgglProgramUniform3fEXT gglProgramUniform3fEXT{ nullptr };
	PgglProgramUniform3fvEXT gglProgramUniform3fvEXT{ nullptr };
	PgglProgramUniform3iEXT gglProgramUniform3iEXT{ nullptr };
	PgglProgramUniform3ivEXT gglProgramUniform3ivEXT{ nullptr };
	PgglProgramUniform3uiEXT gglProgramUniform3uiEXT{ nullptr };
	PgglProgramUniform3uivEXT gglProgramUniform3uivEXT{ nullptr };
	PgglProgramUniform4fEXT gglProgramUniform4fEXT{ nullptr };
	PgglProgramUniform4fvEXT gglProgramUniform4fvEXT{ nullptr };
	PgglProgramUniform4iEXT gglProgramUniform4iEXT{ nullptr };
	PgglProgramUniform4ivEXT gglProgramUniform4ivEXT{ nullptr };
	PgglProgramUniform4uiEXT gglProgramUniform4uiEXT{ nullptr };
	PgglProgramUniform4uivEXT gglProgramUniform4uivEXT{ nullptr };
	PgglProgramUniformMatrix2fvEXT gglProgramUniformMatrix2fvEXT{ nullptr };
	PgglProgramUniformMatrix2x3fvEXT gglProgramUniformMatrix2x3fvEXT{ nullptr };
	PgglProgramUniformMatrix2x4fvEXT gglProgramUniformMatrix2x4fvEXT{ nullptr };
	PgglProgramUniformMatrix3fvEXT gglProgramUniformMatrix3fvEXT{ nullptr };
	PgglProgramUniformMatrix3x2fvEXT gglProgramUniformMatrix3x2fvEXT{ nullptr };
	PgglProgramUniformMatrix3x4fvEXT gglProgramUniformMatrix3x4fvEXT{ nullptr };
	PgglProgramUniformMatrix4fvEXT gglProgramUniformMatrix4fvEXT{ nullptr };
	PgglProgramUniformMatrix4x2fvEXT gglProgramUniformMatrix4x2fvEXT{ nullptr };
	PgglProgramUniformMatrix4x3fvEXT gglProgramUniformMatrix4x3fvEXT{ nullptr };
	PgglPushClientAttribDefaultEXT gglPushClientAttribDefaultEXT{ nullptr };
	PgglTextureBufferEXT gglTextureBufferEXT{ nullptr };
	PgglTextureImage1DEXT gglTextureImage1DEXT{ nullptr };
	PgglTextureImage2DEXT gglTextureImage2DEXT{ nullptr };
	PgglTextureImage3DEXT gglTextureImage3DEXT{ nullptr };
	PgglTextureParameterIivEXT gglTextureParameterIivEXT{ nullptr };
	PgglTextureParameterIuivEXT gglTextureParameterIuivEXT{ nullptr };
	PgglTextureParameterfEXT gglTextureParameterfEXT{ nullptr };
	PgglTextureParameterfvEXT gglTextureParameterfvEXT{ nullptr };
	PgglTextureParameteriEXT gglTextureParameteriEXT{ nullptr };
	PgglTextureParameterivEXT gglTextureParameterivEXT{ nullptr };
	PgglTextureRenderbufferEXT gglTextureRenderbufferEXT{ nullptr };
	PgglTextureSubImage1DEXT gglTextureSubImage1DEXT{ nullptr };
	PgglTextureSubImage2DEXT gglTextureSubImage2DEXT{ nullptr };
	PgglTextureSubImage3DEXT gglTextureSubImage3DEXT{ nullptr };
	PgglUnmapNamedBufferEXT gglUnmapNamedBufferEXT{ nullptr };
	PgglVertexArrayColorOffsetEXT gglVertexArrayColorOffsetEXT{ nullptr };
	PgglVertexArrayEdgeFlagOffsetEXT gglVertexArrayEdgeFlagOffsetEXT{ nullptr };
	PgglVertexArrayFogCoordOffsetEXT gglVertexArrayFogCoordOffsetEXT{ nullptr };
	PgglVertexArrayIndexOffsetEXT gglVertexArrayIndexOffsetEXT{ nullptr };
	PgglVertexArrayMultiTexCoordOffsetEXT gglVertexArrayMultiTexCoordOffsetEXT{ nullptr };
	PgglVertexArrayNormalOffsetEXT gglVertexArrayNormalOffsetEXT{ nullptr };
	PgglVertexArraySecondaryColorOffsetEXT gglVertexArraySecondaryColorOffsetEXT{ nullptr };
	PgglVertexArrayTexCoordOffsetEXT gglVertexArrayTexCoordOffsetEXT{ nullptr };
	PgglVertexArrayVertexAttribDivisorEXT gglVertexArrayVertexAttribDivisorEXT{ nullptr };
	PgglVertexArrayVertexAttribIOffsetEXT gglVertexArrayVertexAttribIOffsetEXT{ nullptr };
	PgglVertexArrayVertexAttribOffsetEXT gglVertexArrayVertexAttribOffsetEXT{ nullptr };
	PgglVertexArrayVertexOffsetEXT gglVertexArrayVertexOffsetEXT{ nullptr };
}

void System
	::GlBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) noexcept
{
	SYSTEM_BODY_3(gglBindMultiTextureEXT, texunit, target, texture);
}

GLenum System
	::GlCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target) noexcept
{
	SYSTEM_BODY_2_RESULT(gglCheckNamedFramebufferStatusEXT, framebuffer, target, GLenum, 0);
}

void System
	::GlClientAttribDefaultEXT(GLbitfield mask) noexcept
{
	SYSTEM_BODY_1(gglClientAttribDefaultEXT, mask);
}

void System
	::GlCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_8(gglCompressedMultiTexImage1DEXT, texunit, target, level, internalformat, width, border, imageSize, data);
}

void System
	::GlCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedMultiTexImage2DEXT, texunit, target, level, internalformat, width, height, border, imageSize, data);
}

void System
	::GlCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width,
									 GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_10(gglCompressedMultiTexImage3DEXT, texunit, target, level, internalformat, width, height, depth, border, imageSize, data);
}

void System
	::GlCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_8(gglCompressedMultiTexSubImage1DEXT, texunit, target, level, xoffset, width, format, imageSize, data);
}

void System
	::GlCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset,
										GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_10(gglCompressedMultiTexSubImage2DEXT, texunit, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void System
	::GlCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
										GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_12(gglCompressedMultiTexSubImage3DEXT, texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void System
	::GlCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_8(gglCompressedTextureImage1DEXT, texture, target, level, internalformat, width, border, imageSize, data);
}

void System
	::GlCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width,
									GLsizei height, GLint border, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_9(gglCompressedTextureImage2DEXT, texture, target, level, internalformat, width, height, border, imageSize, data);
}

void System
	::GlCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width,
									GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_10(gglCompressedTextureImage3DEXT, texture, target, level, internalformat, width, height, depth, border, imageSize, data);
}

void System
	::GlCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_8(gglCompressedTextureSubImage1DEXT, texture, target, level, xoffset, width, format, imageSize, data);
}

void System
	::GlCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset,
									   GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_10(gglCompressedTextureSubImage2DEXT, texture, target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void System
	::GlCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
									   GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept
{
	SYSTEM_BODY_12(gglCompressedTextureSubImage3DEXT, texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void System
	::GlCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) noexcept
{
	SYSTEM_BODY_8(gglCopyMultiTexImage1DEXT, texunit, target, level, internalformat, x, y, width, border);
}

void System
	::GlCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept
{
	SYSTEM_BODY_9(gglCopyMultiTexImage2DEXT, texunit, target, level, internalformat, x, y, width, height, border);
}

void System
	::GlCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_BODY_7(gglCopyMultiTexSubImage1DEXT, texunit, target, level, xoffset, x, y, width);
}

void System
	::GlCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_9(gglCopyMultiTexSubImage2DEXT, texunit, target, level, xoffset, yoffset, x, y, width, height);
}

void System
	::GlCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_10(gglCopyMultiTexSubImage3DEXT, texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void System
	::GlCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) noexcept
{
	SYSTEM_BODY_8(gglCopyTextureImage1DEXT, texture, target, level, internalformat, x, y, width, border);
}

void System
	::GlCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) noexcept
{
	SYSTEM_BODY_9(gglCopyTextureImage2DEXT, texture, target, level, internalformat, x, y, width, height, border);
}

void System
	::GlCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept
{
	SYSTEM_BODY_7(gglCopyTextureSubImage1DEXT, texture, target, level, xoffset, x, y, width);
}

void System
	::GlCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_9(gglCopyTextureSubImage2DEXT, texture, target, level, xoffset, yoffset, x, y, width, height);
}

void System
	::GlCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_10(gglCopyTextureSubImage3DEXT, texture, target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void System
	::GlDisableClientStateIndexedEXT(GLenum array, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglDisableClientStateIndexedEXT, array, index);
}

void System
	::GlDisableClientStateiEXT(GLenum array, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglDisableClientStateiEXT, array, index);
}

void System
	::GlDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglDisableVertexArrayAttribEXT, vaobj, index);
}

void System
	::GlDisableVertexArrayEXT(GLuint vaobj, GLenum array) noexcept
{
	SYSTEM_BODY_2(gglDisableVertexArrayEXT, vaobj, array);
}

void System
	::GlEnableClientStateIndexedEXT(GLenum array, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEnableClientStateIndexedEXT, array, index);
}

void System
	::GlEnableClientStateiEXT(GLenum array, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEnableClientStateiEXT, array, index);
}

void System
	::GlEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) noexcept
{
	SYSTEM_BODY_2(gglEnableVertexArrayAttribEXT, vaobj, index);
}

void System
	::GlEnableVertexArrayEXT(GLuint vaobj, GLenum array) noexcept
{
	SYSTEM_BODY_2(gglEnableVertexArrayEXT, vaobj, array);
}

void System
	::GlFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept
{
	SYSTEM_BODY_3(gglFlushMappedNamedBufferRangeEXT, buffer, offset, length);
}

void System
	::GlFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglFramebufferDrawBufferEXT, framebuffer, mode);
}

void System
	::GlFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs) noexcept
{
	SYSTEM_BODY_3(gglFramebufferDrawBuffersEXT, framebuffer, n, bufs);
}

void System
	::GlFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode) noexcept
{
	SYSTEM_BODY_2(gglFramebufferReadBufferEXT, framebuffer, mode);
}

void System
	::GlGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target) noexcept
{
	SYSTEM_BODY_2(gglGenerateMultiTexMipmapEXT, texunit, target);
}

void System
	::GlGenerateTextureMipmapEXT(GLuint texture, GLenum target) noexcept
{
	SYSTEM_BODY_2(gglGenerateTextureMipmapEXT, texture, target);
}

void System
	::GlGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, void* img) noexcept
{
	SYSTEM_BODY_4(gglGetCompressedMultiTexImageEXT, texunit, target, level, img);
}

void System
	::GlGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint level, void* img) noexcept
{
	SYSTEM_BODY_4(gglGetCompressedTextureImageEXT, texture, target, level, img);
}

void System
	::GlGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble* params) noexcept
{
	SYSTEM_BODY_3(gglGetDoubleIndexedvEXT, target, index, params);
}

void System
	::GlGetDoublei_vEXT(GLenum parameterName, GLuint index, GLdouble* params) noexcept
{
	SYSTEM_BODY_3(gglGetDoublei_vEXT, parameterName, index, params);
}

void System
	::GlGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglGetFloatIndexedvEXT, target, index, params);
}

void System
	::GlGetFloati_vEXT(GLenum parameterName, GLuint index, GLfloat* params) noexcept
{
	SYSTEM_BODY_3(gglGetFloati_vEXT, parameterName, index, params);
}

void System
	::GlGetFramebufferParameterivEXT(GLuint framebuffer, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetFramebufferParameterivEXT, framebuffer, parameterName, param);
}

void System
	::GlGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexEnvfvEXT, texunit, target, parameterName, params);
}

void System
	::GlGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexEnvivEXT, texunit, target, parameterName, params);
}

void System
	::GlGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLdouble* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexGendvEXT, texunit, coord, parameterName, params);
}

void System
	::GlGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexGenfvEXT, texunit, coord, parameterName, params);
}

void System
	::GlGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexGenivEXT, texunit, coord, parameterName, params);
}

void System
	::GlGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept
{
	SYSTEM_BODY_6(gglGetMultiTexImageEXT, texunit, target, level, format, type, pixels);
}

void System
	::GlGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_5(gglGetMultiTexLevelParameterfvEXT, texunit, target, level, parameterName, params);
}

void System
	::GlGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_5(gglGetMultiTexLevelParameterivEXT, texunit, target, level, parameterName, params);
}

void System
	::GlGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexParameterIivEXT, texunit, target, parameterName, params);
}

void System
	::GlGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexParameterIuivEXT, texunit, target, parameterName, params);
}

void System
	::GlGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexParameterfvEXT, texunit, target, parameterName, params);
}

void System
	::GlGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetMultiTexParameterivEXT, texunit, target, parameterName, params);
}

void System
	::GlGetNamedBufferParameterivEXT(GLuint buffer, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedBufferParameterivEXT, buffer, parameterName, params);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetNamedBufferPointervEXT(GLuint buffer, GLenum parameterName, void** params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedBufferPointervEXT, buffer, parameterName, params);
}
#include STSTEM_WARNING_POP

void System
	::GlGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept
{
	SYSTEM_BODY_4(gglGetNamedBufferSubDataEXT, buffer, offset, size, data);
}

void System
	::GlGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedFramebufferAttachmentParameterivEXT, framebuffer, attachment, parameterName, params);
}

void System
	::GlGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedProgramLocalParameterIivEXT, program, target, index, params);
}

void System
	::GlGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedProgramLocalParameterIuivEXT, program, target, index, params);
}

void System
	::GlGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedProgramLocalParameterdvEXT, program, target, index, params);
}

void System
	::GlGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedProgramLocalParameterfvEXT, program, target, index, params);
}

void System
	::GlGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum parameterName, void* programString) noexcept
{
	SYSTEM_BODY_4(gglGetNamedProgramStringEXT, program, target, parameterName, programString);
}

void System
	::GlGetNamedProgramivEXT(GLuint program, GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetNamedProgramivEXT, program, target, parameterName, params);
}

void System
	::GlGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_3(gglGetNamedRenderbufferParameterivEXT, renderbuffer, parameterName, params);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetPointerIndexedvEXT(GLenum target, GLuint index, void** params) noexcept
{
	SYSTEM_BODY_3(gglGetPointerIndexedvEXT, target, index, params);
}

void System
	::GlGetPointeri_vEXT(GLenum parameterName, GLuint index, void** params) noexcept
{
	SYSTEM_BODY_3(gglGetPointeri_vEXT, parameterName, index, params);
}
#include STSTEM_WARNING_POP

void System
	::GlGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels) noexcept
{
	SYSTEM_BODY_6(gglGetTextureImageEXT, texture, target, level, format, type, pixels);
}

void System
	::GlGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_5(gglGetTextureLevelParameterfvEXT, texture, target, level, parameterName, params);
}

void System
	::GlGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_5(gglGetTextureLevelParameterivEXT, texture, target, level, parameterName, params);
}

void System
	::GlGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetTextureParameterIivEXT, texture, target, parameterName, params);
}

void System
	::GlGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum parameterName, GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglGetTextureParameterIuivEXT, texture, target, parameterName, params);
}

void System
	::GlGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum parameterName, GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglGetTextureParameterfvEXT, texture, target, parameterName, params);
}

void System
	::GlGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum parameterName, GLint* params) noexcept
{
	SYSTEM_BODY_4(gglGetTextureParameterivEXT, texture, target, parameterName, params);
}

void System
	::GlGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_4(gglGetVertexArrayIntegeri_vEXT, vaobj, index, parameterName, param);
}

void System
	::GlGetVertexArrayIntegervEXT(GLuint vaobj, GLenum parameterName, GLint* param) noexcept
{
	SYSTEM_BODY_3(gglGetVertexArrayIntegervEXT, vaobj, parameterName, param);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::GlGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum parameterName, void** param) noexcept
{
	SYSTEM_BODY_4(gglGetVertexArrayPointeri_vEXT, vaobj, index, parameterName, param);
}

void System
	::GlGetVertexArrayPointervEXT(GLuint vaobj, GLenum parameterName, void** param) noexcept
{
	SYSTEM_BODY_3(gglGetVertexArrayPointervEXT, vaobj, parameterName, param);
}
#include STSTEM_WARNING_POP

void System
	::GlMapNamedBufferEXT(GLuint buffer, GLenum access) noexcept
{
	SYSTEM_BODY_2(gglMapNamedBufferEXT, buffer, access);
}

void System
	::GlMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept
{
	SYSTEM_BODY_4(gglMapNamedBufferRangeEXT, buffer, offset, length, access);
}

void System
	::GlMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) noexcept
{
	SYSTEM_BODY_7(gglMatrixFrustumEXT, matrixMode, l, r, b, t, n, f);
}

void System
	::GlMatrixLoadIdentityEXT(GLenum matrixMode) noexcept
{
	SYSTEM_BODY_1(gglMatrixLoadIdentityEXT, matrixMode);
}

void System
	::GlMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixLoadTransposedEXT, matrixMode, m);
}

void System
	::GlMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixLoadTransposefEXT, matrixMode, m);
}

void System
	::GlMatrixLoaddEXT(GLenum matrixMode, const GLdouble* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixLoaddEXT, matrixMode, m);
}

void System
	::GlMatrixLoadfEXT(GLenum matrixMode, const GLfloat* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixLoadfEXT, matrixMode, m);
}

void System
	::GlMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixMultTransposedEXT, matrixMode, m);
}

void System
	::GlMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixMultTransposefEXT, matrixMode, m);
}

void System
	::GlMatrixMultdEXT(GLenum matrixMode, const GLdouble* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixMultdEXT, matrixMode, m);
}

void System
	::GlMatrixMultfEXT(GLenum matrixMode, const GLfloat* m) noexcept
{
	SYSTEM_BODY_2(gglMatrixMultfEXT, matrixMode, m);
}

void System
	::GlMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) noexcept
{
	SYSTEM_BODY_7(gglMatrixOrthoEXT, matrixMode, l, r, b, t, n, f);
}

void System
	::GlMatrixPopEXT(GLenum matrixMode) noexcept
{
	SYSTEM_BODY_1(gglMatrixPopEXT, matrixMode);
}

void System
	::GlMatrixPushEXT(GLenum matrixMode) noexcept
{
	SYSTEM_BODY_1(gglMatrixPushEXT, matrixMode);
}

void System
	::GlMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_5(gglMatrixRotatedEXT, matrixMode, angle, x, y, z);
}

void System
	::GlMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_5(gglMatrixRotatefEXT, matrixMode, angle, x, y, z);
}

void System
	::GlMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_4(gglMatrixScaledEXT, matrixMode, x, y, z);
}

void System
	::GlMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_4(gglMatrixScalefEXT, matrixMode, x, y, z);
}

void System
	::GlMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_4(gglMatrixTranslatedEXT, matrixMode, x, y, z);
}

void System
	::GlMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) noexcept
{
	SYSTEM_BODY_4(gglMatrixTranslatefEXT, matrixMode, x, y, z);
}

void System
	::GlMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) noexcept
{
	SYSTEM_BODY_4(gglMultiTexBufferEXT, texunit, target, internalformat, buffer);
}

void System
	::GlMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept
{
	SYSTEM_BODY_5(gglMultiTexCoordPointerEXT, texunit, size, type, stride, pointer);
}

void System
	::GlMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexEnvfEXT, texunit, target, parameterName, param);
}

void System
	::GlMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexEnvfvEXT, texunit, target, parameterName, params);
}

void System
	::GlMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexEnviEXT, texunit, target, parameterName, param);
}

void System
	::GlMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexEnvivEXT, texunit, target, parameterName, params);
}

void System
	::GlMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLdouble param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexGendEXT, texunit, coord, parameterName, param);
}

void System
	::GlMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum parameterName, const GLdouble* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexGendvEXT, texunit, coord, parameterName, params);
}

void System
	::GlMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexGenfEXT, texunit, coord, parameterName, param);
}

void System
	::GlMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum parameterName, const GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexGenfvEXT, texunit, coord, parameterName, params);
}

void System
	::GlMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexGeniEXT, texunit, coord, parameterName, param);
}

void System
	::GlMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexGenivEXT, texunit, coord, parameterName, params);
}

void System
	::GlMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_9(gglMultiTexImage1DEXT, texunit, target, level, internalformat, width, border, format, type, pixels);
}

void System
	::GlMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_10(gglMultiTexImage2DEXT, texunit, target, level, internalformat, width, height, border, format, type, pixels);
}

void System
	::GlMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
						   GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_11(gglMultiTexImage3DEXT, texunit, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void System
	::GlMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexParameterIivEXT, texunit, target, parameterName, params);
}

void System
	::GlMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglMultiTexParameterIuivEXT, texunit, target, parameterName, params);
}

void System
	::GlMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexParameterfEXT, texunit, target, parameterName, param);
}

void System
	::GlMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLfloat* param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexParameterfvEXT, texunit, target, parameterName, param);
}

void System
	::GlMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexParameteriEXT, texunit, target, parameterName, param);
}

void System
	::GlMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum parameterName, const GLint* param) noexcept
{
	SYSTEM_BODY_4(gglMultiTexParameterivEXT, texunit, target, parameterName, param);
}

void System
	::GlMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_3(gglMultiTexRenderbufferEXT, texunit, target, renderbuffer);
}

void System
	::GlMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_8(gglMultiTexSubImage1DEXT, texunit, target, level, xoffset, width, format, type, pixels);
}

void System
	::GlMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_10(gglMultiTexSubImage2DEXT, texunit, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void System
	::GlMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
							  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_12(gglMultiTexSubImage3DEXT, texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);

}

void System
	::GlNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept
{
	SYSTEM_BODY_4(gglNamedBufferDataEXT, buffer, size, data, usage);
}

void System
	::GlNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept
{
	SYSTEM_BODY_4(gglNamedBufferSubDataEXT, buffer, offset, size, data);
}

void System
	::GlNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept
{
	SYSTEM_BODY_5(gglNamedCopyBufferSubDataEXT, readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void System
	::GlNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_4(gglNamedFramebufferRenderbufferEXT, framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void System
	::GlNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_5(gglNamedFramebufferTexture1DEXT, framebuffer, attachment, textarget, texture, level);
}

void System
	::GlNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_5(gglNamedFramebufferTexture2DEXT, framebuffer, attachment, textarget, texture, level);
}

void System
	::GlNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) noexcept
{
	SYSTEM_BODY_6(gglNamedFramebufferTexture3DEXT, framebuffer, attachment, textarget, texture, level, zoffset);
}

void System
	::GlNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_4(gglNamedFramebufferTextureEXT, framebuffer, attachment, texture, level);
}

void System
	::GlNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) noexcept
{
	SYSTEM_BODY_5(gglNamedFramebufferTextureFaceEXT, framebuffer, attachment, texture, level, face);
}

void System
	::GlNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
	SYSTEM_BODY_5(gglNamedFramebufferTextureLayerEXT, framebuffer, attachment, texture, level, layer);
}

void System
	::GlNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_7(gglNamedProgramLocalParameter4dEXT, program, target, index, x, y, z, w);
}

void System
	::GlNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble* params) noexcept
{
	SYSTEM_BODY_4(gglNamedProgramLocalParameter4dvEXT, program, target, index, params);
}

void System
	::GlNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) noexcept
{
	SYSTEM_BODY_7(gglNamedProgramLocalParameter4fEXT, program, target, index, x, y, z, w);
}

void System
	::GlNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat* params) noexcept
{
	SYSTEM_BODY_4(gglNamedProgramLocalParameter4fvEXT, program, target, index, params);
}

void System
	::GlNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept
{
	SYSTEM_BODY_7(gglNamedProgramLocalParameterI4iEXT, program, target, index, x, y, z, w);
}

void System
	::GlNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint* params) noexcept
{
	SYSTEM_BODY_4(gglNamedProgramLocalParameterI4ivEXT, program, target, index, params);
}

void System
	::GlNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept
{
	SYSTEM_BODY_7(gglNamedProgramLocalParameterI4uiEXT, program, target, index, x, y, z, w);
}

void System
	::GlNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglNamedProgramLocalParameterI4uivEXT, program, target, index, params);
}

void System
	::GlNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params) noexcept
{
	SYSTEM_BODY_5(gglNamedProgramLocalParameters4fvEXT, program, target, index, count, params);
}

void System
	::GlNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params) noexcept
{
	SYSTEM_BODY_5(gglNamedProgramLocalParametersI4ivEXT, program, target, index, count, params);

}

void System
	::GlNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params) noexcept
{
	SYSTEM_BODY_5(gglNamedProgramLocalParametersI4uivEXT, program, target, index, count, params);
}

void System
	::GlNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void* programString) noexcept
{
	SYSTEM_BODY_5(gglNamedProgramStringEXT, program, target, format, len, programString);
}

void System
	::GlNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_4(gglNamedRenderbufferStorageEXT, renderbuffer, internalformat, width, height);
}

void System
	::GlNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_6(gglNamedRenderbufferStorageMultisampleCoverageEXT, renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
}

void System
	::GlNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
	SYSTEM_BODY_5(gglNamedRenderbufferStorageMultisampleEXT, renderbuffer, samples, internalformat, width, height);
}

void System
	::GlProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1fEXT, program, location, v0);
}

void System
	::GlProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1fvEXT, program, location, count, value);
}

void System
	::GlProgramUniform1iEXT(GLuint program, GLint location, GLint v0) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1iEXT, program, location, v0);
}

void System
	::GlProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1ivEXT, program, location, count, value);
}

void System
	::GlProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) noexcept
{
	SYSTEM_BODY_3(gglProgramUniform1uiEXT, program, location, v0);
}

void System
	::GlProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform1uivEXT, program, location, count, value);
}

void System
	::GlProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2fEXT, program, location, v0, v1);
}

void System
	::GlProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2fvEXT, program, location, count, value);
}

void System
	::GlProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2iEXT, program, location, v0, v1);
}

void System
	::GlProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2ivEXT, program, location, count, value);
}

void System
	::GlProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2uiEXT, program, location, v0, v1);
}

void System
	::GlProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform2uivEXT, program, location, count, value);
}

void System
	::GlProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3fEXT, program, location, v0, v1, v2);
}

void System
	::GlProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3fvEXT, program, location, count, value);
}

void System
	::GlProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3iEXT, program, location, v0, v1, v2);
}

void System
	::GlProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3ivEXT, program, location, count, value);
}

void System
	::GlProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept
{
	SYSTEM_BODY_5(gglProgramUniform3uiEXT, program, location, v0, v1, v2);
}

void System
	::GlProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform3uivEXT, program, location, count, value);
}

void System
	::GlProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4fEXT, program, location, v0, v1, v2, v3);
}

void System
	::GlProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4fvEXT, program, location, count, value);
}

void System
	::GlProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4iEXT, program, location, v0, v1, v2, v3);
}

void System
	::GlProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4ivEXT, program, location, count, value);
}

void System
	::GlProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept
{
	SYSTEM_BODY_6(gglProgramUniform4iEXT, program, location, v0, v1, v2, v3);
}

void System
	::GlProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint* value) noexcept
{
	SYSTEM_BODY_4(gglProgramUniform4uivEXT, program, location, count, value);
}

void System
	::GlProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2x3fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix2x4fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3x2fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix3x4fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4x2fvEXT, program, location, count, transpose, value);
}

void System
	::GlProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
	SYSTEM_BODY_5(gglProgramUniformMatrix4x3fvEXT, program, location, count, transpose, value);
}

void System
	::GlPushClientAttribDefaultEXT(GLbitfield mask) noexcept
{
	SYSTEM_BODY_1(gglPushClientAttribDefaultEXT, mask);
}

void System
	::GlTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) noexcept
{
	SYSTEM_BODY_4(gglTextureBufferEXT, texture, target, internalformat, buffer);
}

void System
	::GlTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_9(gglTextureImage1DEXT, texture, target, level, internalformat, width, border, format, type, pixels);
}

void System
	::GlTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_10(gglTextureImage2DEXT, texture, target, level, internalformat, width, height, border, format, type, pixels);
}

void System
	::GlTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_11(gglTextureImage3DEXT, texture, target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void System
	::GlTextureParameterIivEXT(GLuint texture, GLenum target, GLenum parameterName, const GLint* params) noexcept
{
	SYSTEM_BODY_4(gglTextureParameterIivEXT, texture, target, parameterName, params);
}

void System
	::GlTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum parameterName, const GLuint* params) noexcept
{
	SYSTEM_BODY_4(gglTextureParameterIuivEXT, texture, target, parameterName, params);
}

void System
	::GlTextureParameterfEXT(GLuint texture, GLenum target, GLenum parameterName, GLfloat param) noexcept
{
	SYSTEM_BODY_4(gglTextureParameterfEXT, texture, target, parameterName, param);
}

void System
	::GlTextureParameterfvEXT(GLuint texture, GLenum target, GLenum parameterName, const GLfloat* param) noexcept
{
	SYSTEM_BODY_4(gglTextureParameterfvEXT, texture, target, parameterName, param);
}

void System
	::GlTextureParameteriEXT(GLuint texture, GLenum target, GLenum parameterName, GLint param) noexcept
{
	SYSTEM_BODY_4(gglTextureParameteriEXT, texture, target, parameterName, param);
}

void System
	::GlTextureParameterivEXT(GLuint texture, GLenum target, GLenum parameterName, const GLint* param) noexcept
{
	SYSTEM_BODY_4(gglTextureParameterivEXT, texture, target, parameterName, param);
}

void System
	::GlTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer) noexcept
{
	SYSTEM_BODY_3(gglTextureRenderbufferEXT, texture, target, renderbuffer);
}

void System
	::GlTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_8(gglTextureSubImage1DEXT, texture, target, level, xoffset, width, format, type, pixels);
}

void System
	::GlTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_10(gglTextureSubImage2DEXT, texture, target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void System
	::GlTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
							 GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
	SYSTEM_BODY_12(gglTextureSubImage3DEXT, texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);

}

GLboolean System
	::GlUnmapNamedBufferEXT(GLuint buffer) noexcept
{
	SYSTEM_BODY_1_RESULT(gglUnmapNamedBufferEXT, buffer, GLboolean, GL_FALSE);
}

void System
	::GlVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_6(gglVertexArrayColorOffsetEXT, vaobj, buffer, size, type, stride, offset);
}

void System
	::GlVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_4(gglVertexArrayEdgeFlagOffsetEXT, vaobj, buffer, stride, offset);
}

void System
	::GlVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_5(gglVertexArrayFogCoordOffsetEXT, vaobj, buffer, type, stride, offset);
}

void System
	::GlVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_5(gglVertexArrayIndexOffsetEXT, vaobj, buffer, type, stride, offset);
}

void System
	::GlVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_7(gglVertexArrayMultiTexCoordOffsetEXT, vaobj, buffer, texunit, size, type, stride, offset);
}

void System
	::GlVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_5(gglVertexArrayNormalOffsetEXT, vaobj, buffer, type, stride, offset);
}

void System
	::GlVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_6(gglVertexArraySecondaryColorOffsetEXT, vaobj, buffer, size, type, stride, offset);
}

void System
	::GlVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_6(gglVertexArrayTexCoordOffsetEXT, vaobj, buffer, size, type, stride, offset);
}

void System
	::GlVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor) noexcept
{
	SYSTEM_BODY_3(gglVertexArrayVertexAttribDivisorEXT, vaobj, index, divisor);
}

void System
	::GlVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_7(gglVertexArrayVertexAttribIOffsetEXT, vaobj, buffer, index, size, type, stride, offset);
}

void System
	::GlVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_8(gglVertexArrayVertexAttribOffsetEXT, vaobj, buffer, index, size, type, normalized, stride, offset);
}
void System
	::GlVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_6(gglVertexArrayVertexOffsetEXT, vaobj, buffer, size, type, stride, offset);
}

void System
	::InitGlExtDirectStateAccess() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_direct_state_access"))
	{
		g_ExistsGlExtDirectStateAccess = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindMultiTextureEXT);
		SYSTEM_GET_FUNCTION(gglCheckNamedFramebufferStatusEXT);
		SYSTEM_GET_FUNCTION(gglClientAttribDefaultEXT);
		SYSTEM_GET_FUNCTION(gglCompressedMultiTexImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedMultiTexImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedMultiTexImage3DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedMultiTexSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedMultiTexSubImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedMultiTexSubImage3DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedTextureImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedTextureImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedTextureImage3DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedTextureSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedTextureSubImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCompressedTextureSubImage3DEXT);
		SYSTEM_GET_FUNCTION(gglCopyMultiTexImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCopyMultiTexImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCopyMultiTexSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCopyMultiTexSubImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCopyMultiTexSubImage3DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTextureImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTextureImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTextureSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTextureSubImage2DEXT);
		SYSTEM_GET_FUNCTION(gglCopyTextureSubImage3DEXT);
		SYSTEM_GET_FUNCTION(gglDisableClientStateIndexedEXT);
		SYSTEM_GET_FUNCTION(gglDisableClientStateiEXT);
		SYSTEM_GET_FUNCTION(gglDisableVertexArrayAttribEXT);
		SYSTEM_GET_FUNCTION(gglDisableVertexArrayEXT);
		SYSTEM_GET_FUNCTION(gglEnableClientStateIndexedEXT);
		SYSTEM_GET_FUNCTION(gglEnableClientStateiEXT);
		SYSTEM_GET_FUNCTION(gglEnableVertexArrayAttribEXT);
		SYSTEM_GET_FUNCTION(gglEnableVertexArrayEXT);
		SYSTEM_GET_FUNCTION(gglFlushMappedNamedBufferRangeEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferDrawBufferEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferDrawBuffersEXT);
		SYSTEM_GET_FUNCTION(gglFramebufferReadBufferEXT);
		SYSTEM_GET_FUNCTION(gglGenerateMultiTexMipmapEXT);
		SYSTEM_GET_FUNCTION(gglGenerateTextureMipmapEXT);
		SYSTEM_GET_FUNCTION(gglGetCompressedMultiTexImageEXT);
		SYSTEM_GET_FUNCTION(gglGetCompressedTextureImageEXT);
		SYSTEM_GET_FUNCTION(gglGetDoubleIndexedvEXT);
		SYSTEM_GET_FUNCTION(gglGetDoublei_vEXT);
		SYSTEM_GET_FUNCTION(gglGetFloatIndexedvEXT);
		SYSTEM_GET_FUNCTION(gglGetFloati_vEXT);
		SYSTEM_GET_FUNCTION(gglGetFramebufferParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexEnvfvEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexEnvivEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexGendvEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexGenfvEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexGenivEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexImageEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexLevelParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexLevelParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexParameterIuivEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglGetMultiTexParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferPointervEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedBufferSubDataEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedFramebufferAttachmentParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedProgramLocalParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedProgramLocalParameterIuivEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedProgramLocalParameterdvEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedProgramLocalParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedProgramStringEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedProgramivEXT);
		SYSTEM_GET_FUNCTION(gglGetNamedRenderbufferParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetPointerIndexedvEXT);
		SYSTEM_GET_FUNCTION(gglGetPointeri_vEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureImageEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureLevelParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureLevelParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterIuivEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglGetTextureParameterivEXT);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayIntegeri_vEXT);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayIntegervEXT);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayPointeri_vEXT);
		SYSTEM_GET_FUNCTION(gglGetVertexArrayPointervEXT);
		SYSTEM_GET_FUNCTION(gglMapNamedBufferEXT);
		SYSTEM_GET_FUNCTION(gglMapNamedBufferRangeEXT);
		SYSTEM_GET_FUNCTION(gglMatrixFrustumEXT);
		SYSTEM_GET_FUNCTION(gglMatrixLoadIdentityEXT);
		SYSTEM_GET_FUNCTION(gglMatrixLoadTransposedEXT);
		SYSTEM_GET_FUNCTION(gglMatrixLoadTransposefEXT);
		SYSTEM_GET_FUNCTION(gglMatrixLoaddEXT);
		SYSTEM_GET_FUNCTION(gglMatrixLoadfEXT);
		SYSTEM_GET_FUNCTION(gglMatrixMultTransposedEXT);
		SYSTEM_GET_FUNCTION(gglMatrixMultTransposefEXT);
		SYSTEM_GET_FUNCTION(gglMatrixMultdEXT);
		SYSTEM_GET_FUNCTION(gglMatrixMultfEXT);
		SYSTEM_GET_FUNCTION(gglMatrixOrthoEXT);
		SYSTEM_GET_FUNCTION(gglMatrixPopEXT);
		SYSTEM_GET_FUNCTION(gglMatrixPushEXT);
		SYSTEM_GET_FUNCTION(gglMatrixRotatedEXT);
		SYSTEM_GET_FUNCTION(gglMatrixRotatefEXT);
		SYSTEM_GET_FUNCTION(gglMatrixScaledEXT);
		SYSTEM_GET_FUNCTION(gglMatrixScalefEXT);
		SYSTEM_GET_FUNCTION(gglMatrixTranslatedEXT);
		SYSTEM_GET_FUNCTION(gglMatrixTranslatefEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexBufferEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexCoordPointerEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexEnvfEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexEnvfvEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexEnviEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexEnvivEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexGendEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexGendvEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexGenfEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexGenfvEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexGeniEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexGenivEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexImage1DEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexImage2DEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexImage3DEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexParameterIuivEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexParameterfEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexParameteriEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexParameterivEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexRenderbufferEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexSubImage2DEXT);
		SYSTEM_GET_FUNCTION(gglMultiTexSubImage3DEXT);
		SYSTEM_GET_FUNCTION(gglNamedBufferDataEXT);
		SYSTEM_GET_FUNCTION(gglNamedBufferSubDataEXT);
		SYSTEM_GET_FUNCTION(gglNamedCopyBufferSubDataEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferRenderbufferEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTexture1DEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTexture2DEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTexture3DEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTextureEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTextureFaceEXT);
		SYSTEM_GET_FUNCTION(gglNamedFramebufferTextureLayerEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameter4dEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameter4dvEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameter4fEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameter4fvEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameterI4iEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameterI4ivEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameterI4uiEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameterI4uivEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParameters4fvEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParametersI4ivEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramLocalParametersI4uivEXT);
		SYSTEM_GET_FUNCTION(gglNamedProgramStringEXT);
		SYSTEM_GET_FUNCTION(gglNamedRenderbufferStorageEXT);
		SYSTEM_GET_FUNCTION(gglNamedRenderbufferStorageMultisampleCoverageEXT);
		SYSTEM_GET_FUNCTION(gglNamedRenderbufferStorageMultisampleEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform1fEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform1fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform1iEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform1ivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform1uiEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform1uivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform2fEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform2fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform2iEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform2ivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform2uiEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform2uivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform3fEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform3fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform3iEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform3ivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform3uiEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform3uivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform4fEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform4fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform4iEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform4ivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform4uiEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniform4uivEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2x3fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix2x4fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3x2fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix3x4fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4x2fvEXT);
		SYSTEM_GET_FUNCTION(gglProgramUniformMatrix4x3fvEXT);
		SYSTEM_GET_FUNCTION(gglPushClientAttribDefaultEXT);
		SYSTEM_GET_FUNCTION(gglTextureBufferEXT);
		SYSTEM_GET_FUNCTION(gglTextureImage1DEXT);
		SYSTEM_GET_FUNCTION(gglTextureImage2DEXT);
		SYSTEM_GET_FUNCTION(gglTextureImage3DEXT);
		SYSTEM_GET_FUNCTION(gglTextureParameterIivEXT);
		SYSTEM_GET_FUNCTION(gglTextureParameterIuivEXT);
		SYSTEM_GET_FUNCTION(gglTextureParameterfEXT);
		SYSTEM_GET_FUNCTION(gglTextureParameterfvEXT);
		SYSTEM_GET_FUNCTION(gglTextureParameteriEXT);
		SYSTEM_GET_FUNCTION(gglTextureParameterivEXT);
		SYSTEM_GET_FUNCTION(gglTextureRenderbufferEXT);
		SYSTEM_GET_FUNCTION(gglTextureSubImage1DEXT);
		SYSTEM_GET_FUNCTION(gglTextureSubImage2DEXT);
		SYSTEM_GET_FUNCTION(gglTextureSubImage3DEXT);
		SYSTEM_GET_FUNCTION(gglUnmapNamedBufferEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayColorOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayEdgeFlagOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayFogCoordOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayIndexOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayMultiTexCoordOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayNormalOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArraySecondaryColorOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayTexCoordOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexAttribDivisorEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexAttribIOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexAttribOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexOffsetEXT); 
	}
	else
	{
		g_ExistsGlExtDirectStateAccess = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 354) GL_EXT_vertex_array_bgra

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtVertexArrayBgra{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtVertexArrayBgra() noexcept
{
	return g_ExistsGlExtVertexArrayBgra;
}

void System
	::InitGlExtVertexArrayBgra() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_vertex_array_bgra"))
	{
		g_ExistsGlExtVertexArrayBgra = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtVertexArrayBgra = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 356) GL_EXT_texture_swizzle

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureSwizzle{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureSwizzle() noexcept
{
	return g_ExistsGlExtTextureSwizzle;
}

void System
	::InitGlExtTextureSwizzle() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_swizzle"))
	{
		g_ExistsGlExtTextureSwizzle = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureSwizzle = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 364) GL_EXT_provoking_vertex

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtProvokingVertex{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtProvokingVertex() noexcept
{
	return g_ExistsGlExtProvokingVertex;
}

namespace System
{
	using PgglProvokingVertexEXT = void (OPENGL_STDCALL*) (GLenum mode);
}

namespace System
{
	PgglProvokingVertexEXT gglProvokingVertexEXT{ nullptr };
}

void System
	::GlProvokingVertexEXT(GLenum mode) noexcept
{
	SYSTEM_BODY_1(gglProvokingVertexEXT, mode);
}

void System
	::InitGlExtProvokingVertex() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_provoking_vertex"))
	{
		g_ExistsGlExtProvokingVertex = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglProvokingVertexEXT);
	}
	else
	{
		g_ExistsGlExtProvokingVertex = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 365) GL_EXT_texture_snorm

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureSnorm{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureSnorm() noexcept
{
	return g_ExistsGlExtTextureSnorm;
}

void System
	::InitGlExtTextureSnorm() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_snorm"))
	{
		g_ExistsGlExtTextureSnorm = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureSnorm = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 377) GL_EXT_separate_shader_objects

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSeparateShaderObjects{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSeparateShaderObjects() noexcept
{
	return g_ExistsGlExtSeparateShaderObjects;
}

namespace System
{
	using PgglActiveProgramEXT = void (OPENGL_STDCALL*) (GLuint program);
	using PgglCreateShaderProgramEXT = GLuint(OPENGL_STDCALL*) (GLenum type, const GLchar* string);
	using PgglUseShaderProgramEXT = void (OPENGL_STDCALL*) (GLenum type, GLuint program);
}

namespace System
{
	PgglActiveProgramEXT gglActiveProgramEXT{ nullptr };
	PgglCreateShaderProgramEXT gglCreateShaderProgramEXT{ nullptr };
	PgglUseShaderProgramEXT gglUseShaderProgramEXT{ nullptr };
}

void System
	::GlActiveProgramEXT(GLuint program) noexcept
{
	SYSTEM_BODY_1(gglActiveProgramEXT, program);
}

GLuint System
	::GlCreateShaderProgramEXT(GLenum type, const GLchar* programString) noexcept
{
	SYSTEM_BODY_2_RESULT(gglCreateShaderProgramEXT, type, programString, GLuint, 0);
}

void System
	::GlUseShaderProgramEXT(GLenum type, GLuint program) noexcept
{
	SYSTEM_BODY_2(gglUseShaderProgramEXT, type, program);
}

void System
	::InitGlExtSeparateShaderObjects() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_separate_shader_objects"))
	{
		g_ExistsGlExtSeparateShaderObjects = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglActiveProgramEXT);
		SYSTEM_GET_FUNCTION(gglCreateShaderProgramEXT);
		SYSTEM_GET_FUNCTION(gglUseShaderProgramEXT);
	}
	else
	{
		g_ExistsGlExtSeparateShaderObjects = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 386) GL_EXT_shader_image_load_store

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtShaderImageLoadStore{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtShaderImageLoadStore() noexcept
{
	return g_ExistsGlExtShaderImageLoadStore;
}

namespace System
{
	using PgglBindImageTextureEXT = void (OPENGL_STDCALL*) (GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
	using PgglMemoryBarrierEXT = void (OPENGL_STDCALL*) (GLbitfield barriers);
}

namespace System
{
	PgglBindImageTextureEXT gglBindImageTextureEXT{ nullptr };
	PgglMemoryBarrierEXT gglMemoryBarrierEXT{ nullptr };
}

void System
	::GlBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) noexcept
{
	SYSTEM_BODY_7(gglBindImageTextureEXT, index, texture, level, layered, layer, access, format);
}

void System
	::GlMemoryBarrierEXT(GLbitfield barriers) noexcept
{
	SYSTEM_BODY_1(gglMemoryBarrierEXT, barriers);
}

void System
	::InitGlExtShaderImageLoadStore() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_shader_image_load_store"))
	{
		g_ExistsGlExtShaderImageLoadStore = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglBindImageTextureEXT);
		SYSTEM_GET_FUNCTION(gglMemoryBarrierEXT);
	}
	else
	{
		g_ExistsGlExtShaderImageLoadStore = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 387) GL_EXT_vertex_attrib_64bit

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtVertexAttrib64bit{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtVertexAttrib64bit() noexcept
{
	return g_ExistsGlExtVertexAttrib64bit;
}

namespace System
{
	using PgglGetVertexAttribLdvEXT = void (OPENGL_STDCALL*)(GLuint index, GLenum parameterName, GLdouble* params);
	using PgglVertexArrayVertexAttribLOffsetEXT = void (OPENGL_STDCALL*) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	using PgglVertexAttribL1dEXT = void (OPENGL_STDCALL*)(GLuint index, GLdouble x);
	using PgglVertexAttribL1dvEXT = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribL2dEXT = void (OPENGL_STDCALL*) (GLuint index, GLdouble x, GLdouble y);
	using PgglVertexAttribL2dvEXT = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribL3dEXT = void (OPENGL_STDCALL*)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	using PgglVertexAttribL3dvEXT = void (OPENGL_STDCALL*)(GLuint index, const GLdouble* v);
	using PgglVertexAttribL4dEXT = void (OPENGL_STDCALL*)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	using PgglVertexAttribL4dvEXT = void (OPENGL_STDCALL*) (GLuint index, const GLdouble* v);
	using PgglVertexAttribLPointerEXT = void (OPENGL_STDCALL*)(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
}

namespace System
{
	PgglGetVertexAttribLdvEXT gglGetVertexAttribLdvEXT{ nullptr };
	PgglVertexArrayVertexAttribLOffsetEXT gglVertexArrayVertexAttribLOffsetEXT{ nullptr };
	PgglVertexAttribL1dEXT gglVertexAttribL1dEXT{ nullptr };
	PgglVertexAttribL1dvEXT gglVertexAttribL1dvEXT{ nullptr };
	PgglVertexAttribL2dEXT gglVertexAttribL2dEXT{ nullptr };
	PgglVertexAttribL2dvEXT gglVertexAttribL2dvEXT{ nullptr };
	PgglVertexAttribL3dEXT gglVertexAttribL3dEXT{ nullptr };
	PgglVertexAttribL3dvEXT gglVertexAttribL3dvEXT{ nullptr };
	PgglVertexAttribL4dEXT gglVertexAttribL4dEXT{ nullptr };
	PgglVertexAttribL4dvEXT gglVertexAttribL4dvEXT{ nullptr };
	PgglVertexAttribLPointerEXT gglVertexAttribLPointerEXT{ nullptr };
}

void System
	::GlGetVertexAttribLdvEXT(GLuint index, GLenum parameterName, GLdouble* params) noexcept
{
	SYSTEM_BODY_3(gglGetVertexAttribLdvEXT, index, parameterName, params);
}

void System
	::GlVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) noexcept
{
	SYSTEM_BODY_7(gglVertexArrayVertexAttribLOffsetEXT, vaobj, buffer, index, size, type, stride, offset);
}

void System
	::GlVertexAttribL1dEXT(GLuint index, GLdouble x) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL1dEXT, index, x);
}

void System
	::GlVertexAttribL1dvEXT(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL1dvEXT, index, v);
}

void System
	::GlVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y) noexcept
{
	SYSTEM_BODY_3(gglVertexAttribL2dEXT, index, x, y);
}

void System
	::GlVertexAttribL2dvEXT(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL2dvEXT, index, v);
}

void System
	::GlVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z) noexcept
{
	SYSTEM_BODY_4(gglVertexAttribL3dEXT, index, x, y, z);
}

void System
	::GlVertexAttribL3dvEXT(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL3dvEXT, index, v);
}

void System
	::GlVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribL4dEXT, index, x, y, z, w);
}

void System
	::GlVertexAttribL4dvEXT(GLuint index, const GLdouble* v) noexcept
{
	SYSTEM_BODY_2(gglVertexAttribL4dvEXT, index, v);
}

void System
	::GlVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept
{
	SYSTEM_BODY_5(gglVertexAttribLPointerEXT, index, size, type, stride, pointer);
}

void System
	::InitGlExtVertexAttrib64bit() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_vertex_attrib_64bit"))
	{
		g_ExistsGlExtVertexAttrib64bit = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetVertexAttribLdvEXT);
		SYSTEM_GET_FUNCTION(gglVertexArrayVertexAttribLOffsetEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL1dEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL1dvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL2dEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL2dvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL3dEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL3dvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL4dEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribL4dvEXT);
		SYSTEM_GET_FUNCTION(gglVertexAttribLPointerEXT);
	}
	else
	{
		g_ExistsGlExtVertexAttrib64bit = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 402) GL_EXT_texture_sRGB_decode

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureSRGBDecode{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureSRGBDecode() noexcept
{
	return g_ExistsGlExtTextureSRGBDecode;
}

void System
	::InitGlExtTextureSRGBDecode() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_sRGB_decode"))
	{
		g_ExistsGlExtTextureSRGBDecode = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureSRGBDecode = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 406) GL_EXT_x11_sync_object

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtX11SynObject{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtX11SynObject() noexcept
{
	return g_ExistsGlExtX11SynObject;
}

namespace System
{
	using PgglImportSyncEXT = GLsync(OPENGL_STDCALL*) (GLenum externalSyncType, GLintptr externalSync, GLbitfield flags);
}

namespace System
{
	PgglImportSyncEXT gglImportSyncEXT{ nullptr };
}

GLsync System
	::GlImportSyncEXT(GLenum externalSyncType, GLintptr externalSync, GLbitfield flags) noexcept
{
	SYSTEM_BODY_3_RESULT(gglImportSyncEXT, externalSyncType, externalSync, flags, GLsync, nullptr);
}

void System
	::InitGlExtX11SynObject() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_x11_sync_object"))
	{
		g_ExistsGlExtX11SynObject = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglImportSyncEXT);
	}
	else
	{
		g_ExistsGlExtX11SynObject = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 409) GL_EXT_framebuffer_multisample_blit_scaled

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtFramebufferMultisampleBlitScaled{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtFramebufferMultisampleBlitScaled() noexcept
{
	return g_ExistsGlExtFramebufferMultisampleBlitScaled;
}

void System
	::InitGlExtFramebufferMultisampleBlitScaled() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_framebuffer_multisample_blit_scaled"))
	{
		g_ExistsGlExtFramebufferMultisampleBlitScaled = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtFramebufferMultisampleBlitScaled = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 437) GL_EXT_shader_integer_mix

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtShaderIntegerMix{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtShaderIntegerMix() noexcept
{
	return g_ExistsGlExtShaderIntegerMix;
}

void System
	::InitGlExtShaderIntegerMix() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_shader_integer_mix"))
	{
		g_ExistsGlExtShaderIntegerMix = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtShaderIntegerMix = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 439) GL_EXT_debug_label
namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDebugLabel{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDebugLabel() noexcept
{
	return g_ExistsGlExtDebugLabel;
}

namespace System
{
	using PgglGetObjectLabelEXT = void (OPENGL_STDCALL*) (GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label);
	using PgglLabelObjectEXT = void (OPENGL_STDCALL*) (GLenum type, GLuint object, GLsizei length, const GLchar* label);
}

namespace System
{
	PgglGetObjectLabelEXT gglGetObjectLabelEXT{ nullptr };
	PgglLabelObjectEXT gglLabelObjectEXT{ nullptr };
}

void System
	::GlGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label) noexcept
{
	SYSTEM_BODY_5(gglGetObjectLabelEXT, type, object, bufSize, length, label);
}

void System
	::GlLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label) noexcept
{
	SYSTEM_BODY_4(gglLabelObjectEXT, type, object, length, label);
}

void System
	::InitGlExtDebugLabel() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_debug_label"))
	{
		g_ExistsGlExtDebugLabel = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetObjectLabelEXT);
		SYSTEM_GET_FUNCTION(gglLabelObjectEXT);
	}
	else
	{
		g_ExistsGlExtDebugLabel = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 440) GL_EXT_debug_marker

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtDebugMarker{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtDebugMarker() noexcept
{
	return g_ExistsGlExtDebugMarker;
}

namespace System
{
	using PgglInsertEventMarkerEXT = void (OPENGL_STDCALL*) (GLsizei length, const GLchar* marker);
	using PgglPopGroupMarkerEXT = void (OPENGL_STDCALL*)(void);
	using PgglPushGroupMarkerEXT = void (OPENGL_STDCALL*) (GLsizei length, const GLchar* marker);
}

namespace System
{
	PgglInsertEventMarkerEXT gglInsertEventMarkerEXT{ nullptr };
	PgglPopGroupMarkerEXT gglPopGroupMarkerEXT{ nullptr };
	PgglPushGroupMarkerEXT gglPushGroupMarkerEXT{ nullptr };
}

void System
	::GlInsertEventMarkerEXT(GLsizei length, const GLchar* marker) noexcept
{
	SYSTEM_BODY_2(gglInsertEventMarkerEXT, length, marker);
}

void System
	::GlPopGroupMarkerEXT(void) noexcept
{
	SYSTEM_BODY_0(gglPopGroupMarkerEXT);
}

void System
	::GlPushGroupMarkerEXT(GLsizei length, const GLchar* marker) noexcept
{
	SYSTEM_BODY_2(gglPushGroupMarkerEXT, length, marker);
}

void System
	::InitGlExtDebugMarker() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_debug_marker"))
	{
		g_ExistsGlExtDebugMarker = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglInsertEventMarkerEXT);
		SYSTEM_GET_FUNCTION(gglPopGroupMarkerEXT);
		SYSTEM_GET_FUNCTION(gglPushGroupMarkerEXT);
	}
	else
	{
		g_ExistsGlExtDebugMarker = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 449) GL_EXT_shader_image_load_formatted

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtShaderImageLoadFormatted{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtShaderImageLoadFormatted() noexcept
{
	return g_ExistsGlExtShaderImageLoadFormatted;
}

void System
	::InitGlExtShaderImageLoadFormatted() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_shader_image_load_formatted"))
	{
		g_ExistsGlExtShaderImageLoadFormatted = ExistsOpenGLExtensions::Exists;

	}
	else
	{
		g_ExistsGlExtShaderImageLoadFormatted = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 460) GL_EXT_polygon_offset_clamp

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPolygonOffsetClamp{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPolygonOffsetClamp() noexcept
{
	return g_ExistsGlExtPolygonOffsetClamp;
}

namespace System
{
	using PgglPolygonOffsetClampEXT = void (OPENGL_STDCALL*) (GLfloat factor, GLfloat units, GLfloat clamp);
}

namespace System
{
	PgglPolygonOffsetClampEXT gglPolygonOffsetClampEXT{ nullptr };
}

void System
	::GlPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp) noexcept
{
	SYSTEM_BODY_3(gglPolygonOffsetClampEXT, factor, units, clamp);
}

void System
	::InitGlExtPolygonOffsetClamp() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_polygon_offset_clamp"))
	{
		g_ExistsGlExtPolygonOffsetClamp = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglPolygonOffsetClampEXT);
	}
	else
	{
		g_ExistsGlExtPolygonOffsetClamp = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 461) GL_EXT_post_depth_coverage

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtPostDepthCoverage{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtPostDepthCoverage() noexcept
{
	return g_ExistsGlExtPostDepthCoverage;
}

void System
	::InitGlExtPostDepthCoverage() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_post_depth_coverage"))
	{
		g_ExistsGlExtPostDepthCoverage = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtPostDepthCoverage = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 462) GL_EXT_raster_multisample

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtRasterMultisample{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtRasterMultisample() noexcept
{
	return g_ExistsGlExtRasterMultisample;
}

namespace System
{
	using PgglCoverageModulationNV = void (OPENGL_STDCALL*)(GLenum components);
	using PgglCoverageModulationTableNV = void (OPENGL_STDCALL*) (GLsizei n, const GLfloat* v);
	using PgglGetCoverageModulationTableNV = void (OPENGL_STDCALL*)(GLsizei bufsize, GLfloat* v);
	using PgglRasterSamplesEXT = void (OPENGL_STDCALL*) (GLuint samples, GLboolean fixedsamplelocations);
}

namespace System
{
	PgglCoverageModulationNV gglCoverageModulationNV{ nullptr };
	PgglCoverageModulationTableNV gglCoverageModulationTableNV{ nullptr };
	PgglGetCoverageModulationTableNV gglGetCoverageModulationTableNV{ nullptr };
	PgglRasterSamplesEXT gglRasterSamplesEXT{ nullptr };
}

void System
	::GlCoverageModulationNV(GLenum components) noexcept
{
	SYSTEM_BODY_1(gglCoverageModulationNV, components);
}

void System
	::GlCoverageModulationTableNV(GLsizei n, const GLfloat* v) noexcept
{
	SYSTEM_BODY_2(gglCoverageModulationTableNV, n, v);
}

void System
	::GlGetCoverageModulationTableNV(GLsizei bufsize, GLfloat* v) noexcept
{
	SYSTEM_BODY_2(gglGetCoverageModulationTableNV, bufsize, v);
}

void System
	::GlRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations) noexcept
{
	SYSTEM_BODY_2(gglRasterSamplesEXT, samples, fixedsamplelocations);
}

void System
	::InitGlExtRasterMultisample() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_raster_multisample"))
	{
		g_ExistsGlExtRasterMultisample = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglCoverageModulationNV);
		SYSTEM_GET_FUNCTION(gglCoverageModulationTableNV);
		SYSTEM_GET_FUNCTION(gglGetCoverageModulationTableNV);
		SYSTEM_GET_FUNCTION(gglRasterSamplesEXT);
	}
	else
	{
		g_ExistsGlExtRasterMultisample = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 463) GL_EXT_sparse_texture2

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtSparseTexture2{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtSparseTexture2() noexcept
{
	return g_ExistsGlExtSparseTexture2;
}

void System
	::InitGlExtSparseTexture2() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_sparse_texture2"))
	{
		g_ExistsGlExtSparseTexture2 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtSparseTexture2 = ExistsOpenGLExtensions::NotExist;
	}
}

// (EXT 464) GL_EXT_texture_filter_minmax

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtTextureFilterMinmax{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtTextureFilterMinmax() noexcept
{
	return g_ExistsGlExtTextureFilterMinmax;
}

void System
	::InitGlExtFilterMinmax() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_texture_filter_minmax"))
	{
		g_ExistsGlExtTextureFilterMinmax = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtTextureFilterMinmax = ExistsOpenGLExtensions::NotExist;
	}
}

// GL_EXT_Cg_shader

namespace System
{
	ExistsOpenGLExtensions g_ExistsGlExtCgShader{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsGlExtCgShader() noexcept
{
	return g_ExistsGlExtCgShader;
}

void System
	::InitGlExtCgShader() noexcept
{
	if (IsOpenGLSupportsExtension("GL_EXT_Cg_shader"))
	{
		g_ExistsGlExtCgShader = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsGlExtCgShader = ExistsOpenGLExtensions::NotExist;
	}
}

void System
	::InitGlExt() noexcept
{
	InitGlExtABGR();
	InitGlExtBlendColor();
	InitGlExtPolygonOffset();
	InitGlExtTexture();
	InitGlExtTexture3D();
	InitGlExtSubtexture();
	InitGlExtCopyTexture();
	InitGlExtHistogram();
	InitGlExtConvolution();
	InitGlExtCMYKA();
	InitGlExtTextureObject();
	InitGlExtPackedPixels();
	InitGlExtRescaleNormal();
	InitGlExtVertexArray();
	InitGlExtMiscAttribute();
	InitGlExtTextureEdgeClamp();
	InitGlExtBlendMinMax();
	InitGlExtBlendSubtract();
	InitGlExtBlendLogicOp();
	InitGlExtPointParameters();
	InitGlExtColorSubtable();
	InitGlExtPalettedTexture();
	InitGlExtClipVolumeHint();
	InitGlExtIndexTexture();
	InitGlExtIndexMaterial();
	InitGlExtIndexFunc();
	InitGlExtIndexArrayFormats();
	InitGlExtCompiledVertexArray();
	InitGlExtCullVertex();
	InitGlExtFragmentLighting();
	InitGlExtDrawRangeElements();
	InitGlExtLightTexture();
	InitGlExtSceneMarker();
	InitGlExtBGRA();
	InitGlExtPixelTransform();
	InitGlExtPixelTransformColorTable();
	InitGlExtSharedTexturePalette();
	InitGlExtSeparateSpecularColor();
	InitGlExtSecondaryColor();
	InitGlExtTextureEnv();
	InitGlExtTexturePerturbNormal();
	InitGlExtMultidrawArrays();
	InitGlExtFogCoord();
	InitGlExtCoordinateFrame();
	InitGlExtTextureEnvCombine();
	InitGlExtBlendFuncSeparate();
	InitGlExtStencilWrap();
	InitGlExt422Pixels();
	InitGlExtTextureCubeMap();
	InitGlExtTextureEnvAdd();
	InitGlExtTextureLodBias();
	InitGlExtTextureFilterAnisotropic();
	InitGlExtVertexWeighting();
	InitGlExtTextureCompressionS3TC();
	InitGlExtMultisample();
	InitGlExtTextureEnvDot3();
	InitGlExtTextureRectangle();
	InitGlExtVertexShader();
	InitGlExtShadowFuncs();
	InitGlExtStencilTwoSide();
	InitGlExtDepthBoundsTest();
	InitGlExtTextureMirrorClamp();
	InitGlExtBlendEquationSeparate();
	InitGlExtPixelBufferObject();
	InitGlExtTextureCompressionDXT1();
	InitGlExtFrameBufferObject();
	InitGlExtPackedDepthStencil();
	InitGlExtStencilClearTag();
	InitGlExtTextureSRGB();
	InitGlExtFrameBufferBlit();
	InitGlExtFrameBufferMultisample();
	InitGlExtTimerQuery();
	InitGlExtGpuProgramParameters();
	InitGlExtGeometryShader4();
	InitGlExtGpuShader4();
	InitGlExtDrawInstanced();
	InitGlExtPackedFloat();
	InitGlExtTextureArray();
	InitGlExtTextureBufferObject();
	InitGlExtTextureCompressionLatc();
	InitGlExtTextureCompressionRgtc();
	InitGlExtTextureSharedExponent();
	InitGlExtFramebufferSRGB();
	InitGlExtDrawBuffers2();
	InitGlExtBindableUniform();
	InitGlExtTextureInteger();
	InitGlExtTransformFeedback();
	InitGlExtDirectStateAccess();
	InitGlExtVertexArrayBgra();
	InitGlExtTextureSwizzle();
	InitGlExtProvokingVertex();
	InitGlExtTextureSnorm();
	InitGlExtSeparateShaderObjects();
	InitGlExtShaderImageLoadStore();
	InitGlExtVertexAttrib64bit();
	InitGlExtTextureSRGBDecode();
	InitGlExtX11SynObject();
	InitGlExtFramebufferMultisampleBlitScaled();
	InitGlExtShaderIntegerMix();
	InitGlExtDebugLabel();
	InitGlExtDebugMarker();
	InitGlExtShaderImageLoadFormatted();
	InitGlExtPolygonOffsetClamp();
	InitGlExtPostDepthCoverage();
	InitGlExtRasterMultisample();
	InitGlExtSparseTexture2();
	InitGlExtFilterMinmax();
	InitGlExtCgShader();
}



