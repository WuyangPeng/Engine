///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:09)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "IntersectorUtility3Detail.h"
#include "StaticFindIntersectorLine3Box3Detail.h"
#include "StaticFindIntersectorSegment3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Box3<Real>::StaticFindIntersectorSegment3Box3(const Segment3Type& segment, const Box3Type& box, bool solid, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, box{ box }, solid{ solid }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Box3<Real>::Find()
{
    auto t0 = -segment.GetExtent();
    auto t1 = segment.GetExtent();

    const auto findShared = StaticFindIntersectorLine3Box3<Real>::DoClipping(t0, t1, segment.GetCenterPoint(), segment.GetDirection(), box, solid);
    this->SetIntersectionType(findShared.intersectionType);
    quantity = findShared.quantity;
    point0 = findShared.point0;
    point1 = findShared.point1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSegment3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H