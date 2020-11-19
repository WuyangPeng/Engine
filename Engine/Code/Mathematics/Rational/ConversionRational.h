///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 16:47)

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

        [[nodiscard]] uint64_t GetNumeratorMantissa() const;
        [[nodiscard]] uint64_t GetDenominatorMantissa() const;
        [[nodiscard]] NumericalValueSymbol GetSymbol() const;
        [[nodiscard]] int GetNumeratorShifting() const;
        [[nodiscard]] int GetDenominatorShifting() const;
        [[nodiscard]] int GetMaxShifting() const;
        [[nodiscard]] int GetReducibilityShifting() const;

        template <int N>
        [[nodiscard]] bool IsCanConversion() const noexcept;

        template <int N>
        [[nodiscard]] const Integer<N> GetNumerator() const;

        template <int N>
        [[nodiscard]] const Integer<N> GetDenominator() const;

    private:
        void Init(T value, const SignedIntegerType&);
        void Init(T value, const UnsignedIntegerType&);
        void Init(T value, const FloatType&);
        void Init(T value, const DoubleType&);
        void InitFloatingPoint(T value);
        [[nodiscard]] int GetAssignmentNumeratorShifting(int bit) const;
        [[nodiscard]] int GetAssignmentDenominatorShifting(int bit) const;
        [[nodiscard]] uint64_t GetAssignmentNumeratorMantissa(int bit) const;
        [[nodiscard]] uint64_t GetAssignmentDenominatorMantissa(int bit) const;

    private:
        int m_NumeratorShifting;
        int m_DenominatorShifting;
        uint64_t m_NumeratorMantissa;
        uint64_t m_DenominatorMantissa;
        NumericalValueSymbol m_Symbol;
        int m_MaxShifting;
        int m_ReducibilityShifting;
    };
}

#endif  // MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_H
