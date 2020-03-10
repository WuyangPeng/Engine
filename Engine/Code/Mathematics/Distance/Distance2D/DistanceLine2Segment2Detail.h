// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 17:47)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_DETAIL_H

#include "DistanceLine2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine2Segment2<Real>
	::DistanceLine2Segment2(const Line2& line, const Segment2& segment)
	:ParentType{}, m_Line{ line }, m_Segment{ segment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceLine2Segment2<Real>
	::~DistanceLine2Segment2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine2Segment2<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceLine2Segment2<Real>::Line2 Mathematics::DistanceLine2Segment2<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
const typename Mathematics::DistanceLine2Segment2<Real>::Segment2 Mathematics::DistanceLine2Segment2<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
const typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine2Line2Tool tool{ m_Line.GetOrigin(), m_Line.GetDirection(),m_Segment.GetCenterPoint(),m_Segment.GetDirection() };

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
				auto lhsT = tool.GetLhsT();

				return DistanceResult{ Real{}, Real{}, m_Line.GetOrigin() + lhsT / det * m_Line.GetDirection(),
									   m_Segment.GetCenterPoint() + rhsT / det * m_Segment.GetDirection() };
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
const typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>
	::GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
{
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();
 
	return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
						   Real{}, m_Line.GetOrigin() + t * m_Line.GetDirection(),
						   m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection() };
}

template <typename Real>
const typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>
	::GetSquaredWithClosestPointsIsParallel(const DistanceLine2Line2Tool& tool) const
{
	auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
	auto squaredDistance = tool.GetSquaredDistanceWithParallel();

	return DistanceResult{ squaredDistance, Real{},
						   m_Line.GetOrigin() - originDifferenceDotLhsDirection * m_Line.GetDirection(),
						   m_Segment.GetCenterPoint() };
}

template <typename Real>
const typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
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

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_DETAIL_H
