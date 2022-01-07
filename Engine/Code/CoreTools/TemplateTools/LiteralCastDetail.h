///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 11:18)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_DETAIL_H

#include "LiteralCast.h"
#include "System/Helper/PragmaWarning/LimitTraits.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, int64_t V>
void CoreTools::LiteralCast<T, V>::Constranints() noexcept
{
    static_assert(V <= stlsoft::limit_traits<T>::maximum_value, "V must <= maximum_value");
    static_assert(stlsoft::limit_traits<T>::minimum_value <= V, "V must >= minimum_value");
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, int64_t V>
bool CoreTools::LiteralCast<T, V>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, int64_t V>
CoreTools::LiteralCast<T, V>::~LiteralCast()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    MAYBE_UNUSED void (*ptr)() = Constranints;
}

template <typename T, int64_t V>
CoreTools::LiteralCast<T, V>::operator T() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return T(V);
}

#ifdef OPEN_CLASS_INVARIANT

template <int64_t V>
bool CoreTools::LiteralCast<uint64_t, V>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int64_t V>
CoreTools::LiteralCast<uint64_t, V>::operator uint64_t() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto literalCastCannotCastToLargestUnsignedIntegerType = 0;

    static_assert(literalCastCannotCastToLargestUnsignedIntegerType, "Literal Cast Cannot Cast To Largest Unsigned Integer Type");

    return 0;
}

#ifdef OPEN_CLASS_INVARIANT

template <int64_t V>
bool CoreTools::LiteralCast<int64_t, V>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int64_t V>
CoreTools::LiteralCast<int64_t, V>::operator int64_t() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    constexpr auto literalCastCannotCastToLargestSignedIntegerType = 0;

    static_assert(literalCastCannotCastToLargestSignedIntegerType, "Literal Cast Cannot Cast To Largest Signed Integer Type");

    return 0;
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_DETAIL_H
