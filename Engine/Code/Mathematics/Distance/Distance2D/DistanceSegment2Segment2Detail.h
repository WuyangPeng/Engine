// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 19:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_DETAIL_H 

#include "DistanceSegment2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::DistanceSegment2Segment2<Real>
	::DistanceSegment2Segment2( const Segment2& lhsSegment, const Segment2& rhsSegment )
	:m_LhsSegment{ lhsSegment }, m_RhsSegment{ rhsSegment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::DistanceSegment2Segment2<Real>
	::~DistanceSegment2Segment2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceSegment2Segment2<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::Segment2 Mathematics::DistanceSegment2Segment2<Real>
	::GetLhsSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsSegment;
}

template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::Segment2 Mathematics::DistanceSegment2Segment2<Real>
	::GetRhsSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsSegment;
}

template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine2Line2Tool tool{ m_LhsSegment.GetCenterPoint(), m_LhsSegment.GetDirection(),m_RhsSegment.GetCenterPoint(), m_RhsSegment.GetDirection() };

	auto det = tool.GetDet();
	auto lhsExtent = m_LhsSegment.GetExtent();
	auto rhsExtent = m_RhsSegment.GetExtent();

	if (GetZeroThreshold() <= det)
	{
		// 线段不平行。
		auto lhsT = tool.GetLhsT();
		auto rhsT = tool.GetRhsT();

		auto lhsExtentMultiplyDet = lhsExtent * det;
		auto rhsExtentMultiplyDet = rhsExtent * det;

		if (-lhsExtentMultiplyDet <= lhsT)
		{
			if (lhsT <= lhsExtentMultiplyDet)
			{
				if (-rhsExtentMultiplyDet <= rhsT)
				{
					if (rhsT <= rhsExtentMultiplyDet) 
					{
						// 区域0（内部）
						// 最小值为两个线段内部点。
						return DistanceResult{ Real{}, Real{}, m_LhsSegment.GetCenterPoint() + lhsT / det * m_LhsSegment.GetDirection(),
											   m_RhsSegment.GetCenterPoint() + rhsT / det * m_RhsSegment.GetDirection() };
					}
					else
					{
						// 区域3（边）	
						return GetSquaredWithClosestPointsIsLhsSide(tool, lhsExtent, rhsExtent);
					}
				}
				else  
				{
					// 区域7（边）
					return GetSquaredWithClosestPointsIsLhsSide(tool, lhsExtent, -rhsExtent); 
				}
			}
			else
			{
				if (-rhsExtentMultiplyDet <= rhsT)
				{
					if (rhsT <= rhsExtentMultiplyDet)
					{
						// 区域1（边）
						return GetSquaredWithClosestPointsIsRhsSide(tool, lhsExtent, rhsExtent);						
					}
					else  
					{
						// 区域2（角）
						return GetSquaredWithClosestPointsIsLhsCorner(tool, lhsExtent, rhsExtent);
					}
				}
				else  
				{
					// 区域8（角）
					return GetSquaredWithClosestPointsIsLhsCorner(tool, lhsExtent, -rhsExtent);			
				}
			}
		}
		else
		{
			if (-rhsExtentMultiplyDet <= rhsT)
			{
				if (rhsT <= rhsExtentMultiplyDet)  
				{
					// 区域5（边）
					return GetSquaredWithClosestPointsIsRhsSide(tool, -lhsExtent, rhsExtent);
				}
				else  
				{
					// 区域4（角）
					return GetSquaredWithClosestPointsIsRhsCorner(tool, lhsExtent, rhsExtent);
				}
			}
			else   
			{
				// 区域6（角）
				return GetSquaredWithClosestPointsIsRhsCorner(tool, lhsExtent, -rhsExtent);			
			}
		}
	}
	else
	{
		// 线段是平行的。 
		// 平均项originDifferenceDotLhsDirection被设计为确保函数的对称性。 
		// 也就是说，DistanceSegment2Segment2（seg0，seg1）和DistanceSegment2Segment2（seg1，seg0）应该产生相同的数。
		auto extentSum = lhsExtent + rhsExtent;
		auto sign = (Real{} < tool.GetDirectionDot() ? static_cast<Real>(-1) : static_cast<Real>(1));
		auto originDifferenceDotLhsDirectionAverage = tool.GetOriginDifferenceDotDirectionAverage();
		auto lambda = -originDifferenceDotLhsDirectionAverage;
		if (lambda < -extentSum)
		{
			lambda = -extentSum;
		}
		else if (extentSum < lambda)
		{
			lambda = extentSum;
		}

		auto rhsT = (-sign * lambda * rhsExtent / extentSum);
		auto lhsT = lambda + sign * rhsT;

		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(lambda * (lambda + static_cast<Real>(2) * originDifferenceDotLhsDirectionAverage) + tool.GetOriginDifferenceSquaredLength()),
							   Real{},
							   m_LhsSegment.GetCenterPoint() + lhsT * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsT * m_RhsSegment.GetDirection() };
	}
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>
	::GetSquaredWithClosestPointsIsLhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
		             tool.GetOriginDifferenceSquaredLength();

	if (t < -lhsExtent)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-lhsExtent * (-lhsExtent - static_cast<Real>(2) * t) + rhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() - lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
	else if (t <= lhsExtent)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + t * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
	else
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(lhsExtent * (lhsExtent - static_cast<Real>(2) * t) + rhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>
	::GetSquaredWithClosestPointsIsRhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
	auto t = tool.GetRhsT(-lhsExtent);
	auto lhsSquare = lhsExtent * (lhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotLhsDirection()) +
		             tool.GetOriginDifferenceSquaredLength();

	if (t < -rhsExtent)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-rhsExtent * (-rhsExtent - static_cast<Real>(2) * t) + lhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() - rhsExtent * m_RhsSegment.GetDirection() };
	}
	else if (t <= rhsExtent)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + lhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + t * m_RhsSegment.GetDirection() };
	}
	else
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(rhsExtent * (rhsExtent - static_cast<Real>(2) * t) + lhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>
	::GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
		             tool.GetOriginDifferenceSquaredLength();

	if (t < -lhsExtent)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-lhsExtent * (-lhsExtent - static_cast<Real>(2) * t) + rhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() - lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
	else if (t <= lhsExtent)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + t * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
	else
	{
		return GetSquaredWithClosestPointsIsRhsSide(tool, lhsExtent,Math::FAbs(rhsExtent));
	}
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>
	::GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{	
	auto t = tool.GetLhsT(-rhsExtent);
	auto rhsSquare = rhsExtent * (rhsExtent + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
		             tool.GetOriginDifferenceSquaredLength();

	if (lhsExtent < t)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(lhsExtent * (lhsExtent - static_cast<Real>(2) * t) + rhsSquare),
							   Real{}, m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
							   m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
	else if (-lhsExtent <= t)
	{
		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
							  Real{}, m_LhsSegment.GetCenterPoint() + t * m_LhsSegment.GetDirection(),
							  m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection() };
	}
	else
	{
		return GetSquaredWithClosestPointsIsRhsSide(tool, -lhsExtent, Math::FAbs(rhsExtent));
	}		
}

template <typename Real>
const typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>
	::GetSquared( Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto lhsMovedSegment = m_LhsSegment.GetMove(t, lhsVelocity);
	auto rhsMovedSegment = m_RhsSegment.GetMove(t, rhsVelocity);

	ClassType distance{ lhsMovedSegment, rhsMovedSegment };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_DETAIL_H
