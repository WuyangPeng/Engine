// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:30)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_DETAIL_H

#include "BezierCurve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BEZIER_CURVE2_DETAIL)

#include "CoreTools/Helper/MemoryMacro.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
template <typename Real>
Mathematics::BezierCurve2<Real>
	::BezierCurve2 (int degree, Vector2D<Real>* ctrlPoint)
    : SingleCurve2<Real>{ Math::GetValue(0), Math::GetValue(1) }
{
    MATHEMATICS_ASSERTION_0(degree >= 2, "The degree must be three or larger\n");

    int   j = 0;

    mDegree = degree;
    mNumCtrlPoints = mDegree + 1;
    mCtrlPoint = ctrlPoint;

    // Compute first-order differences.
    mDer1CtrlPoint = NEW1<Vector2D<Real> >(mNumCtrlPoints - 1);
    for (auto i = 0; i < mNumCtrlPoints - 1; ++i)
    {
		mDer1CtrlPoint[i] = mCtrlPoint[i + 1];
		mDer1CtrlPoint[i] -= mCtrlPoint[i];
    }

    // Compute second-order differences.
    mDer2CtrlPoint = NEW1<Vector2D<Real> >(mNumCtrlPoints - 2);
    for (auto i = 0; i < mNumCtrlPoints-2; ++i)
    {
        mDer2CtrlPoint[i] = mDer1CtrlPoint[i + 1] - mDer1CtrlPoint[i];
    }

    // Compute third-order differences.
    if (degree >= 3)
    {
        mDer3CtrlPoint = NEW1<Vector2D<Real> >(mNumCtrlPoints - 3);
        for (auto i = 0; i < mNumCtrlPoints-3; ++i)
        {
            mDer3CtrlPoint[i] = mDer2CtrlPoint[i + 1] - mDer2CtrlPoint[i];
        }
    }
    else
    {
        mDer3CtrlPoint = 0;
    }

    // Compute combinatorial values Choose(N,K), store in mChoose[N][K].
    // The values mChoose[r][c] are invalid for r < c (use only the
    // entries for r >= c).
    mChoose = NEW2<Real>(mNumCtrlPoints, mNumCtrlPoints);

    mChoose[0][0] = Math::GetValue(1);
    mChoose[1][0] = Math::GetValue(1);
    mChoose[1][1] = Math::GetValue(1);
    for (auto i = 2; i <= mDegree; ++i)
    {
        mChoose[i][0] = Math::GetValue(1);
        mChoose[i][i] = Math::GetValue(1);
        for (j = 1; j < i; ++j)
        {
            mChoose[i][j] = mChoose[i-1][j-1] + mChoose[i-1][j];
        }
    }
}

template <typename Real>
Mathematics::BezierCurve2<Real>
	::~BezierCurve2 ()
{
	EXCEPTION_TRY
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		DELETE2(mChoose);
		DELETE1(mDer3CtrlPoint);
		DELETE1(mDer2CtrlPoint);
		DELETE1(mDer1CtrlPoint);
		DELETE1(mCtrlPoint);
#include STSTEM_WARNING_POP
	}
	EXCEPTION_ALL_CATCH(Mathematics) 
}

template <typename Real>
int Mathematics::BezierCurve2<Real>
	::GetDegree () const noexcept
{
    return mDegree;
}

template <typename Real>
const Mathematics::Vector2D<Real>* Mathematics::BezierCurve2<Real>
	::GetControlPoints () const noexcept
{
    return mCtrlPoint;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BezierCurve2<Real>
	::GetPosition (Real t) const
{
    auto oneMinusT = Math::GetValue(1) - t;
	auto powT = t;
	auto result = oneMinusT*mCtrlPoint[0];

    for (auto i = 1; i < mDegree; ++i)
    {
		auto coeff = mChoose[mDegree][i]*powT;
        result = (result+mCtrlPoint[i]*coeff)*oneMinusT;
        powT *= t;
    }

    result += mCtrlPoint[mDegree]*powT;

    return result;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BezierCurve2<Real>
	::GetFirstDerivative (Real t) const
{
	auto oneMinusT = Math::GetValue(1) - t;
	auto powT = t;
	auto result = oneMinusT*mDer1CtrlPoint[0];

	const auto degreeM1 = mDegree - 1;
    for (auto i = 1; i < degreeM1; ++i)
    {
		auto coeff = mChoose[degreeM1][i]*powT;
        result = (result+mDer1CtrlPoint[i]*coeff)*oneMinusT;
        powT *= t;
    }

    result += mDer1CtrlPoint[degreeM1]*powT;
    result *= static_cast<Real>(mDegree);

    return result;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BezierCurve2<Real>
	::GetSecondDerivative (Real t) const
{
	auto oneMinusT = Math::GetValue(1) - t;
	auto powT = t;
	auto result = oneMinusT*mDer2CtrlPoint[0];

	const auto degreeM2 = mDegree - 2;
    for (auto i = 1; i < degreeM2; ++i)
    {
		auto coeff = mChoose[degreeM2][i]*powT;
        result = (result+mDer2CtrlPoint[i]*coeff)*oneMinusT;
        powT *= t;
    }

    result += mDer2CtrlPoint[degreeM2]*powT;
	const auto temp = mDegree - 1;
	const auto temp2 = mDegree * temp;
    result *= static_cast<Real>(temp2);

    return result;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::BezierCurve2<Real>
	::GetThirdDerivative (Real t) const
{
    if (mDegree < 3)
    {
        return Vector2D<Real>::GetZero();
    }

	auto oneMinusT = Math::GetValue(1) - t;
	auto powT = t;
	auto result = oneMinusT*mDer3CtrlPoint[0];

	const auto degreeM3 = mDegree - 3;
    for (auto i = 1; i < degreeM3; ++i)
    {
		auto coeff = mChoose[degreeM3][i]*powT;
        result = (result+mDer3CtrlPoint[i]*coeff)*oneMinusT;
        powT *= t;
    }

    result += mDer3CtrlPoint[degreeM3]*powT;
	const auto temp1 = mDegree - 1;
	const auto temp2 = mDegree - 2;
	const auto temp3 = mDegree * temp1*temp2;
    result *= static_cast<Real>(temp3);

    return result;
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BEZIER_CURVE2_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_DETAIL_H