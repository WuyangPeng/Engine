// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 17:59)

#ifndef CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_DETAIL_H
#define CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_DETAIL_H

#include "CheckInvariant.h"
#include "TriggerAssert.h"

template <typename T>
CoreTools::CheckInvariant<T>
	::CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed, CheckInvariantConditions conditions) noexcept
	:m_Master{ master }, m_FunctionDescribed{ functionDescribed }, m_Conditions{ conditions }
{
	if (m_Conditions != CheckInvariantConditions::OnlyPostconditions)
	{
		CheckIsValid("ǰ������");
	}
}

template <typename T>
CoreTools::CheckInvariant<T>
	::~CheckInvariant() noexcept
{
	if (m_Conditions != CheckInvariantConditions::OnlyPreconditions)
	{
		CheckIsValid("��������");
	}
}

// private
template <typename T>
void CoreTools::CheckInvariant<T>
	::CheckIsValid(const char* failLocationDescribe) noexcept
{
	try
	{
		if (!m_Master.IsValid())
		{
			TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant,m_FunctionDescribed,"%s", failLocationDescribe };
		}
	}
	catch (...)
	{
		// ���������쳣�����ﲻ�����κ��߼���������ɵݹ���á�
	}
}

#endif // CORE_TOOLS_CLASS_INVARIANT_CHECK_INVARIANT_DETAIL_H