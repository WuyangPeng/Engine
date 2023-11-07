///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 20:08)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

namespace Mathematics
{
    // ֧�ֳ�����ȡģ��
    template <int N>
    class IntegerDivisionModulo final
    {
    public:
        using ClassType = IntegerDivisionModulo<N>;

        using IntegerData = IntegerData<N>;
        using IntegerDataAnalysis = IntegerDataAnalysis<N>;

    public:
        IntegerDivisionModulo(const IntegerData& division, const IntegerData& modulo);

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IsCorrect() const;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD IntegerData GetQuotient() const noexcept;
        NODISCARD IntegerData GetRemainder() const noexcept;

    private:
        void Calculate();
        void DivisionSingle();
        void DivisionMultiple();
        void CalculateRemainder();

    private:
        static constexpr auto low = 0x0000FFFFu;
        static constexpr auto high = 0xFFFF0000u;
        static constexpr auto carry = 0x00010000u;

        IntegerData numerator;
        IntegerData denominator;
        IntegerData absNumerator;
        IntegerData absDenominator;
        IntegerData quotient;
        IntegerData remainder;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
