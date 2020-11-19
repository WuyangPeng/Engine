// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 13:01)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_DETAIL_H

#include "DistanceRay3Ray3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceRay3Ray3<Real>
	::DistanceRay3Ray3(const Ray3& lhsRay, const Ray3& rhsRay)
	:ParentType{}, m_LhsRay{ lhsRay }, m_RhsRay{ rhsRay }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceRay3Ray3<Real>
	::~DistanceRay3Ray3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceRay3Ray3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::Ray3 Mathematics::DistanceRay3Ray3<Real>
	::GetLhsRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsRay;
}

template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::Ray3 Mathematics::DistanceRay3Ray3<Real>
	::GetRhsRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsRay;
}

template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine3Line3Tool tool{ m_LhsRay.GetOrigin(), m_LhsRay.GetDirection(),m_RhsRay.GetOrigin(),m_RhsRay.GetDirection() };

	auto det = tool.GetDet();
	auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();

	if (this->GetZeroThreshold() <= det)
	{
		// 射线不平行。
		auto lhsT = tool.GetLhsT();
		auto rhsT = tool.GetRhsT();

		if (Math::GetValue(0) <= lhsT)
		{
			// 区域0（内部）
			if (Math::GetValue(0) <= rhsT)
			{
				lhsT /= det;
				rhsT /= det;

				auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
									   rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
									   tool.GetOriginDifferenceSquaredLength();

				return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::GetValue(0), m_LhsRay.GetOrigin() + lhsT * m_LhsRay.GetDirection(),
									   m_RhsRay.GetOrigin() + rhsT * m_RhsRay.GetDirection(),lhsT,rhsT };

			}
			else  // 区域3（边）
			{
				if (Math::GetValue(0) <= originDifferenceDotLhsDirection)
				{
					return GetSquaredWithClosestPointsIsOrigin(tool);
				}
				else
				{
					return GetSquaredWithClosestPointsIsLhs(tool);
				}
			}
		}
		else
		{
			auto originDifferenceDotRhsDirection = tool.GetOriginDifferenceDotRhsDirection();

			if (Math::GetValue(0) <= rhsT) // 区域1（边）
			{
				if (Math::GetValue(0) <= originDifferenceDotRhsDirection)
				{
					return GetSquaredWithClosestPointsIsOrigin(tool);
				}
				else
				{
					return GetSquaredWithClosestPointsIsRhs(tool);
				}
			}
			else  // 区域2（角）
			{
				if (originDifferenceDotLhsDirection < Math::GetValue(0))
				{
					return GetSquaredWithClosestPointsIsLhs(tool);
				}
				else
				{
					if (Math::GetValue(0) <= originDifferenceDotRhsDirection)
					{
						return GetSquaredWithClosestPointsIsOrigin(tool);
					}
					else
					{
						return GetSquaredWithClosestPointsIsRhs(tool);
					}
				}
			}
		}
	}
	else
	{
		// 射线是平行的。
		auto directionDot = tool.GetDirectionDot();

		if (Math::GetValue(0) < directionDot)
		{
			// 相反的方向向量。
			if (Math::GetValue(0) <= originDifferenceDotLhsDirection)
			{
				return GetSquaredWithClosestPointsIsOrigin(tool);
			}
			else
			{
				return GetSquaredWithClosestPointsIsLhs(tool);
			}
		}
		else
		{
			// 相同的方向向量
			if (Math::GetValue(0) <= originDifferenceDotLhsDirection)
			{
				return GetSquaredWithClosestPointsIsRhs(tool);
			}
			else
			{
				return GetSquaredWithClosestPointsIsLhs(tool);
			}
		}
	}
}

// private
template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>
	::GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3Tool& tool) const
{
	return DistanceResult{ Math::GetNumericalRoundOffNonnegative(tool.GetOriginDifferenceSquaredLength()),
						   Math::GetValue(0), m_LhsRay.GetOrigin(), m_RhsRay.GetOrigin(), Math::GetValue(0), Math::GetValue(0) };
}

// private
template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>
	::GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3Tool& tool) const
{
	Real squaredDistance = tool.GetSquaredDistanceWithLhs();

	return DistanceResult{ squaredDistance,Math::GetValue(0),m_LhsRay.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * m_LhsRay.GetDirection(),
						   m_RhsRay.GetOrigin(), -tool.GetOriginDifferenceDotLhsDirection(),Math::GetValue(0) };
}

// private
template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>
	::GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3Tool& tool) const
{
	Real squaredDistance = tool.GetSquaredDistanceWithRhs();

	return DistanceResult{ squaredDistance, Math::GetValue(0),m_LhsRay.GetOrigin(),
						   m_RhsRay.GetOrigin() - tool.GetOriginDifferenceDotRhsDirection() * m_RhsRay.GetDirection(),
						   Math::GetValue(0), -tool.GetOriginDifferenceDotRhsDirection() };
}

template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto lhsMovedRay = m_LhsRay.GetMove(t, lhsVelocity);
	auto rhsMovedRay = m_RhsRay.GetMove(t, rhsVelocity);

	ClassType distance{ lhsMovedRay, rhsMovedRay };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_DETAIL_H
