///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorLine3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Capsule3<Real>::StaticTestIntersectorLine3Capsule3(const Line3Type& line, const Capsule3Type& capsule, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, capsule{ capsule }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Capsule3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorLine3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Capsule3<Real>::Test()
{
    const auto distance = DistanceLine3Segment3<Real>(line, capsule.GetSegment()).Get().GetDistance();
    if (distance <= capsule.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_DETAIL_H
