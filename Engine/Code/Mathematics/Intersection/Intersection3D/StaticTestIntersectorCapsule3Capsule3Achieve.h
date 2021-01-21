///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 15:40)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_ACHIEVE_H

#include "StaticTestIntersectorCapsule3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::StaticTestIntersectorCapsule3Capsule3(const Capsule3& capsule0, const Capsule3& capsule1, const Real epsilon)
    : ParentType{ epsilon }, m_Capsule0{ capsule0 }, m_Capsule1{ capsule1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::GetCapsule0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Capsule0;
}

template <typename Real>
const Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::GetCapsule1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Capsule1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::Test()
{
    DistanceSegment3Segment3<Real> distanceSegment3Segment3{ m_Capsule0.GetSegment(), m_Capsule1.GetSegment() };
    auto distance = distanceSegment3Segment3.Get().GetDistance();
    auto radiusSum = m_Capsule0.GetRadius() + m_Capsule1.GetRadius();
    if (distance <= radiusSum)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_ACHIEVE_H