//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:40)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H

#include "StaticPropertyGetSet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value, typename GetReference, typename SetReference, typename Container,
          GetReference (*FG)(void), void (*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>::StaticPropertyGetSet() noexcept
    : m_Value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value, typename GetReference, typename SetReference, typename Container,
          GetReference (*FG)(void), void (*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>::StaticPropertyGetSet(SetReferenceType value)
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Value, typename GetReference, typename SetReference, typename Container,
          GetReference (*FG)(void), void (*FS)(SetReference)>
bool CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Value, typename GetReference, typename SetReference, typename Container,
          GetReference (*FG)(void), void (*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>::operator GetReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*FG)();
}

template <typename Value, typename GetReference, typename SetReference, typename Container,
          GetReference (*FG)(void), void (*FS)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>& CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, FG, FS>::operator=(SetReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (*FS)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H