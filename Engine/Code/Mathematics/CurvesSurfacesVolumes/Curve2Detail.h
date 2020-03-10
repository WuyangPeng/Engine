// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:51)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H

#include "Curve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE2_DETAIL)

#include "CoreTools/Helper/MemoryMacro.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real>
Mathematics::Curve2<Real>
	::Curve2(Real tmin, Real tmax)
{
    mTMin = tmin;
    mTMax = tmax;
}

template <typename Real>
Mathematics::Curve2<Real>
	::~Curve2()
{
}

template <typename Real>
Real Mathematics::Curve2<Real>
	::GetMinTime() const
{
    return mTMin;
}

template <typename Real>
Real Mathematics::Curve2<Real>
	::GetMaxTime() const
{
    return mTMax;
}

template <typename Real>
void Mathematics::Curve2<Real>
	::SetTimeInterval(Real tmin, Real tmax)
{
    MATHEMATICS_ASSERTION_0(tmin < tmax, "Invalid time interval\n");
    mTMin = tmin;
    mTMax = tmax;
}

template <typename Real>
Real Mathematics::Curve2<Real>
	::GetSpeed(Real t) const
{
    Vector2D<Real> velocity = GetFirstDerivative(t);
	Real speed = Vector2DTools<Real>::VectorMagnitude(velocity);
    return speed;
}

template <typename Real>
Real Mathematics::Curve2<Real>
	::GetTotalLength() const
{
    return GetLength(mTMin, mTMax);
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::Curve2<Real>
	::GetTangent(Real t) const
{
	auto velocity = GetFirstDerivative(t);
    velocity.Normalize();
    return velocity;
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::Curve2<Real>
	::GetNormal(Real t) const
{
	auto tangent = GetFirstDerivative(t);
    tangent.Normalize();
	auto normal = Vector2DTools<Real>::GetPerp(tangent);
    return normal;
}

template <typename Real>
void Mathematics::Curve2<Real>
	::GetFrame(Real t, Vector2D<Real>& position,Vector2D<Real>& tangent, Vector2D<Real>& normal) const
{
    position = GetPosition(t);
    tangent = GetFirstDerivative(t);
    tangent.Normalize();
	normal = Vector2DTools<Real>::GetPerp(tangent);
}

template <typename Real>
Real Mathematics::Curve2<Real>
	::GetCurvature(Real t) const
{
	auto der1 = GetFirstDerivative(t);
	auto der2 = GetSecondDerivative(t);
	auto speedSqr = Vector2DTools<Real>::VectorMagnitudeSquared(der1);

    if (speedSqr >= Math<Real>::sm_ZeroTolerance)
    {
		auto numer = Vector2DTools<Real>::DotPerp(der1,der2);
		auto denom = Math<Real>::Pow(speedSqr, (Real)1.5);
        return numer/denom;
    }
    else
    {
        // Curvature is indeterminate, just return 0.
        return Real{};
    }
}

template <typename Real>
void Mathematics::Curve2<Real>
	::SubdivideByTime(int numPoints, Vector2D<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = NEW1<Vector2D<Real> >(numPoints);

	auto delta = (mTMax - mTMin)/(numPoints - 1);

    for (auto i = 0; i < numPoints; ++i)
    {
		auto t = mTMin + delta*i;
        points[i] = GetPosition(t);
    }
}

template <typename Real>
void Mathematics::Curve2<Real>
	::SubdivideByLength(int numPoints,Vector2D<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = NEW1<Vector2D<Real> >(numPoints);

	auto delta = GetTotalLength()/(numPoints - 1);

    for (auto i = 0; i < numPoints; ++i)
    {
		auto length = delta*i;
		auto t = GetTime(length);
        points[i] = GetPosition(t);
    }
} 

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE2_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H