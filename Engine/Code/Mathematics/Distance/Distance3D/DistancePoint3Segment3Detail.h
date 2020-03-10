// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 10:19)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_DETAIL_H

#include "DistancePoint3Segment3.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Segment3Detail.h" 
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint3Segment3<Real>
	::DistancePoint3Segment3(const Vector3D& point, const Segment3& segment)
	:ParentType{}, m_Point{ point }, m_Segment{ segment }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint3Segment3<Real>
	::~DistancePoint3Segment3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint3Segment3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint3Segment3<Real>::Vector3D Mathematics::DistancePoint3Segment3<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint3Segment3<Real>::Segment3 Mathematics::DistancePoint3Segment3<Real>
	::GetSegment() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Segment;
}

template <typename Real>
const typename Mathematics::DistancePoint3Segment3<Real>::DistanceResult Mathematics::DistancePoint3Segment3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto difference = m_Point - m_Segment.GetCenterPoint();
	auto param = Vector3DTools::DotProduct(m_Segment.GetDirection(), difference);

	Vector3D rhsClosestPoint;
	if (-m_Segment.GetExtent() < param)
	{
		if (param < m_Segment.GetExtent())
		{
			rhsClosestPoint = m_Segment.GetCenterPoint() + param * m_Segment.GetDirection();
		}
		else
		{
			rhsClosestPoint = m_Segment.GetEndPoint();
			param = m_Segment.GetExtent();
		}
	}
	else
	{
		rhsClosestPoint = m_Segment.GetBeginPoint();
		param = -m_Segment.GetExtent();
	}

	difference = rhsClosestPoint - m_Point;

	return DistanceResult{ Vector3DTools::VectorMagnitudeSquared(difference), Real{},
						   m_Point,rhsClosestPoint,Real{},param };
}

template <typename Real>
const typename Mathematics::DistancePoint3Segment3<Real>::DistanceResult Mathematics::DistancePoint3Segment3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
 
	auto movePoint = m_Point.GetMove(t, lhsVelocity);
	auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

	ClassType distance{ movePoint, movedSegment };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_DETAIL_H
 