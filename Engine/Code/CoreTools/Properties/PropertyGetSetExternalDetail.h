/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H

#include "PropertyGetSetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T,
          typename GetReference,
          GetReference (T::*PropertyGet)() const,
          typename SetReference,
          void (T::*PropertySet)(SetReference)>
CoreTools::PropertyGetSetExternal<T, GetReference, PropertyGet, SetReference, PropertySet>::PropertyGetSetExternal(T& object) noexcept
    : object{ object }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T,
          typename GetReference,
          GetReference (T::*PropertyGet)() const,
          typename SetReference,
          void (T::*PropertySet)(SetReference)>
bool CoreTools::PropertyGetSetExternal<T, GetReference, PropertyGet, SetReference, PropertySet>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T,
          typename GetReference,
          GetReference (T::*PropertyGet)() const,
          typename SetReference,
          void (T::*PropertySet)(SetReference)>
CoreTools::PropertyGetSetExternal<T, GetReference, PropertyGet, SetReference, PropertySet>::operator GetReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (object.*PropertyGet)();
}

template <typename T,
          typename GetReference,
          GetReference (T::*PropertyGet)() const,
          typename SetReference,
          void (T::*PropertySet)(SetReference)>
CoreTools::PropertyGetSetExternal<T, GetReference, PropertyGet, SetReference, PropertySet>& CoreTools::PropertyGetSetExternal<T, GetReference, PropertyGet, SetReference, PropertySet>::operator=(SetReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (object.*PropertySet)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_DETAIL_H