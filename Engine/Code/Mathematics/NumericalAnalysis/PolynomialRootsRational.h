///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/16 21:39)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/QuantityType.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/SignRational.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class PolynomialRootsRational final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialRootsRational<Real>;

        static constexpr auto signRationalSize = 16;
        using PolynomialRational = SignRational<signRationalSize * sizeof(Real)>;
        using Math = Math<Real>;

    public:
        explicit PolynomialRootsRational(Real epsilon = Math::epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Real GetRoot(int index) const;
        NODISCARD int GetMultiplicity(int index) const;

        // p(x) = constant + once * x
        NODISCARD bool Linear(Real constant, Real once);
        NODISCARD bool Linear(const PolynomialRational& constant, const PolynomialRational& once);

        // p(x) = constant + once * x + secondary * x^2
        // m(x) = constant + once * x + x^2
        NODISCARD bool Quadratic(Real constant, Real once, Real secondary);
        NODISCARD bool Quadratic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary);
        NODISCARD bool Quadratic(const PolynomialRational& constant, const PolynomialRational& once);

        // p(x) = constant + once * x + secondary * x^2 + thrice * x^3
        // m(x) = constant + once * x + secondary * x^2 + x^3
        NODISCARD bool Cubic(Real constant, Real once, Real secondary, Real thrice);
        NODISCARD bool Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice);
        NODISCARD bool Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary);

        // p(x) = constant + once * x + secondary * x^2 + thrice * x^3 + quartic * x^4 (首一当 c4 = 1)
        // m(x) = constant + once * x + secondary * x^2 + thrice * x^3 + x^4
        NODISCARD bool Quartic(Real constant, Real once, Real secondary, Real thrice, Real quartic);
        NODISCARD bool Quartic(const PolynomialRational& constant,
                               const PolynomialRational& once,
                               const PolynomialRational& secondary,
                               const PolynomialRational& thrice,
                               const PolynomialRational& quartic);
        NODISCARD bool Quartic(const PolynomialRational& constant,
                               const PolynomialRational& once,
                               const PolynomialRational& secondary,
                               const PolynomialRational& thrice);

    private:
        void SortRoots() noexcept;

    private:
        static PolynomialRational GetZero() noexcept;
        static PolynomialRational GetOne();

        static constexpr auto maxRoot = 4;
        using RootType = std::array<Real, maxRoot>;
        using MultiplicityType = std::array<int, maxRoot>;

        int quantity;
        RootType root;
        MultiplicityType multiplicity;
        Real epsilon;
    };

    using PolynomialRootsRationalF = PolynomialRootsRational<float>;
    using PolynomialRootsRationalD = PolynomialRootsRational<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H
