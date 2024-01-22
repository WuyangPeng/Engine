/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:14)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "SimplePropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>::SimplePropertySetExternal(ValueType& value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value, typename Reference>
bool CoreTools::SimplePropertySetExternal<Value, Reference>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>& CoreTools::SimplePropertySetExternal<Value, Reference>::operator=(ReferenceType aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H