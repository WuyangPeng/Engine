// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/11 09:54)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_DETAIL_H

#include "DistanceLine3Segment3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine3Segment3<Real>
	::DistanceLine3Segment3(const Line3& line, const Segment3& segment)
	:ParentType{}, m_Line{ line }, m_Segment{ segment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceLine3Segment3<Real>
	::~DistanceLine3Segment3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Segment3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::Line3 Mathematics::DistanceLine3Segment3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::Segment3 Mathematics::DistanceLine3Segment3<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine3Line3Tool tool{ m_Line.GetOrigin(), m_Line.GetDirection(),m_Segment.GetCenterPoint(),m_Segment.GetDirection() };

	auto det = tool.GetDet();

	if (GetZeroThreshold() <= det)
	{
		// 直线和线段不平行。
		auto rhsT = tool.GetRhsT();
		auto rhsExtent = m_Segment.GetExtent();
		auto rhsExtentMultiplyDet = rhsExtent * det;

		if (-rhsExtentMultiplyDet <= rhsT)
		{
			if (rhsT <= rhsExtentMultiplyDet)
			{		
				// 两个内部点最接近，一个在直线上，一个在线段上。
				auto lhsT = tool.GetLhsT() / det;
				rhsT /= det;
		
				auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotLhsDirection()) +
									   rhsT * (tool.GetDirectionDot() * lhsT + rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
									   tool.GetOriginDifferenceSquaredLength();
	 
				return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Real{}, m_Line.GetOrigin() + lhsT * m_Line.GetDirection(),
									   m_Segment.GetCenterPoint() + rhsT * m_Segment.GetDirection(),lhsT,rhsT };
			}
			else
			{		
				// 线段的终点和直线的内部点最接近。
				return GetSquaredWithClosestPoints(tool, rhsExtent);	 	
			}
		}
		else
		{		
			// 线段的起点和直线的内部点最接近。
			return GetSquaredWithClosestPoints(tool, -rhsExtent);
		}
	}
	else
	{		
		// 直线和线段是平行的。 选择最近的一对，使得一个点在线段中点。
		return GetSquaredWithClosestPointsIsParallel(tool);
	}	
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>
	::GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();
 
	return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),Real{}, m_Line.GetOrigin() + t * m_Line.GetDirection(),
						   m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection(),t,rhsExtent };
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>
	::GetSquaredWithClosestPointsIsParallel(const DistanceLine3Line3Tool& tool) const
{
	auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
	auto squaredDistance = tool.GetSquaredDistanceWithParallel();

	return DistanceResult{ squaredDistance, Real{}, m_Line.GetOrigin() - originDifferenceDotLhsDirection * m_Line.GetDirection(),
						   m_Segment.GetCenterPoint(), -originDifferenceDotLhsDirection,Real{} };
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
 
	auto movedLine = m_Line.GetMove(t, lhsVelocity);
	auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

	ClassType distance{ movedLine, movedSegment };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_DETAIL_H
