///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:36)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H

#include "ValueScope.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T>
template <typename V>
CoreTools::ValueScope<T>::ValueScope(Reference value, V const& set) noexcept(std::is_arithmetic_v<T>)
    : value{ value }, revert{ value }
{
    value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
template <typename V1, typename V2>
CoreTools::ValueScope<T>::ValueScope(Reference value, V1 const& set, V2 const& revert) noexcept(std::is_arithmetic_v<T>)
    : value{ value }, revert{ revert }
{
    value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
CoreTools::ValueScope<T>::~ValueScope() noexcept
{
    EXCEPTION_TRY
    {
        value = revert;
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ValueScope<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
