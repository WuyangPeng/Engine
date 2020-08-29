// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_DETAIL_H

#include "StaticFindIntersectorRay2Box2.h"
#include "StaticFindIntersectorLine2Box2.h" 

template <typename Real>
Mathematics::StaticFindIntersectorRay2Box2<Real>
	::StaticFindIntersectorRay2Box2(const Ray2& ray, const Box2& box)
	: mRay{ ray }, mBox{ box }
{
	Find();
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>
	::GetRay() const
{
	return mRay;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay2Box2<Real>
	::Find()
{
	auto t0 = Math::GetValue(0);
	auto t1 = Math::sm_MaxReal;
	auto mIntersectionType = 0;
	StaticFindIntersectorLine2Box2<Real>::DoClipping(t0, t1, mRay.GetOrigin(), mRay.GetDirection(), mBox, true, mQuantity, mPoint, mIntersectionType);
	this->SetIntersectionType(static_cast<IntersectionType>(mIntersectionType));
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay2Box2<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorRay2Box2<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_DETAIL_H