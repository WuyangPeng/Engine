/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:07)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PropertyFunction)()>
requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
bool CoreTools::StaticPropertyGetExternal<ConstReference, PropertyFunction>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PropertyFunction)()>
requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
CoreTools::StaticPropertyGetExternal<ConstReference, PropertyFunction>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PropertyFunction)();
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H