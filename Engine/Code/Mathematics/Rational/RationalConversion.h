///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:07)

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

        NODISCARD T GetValue() const noexcept;

    private:
        void Init(const SignedIntegerType&);
        void Init(const UnsignedIntegerType&);
        void Init(const FloatType&);
        void Init(const DoubleType&);
        void InitToFloatingPoint();
        void InitToIntegral();

        void CorrectWithShifting();
        void CalculateMantissa();
        void Negative() noexcept;

    private:
        Integer absNumerator;
        Integer absDenominator;
        // �õ����Ӻͷ�ĸ����ʼλ�Ĳ
        int shifting;
        NumericalValueSymbol symbol;
        uint64_t mantissa;
        T value;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H
