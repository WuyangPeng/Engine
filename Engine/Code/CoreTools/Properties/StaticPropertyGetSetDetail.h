///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:07)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H

#include "StaticPropertyGetSet.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          GetReference (*PropertyGet)(),
          void (*PropertySet)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, PropertyGet, PropertySet>::StaticPropertyGetSet() noexcept
    : value{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          GetReference (*PropertyGet)(),
          void (*PropertySet)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, PropertyGet, PropertySet>::StaticPropertyGetSet(SetReferenceType value)
    : value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          GetReference (*PropertyGet)(),
          void (*PropertySet)(SetReference)>
bool CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, PropertyGet, PropertySet>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          GetReference (*PropertyGet)(),
          void (*PropertySet)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, PropertyGet, PropertySet>::operator GetReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PropertyGet)();
}

template <typename Value,
          typename GetReference,
          typename SetReference,
          typename Container,
          GetReference (*PropertyGet)(),
          void (*PropertySet)(SetReference)>
CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, PropertyGet, PropertySet>& CoreTools::StaticPropertyGetSet<Value, GetReference, SetReference, Container, PropertyGet, PropertySet>::operator=(SetReferenceType aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (*PropertySet)(aValue);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_DETAIL_H