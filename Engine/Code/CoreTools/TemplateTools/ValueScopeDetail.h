//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H

#include "ValueScope.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
template <typename V>
CoreTools::ValueScope<T>::ValueScope(Reference value, V const& set)
    : m_Value{ value }, m_Revert{ value }
{
    m_Value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
template <typename V1, typename V2>
CoreTools::ValueScope<T>::ValueScope(Reference value, V1 const& set, V2 const& revert)
    : m_Value{ value }, m_Revert{ revert }
{
    m_Value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ValueScope<T>::~ValueScope()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    m_Value = m_Revert;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ValueScope<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
