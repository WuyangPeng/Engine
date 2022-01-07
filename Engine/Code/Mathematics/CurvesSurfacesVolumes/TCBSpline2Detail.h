// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:10)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_DETAIL_H

#include "TCBSpline2.h"

namespace Mathematics
{

template <typename Real>
TCBSpline2<Real>::TCBSpline2 (int numSegments, Real* times, Vector2D<Real>* points, Real* tension, Real* continuity, Real* bias)
    : MultipleCurve2<Real>(numSegments,times)
{
    // TO DO.  Add 'boundary type' just as in natural splines.
    MATHEMATICS_ASSERTION_0(mNumSegments >= 3, "Not enough segments\n");

    // All four of these arrays have mNumSegments+1 elements.
    mPoints = points;
    mTension = tension;
    mContinuity = continuity;
    mBias = bias;

    mA = nullptr;  // NEW1<Vector2D<Real> >(mNumSegments);
    mB = nullptr;  // NEW1<Vector2D<Real> >(mNumSegments);
    mC = nullptr;  // NEW1<Vector2D<Real> >(mNumSegments);
    mD = nullptr;  // NEW1<Vector2D<Real> >(mNumSegments);

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
TCBSpline2<Real>::~TCBSpline2 ()
{
//     DELETE1(mPoints);
//     DELETE1(mTension);
//     DELETE1(mContinuity);
//     DELETE1(mBias);
//     DELETE1(mA);
//     DELETE1(mB);
//     DELETE1(mC);
//     DELETE1(mD);
}

template <typename Real>
const Vector2D<Real>* TCBSpline2<Real>::GetPoints () const
{
    return mPoints;
}

template <typename Real>
const Real* TCBSpline2<Real>::GetTensions () const
{
    return mTension;
}

template <typename Real>
const Real* TCBSpline2<Real>::GetContinuities () const
{
    return mContinuity;
}

template <typename Real>
const Real* TCBSpline2<Real>::GetBiases () const
{
    return mBias;
}

template <typename Real>
void TCBSpline2<Real>::ComputePoly (int i0, int i1, int i2, int i3)
{
    Vector2D<Real> diff = mPoints[i2] - mPoints[i1];
    Real dt = mTimes[i2] - mTimes[i1];

    // Build multipliers at P1.
    Real oneMinusT0 = Math::GetValue(1) - mTension[i1];
    Real oneMinusC0 = Math::GetValue(1) - mContinuity[i1];
    Real onePlusC0 = Math::GetValue(1) + mContinuity[i1];
    Real oneMinusB0 = Math::GetValue(1) - mBias[i1];
    Real onePlusB0 = Math::GetValue(1) + mBias[i1];
    Real adj0 = (Math::GetValue(2))*dt/(mTimes[i2] - mTimes[i0]);
    Real out0 = (Real{0.5})*adj0*oneMinusT0*onePlusC0*onePlusB0;
    Real out1 = (Real{0.5})*adj0*oneMinusT0*oneMinusC0*oneMinusB0;

    // Build outgoing tangent at P1.
    Vector2D<Real> TOut = out1*diff + out0*(mPoints[i1] - mPoints[i0]);

    // Build multipliers at point P2.
    Real oneMinusT1 = Math::GetValue(1) - mTension[i2];
    Real oneMinusC1 = Math::GetValue(1) - mContinuity[i2];
    Real onePlusC1 = Math::GetValue(1) + mContinuity[i2];
    Real oneMinusB1 = Math::GetValue(1) - mBias[i2];
    Real onePlusB1 = Math::GetValue(1) + mBias[i2];
    Real adj1 = (Math::GetValue(2))*dt/(mTimes[i3] - mTimes[i1]);
    Real in0 = (Real{0.5})*adj1*oneMinusT1*oneMinusC1*onePlusB1;
    Real in1 = (Real{0.5})*adj1*oneMinusT1*onePlusC1*oneMinusB1;

    // Build incoming tangent at P2.
    Vector2D<Real> TIn = in1*(mPoints[i3] - mPoints[i2]) + in0*diff;

    mA[i1] = mPoints[i1];
    mB[i1] = TOut;
    mC[i1] = (static_cast<Real>(3))*diff - (Math::GetValue(2))*TOut - TIn;
    mD[i1] = ((Real)-2)*diff + TOut + TIn;
}

template <typename Real>
Vector2D<Real> TCBSpline2<Real>::GetPosition (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return mA[key] + dt*(mB[key] + dt*(mC[key] + dt*mD[key]));
}

template <typename Real>
Vector2D<Real> TCBSpline2<Real>::GetFirstDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return mB[key] + dt*(mC[key]*(Math::GetValue(2)) + mD[key]*((static_cast<Real>(3))*dt));
}

template <typename Real>
Vector2D<Real> TCBSpline2<Real>::GetSecondDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return mC[key]*(Math::GetValue(2)) + mD[key]*(((Real)6)*dt);
}

template <typename Real>
Vector2D<Real> TCBSpline2<Real>::GetThirdDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    dt /= (mTimes[key + 1] - mTimes[key]);
    return ((Real)6)*mD[key];
}

template <typename Real>
Real TCBSpline2<Real>::GetSpeedKey (int key, Real t) const
{
    Vector2D<Real> velocity = mB[key] + t*(mC[key]*(Math::GetValue(2)) +  mD[key]*((static_cast<Real>(3))*t));

	return  Vector2DTools<Real>::VectorMagnitude(velocity);
}

template <typename Real>
Real TCBSpline2<Real>::GetLengthKey (int key, Real t0, Real t1) const
{
    SplineKey data(this, key);
	return RombergIntegral<Real, SplineKey>(8, t0, t1, GetSpeedWithDataKey, &data).GetValue();
}

template <typename Real>
Real Mathematics::TCBSpline2<Real>::GetSpeedWithDataKey(Real t, const SplineKey* data)
{
	return GetSpeedWithData(t, (void*)data);
}



// TCBSpline2::SplineKey

template <typename Real>
TCBSpline2<Real>::SplineKey::SplineKey (const TCBSpline2* spline, int key)
    : Spline(spline),Key(key)
{
}


 

}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_DETAIL_H