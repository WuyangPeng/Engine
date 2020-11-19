///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:13)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
    template <int N, typename T>
    class IntegerDataConversion final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = IntegerDataConversion<N, T>;
        using TraitsType = typename IntegerTraits<T>::TraitsType;
        using IntegerData = IntegerData<N>;

    public:
        // 返回值若被截断，抛出异常
        explicit IntegerDataConversion(const IntegerData& data);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] T GetValue() const;

    private:
        void Init(const SignedIntegerType&);
        void Init(const UnsignedIntegerType&);
        void Init(const FloatType&);
        void Init(const DoubleType&);
        void InitToFloatingPoint();
        void CalculateMantissa();
        void CalculateConversionValue();
        void Negative();
        void SignedIntegerNegative();

    private:
        IntegerData m_AbsData;
        int m_Shifting;
        uint64_t m_Mantissa;
        NumericalValueSymbol m_Symbol;
        T m_Value;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
