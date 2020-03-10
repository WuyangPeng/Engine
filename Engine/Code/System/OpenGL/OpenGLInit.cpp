// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:49)

#include "System/SystemExport.h"

#include "OpenGLInit.h"
#include "Detail/GLExtensions.h"
#include "Detail/WglExtensions.h"
#include "Detail/GlxExtensions.h" 

bool System
	::OpenGLInit()
{
#ifdef SYSTEM_PLATFORM_WIN32
	return InitWGL();
#elif defined(SYSTEM_PLATFORM_LINUX)
    return InitGLX();
#else // !SYSTEM_PLATFORM_WIN32 && !SYSTEM_PLATFORM_LINUX
	return InitGL();
#endif // SYSTEM_PLATFORM_WIN32
}
 