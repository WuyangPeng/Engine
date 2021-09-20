//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 13:39)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_DETAIL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_DETAIL_H

#include "PropertyGetExternal.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T, typename ConstReference, ConstReference (T::*PF)() const>
CoreTools::PropertyGetExternal<T, ConstReference, PF>::PropertyGetExternal(const T& object) noexcept
    : m_Object{ object }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T, typename ConstReference, ConstReference (T::*PF)() const>
bool CoreTools::PropertyGetExternal<T, ConstReference, PF>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename ConstReference, ConstReference (T::*PF)() const>
CoreTools::PropertyGetExternal<T, ConstReference, PF>::operator ConstReferenceType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return (m_Object.*PF)();
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_DETAIL_H