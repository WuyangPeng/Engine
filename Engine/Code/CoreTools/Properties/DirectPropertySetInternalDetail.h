///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:10)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_DETAIL_H

#include "DirectPropertySetInternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertySetInternal<Value, Reference, Container>::DirectPropertySetInternal(ReferenceType value)
    : m_Value{ value }
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
CoreTools::DirectPropertySetInternal<Value, Reference, Container>& CoreTools::DirectPropertySetInternal<Value, Reference, Container>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Value = value;

    return *this;
}

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertySetInternal<Value, Reference, Container>::operator ReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_DETAIL_H