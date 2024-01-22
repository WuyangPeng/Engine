/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:29)

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

        NODISCARD IntegerData GetQuotient() const noexcept;
        NODISCARD IntegerData GetRemainder() const noexcept;

    private:
        void Calculate();
        void Adjust();
        void Recover();
        void Calculate(int quotientInit);

    private:
        static constexpr auto low = 0x0000FFFFu;
        static constexpr auto high = 0xFFFF0000u;
        static constexpr auto integerCarry = 0x00010000u;

        const IntegerData& absNumerator;
        const IntegerData& absDenominator;
        IntegerData adjustNumerator;
        IntegerData adjustDenominator;
        int numeratorInit;
        int denominatorInit;
        int adjust;
        uint32_t firstDigit;
        uint32_t secondDigit;
        uint32_t remainderHat;
        IntegerData quotient;
        IntegerData remainder;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
