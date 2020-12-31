//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:34)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H

#include "ReferenceCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
CoreTools::ReferenceCast<T>::ReferenceCast(T& value) noexcept
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ReferenceCast<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
CoreTools::ReferenceCast<T>::operator T&() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return const_cast<ClassType*>(this)->m_Value;
}

CoreTools::ReferenceCast<int>::ReferenceCast(int value) noexcept
    : m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ReferenceCast<int>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::ReferenceCast<int>::operator int() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_Value;
}
#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_DETAIL_H
