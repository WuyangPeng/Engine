///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/14 10:50)

#ifndef CORE_TOOLS_HELPER_HASH_COMBINE_H
#define CORE_TOOLS_HELPER_HASH_COMBINE_H

#include "UserMacro.h"

#include <functional>

namespace CoreTools
{
    template <typename T>
    std::size_t HashCombine(std::size_t seed, const T& value)
    {
        seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }

    template <typename T>
    std::size_t HashValue(std::size_t seed, const T& value)
    {
        return HashCombine(seed, value);
    }

    template <typename T, typename... Tail>
    std::size_t HashValue(std::size_t seed, const T& value, Tail&&... arguments)
    {
        seed = HashCombine(seed, value);
        return HashValue(seed, std::forward<Tail>(arguments)...);
    }

    template <typename... Tail>
    std::size_t HashValue(Tail&&... arguments)
    {
        return HashValue(0, std::forward<Tail>(arguments)...);
    }
}

#endif  // CORE_TOOLS_HELPER_HASH_COMBINE_H