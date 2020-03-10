// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:23)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_USING_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_USING_H

#include "System/Helper/Platform.h" 

namespace System
{	
#ifdef SYSTEM_PLATFORM_WIN32	

	using MemoryResourceNotificationType = MEMORY_RESOURCE_NOTIFICATION_TYPE; 

#else // !SYSTEM_PLATFORM_WIN32	

	enum MemoryResourceNotificationType 
	{
		LowMemoryResourceNotification,
		HighMemoryResourceNotification,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_USING_H