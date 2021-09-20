//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H

#include "ValueScope.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
template <typename V>
CoreTools::ValueScope<T>::ValueScope(Reference value, V const& set) noexcept(std::is_arithmetic_v<T>)
    : m_Value{ value }, m_Revert{ value }
{
    m_Value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
template <typename V1, typename V2>
CoreTools::ValueScope<T>::ValueScope(Reference value, V1 const& set, V2 const& revert) noexcept(std::is_arithmetic_v<T>)
    : m_Value{ value }, m_Revert{ revert }
{
    m_Value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ValueScope<T>::~ValueScope() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    try
    {
        m_Value = m_Revert;
    }
    catch (...)
    {
    	
    }
    
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::ValueScope<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
