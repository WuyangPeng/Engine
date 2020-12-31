///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:22)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    // 支持除法和取模。
    template <int N>
    class IntegerDivisionMultiple final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerDivisionMultiple<N>;
        using IntegerData = IntegerData<N>;
        using IntegerDataAnalysis = IntegerDataAnalysis<N>;

    public:
        IntegerDivisionMultiple(const IntegerData& absNumerator, const IntegerData& absDenominator);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const IntegerData GetQuotient() const noexcept;
        [[nodiscard]] const IntegerData GetRemainder() const noexcept;

    private:
        void Calculate();
        void Adjust();
        void Recover();
        void Calculate(int quotientInit);

    private:
        static constexpr auto sm_Low = 0x0000FFFFu;
        static constexpr auto sm_High = 0xFFFF0000u;
        static constexpr auto sm_Carry = 0x00010000u;

        const IntegerData& m_AbsNumerator;
        const IntegerData& m_AbsDenominator;
        IntegerData m_AdjustNumerator;
        IntegerData m_AdjustDenominator;
        int m_NumeratorInit;
        int m_DenominatorInit;
        int m_Adjust;
        uint32_t m_FirstDigit;
        uint32_t m_SecondDigit;
        uint32_t m_RemainderHat;
        IntegerData m_Quotient;
        IntegerData m_Remainder;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
