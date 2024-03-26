/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:46)

#ifndef SYSTEM_HELPER_ENUM_CAST_H
#define SYSTEM_HELPER_ENUM_CAST_H

#include "System/Helper/ConfigMacro.h"

#include <type_traits>

namespace System
{
    /// ö�ٺ�����֮���ת��

    template <typename E>
    NODISCARD constexpr auto EnumCastUnderlying(E enumerator) noexcept requires(std::is_enum_v<E>)
    {
        using UnderlyingType = std::underlying_type_t<E>;

        return static_cast<UnderlyingType>(enumerator);
    }

    template <typename T, typename E>
    NODISCARD constexpr T EnumCastUnderlying(E enumerator) noexcept requires(std::is_enum_v<E>)
    {
        return static_cast<T>(enumerator);
    }

    template <typename E>
    NODISCARD constexpr E UnderlyingCastEnum(std::underlying_type_t<E> value) noexcept requires(std::is_enum_v<E>)
    {
        return static_cast<E>(value);
    }

    template <typename E>
    void UnderlyingCastEnumPtr(std::underlying_type_t<E> value, E* ptr) noexcept requires(std::is_enum_v<E>)
    {
        /// ָ������Ϊ�ա�
        if (ptr != nullptr)
        {
            *ptr = UnderlyingCastEnum<E>(value);
        }
    }
}

#endif  // SYSTEM_HELPER_ENUM_CAST_H