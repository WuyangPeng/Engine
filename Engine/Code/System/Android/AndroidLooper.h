//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 18:44)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidLooperUsing.h"

namespace System
{
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE AndroidLooper* AndroidLooperForThread() noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE AndroidLooper* AndroidLooperPrepare(int opts) noexcept;

    void SYSTEM_DEFAULT_DECLARE AndroidLooperAcquire(AndroidLooper* looper) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidLooperRelease(AndroidLooper* looper) noexcept;

    [[nodiscard]] AndroidLooperEvent SYSTEM_DEFAULT_DECLARE AndroidLooperPollOnce(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept;
    [[nodiscard]] AndroidLooperEvent SYSTEM_DEFAULT_DECLARE AndroidLooperPollAll(int timeoutMillis, int* outFd, int* outEvents, void** outData) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidLooperWake(AndroidLooper* looper) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidLooperAddFd(AndroidLooper* looper, int fd, LooperID ident, AndroidLooperEvent events, AndroidLooperCallbackFunc callback, void* data) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidLooperRemoveFd(AndroidLooper* looper, int fd) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_LOOPER_H
