/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:14)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename GetReference, typename SetReference, GetReference (*PropertyGet)(), void (*PropertySet)(SetReference)>
bool CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, PropertyGet, PropertySet>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename GetReference, typename SetReference, GetReference (*PropertyGet)(), void (*PropertySet)(SetReference)>
CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, PropertyGet, PropertySet>::operator GetReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PropertyGet)();
}

template <typename GetReference, typename SetReference, GetReference (*PropertyGet)(), void (*PropertySet)(SetReference)>
CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, PropertyGet, PropertySet>& CoreTools::StaticPropertyGetSetExternal<GetReference, SetReference, PropertyGet, PropertySet>::operator=(SetReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (*PropertySet)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_EXTERNAL_DETAIL_H