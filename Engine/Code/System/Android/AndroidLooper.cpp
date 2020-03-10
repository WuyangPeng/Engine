// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:03)

#include "System/SystemExport.h"

#include "AndroidLooper.h"
#include "Flags/AndroidLooperFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowProcess.h"
#include "System/EnumOperator/EnumCastDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
System::AndroidLooper* System
	::AndroidLooperForThread() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_forThread();
#else // !SYSTEM_PLATFORM_ANDROID
	return nullptr;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooper* System
	::AndroidLooperPrepare(int opts) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_prepare(opts);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(opts);

	static AndroidLooper s_AndroidLooper;

	return &s_AndroidLooper;
#endif // SYSTEM_PLATFORM_ANDROID
}

void System
	::AndroidLooperAcquire(AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_acquire(looper);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(looper);
#endif // SYSTEM_PLATFORM_ANDROID
}

void System
	::AndroidLooperRelease(AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_release(looper);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(looper);
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooperEvent System
	::AndroidLooperPollOnce(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_pollOnce(timeoutMillis, outFd, outEvents, outData);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(timeoutMillis);
	SYSTEM_UNUSED_ARG(outFd);
	SYSTEM_UNUSED_ARG(outEvents);
	SYSTEM_UNUSED_ARG(outData);

	return AndroidLooperEvent::Input;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooperEvent System
	::AndroidLooperPollAll(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_pollAll(timeoutMillis, outFd, outEvents, outData);

#elif defined(SYSTEM_PLATFORM_WIN32)

	SYSTEM_UNUSED_ARG(timeoutMillis);
	SYSTEM_UNUSED_ARG(outFd);
	SYSTEM_UNUSED_ARG(outEvents);
	SYSTEM_UNUSED_ARG(outData);

	WindowMsg msg{};

	if (PeekSystemMessage(&msg))
	{
		TranslateSystemMessage(&msg);
		DispatchSystemMessage(&msg);

		return AndroidLooperEvent::Input;
	}
	else
	{
		return UnderlyingCastEnum<AndroidLooperEvent>(-1);
	}

#else // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timeoutMillis);
	SYSTEM_UNUSED_ARG(outFd);
	SYSTEM_UNUSED_ARG(outEvents);
	SYSTEM_UNUSED_ARG(outData);

	return AndroidLooperEventInput;
#endif // SYSTEM_PLATFORM_ANDROID
}

void System
	::AndroidLooperWake(AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_wake(looper);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(looper);
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidLooperAddFd(AndroidLooper* looper, int fd, LooperID ident, AndroidLooperEvent events, AndroidLooperCallbackFunc callback, void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_addFd(looper, fd, ident, events, callback, data);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(looper);
	SYSTEM_UNUSED_ARG(fd);
	SYSTEM_UNUSED_ARG(ident);
	SYSTEM_UNUSED_ARG(events);
	SYSTEM_UNUSED_ARG(callback);
	SYSTEM_UNUSED_ARG(data);

	return 1;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidLooperRemoveFd(AndroidLooper* looper, int fd) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return ALooper_removeFd(looper, fd);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(looper);
	SYSTEM_UNUSED_ARG(fd);

	return 1;
#endif // SYSTEM_PLATFORM_ANDROID
}
#include STSTEM_WARNING_POP
