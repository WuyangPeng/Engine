// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:44)

#include "System/SystemExport.h"

#include "GL32Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL32ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 3.2
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL32{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL32() noexcept
{
	return g_ExistsOpenGL32;
}

System::PgglGetInteger64i_v System::gglGetInteger64i_v{ nullptr };
System::PgglGetBufferParameteri64v System::gglGetBufferParameteri64v{ nullptr };
System::PgglProgramParameteri System::gglProgramParameteri{ nullptr };
System::PgglFramebufferTexture System::gglFramebufferTexture{ nullptr };

void System
	::GlGetInteger64i_v(GLenum target, GLuint index, GLint64* data) noexcept
{
	SYSTEM_BODY_A3(gglGetInteger64i_v, target, index, data);
}

void System
	::GlGetBufferParameteri64v(GLenum target, GLenum name, GLint64* params) noexcept
{
	SYSTEM_BODY_A3(gglGetBufferParameteri64v, target, name, params);
}

void System
	::GlProgramParameteri(GLuint program, GLenum name, GLint value) noexcept
{
	SYSTEM_BODY_A3(gglProgramParameteri, program, name, value);
}

void System
	::GlFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) noexcept
{
	SYSTEM_BODY_A4(gglFramebufferTexture, target, attachment, texture, level);
}

void System
	::InitOpenGL32() noexcept
{
	if (System::OpenGLSystemVersion::Version32 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL32 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetInteger64i_v);
		SYSTEM_GET_FUNCTION(gglGetBufferParameteri64v);
		SYSTEM_GET_FUNCTION(gglProgramParameteri);
		SYSTEM_GET_FUNCTION(gglFramebufferTexture);
	}
	else
	{
		g_ExistsOpenGL32 = ExistsOpenGLExtensions::NotExist;
	}
}