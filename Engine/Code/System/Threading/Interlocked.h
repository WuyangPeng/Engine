//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_INTERLOCKED_H
#define SYSTEM_THREADING_INTERLOCKED_H

#include "System/SystemDll.h"

namespace System
{
    // ԭ�Ӳ���

    template <typename T>
    [[nodiscard]] T SystemInterlockedIncrement(T* addend) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedDecrement(T* addend) noexcept;

    // ���ص���ԭ����ֵ��
    template <typename T>
    [[nodiscard]] T SystemInterlockedExchangeAdd(T* addend, T value) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedExchange(T* target, T value) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedExchangeSubtract(T* addend, T value) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedCompareExchange(T* destination, T exchange, T comperand) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedAnd(T* destination, T value) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedOr(T* destination, T value) noexcept;

    template <typename T>
    [[nodiscard]] T SystemInterlockedXor(T* destination, T value) noexcept;
}

#endif  // SYSTEM_THREADING_INTERLOCKED_H