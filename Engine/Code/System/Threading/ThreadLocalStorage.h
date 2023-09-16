///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:21)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H

#include "System/SystemDll.h"

#include "System/Windows/Using/WindowsUsing.h"

// �ֲ߳̾��洢
namespace System
{
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE ThreadLocalStorageAlloc() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsThreadLocalStorageValid(WindowsDWord threadLocalStorageIndex) noexcept;
    MAYBE_NULLPTR WindowsVoidPtr SYSTEM_DEFAULT_DECLARE GetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetThreadLocalStorageValue(WindowsDWord threadLocalStorageIndex, WindowsVoidPtr threadLocalStorageValue) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ThreadLocalStorageFree(WindowsDWord threadLocalStorageIndex) noexcept;
}

#endif  // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H