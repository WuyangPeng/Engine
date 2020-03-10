// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/13 10:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H

#include "StaticTestIntersectorLine2Box2.h"
 
template <typename Real>
Mathematics::StaticTestIntersectorLine2Box2<Real>
	::StaticTestIntersectorLine2Box2(const Line2& line,const Box2& box)
	: mLine{ line }, mBox{ box }
{
	Test();
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::StaticTestIntersectorLine2Box2<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const  Mathematics::Box2<Real> Mathematics::StaticTestIntersectorLine2Box2<Real>
	::GetBox() const
{
    return mBox;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Box2<Real>
	::Test()
{
    auto diff = mLine.GetOrigin() - mBox.GetCenter();
	auto perp = Vector2DTools::GetPerp(mLine.GetDirection());
	auto LHS = Math::FAbs(Vector2DTools::DotProduct(perp,diff));
	auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp,mBox.GetFirstAxis()));
	auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp,mBox.GetSecondAxis()));
	auto RHS = mBox.GetFirstExtent()*part0 + mBox.GetSecondExtent()*part1;
	if (LHS <= RHS)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 
#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H