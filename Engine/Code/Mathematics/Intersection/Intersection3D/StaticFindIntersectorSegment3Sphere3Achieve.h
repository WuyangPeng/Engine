///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/02 18:01)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorSegment3Capsule3.h"
#include "StaticFindIntersectorSegment3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::StaticFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, sphere{ sphere }, quantity{}, point0{}, point1{}, segmentParameter0{}, segmentParameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::Find()
{
    auto diff = segment.GetCenterPoint() - sphere.GetCenter();
    auto a0 = Vector3Tools::DotProduct(diff, diff) - sphere.GetRadius() * sphere.GetRadius();
    auto a1 = Vector3Tools::DotProduct(segment.GetDirection(), diff);
    auto discr = a1 * a1 - a0;
    if (discr < Math::GetValue(0))
    {
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto extent0 = segment.GetExtent() * segment.GetExtent() + a0;
    auto extent1 = (Math::GetValue(2)) * a1 * segment.GetExtent();
    auto minus = extent0 - extent1;
    auto plus = extent0 + extent1;

    if (minus * plus <= Math::GetValue(0))
    {
        auto root = Math::Sqrt(discr);
        segmentParameter0 = (minus > Math::GetValue(0) ? -a1 - root : -a1 + root);
        point0 = segment.GetCenterPoint() + segmentParameter0 * segment.GetDirection();
        quantity = 1;
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (Math::GetValue(0) < minus && Math::FAbs(a1) < segment.GetExtent())
    {
        if (this->GetEpsilon() <= discr)
        {
            auto root = Math::Sqrt(discr);
            segmentParameter0 = -a1 - root;
            segmentParameter1 = -a1 + root;
            point0 = segment.GetCenterPoint() + segmentParameter0 * segment.GetDirection();
            point1 = segment.GetCenterPoint() + segmentParameter1 * segment.GetDirection();
            quantity = 2;
            this->SetIntersectionType(IntersectionType::Segment);
        }
        else
        {
            segmentParameter0 = -a1;
            point0 = segment.GetCenterPoint() + segmentParameter0 * segment.GetDirection();
            quantity = 1;
            this->SetIntersectionType(IntersectionType::Point);
        }
    }
    else
    {
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetPoint(int index) const
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
Real Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segmentParameter0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Sphere3<Real>::GetSegmentParameter1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segmentParameter1;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H