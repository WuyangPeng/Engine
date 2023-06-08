///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H

#include "StaticTestIntersectorBox2Circle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Box2.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox2Circle2<Real>::StaticTestIntersectorBox2Circle2(const Box2& box, const Circle2& circle, const Real epsilon)
    : ParentType{ epsilon }, box{ box }, circle{ circle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorBox2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticTestIntersectorBox2Circle2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::StaticTestIntersectorBox2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox2Circle2<Real>::Test()
{
    DistancePoint2Box2<Real> distancePoint2Box2{ circle.GetCenter(), box };
    const auto distance = distancePoint2Box2.Get().GetDistance();
    if (distance <= circle.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_CIRCLE2_DETAIL_H