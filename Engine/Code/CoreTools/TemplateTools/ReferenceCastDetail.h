///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H

#include "ReferenceCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ReferenceCast<T>::ReferenceCast(T& value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ReferenceCast<T>::ReferenceCast(const ReferenceCast& rhs) noexcept
    : value{ rhs.value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ReferenceCast<T>::ReferenceCast(ReferenceCast&& rhs) noexcept
    : value{ std::move(rhs.value) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ReferenceCast<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ReferenceCast<T>::operator T&() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return value;
}

CoreTools::ReferenceCast<int>::ReferenceCast(int value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ReferenceCast<int>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::ReferenceCast<int>::operator int() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return value;
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H
