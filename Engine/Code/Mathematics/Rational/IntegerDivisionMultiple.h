/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:29)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
#define MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

#include <boost/noncopyable.hpp>

namespace Mathematics
{
    // ֧�ֳ�����ȡģ��
    template <int N>
    class IntegerDivisionMultiple final : private boost::noncopyable
    {
    public:
        using ClassType = IntegerDivisionMultiple<N>;
        using IntegerDataType = IntegerData<N>;
        using IntegerDataAnalysisType = IntegerDataAnalysis<N>;

    public:
        IntegerDivisionMultiple(const IntegerDataType& absNumerator, const IntegerDataType& absDenominator);

        CLASS_INVARIANT_DECLARE;

        NODISCARD IntegerDataType GetQuotient() const noexcept;
        NODISCARD IntegerDataType GetRemainder() const noexcept;

    private:
        void Calculate();
        void Adjust();
        void Recover();
        void Calculate(int quotientInit);

    private:
        static constexpr auto low = 0x0000FFFFu;
        static constexpr auto high = 0xFFFF0000u;
        static constexpr auto integerCarry = 0x00010000u;

        const IntegerDataType& absNumerator;
        const IntegerDataType& absDenominator;
        IntegerDataType adjustNumerator;
        IntegerDataType adjustDenominator;
        int numeratorInit;
        int denominatorInit;
        int adjust;
        uint32_t firstDigit;
        uint32_t secondDigit;
        uint32_t remainderHat;
        IntegerDataType quotient;
        IntegerDataType remainder;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DIVISION_MULTIPLE_H
