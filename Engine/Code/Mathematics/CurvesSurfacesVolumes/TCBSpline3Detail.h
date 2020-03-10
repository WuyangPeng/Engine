// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:10)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_DETAIL_H

#include "TCBSpline3.h"

namespace Mathematics
{

template <typename Real>
TCBSpline3<Real>::TCBSpline3 (int numSegments, Real* times,Vector3D<Real>* points, Real* tension, Real* continuity, Real* bias)
    :MultipleCurve3<Real>(numSegments,times)
{
    // TO DO.  Add 'boundary type' just as in natural splines.
    MATHEMATICS_ASSERTION_0(mNumSegments >= 3, "Not enough segments\n");

    // All four of these arrays have mNumSegments+1 elements.
    mPoints = points;
    mTension = tension;
    mContinuity = continuity;
    mBias = bias;

    mA = NEW1<Vector3D<Real> >(mNumSegments);
    mB = NEW1<Vector3D<Real> >(mNumSegments);
    mC = NEW1<Vector3D<Real> >(mNumSegments);
    mD = NEW1<Vector3D<Real> >(mNumSegments);

    // For now, treat the first point as if it occurred twice.
    ComputePoly(0, 0, 1, 2);

    for (int i = 1; i < mNumSegments - 1; ++i)
    {
        ComputePoly(i - 1, i, i + 1, i + 2);
    }

    // For now, treat the last point as if it occurred twice.
    ComputePoly(mNumSegments - 2, mNumSegments - 1, mNumSegments, mNumSegments);
}

template <typename Real>
TCBSpline3<Real>::~TCBSpline3 ()
{
    DELETE1(mPoints);
    DELETE1(mTension);
    DELETE1(mContinuity);
    DELETE1(mBias);
    DELETE1(mA);
    DELETE1(mB);
    DELETE1(mC);
    DELETE1(mD);
}

template <typename Real>
const Vector3D<Real>* TCBSpline3<Real>::GetPoints () const
{
    return mPoints;
}

template <typename Real>
const Real* TCBSpline3<Real>::GetTensions () const
{
    return mTension;
}

template <typename Real>
const Real* TCBSpline3<Real>::GetContinuities () const
{
    return mContinuity;
}

template <typename Real>
const Real* TCBSpline3<Real>::GetBiases () const
{
    return mBias;
}

template <typename Real>
void TCBSpline3<Real>::ComputePoly (int i0, int i1, int i2, int i3)
{
    Vector3D<Real> diff = mPoints[i2] - mPoints[i1];
    Real dt = mTimes[i2] - mTimes[i1];

    // Build multipliers at P1.
    Real oneMinusT0 = (Real)1 - mTension[i1];
    Real oneMinusC0 = (Real)1 - mContinuity[i1];
    Real onePlusC0 = (Real)1 + mContinuity[i1];
    Real oneMinusB0 = (Real)1 - mBias[i1];
    Real onePlusB0 = (Real)1 + mBias[i1];
    Real adj0 = ((Real)2)*dt/(mTimes[i2] - mTimes[i0]);
    Real out0 = (Real{0.5})*adj0*oneMinusT0*onePlusC0*onePlusB0;
    Real out1 = (Real{0.5})*adj0*oneMinusT0*oneMinusC0*oneMinusB0;

    // Build outgoing tangent at P1.
    Vector3D<Real> TOut = out1*diff + out0*(mPoints[i1] - mPoints[i0]);

    // Build multipliers at point P2.
    Real oneMinusT1 = (Real)1 - mTension[i2];
    Real oneMinusC1 = (Real)1 - mContinuity[i2];
    Real onePlusC1 = (Real)1 + mContinuity[i2];
    Real oneMinusB1 = (Real)1 - mBias[i2];
    Real onePlusB1 = (Real)1 + mBias[i2];
    Real adj1 = ((Real)2)*dt/(mTimes[i3] - mTimes[i1]);
    Real in0 = (Real{0.5})*adj1*oneMinusT1*oneMinusC1*onePlusB1;
    Real in1 = (Real{0.5})*adj1*oneMinusT1*onePlusC1*oneMinusB1;

    // Build incoming tangent at P2.
    Vector3D<Real> TIn = in1*(mPoints[i3] - mPoints[i2]) + in0*diff;

    mA[i1] = mPoints[i1];
    mB[i1] = TOut;
    mC[i1] = ((Real)3)*diff - ((Real)2)*TOut - TIn;
    mD[i1] = ((Real)-2)*diff + TOut + TIn;
}

template <typename Real>
Vector3D<Real> TCBSpline3<Real>::GetPosition (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return mA[key] + dt*(mB[key] + dt*(mC[key] + dt*mD[key]));
}

template <typename Real>
Vector3D<Real> TCBSpline3<Real>::GetFirstDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return mB[key] + dt*(mC[key]*((Real)2) + mD[key]*(((Real)3)*dt));
}

template <typename Real>
Vector3D<Real> TCBSpline3<Real>::GetSecondDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return mC[key]*((Real)2) + mD[key]*(((Real)6)*dt);
}

template <typename Real>
Vector3D<Real> TCBSpline3<Real>::GetThirdDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return ((Real)6)*mD[key];
}

template <typename Real>
Real TCBSpline3<Real>::GetSpeedKey (int key, Real t) const
{
    Vector3D<Real> velocity = mB[key] + t*(mC[key]*((Real)2) + mD[key]*(((Real)3)*t));

	return Vector3DTools<Real>::VectorMagnitude( velocity);
}

template <typename Real>
Real TCBSpline3<Real>::GetLengthKey (int key, Real t0, Real t1) const
{
    SplineKey data(this, key);
	return RombergIntegral<Real, SplineKey>(8, t0, t1, GetSpeedWithDataKey, &data).GetValue();
}


template <typename Real>
Real Mathematics::TCBSpline3<Real>::GetSpeedWithDataKey(Real t, const SplineKey* data)
{
	return GetSpeedWithData(t, (void*)data);
}


// TCBSpline3::SplineKey

template <typename Real>
TCBSpline3<Real>::SplineKey::SplineKey (const TCBSpline3* spline, int key)
    :Spline(spline),Key(key)
{
}



 
}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_DETAIL_H