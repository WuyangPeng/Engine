///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H

#include "StaticTestIntersectorLine2Box2.h"
#include "StaticTestIntersectorSegment2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment2Box2<Real>::StaticTestIntersectorSegment2Box2(const Segment2& segment, const Box2& box, bool solid, const Real dotThreshold)
    : ParentType{ dotThreshold }, segment{ segment }, box{ box }, solid{ solid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorSegment2Box2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticTestIntersectorSegment2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment2Box2<Real>::Test()
{
    auto diff = segment.GetCenterPoint() - box.GetCenter();

    Vector2Type directionDotBox{};
    Vector2Type diffDotBox{};

    directionDotBox[0] = MathType::FAbs(Vector2Tools::DotProduct(segment.GetDirection(), box.GetAxis0()));
    diffDotBox[0] = MathType::FAbs(Vector2Tools::DotProduct(diff, box.GetAxis0()));
    auto rhs = box.GetExtent0() + segment.GetExtent() * directionDotBox[0];
    if (rhs < diffDotBox[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    directionDotBox[1] = MathType::FAbs(Vector2Tools::DotProduct(segment.GetDirection(), box.GetAxis1()));
    diffDotBox[1] = MathType::FAbs(Vector2Tools::DotProduct(diff, box.GetAxis1()));
    rhs = box.GetExtent1() + segment.GetExtent() * directionDotBox[1];
    if (rhs < diffDotBox[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto perp = Vector2Tools::GetPerp(segment.GetDirection());
    auto lhs = MathType::FAbs(Vector2Tools::DotProduct(perp, diff));
    auto part0 = MathType::FAbs(Vector2Tools::DotProduct(perp, box.GetAxis0()));
    auto part1 = MathType::FAbs(Vector2Tools::DotProduct(perp, box.GetAxis1()));
    rhs = box.GetExtent0() * part0 + box.GetExtent1() * part1;
    if (lhs <= rhs)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_DETAIL_H