///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/15 16:59)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve2.h"
#include "Mathematics/Algebra/Polynomial.h"

namespace Mathematics
{
    template <typename Real>
    class PolynomialCurve2 : public SingleCurve2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialCurve2<Real>;
        using ParentType = SingleCurve2<Real>;
        using Math = ParentType::Math;

    public:
        PolynomialCurve2(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetDegree() const;
        NODISCARD Polynomial<Real> GetXPolynomial() const;
        NODISCARD Polynomial<Real> GetYPolynomial() const;

        NODISCARD Vector2<Real> GetPosition(Real t) const override;
        NODISCARD Vector2<Real> GetFirstDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetSecondDerivative(Real t) const override;
        NODISCARD Vector2<Real> GetThirdDerivative(Real t) const override;

    private:
        Polynomial<Real> xPoly;
        Polynomial<Real> yPoly;
        Polynomial<Real> xDer1;
        Polynomial<Real> yDer1;
        Polynomial<Real> xDer2;
        Polynomial<Real> yDer2;
        Polynomial<Real> xDer3;
        Polynomial<Real> yDer3;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_H
