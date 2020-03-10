// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:30)

#ifndef SYSTEM_THREADING_DELTA_TIME_USING_H
#define SYSTEM_THREADING_DELTA_TIME_USING_H  

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_MACOS	
	#include <sys/time.h>
#else // !SYSTEM_PLATFORM_MACOS	
	#include <sys/timeb.h>
	#ifdef SYSTEM_PLATFORM_WIN32
		#include <cstdlib>
	#endif // SYSTEM_PLATFORM_WIN32
#endif // SYSTEM_PLATFORM_MACOS

namespace System
{
#ifdef SYSTEM_PLATFORM_MACOS	
	using DeltaTimeValue = timeval;
	using DeltaTimeB = timeval;
#else // !SYSTEM_PLATFORM_MACOS	
	struct DeltaTimeValue
	{
		int64_t tv_sec;
		int32_t tv_usec;
	};

	using DeltaTimeB = timeb;
#endif // SYSTEM_PLATFORM_MACOS

	constexpr auto g_Microseconds = 1000000;
	constexpr auto g_Millisecond = 1000;
}

#endif // SYSTEM_THREADING_DELTA_TIME_USING_H