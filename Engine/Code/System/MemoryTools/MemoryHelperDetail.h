/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:30)

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