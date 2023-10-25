///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:08)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "SimplePropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename ConstReference>
CoreTools::SimplePropertyGetExternal<Value, ConstReference>::SimplePropertyGetExternal(const ValueType& value) noexcept
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value, typename ConstReference>
bool CoreTools::SimplePropertyGetExternal<Value, ConstReference>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename ConstReference>
CoreTools::SimplePropertyGetExternal<Value, ConstReference>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_GET_EXTERNAL_DETAIL_H