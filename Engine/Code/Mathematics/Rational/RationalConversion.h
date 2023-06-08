///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:07)

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
        // 返回值若被截断，抛出异常
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
        // 得到分子和分母的起始位的差。
        int shifting;
        NumericalValueSymbol symbol;
        uint64_t mantissa;
        T value;
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_CONVERSION_H
