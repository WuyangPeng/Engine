///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:04)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Segment3.h"
#include "FindIntersectorAxis.h"
#include "IntersectorConfiguration.h"
#include "TestIntersectorAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::DynamicFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, halfspace{ halfspace }, segment{ segment }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    using SegmentType = std::array<Vector3, 2>;
    SegmentType segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

    const auto cfg = FindIntersectorAxis<Real>::GetConfiguration(halfspace.GetNormal(), segmentType);
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    const TestIntersectorAxis<Real> testIntersectorAxis{ halfspace.GetNormal(), relVelocity, -Math::maxReal, halfspace.GetConstant(), cfg.GetMin(), cfg.GetMax(), this->GetTMax() };
    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        // 永不相交。
        this->SetIntersectionType(IntersectionType::Empty);
        this->SetContactTime(contactTime);
        return;
    }

    if (Math::Approximate(contactTime, Math::GetValue(0)))
    {
        // 现在相交。
        this->SetIntersectionType(IntersectionType::Empty);
        this->SetContactTime(contactTime);
        return;
    }

    // 将点也及时调整到正确的位置。
    auto diff = contactTime * this->GetRhsVelocity();

    // 正极线（右）。
    if (cfg.GetMap() == VertexProjectionMap::M1_1)
    {
        quantity = 1;
        point0 = segmentType.at(cfg.GetIndex(0));
        point0 += diff;
    }
    else  // cfg.mMap == VertexProjectionMap::M2
    {
        quantity = 2;
        point0 = segmentType.at(cfg.GetIndex(0));
        point1 = segmentType.at(cfg.GetIndex(1));
        point0 += diff;
        point1 += diff;
    }

    this->SetIntersectionType(IntersectionType::Other);
    this->SetContactTime(contactTime);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorHalfspace3Segment3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_DETAIL_H