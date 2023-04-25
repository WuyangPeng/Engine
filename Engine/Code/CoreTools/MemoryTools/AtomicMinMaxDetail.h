///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 10:35)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H

#include "AtomicMinMax.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
T CoreTools::AtomicMin(std::atomic<T>& atomic, const T& value) noexcept
{
    T initial{};
    T min{};

    do
    {
        initial = atomic;
        min = std::min(initial, value);
    } while (!std::atomic_compare_exchange_strong(&atomic, &initial, min));

    return initial;
}

template <typename T>
T CoreTools::AtomicMax(std::atomic<T>& atomic, const T& value) noexcept
{
    T initial{};
    T max{};

    do
    {
        initial = atomic;
        max = std::max(initial, value);
    } while (!std::atomic_compare_exchange_strong(&atomic, &initial, max));

    return initial;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H
