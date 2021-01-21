///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/07 16:14)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_ACHIEVE_H

#include "DynamicFindIntersectorTriangle3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection3D/DynamicFindIntersectorSegment3Sphere3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Triangle{ triangle }, m_Sphere{ sphere }, m_Point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::Find()
{
    auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();

    // 获取三角形顶点。
    auto vertices = m_Triangle.GetVertex();

    using EdgesType = std::array<Vector3D, 3>;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 获取三角形的边缘。
    EdgesType edges{ vertices[1] - vertices[0], vertices[2] - vertices[1], vertices[0] - vertices[2] };

    // 得到三角形法线。
    auto normal = Vector3DTools::CrossProduct(edges[1], edges[0]);

    // 球体中心投影在三角形法线上。
    auto normalDotCenter = Vector3DTools::DotProduct(normal, m_Sphere.GetCenter());

    // 半径在法线方向上的投影长度。 直到绝对需要时，这才使平方根归一化法线。
    auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto normRadiusSqr = Vector3DTools::VectorMagnitudeSquared(normal) * radiusSqr;

    // 三角形法线上的三角形投影。
    auto normalDotTriangle = Vector3DTools::DotProduct(normal, vertices[0]);

    // 球体到三角形沿法线的距离。
    auto distance = normalDotCenter - normalDotTriangle;

    // 由边i和三角形法线形成的平面的法线。
    EdgesType edgesCrossNormal{ Vector3DTools::CrossProduct(edges[0], normal),
                                Vector3DTools::CrossProduct(edges[1], normal),
                                Vector3DTools::CrossProduct(edges[2], normal) };

    using InsideType = std::array<bool, 3>;

    if (distance * distance <= normRadiusSqr)
    {
        // 球体当前与三角形的平面相交。

        // 查看球体中心在内部/外部的边缘。

        InsideType inside{};
        for (auto i = 0u; i < inside.size(); ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
            inside[i] = Vector3DTools::DotProduct(edgesCrossNormal[i], vertices[i]) <= Vector3DTools::DotProduct(edgesCrossNormal[i], m_Sphere.GetCenter());
#include STSTEM_WARNING_POP
        }

        if (inside[0])
        {
            if (inside[1])
            {
                if (inside[2])
                {
                    // 球体内的三角形。
                    this->SetContactTime(Math::GetValue(0));
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
                else  // !inside[2]
                {
                    // 与边<V2,V0>可能相交。
                    const Segment3<Real> segment{ vertices[2], vertices[0] };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, m_Sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        m_Point = calc.GetPoint(0);
                        this->SetIntersectionType(IntersectionType::Point);
                        return;
                    }
                    this->SetContactTime(calc.GetContactTime());
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside[2])
                {
                    // 与边<V1,V2>可能相交。
                    const Segment3<Real> segment(vertices[1], vertices[2]);
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, m_Sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        m_Point = calc.GetPoint(0);
                        this->SetIntersectionType(IntersectionType::Point);
                        return;
                    }
                    this->SetContactTime(calc.GetContactTime());
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
                else  // !inside[2]
                {
                    // 边缘为 <V1,V2>, <V2,V0>的可能相交。
                    if (FindTriangleSphereCoplanarIntersection(2, vertices, edgesCrossNormal[2], edges[2], tMax, lhsVelocity, rhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(Math::GetValue(0));
                    return;
                }
            }
        }
        else  // !inside[0]
        {
            if (inside[1])
            {
                if (inside[2])
                {
                    // 与边<V0,V1>可能相交。
                    const Segment3<Real> segment(vertices[0], vertices[1]);
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, m_Sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        m_Point = calc.GetPoint(0);
                        this->SetIntersectionType(IntersectionType::Point);
                        return;
                    }
                    this->SetContactTime(calc.GetContactTime());
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
                else  // !inside[2]
                {
                    // 边缘为 <V2,V0>, <V0,V1>的可能相交。
                    if (FindTriangleSphereCoplanarIntersection(0, vertices, edgesCrossNormal[0], edges[0], tMax, lhsVelocity, rhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(Math::GetValue(0));
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside[2])
                {
                    // 边缘为 <V0,V1>, <V1,V2>的可能相交。
                    if (FindTriangleSphereCoplanarIntersection(1, vertices, edgesCrossNormal[1], edges[1], tMax, lhsVelocity, rhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(Math::GetValue(0));
                    return;
                }
                else  // !inside[2]
                {
                    // 我们不应该到这里。
                    MATHEMATICS_ASSERTION_0(false, "意外状况\n");
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
    }
    else
    {
        // 球体当前不与三角形的平面相交。

        // 球体移动，三角形固定。
        const Vector3D relVelocity = rhsVelocity - lhsVelocity;

        // 查找球体和三角形平面的交点。 在相对于三角形的平面上发生此点的位置确定了可能的相交类型。
        normal.Normalize();

        // 球上的点我们关心与三角形平面相交。
        Vector3D spherePoint{};

        // 球面在三角形的哪一侧？
        if (normalDotTriangle < normalDotCenter)
        {
            // 正面
            if (Math::GetValue(0) <= Vector3DTools::DotProduct(relVelocity, normal))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = m_Sphere.GetCenter() - m_Sphere.GetRadius() * normal;
        }
        else
        {
            // 负面
            if (Vector3DTools::DotProduct(relVelocity, normal) <= Math::GetValue(0))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = m_Sphere.GetCenter() + m_Sphere.GetRadius() * normal;
        }

        // 找到速度射线与三角形平面的交点。

        // 将射线和平面投影到法线平面上。
        auto plane = Vector3DTools::DotProduct(normal, vertices[0]);
        auto point = Vector3DTools::DotProduct(normal, spherePoint);
        auto velocity = Vector3DTools::DotProduct(normal, relVelocity);
        auto time = (plane - point) / velocity;

        // 这相交的地方。
        auto intrPoint = spherePoint + time * relVelocity;

        // 查看此相交点在哪些边的内部/外部。
        InsideType inside{};
        for (auto i = 0u; i < inside.size(); ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
            inside[i] = Vector3DTools::DotProduct(edgesCrossNormal[i], vertices[i]) <= Vector3DTools::DotProduct(edgesCrossNormal[i], intrPoint);
#include STSTEM_WARNING_POP
        }

        if (inside[0])
        {
            if (inside[1])
            {
                if (inside[2])
                {
                    // 在时间上相交。
                    if (tMax < time)
                    {
                        // tMax之后的交点。
                        this->SetIntersectionType(IntersectionType::Empty);
                        return;
                    }
                    else
                    {
                        // intrPoint是空间中的点，假定TriVel为0。如果不是，则将其重新调整到应该的位置。
                        this->SetContactTime(time);
                        m_Point = intrPoint + time * lhsVelocity;
                        this->SetIntersectionType(IntersectionType::Empty);
                        return;
                    }
                }
                else  // !inside[2]
                {
                    // 与边<V2,V0>的可能相交。
                    const Segment3<Real> segment{ vertices[2], vertices[0] };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, m_Sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        m_Point = calc.GetPoint(0);
                        this->SetIntersectionType(calc.GetIntersectionType());
                        return;
                    }
                    this->SetIntersectionType(calc.GetIntersectionType());
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside[2])
                {
                    // 与边<V1,V2>的可能相交。
                    const Segment3<Real> segment{ vertices[1], vertices[2] };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, m_Sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        m_Point = calc.GetPoint(0);
                        this->SetIntersectionType(calc.GetIntersectionType());
                        return;
                    }
                    this->SetIntersectionType(calc.GetIntersectionType());
                    return;
                }
                else  // !inside[2]
                {
                    // 与顶点V2的潜在交点。
                    if (FindSphereVertexIntersection(vertices[2], tMax, rhsVelocity, lhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(Math::GetValue(0));
                    return;
                }
            }
        }
        else  // !inside[0]
        {
            if (inside[1])
            {
                if (inside[2])
                {
                    // 与边<V0,V1>的可能相交。
                    const Segment3<Real> segment{ vertices[0], vertices[1] };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, m_Sphere, tMax, lhsVelocity, rhsVelocity };

                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        m_Point = calc.GetPoint(0);
                        this->SetIntersectionType(calc.GetIntersectionType());
                        return;
                    }
                    this->SetIntersectionType(calc.GetIntersectionType());
                    return;
                }
                else  // !inside[2]
                {
                    // 与顶点V0的潜在交点。
                    if (FindSphereVertexIntersection(vertices[0], tMax, rhsVelocity, lhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(Math::GetValue(0));
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside[2])
                {
                    // 与顶点V1的潜在交点。
                    if (FindSphereVertexIntersection(vertices[1], tMax, rhsVelocity, lhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(Math::GetValue(0));
                    return;
                }
                else  // !inside[2]
                {
                    // 我们不应该到这里。
                    MATHEMATICS_ASSERTION_0(false, "意外状况\n");
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::FindTriangleSphereCoplanarIntersection(int index, const VertexType& vertexs, const Vector3D& sideNorm, const Vector3D& side, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 顶点是球体可以相交的两个潜在边所连接的“关键”顶点，它索引为vertex。
    // sideNorm是由（vertex，vertex + 1）和tri norm形成的平面的法线，为了避免重新计算而通过

    // 在时间0检查交叉点。
    auto dist = vertexs[index] - m_Sphere.GetCenter();
    if (Vector3DTools::VectorMagnitudeSquared(dist) < m_Sphere.GetRadius() * m_Sphere.GetRadius())
    {
        // 已经与该顶点相交。
        this->SetContactTime(Math::GetValue(0));
        return false;
    }

    // 三角形静止不动，球运动。
    auto relVelocity = velocity1 - velocity0;

    if (Vector3DTools::DotProduct(relVelocity, dist) <= Math::GetValue(0))
    {
        return false;
    }

    // 找到速度射线与侧面法线的交点。

    // 将射线和平面投影到法线平面上。
    auto plane = Vector3DTools::DotProduct(sideNorm, vertexs[index]);
    auto center = Vector3DTools::DotProduct(sideNorm, m_Sphere.GetCenter());
    auto velocity = Vector3DTools::DotProduct(sideNorm, relVelocity);
    auto factor = (plane - center) / velocity;
    auto point = m_Sphere.GetCenter() + factor * relVelocity;

    // 通过将顶点和新点都投影到三角形边缘（使用其“法线”找到该点的同一边缘）上，来找到顶点位于哪一侧。
    auto vertexDot = Vector3DTools::DotProduct(side, vertexs[index]);
    auto pointDot = Vector3DTools::DotProduct(side, point);
    const Vector3D end0 = vertexs[index];
    Vector3D end1{};
    if (vertexDot <= pointDot)
    {
        // 与边的交点 (vertex,vertex+1).
        end1 = vertexs[(index + 1) % 3];
    }
    else
    {
        // 与边的交点 (vertex-1,vertex).
        if (index != 0)
        {
            const auto nextIndex = index - 1;
            end1 = vertexs.at(nextIndex);
        }
        else
        {
            end1 = vertexs[2];
        }
    }
    const Segment3<Real> seg{ end0, end1 };

    // 这可能是球体边缘或球体与顶点的交点（此测试不足以区分），因此请使用完全在线球体测试。
    DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, m_Sphere, tmax, velocity0, velocity1 };
    if (calc.IsIntersection())
    {
        this->SetContactTime(calc.GetContactTime());
        m_Point = calc.GetPoint(0);
        this->SetIntersectionType(IntersectionType::Empty);
        return true;
    }

    return false;

#include STSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::FindSphereVertexIntersection(const Vector3D& vertex, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1)
{
    /// 查找rkOrigin处rkDir处的fRadius球面朝顶点处的顶点移动的交点的时间和地点
    /// （以及可能错过的可能发生的情况）。
    auto relVelocity = velocity1 - velocity0;
    auto minus = m_Sphere.GetCenter() - vertex;
    const auto cross = Vector3DTools::CrossProduct(minus, relVelocity);
    auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto velocitySqr = Vector3DTools::VectorMagnitudeSquared(relVelocity);

    if (radiusSqr * velocitySqr < Vector3DTools::VectorMagnitudeSquared(cross))
    {
        // 射线越过球体。
        return false;
    }

    // 找到相交的时间。
    auto dot = Vector3DTools::DotProduct(minus, relVelocity);
    auto diff = Vector3DTools::VectorMagnitudeSquared(minus) - radiusSqr;
    auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));

    auto contactTime = diff * inv / (Math::GetValue(1) - dot * inv);
    this->SetContactTime(contactTime);
    if (tmax < contactTime)
    {
        // 相交发生在最大时间之后。
        return false;
    }

    // 相交是一个三角形顶点。
    m_Point = vertex + contactTime * velocity0;
    return true;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_ACHIEVE_H