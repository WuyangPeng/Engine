/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/14 16:39)

#ifndef CORE_TOOLS_HELPER_HASH_COMBINE_H
#define CORE_TOOLS_HELPER_HASH_COMBINE_H

#include "CoreTools/CoreToolsDll.h"

#include <functional>
#include <type_traits>

/// ����Ϊ�����б�����ϣֵ��ÿ������T����һ����Ч��std::hash<T>()������
namespace CoreTools
{
    template <typename T>
    NODISCARD size_t HashCombine(size_t seed, const T& value) noexcept
    {
        seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }

    /// ʹ�����Ӵ�����ϣֵ�ĺ�����
    template <typename T>
    NODISCARD size_t DoHashValue(size_t seed, T&& value) noexcept
    {
        return HashCombine(seed, std::forward<T>(value));
    }

    template <typename T, typename... Tail>
    NODISCARD size_t DoHashValue(size_t seed, T&& value, Tail&&... arguments) noexcept
    {
        seed = HashCombine(seed, std::forward<T>(value));

        return DoHashValue(seed, std::forward<Tail>(arguments)...);
    }

    /// ���ڴӲ����б��д�����ϣֵ�ĺ�����
    template <typename... Tail>
    NODISCARD size_t HashValue(Tail&&... arguments) noexcept
    {
        return DoHashValue(0u, std::forward<Tail>(arguments)...);
    }
}

#endif  // CORE_TOOLS_HELPER_HASH_COMBINE_H