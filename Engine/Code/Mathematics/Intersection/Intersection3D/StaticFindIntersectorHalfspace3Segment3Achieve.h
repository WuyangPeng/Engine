///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:22)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H

#include "IntersectorUtility3Detail.h"
#include "StaticFindIntersectorHalfspace3Segment3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, const Real epsilon)
    : ParentType{ epsilon }, halfspace{ halfspace }, segment{ segment }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
void Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::Find()
{
    // 从线段开始，将其裁剪在平面上。

    typename IntersectorUtility3<Real>::Container container{ segment.GetBeginPoint(), point1 = segment.GetEndPoint() };

    container = IntersectorUtility3<Real>::ClipConvexPolygonAgainstPlane(-halfspace.GetNormal(), -halfspace.GetConstant(), container);
    quantity = boost::numeric_cast<int>(container.size());

    if (quantity == 0)
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else if (quantity == 1)
    {
        point0 = container.at(0);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else if (1 < quantity)
    {
        point0 = container.at(0);
        point1 = container.at(1);
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorHalfspace3Segment3<Real>::GetPoint(int index) const
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H