/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:29)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

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
        // ����ֵ�����ضϣ��׳��쳣
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
