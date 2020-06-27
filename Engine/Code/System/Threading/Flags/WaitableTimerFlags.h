// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:01)

#ifndef SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H
#define SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	enum class CreateWaitableTimerReset
	{
		CheckOnly = CREATE_WAITABLE_TIMER_MANUAL_RESET,
		Default = 0x00000000,
	};

	enum class WaitableTimerSpecificAccess
	{
		Default = 0x0000,
		ModifyState = TIMER_MODIFY_STATE,
		AllAccess = TIMER_ALL_ACCESS,
		QueryState = TIMER_QUERY_STATE,
	};

#else // !SYSTEM_PLATFORM_WIN32	

	enum class CreateWaitableTimerReset
	{
		CheckOnly = 0x00000001,
		Default = 0x00000000,
	};

	enum class WaitableTimerSpecificAccess
	{
		Default = 0x0000,
		ModifyState = 0x0002,
		AllAccess = 0x000F0000L | 0x00100000L | 0x3,
		QueryState = 0x0001,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_WAITABLE_TIMER_FLAGS_H