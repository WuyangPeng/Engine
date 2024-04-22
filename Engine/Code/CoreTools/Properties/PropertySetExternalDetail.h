/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:07)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_DETAIL_H

#include "PropertySetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename Reference, void (T::*PropertyFunction)(Reference)>
requires(std::is_reference_v<Reference>)
CoreTools::PropertySetExternal<T, Reference, PropertyFunction>::PropertySetExternal(T& object) noexcept
    : object{ object }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, typename Reference, void (T::*PropertyFunction)(Reference)>
requires(std::is_reference_v<Reference>)
bool CoreTools::PropertySetExternal<T, Reference, PropertyFunction>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename Reference, void (T::*PropertyFunction)(Reference)>
requires(std::is_reference_v<Reference>)
CoreTools::PropertySetExternal<T, Reference, PropertyFunction>& CoreTools::PropertySetExternal<T, Reference, PropertyFunction>::operator=(ReferenceType value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    (object.*PropertyFunction)(value);

    return *this;
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_DETAIL_H