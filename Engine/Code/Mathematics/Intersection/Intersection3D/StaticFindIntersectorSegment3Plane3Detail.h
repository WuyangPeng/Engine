// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H

#include "StaticFindIntersectorSegment3Plane3.h"
#include "StaticFindIntersectorLine3Plane3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Plane3<Real>
	::StaticFindIntersectorSegment3Plane3 (const Segment3& rkSegment,const Plane3& rkPlane)
	: m_Segment{ rkSegment }, m_Plane{ rkPlane }
{
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Plane3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorSegment3Plane3<Real>
	::GetPlane() const
{
    return m_Plane;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Plane3<Real>
	::Find()
{
	Line3<Real> line{ m_Segment.GetCenterPoint(), m_Segment.GetDirection() };
	StaticFindIntersectorLine3Plane3<Real> intr{ line, m_Plane };
	if (intr.IsIntersection())
    {
        // The line intersects the plane, but possibly at a point that is
        // not on the segment.
        SetIntersectionType(intr.GetIntersectionType());
        m_SegmentParameter = intr.GetLineParameter();
		if (!(Math::FAbs(m_SegmentParameter) <= m_Segment.GetExtent()))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}
    }

	this->SetIntersectionType(IntersectionType::Empty);
    return;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Plane3<Real>
	::GetSegmentParameter() const
{
    return m_SegmentParameter;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_DETAIL_H