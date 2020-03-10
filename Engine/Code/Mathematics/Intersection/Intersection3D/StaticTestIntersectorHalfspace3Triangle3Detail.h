// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorHalfspace3Triangle3.h"
#include "IntersectorAxis.h"
 
template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::StaticTestIntersectorHalfspace3Triangle3 (const Plane3& halfspace, const Triangle3& triangle)
	:mHalfspace{ halfspace }, mTriangle{ triangle }
{
	Test();
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::GetHalfspace() const
{
    return mHalfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::GetTriangle() const
{
    return mTriangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Triangle3<Real>
	::Test()
{
    Real fmin, fmax;
    IntersectorAxis<Real>::GetProjection(mHalfspace.GetNormal(), mTriangle, fmin, fmax);

	if (fmin <= mHalfspace.GetConstant())
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}
 

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_DETAIL_H