//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 14:11)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H

#include "CheckInvariant.h"
#include "Noexcept.h"
#include "TriggerAssert.h"

template <typename T>
CoreTools::CheckInvariant<T>::CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed, CheckInvariantConditions conditions) noexcept
    : m_Master{ master }, m_FunctionDescribed{ functionDescribed }, m_Conditions{ conditions }
{
    if (m_Conditions != CheckInvariantConditions::OnlyPostconditions)
    {
        NoexceptNoReturn<const char*>(*this, &ClassType::CheckIsValid, "ǰ������");
    }
}

template <typename T>
CoreTools::CheckInvariant<T>::~CheckInvariant() noexcept
{
    if (m_Conditions != CheckInvariantConditions::OnlyPreconditions)
    {
        NoexceptNoReturn<const char*>(*this, &ClassType::CheckIsValid, "��������");
    }
}

// private
template <typename T>
void CoreTools::CheckInvariant<T>::CheckIsValid(const char* failLocationDescribe) const
{
    if (!m_Master.IsValid())
    {
        const TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant, m_FunctionDescribed, "%s", failLocationDescribe };
    }
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H