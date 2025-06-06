///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_DETAIL_H

#include "PolynomialCurve2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialCurve2<Real>::PolynomialCurve2(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly)
    : ParentType{ MathType::GetValue(0), MathType::GetValue(1) },
      xPoly{ xPoly },
      yPoly{ yPoly },
      xDer1{ xPoly.GetDerivative() },
      yDer1{ yPoly.GetDerivative() },
      xDer2{ xDer1.GetDerivative() },
      yDer2{ yDer1.GetDerivative() },
      xDer3{ xDer2.GetDerivative() },
      yDer3{ yDer2.GetDerivative() }
{
    MATHEMATICS_ASSERTION_0(xPoly.GetDegree() == yPoly.GetDegree(), "无效输入\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialCurve2<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::PolynomialCurve2<Real>::GetDegree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xPoly.GetDegree();
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::PolynomialCurve2<Real>::GetXPolynomial() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return xPoly;
}

template <typename Real>
Mathematics::Polynomial<Real> Mathematics::PolynomialCurve2<Real>::GetYPolynomial() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return yPoly;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::PolynomialCurve2<Real>::GetPosition(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2<Real>{ (xPoly)(t), (yPoly)(t) };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::PolynomialCurve2<Real>::GetFirstDerivative(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2<Real>{ xDer1(t), yDer1(t) };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::PolynomialCurve2<Real>::GetSecondDerivative(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2<Real>{ xDer2(t), yDer2(t) };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::PolynomialCurve2<Real>::GetThirdDerivative(Real t) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector2<Real>{ xDer3(t), yDer3(t) };
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_DETAIL_H