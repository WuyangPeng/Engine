// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H

#include "StaticTestIntersectorRay2Box2.h"
#include "StaticFindIntersectorLine2Box2.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Box2<Real>
	::StaticTestIntersectorRay2Box2(const Ray2& ray, const Box2& box)
	:mRay{ ray }, mBox{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Box2<Real>
	::GetRay() const
{
    return mRay;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorRay2Box2<Real>
	::GetBox() const
{
    return mBox;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Box2<Real>
	::Test()
{
    Real WdU[2], AWdU[2], DdU[2], ADdU[2];

    auto diff = mRay.GetOrigin() - mBox.GetCenter();

    WdU[0] = Vector2DTools::DotProduct(mRay.GetDirection(),mBox.GetFirstAxis());
    AWdU[0] = Math::FAbs(WdU[0]);
    DdU[0] = Vector2DTools::DotProduct(diff,mBox.GetFirstAxis());
    ADdU[0] = Math::FAbs(DdU[0]);
    if (ADdU[0] > mBox.GetFirstExtent() && DdU[0]*WdU[0] >= Real{})
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    WdU[1] = Vector2DTools::DotProduct(mRay.GetDirection(),mBox.GetSecondAxis());
    AWdU[1] = Math::FAbs(WdU[1]);
    DdU[1] = Vector2DTools::DotProduct(diff,mBox.GetSecondAxis());
    ADdU[1] = Math::FAbs(DdU[1]);
    if (ADdU[1] > mBox.GetSecondExtent() && DdU[1]*WdU[1] >= Real{})
    {
		this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

	auto perp = Vector2DTools::GetPerp(mRay.GetDirection());
	auto LHS = Math::FAbs(Vector2DTools::DotProduct(perp,diff));
	auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp,mBox.GetFirstAxis()));
	auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp,mBox.GetSecondAxis()));
	auto RHS = mBox.GetFirstExtent()*part0 + mBox.GetSecondExtent()*part1;
    if( LHS <= RHS)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);

	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H