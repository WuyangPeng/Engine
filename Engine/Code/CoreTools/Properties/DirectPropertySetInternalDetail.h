/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:09)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_DETAIL_H

#include "DirectPropertySetInternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertySetInternal<Value, Reference, Container>::DirectPropertySetInternal(ReferenceType value)
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value, typename Reference, typename Container>
bool CoreTools::DirectPropertySetInternal<Value, Reference, Container>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertySetInternal<Value, Reference, Container>& CoreTools::DirectPropertySetInternal<Value, Reference, Container>::operator=(ReferenceType aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;

    return *this;
}

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertySetInternal<Value, Reference, Container>::operator ReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_DETAIL_H