/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:47)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H

#include "CallbackParametersImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
void CoreTools::CallbackParametersImpl::SetValue(int index, T&& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (boost::numeric_cast<int>(container.size()) <= index)
    {
        const auto nextIndex = index + 1;
        container.resize(nextIndex);
    }

    std::any anyValue{ std::forward<T>(value) };

    container.at(index).swap(anyValue);
}

template <typename T>
T CoreTools::CallbackParametersImpl::GetValue(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::any_cast<T>(container.at(index));
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H
