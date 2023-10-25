///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:39)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H

#include "ExplicitCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ExplicitCast<T>::ExplicitCast(T value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ExplicitCast<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<T>::operator ValueType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

template <typename T>
CoreTools::ExplicitCast<const T&>::ExplicitCast(const T& value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ExplicitCast<T const&>::ExplicitCast(const ExplicitCast& rhs) noexcept
    : value{ rhs.value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ExplicitCast<T const&>::ExplicitCast(ExplicitCast&& rhs) noexcept
    : value{ std::move(rhs.value) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ExplicitCast<T const&>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<const T&>::operator const T&() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

template <typename T>
CoreTools::ExplicitCast<const T*>::ExplicitCast(const T* value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ExplicitCast<const T*>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ExplicitCast<const T*>::operator const T*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
