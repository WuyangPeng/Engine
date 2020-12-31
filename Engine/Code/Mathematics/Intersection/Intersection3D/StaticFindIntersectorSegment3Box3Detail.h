// Threading Core Render Engine
// ���ߣ������������ʶ���������
// Copyright (c) 2011-2017
//
// ����汾��1.0.0.0 (2017/12/21 14:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "StaticFindIntersectorSegment3Box3.h"
#include "IntersectorUtility3.h" 
#include "StaticFindIntersectorLine3Box3.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Box3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::StaticFindIntersectorSegment3Box3(const Segment3& segment,const Box3& box, bool solid)
	: m_Segment{ segment }, m_Box{ box }
{
    m_Quantity = 0;
    m_Solid = solid;
	Find();
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetSegment() const
{
    return m_Segment;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetBox() const
{
    return m_Box;
} 

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::Find()
{
    auto t0 = -m_Segment.GetExtent();
	auto t1 = m_Segment.GetExtent();
	int mIntersectionType = 0;
	StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, m_Segment.GetCenterPoint(),  m_Segment.GetDirection(), m_Box, m_Solid, m_Quantity, m_Point,  mIntersectionType);
	this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType>( mIntersectionType));
}
 
template <typename Real>
int  Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const  Mathematics::Vector3D<Real>  Mathematics::StaticFindIntersectorSegment3Box3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H