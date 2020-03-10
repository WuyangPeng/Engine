// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 18:03)

#ifndef CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_FLAGS_H
#define CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
	enum class CheckInvariantConditions
	{
		OnlyPreconditions, // 仅断言前置条件
		OnlyPostconditions, // 仅断言后置条件
		Fully // 完全类不变式
	};

	enum class TriggerAssertCheck
	{
		Invariant, // 不变式
		Assertion, // 断言
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_FLAGS_H