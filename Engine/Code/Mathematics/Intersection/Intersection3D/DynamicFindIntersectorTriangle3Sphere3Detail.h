///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:14)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorTriangle3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection3D/DynamicFindIntersectorSegment3Sphere3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, Real tMax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, triangle{ triangle }, sphere{ sphere }, point{}
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
Mathematics::Triangle3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::Find()
{
    auto tMax = this->GetTMax();
    const auto lhsVelocity = this->GetLhsVelocity();
    const auto rhsVelocity = this->GetRhsVelocity();

    // 获取三角形顶点。
    auto vertices = triangle.GetVertex();

    using EdgesType = std::array<Vector3, 3>;

    // 获取三角形的边缘。
    EdgesType edges{ vertices.at(1) - vertices.at(0), vertices.at(2) - vertices.at(1), vertices.at(0) - vertices.at(2) };

    // 得到三角形法线。
    auto normal = Vector3ToolsType::CrossProduct(edges.at(1), edges.at(0));

    // 球体中心投影在三角形法线上。
    auto normalDotCenter = Vector3ToolsType::DotProduct(normal, sphere.GetCenter());

    // 半径在法线方向上的投影长度。 直到绝对需要时，这才使平方根归一化法线。
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto normRadiusSqr = Vector3ToolsType::GetLengthSquared(normal) * radiusSqr;

    // 三角形法线上的三角形投影。
    auto normalDotTriangle = Vector3ToolsType::DotProduct(normal, vertices.at(0));

    // 球体到三角形沿法线的距离。
    auto distance = normalDotCenter - normalDotTriangle;

    // 由边i和三角形法线形成的平面的法线。
    EdgesType edgesCrossNormal{ Vector3ToolsType::CrossProduct(edges.at(0), normal),
                                Vector3ToolsType::CrossProduct(edges.at(1), normal),
                                Vector3ToolsType::CrossProduct(edges.at(2), normal) };

    using InsideType = std::array<bool, 3>;

    if (distance * distance <= normRadiusSqr)
    {
        // 球体当前与三角形的平面相交。

        // 查看球体中心在内部/外部的边缘。

        InsideType inside{};
        for (auto i = 0u; i < inside.size(); ++i)
        {
            inside.at(i) = Vector3ToolsType::DotProduct(edgesCrossNormal.at(i), vertices.at(i)) <= Vector3ToolsType::DotProduct(edgesCrossNormal.at(i), sphere.GetCenter());
        }

        if (inside.at(0))
        {
            if (inside.at(1))
            {
                if (inside.at(2))
                {
                    // 球体内的三角形。
                    this->SetContactTime(MathType::GetValue(0));
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
                else  // !inside[2]
                {
                    // 与边<V2,V0>可能相交。
                    const Segment3<Real> segment{ vertices.at(2), vertices.at(0) };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        point = calc.GetPoint(0);
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
                if (inside.at(2))
                {
                    // 与边<V1,V2>可能相交。
                    const Segment3<Real> segment(vertices.at(1), vertices.at(2));
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        point = calc.GetPoint(0);
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
                    if (FindTriangleSphereCoplanarIntersection(2, vertices, edgesCrossNormal.at(2), edges.at(2), tMax, lhsVelocity, rhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(MathType::GetValue(0));
                    return;
                }
            }
        }
        else  // !inside[0]
        {
            if (inside.at(1))
            {
                if (inside.at(2))
                {
                    // 与边<V0,V1>可能相交。
                    const Segment3<Real> segment(vertices.at(0), vertices.at(1));
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        point = calc.GetPoint(0);
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
                    if (FindTriangleSphereCoplanarIntersection(0, vertices, edgesCrossNormal.at(0), edges.at(0), tMax, lhsVelocity, rhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(MathType::GetValue(0));
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside.at(2))
                {
                    // 边缘为 <V0,V1>, <V1,V2>的可能相交。
                    if (FindTriangleSphereCoplanarIntersection(1, vertices, edgesCrossNormal.at(1), edges.at(1), tMax, lhsVelocity, rhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(MathType::GetValue(0));
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
        const Vector3 relVelocity = rhsVelocity - lhsVelocity;

        // 查找球体和三角形平面的交点。 在相对于三角形的平面上发生此点的位置确定了可能的相交类型。
        normal.Normalize();

        // 球上的点我们关心与三角形平面相交。
        Vector3 spherePoint{};

        // 球面在三角形的哪一侧？
        if (normalDotTriangle < normalDotCenter)
        {
            // 正面
            if (MathType::GetValue(0) <= Vector3ToolsType::DotProduct(relVelocity, normal))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = sphere.GetCenter() - sphere.GetRadius() * normal;
        }
        else
        {
            // 负面
            if (Vector3ToolsType::DotProduct(relVelocity, normal) <= MathType::GetValue(0))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = sphere.GetCenter() + sphere.GetRadius() * normal;
        }

        // 找到速度射线与三角形平面的交点。

        // 将射线和平面投影到法线平面上。
        auto plane = Vector3ToolsType::DotProduct(normal, vertices.at(0));
        auto dotProduct = Vector3ToolsType::DotProduct(normal, spherePoint);
        auto velocity = Vector3ToolsType::DotProduct(normal, relVelocity);
        auto time = (plane - dotProduct) / velocity;

        // 这相交的地方。
        auto intrPoint = spherePoint + time * relVelocity;

        // 查看此相交点在哪些边的内部/外部。
        InsideType inside{};
        for (auto i = 0u; i < inside.size(); ++i)
        {
            inside.at(i) = Vector3ToolsType::DotProduct(edgesCrossNormal.at(i), vertices.at(i)) <= Vector3ToolsType::DotProduct(edgesCrossNormal.at(i), intrPoint);
        }

        if (inside.at(0))
        {
            if (inside.at(1))
            {
                if (inside.at(2))
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
                        point = intrPoint + time * lhsVelocity;
                        this->SetIntersectionType(IntersectionType::Empty);
                        return;
                    }
                }
                else  // !inside[2]
                {
                    // 与边<V2,V0>的可能相交。
                    const Segment3<Real> segment{ vertices.at(2), vertices.at(0) };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        point = calc.GetPoint(0);
                        this->SetIntersectionType(calc.GetIntersectionType());
                        return;
                    }
                    this->SetIntersectionType(calc.GetIntersectionType());
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside.at(2))
                {
                    // 与边<V1,V2>的可能相交。
                    const Segment3<Real> segment{ vertices.at(1), vertices.at(2) };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, sphere, tMax, lhsVelocity, rhsVelocity };
                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        point = calc.GetPoint(0);
                        this->SetIntersectionType(calc.GetIntersectionType());
                        return;
                    }
                    this->SetIntersectionType(calc.GetIntersectionType());
                    return;
                }
                else  // !inside[2]
                {
                    // 与顶点V2的潜在交点。
                    if (FindSphereVertexIntersection(vertices.at(2), tMax, rhsVelocity, lhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(MathType::GetValue(0));
                    return;
                }
            }
        }
        else  // !inside[0]
        {
            if (inside.at(1))
            {
                if (inside.at(2))
                {
                    // 与边<V0,V1>的可能相交。
                    const Segment3<Real> segment{ vertices.at(0), vertices.at(1) };
                    DynamicFindIntersectorSegment3Sphere3<Real> calc{ segment, sphere, tMax, lhsVelocity, rhsVelocity };

                    if (calc.IsIntersection())
                    {
                        this->SetContactTime(calc.GetContactTime());
                        point = calc.GetPoint(0);
                        this->SetIntersectionType(calc.GetIntersectionType());
                        return;
                    }
                    this->SetIntersectionType(calc.GetIntersectionType());
                    return;
                }
                else  // !inside[2]
                {
                    // 与顶点V0的潜在交点。
                    if (FindSphereVertexIntersection(vertices.at(0), tMax, rhsVelocity, lhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(MathType::GetValue(0));
                    return;
                }
            }
            else  // !inside[1]
            {
                if (inside.at(2))
                {
                    // 与顶点V1的潜在交点。
                    if (FindSphereVertexIntersection(vertices.at(1), tMax, rhsVelocity, lhsVelocity))
                    {
                        this->SetIntersectionType(IntersectionType::Point);
                    }
                    else
                    {
                        this->SetIntersectionType(IntersectionType::Empty);
                    }
                    this->SetContactTime(MathType::GetValue(0));
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
}

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::FindTriangleSphereCoplanarIntersection(int index, const VertexType& vertexs, const Vector3& sideNorm, const Vector3& side, Real tmax, const Vector3& velocity0, const Vector3& velocity1)
{
    // 顶点是球体可以相交的两个潜在边所连接的“关键”顶点，它索引为vertex。
    // sideNorm是由（vertex，vertex + 1）和tri norm形成的平面的法线，为了避免重新计算而通过

    // 在时间0检查交叉点。
    auto dist = vertexs.at(index) - sphere.GetCenter();
    if (Vector3ToolsType::GetLengthSquared(dist) < sphere.GetRadius() * sphere.GetRadius())
    {
        // 已经与该顶点相交。
        this->SetContactTime(MathType::GetValue(0));
        return false;
    }

    // 三角形静止不动，球运动。
    auto relVelocity = velocity1 - velocity0;

    if (Vector3ToolsType::DotProduct(relVelocity, dist) <= MathType::GetValue(0))
    {
        return false;
    }

    // 找到速度射线与侧面法线的交点。

    // 将射线和平面投影到法线平面上。
    auto plane = Vector3ToolsType::DotProduct(sideNorm, vertexs.at(index));
    auto center = Vector3ToolsType::DotProduct(sideNorm, sphere.GetCenter());
    auto velocity = Vector3ToolsType::DotProduct(sideNorm, relVelocity);
    auto factor = (plane - center) / velocity;
    auto spherePoint = sphere.GetCenter() + factor * relVelocity;

    // 通过将顶点和新点都投影到三角形边缘（使用其“法线”找到该点的同一边缘）上，来找到顶点位于哪一侧。
    auto vertexDot = Vector3ToolsType::DotProduct(side, vertexs.at(index));
    auto pointDot = Vector3ToolsType::DotProduct(side, spherePoint);
    const Vector3 end0 = vertexs.at(index);
    Vector3 end1{};
    if (vertexDot <= pointDot)
    {
        // 与边的交点 (vertex,vertex+1).
        end1 = vertexs.at((index + 1) % 3);
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
            end1 = vertexs.at(2);
        }
    }
    const Segment3<Real> seg{ end0, end1 };

    // 这可能是球体边缘或球体与顶点的交点（此测试不足以区分），因此请使用完全在线球体测试。
    DynamicFindIntersectorSegment3Sphere3<Real> calc{ seg, sphere, tmax, velocity0, velocity1 };
    if (calc.IsIntersection())
    {
        this->SetContactTime(calc.GetContactTime());
        point = calc.GetPoint(0);
        this->SetIntersectionType(IntersectionType::Empty);
        return true;
    }

    return false;
}

template <typename Real>
bool Mathematics::DynamicFindIntersectorTriangle3Sphere3<Real>::FindSphereVertexIntersection(const Vector3& vertex, Real tmax, const Vector3& velocity0, const Vector3& velocity1)
{
    /// 查找rkOrigin处rkDir处的fRadius球面朝顶点处的顶点移动的交点的时间和地点
    /// （以及可能错过的可能发生的情况）。
    auto relVelocity = velocity1 - velocity0;
    auto minus = sphere.GetCenter() - vertex;
    const auto cross = Vector3ToolsType::CrossProduct(minus, relVelocity);
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto velocitySqr = Vector3ToolsType::GetLengthSquared(relVelocity);

    if (radiusSqr * velocitySqr < Vector3ToolsType::GetLengthSquared(cross))
    {
        // 射线越过球体。
        return false;
    }

    // 找到相交的时间。
    auto dot = Vector3ToolsType::DotProduct(minus, relVelocity);
    auto diff = Vector3ToolsType::GetLengthSquared(minus) - radiusSqr;
    auto inv = MathType::InvSqrt(MathType::FAbs(dot * dot - velocitySqr * diff));

    auto contactTime = diff * inv / (MathType::GetValue(1) - dot * inv);
    this->SetContactTime(contactTime);
    if (tmax < contactTime)
    {
        // 相交发生在最大时间之后。
        return false;
    }

    // 相交是一个三角形顶点。
    point = vertex + contactTime * velocity0;

    return true;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H