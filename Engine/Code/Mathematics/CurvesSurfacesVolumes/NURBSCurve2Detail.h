// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:01)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_DETAIL_H

#include "NURBSCurve2.h"

namespace Mathematics
{

template <typename Real>
NURBSCurve2<Real>::NURBSCurve2 (int numCtrlPoints,const Vector2<Real>* ctrlPoint, const Real* ctrlWeight, int degree,bool loop, bool open)
	: SingleCurve2<Real>{ Math<Real>::GetValue(0), Math::GetValue(1) }, mLoop{ loop }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mReplicate = (loop ? (open ? 1 : degree) : 0);
    CreateControl(ctrlPoint, ctrlWeight);
    mBasis.Create(mNumCtrlPoints + mReplicate, degree, open);
}

template <typename Real>
NURBSCurve2<Real>::NURBSCurve2 (int numCtrlPoints, const Vector2<Real>* ctrlPoint, const Real* ctrlWeight, int degree,bool loop, const Real* knot)
	: SingleCurve2<Real>{ Math<Real>::GetValue(0), Math::GetValue(1) }, mLoop{ loop }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mReplicate = (loop ? 1 : 0);
    CreateControl(ctrlPoint, ctrlWeight);
    mBasis.Create(mNumCtrlPoints + mReplicate, degree, knot);
}

template <typename Real>
NURBSCurve2<Real>::~NURBSCurve2 ()
{
    DELETE1(mCtrlPoint);
    DELETE1(mCtrlWeight);
}

template <typename Real>
void NURBSCurve2<Real>::CreateControl (const Vector2<Real>* ctrlPoint, const Real* ctrlWeight)
{
	auto newNumCtrlPoints = mNumCtrlPoints + mReplicate;

    mCtrlPoint = nullptr;  // NEW1<Vector2<Real> >(newNumCtrlPoints);
    memcpy(mCtrlPoint, ctrlPoint, mNumCtrlPoints*sizeof(Vector2<Real>));

    mCtrlWeight = nullptr;  // NEW1<Real>(newNumCtrlPoints);
    memcpy(mCtrlWeight, ctrlWeight, mNumCtrlPoints*sizeof(Real));

    for (auto i = 0; i < mReplicate; ++i)
    {
        mCtrlPoint[mNumCtrlPoints + i] = ctrlPoint[i];
        mCtrlWeight[mNumCtrlPoints + i] = ctrlWeight[i];
    }
}

template <typename Real>
int NURBSCurve2<Real>::GetNumCtrlPoints () const
{
    return mNumCtrlPoints;
}

template <typename Real>
int NURBSCurve2<Real>::GetDegree () const
{
    return mBasis.GetDegree();
}

template <typename Real>
bool NURBSCurve2<Real>::IsOpen () const
{
    return mBasis.IsOpen();
}

template <typename Real>
bool NURBSCurve2<Real>::IsUniform () const
{
    return mBasis.IsUniform();
}

template <typename Real>
bool NURBSCurve2<Real>::IsLoop () const
{
    return mLoop;
}

template <typename Real>
void NURBSCurve2<Real>::SetControlPoint (int i, const Vector2<Real>& ctrl)
{
    if (0 <= i && i < mNumCtrlPoints)
    {
        // Set the control point.
        mCtrlPoint[i] = ctrl;

        // Set the replicated control point.
        if (i < mReplicate)
        {
            mCtrlPoint[mNumCtrlPoints + i] = ctrl;
        }
    }
}

template <typename Real>
Vector2<Real> NURBSCurve2<Real>::GetControlPoint (int i) const
{
    if (0 <= i && i < mNumCtrlPoints)
    {
        return mCtrlPoint[i];
    }

	return Vector2<Real>{ Math<Real>::maxReal, Math<Real>::maxReal };
}

template <typename Real>
void NURBSCurve2<Real>::SetControlWeight (int i, Real weight)
{
    if (0 <= i && i < mNumCtrlPoints)
    {
        // Set the control weight.
        mCtrlWeight[i] = weight;

        // Set the replicated control weight.
        if (i < mReplicate)
        {
            mCtrlWeight[mNumCtrlPoints + i] = weight;
        }
    }
}

template <typename Real>
Real NURBSCurve2<Real>::GetControlWeight (int i) const
{
    if (0 <= i && i < mNumCtrlPoints)
    {
        return mCtrlWeight[i];
    }

    return Math<Real>::maxReal;
}

