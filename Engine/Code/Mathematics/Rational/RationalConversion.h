///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:41)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H
#define MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
    template <int N, typename T>
    class RationalConversion final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = RationalConversion<N, T>;
        using TraitsType = typename IntegerTraits<T>::TraitsType;
        using Rational = SignRational<N>;
        using Integer = Integer<N>;

    public:
        // ����ֵ�����ضϣ��׳��쳣
        explicit RationalConversion(const Rational& rational);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] T GetValue() const;

    private:
        void Init(const SignedIntegerType&);
        void Init(const UnsignedIntegerType&);
        void Init(const FloatType&);
        void Init(const DoubleType&);
        void InitToFloatingPoint();
        void InitToIntegral();

        void CorrectWithShifting();
        void CalculateMantissa();
        void Negative();

    private:
        Integer m_AbsNumerator;
        Integer m_AbsDenominator;
        // �õ����Ӻͷ�ĸ����ʼλ�Ĳ
        int m_Shifting;
        NumericalValueSymbol m_Symbol;
        uint64_t m_Mantissa;
        T m_Value;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H
