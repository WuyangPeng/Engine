///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_DETAIL_H

#include "PolynomialCurve3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialCurve3<Real>::PolynomialCurve3(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly, const Polynomial<Real>& zPoly)
    : ParentType{ MathType::GetValue(0), MathType::GetValue(1) },
      xPoly{ xPoly },
      yPoly{ yPoly },
      zPoly{ zPoly },
      xDer1{ xPoly.GetDerivative() },
      yDer1{ yPoly.GetDerivative() },
      zDer1{ zPoly.GetDerivative() },
      xDer2{ xDer1.GetDerivative() },
      yDer2{ yDer1.GetDerivative() },
      zDer2{ zDer1.GetDerivative() },
      xDer3{ xDer2.GetDerivative() },
      yDer3{ yDer2.GetDerivative() },
      zDer3{ zDer2.GetDerivative() }
{
    MATHEMATICS_ASSERTION_0(xPoly.GetDegree() == yPoly.GetDegree(), "无效输入\n");
    MATHEMATICS_ASSERTION_0(xPoly.GetDegree() == zPoly.GetDegree(), "无效输入\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialCurve3<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::PolynomialCurve3<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xPoly.GetDegree();
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::PolynomialCurve3<Real>::GetXPolynomial() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xPoly;
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::PolynomialCurve3<Real>::GetYPolynomial() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yPoly;
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::PolynomialCurve3<Real>::GetZPolynomial() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return zPoly;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::PolynomialCurve3<Real>::GetPosition(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3<Real>{ (xPoly)(t), (yPoly)(t), (zPoly)(t) };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::PolynomialCurve3<Real>::GetFirstDerivative(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3<Real>{ xDer1(t), yDer1(t), zDer1(t) };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::PolynomialCurve3<Real>::GetSecondDerivative(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3<Real>{ xDer2(t), yDer2(t), zDer2(t) };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::PolynomialCurve3<Real>::GetThirdDerivative(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3<Real>{ xDer3(t), yDer3(t), zDer3(t) };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_DETAIL_H