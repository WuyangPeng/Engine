// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_DETAIL_H

#include "StaticFindIntersectorSegment3Cylinder3.h"
#include "StaticFindIntersectorLine3Cylinder3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::StaticFindIntersectorSegment3Cylinder3 (const Segment3& segment, const Cylinder3& cylinder)
	:m_Segment{ segment }, mCylinder{ cylinder }
{
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetCylinder() const
{
    return mCylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::Find()
{
    Real t[2];
	auto quantity = StaticFindIntersectorLine3Cylinder3<Real>::Find(m_Segment.GetCenterPoint(), m_Segment.GetDirection(), mCylinder, t);

    m_Quantity = 0;
    for (auto i = 0; i < quantity; ++i)
    {
        if (Math::FAbs(t[i]) <= m_Segment.GetExtent())
        {
			m_Point[m_Quantity++] = m_Segment.GetCenterPoint() +  t[i]*m_Segment.GetDirection();
        }
    }

    if (m_Quantity == 2)
    {
		this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (m_Quantity == 1)
    {
		this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
		this->SetIntersectionType(IntersectionType::Empty);
    }	 
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Cylinder3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}
 

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_DETAIL_H