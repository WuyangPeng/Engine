///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 10:05)

#ifndef SYSTEM_HELPER_ENUM_OPERATOR_H
#define SYSTEM_HELPER_ENUM_OPERATOR_H

#include "ConfigMacro.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"

#include <iosfwd>
#include <type_traits>

namespace System
{
    template <typename E>
    NODISCARD auto& ReinterpretCast(E& enumerator) noexcept requires std::is_enum_v<E>
    {
        using UnderlyingType = std::underlying_type_t<E>;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        return reinterpret_cast<UnderlyingType&>(enumerator);

#include SYSTEM_WARNING_POP
    }

    template <typename E>
    NODISCARD constexpr E operator+(E lhs, std::underlying_type_t<E> rhs) noexcept requires std::is_enum_v<E>
    {
        return System::UnderlyingCastEnum<E>(System::EnumCastUnderlying(lhs) + rhs);
    }

    template <typename E>
    NODISCARD constexpr E operator+(std::underlying_type_t<E> lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        return rhs + lhs;
    }

    template <typename E>
    E& operator+=(E& lhs, std::underlying_type_t<E> rhs) noexcept requires std::is_enum_v<E>
    {
        lhs = lhs + rhs;

        return lhs;
    }

    template <typename E>
    NODISCARD constexpr E operator-(E lhs, std::underlying_type_t<E> rhs) noexcept requires std::is_enum_v<E>
    {
        return System::UnderlyingCastEnum<E>(System::EnumCastUnderlying(lhs) - rhs);
    }

    template <typename E>
    E& operator-=(E& lhs, std::underlying_type_t<E> rhs) noexcept requires std::is_enum_v<E>
    {
        lhs = lhs - rhs;

        return lhs;
    }

    template <typename E, typename T>
    NODISCARD constexpr T operator*(E lhs, T rhs) noexcept requires std::is_enum_v<E> && std::is_arithmetic_v<T>
    {
        return System::EnumCastUnderlying(lhs) * rhs;
    }

    template <typename E, typename T>
    NODISCARD constexpr T operator*(T lhs, E rhs) noexcept requires std::is_enum_v<E> && std::is_arithmetic_v<T>
    {
        return rhs * lhs;
    }

    template <typename E>
    NODISCARD constexpr E operator-(E lhs) noexcept requires std::is_enum_v<E> && std::is_signed_v<std::underlying_type_t<E>>
    {
        return System::UnderlyingCastEnum<E>(-System::EnumCastUnderlying(lhs));
    }

    template <typename E>
    E& operator++(E& lhs) noexcept requires std::is_enum_v<E>
    {
        auto& result = ReinterpretCast(lhs);

        ++result;

        return lhs;
    }

    template <typename E>
    E operator++(E& lhs, int) noexcept requires std::is_enum_v<E>
    {
        const auto result = lhs;
        ++lhs;

        return result;
    }

    template <typename E>
    E& operator--(E& lhs) noexcept requires std::is_enum_v<E>
    {
        auto& result = ReinterpretCast(lhs);

        --result;

        return lhs;
    }

    template <typename E>
    E operator--(E& lhs, int) noexcept requires std::is_enum_v<E>
    {
        const auto result = lhs;
        --lhs;

        return result;
    }

    template <typename E>
    NODISCARD constexpr E operator&(E lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        return System::UnderlyingCastEnum<E>(System::EnumCastUnderlying(lhs) & System::EnumCastUnderlying(rhs));
    }

    template <typename E>
    E& operator&=(E& lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        lhs = lhs & rhs;
        return lhs;
    }

    template <typename E>
    NODISCARD constexpr E operator|(E lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        return System::UnderlyingCastEnum<E>(System::EnumCastUnderlying(lhs) | System::EnumCastUnderlying(rhs));
    }

    template <typename E>
    E& operator|=(E& lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        lhs = lhs | rhs;
        return lhs;
    }

    template <typename E>
    NODISCARD constexpr E operator^(E lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        return System::UnderlyingCastEnum<E>(System::EnumCastUnderlying(lhs) ^ System::EnumCastUnderlying(rhs));
    }

    template <typename E>
    E& operator^=(E& lhs, E rhs) noexcept requires std::is_enum_v<E>
    {
        lhs = lhs ^ rhs;
        return lhs;
    }

    // 使用下面函数需要包含头文件iostream。

    template <typename E>
    std::ostream& operator<<(std::ostream& os, E lhs) requires std::is_enum_v<E>
    {
        os << System::EnumCastUnderlying(lhs);

        return os;
    }

    template <typename E>
    std::istream& operator>>(std::istream& is, E& lhs) requires std::is_enum_v<E>
    {
        auto& result = ReinterpretCast(lhs);

        is >> result;

        return is;
    }

    template <typename E>
    std::wostream& operator<<(std::wostream& os, E lhs) requires std::is_enum_v<E>
    {
        os << System::EnumCastUnderlying(lhs);

        return os;
    }

    template <typename E>
    std::wistream& operator>>(std::wistream& is, E& lhs) requires std::is_enum_v<E>
    {
        auto& result = ReinterpretCast(lhs);

        is >> result;

        return is;
    }
}

#endif  // SYSTEM_HELPER_ENUM_OPERATOR_H
