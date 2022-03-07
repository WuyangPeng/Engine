///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 17:16)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H
#define MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Integer.h"
#include "IntegerTraits.h"
#include "RationalFwd.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

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

        NODISCARD uint64_t GetNumeratorMantissa() const;
        NODISCARD uint64_t GetDenominatorMantissa() const;
        NODISCARD NumericalValueSymbol GetSymbol() const;
        NODISCARD int GetNumeratorShifting() const;
        NODISCARD int GetDenominatorShifting() const;
        NODISCARD int GetMaxShifting() const;
        NODISCARD int GetReducibilityShifting() const;

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
