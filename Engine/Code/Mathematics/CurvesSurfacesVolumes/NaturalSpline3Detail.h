// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:00)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_DETAIL_H

#include "NaturalSpline3.h"

namespace Mathematics
{

template <typename Real>
NaturalSpline3<Real>::NaturalSpline3 (BoundaryType type, int numSegments,Real* times, Vector3D<Real>* points)
	: MultipleCurve3<Real>{ numSegments, times }
{
    mA = points;

    switch (type)
    {
        case BT_FREE:
        {
            CreateFreeSpline();
            break;
        }
        case BT_CLAMPED:
        {
			auto derStart = mA[1] - mA[0];
			auto derFinal = mA[mNumSegments] - mA[mNumSegments-1];
            CreateClampedSpline(derStart, derFinal);
            break;
        }
        case BT_CLOSED:
        {
            CreateClosedSpline();
            break;
        }
    }
}

template <typename Real>
NaturalSpline3<Real>::NaturalSpline3 (int numSegments, Real* times,Vector3D<Real>* points, const Vector3D<Real>& derivativeStart,const Vector3D<Real>& derivativeFinal)
	:MultipleCurve3<Real>{ numSegments, times }
{
    mA = points;
    CreateClampedSpline(derivativeStart, derivativeFinal);
}

template <typename Real>
NaturalSpline3<Real>::~NaturalSpline3 ()
{
    DELETE1(mA);
    DELETE1(mB);
    DELETE1(mC);
    DELETE1(mD);
}

template <typename Real>
void NaturalSpline3<Real>::CreateFreeSpline ()
{
    Real* dt = NEW1<Real>(mNumSegments);
    int i;
    for (i = 0; i < mNumSegments; ++i)
    {
        dt[i] = mTimes[i+1] - mTimes[i];
    }

    Real* d2t = NEW1<Real>(mNumSegments);
    for (i = 1; i < mNumSegments; ++i)
    {
        d2t[i] = mTimes[i+1] - mTimes[i-1];
    }

    Vector3D<Real>* alpha = NEW1<Vector3D<Real> >(mNumSegments);
    for (i = 1; i < mNumSegments; ++i)
    {
        Vector3D<Real> numer = (static_cast<Real>(3))*(dt[i-1]*mA[i+1] - d2t[i]*mA[i] + dt[i]*mA[i-1]);
        Real invDenom = (static_cast<Real>(1))/(dt[i-1]*dt[i]);
        alpha[i] = invDenom*numer;
    }

    Real* ell = NEW1<Real>(mNumSegments + 1);
    Real* mu = NEW1<Real>(mNumSegments);
    Vector3D<Real>* z = NEW1<Vector3D<Real> >(mNumSegments + 1);
    Real inv;

    ell[0] = static_cast<Real>(1);
    mu[0] = Math<Real>::GetValue(0);
    z[0] = Vector3D<Real>::sm_Zero;
    for (i = 1; i < mNumSegments; ++i)
    {
        ell[i] = (static_cast<Real>(2))*d2t[i] - dt[i-1]*mu[i-1];
        inv = (static_cast<Real>(1))/ell[i];
        mu[i] = inv*dt[i];
        z[i] = inv*(alpha[i] - dt[i-1]*z[i-1]);
    }
    ell[mNumSegments] = static_cast<Real>(1);
    z[mNumSegments] = Vector3D<Real>::sm_Zero;

    mB = NEW1<Vector3D<Real> >(mNumSegments);
    mC = NEW1<Vector3D<Real> >(mNumSegments + 1);
    mD = NEW1<Vector3D<Real> >(mNumSegments);

    mC[mNumSegments] = Vector3D<Real>::sm_Zero;

    const Real oneThird = (static_cast<Real>(1))/static_cast<Real>(3);
    for (i = mNumSegments-1; i >= 0; --i)
    {
        mC[i] = z[i] - mu[i]*mC[i+1];
        inv = (static_cast<Real>(1))/dt[i];
        mB[i] = inv*(mA[i+1] - mA[i]) - oneThird*dt[i]*(mC[i+1] + (static_cast<Real>(2))*mC[i]);
        mD[i] = oneThird*inv*(mC[i+1] - mC[i]);
    }

    DELETE1(dt);
    DELETE1(d2t);
    DELETE1(alpha);
    DELETE1(ell);
    DELETE1(mu);
    DELETE1(z);
}

template <typename Real>
void NaturalSpline3<Real>::CreateClampedSpline ( const Vector3D<Real>& derivativeStart, const Vector3D<Real>& derivativeFinal)
{
    Real* dt = NEW1<Real>(mNumSegments);
    int i;
    for (i = 0; i < mNumSegments; ++i)
    {
        dt[i] = mTimes[i+1] - mTimes[i];
    }

    Real* d2t = NEW1<Real>(mNumSegments);
    for (i = 1; i < mNumSegments; ++i)
    {
        d2t[i] = mTimes[i+1] - mTimes[i-1];
    }

    Vector3D<Real>* alpha = NEW1<Vector3D<Real> >(mNumSegments + 1);
	auto inv = (static_cast<Real>(1))/dt[0];
    alpha[0] = (static_cast<Real>(3))*(inv*(mA[1] - mA[0]) - derivativeStart);
    inv = (static_cast<Real>(1))/dt[mNumSegments-1];
    alpha[mNumSegments] = (static_cast<Real>(3))*(derivativeFinal - inv*(mA[mNumSegments] - mA[mNumSegments-1]));
    for (i = 1; i < mNumSegments; ++i)
    {
        Vector3D<Real> numer = (static_cast<Real>(3))*(dt[i-1]*mA[i+1] - d2t[i]*mA[i] + dt[i]*mA[i-1]);
        Real invDenom = (static_cast<Real>(1))/(dt[i-1]*dt[i]);
        alpha[i] = invDenom*numer;
    }

    Real* ell = NEW1<Real>(mNumSegments + 1);
    Real* mu = NEW1<Real>(mNumSegments);
    Vector3D<Real>* z = NEW1<Vector3D<Real> >(mNumSegments + 1);

    ell[0] = (static_cast<Real>(2))*dt[0];
    mu[0] = Real{0.5};
    inv = (static_cast<Real>(1))/ell[0];
    z[0] = inv*alpha[0];

    for (i = 1; i < mNumSegments; ++i)
    {
        ell[i] = (static_cast<Real>(2))*d2t[i] - dt[i-1]*mu[i-1];
        inv = (static_cast<Real>(1))/ell[i];
        mu[i] = inv*dt[i];
        z[i] = inv*(alpha[i] - dt[i-1]*z[i-1]);
    }
    ell[mNumSegments] = dt[mNumSegments-1]*((static_cast<Real>(2)) - mu[mNumSegments-1]);
    inv = (static_cast<Real>(1))/ell[mNumSegments];
    z[mNumSegments] = inv*(alpha[mNumSegments] - dt[mNumSegments-1]* z[mNumSegments-1]);

    mB = NEW1<Vector3D<Real> >(mNumSegments);
    mC = NEW1<Vector3D<Real> >(mNumSegments + 1);
    mD = NEW1<Vector3D<Real> >(mNumSegments);

    mC[mNumSegments] = z[mNumSegments];

    const Real oneThird = (static_cast<Real>(1))/static_cast<Real>(3);
    for (i = mNumSegments-1; i >= 0; --i)
    {
        mC[i] = z[i] - mu[i]*mC[i+1];
        inv = (static_cast<Real>(1))/dt[i];
        mB[i] = inv*(mA[i+1] - mA[i]) - oneThird*dt[i]*(mC[i+1] + (static_cast<Real>(2))*mC[i]);
        mD[i] = oneThird*inv*(mC[i+1] - mC[i]);
    }

    DELETE1(dt);
    DELETE1(d2t);
    DELETE1(alpha);
    DELETE1(ell);
    DELETE1(mu);
    DELETE1(z);
}

template <typename Real>
void NaturalSpline3<Real>::CreateClosedSpline ()
{
    // TO DO.  A general linear system solver is used here.  The matrix
    // corresponding to this case is actually "cyclic banded", so a faster
    // linear solver can be used.  The current linear system code does not
    // have such a solver.

    Real* dt = NEW1<Real>(mNumSegments);
    int i;
    for (i = 0; i < mNumSegments; ++i)
    {
        dt[i] = mTimes[i+1] - mTimes[i];
    }

    // Construct matrix of system.
    VariableMatrix<Real> mat(mNumSegments + 1, mNumSegments + 1);
    mat[0][0] = static_cast<Real>(1);
    mat[0][mNumSegments] = (Real)-1;
    for (i = 1; i <= mNumSegments-1; ++i)
    {
        mat[i][i-1] = dt[i-1];
        mat[i][i  ] = (static_cast<Real>(2))*(dt[i-1] + dt[i]);
        mat[i][i+1] = dt[i];
    }
    mat[mNumSegments][mNumSegments - 1] = dt[mNumSegments - 1];
    mat[mNumSegments][0] = (static_cast<Real>(2))*(dt[mNumSegments - 1] + dt[0]);
    mat[mNumSegments][1] = dt[0];

    // Construct right-hand side of system.
    mC = NEW1<Vector3D<Real> >(mNumSegments + 1);
    mC[0] = Vector3D<Real>::sm_Zero;
    Real inv0, inv1;
    for (i = 1; i <= mNumSegments-1; ++i)
    {
        inv0 = (static_cast<Real>(1))/dt[i];
        inv1 = (static_cast<Real>(1))/dt[i-1];
        mC[i] = (static_cast<Real>(3))*(inv0*(mA[i+1] - mA[i]) - inv1*(mA[i] - mA[i-1]));
    }
    inv0 = (static_cast<Real>(1))/dt[0];
    inv1 = (static_cast<Real>(1))/dt[mNumSegments-1];
    mC[mNumSegments] = (static_cast<Real>(3))*(inv0*(mA[1] - mA[0]) -inv1*(mA[0] - mA[mNumSegments-1]));

    // Solve the linear systems.
    Real* input = NEW1<Real>(mNumSegments + 1);
    Real* output = NEW1<Real>(mNumSegments + 1);

    for (i = 0; i <= mNumSegments; ++i)
    {
        input[i] = mC[i][0];
    }
    LinearSystem<Real>().Solve(mat, input, output);
    for (i = 0; i <= mNumSegments; ++i)
    {
        mC[i][0] = output[i];
    }

    for (i = 0; i <= mNumSegments; ++i)
    {
        input[i] = mC[i][1];
    }
    LinearSystem<Real>().Solve(mat, input, output);
    for (i = 0; i <= mNumSegments; ++i)
    {
        mC[i][1] = output[i];
    }

    for (i = 0; i <= mNumSegments; ++i)
    {
        input[i] = mC[i][2];
    }
    LinearSystem<Real>().Solve(mat, input, output);
    for (i = 0; i <= mNumSegments; ++i)
    {
        mC[i][2] = output[i];
    }

    DELETE1(input);
    DELETE1(output);
    // End linear system solving.

    const Real oneThird = (static_cast<Real>(1))/static_cast<Real>(3);
    mB = NEW1<Vector3D<Real> >(mNumSegments);
    mD = NEW1<Vector3D<Real> >(mNumSegments);
    for (i = 0; i < mNumSegments; ++i)
    {
        inv0 = (static_cast<Real>(1))/dt[i];
        mB[i] = inv0*(mA[i+1] - mA[i]) - oneThird*(mC[i+1] + (static_cast<Real>(2))*mC[i])*dt[i];
        mD[i] = oneThird*inv0*(mC[i+1] - mC[i]);
    }

    DELETE1(dt);
}

template <typename Real>
const Vector3D<Real>* NaturalSpline3<Real>::GetPoints () const
{
    return mA;
}

template <typename Real>
Vector3D<Real> NaturalSpline3<Real>::GetPosition (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    return mA[key] + dt*(mB[key] + dt*(mC[key] + dt*mD[key]));
}

template <typename Real>
Vector3D<Real> NaturalSpline3<Real>::GetFirstDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    return mB[key] + dt*((static_cast<Real>(2))*mC[key] + (static_cast<Real>(3))*dt*mD[key]);
}

