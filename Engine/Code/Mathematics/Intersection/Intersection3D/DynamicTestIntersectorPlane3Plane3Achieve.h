///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/14 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H

#include "DynamicTestIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::DynamicTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Plane0{ plane0 }, m_Plane1{ plane1 }
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
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorPlane3Plane3<Real>::Test()
{
    auto dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal());
    if (Math::FAbs(dot) < Math::GetValue(1) - Math::GetZeroTolerance())
    {
        /// 平面最初是相交的。 线速度不会改变它们相交的事实。
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Line);
        return;
    }

    // 检查平面是否已经共面。
    auto diff = Math::GetValue(0);
    if (Math::GetValue(0) <= dot)
    {
        // 法线方向相同，需要查看c0 - c1。
        diff = m_Plane0.GetConstant() - m_Plane1.GetConstant();
    }
    else
    {
        // 法线方向相反，需要查看c0 + c1。
        diff = m_Plane0.GetConstant() + m_Plane1.GetConstant();
    }

    if (Math::FAbs(diff) < Math::GetZeroTolerance())
    {
        // 平面最初是相同的。
        this->SetContactTime(Math::GetValue(0));
        this->SetIntersectionType(IntersectionType::Plane);
        return;
    }

    // 这些平面是平行且分开的。 确定何时它们将成为共面的。
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), relVelocity);
    if (Math::FAbs(dot) < Math::GetZeroTolerance())
    {
        // 平面的相对运动使它们保持平行。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetContactTime(diff / dot);
    if (Math::GetValue(0) <= this->GetContactTime() && this->GetContactTime() <= this->GetTMax())
    {
        // 平面彼此相向，并会在指定的时间间隔内相遇。
        this->SetIntersectionType(IntersectionType::Plane);
        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H