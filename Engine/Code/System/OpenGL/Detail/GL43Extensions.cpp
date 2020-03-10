// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GL43Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 4.3
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL43{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL43() noexcept
{
	return g_ExistsOpenGL43;
}

void System
	::InitOpenGL43() noexcept
{
	if (System::OpenGLSystemVersion::Version43 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL43 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsOpenGL43 = ExistsOpenGLExtensions::NotExist;
	}
}