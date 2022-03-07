// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:50)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_DEATIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_DEATIL_H
 
#include "CubicPolynomialCurve2.h"

namespace Mathematics
{

template <typename Real>
CubicPolynomialCurve2<Real>::CubicPolynomialCurve2
    (Polynomial<Real>* xPoly, Polynomial<Real>* yPoly)
	:PolynomialCurve2<Real>{ xPoly, yPoly }
{
    MATHEMATICS_ASSERTION_0(xPoly && yPoly, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(xPoly->GetDegree() == 3, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(yPoly->GetDegree() == 3, "Invalid input\n");

    mNumVertices = 0;
    mVertices = 0;
}

template <typename Real>
CubicPolynomialCurve2<Real>::~CubicPolynomialCurve2 ()
{
    DELETE1(mVertices);
}

template <typename Real>
int CubicPolynomialCurve2<Real>::GetNumVertices () const
{
    return mNumVertices;
}

template <typename Real>
const Vector2<Real>* CubicPolynomialCurve2<Real>::GetVertices () const
{
    return mVertices;
}

template <typename Real>
Vector2<Real>* CubicPolynomialCurve2<Real>::GetVertices ()
{
    return mVertices;
}

template <typename Real>
void CubicPolynomialCurve2<Real>::Tessellate (int level)
{
    // Vertices V = (2^L+1).
	auto twoPowL = (1 << level);
    mNumVertices = twoPowL + 1;
    DELETE1(mVertices);
    mVertices = nullptr;  // NEW1<Vector2<Real> >(mNumVertices);

    // Indices of endpoints, I[t].
    IntervalParameters IP;
    IP.I0 = 0;
    IP.I1 = twoPowL;

    // Vertices for subdivision.
    Vector2<Real>* X = mVertices;
    X[IP.I0] = GetPosition(mTMin);
    X[IP.I1] = GetPosition(mTMax);

    // Recursive subdivision.
    if (level > 0)
    {
        IP.Xuu[0] = GetSecondDerivative(mTMin);
        IP.Xuu[1] = GetSecondDerivative(mTMax);
        Subdivide(--level, Real{0.25}, X, IP);
    }
}

template <typename Real>
void CubicPolynomialCurve2<Real>::Subdivide (int level, Real dsqr, Vector2<Real>* X, IntervalParameters& IP)
{
    // Subdivision index.
    int IMid = (IP.I0 + IP.I1) >> 1;

    // Vertices.
	auto XuuM = (Real{0.5})*(IP.Xuu[0] + IP.Xuu[1]);
    X[IMid] = (Real{0.5})*(X[IP.I0] + X[IP.I1] - dsqr*XuuM);

    // Recurse on two children.
    if (level > 0)
    {
        --level;
        dsqr *= Real{0.25};

        IntervalParameters subIP;

        // Subinterval [t0,tM].
        subIP.I0 = IP.I0;
        subIP.I1 = IMid;
        subIP.Xuu[0] = IP.Xuu[0];
        subIP.Xuu[1] = XuuM;
        Subdivide(level, dsqr, X, subIP);

        // Subinterval [tM,t1].
        subIP.I0 = IMid;
        subIP.I1 = IP.I1;
        subIP.Xuu[0] = XuuM;
        subIP.Xuu[1] = IP.Xuu[1];
        Subdivide(level, dsqr, X, subIP);
    }
}

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_DEATIL_H
