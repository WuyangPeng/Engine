/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/14 16:39)

#ifndef CORE_TOOLS_HELPER_HASH_COMBINE_H
#define CORE_TOOLS_HELPER_HASH_COMBINE_H

#include "CoreTools/CoreToolsDll.h"

#include <functional>
#include <type_traits>

/// 允许为类型列表创建哈希值，每个类型T都有一个有效的std::hash<T>()函数。
namespace CoreTools
{
    template <typename T>
    NODISCARD size_t HashCombine(size_t seed, const T& value) noexcept
    {
        seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }

    /// 使用种子创建哈希值的函数。
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

    /// 用于从参数列表中创建哈希值的函数。
    template <typename... Tail>
    NODISCARD size_t HashValue(Tail&&... arguments) noexcept
    {
        return DoHashValue(0u, std::forward<Tail>(arguments)...);
    }
}

#endif  // CORE_TOOLS_HELPER_HASH_COMBINE_H