///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/19 13:45)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H

#include "MemoryHelper.h"

template <typename T>
void System::FillMemoryToZero(T& value) noexcept
{
    static_assert(std::is_pod_v<T>);

    ::ZeroMemory(&value, sizeof(T));
}

template <typename T>
T System::GetWindowsStructDefaultSize() noexcept
{
    static_assert(std::is_nothrow_default_constructible_v<T> && std::is_nothrow_copy_constructible_v<T> && std::is_nothrow_move_constructible_v<T>);

    T result{};

    result.cbSize = sizeof(T);

    return result;
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H