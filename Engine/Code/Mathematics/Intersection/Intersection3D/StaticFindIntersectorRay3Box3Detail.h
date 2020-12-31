// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/15 09:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_DETAIL_H

#include "StaticFindIntersectorRay3Box3.h" 

template <typename Real>
Mathematics::StaticFindIntersectorRay3Box3<Real>
	::StaticFindIntersectorRay3Box3(const Ray3& rkRay, const Box3& rkBox)
	: mRay{ rkRay }, m_Box{ rkBox }
{
	Find();
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>
	::GetBox() const
{
    return m_Box;
}
 
template <typename Real>
void Mathematics::StaticFindIntersectorRay3Box3<Real>
	::Find()
{
	auto t0 = Math<Real>::GetZero();
	auto t1 = Math::sm_MaxReal;
	auto mIntersectionType = 0;
	StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, mRay.GetOrigin(), mRay.GetDirection(), m_Box, true, m_Quantity, m_Point, mIntersectionType);
	this->SetIntersectionType(System::UnderlyingCastEnum<IntersectionType>(mIntersectionType));
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Box3<Real>
	::GetQuantity() const
{
    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Box3<Real>
	::GetPoint(int i) const
{
    return m_Point[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_DETAIL_H