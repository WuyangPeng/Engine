/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:20)

#include "System/SystemExport.h"

#include "AndroidLooper.h"
#include "Flags/AndroidLooperFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
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

    WindowsMessage msg{};

    if (PeekSystemMessage(&msg))
    {
        TranslateSystemMessage(&msg);
        DispatchSystemMessage(&msg);

        return AndroidLooperEvent::Input;
    }
    else
    {
        return AndroidLooperEvent::Null;
    }

#else  // !SYSTEM_PLATFORM_ANDROID && !SYSTEM_PLATFORM_WIN32

    return AndroidLooperEvent::Input;

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

int32_t System::AndroidLooperAddFileDescriptor(AndroidLooper* looper, int32_t fileDescriptor, LooperId ident, AndroidLooperEvent events, AndroidLooperCallbackFunction callback, void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_addFd(looper, fileDescriptor, ident, events, callback, data);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper, fileDescriptor, ident, events, callback, data);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidLooperRemoveFd(AndroidLooper* looper, int32_t fd) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return ALooper_removeFd(looper, fd);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper, fd);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}
