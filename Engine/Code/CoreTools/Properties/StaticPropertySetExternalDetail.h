//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:40)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "StaticPropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename Reference, void (*PF)(Reference)>
bool CoreTools::StaticPropertySetExternal<Reference, PF>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Reference, void (*PF)(Reference)>
CoreTools::StaticPropertySetExternal<Reference, PF>& CoreTools::StaticPropertySetExternal<Reference, PF>::operator=(ReferenceType value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (*PF)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_DETAIL_H