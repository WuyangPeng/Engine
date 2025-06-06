/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:29)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

namespace Mathematics
{
    // 支持除法和取模。
    template <int N>
    class IntegerDivisionModulo final
    {
    public:
        using ClassType = IntegerDivisionModulo<N>;

        using IntegerDataType = IntegerData<N>;
        using IntegerDataAnalysisType = IntegerDataAnalysis<N>;

    public:
        IntegerDivisionModulo(const IntegerDataType& division, const IntegerDataType& modulo);

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IsCorrect() const;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD IntegerDataType GetQuotient() const noexcept;
        NODISCARD IntegerDataType GetRemainder() const noexcept;

    private:
        void Calculate();
        void DivisionSingle();
        void DivisionMultiple();
        void CalculateRemainder();

    private:
        static constexpr auto low = 0x0000FFFFu;
        static constexpr auto high = 0xFFFF0000u;
        static constexpr auto carry = 0x00010000u;

        IntegerDataType numerator;
        IntegerDataType denominator;
        IntegerDataType absNumerator;
        IntegerDataType absDenominator;
        IntegerDataType quotient;
        IntegerDataType remainder;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
