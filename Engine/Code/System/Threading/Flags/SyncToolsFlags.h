// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:06)

#ifndef SYSTEM_THREADING_SYNC_TOOLS_FLAGS_H
#define SYSTEM_THREADING_SYNC_TOOLS_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	enum class SleepReturn
	{
		Succeed = 0,
		WaitIOCompletion = WAIT_IO_COMPLETION,
	};

#else // !SYSTEM_PLATFORM_WIN32		

	enum class SleepReturn
	{
		Succeed = 0,
		WaitIOCompletion = 0x000000C0L,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_SYNC_TOOLS_FLAGS_H