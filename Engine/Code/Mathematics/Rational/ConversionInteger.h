///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 13:46)

#ifndef MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H
#define MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
    template <typename T>
    class ConversionInteger final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = ConversionInteger<T>;
        using TraitsType = typename IntegerTraits<T>::TraitsType;

    public:
        explicit ConversionInteger(T value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetShifting() const noexcept;
        NODISCARD uint64_t GetMantissa() const noexcept;
        NODISCARD NumericalValueSymbol GetSymbol() const noexcept;
        NODISCARD int GetMaxMantissaBit() const;
        NODISCARD uint64_t GetShiftingMantissa() const noexcept;
        NODISCARD int GetBeginBlock() const noexcept;

        NODISCARD int GetMantissaSize() const noexcept;
        NODISCARD int GetCopySize() const noexcept;

    private:
        void Init(T value, const SignedIntegerType&);
        void Init(T value, const UnsignedIntegerType&);
        void Init(T value, const FloatType&);
        void Init(T value, const DoubleType&);
        void Amendment() noexcept;
        void ShiftingMantissa() noexcept;

    private:
        static constexpr auto blockSize = 16;

    private:
        int shifting;
        uint64_t mantissa;
        NumericalValueSymbol symbol;
        int maxMantissaBit;
        uint64_t shiftingMantissa;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H
