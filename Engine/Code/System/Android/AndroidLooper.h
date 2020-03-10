// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:27)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidLooperUsing.h"

namespace System
{
	SYSTEM_DEFAULT_DECLARE AndroidLooper* AndroidLooperForThread() noexcept;
	SYSTEM_DEFAULT_DECLARE AndroidLooper* AndroidLooperPrepare(int opts) noexcept;

	void SYSTEM_DEFAULT_DECLARE AndroidLooperAcquire(AndroidLooper* looper) noexcept;
	void SYSTEM_DEFAULT_DECLARE AndroidLooperRelease(AndroidLooper* looper) noexcept;

	AndroidLooperEvent SYSTEM_DEFAULT_DECLARE AndroidLooperPollOnce(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept;
	AndroidLooperEvent SYSTEM_DEFAULT_DECLARE AndroidLooperPollAll(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept;
	void SYSTEM_DEFAULT_DECLARE AndroidLooperWake(AndroidLooper* looper) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidLooperAddFd(AndroidLooper* looper, int fd, LooperID ident, AndroidLooperEvent events, AndroidLooperCallbackFunc callback, void* data) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidLooperRemoveFd(AndroidLooper* looper, int fd) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_LOOPER_H
