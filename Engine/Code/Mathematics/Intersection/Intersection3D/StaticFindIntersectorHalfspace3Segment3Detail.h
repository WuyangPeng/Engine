// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 17:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "StaticFindIntersectorHalfspace3Segment3.h"
#include "IntersectorUtility3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment)
	: m_Halfspace{ halfspace }, m_Segment{ segment }
{
	m_Quantity = 0;

	Find();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetHalfspace() const
{
	return m_Halfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetSegment() const
{
	return m_Segment;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::Find()
{
	// Start with the segment and clip it against the plane.
	m_Quantity = 2;
	m_Point[0] = m_Segment.GetBeginPoint();;
	m_Point[1] = m_Segment.GetEndPoint();

	IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(-m_Halfspace.GetNormal(), -m_Halfspace.GetConstant(), m_Quantity, m_Point);

	if (m_Quantity > 0)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetQuantity() const
{
	return m_Quantity;
}

template <typename Real>
const  Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>
	::GetPoint(int i) const
{
	return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H