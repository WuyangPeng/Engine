/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:15)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H

#include "System/SystemDll.h"

#include "Flags/ThreadLocalStorageFlags.h"
#include "System/Windows/Using/WindowsUsing.h"

/// �ֲ߳̾��洢
namespace System
{
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE ThreadLocalStorageAlloc() noexcept;
    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE GetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex, WindowsVoidPtr threadLocalStorageValue) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ThreadLocalStorageFree(WindowsDWord threadLocalStorageIndex) noexcept;

    NODISCARD constexpr bool IsThreadLocalStorageValid(const WindowsDWord threadLocalStorageIndex) noexcept
    {
        return threadLocalStorageIndex != EnumCastUnderlying<WindowsDWord>(ThreadLocalStorageIndexes::OutOfIndexes);
    }
}

#endif  // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H