// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GL40Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL40ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 4.0
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL40{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL40() noexcept
{
	return g_ExistsOpenGL40;
}

System::PgglBlendEquationSeparatei System::gglBlendEquationSeparatei{ nullptr };
System::PgglBlendEquationi System::gglBlendEquationi{ nullptr };
System::PgglBlendFuncSeparatei System::gglBlendFuncSeparatei{ nullptr };
System::PgglBlendFunci System::gglBlendFunci{ nullptr };
System::PgglMinSampleShading System::gglMinSampleShading{ nullptr };

void System
	::GlBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) noexcept
{
	SYSTEM_BODY_A3(gglBlendEquationSeparatei, buf, modeRGB, modeAlpha);
}

void System
	::GlBlendEquationi(GLuint buf, GLenum mode) noexcept
{
	SYSTEM_BODY_A2(gglBlendEquationi, buf, mode);
}

void System
	::GlBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) noexcept
{
	SYSTEM_BODY_A5(gglBlendFuncSeparatei, buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void System
	::GlBlendFunci(GLuint buf, GLenum src, GLenum dst) noexcept
{
	SYSTEM_BODY_A3(gglBlendFunci, buf, src, dst);
}

void System
	::GlMinSampleShading(GLclampf value) noexcept
{
	SYSTEM_BODY_A1(gglMinSampleShading, value);
}

void System
	::InitOpenGL40() noexcept
{
	if (System::OpenGLSystemVersion::Version40 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL40 = ExistsOpenGLExtensions::Exists;

		// GL_ARB_draw_buffers_blend
		SYSTEM_GET_FUNCTION(gglBlendEquationSeparatei);
		SYSTEM_GET_FUNCTION(gglBlendEquationi);
		SYSTEM_GET_FUNCTION(gglBlendFuncSeparatei);
		SYSTEM_GET_FUNCTION(gglBlendFunci);

		// GL_ARB_sample_shading
		SYSTEM_GET_FUNCTION(gglMinSampleShading);
	}
	else
	{
		g_ExistsOpenGL40 = ExistsOpenGLExtensions::NotExist;
	}
}


