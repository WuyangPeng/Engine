// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 10:59)

#ifndef SYSTEM_THREADING_INIT_ONCE_FLAGS_H
#define SYSTEM_THREADING_INIT_ONCE_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	enum class InitOnceBeginInitialize
	{
		CheckOnly = INIT_ONCE_CHECK_ONLY,
		Async = INIT_ONCE_ASYNC,
		InitFailed = INIT_ONCE_INIT_FAILED,
	};

#else // !SYSTEM_PLATFORM_WIN32	

	enum class InitOnceBeginInitialize
	{
		CheckOnly = 0x00000001UL,
		Async = 0x00000002UL,
		InitFailed = 0x00000004UL,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_INIT_ONCE_FLAGS_H