// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 15:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H

#include "StaticTestIntersectorLine2Box2.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Box2<Real>
	::StaticTestIntersectorLine2Box2(const Line2& line, const Box2& box)
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
	auto LHS = Math::FAbs(Vector2DTools::DotProduct(perp, diff));
	auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp, mBox.GetAxis0()));
	auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp, mBox.GetAxis1()));
	auto RHS = mBox.GetExtent0()*part0 + mBox.GetExtent1()*part1;
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