// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H

#include "StaticTestIntersectorSegment2Box2.h"
#include "StaticTestIntersectorLine2Box2.h" 

template <typename Real>
Mathematics::StaticTestIntersectorSegment2Box2<Real>
	::StaticTestIntersectorSegment2Box2(const Segment2& segment, const Box2& box, bool solid)
	:mSegment{ segment }, mBox{ box }
{
	mSolid = solid;

	Test();
}

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorSegment2Box2<Real>
	::GetSegment() const
{
	return mSegment;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorSegment2Box2<Real>
	::GetBox() const
{
	return mBox;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment2Box2<Real>
	::Test()
{
	auto diff = mSegment.GetCenterPoint() - mBox.GetCenter();

	Real AWdU[2]{};
	Real ADdU[2]{};
	auto RHS = Math::sm_Zero;
	AWdU[0] = Math::FAbs(Vector2DTools::DotProduct(mSegment.GetDirection(), mBox.GetFirstAxis()));
	ADdU[0] = Math::FAbs(Vector2DTools::DotProduct(diff, mBox.GetFirstAxis()));
	RHS = mBox.GetFirstExtent() + mSegment.GetExtent() * AWdU[0];
	if (ADdU[0] > RHS)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	AWdU[1] = Math::FAbs(Vector2DTools::DotProduct(mSegment.GetDirection(), mBox.GetSecondAxis()));
	ADdU[1] = Math::FAbs(Vector2DTools::DotProduct(diff, mBox.GetSecondAxis()));
	RHS = mBox.GetSecondExtent() + mSegment.GetExtent() * AWdU[1];
	if (ADdU[1] > RHS)
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	auto perp = Vector2DTools::GetPerp(mSegment.GetDirection());
	auto LHS = Math::FAbs(Vector2DTools::DotProduct(perp, diff));
	auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp, mBox.GetFirstAxis()));
	auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp, mBox.GetSecondAxis()));
	RHS = mBox.GetFirstExtent() * part0 + mBox.GetSecondExtent()*part1;
	if (LHS <= RHS)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);

	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H