///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/11 14:26)

#ifndef SYSTEM_ANDROID_ANDROID_LOOPER_H
#define SYSTEM_ANDROID_ANDROID_LOOPER_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidLooperUsing.h"

namespace System
{
    NODISCARD SYSTEM_DEFAULT_DECLARE AndroidLooper* AndroidLooperForThread() noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE AndroidLooper* AndroidLooperPrepare(int32_t opts) noexcept;

    void SYSTEM_DEFAULT_DECLARE AndroidLooperAcquire(AndroidLooper* looper) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidLooperRelease(AndroidLooper* looper) noexcept;

    NODISCARD AndroidLooperEvent SYSTEM_DEFAULT_DECLARE AndroidLooperPollOnce(int32_t timeoutMillis, int32_t* outFd, int32_t* outEvents, void** outData) noexcept;
    NODISCARD AndroidLooperEvent SYSTEM_DEFAULT_DECLARE AndroidLooperPollAll(int32_t timeoutMillis, int32_t* outFd, int32_t* outEvents, void** outData) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidLooperWake(AndroidLooper* looper) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidLooperAddFd(AndroidLooper* looper, int32_t fd, LooperID ident, AndroidLooperEvent events, AndroidLooperCallbackFunc callback, void* data) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidLooperRemoveFd(AndroidLooper* looper, int32_t fd) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_LOOPER_H
