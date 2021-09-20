///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/25 15:55)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H

#include "CheckInvariant.h"
#include "Noexcept.h"
#include "TriggerAssertDetail.h"

template <typename T>
CoreTools::CheckInvariant<T>::CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed, CheckInvariantConditions conditions) noexcept
    : master{ master }, functionDescribed{ functionDescribed }, conditions{ conditions }
{
    if (conditions != CheckInvariantConditions::OnlyPostconditions)
    {
        NoexceptNoReturn<const char*>(*this, &ClassType::CheckIsValid, "前置条件");
    }
}

template <typename T>
CoreTools::CheckInvariant<T>::~CheckInvariant() noexcept
{
    if (conditions != CheckInvariantConditions::OnlyPreconditions)
    {
        NoexceptNoReturn<const char*>(*this, &ClassType::CheckIsValid, "后置条件");
    }
}

// private
template <typename T>
void CoreTools::CheckInvariant<T>::CheckIsValid(const char* failLocationDescribe) const
{
    if (!master.IsValid())
    {
        const TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant, functionDescribed, "%s", failLocationDescribe };
    }
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H