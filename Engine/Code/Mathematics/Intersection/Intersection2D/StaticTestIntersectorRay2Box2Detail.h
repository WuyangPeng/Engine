///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H

#include "StaticFindIntersectorLine2Box2.h"
#include "StaticTestIntersectorRay2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Box2<Real>::StaticTestIntersectorRay2Box2(const Ray2Type& ray, const Box2Type& box, const Real dotThreshold)
    : ParentType{ dotThreshold }, ray{ ray }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Box2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticTestIntersectorRay2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Box2<Real>::Test()
{
    Vector2Type directionDotAxis{};
    Vector2Type directionDotAxisAbs{};
    Vector2Type diffDotAxis{};
    Vector2Type diffDotAxisAbs{};

    auto diff = ray.GetOrigin() - box.GetCenter();

    directionDotAxis[0] = Vector2ToolsType::DotProduct(ray.GetDirection(), box.GetAxis0());
    directionDotAxisAbs[0] = MathType::FAbs(directionDotAxis[0]);
    diffDotAxis[0] = Vector2ToolsType::DotProduct(diff, box.GetAxis0());
    diffDotAxisAbs[0] = MathType::FAbs(diffDotAxis[0]);
    if (box.GetExtent0() < diffDotAxisAbs[0] && MathType::GetValue(0) <= diffDotAxis[0] * directionDotAxis[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    directionDotAxis[1] = Vector2ToolsType::DotProduct(ray.GetDirection(), box.GetAxis1());
    directionDotAxisAbs[1] = MathType::FAbs(directionDotAxis[1]);
    diffDotAxis[1] = Vector2ToolsType::DotProduct(diff, box.GetAxis1());
    diffDotAxisAbs[1] = MathType::FAbs(diffDotAxis[1]);
    if (box.GetExtent1() < diffDotAxisAbs[1] && MathType::GetValue(0) <= diffDotAxis[1] * directionDotAxis[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto perp = Vector2ToolsType::GetPerp(ray.GetDirection());
    const auto lhs = MathType::FAbs(Vector2ToolsType::DotProduct(perp, diff));
    const auto part0 = MathType::FAbs(Vector2ToolsType::DotProduct(perp, box.GetAxis0()));
    const auto part1 = MathType::FAbs(Vector2ToolsType::DotProduct(perp, box.GetAxis1()));
    const auto rhs = box.GetExtent0() * part0 + box.GetExtent1() * part1;
    if (lhs <= rhs)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H