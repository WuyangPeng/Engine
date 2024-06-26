/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:28)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H
#define MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Integer.h"
#include "IntegerTraits.h"
#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

namespace Mathematics
{
    template <typename T>
    class ConversionRational final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = ConversionRational<T>;

        using TraitsType = typename IntegerTraits<T>::TraitsType;

    public:
        explicit ConversionRational(T value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint64_t GetNumeratorMantissa() const noexcept;
        NODISCARD uint64_t GetDenominatorMantissa() const noexcept;
        NODISCARD NumericalValueSymbol GetSymbol() const noexcept;
        NODISCARD int GetNumeratorShifting() const noexcept;
        NODISCARD int GetDenominatorShifting() const noexcept;
        NODISCARD int GetMaxShifting() const noexcept;
        NODISCARD int GetReducibilityShifting() const noexcept;

        template <int N>
        NODISCARD bool IsCanConversion() const noexcept;

        template <int N>
        NODISCARD Integer<N> GetNumerator() const;

        template <int N>
        NODISCARD Integer<N> GetDenominator() const;

    private:
        void Init(T value, const SignedIntegerType&);
        void Init(T value, const UnsignedIntegerType&);
        void Init(T value, const FloatType&);
        void Init(T value, const DoubleType&);
        void InitFloatingPoint(T value);
        NODISCARD int GetAssignmentNumeratorShifting(int bit) const;
        NODISCARD int GetAssignmentDenominatorShifting(int bit) const;
        NODISCARD uint64_t GetAssignmentNumeratorMantissa(int bit) const;
        NODISCARD uint64_t GetAssignmentDenominatorMantissa(int bit) const;

    private:
        int numeratorShifting;
        int denominatorShifting;
        uint64_t numeratorMantissa;
        uint64_t denominatorMantissa;
        NumericalValueSymbol symbol;
        int maxShifting;
        int reducibilityShifting;
    };
}

#endif  // MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H
