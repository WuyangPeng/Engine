///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 15:45)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Plane3.h"
#include "StaticTestIntersectorCircle3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorCircle3Plane3<Real>::StaticTestIntersectorCircle3Plane3(const Circle3& circle, const Plane3& plane, const Real epsilon)
    : ParentType{ epsilon }, m_Circle{ circle }, m_Plane{ plane }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorCircle3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticTestIntersectorCircle3Plane3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorCircle3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
void Mathematics::StaticTestIntersectorCircle3Plane3<Real>::Test()
{
    // 构造圆的平面。
    const Plane3 circlePlane{ m_Circle.GetNormal(), m_Circle.GetCenter() };

    // 计算此平面与输入平面的交点。
    StaticFindIntersectorPlane3Plane3<Real> intr{ m_Plane, circlePlane };
    if (!intr.IsIntersection())
    {
        // 平面是平行且不相交的。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (intr.GetIntersectionType() == IntersectionType::Plane)
    {
        // 平面相同，圆是常见的交集。
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // 平面相交成一条线。
    const auto line = intr.GetIntersectionLine();

    /// 找到圆和直线上的一两个点。 如果线为t * D + P，圆心为C，圆半径为r，
    /// 则r^2 = |t * D + P - C|^2 = |D|^2 * t^2 + 2 * Dot(D,P-C) * t + |P-C|^2。
    /// 这是形式为a2 * t^2 + 2 * a1 * t + a0 = 0的二次方程。
    auto diff = line.GetOrigin() - m_Circle.GetCenter();
    auto a2 = Vector3DTools::VectorMagnitudeSquared(line.GetDirection());
    auto a1 = Vector3DTools::DotProduct(diff, line.GetDirection());
    auto a0 = Vector3DTools::VectorMagnitudeSquared(diff) - m_Circle.GetRadius() * m_Circle.GetRadius();

    // 实值根表示一个交集。
    auto discr = a1 * a1 - a0 * a2;
    this->SetIntersectionType(Math::GetValue(0) <= discr ? IntersectionType::Point : IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_ACHIEVE_H