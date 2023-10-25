///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 09:42)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H

#include "ContractFwd.h"
#include "Flags/CheckInvariantFlags.h"

#include <string>

// ��֤�಻��ʽ�Ĺ�����
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