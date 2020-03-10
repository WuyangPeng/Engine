// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:45)

#include "System/SystemExport.h"

#include "GL42Extensions.h"
#include "GLUtility.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"

// OpenGL 4.2
namespace System
{
	ExistsOpenGLExtensions g_ExistsOpenGL42{ ExistsOpenGLExtensions::Unknown };
}

System::ExistsOpenGLExtensions System
	::IsExistsOpenGL42() noexcept
{
	return g_ExistsOpenGL42;
}

void System
	::InitOpenGL42() noexcept
{
	if (System::OpenGLSystemVersion::Version42 <= System::GetOpenGLVersion())
	{
		g_ExistsOpenGL42 = ExistsOpenGLExtensions::Exists;
	}
	else
	{
		g_ExistsOpenGL42 = ExistsOpenGLExtensions::NotExist;
	}
}