/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_TRAPEZOID_RULE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class TrapezoidRule final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = TrapezoidRule<Real, UserDataType>;

        // 最后一个参数是用户定义的数据。
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
