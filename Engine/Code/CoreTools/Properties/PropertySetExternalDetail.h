///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:57)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "PropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename Reference, void (T::*PF)(Reference)>
CoreTools::PropertySetExternal<T, Reference, PF>::PropertySetExternal(T& object) noexcept
    : m_Object{ object }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename Reference, void (T::*PF)(Reference)>
bool CoreTools::PropertySetExternal<T, Reference, PF>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename Reference, void (T::*PF)(Reference)>
CoreTools::PropertySetExternal<T, Reference, PF>& CoreTools::PropertySetExternal<T, Reference, PF>::operator=(ReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (m_Object.*PF)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_DETAIL_H