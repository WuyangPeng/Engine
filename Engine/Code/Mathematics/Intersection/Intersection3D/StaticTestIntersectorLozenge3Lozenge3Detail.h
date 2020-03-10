// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorLozenge3Lozenge3.h"
#include "Mathematics/Distance/Distance3D/DistRectangle3Rectangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>
	::StaticTestIntersectorLozenge3Lozenge3(const Lozenge3& lozenge0, const Lozenge3& lozenge1)
	:mLozenge0{ lozenge0 }, mLozenge1{ lozenge1 }
{
	Test();
}

template <typename Real>
const Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>
	::GetLozenge0() const
{
    return mLozenge0;
}

template <typename Real>
const Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>
	::GetLozenge1() const
{
    return mLozenge1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>
	::Test()
{
    auto distance = DistRectangle3Rectangle3<Real>(mLozenge0.GetRectangle(),mLozenge1.GetRectangle()).Get().GetDistance();
	auto rSum = mLozenge0.GetRadius() + mLozenge1.GetRadius();
	if (distance <= rSum)
	{
		this->SetIntersectionType(IntersectionType::Point);
	}
	else
	{
		this->SetIntersectionType(IntersectionType::Empty);
	}
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_DETAIL_H