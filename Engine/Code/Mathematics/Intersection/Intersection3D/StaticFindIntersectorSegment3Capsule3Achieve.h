///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/02 17:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Capsule3Detail.h"
#include "StaticFindIntersectorSegment3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::StaticFindIntersectorSegment3Capsule3(const Segment3& segment, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, capsule{ capsule }, quantity{}, point0{}, point1{}, parameter0{}, parameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return capsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::Find()
{
    const auto findShared = StaticFindIntersectorLine3Capsule3<Real>::Find(segment.GetCenterPoint(), segment.GetDirection(), capsule);

    quantity = 0;
    for (auto i = 0; i < findShared.quantity; ++i)
    {
        auto parameter = (i == 0) ? findShared.parameter0 : findShared.parameter1;
        if (Math::FAbs(parameter) <= segment.GetExtent())
        {
            if (quantity == 0)
            {
                point0 = segment.GetCenterPoint() + parameter * segment.GetDirection();
            }
            else if (quantity == 1)
            {
                point1 = segment.GetCenterPoint() + parameter * segment.GetDirection();
            }
        }

        ++quantity;
    }

    parameter0 = findShared.parameter0;
    parameter1 = findShared.parameter1;

    if (quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetParameter0() const noexcept
{
    return parameter0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Capsule3<Real>::GetParameter1() const noexcept
{
    return parameter1;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_ACHIEVE_H