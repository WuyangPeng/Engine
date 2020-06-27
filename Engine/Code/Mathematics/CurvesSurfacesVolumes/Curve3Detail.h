// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H

#include "Curve3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE3_DETAIL)

#include "CoreTools/Helper/MemoryMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

template <typename Real>
Mathematics::Curve3<Real>
	::Curve3(Real tmin, Real tmax)
	:mTMin{ tmin }, mTMax{ tmax }
{
    
}

template <typename Real>
Mathematics::Curve3<Real>
	::~Curve3()
{
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetMinTime() const
{
    return mTMin;
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetMaxTime() const
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
	auto velocity = GetFirstDerivative(t);
	auto speed = Vector3DTools<Real>::VectorMagnitude(velocity);
    return speed;
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetTotalLength() const
{
    return GetLength(mTMin, mTMax);
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::Curve3<Real>
	::GetTangent(Real t) const
{
	auto velocity = GetFirstDerivative(t);
    velocity.Normalize();
    return velocity;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::Curve3<Real>
	::GetNormal(Real t) const
{
	auto velocity = GetFirstDerivative(t);
	auto acceleration = GetSecondDerivative(t);
	auto VDotV = Vector3DTools<Real>::DotProduct(velocity,velocity);
	auto VDotA = Vector3DTools<Real>::DotProduct(velocity,acceleration);
	auto normal = VDotV*acceleration - VDotA*velocity;
    normal.Normalize();
    return normal;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::Curve3<Real>
	::GetBinormal(Real t) const
{
	auto velocity = GetFirstDerivative(t);
	auto acceleration = GetSecondDerivative(t);
	auto VDotV = Vector3DTools<Real>::DotProduct(velocity,velocity);
	auto VDotA = Vector3DTools<Real>::DotProduct(velocity,acceleration);
	auto normal = VDotV*acceleration - VDotA*velocity;
    normal.Normalize();
    velocity.Normalize();
	auto binormal = Vector3DTools<Real>::CrossProduct(velocity,normal);
    return binormal;
}

template <typename Real>
void Mathematics::Curve3<Real>
	::GetFrame(Real t, Vector3D<Real>& position, Vector3D<Real>& tangent, Vector3D<Real>& normal, Vector3D<Real>& binormal) const
{
    position = GetPosition(t);
	auto velocity = GetFirstDerivative(t);
	auto acceleration = GetSecondDerivative(t);
	auto VDotV = Vector3DTools<Real>::DotProduct(velocity,velocity);
	auto VDotA = Vector3DTools<Real>::DotProduct(velocity,acceleration);
    normal = VDotV*acceleration - VDotA*velocity;
    normal.Normalize();
    tangent = velocity;
    tangent.Normalize();
	binormal = Vector3DTools<Real>::CrossProduct(tangent,normal);
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetCurvature(Real t) const
{
	auto velocity = GetFirstDerivative(t);
	auto speedSqr = Vector3DTools<Real>::VectorMagnitudeSquared(velocity);

    if (speedSqr >= Math<Real>::sm_ZeroTolerance)
    {
		auto acceleration = GetSecondDerivative(t);
		auto cross = Vector3DTools<Real>::CrossProduct(velocity,acceleration);
		auto numer = Vector3DTools<Real>::VectorMagnitude(cross);
		auto denom = Math<Real>::Pow(speedSqr, static_cast<Real>(1.5));
        return numer/denom;
    }
    else
    {
        // Curvature is indeterminate, just return 0.
        return Math<Real>::sm_Zero;
    }
}

template <typename Real>
Real Mathematics::Curve3<Real>
	::GetTorsion(Real t) const
{
	auto velocity = GetFirstDerivative(t);
	auto acceleration = GetSecondDerivative(t);
	auto cross = Vector3DTools<Real>::CrossProduct(velocity,acceleration);
	auto denom = Vector3DTools<Real>::VectorMagnitudeSquared(cross);

    if (denom >= Math<Real>::sm_ZeroTolerance)
    {
		auto jerk = GetThirdDerivative(t);
		auto numer = Vector3DTools<Real>::DotProduct(cross,jerk);
        return numer/denom;
    }
    else
    {
        // Torsion is indeterminate, just return 0.
        return Math<Real>::sm_Zero;
    }
}

template <typename Real>
void Mathematics::Curve3<Real>
	::SubdivideByTime(int numPoints, Vector3D<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = NEW1<Vector3D<Real> >(numPoints);

	auto temp1 = mTMax - mTMin;
	auto temp2 = numPoints - 1;
	auto delta = (temp1 )/(temp2);

    for (auto i = 0; i < numPoints; ++i)
    {
		auto t = mTMin + delta*i;
        points[i] = GetPosition(t);
    }
}

template <typename Real>
void Mathematics::Curve3<Real>
	::SubdivideByLength(int numPoints, Vector3D<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = NEW1<Vector3D<Real> >(numPoints);

	auto temp = numPoints - 1;
	auto delta = GetTotalLength()/(temp);

    for (auto i = 0; i < numPoints; ++i)
    {
		auto length = delta*i;
		auto t = GetTime(length);
        points[i] = GetPosition(t);
    }
}


#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE3_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H