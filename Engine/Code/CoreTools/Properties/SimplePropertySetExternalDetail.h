//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:40)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "SimplePropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference>
CoreTools::SimplePropertySetExternal<Value, Reference>::SimplePropertySetExternal(ValueType& value)
    : m_Value{ value }
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
CoreTools::SimplePropertySetExternal<Value, Reference>& CoreTools::SimplePropertySetExternal<Value, Reference>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Value = value;

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_DETAIL_H