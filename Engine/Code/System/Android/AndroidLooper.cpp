//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 23:13)

#include "System/SystemExport.h"

#include "AndroidLooper.h"
#include "Flags/AndroidLooperFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowProcess.h"

System::AndroidLooper* System::AndroidLooperForThread() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_forThread();
#else  // !SYSTEM_PLATFORM_ANDROID
    return nullptr;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooper* System::AndroidLooperPrepare([[maybe_unused]] int opts) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_prepare(opts);
#else  // !SYSTEM_PLATFORM_ANDROID
    static AndroidLooper s_AndroidLooper;

    return &s_AndroidLooper;
#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidLooperAcquire([[maybe_unused]] AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_acquire(looper);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidLooperRelease([[maybe_unused]] AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_release(looper);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooperEvent System::AndroidLooperPollOnce([[maybe_unused]] int timeoutMillis, [[maybe_unused]] int* outFd, [[maybe_unused]] int* outEvents, [[maybe_unused]] void** outData) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_pollOnce(timeoutMillis, outFd, outEvents, outData);
#else  // !SYSTEM_PLATFORM_ANDROID
    return AndroidLooperEvent::Input;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooperEvent System::AndroidLooperPollAll([[maybe_unused]] int timeoutMillis, [[maybe_unused]] int* outFd, [[maybe_unused]] int* outEvents, [[maybe_unused]] void** outData) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_pollAll(timeoutMillis, outFd, outEvents, outData);
#elif defined(SYSTEM_PLATFORM_WIN32)

    WindowMsg msg{};

    if (PeekSystemMessage(&msg))
    {
        auto success = TranslateSystemMessage(&msg);
        success = DispatchSystemMessage(&msg);

        return AndroidLooperEvent::Input;
    }
    else
    {
        return UnderlyingCastEnum<AndroidLooperEvent>(-1);
    }

#else  // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32
    return AndroidLooperEventInput;
#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidLooperWake([[maybe_unused]] AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_wake(looper);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidLooperAddFd([[maybe_unused]] AndroidLooper* looper, [[maybe_unused]] int fd, [[maybe_unused]] LooperID ident, [[maybe_unused]] AndroidLooperEvent events, [[maybe_unused]] AndroidLooperCallbackFunc callback, [[maybe_unused]] void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_addFd(looper, fd, ident, events, callback, data);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 1;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidLooperRemoveFd([[maybe_unused]] AndroidLooper* looper, [[maybe_unused]] int fd) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return ALooper_removeFd(looper, fd);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 1;
#endif  // SYSTEM_PLATFORM_ANDROID
}
