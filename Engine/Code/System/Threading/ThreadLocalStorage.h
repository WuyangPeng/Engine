//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:29)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H

#include "System/SystemDll.h"

#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 线程局部存储

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE ThreadLocalStorageAlloc() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsThreadLocalStorageValid(WindowDWord threadLocalStorageIndex) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex, WindowVoidPtr threadLocalStorageValue) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ThreadLocalStorageFree(WindowDWord threadLocalStorageIndex) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H