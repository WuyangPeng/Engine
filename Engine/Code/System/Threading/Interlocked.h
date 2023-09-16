///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:18)

#ifndef SYSTEM_THREADING_INTERLOCKED_H
#define SYSTEM_THREADING_INTERLOCKED_H

#include "System/SystemDll.h"

// ԭ�Ӳ���
namespace System
{
    template <typename T>
    NODISCARD T SystemInterlockedIncrement(T* addend) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedDecrement(T* addend) noexcept(std::is_same_v<long, T>);

    // ���ص���ԭ����ֵ��
    template <typename T>
    NODISCARD T SystemInterlockedExchangeAdd(T* addend, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedExchange(T* target, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedExchangeSubtract(T* addend, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedCompareExchange(T* destination, T exchange, T comparand) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedAnd(T* destination, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedOr(T* destination, T value) noexcept(std::is_same_v<long, T>);

    template <typename T>
    NODISCARD T SystemInterlockedXor(T* destination, T value) noexcept(std::is_same_v<long, T>);
}

#endif  // SYSTEM_THREADING_INTERLOCKED_H