///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorSegment3Lozenge3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Rectangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>::StaticTestIntersectorSegment3Lozenge3(const Segment3Type& segment, const Lozenge3Type& lozenge, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, lozenge{ lozenge }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>::GetLozenge() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Lozenge3<Real>::Test()
{
    const auto distance = DistanceSegment3Rectangle3<Real>(segment, lozenge.GetRectangle()).Get().GetDistance();

    if (distance <= lozenge.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_DETAIL_H