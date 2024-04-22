/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:03)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H

#include "CheckInvariant.h"
#include "Noexcept.h"
#include "TriggerAssertDetail.h"

template <typename T>
CoreTools::CheckInvariant<T>::CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed, CheckInvariantConditions conditions) noexcept
    : master{ master }, functionDescribed{ functionDescribed }, conditions{ conditions }
{
    if (conditions != CheckInvariantConditions::OnlyPostCondition)
    {
        using namespace std::literals;

        NoexceptNoReturn(*this, &ClassType::CheckIsValid, "前置条件"sv);
    }
}

template <typename T>
CoreTools::CheckInvariant<T>::~CheckInvariant() noexcept
{
    if (conditions != CheckInvariantConditions::OnlyPreCondition)
    {
        using namespace std::literals;

        NoexceptNoReturn(*this, &ClassType::CheckIsValid, "后置条件"sv);
    }
}

template <typename T>
void CoreTools::CheckInvariant<T>::CheckIsValid(std::string_view failLocationDescribe) const
{
    if (!master.IsValid())
    {
        const TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant, functionDescribed, "%s", failLocationDescribe };
    }
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H