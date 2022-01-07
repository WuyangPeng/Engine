///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:58)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "StaticPropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PF)()>
bool CoreTools::StaticPropertyGetExternal<ConstReference, PF>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename ConstReference, ConstReference (*PF)()>
CoreTools::StaticPropertyGetExternal<ConstReference, PF>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (*PF)();
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_DETAIL_H