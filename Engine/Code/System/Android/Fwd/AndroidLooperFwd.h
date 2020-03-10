// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:21)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_FWD_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_FWD_H 

#include "AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidLooperUsing.h"

namespace System
{
	AndroidLooper* AndroidLooperForThread() noexcept;
	AndroidLooper* AndroidLooperPrepare(int opts) noexcept;

	void AndroidLooperAcquire(AndroidLooper* looper) noexcept;
	void AndroidLooperRelease(AndroidLooper* looper) noexcept;

	AndroidLooperEvent AndroidLooperPollOnce(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept;
	AndroidLooperEvent AndroidLooperPollAll(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept;
	void AndroidLooperWake(AndroidLooper* looper) noexcept;
	int AndroidLooperAddFd(AndroidLooper* looper, int fd, LooperID ident, AndroidLooperEvent events, AndroidLooperCallbackFunc callback, void* data) noexcept;
	int AndroidLooperRemoveFd(AndroidLooper* looper, int fd) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_LOOPER_FWD_H