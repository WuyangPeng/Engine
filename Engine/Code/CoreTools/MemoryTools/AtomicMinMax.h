///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:33)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H
#define CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    // ��������ʱ��atomic = min(atomic,value)������ֵ�Ǵ��ݸ�������atomic��ԭʼֵ��
    template <typename T>
    T AtomicMin(std::atomic<T>& atomic, const T& value) noexcept;

    // ��������ʱ��atomic = max(atomic,value)������ֵ�Ǵ��ݸ�������atomic��ԭʼֵ��
    template <typename T>
    T AtomicMax(std::atomic<T>& atomic, const T& value) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H