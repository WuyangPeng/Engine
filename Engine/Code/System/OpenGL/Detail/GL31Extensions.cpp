// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:44)

#include "System/SystemExport.h"

#include "GL31Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/Using/GL31ExtensionsUsing.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 3.1

namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL31{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL31() noexcept
{
	return g_ExistsOpenGL31;
}

System::PgglDrawArraysInstanced System::gglDrawArraysInstanced{ nullptr };
System::PgglDrawElementsInstanced System::gglDrawElementsInstanced{ nullptr };
System::PgglTexBuffer System::gglTexBuffer{ nullptr };
System::PgglPrimitiveRestartIndex System::gglPrimitiveRestartIndex{ nullptr };

void System
	::GlDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount) noexcept
{
	SYSTEM_BODY_4(gglDrawArraysInstanced, mode, first, count, primcount);
}

void System
	::GlDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices, GLsizei primcount) noexcept
{
	SYSTEM_BODY_5(gglDrawElementsInstanced, mode, count, type, indices, primcount);
}

void System
	::GlTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) noexcept
{
	SYSTEM_BODY_3(gglTexBuffer, target, internalformat, buffer);
}

void System
	::GlPrimitiveRestartIndex(GLuint index) noexcept
{
	SYSTEM_BODY_1(gglPrimitiveRestartIndex, index);
}

void System
	::InitOpenGL31() noexcept
{
	if (System::OpenGLSystemVersion::Version31 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL31 = ExistsOpenGLExtensions::Exists;

		SYSTEM_GET_FUNCTION(gglDrawArraysInstanced);
		SYSTEM_GET_FUNCTION(gglDrawElementsInstanced);
		SYSTEM_GET_FUNCTION(gglTexBuffer);
		SYSTEM_GET_FUNCTION(gglPrimitiveRestartIndex);
	}
	else
	{
		g_ExistsOpenGL31 = ExistsOpenGLExtensions::NotExist;
	}
}
