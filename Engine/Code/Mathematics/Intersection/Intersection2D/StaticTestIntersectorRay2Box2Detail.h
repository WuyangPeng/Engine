///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/25 11:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_DETAIL_H

#include "StaticFindIntersectorLine2Box2.h"
#include "StaticTestIntersectorRay2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Box2<Real>::StaticTestIntersectorRay2Box2(const Ray2& ray, const Box2& box, const Real dotThreshold)
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
    Vector2 directionDotAxis{};
    Vector2 directionDotAxisAbs{};
    Vector2 diffDotAxis{};
    Vector2 diffDotAxisAbs{};

    auto diff = ray.GetOrigin() - box.GetCenter();

    directionDotAxis[0] = Vector2Tools::DotProduct(ray.GetDirection(), box.GetAxis0());
    directionDotAxisAbs[0] = Math::FAbs(directionDotAxis[0]);
    diffDotAxis[0] = Vector2Tools::DotProduct(diff, box.GetAxis0());
    diffDotAxisAbs[0] = Math::FAbs(diffDotAxis[0]);
    if (box.GetExtent0() < diffDotAxisAbs[0] && Math::GetValue(0) <= diffDotAxis[0] * directionDotAxis[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    directionDotAxis[1] = Vector2Tools::DotProduct(ray.GetDirection(), box.GetAxis1());
    directionDotAxisAbs[1] = Math::FAbs(directionDotAxis[1]);
    diffDotAxis[1] = Vector2Tools::DotProduct(diff, box.GetAxis1());
    diffDotAxisAbs[1] = Math::FAbs(diffDotAxis[1]);
    if (box.GetExtent1() < diffDotAxisAbs[1] && Math::GetValue(0) <= diffDotAxis[1] * directionDotAxis[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto perp = Vector2Tools::GetPerp(ray.GetDirection());
    const auto lhs = Math::FAbs(Vector2Tools::DotProduct(perp, diff));
    const auto part0 = Math::FAbs(Vector2Tools::DotProduct(perp, box.GetAxis0()));
    const auto part1 = Math::FAbs(Vector2Tools::DotProduct(perp, box.GetAxis1()));
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