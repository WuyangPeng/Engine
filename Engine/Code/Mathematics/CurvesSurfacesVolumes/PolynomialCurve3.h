///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve3.h"
#include "Mathematics/Algebra/Polynomial.h"

namespace Mathematics
{
    template <typename Real>
    class PolynomialCurve3 : public SingleCurve3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialCurve3<Real>;
        using ParentType = SingleCurve3<Real>;
        using MathType = typename ParentType::MathType;

    public:
        PolynomialCurve3(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly, const Polynomial<Real>& zPoly);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetDegree() const;
        NODISCARD Polynomial<Real> GetXPolynomial() const;
        NODISCARD Polynomial<Real> GetYPolynomial() const;
        NODISCARD Polynomial<Real> GetZPolynomial() const;

        NODISCARD Vector3<Real> GetPosition(Real t) const noexcept override;
        NODISCARD Vector3<Real> GetFirstDerivative(Real t) const noexcept override;
        NODISCARD Vector3<Real> GetSecondDerivative(Real t) const noexcept override;
        NODISCARD Vector3<Real> GetThirdDerivative(Real t) const noexcept override;

    protected:
        Polynomial<Real> xPoly;
        Polynomial<Real> yPoly;
        Polynomial<Real> zPoly;
        Polynomial<Real> xDer1;
        Polynomial<Real> yDer1;
        Polynomial<Real> zDer1;
        Polynomial<Real> xDer2;
        Polynomial<Real> yDer2;
        Polynomial<Real> zDer2;
        Polynomial<Real> xDer3;
        Polynomial<Real> yDer3;
        Polynomial<Real> zDer3;
    };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_H
