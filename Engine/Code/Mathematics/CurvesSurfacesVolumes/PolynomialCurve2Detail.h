// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:07)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_DETAIL_H

#include "PolynomialCurve2.h"

namespace Mathematics
{

template <typename Real>
PolynomialCurve2<Real>::PolynomialCurve2 (Polynomial<Real>* xPoly,
	Polynomial<Real>* yPoly)
	: SingleCurve2<Real>{ Real{}, (Real)1 }
{
    MATHEMATICS_ASSERTION_0(xPoly && yPoly, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(xPoly->GetDegree() == yPoly->GetDegree(), "Invalid input\n");

    mXPoly = xPoly;
    mYPoly = yPoly;
    mXDer1 = mXPoly->GetDerivative();
    mYDer1 = mYPoly->GetDerivative();
    mXDer2 = mXDer1.GetDerivative();
    mYDer2 = mYDer1.GetDerivative();
    mXDer3 = mXDer2.GetDerivative();
    mYDer3 = mYDer2.GetDerivative();
}

template <typename Real>
PolynomialCurve2<Real>::~PolynomialCurve2 ()
{
    DELETE0(mXPoly);
    DELETE0(mYPoly);
}

template <typename Real>
int PolynomialCurve2<Real>::GetDegree () const
{
    return mXPoly->GetDegree();
}

template <typename Real>
const Polynomial<Real>* PolynomialCurve2<Real>::GetXPolynomial() const
{
    return mXPoly;
}

template <typename Real>
const Polynomial<Real>* PolynomialCurve2<Real>::GetYPolynomial() const
{
    return mYPoly;
}

template <typename Real>
Vector2D<Real> PolynomialCurve2<Real>::GetPosition (Real t) const
{
    return Vector2D<Real>((*mXPoly)(t), (*mYPoly)(t));
}

template <typename Real>
Vector2D<Real> PolynomialCurve2<Real>::GetFirstDerivative (Real t) const
{
    return Vector2D<Real>(mXDer1(t), mYDer1(t));
}

template <typename Real>
Vector2D<Real> PolynomialCurve2<Real>::GetSecondDerivative (Real t) const
{
    return Vector2D<Real>(mXDer2(t) ,mYDer2(t));
}

template <typename Real>
Vector2D<Real> PolynomialCurve2<Real>::GetThirdDerivative (Real t) const
{
    return Vector2D<Real>(mXDer3(t), mYDer3(t));
}

 

}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_DETAIL_H