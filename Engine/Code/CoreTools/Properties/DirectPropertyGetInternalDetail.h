//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:36)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_DETAIL_H

#include "DirectPropertyGetInternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertyGetInternal<Value, Reference, Container>::DirectPropertyGetInternal()
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertyGetInternal<Value, Reference, Container>::DirectPropertyGetInternal(ReferenceType value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value, typename Reference, typename Container>
bool CoreTools::DirectPropertyGetInternal<Value, Reference, Container>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertyGetInternal<Value, Reference, Container>& CoreTools::DirectPropertyGetInternal<Value, Reference, Container>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Value = value;

    return *this;
}

template <typename Value, typename Reference, typename Container>
CoreTools::DirectPropertyGetInternal<Value, Reference, Container>::operator ReferenceType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_DETAIL_H