///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:19)

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

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        [[nodiscard]] bool IsCorrect() const;
#endif  // OPEN_CLASS_INVARIANT

        [[nodiscard]] const IntegerData GetQuotient() const noexcept;
        [[nodiscard]] const IntegerData GetRemainder() const noexcept;

    private:
        void Calculate();
        void DivisionSingle();
        void DivisionMultiple();
        void CalculateRemainder();

    private:
        static constexpr auto sm_Low = 0x0000FFFFu;
        static constexpr auto sm_High = 0xFFFF0000u;
        static constexpr auto sm_Carry = 0x00010000u;

        IntegerData m_Numerator;
        IntegerData m_Denominator;
        IntegerData m_AbsNumerator;
        IntegerData m_AbsDenominator;
        IntegerData m_Quotient;
        IntegerData m_Remainder;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MODULO_H
