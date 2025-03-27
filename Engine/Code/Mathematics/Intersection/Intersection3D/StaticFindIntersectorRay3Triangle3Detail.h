///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:53)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorRay3Triangle3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Triangle3<Real>::StaticFindIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, triangle{ triangle }, rayParameter{}, triangleBary0{}, triangleBary1{}, triangleBary2{ MathType::GetValue(1) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Triangle3<Real>::Find()
{
    // 计算偏移原点，边和法线。
    auto diff = ray.GetOrigin() - triangle.GetVertex(0);
    auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    const auto normal = Vector3Tools::CrossProduct(edge1, edge2);

    // 求解 Q + t * D = b1 * E1 + b2 * E2（Q = kDiff，D = 射线方向，
    // E1 = kEdge1, E2 = kEdge2, N = Cross(E1,E2))
    //   |Dot(D,N)| * b1 = sign(Dot(D,N)) * Dot(D,Cross(Q,E2))
    //   |Dot(D,N)| * b2 = sign(Dot(D,N)) * Dot(D,Cross(E1,Q))
    //   |Dot(D,N)| * t = -sign(Dot(D,N)) * Dot(Q,N)
    auto directionDotNormal = Vector3Tools::DotProduct(ray.GetDirection(), normal);
    auto sign = MathType::GetValue(0);
    if (MathType::GetZeroTolerance() < directionDotNormal)
    {
        sign = MathType::GetValue(1);
    }
    else if (directionDotNormal < -MathType::GetZeroTolerance())
    {
        sign = MathType::GetValue(-1);
        directionDotNormal = -directionDotNormal;
    }
    else
    {
        // 射线和三角形是平行的，即使射线相交也称其为“无交集”。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto value0 = sign * Vector3Tools::DotProduct(ray.GetDirection(), Vector3Tools::CrossProduct(diff, edge2));
    if (MathType::GetValue(0) <= value0)
    {
        auto value1 = sign * Vector3Tools::DotProduct(ray.GetDirection(), Vector3Tools::CrossProduct(edge1, diff));
        if (MathType::GetValue(0) <= value1)
        {
            if (value0 + value1 <= directionDotNormal)
            {
                // 线与三角形相交，检查射线是否相交。
                auto value2 = -sign * Vector3Tools::DotProduct(diff, normal);
                if (MathType::GetValue(0) <= value2)
                {
                    // 射线与三角形相交。
                    auto inv = (MathType::GetValue(1)) / directionDotNormal;
                    rayParameter = value2 * inv;
                    triangleBary1 = value0 * inv;
                    triangleBary2 = value1 * inv;
                    triangleBary0 = MathType::GetValue(1) - triangleBary1 - triangleBary2;
                    this->SetIntersectionType(IntersectionType::Point);
                    return;
                }
                // else: t < 0, 没有交集
            }
            // else: b1+b2 > 1, 没有交集
        }
        // else: b2 < 0,  没有交集
    }
    // else: b1 < 0, 没有交集

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetRayParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rayParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangleBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangleBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangleBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangleBary2;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H