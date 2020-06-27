// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorRay2Triangle2.h"
#include "StaticTestIntersectorLine2Triangle2.h" 
#include "Mathematics/Intersection/StaticFindIntersector1.h" 

template <typename Real>
Mathematics::StaticTestIntersectorRay2Triangle2<Real>
	::StaticTestIntersectorRay2Triangle2(const Ray2& ray, const Triangle2& triangle)
	:mRay{ ray }, mTriangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Triangle2<Real>
	::GetRay() const
{
	return mRay;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorRay2Triangle2<Real>
	::GetTriangle() const
{
	return mTriangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Triangle2<Real>
	::Test()
{
	Real dist[3]{};
	int sign[3]{};
	auto positive = 0;
	auto negative = 0;
	auto zero = 0;
	StaticFindIntersectorLine2Triangle2<Real>::TriangleLineRelations(mRay.GetOrigin(), mRay.GetDirection(), mTriangle, dist, sign, positive, negative, zero);

	if (positive == 3 || negative == 3)
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
	else
	{
		Real param[2]{};
		StaticFindIntersectorLine2Triangle2<Real>::GetInterval(mRay.GetOrigin(), mRay.GetDirection(), mTriangle, dist, sign, param);

		StaticFindIntersector1<Real> intr{ param[0], param[1], Math<Real>::sm_Zero,Math::sm_MaxReal };

		auto mQuantity = intr.GetNumIntersections();
		if (mQuantity == 2)
		{
			this->SetIntersectionType(IntersectionType::Segment);
		}
		else if (mQuantity == 1)
		{
			this->SetIntersectionType(IntersectionType::Point);
		}
		else
		{
			this->SetIntersectionType(IntersectionType::Empty);
		}
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_DETAIL_H