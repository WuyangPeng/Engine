///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:14)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Cone3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Cone3<Real>::StaticFindIntersectorSphere3Cone3(const Sphere3Type& sphere, const Cone3Type& cone, const Real epsilon)
    : ParentType{ epsilon }, sphere{ sphere }, cone{ cone }, point{}
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
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
Mathematics::Cone3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetCone() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cone;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Cone3<Real>::Find()
{
    // 测试圆锥顶点是否在球体中。
    auto diff = sphere.GetCenter() - cone.GetVertex();
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto lengthSqr = Vector3ToolsType::GetLengthSquared(diff);
    if (lengthSqr <= radiusSqr)
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // 测试球心是否在圆锥中
    auto dot = Vector3ToolsType::DotProduct(diff, cone.GetAxis());
    auto dotSqr = dot * dot;
    auto cosSqr = cone.GetCosAngle() * cone.GetCosAngle();
    if (lengthSqr * cosSqr <= dotSqr && MathType::GetValue(0) < dot)
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

    auto length = MathType::Sqrt(MathType::FAbs(lengthSqr - dotSqr));
    auto test = cone.GetCosAngle() * dot + cone.GetSinAngle() * length;
    auto discr = test * test - lengthSqr + radiusSqr;

    // 计算最接近顶点V的交点
    auto t = test - MathType::Sqrt(discr);
    auto value0 = diff - dot * cone.GetAxis();
    auto value1 = cone.GetSinAngle() / length;
    point = t * (cone.GetCosAngle() * cone.GetAxis() + value1 * value0);

    if (MathType::GetValue(0) <= discr && MathType::GetValue(0) <= test)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSphere3Cone3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_ACHIEVE_H