///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 11:08)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class TrapezoidRule final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = TrapezoidRule<Real, UserDataType>;

        // ���һ���������û���������ݡ�
        using Function = Real (*)(Real, const UserDataType*);

        using Math = Math<Real>;

    public:
        TrapezoidRule(int numSamples, Real begin, Real end, Function function, const UserDataType* userData);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetValue() const noexcept;

    private:
        void Calculate();

    private:
        int numSamples;
        Real begin;
        Real end;
        Function function;
        const UserDataType* userData;
        Real value;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H
