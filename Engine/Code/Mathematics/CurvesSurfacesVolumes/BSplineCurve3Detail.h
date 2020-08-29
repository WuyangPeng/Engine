// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:36)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_DETAIL_H

#include "BSplineCurve3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BSPLINE_CURVE3_DETAIL)

#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26429)
template <typename Real>
Mathematics::BSplineCurve3<Real>
	::BSplineCurve3 (int numCtrlPoints,const Vector3D<Real>* ctrlPoint, int degree, bool loop, bool open)
	:SingleCurve3<Real>{ Math<Real>::GetValue(0), static_cast<Real>(1) }, mLoop{ loop }, mCtrlPoint{}
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mReplicate = (loop ? (open ? 1 : degree) : 0);
    CreateControl(ctrlPoint);
    mBasis.Create(mNumCtrlPoints + mReplicate, degree, open);
}

template <typename Real>
Mathematics::BSplineCurve3<Real>
	::BSplineCurve3 (int numCtrlPoints, const Vector3D<Real>* ctrlPoint, int degree, bool loop,const Real* knot)
	:SingleCurve3<Real>{ Math<Real>::GetValue(0), static_cast<Real>(1) }, mLoop{ loop }, mCtrlPoint{}
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mReplicate = (loop ? 1 : 0);
    CreateControl(ctrlPoint);
    mBasis.Create(mNumCtrlPoints + mReplicate, degree, knot);
}

template <typename Real>
Mathematics::BSplineCurve3<Real>
	::~BSplineCurve3 ()
{
	EXCEPTION_TRY
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
 DELETE1(mCtrlPoint);
#include STSTEM_WARNING_POP
}
EXCEPTION_ALL_CATCH(Mathematics) 
    
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>
	::CreateControl (const Vector3D<Real>* ctrlPoint)
{
	const auto newNumCtrlPoints = mNumCtrlPoints + mReplicate;

    mCtrlPoint = NEW1<Vector3D<Real> >(newNumCtrlPoints);
    memcpy(mCtrlPoint, ctrlPoint, mNumCtrlPoints*sizeof(Vector3D<Real>));

    for (auto i = 0; i < mReplicate; ++i)
    {
        mCtrlPoint[mNumCtrlPoints + i] = ctrlPoint[i];
    }
}

template <typename Real>
int Mathematics::BSplineCurve3<Real>
	::GetNumCtrlPoints () const noexcept
{
    return mNumCtrlPoints;
}

template <typename Real>
int Mathematics::BSplineCurve3<Real>
	::GetDegree () const noexcept
{
    return mBasis.GetDegree();
}

template <typename Real>
bool Mathematics::BSplineCurve3<Real>
	::IsOpen () const noexcept
{
    return mBasis.IsOpen();
}

template <typename Real>
bool Mathematics::BSplineCurve3<Real>
	::IsUniform () const noexcept
{
    return mBasis.IsUniform();
}

template <typename Real>
bool Mathematics::BSplineCurve3<Real>
	::IsLoop () const noexcept
{
    return mLoop;
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>::SetControlPoint(int i, const Vector3D<Real>& ctrl) noexcept
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
Mathematics::Vector3D<Real> Mathematics::BSplineCurve3<Real>::GetControlPoint(int i) const noexcept
{
    if (0 <= i && i < mNumCtrlPoints)
    {
        return mCtrlPoint[i];
    }

	return Vector3D<Real>{ Math<Real>::sm_MaxReal, Math<Real>::sm_MaxReal, Math<Real>::sm_MaxReal };
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>
	::SetKnot (int i, Real knot)
{
    mBasis.SetKnot(i, knot);
}

template <typename Real>
Real Mathematics::BSplineCurve3<Real>
	::GetKnot (int i) const
{
    return mBasis.GetKnot(i);
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>
	::Get (Real t, Vector3D<Real>* pos,Vector3D<Real>* der1, Vector3D<Real>* der2, Vector3D<Real>* der3) const
{
    int i = 0;
	int imin= 0;
	int imax= 0;
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
    else
    {
        mBasis.Compute(t, 0, imin, imax);
    }

    if (pos)
    {
        *pos = Vector3D<Real>::sm_Zero;
        for (i = imin; i <= imax; ++i)
        {
            *pos += mBasis.GetD0(i)*mCtrlPoint[i];
        }
    }

    if (der1)
    {
        *der1 = Vector3D<Real>::sm_Zero;
        for (i = imin; i <= imax; ++i)
        {
            *der1 += mBasis.GetD1(i)*mCtrlPoint[i];
        }
    }

    if (der2)
    {
        *der2 = Vector3D<Real>::sm_Zero;
        for (i = imin; i <= imax; ++i)
        {
            *der2 += mBasis.GetD2(i)*mCtrlPoint[i];
        }
    }

    if (der3)
    {
        *der3 = Vector3D<Real>::sm_Zero;
        for (i = imin; i <= imax; ++i)
        {
            *der3 += mBasis.GetD3(i)*mCtrlPoint[i];
        }
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>& Mathematics::BSplineCurve3<Real>
	::GetBasis () noexcept
{
    return mBasis;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::BSplineCurve3<Real>
	::GetPosition (Real t) const
{
    Vector3D<Real> pos;
    Get(t, &pos, 0, 0, 0);
    return pos;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::BSplineCurve3<Real>
	::GetFirstDerivative (Real t) const
{
    Vector3D<Real> der1;
    Get(t, 0, &der1, 0, 0);
    return der1;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::BSplineCurve3<Real>
	::GetSecondDerivative (Real t) const
{
    Vector3D<Real> der2;
    Get(t, 0, 0, &der2, 0);
    return der2;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::BSplineCurve3<Real>
	::GetThirdDerivative (Real t) const
{
    Vector3D<Real> der3;
    Get(t, 0, 0, 0, &der3);
    return der3;
}
#include STSTEM_WARNING_POP

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BSPLINE_CURVE3_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_DETAIL_H