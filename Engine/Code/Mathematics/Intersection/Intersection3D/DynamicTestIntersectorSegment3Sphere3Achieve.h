///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 10:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H

#include "DynamicTestIntersectorSegment3Sphere3.h"
#include "StaticTestIntersectorSegment3Capsule3Detail.h"
#include "StaticTestIntersectorSegment3Sphere3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::DynamicTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Segment{ segment }, m_Sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Sphere3<Real>::Test()
{
    // 检查最初是否相交。
    StaticTestIntersectorSegment3Sphere3<Real> inte{ m_Segment, m_Sphere };
    this->SetIntersectionType(inte.GetIntersectionType());
    if (inte.IsIntersection())
    {
        return;
    }

    /// 从球体速度中减去线段速度，以便计算基于线段的坐标系。
    /// 在该系统中，线路当然是固定的。 球体跨越一个胶囊，但是取而代之的是，我们将根据球体半径“扩大”线段，并将球体收缩到其中心。
    /// 现在的问题是检测移动中心第一次与由线段和球体半径形成的胶囊相交。

    const Capsule3<Real> capsule{ m_Segment, m_Sphere.GetRadius() };

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto relSpeed = Vector3DTools::VectorMagnitude(relVelocity);
    relVelocity.Normalize();
    const Segment3 path{ (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed, m_Sphere.GetCenter() + (Math::GetRational(1, 2)) * this->GetTMax() * relSpeed * relVelocity, relVelocity };

    StaticTestIntersectorSegment3Capsule3<Real> intersector{ path, capsule };
    this->SetIntersectionType(intersector.GetIntersectionType());
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_ACHIEVE_H