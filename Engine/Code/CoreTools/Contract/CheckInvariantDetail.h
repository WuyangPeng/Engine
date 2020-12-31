//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/10 14:11)

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
        NoexceptNoReturn<const char*>(*this, &ClassType::CheckIsValid, "前置条件");
    }
}

template <typename T>
CoreTools::CheckInvariant<T>::~CheckInvariant() noexcept
{
    if (m_Conditions != CheckInvariantConditions::OnlyPreconditions)
    {
        NoexceptNoReturn<const char*>(*this, &ClassType::CheckIsValid, "后置条件");
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