// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:06)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H

#include "CallbackParametersImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template<typename T>
void CoreTools::CallbackParametersImpl
	::SetValue(int index, typename boost::call_traits<T>::param_type value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (boost::numeric_cast<int>(m_Container.size()) <= index)
	{
		auto nextIndex = index + 1;
		m_Container.resize(nextIndex);
	}

	boost::any anyValue{ value };

	m_Container[index].swap(anyValue);
}

template<typename T>
const T CoreTools::CallbackParametersImpl
	::GetValue(int index)
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Container.size()), "索引越界");

	return boost::any_cast<T>(m_Container[index]);
}

#endif // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_IMPL_DETAIL_H
