///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 14:14)

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

        [[nodiscard]] int GetShifting() const;
        [[nodiscard]] uint64_t GetMantissa() const;
        [[nodiscard]] NumericalValueSymbol GetSymbol() const noexcept;
        [[nodiscard]] int GetMaxMantissaBit() const;
        [[nodiscard]] uint64_t GetShiftingMantissa() const noexcept;
        [[nodiscard]] int GetBeginBlock() const noexcept;

        [[nodiscard]] int GetMantissaSize() const noexcept;
        [[nodiscard]] int GetCopySize() const noexcept;

    private:
        void Init(T value, const SignedIntegerType&);
        void Init(T value, const UnsignedIntegerType&);
        void Init(T value, const FloatType&);
        void Init(T value, const DoubleType&);
        void Amendment() noexcept;
        void ShiftingMantissa() noexcept;

    private:
        static constexpr auto sm_BlockSize = 16;

    private:
        int m_Shifting;
        uint64_t m_Mantissa;
        NumericalValueSymbol m_Symbol;
        int m_MaxMantissaBit;
        uint64_t m_ShiftingMantissa;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_CONVERSION_H
