//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:57)

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
    static_assert(std::is_nothrow_default_constructible_v<T>);

    T result{};

    result.cbSize = sizeof(T);

    return result;
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H