// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 10:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_DETAIL_H 

#include "DistanceLine3Ray3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine3Ray3<Real>
	::DistanceLine3Ray3(const Line3& line, const Ray3& ray)
	:ParentType{}, m_Line{ line }, m_Ray{ ray }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceLine3Ray3<Real>
	::~DistanceLine3Ray3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Ray3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::Line3 Mathematics::DistanceLine3Ray3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::Ray3 Mathematics::DistanceLine3Ray3<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine3Line3Tool tool{ m_Line.GetOrigin(), m_Line.GetDirection(),m_Ray.GetOrigin(),m_Ray.GetDirection() };

	auto det = tool.GetDet();

	if (this->GetZeroThreshold() <= det)
	{
		auto rhsT = tool.GetRhsT();

		if (Math::GetValue(0) <= rhsT)
		{
			// 两个内部点最接近，一个在直线上，一个在射线上。
			auto lhsT = tool.GetLhsT() / det;
			rhsT /= det;
			auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotLhsDirection()) +
								   rhsT * (tool.GetDirectionDot() * lhsT + rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
								   tool.GetOriginDifferenceSquaredLength();

			return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::GetValue(0), m_Line.GetOrigin() + lhsT * m_Line.GetDirection(),
								   m_Ray.GetOrigin() + rhsT * m_Ray.GetDirection(),lhsT,rhsT };
		}
		else
		{
			// 射线的原点同直线的某一点最接近。
			return GetSquaredWithClosestPoints(tool);
		}
	}
	else
	{
		// 线是平行的，最接近的一对点在射线原点。
		return GetSquaredWithClosestPoints(tool);
	}
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>
	::GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool) const
{
	auto squaredDistance = tool.GetSquaredDistanceWithLhs();

	return DistanceResult{ squaredDistance, Math::GetValue(0),
						   m_Line.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * m_Line.GetDirection(), m_Ray.GetOrigin(),
						   -tool.GetOriginDifferenceDotLhsDirection(),Math::GetValue(0) };
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movedLine = m_Line.GetMove(t, lhsVelocity);
	auto movedRay = m_Ray.GetMove(t, rhsVelocity);

	ClassType distance{ movedLine, movedRay };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}
#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_DETAIL_H
