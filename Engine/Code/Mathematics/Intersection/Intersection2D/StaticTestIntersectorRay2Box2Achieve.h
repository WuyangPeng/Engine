///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 16:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_ACHIEVE_H

#include "StaticFindIntersectorLine2Box2.h"
#include "StaticTestIntersectorRay2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay2Box2<Real>::StaticTestIntersectorRay2Box2(const Ray2& ray, const Box2& box, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Ray{ ray }, m_Box{ box }
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
const Mathematics::Ray2<Real> Mathematics::StaticTestIntersectorRay2Box2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorRay2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay2Box2<Real>::Test()
{
    Vector2D directionDotAxis{};
    Vector2D directionDotAxisAbs{};
    Vector2D diffDotAxis{};
    Vector2D diffDotAxisAbs{};

    auto diff = m_Ray.GetOrigin() - m_Box.GetCenter();

    directionDotAxis[0] = Vector2DTools::DotProduct(m_Ray.GetDirection(), m_Box.GetAxis0());
    directionDotAxisAbs[0] = Math::FAbs(directionDotAxis[0]);
    diffDotAxis[0] = Vector2DTools::DotProduct(diff, m_Box.GetAxis0());
    diffDotAxisAbs[0] = Math::FAbs(diffDotAxis[0]);
    if (m_Box.GetExtent0() < diffDotAxisAbs[0] && Math::GetValue(0) <= diffDotAxis[0] * directionDotAxis[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    directionDotAxis[1] = Vector2DTools::DotProduct(m_Ray.GetDirection(), m_Box.GetAxis1());
    directionDotAxisAbs[1] = Math::FAbs(directionDotAxis[1]);
    diffDotAxis[1] = Vector2DTools::DotProduct(diff, m_Box.GetAxis1());
    diffDotAxisAbs[1] = Math::FAbs(diffDotAxis[1]);
    if (m_Box.GetExtent1() < diffDotAxisAbs[1] && Math::GetValue(0) <= diffDotAxis[1] * directionDotAxis[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto perp = Vector2DTools::GetPerp(m_Ray.GetDirection());
    auto lhs = Math::FAbs(Vector2DTools::DotProduct(perp, diff));
    auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp, m_Box.GetAxis0()));
    auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp, m_Box.GetAxis1()));
    auto rhs = m_Box.GetExtent0() * part0 + m_Box.GetExtent1() * part1;
    if (lhs <= rhs)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_ACHIEVE_H