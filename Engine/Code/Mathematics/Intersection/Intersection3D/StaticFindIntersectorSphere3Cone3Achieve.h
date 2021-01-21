///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 11:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Cone3<Real>::StaticFindIntersectorSphere3Cone3(const Sphere3& sphere, const Cone3& cone, const Real epsilon)
    : ParentType{ epsilon }, m_Sphere{ sphere }, m_Cone{ cone }, m_Point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSphere3Cone3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
const Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Cone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Cone3<Real>::Find()
{
    // 测试圆锥顶点是否在球体中。
    auto diff = m_Sphere.GetCenter() - m_Cone.GetVertex();
    auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto lengthSqr = Vector3DTools::VectorMagnitudeSquared(diff);
    if (lengthSqr <= radiusSqr)
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // 测试球心是否在圆锥中
    auto dot = Vector3DTools::DotProduct(diff, m_Cone.GetAxis());
    auto dotSqr = dot * dot;
    auto cosSqr = m_Cone.GetCosAngle() * m_Cone.GetCosAngle();
    if (lengthSqr * cosSqr <= dotSqr && Math::GetValue(0) < dot)
    {
        // 球体中心在圆锥体内部，因此球体和圆锥体相交。
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    /// 球体中心在圆锥体外部。 现在的问题简化为在包含圆锥顶点并由圆锥轴和从顶点到球体中心的向量跨越的平面中寻找圆与射线之间的交点。

    /// 射线是 t * D + V (t >= 0)，其中|D| = 1，dot(A,D) = cos(angle)。
    /// 同样，D = e * A + f * (C - V)。 将射线方程式插入球面方程式会产生Real^2 = |t * D + V - C|^2，
    /// 因此交点的二次方为t^2 - 2 * dot(D,C - V) * t + |C - V|^2 - Real^2 = 0。
    /// 当且仅当判别式为非负时，才发生交集。 这个测试变成
    /// dot(D,C - V)^2 >= dot(C - V,C - V) - Real^2
    /// 注意，如果右侧为非正，则不等式为true（球体包含V）。 我已经在此函数的第一段代码中排除了这一点

    auto uLength = Math::Sqrt(Math::FAbs(lengthSqr - dotSqr));
    auto test = m_Cone.GetCosAngle() * dot + m_Cone.GetSinAngle() * uLength;
    auto discr = test * test - lengthSqr + radiusSqr;

    // 计算最接近顶点V的交点
    auto t = test - Math::Sqrt(discr);
    auto value0 = diff - dot * m_Cone.GetAxis();
    auto value1 = m_Cone.GetSinAngle() / uLength;
    m_Point = t * (m_Cone.GetCosAngle() * m_Cone.GetAxis() + value1 * value0);

    if (Math::GetValue(0) <= discr && Math::GetValue(0) <= test)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H