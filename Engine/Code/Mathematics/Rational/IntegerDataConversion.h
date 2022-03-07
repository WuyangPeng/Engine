///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 16:25)

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

        NODISCARD T GetValue() const noexcept;

    private:
        void Init(const SignedIntegerType&);
        void Init(const UnsignedIntegerType&);
        void Init(const FloatType&);
        void Init(const DoubleType&);
        void InitToFloatingPoint();
        void CalculateMantissa();
        void CalculateConversionValue();
        void Negative() noexcept;
        void SignedIntegerNegative();

    private:
        IntegerData absData;
        int shifting;
        uint64_t mantissa;
        NumericalValueSymbol symbol;
        T value;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
