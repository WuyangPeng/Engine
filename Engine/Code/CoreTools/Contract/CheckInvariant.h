///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 09:42)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H

#include "ContractFwd.h"
#include "Flags/CheckInvariantFlags.h"

#include <string>

// 验证类不变式的工具类
namespace CoreTools
{
    template <typename T>
    class CheckInvariant final
    {
    public:
        using ClassType = CheckInvariant<T>;

        using ValueType = T;
        using Reference = T&;
        using ConstReference = const T&;

    public:
        CheckInvariant(ConstReference master,
                       const FunctionDescribed& functionDescribed,
                       CheckInvariantConditions conditions = CheckInvariantConditions::Fully) noexcept;
        ~CheckInvariant() noexcept;

        CheckInvariant(const CheckInvariant& rhs) = delete;
        CheckInvariant& operator=(const CheckInvariant& rhs) = delete;
        CheckInvariant(CheckInvariant&& rhs) noexcept = delete;
        CheckInvariant& operator=(CheckInvariant&& rhs) noexcept = delete;

    private:
        void CheckIsValid(std::string_view failLocationDescribe) const;

    private:
        ConstReference master;
        const FunctionDescribed& functionDescribed;
        CheckInvariantConditions conditions;
    };
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H