// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:25)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/looper.h>

namespace System
{
	using AndroidLooper = ALooper;
	using AndroidLooperCallbackFunc = ALooper_callbackFunc;
}

#else // !SYSTEM_PLATFORM_ANDROID

namespace System
{
	struct AndroidLooper
	{

	};

	using AndroidLooperCallbackFunc = int(*)(int fd, int events, void* data);
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_LOOPER_TYPEDEF_H
