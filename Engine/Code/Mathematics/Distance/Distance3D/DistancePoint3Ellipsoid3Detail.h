// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 10:19)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_DETAIL_H

#include "DistancePoint3Ellipsoid3.h"
#include "Detail/DistancePoint3Ellipsoid3ToolDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DistancePoint3Ellipsoid3<Real>
	::DistancePoint3Ellipsoid3(const Vector3D& point, const Ellipsoid3& ellipsoid)
	:ParentType{}, m_Point{ point }, m_Ellipsoid{ ellipsoid }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint3Ellipsoid3<Real>
	::~DistancePoint3Ellipsoid3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Ellipsoid3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint3Ellipsoid3<Real>::Vector3D Mathematics::DistancePoint3Ellipsoid3<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
typename const Mathematics::DistancePoint3Ellipsoid3<Real>::Ellipsoid3 Mathematics::DistancePoint3Ellipsoid3<Real>
	::GetEllipsoid() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ellipsoid;
}

template <typename Real>
const typename  Mathematics::DistancePoint3Ellipsoid3<Real>::DistanceResult Mathematics::DistancePoint3Ellipsoid3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto diff = m_Point - m_Ellipsoid.GetCenter();
	Vector3D dot{ Vector3DTools::DotProduct(diff, m_Ellipsoid.GetAxis0()),
				  Vector3DTools::DotProduct(diff,m_Ellipsoid.GetAxis1()),
				  Vector3DTools::DotProduct(diff, m_Ellipsoid.GetAxis2()) };

	DistancePoint3Ellipsoid3Tool<Real> point3Ellipsoid3SquaredDistance{ m_Ellipsoid.GetExtent0(), m_Ellipsoid.GetExtent1(), m_Ellipsoid.GetExtent2(), dot, this->GetZeroThreshold() };

	auto squaredDistance = point3Ellipsoid3SquaredDistance.GetSquaredDistance();
	auto outputVector = point3Ellipsoid3SquaredDistance.GetOutputVector();

	auto lhsClosestPoint = m_Point;
	auto rhsClosestPoint = m_Ellipsoid.GetCenter() + outputVector[0] * m_Ellipsoid.GetAxis0() + outputVector[1] * m_Ellipsoid.GetAxis1() + outputVector[2] * m_Ellipsoid.GetAxis2();

	return DistanceResult{ squaredDistance, Math<Real>::sm_Zero, lhsClosestPoint, rhsClosestPoint };
}

template <typename Real>
typename const Mathematics::DistancePoint3Ellipsoid3<Real>::DistanceResult Mathematics::DistancePoint3Ellipsoid3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movedPoint = m_Point.GetMove(t, lhsVelocity);
	auto movedEllipsoid = m_Ellipsoid.GetMove(t, rhsVelocity);

	ClassType distance{ movedPoint, movedEllipsoid };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_DETAIL_H
