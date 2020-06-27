// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.1.0.0 (2020/04/02 15:09)

#ifndef CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_DETAIL_H
#define CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_DETAIL_H

#include "CheckInvariant.h"
#include "TriggerAssert.h"
#include "NoexceptDetail.h"

template <typename T>
CoreTools::CheckInvariant<T>
	::CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed, CheckInvariantConditions conditions) noexcept
	:m_Master{ master }, m_FunctionDescribed{ functionDescribed }, m_Conditions{ conditions }
{
	if (m_Conditions != CheckInvariantConditions::OnlyPostconditions)
	{
		NoexceptNoReturn(*this, &ClassType::CheckIsValid, "前置条件");
	}
}

template <typename T>
CoreTools::CheckInvariant<T>
	::~CheckInvariant() noexcept
{
	if (m_Conditions != CheckInvariantConditions::OnlyPreconditions)
	{
		NoexceptNoReturn(*this, &ClassType::CheckIsValid, "后置条件");
	}
}

// private
template <typename T>
void CoreTools::CheckInvariant<T>
	::CheckIsValid(const char* failLocationDescribe) const
{
	if (!m_Master.IsValid())
	{
		const TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant,m_FunctionDescribed,"%s", failLocationDescribe };
	}
}

#endif // CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_DETAIL_H