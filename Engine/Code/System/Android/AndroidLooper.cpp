///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 23:01)

#include "System/SystemExport.h"

#include "AndroidLooper.h"
#include "Flags/AndroidLooperFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsProcess.h"

System::AndroidLooper* System::AndroidLooperForThread() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_forThread();

#else  // !SYSTEM_PLATFORM_ANDROID

    return nullptr;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooper* System::AndroidLooperPrepare(int32_t opts) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_prepare(opts);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(opts);

    return nullptr;

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidLooperAcquire(AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_acquire(looper);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper);

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidLooperRelease(AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_release(looper);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper);

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooperEvent System::AndroidLooperPollOnce(int32_t timeoutMillis, int32_t* outFd, int32_t* outEvents, void** outData) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_pollOnce(timeoutMillis, outFd, outEvents, outData);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(timeoutMillis, outFd, outEvents, outData);

    return AndroidLooperEvent::Input;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidLooperEvent System::AndroidLooperPollAll(int32_t timeoutMillis, int32_t* outFd, int32_t* outEvents, void** outData) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_pollAll(timeoutMillis, outFd, outEvents, outData);

#elif defined(SYSTEM_PLATFORM_WIN32)

    UnusedFunction(timeoutMillis, outFd, outEvents, outData);

    WindowsMsg msg{};

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

void System::AndroidLooperWake(AndroidLooper* looper) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_wake(looper);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper);

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidLooperAddFd(AndroidLooper* looper, int32_t fd, LooperID ident, AndroidLooperEvent events, AndroidLooperCallbackFunc callback, void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_addFd(looper, fd, ident, events, callback, data);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper, fd, ident, events, callback, data);

    return 1;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidLooperRemoveFd(AndroidLooper* looper, int32_t fd) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_removeFd(looper, fd);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper, fd);

    return 1;

#endif  // SYSTEM_PLATFORM_ANDROID
}
