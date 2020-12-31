//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:37)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H

#include "CallbackParametersImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename T>
void CoreTools::CallbackParametersImpl::SetValue(int index, typename boost::call_traits<T>::param_type value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (boost::numeric_cast<int>(m_Container.size()) <= index)
    {
        const auto nextIndex = index + 1;
        m_Container.resize(nextIndex);
    }

    boost::any anyValue{ value };

    m_Container.at(index).swap(anyValue);
}

template <typename T>
const T CoreTools::CallbackParametersImpl::GetValue(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::any_cast<T>(m_Container.at(index));
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H
