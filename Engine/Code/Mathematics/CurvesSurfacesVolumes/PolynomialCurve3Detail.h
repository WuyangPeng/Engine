// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:07)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_DETAIL_H

#include "PolynomialCurve3.h"

namespace Mathematics
{

template <typename Real>
PolynomialCurve3<Real>::PolynomialCurve3 (Polynomial<Real>* xPoly, Polynomial<Real>* yPoly, Polynomial<Real>* zPoly)
	: SingleCurve3<Real>{ Math<Real>::GetValue(0), Math::GetValue(1) }
{
    MATHEMATICS_ASSERTION_0(xPoly && yPoly && zPoly, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(xPoly->GetDegree() == yPoly->GetDegree(), "Invalid input\n");
    MATHEMATICS_ASSERTION_0(xPoly->GetDegree() == zPoly->GetDegree(), "Invalid input\n");

    mXPoly = xPoly;
    mYPoly = yPoly;
    mZPoly = zPoly;
    mXDer1 = mXPoly->GetDerivative();
    mYDer1 = mYPoly->GetDerivative();
    mZDer1 = mZPoly->GetDerivative();
    mXDer2 = mXDer1.GetDerivative();
    mYDer2 = mYDer1.GetDerivative();
    mZDer2 = mZDer1.GetDerivative();
    mXDer3 = mXDer2.GetDerivative();
    mYDer3 = mYDer2.GetDerivative();
    mZDer3 = mZDer2.GetDerivative();
}

template <typename Real>
PolynomialCurve3<Real>::~PolynomialCurve3 ()
{
    DELETE0(mXPoly);
    DELETE0(mYPoly);
    DELETE0(mZPoly);
}

template <typename Real>
int PolynomialCurve3<Real>::GetDegree () const
{
    return mXPoly->GetDegree();
}

template <typename Real>
const Polynomial<Real>* PolynomialCurve3<Real>::GetXPolynomial () const
{
    return mXPoly;
}

template <typename Real>
const Polynomial<Real>* PolynomialCurve3<Real>::GetYPolynomial () const
{
    return mYPoly;
}

template <typename Real>
const Polynomial<Real>* PolynomialCurve3<Real>::GetZPolynomial () const
{
    return mZPoly;
}

template <typename Real>
Vector3<Real> PolynomialCurve3<Real>::GetPosition (Real t) const
{
    return Vector3<Real>((*mXPoly)(t), (*mYPoly)(t), (*mZPoly)(t));
}

template <typename Real>
Vector3<Real> PolynomialCurve3<Real>::GetFirstDerivative (Real t) const
{
    return Vector3<Real>(mXDer1(t), mYDer1(t), mZDer1(t));
}

template <typename Real>
Vector3<Real> PolynomialCurve3<Real>::GetSecondDerivative (Real t) const
{
    return Vector3<Real>(mXDer2(t), mYDer2(t), mZDer2(t));
}

template <typename Real>
Vector3<Real> PolynomialCurve3<Real>::GetThirdDerivative (Real t) const
{
    return Vector3<Real>(mXDer3(t), mYDer3(t), mZDer3(t));
}

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_DETAIL_H