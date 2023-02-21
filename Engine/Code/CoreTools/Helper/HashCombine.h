///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/18 18:30)

#ifndef CORE_TOOLS_HELPER_HASH_COMBINE_H
#define CORE_TOOLS_HELPER_HASH_COMBINE_H

#include "UserMacro.h"

#include <functional>
#include <type_traits>

namespace CoreTools
{
    template <typename T>
    NODISCARD std::size_t HashCombine(std::size_t seed, const T& value) noexcept
    {
        seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }

    template <typename T>
    NODISCARD std::size_t DoHashValue(std::size_t seed, T&& value) noexcept
    {
        return HashCombine(seed, std::forward<T>(value));
    }

    template <typename T, typename... Tail>
    NODISCARD std::size_t DoHashValue(std::size_t seed, T&& value, Tail&&... arguments) noexcept
    {
        seed = HashCombine(seed, std::forward<T>(value));
        return DoHashValue(seed, std::forward<Tail>(arguments)...);
    }

    template <typename... Tail>
    NODISCARD std::size_t HashValue(Tail&&... arguments) noexcept
    {
        return DoHashValue(0, std::forward<Tail>(arguments)...);
    }
}

#endif  // CORE_TOOLS_HELPER_HASH_COMBINE_H