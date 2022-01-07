// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:35)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE2_DETAIL_H

#include "BSplineCurve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BSPLINE_CURVE2_DETAIL)


#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26429)

template <typename Real>
Mathematics::BSplineCurve2<Real>
	::BSplineCurve2 (int numCtrlPoints,const Vector2D<Real>* ctrlPoint, int degree, bool loop, bool open)
	:SingleCurve2<Real>{ Math::GetValue(0), Math::GetValue(1) }, mLoop{ loop }, mCtrlPoint{}
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mReplicate = (loop ? (open ? 1 : degree) : 0);
    CreateControl(ctrlPoint);
    mBasis.Create(mNumCtrlPoints+mReplicate, degree, open);
}

template <typename Real>
Mathematics::BSplineCurve2<Real>
	::BSplineCurve2 (int numCtrlPoints,const Vector2D<Real>* ctrlPoint, int degree, bool loop, const Real* knot)
	:SingleCurve2<Real>(Math ::GetValue(0), Math::GetValue(1)), mLoop(loop), mCtrlPoint{}
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints-1, "Invalid input\n");

    mNumCtrlPoints = numCtrlPoints;
    mReplicate = (loop ? 1 : 0);
    CreateControl(ctrlPoint);
    mBasis.Create(mNumCtrlPoints + mReplicate, degree, knot);
}

template <typename Real>
Mathematics::BSplineCurve2<Real>
	::~BSplineCurve2 ()
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
void Mathematics::BSplineCurve2<Real>
	::CreateControl (const Vector2D<Real>* ctrlPoint)
{
	const auto newNumCtrlPoints = mNumCtrlPoints + mReplicate;

    mCtrlPoint = NEW1<Vector2D<Real> >(newNumCtrlPoints);
    memcpy(mCtrlPoint, ctrlPoint, mNumCtrlPoints*sizeof(Vector2D<Real>));

    for (auto i = 0; i < mReplicate; ++i)
    {
        mCtrlPoint[mNumCtrlPoints + i] = ctrlPoint[i];
    }
}

template <typename Real>
int Mathematics::BSplineCurve2<Real>
	::GetNumCtrlPoints () const noexcept
{
    return mNumCtrlPoints;
}

template <typename Real>
int Mathematics::BSplineCurve2<Real>
	::GetDegree () const noexcept
{
    return mBasis.GetDegree();
}

template <typename Real>
bool Mathematics::BSplineCurve2<Real>
	::IsOpen () const noexcept
{
    return mBasis.IsOpen();
}

template <typename Real>
bool Mathematics::BSplineCurve2<Real>
	::IsUniform () const noexcept
{
    return mBasis.IsUniform();
}

template <typename Real>
bool Mathematics::BSplineCurve2<Real>
	::IsLoop () const noexcept
{
    return mLoop;
}

template <typename Real>
void Mathematics::BSplineCurve2<Real>
	::SetControlPoint (int i, const Vector2D<Real>& ctrl) noexcept
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
Mathematics::Vector2D<Real> Mathematics::BSplineCurve2<Real>
	::GetControlPoint (int i) const noexcept
{
    if (0 <= i && i < mNumCtrlPoints)
    {
        return mCtrlPoint[i];
    }

    return Vector2D<Real>{ Math::sm_MaxReal, Math::sm_MaxReal };
}

template <typename Real>
void Mathematics::BSplineCurve2<Real>
	::SetKnot (int i, Real knot)
{
    mBasis.SetKnot(i, knot);
}

template <typename Real>
Real Mathematics::BSplineCurve2<Real>
	::GetKnot (int i) const
{
    return mBasis.GetKnot(i);
}

template <typename Real>
void Mathematics::BSplineCurve2<Real>
	::Get (Real t, Vector2D<Real>* pos, Vector2D<Real>* der1, Vector2D<Real>* der2, Vector2D<Real>* der3) const
{
    int i = 0, imin = 0, imax = 0;
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

    if (pos)
    {
        *pos = Vector2D<Real>::GetZero();
        for (i = imin; i <= imax; ++i)
        {
            *pos += mCtrlPoint[i]*mBasis.GetD0(i);
        }
    }

    if (der1)
    {
        *der1 = Vector2D<Real>::GetZero();
        for (i = imin; i <= imax; ++i)
        {
            *der1 += mCtrlPoint[i]*mBasis.GetD1(i);
        }
    }

    if (der2)
    {
        *der2 = Vector2D<Real>::GetZero();
        for (i = imin; i <= imax; ++i)
        {
            *der2 += mCtrlPoint[i]*mBasis.GetD2(i);
        }
    }

    if (der3)
    {
        *der3 = Vector2D<Real>::GetZero();
        for (i = imin; i <= imax; ++i)
        {
            *der3 += mCtrlPoint[i]*mBasis.GetD3(i);
        }
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>& Mathematics::BSplineCurve2<Real>
	::GetBasis () noexcept
{
    return mBasis;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BSplineCurve2<Real>
	::GetPosition (Real t) const
{
    Vector2D<Real> pos;
    Get(t, &pos, 0, 0, 0);
    return pos;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BSplineCurve2<Real>
	::GetFirstDerivative (Real t) const
{
    Vector2D<Real> der1;
    Get(t, 0, &der1, 0, 0);
    return der1;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BSplineCurve2<Real>
	::GetSecondDerivative (Real t) const
{
    Vector2D<Real> der2;
    Get(t, 0, 0, &der2, 0);
    return der2;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BSplineCurve2<Real>
	::GetThirdDerivative (Real t) const
{
    Vector2D<Real> der3;
    Get(t, 0, 0, 0, &der3);
    return der3;
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BSPLINE_CURVE2_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE2_DETAIL_H