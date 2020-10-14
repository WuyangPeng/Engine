//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/10 13:03)

#ifndef CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H
#define CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H

#include "ContractFwd.h"
#include "Flags/CheckInvariantFlags.h"

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
        CheckInvariant(ConstReference master, const FunctionDescribed& functionDescribed,
                       CheckInvariantConditions conditions = CheckInvariantConditions::Fully) noexcept;
        ~CheckInvariant() noexcept;

        CheckInvariant(const CheckInvariant&) = delete;
        CheckInvariant& operator=(const CheckInvariant&) = delete;
        CheckInvariant(CheckInvariant&&) noexcept = delete;
        CheckInvariant& operator=(CheckInvariant&&) noexcept = delete;

    private:
        void CheckIsValid(const char* failLocationDescribe) const;

    private:
        ConstReference m_Master;
        const FunctionDescribed& m_FunctionDescribed;
        CheckInvariantConditions m_Conditions;
    };
}

#endif  // CORE_TOOLS_CONTRACT_CHECK_INVARIANT_H