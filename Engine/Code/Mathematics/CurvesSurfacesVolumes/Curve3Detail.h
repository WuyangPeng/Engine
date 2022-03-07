// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H

#include "Curve3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_CURVE3_DETAIL)


#include "Mathematics/Algebra/Vector3Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
template <typename Real>
Mathematics::Curve3<Real>::Curve3(Real tmin, Real tmax) noexcept
    : mTMin{ tmin }, mTMax{ tmax }
{
    
}

template <typename Real>
Mathematics::Curve3<Real>
	::~Curve3()
{
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetMinTime() const noexcept
{
    return mTMin;
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetMaxTime() const noexcept
{
    return mTMax;
}

template <typename Real>
void Mathematics::Curve3<Real>
	::SetTimeInterval(Real tmin, Real tmax)
{
    MATHEMATICS_ASSERTION_0(tmin < tmax, "Invalid time interval\n");
    mTMin = tmin;
    mTMax = tmax;
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetSpeed(Real t) const
{
	const auto velocity = GetFirstDerivative(t);
	const auto speed = Vector3Tools<Real>::GetLength(velocity);
    return speed;
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetTotalLength() const
{
    return GetLength(mTMin, mTMax);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Curve3<Real>
	::GetTangent(Real t) const
{
	auto velocity = GetFirstDerivative(t);
    velocity.Normalize();
    return velocity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Curve3<Real>
	::GetNormal(Real t) const
{
	const auto velocity = GetFirstDerivative(t);
	const auto acceleration = GetSecondDerivative(t);
	auto VDotV = Vector3Tools<Real>::DotProduct(velocity,velocity);
	auto VDotA = Vector3Tools<Real>::DotProduct(velocity,acceleration);
	auto normal = VDotV*acceleration - VDotA*velocity;
    normal.Normalize();
    return normal;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Curve3<Real>
	::GetBinormal(Real t) const
{
	auto velocity = GetFirstDerivative(t);
	const auto acceleration = GetSecondDerivative(t);
	auto VDotV = Vector3Tools<Real>::DotProduct(velocity,velocity);
	auto VDotA = Vector3Tools<Real>::DotProduct(velocity,acceleration);
	auto normal = VDotV*acceleration - VDotA*velocity;
    normal.Normalize();
    velocity.Normalize();
	auto binormal = Vector3Tools<Real>::CrossProduct(velocity,normal);
    return binormal;
}

template <typename Real>
void Mathematics::Curve3<Real>
	::GetFrame(Real t, Vector3<Real>& position, Vector3<Real>& tangent, Vector3<Real>& normal, Vector3<Real>& binormal) const
{
    position = GetPosition(t);
	auto velocity = GetFirstDerivative(t);
	const auto acceleration = GetSecondDerivative(t);
	auto VDotV = Vector3Tools<Real>::DotProduct(velocity,velocity);
	auto VDotA = Vector3Tools<Real>::DotProduct(velocity,acceleration);
    normal = VDotV*acceleration - VDotA*velocity;
    normal.Normalize();
    tangent = velocity;
    tangent.Normalize();
	binormal = Vector3Tools<Real>::CrossProduct(tangent,normal);
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetCurvature(Real t) const
{
	const auto velocity = GetFirstDerivative(t);
	auto speedSqr = Vector3Tools<Real>::GetLengthSquared(velocity);

    if (speedSqr >= Math<Real>::GetZeroTolerance())
    {
		const auto acceleration = GetSecondDerivative(t);
		const auto cross = Vector3Tools<Real>::CrossProduct(velocity,acceleration);
		auto numer = Vector3Tools<Real>::GetLength(cross);
		auto denom = Math<Real>::Pow(speedSqr, static_cast<Real>(1.5));
        return numer/denom;
    }
    else
    {
        // Curvature is indeterminate, just return 0.
        return Math<Real>::GetValue(0);
    }
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetTorsion(Real t) const
{
	const auto velocity = GetFirstDerivative(t);
	const auto acceleration = GetSecondDerivative(t);
	const auto cross = Vector3Tools<Real>::CrossProduct(velocity,acceleration);
	auto denom = Vector3Tools<Real>::GetLengthSquared(cross);

    if (denom >= Math<Real>::GetZeroTolerance())
    {
		const auto jerk = GetThirdDerivative(t);
		auto numer = Vector3Tools<Real>::DotProduct(cross,jerk);
        return numer/denom;
    }
    else
    {
        // Torsion is indeterminate, just return 0.
        return Math<Real>::GetValue(0);
    }
}

template <typename Real>
void Mathematics::Curve3<Real>
	::SubdivideByTime(int numPoints, Vector3<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = nullptr;  // NEW1<Vector3<Real> >(numPoints);

	const auto temp1 = mTMax - mTMin;
	const auto temp2 = numPoints - 1;
	const auto delta = (temp1 )/(temp2);

    for (auto i = 0; i < numPoints; ++i)
    {
		auto t = mTMin + delta*i;
        points[i] = GetPosition(t);
    }
}

template <typename Real>
void Mathematics::Curve3<Real>
	::SubdivideByLength(int numPoints, Vector3<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = nullptr;  // NEW1<Vector3<Real> >(numPoints);

	const auto temp = numPoints - 1;
	auto delta = GetTotalLength()/(temp);

    for (auto i = 0; i < numPoints; ++i)
    {
		auto length = delta*i;
		auto t = GetTime(length);
        points[i] = GetPosition(t);
    }
}
#include STSTEM_WARNING_POP

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_CURVE3_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H