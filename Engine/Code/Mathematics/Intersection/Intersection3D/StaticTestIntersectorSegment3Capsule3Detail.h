///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 22:20)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorLine3Capsule3.h"
#include "StaticTestIntersectorSegment3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::StaticTestIntersectorSegment3Capsule3(const Segment3& segment, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, capsule{ capsule }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Capsule3<Real>::Test()
{
    const auto distance = DistanceSegment3Segment3<Real>(segment, capsule.GetSegment()).Get().GetDistance();
    if (distance <= capsule.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_CAPSULE3_DETAIL_H