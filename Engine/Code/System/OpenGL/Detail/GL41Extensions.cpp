// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GL41Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 4.1

namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL41{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL41() noexcept
{
	return g_ExistsOpenGL41;
}

void System
	::InitOpenGL41() noexcept
{
	if (System::OpenGLSystemVersion::Version41 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL41 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsOpenGL41 = ExistsOpenGLExtensions::NotExist;
	}
}