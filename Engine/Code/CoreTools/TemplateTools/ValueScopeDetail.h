/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:18)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_DETAIL_H

#include "ValueScope.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T>
template <typename V>
CoreTools::ValueScope<T>::ValueScope(Reference value, const V& set) noexcept(std::is_arithmetic_v<T>)
    : value{ value }, revert{ value }
{
    value = set;

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
template <typename V1, typename V2>
CoreTools::ValueScope<T>::ValueScope(Reference value, const V1& set, const V2& revert) noexcept(std::is_arithmetic_v<T>)
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
