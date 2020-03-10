// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GL33Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL33ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 3.3
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL33{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL33() noexcept
{
	return g_ExistsOpenGL33;
}

System::PgglVertexAttribDivisor System::gglVertexAttribDivisor{ nullptr };

void System
	::GlVertexAttribDivisor(GLuint index, GLuint divisor) noexcept
{
	SYSTEM_BODY_A2(gglVertexAttribDivisor, index, divisor);
}

void System
	::InitOpenGL33() noexcept
{
	if (System::OpenGLSystemVersion::Version33 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL33 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglVertexAttribDivisor);
	}
	else
	{
		g_ExistsOpenGL33 = ExistsOpenGLExtensions::NotExist;
	}
}