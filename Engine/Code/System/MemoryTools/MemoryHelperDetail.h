///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 16:37)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H

#include "MemoryHelper.h"

template <typename T>
requires(std::is_trivial_v<T> && std::is_standard_layout_v<T>)
void System::FillMemoryToZero(T& value) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::ZeroMemory(&value, sizeof(T));

#else  // !SYSTEM_PLATFORM_WIN32

    memset(&value, 0, sizeof(T));

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_DETAIL_H