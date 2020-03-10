// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:20)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_FLAGS_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_FLAGS_H

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/looper.h>

namespace System
{
	enum class AndroidLooperPrepareAllow
	{
		AllowNonCallbacks = ALOOPER_PREPARE_ALLOW_NON_CALLBACKS
	};

	enum class AndroidLooperPoll
	{
		Wake = ALOOPER_POLL_WAKE,
		Callback = ALOOPER_POLL_CALLBACK,
		Timeout = ALOOPER_POLL_TIMEOUT,
		Error = ALOOPER_POLL_ERROR,
	};

	// AndroidLooper
	enum class AndroidLooperEvent
	{
		Input = ALOOPER_EVENT_INPUT,
		Output = ALOOPER_EVENT_OUTPUT,
		Error = ALOOPER_EVENT_ERROR,
		Hangup = ALOOPER_EVENT_HANGUP,
		Invalid = ALOOPER_EVENT_INVALID,
	};
}

#else // !SYSTEM_PLATFORM_ANDROID

namespace System
{
	enum class AndroidLooperPrepareAllow
	{
		AllowNonCallbacks = 1 << 0
	};

	enum class AndroidLooperPoll
	{
		Wake = -1,
		Callback = -2,
		Timeout = -3,
		Error = -4,
	};

	enum class AndroidLooperEvent
	{
		Input = 1 << 0,
		Output = 1 << 1,
		Error = 1 << 2,
		Hangup = 1 << 3,
		Invalid = 1 << 4,
	};
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_LOOPER_FLAGS_H
