///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 16:10)

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
    class PolynomialRootsRationalImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialRootsRationalImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialRootsRationalImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialRootsRationalImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialRootsRational final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using PolynomialRootsRationalImpl = PolynomialRootsRationalImpl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(PolynomialRootsRational, DESTRUCTOR_DEFAULT);

        using PolynomialRational = SignRational<16 * sizeof(Real)>;
        using Math = Math<Real>;

    public:
        explicit PolynomialRootsRational(Real epsilon = Math::sm_Epsilon);

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
        IMPL_TYPE_DECLARE(PolynomialRootsRational);
    };

    using FloatPolynomialRootsRational = PolynomialRootsRational<float>;
    using DoublePolynomialRootsRational = PolynomialRootsRational<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_H