template <typename Real>
Vector3D<Real> NaturalSpline3<Real>::GetSecondDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    return (static_cast<Real>(2))*mC[key] + ((Real)6)*dt*mD[key];
}

template <typename Real>
Vector3D<Real> NaturalSpline3<Real>::GetThirdDerivative (Real t) const
{
    int key;
    Real dt;
    GetKeyInfo(t, key, dt);
    return ((Real)6)*mD[key];
}

template <typename Real>
Real NaturalSpline3<Real>::GetSpeedKey (int key, Real t) const
{
    Vector3D<Real> velocity = mB[key] + t*((static_cast<Real>(2))*mC[key] +  (static_cast<Real>(3))*t*mD[key]);

    return  Vector3DTools<Real>::VectorMagnitude(velocity);
}

template <typename Real>
Real NaturalSpline3<Real>::GetLengthKey (int key, Real t0, Real t1) const
{
    SplineKey data(this, key);
    return RombergIntegral<Real,SplineKey>(8, t0, t1, GetSpeedWithDataKey,  &data).GetValue();
}


template <typename Real>
Real Mathematics::NaturalSpline3<Real>::GetSpeedWithDataKey(Real t, const SplineKey* data)
{
	return GetSpeedWithData(t,(void*)data);
}


// NaturalSpline3::SplineKey

template <typename Real>
NaturalSpline3<Real>::SplineKey::SplineKey (const NaturalSpline3* spline,
    int key)
	: Spline{ spline }, Key{ key }
{
}


}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_DETAIL_H