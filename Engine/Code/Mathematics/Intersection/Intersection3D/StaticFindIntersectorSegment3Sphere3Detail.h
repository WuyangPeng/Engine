// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H

#include "StaticFindIntersectorSegment3Sphere3.h"
#include "StaticFindIntersectorSegment3Capsule3.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::StaticFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere)
	: m_Segment{ segment }, m_Sphere{ sphere }
{
    m_Quantity = 0;
    ZeroThreshold = Math::GetZeroTolerance();
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetSphere() const
{
    return m_Sphere;
}
 

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::Find()
{
	auto diff = m_Segment.GetCenterPoint() - m_Sphere.GetCenter();
	auto a0 = Vector3DTools::DotProduct(diff,diff) - m_Sphere.GetRadius()*m_Sphere.GetRadius();
	auto a1 = Vector3DTools::DotProduct(m_Segment.GetDirection(),diff);
	auto discr = a1*a1 - a0;
    if (discr < Math<Real>::GetZero())
    {
        m_Quantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	auto tmp0 = m_Segment.GetExtent()*m_Segment.GetExtent() + a0;
	auto tmp1 = (Math::GetValue(2))*a1*m_Segment.GetExtent();
	auto qm = tmp0 - tmp1;
	auto qp = tmp0 + tmp1;
    Real root;
    if (qm*qp <= Math<Real>::GetZero())
    {
        root = Math::Sqrt(discr);
        m_SegmentParameter[0] = (qm > Math<Real>::GetZero() ? -a1 - root : -a1 + root);
        m_Point[0] = m_Segment.GetCenterPoint() + m_SegmentParameter[0] * m_Segment.GetDirection();
        m_Quantity = 1;
		this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (qm > Math<Real>::GetZero() && Math::FAbs(a1) < m_Segment.GetExtent())
    {
        if (discr >= ZeroThreshold)
        {
            root = Math::Sqrt(discr);
            m_SegmentParameter[0] = -a1 - root;
            m_SegmentParameter[1] = -a1 + root;
            m_Point[0] = m_Segment.GetCenterPoint() + m_SegmentParameter[0] *  m_Segment.GetDirection();
            m_Point[1] = m_Segment.GetCenterPoint() + m_SegmentParameter[1] * m_Segment.GetDirection();
            m_Quantity = 2;
			this->SetIntersectionType(IntersectionType::Segment);
        }
        else
        {
            m_SegmentParameter[0] = -a1;
            m_Point[0] = m_Segment.GetCenterPoint() + m_SegmentParameter[0] * m_Segment.GetDirection();
            m_Quantity = 1;
			this->SetIntersectionType(IntersectionType::Point);
        }
    }
    else
    {
        m_Quantity = 0;
		this->SetIntersectionType(IntersectionType::Empty);
    }   
}
 
template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Sphere3<Real>
	::GetSegmentParameter(int i) const
{
    return m_SegmentParameter[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_DETAIL_H