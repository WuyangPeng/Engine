///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H

#include "DynamicTestIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::DynamicTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tMax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, plane0{ plane0 }, plane1{ plane1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane0;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::Test()
{
    auto dot = Vector3ToolsType::DotProduct(plane0.GetNormal(), plane1.GetNormal());
    if (MathType::FAbs(dot) < MathType::GetValue(1) - MathType::GetZeroTolerance())
    {
        /// 平面最初是相交的。 线速度不会改变它们相交的事实。
        this->SetContactTime(MathType::GetValue(0));
        this->SetIntersectionType(IntersectionType::Line);
        return;
    }

    // 检查平面是否已经共面。
    auto diff = MathType::GetValue(0);
    if (MathType::GetValue(0) <= dot)
    {
        // 法线方向相同，需要查看c0 - c1。
        diff = plane0.GetConstant() - plane1.GetConstant();
    }
    else
    {
        // 法线方向相反，需要查看c0 + c1。
        diff = plane0.GetConstant() + plane1.GetConstant();
    }

    if (MathType::FAbs(diff) < MathType::GetZeroTolerance())
    {
        // 平面最初是相同的。
        this->SetContactTime(MathType::GetValue(0));
        this->SetIntersectionType(IntersectionType::Plane);
        return;
    }

    // 这些平面是平行且分开的。 确定何时它们将成为共面的。
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    dot = Vector3ToolsType::DotProduct(plane0.GetNormal(), relVelocity);
    if (MathType::FAbs(dot) < MathType::GetZeroTolerance())
    {
        // 平面的相对运动使它们保持平行。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetContactTime(diff / dot);
    if (MathType::GetValue(0) <= this->GetContactTime() && this->GetContactTime() <= this->GetTMax())
    {
        // 平面彼此相向，并会在指定的时间间隔内相遇。
        this->SetIntersectionType(IntersectionType::Plane);
        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_DETAIL_H