///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/10 10:34)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
#define CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    T AtomicMin(std::atomic<T>& atomic, const T& value) noexcept;

    template <typename T>
    T AtomicMax(std::atomic<T>& atomic, const T& value) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
