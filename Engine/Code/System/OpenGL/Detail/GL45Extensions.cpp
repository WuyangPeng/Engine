// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GL45Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL45ExtensionsUsing.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 4.5
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL45{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL45() noexcept
{
	return g_ExistsOpenGL45;
}

System::PgglGetGraphicsResetStatus System::gglGetGraphicsResetStatus{ nullptr };
System::PgglGetnCompressedTexImage System::gglGetnCompressedTexImage{ nullptr };
System::PgglGetnTexImage System::gglGetnTexImage{ nullptr };
System::PgglGetnUniformdv System::gglGetnUniformdv{ nullptr };

GLenum System
	::GlGetGraphicsResetStatus() noexcept
{
	SYSTEM_BODY_A0_RESULT(gglGetGraphicsResetStatus, GLenum, EnumCastUnderlying<GLenum>(OpenGLErrorCode::InvalidValue));
}

void System
	::GlGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, GLvoid* pixels) noexcept
{
	SYSTEM_BODY_A4(gglGetnCompressedTexImage, target, lod, bufSize, pixels);
}

void System
	::GlGetnTexImage(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept
{
	SYSTEM_BODY_A6(gglGetnTexImage, tex, level, format, type, bufSize, pixels);
}

void System
	::GlGetnUniformdv(GLenum tex, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid* pixels) noexcept
{
	SYSTEM_BODY_A6(gglGetnUniformdv, tex, level, format, type, bufSize, pixels);
}

void System
	::InitOpenGL45() noexcept
{
	if (System::OpenGLSystemVersion::Version45 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL45 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglGetGraphicsResetStatus);
		SYSTEM_GET_FUNCTION(gglGetnCompressedTexImage);
		SYSTEM_GET_FUNCTION(gglGetnTexImage);
		SYSTEM_GET_FUNCTION(gglGetnUniformdv);
	}
	else
	{
		g_ExistsOpenGL45 = ExistsOpenGLExtensions::NotExist;
	}
}