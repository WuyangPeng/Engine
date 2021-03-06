//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 18:43)

#ifndef SYSTEM_HELPER_ENUM_CAST_H
#define SYSTEM_HELPER_ENUM_CAST_H

#include "System/Helper/ConfigMacro.h"

#include <type_traits>

namespace System
{
    // 枚举和整型之间的转换

    template <typename E>
    [[nodiscard]] constexpr auto EnumCastUnderlying(E value) noexcept
    {
        static_assert(std::is_enum_v<E>, "E must be an enum.");

        using UnderlyingType = std::underlying_type_t<E>;

        return static_cast<UnderlyingType>(value);
    }

    template <typename T, typename E>
    [[nodiscard]] constexpr T EnumCastUnderlying(E value) noexcept
    {
        static_assert(std::is_enum_v<E>, "E must be an enum.");

        return static_cast<T>(value);
    }

    template <typename E>
    [[nodiscard]] constexpr E UnderlyingCastEnum(std::underlying_type_t<E> value) noexcept
    {
        static_assert(std::is_enum_v<E>, "E must be an enum.");

        return static_cast<E>(value);
    }

    template <typename E>
    void UnderlyingCastEnumPtr(typename std::underlying_type_t<E> value, E* ptr) noexcept
    {
        static_assert(std::is_enum_v<E>, "E must be an enum.");

        // 指针允许为空。
        if (ptr != nullptr)
        {
            *ptr = UnderlyingCastEnum<E>(value);
        }
    }
}

#endif  // SYSTEM_HELPER_ENUM_CAST_H