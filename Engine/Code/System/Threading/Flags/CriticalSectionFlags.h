// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:06)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_FLAGS_H
#define SYSTEM_THREADING_CRITICAL_SECTION_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	enum class CriticalSectionInfo
	{
		Default = 0x00000000,
		NoDebugInfo = CRITICAL_SECTION_NO_DEBUG_INFO,
	};

#else // !SYSTEM_PLATFORM_WIN32	

	enum class CriticalSectionInfo
	{
		Default = 0x00000000,
		NoDebugInfo = 0x01000000,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_CRITICAL_SECTION_FLAGS_H