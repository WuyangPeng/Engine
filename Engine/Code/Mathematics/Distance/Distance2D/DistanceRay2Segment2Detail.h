// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 18:56)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_DEATIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_DEATIL_H 

#include "DistanceRay2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

template <typename Real>
Mathematics::DistanceRay2Segment2<Real>
	::DistanceRay2Segment2(const Ray2& ray, const Segment2& segment)
	:ParentType{}, m_Ray{ ray }, m_Segment{ segment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceRay2Segment2<Real>
	::~DistanceRay2Segment2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceRay2Segment2<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::Segment2 Mathematics::DistanceRay2Segment2<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::Ray2 Mathematics::DistanceRay2Segment2<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine2Line2Tool tool{ m_Ray.GetOrigin(), m_Ray.GetDirection(),m_Segment.GetCenterPoint(),m_Segment.GetDirection() };

	auto det = tool.GetDet();
	auto rhsExtent = m_Segment.GetExtent();

	if (GetZeroThreshold() <= det)
	{
		// 射线和线段不平行
		auto lhsT = tool.GetLhsT();
		auto rhsT = tool.GetRhsT();
		auto rhsExtentMultiplyDet = rhsExtent * det;

		if (Real{} <= lhsT)
		{
			if (-rhsExtentMultiplyDet <= rhsT)
			{
				if (rhsT <= rhsExtentMultiplyDet)
				{
					// 区域 0			
					
					// 最小点为射线和线段内部点。
					return DistanceResult{ Real{}, Real{}, m_Ray.GetOrigin() + lhsT / det * m_Ray.GetDirection(),
										   m_Segment.GetCenterPoint() + rhsT / det * m_Segment.GetDirection() };
				}
				else 
				{
					// 区域 1
					return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, rhsExtent);
				}
			}
			else  
			{
				// 区域 5
				return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, -rhsExtent);
			}
		}
		else
		{
			if (rhsT <= -rhsExtentMultiplyDet)		
			{
				// 区域 4
				return GetSquaredWithClosestPointsIsSegmentBeginPoint(tool, rhsExtent);
			}
			else if (rhsT <= rhsExtentMultiplyDet)		
			{
				// 区域 3
				return GetSquaredWithClosestPointsIsRayOrigin(tool, rhsExtent);
			}
			else  
			{
				// 区域 2
				return GetSquaredWithClosestPointsIsSegmentBeginPoint(tool, -rhsExtent);
			}
		}
	}
	else
	{
		// 射线和线段平行
		if (Real{} < tool.GetDirectionDot())
		{
			// 相反的方向向量。
			return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, -rhsExtent);	
		}
		else
		{
			// 相同的方向向量
			return GetSquaredWithClosestPointsIsSegmentEndPoint(tool, rhsExtent);		
		}
	}	
}

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>
	::GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine2Line2Tool& tool,Real rhsExtent) const
{
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
		             tool.GetOriginDifferenceSquaredLength();

	if (Real{} < t)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
							   Real{}, m_Ray.GetOrigin() + t * m_Ray.GetDirection(),
							   m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection() };
	}
	else
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(rhsSquare),
							   Real{}, m_Ray.GetOrigin(),
							   m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection() };
	}
}

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>
	::GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
{
	auto t = tool.GetLhsT(rhsExtent);
	if (Real{} < t)
	{
		auto rhsSquare = -rhsExtent * (-rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
		                 tool.GetOriginDifferenceSquaredLength();

		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
							   Real{}, m_Ray.GetOrigin() + t * m_Ray.GetDirection(),
							   m_Segment.GetCenterPoint() - rhsExtent * m_Segment.GetDirection() };
	}
	else
	{	
		return GetSquaredWithClosestPointsIsRayOrigin(tool,Math::FAbs(rhsExtent));
	}
}

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>
	::GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
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
	
	return DistanceResult{ Math::GetNumericalRoundOffNonnegative(dotRhsDirection * (dotRhsDirection + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
													             tool.GetOriginDifferenceSquaredLength()),
						   Real{}, m_Ray.GetOrigin(), m_Segment.GetCenterPoint() + dotRhsDirection * m_Segment.GetDirection() };
} 

template <typename Real>
const typename Mathematics::DistanceRay2Segment2<Real>::DistanceResult Mathematics::DistanceRay2Segment2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
 	
	auto movedRay = m_Ray.GetMove(t, lhsVelocity);
	auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

	ClassType distance{ movedRay, movedSegment };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_DEATIL_H