template <typename Real>
void NURBSCurve2<Real>::SetKnot (int i, Real knot)
{
    mBasis.SetKnot(i, knot);
}

template <typename Real>
Real NURBSCurve2<Real>::GetKnot (int i) const
{
    return mBasis.GetKnot(i);
}

template <typename Real>
void NURBSCurve2<Real>::Get (Real t, Vector2<Real>* pos, Vector2<Real>* der1, Vector2<Real>* der2, Vector2<Real>* der3) const
{
    int i, imin, imax;
    if (der3)
    {
        mBasis.Compute(t, 0, imin, imax);
        mBasis.Compute(t, 1, imin, imax);
        mBasis.Compute(t, 2, imin, imax);
        mBasis.Compute(t, 3, imin, imax);
    }
    else if (der2)
    {
        mBasis.Compute(t, 0, imin, imax);
        mBasis.Compute(t, 1, imin, imax);
        mBasis.Compute(t, 2, imin, imax);
    }
    else if (der1)
    {
        mBasis.Compute(t, 0, imin, imax);
        mBasis.Compute(t, 1, imin, imax);
    }
    else  // pos
    {
        mBasis.Compute(t, 0, imin, imax);
    }

    Real tmp;

    // Compute position.
	auto X = Vector2<Real>::sm_Zero;
	auto w = Math<Real>::GetValue(0);
    for (i = imin; i <= imax; ++i)
    {
        tmp = mBasis.GetD0(i)*mCtrlWeight[i];
        X += tmp*mCtrlPoint[i];
        w += tmp;
    }
    Real invW = (Math::GetValue(1))/w;
	auto P = invW*X;
    if (pos)
    {
        *pos = P;
    }

    if (!der1 && !der2 && !der3)
    {
        return;
    }

    // Compute first derivative.
	auto XDer1 = Vector2<Real>::sm_Zero;
	auto wDer1 = Math<Real>::GetValue(0);
    for (i = imin; i <= imax; ++i)
    {
        tmp = mBasis.GetD1(i)*mCtrlWeight[i];
        XDer1 += tmp*mCtrlPoint[i];
        wDer1 += tmp;
    }
	auto PDer1 = invW*(XDer1 - wDer1*P);
    if (der1)
    {
        *der1 = PDer1;
    }

    if (!der2 && !der3)
    {
        return;
    }

    // Compute second derivative.
	auto XDer2 = Vector2<Real>::sm_Zero;
	auto wDer2 = Math<Real>::GetValue(0);
    for (i = imin; i <= imax; ++i)
    {
        tmp = mBasis.GetD2(i)*mCtrlWeight[i];
        XDer2 += tmp*mCtrlPoint[i];
        wDer2 += tmp;
    }
	auto PDer2 = invW*(XDer2 - (Math::GetValue(2))*wDer1*PDer1 - wDer2*P);
    if (der2)
    {
        *der2 = PDer2;
    }

    if (!der3)
    {
        return;
    }

    // Compute third derivative.
	auto XDer3 = Vector2<Real>::sm_Zero;
	auto wDer3 = Math<Real>::GetValue(0);
    for (i = imin; i <= imax; i++)
    {
        tmp = mBasis.GetD3(i)*mCtrlWeight[i];
        XDer3 += tmp*mCtrlPoint[i];
        wDer3 += tmp;
    }
    if (der3)
    {
        *der3 = invW*(XDer3 - (static_cast<Real>(3))*wDer1*PDer2 - (static_cast<Real>(3))*wDer2*PDer1 - wDer3*P);
    }
}

template <typename Real>
BSplineBasis<Real>& NURBSCurve2<Real>::GetBasis ()
{
    return mBasis;
}

template <typename Real>
Vector2<Real> NURBSCurve2<Real>::GetPosition (Real t) const
{
    Vector2<Real> pos;
    Get(t, &pos, 0, 0, 0);
    return pos;
}

template <typename Real>
Vector2<Real> NURBSCurve2<Real>::GetFirstDerivative (Real t) const
{
    Vector2<Real> der1;
    Get(t, 0, &der1, 0, 0);
    return der1;
}

template <typename Real>
Vector2<Real> NURBSCurve2<Real>::GetSecondDerivative (Real t) const
{
    Vector2<Real> der2;
    Get(t, 0, 0, &der2, 0);
    return der2;
}

template <typename Real>
Vector2<Real> NURBSCurve2<Real>::GetThirdDerivative (Real t) const
{
    Vector2<Real> der3;
    Get(t, 0, 0, 0, &der3);
    return der3;
}

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_DETAIL_H