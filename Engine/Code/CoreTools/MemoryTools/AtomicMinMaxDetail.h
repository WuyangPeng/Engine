/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/14 10:52)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H

#include "AtomicMinMax.h"

/// ��ĳЩƽ̨�ϣ�atomic_compare_exchange_weak�����ܾ�˵��ʹ��atomic_compare_exchange_strongҪ�á�
/// atomic_compare_exchange_weak�ıȽϺͽ������ܻ������ٹ��ϣ�
/// ��ʹ*x��*y��ֵ��ͬ������Ҳ�᷵��false�������ڴ�ϵͳ��Ӳ���ܹ����⡣
/// ��AtomicMin��AtomicMax�Ĵ����У����۱Ƚϻ������ʧ�ܻᵼ��std::atomic_compare_exchange_weak����false��
/// ѭ������ȷ���ٴγ��Խ��бȽϺͽ�����

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