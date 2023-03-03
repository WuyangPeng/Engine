///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/02/23 13:41)

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

        NoexceptNoReturn(*this, &ClassType::CheckIsValid, "ǰ������"sv);
    }
}

template <typename T>
CoreTools::CheckInvariant<T>::~CheckInvariant() noexcept
{
    if (conditions != CheckInvariantConditions::OnlyPreCondition)
    {
        using namespace std::literals;

        NoexceptNoReturn(*this, &ClassType::CheckIsValid, "��������"sv);
    }
}

// private
template <typename T>
void CoreTools::CheckInvariant<T>::CheckIsValid(std::string_view failLocationDescribe) const
{
    if (!master.IsValid())
    {
        const TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant, functionDescribed, "%s", failLocationDescribe };
    }
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_DETAIL_H