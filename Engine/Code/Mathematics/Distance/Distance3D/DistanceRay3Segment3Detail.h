// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 13:02)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_DEATIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_DEATIL_H 

#include "DistanceRay3Segment3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceRay3Segment3<Real>
	::DistanceRay3Segment3(const Ray3& ray, const Segment3& segment)
	:ParentType{}, m_Ray{ ray }, m_Segment{ segment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceRay3Segment3<Real>
	::~DistanceRay3Segment3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceRay3Segment3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::Segment3 Mathematics::DistanceRay3Segment3<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::Ray3 Mathematics::DistanceRay3Segment3<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine3Line3Tool tool{ m_Ray.GetOrigin(), m_Ray.GetDirection(),m_Segment.GetCenterPoint(),m_Segment.GetDirection() };

	auto det = tool.GetDet();
	auto rhsExtent = m_Segment.GetExtent();

	if (this->GetZeroThreshold() <= det)
	{
		// ���ߺ��߶β�ƽ��
		auto lhsT = tool.GetLhsT();
		auto rhsT = tool.GetRhsT();
		auto rhsExtentMultiplyDet = rhsExtent * det;

		if (Math::GetValue(0) <= lhsT)
		{
			if (-rhsExtentMultiplyDet <= rhsT)
			{
				if (rhsT <= rhsExtentMultiplyDet)
				{
					// ���� 0			

					// ��С��Ϊ���ߺ��߶��ڲ��㡣
					lhsT /= det;
					rhsT /= det;

					auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
										   rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
										   tool.GetOriginDifferenceSquaredLength();

					return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::GetValue(0), m_Ray.GetOrigin() + lhsT * m_Ray.GetDirection(),
										   m_Segment.GetCenterPoint() + rhsT * m_Segment.GetDirection(),lhsT,rhsT };

				}
				else
				{
					// ���� 1
					return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, rhsExtent);
				}
			}
			else
			{
				// ���� 5
				return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, -rhsExtent);
			}
		}
		else
		{
			if (rhsT <= -rhsExtentMultiplyDet)
			{
				// ���� 4
				return GetSquaredWithClosestPointsIsSegmentBeginPoint(tool, rhsExtent);
			}
			else if (rhsT <= rhsExtentMultiplyDet)
			{
				// ���� 3
				return GetSquaredWithClosestPointsIsRayOrigin(tool, rhsExtent);
			}
			else
			{
				// ���� 2
				return GetSquaredWithClosestPointsIsSegmentBeginPoint(tool, -rhsExtent);
			}
		}
	}
	else
	{
		// ���ߺ��߶�ƽ��
		if (Math::GetValue(0) < tool.GetDirectionDot())
		{
			// �෴�ķ���������
			return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, -rhsExtent);
		}
		else
		{
			// ��ͬ�ķ�������
			return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, rhsExtent);
		}
	}
}

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>
	::GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

	if (Math::GetValue(0) < t)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare), Math::GetValue(0), m_Ray.GetOrigin() + t * m_Ray.GetDirection(),
							   m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection(), t,rhsExtent };
	}
	else
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(rhsSquare), Math::GetValue(0), m_Ray.GetOrigin(),
							   m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection(), Math::GetValue(0),rhsExtent };
	}
}

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>
	::GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
	auto t = tool.GetLhsT(rhsExtent);
	if (Math::GetValue(0) < t)
	{
		auto rhsSquare = -rhsExtent * (-rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare), Math::GetValue(0), m_Ray.GetOrigin() + t * m_Ray.GetDirection(),
							   m_Segment.GetCenterPoint() - rhsExtent * m_Segment.GetDirection(), t,-rhsExtent };
	}
	else
	{
		return GetSquaredWithClosestPointsIsRayOrigin(tool, Math::FAbs(rhsExtent));
	}
}

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>
	::GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
	auto dotRhsDirection = -tool.GetOriginDifferenceDotRhsDirection();
	if (dotRhsDirection < -rhsExtent)
	{
		dotRhsDirection = -rhsExtent;
	}
	else if (rhsExtent < dotRhsDirection)
	{
		dotRhsDirection = rhsExtent;
	}

	return DistanceResult{ Math::GetNumericalRoundOffNonnegative(dotRhsDirection * (dotRhsDirection + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength()),
						   Math::GetValue(0), m_Ray.GetOrigin(), m_Segment.GetCenterPoint() + dotRhsDirection * m_Segment.GetDirection(), Math::GetValue(0), dotRhsDirection };
}

template <typename Real>
const typename Mathematics::DistanceRay3Segment3<Real>::DistanceResult Mathematics::DistanceRay3Segment3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movedRay = m_Ray.GetMove(t, lhsVelocity);
	auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

	ClassType distance{ movedRay, movedSegment };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_DEATIL_H
