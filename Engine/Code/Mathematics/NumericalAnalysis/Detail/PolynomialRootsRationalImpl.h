///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 16:00)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Flags/QuantityType.h"
#include "Mathematics/Rational/SignRational.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_HIDDEN_DECLARE PolynomialRootsRationalImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialRootsRationalImpl<Real>;
        using PolynomialRational = SignRational<16 * sizeof(Real)>;
        using Math = Math<Real>;

    public:
        explicit PolynomialRootsRationalImpl(Real epsilon = Math::sm_Epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] Real GetRoot(int index) const;
        [[nodiscard]] int GetMultiplicity(int index) const;

        // p(x) = constant + once * x
        [[nodiscard]] bool Linear(Real constant, Real once);
        [[nodiscard]] bool Linear(const PolynomialRational& constant, const PolynomialRational& once);

        // p(x) = constant + once * x + secondary * x^2
        // m(x) = constant + once * x + x^2
        [[nodiscard]] bool Quadratic(Real constant, Real once, Real secondary);
        [[nodiscard]] bool Quadratic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary);
        [[nodiscard]] bool Quadratic(const PolynomialRational& constant, const PolynomialRational& once);

        // p(x) = constant + once * x + secondary * x^2 + thrice * x^3
        // m(x) = constant + once * x + secondary * x^2 + x^3
        [[nodiscard]] bool Cubic(Real constant, Real once, Real secondary, Real thrice);
        [[nodiscard]] bool Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice);
        [[nodiscard]] bool Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary);

        // p(x) = constant + once * x + secondary * x^2 + thrice * x^3 + quartic * x^4 (首一当 c4 = 1)
        // m(x) = constant + once * x + secondary * x^2 + thrice * x^3 + x^4
        [[nodiscard]] bool Quartic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
        [[nodiscard]] bool Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary,
                                   const PolynomialRational& thrice, const PolynomialRational& quartic);
        [[nodiscard]] bool Quartic(const PolynomialRational& constant, const PolynomialRational& once,
                                   const PolynomialRational& secondary, const PolynomialRational& thrice);

    private:
        void SortRoots() noexcept;

    private:
        static const PolynomialRational GetZero();
        static const PolynomialRational GetOne();

        static constexpr auto sm_MaxRoot = 4;
        using RootType = std::array<Real, sm_MaxRoot>;
        using MultiplicityType = std::array<int, sm_MaxRoot>;

        int m_Quantity;
        RootType m_Root;
        MultiplicityType m_Multiplicity;
        Real m_Epsilon;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_IMPL_H
