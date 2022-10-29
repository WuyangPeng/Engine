///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:05)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H

#include "System/SystemDll.h"

#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 线程局部存储

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE ThreadLocalStorageAlloc() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsThreadLocalStorageValid(WindowsDWord threadLocalStorageIndex) noexcept;
    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE GetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex, WindowsVoidPtr threadLocalStorageValue) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ThreadLocalStorageFree(WindowsDWord threadLocalStorageIndex) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H