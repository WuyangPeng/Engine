/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/14 10:52)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H

#include "AtomicMinMax.h"

/// 在某些平台上，atomic_compare_exchange_weak的性能据说比使用atomic_compare_exchange_strong要好。
/// atomic_compare_exchange_weak的比较和交换可能会出现虚假故障，
/// 即使*x和*y的值相同，函数也会返回false，这是内存系统的硬件架构问题。
/// 在AtomicMin和AtomicMax的代码中，无论比较或者虚假失败会导致std::atomic_compare_exchange_weak返回false，
/// 循环都会确保再次尝试进行比较和交换。

template <typename T>
T CoreTools::AtomicMin(std::atomic<T>& atomic, const T& value) noexcept
{
    T initial{};
    T min{};

    do
    {
        initial = atomic;
        min = std::min(initial, value);

    } while (!std::atomic_compare_exchange_weak(&atomic, &initial, min));

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

    } while (!std::atomic_compare_exchange_weak(&atomic, &initial, max));

    return initial;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H