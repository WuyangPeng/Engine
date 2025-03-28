///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:14)

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

    // ��ȡ�����ζ��㡣
    auto vertices = triangle.GetVertex();

    using EdgesType = std::array<Vector3, 3>;

    // ��ȡ�����εı�Ե��
    EdgesType edges{ vertices.at(1) - vertices.at(0), vertices.at(2) - vertices.at(1), vertices.at(0) - vertices.at(2) };

    // �õ������η��ߡ�
    auto normal = Vector3ToolsType::CrossProduct(edges.at(1), edges.at(0));

    // ��������ͶӰ�������η����ϡ�
    auto normalDotCenter = Vector3ToolsType::DotProduct(normal, sphere.GetCenter());

    // �뾶�ڷ��߷����ϵ�ͶӰ���ȡ� ֱ��������Ҫʱ�����ʹƽ������һ�����ߡ�
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto normRadiusSqr = Vector3ToolsType::GetLengthSquared(normal) * radiusSqr;

    // �����η����ϵ�������ͶӰ��
    auto normalDotTriangle = Vector3ToolsType::DotProduct(normal, vertices.at(0));

    // ���嵽�������ط��ߵľ��롣
    auto distance = normalDotCenter - normalDotTriangle;

    // �ɱ�i�������η����γɵ�ƽ��ķ��ߡ�
    EdgesType edgesCrossNormal{ Vector3ToolsType::CrossProduct(edges.at(0), normal),
                                Vector3ToolsType::CrossProduct(edges.at(1), normal),
                                Vector3ToolsType::CrossProduct(edges.at(2), normal) };

    using InsideType = std::array<bool, 3>;

    if (distance * distance <= normRadiusSqr)
    {
        // ���嵱ǰ�������ε�ƽ���ཻ��

        // �鿴�����������ڲ�/�ⲿ�ı�Ե��

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
                    // �����ڵ������Ρ�
                    this->SetContactTime(MathType::GetValue(0));
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
                else  // !inside[2]
                {
                    // ���<V2,V0>�����ཻ��
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
                    // ���<V1,V2>�����ཻ��
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
                    // ��ԵΪ <V1,V2>, <V2,V0>�Ŀ����ཻ��
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
                    // ���<V0,V1>�����ཻ��
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
                    // ��ԵΪ <V2,V0>, <V0,V1>�Ŀ����ཻ��
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
                    // ��ԵΪ <V0,V1>, <V1,V2>�Ŀ����ཻ��
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
                    // ���ǲ�Ӧ�õ����
                    MATHEMATICS_ASSERTION_0(false, "����״��\n");
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
            }
        }
    }
    else
    {
        // ���嵱ǰ���������ε�ƽ���ཻ��

        // �����ƶ��������ι̶���
        const Vector3 relVelocity = rhsVelocity - lhsVelocity;

        // ���������������ƽ��Ľ��㡣 ������������ε�ƽ���Ϸ����˵��λ��ȷ���˿��ܵ��ཻ���͡�
        normal.Normalize();

        // ���ϵĵ����ǹ�����������ƽ���ཻ��
        Vector3 spherePoint{};

        // �����������ε���һ�ࣿ
        if (normalDotTriangle < normalDotCenter)
        {
            // ����
            if (MathType::GetValue(0) <= Vector3ToolsType::DotProduct(relVelocity, normal))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = sphere.GetCenter() - sphere.GetRadius() * normal;
        }
        else
        {
            // ����
            if (Vector3ToolsType::DotProduct(relVelocity, normal) <= MathType::GetValue(0))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = sphere.GetCenter() + sphere.GetRadius() * normal;
        }

        // �ҵ��ٶ�������������ƽ��Ľ��㡣

        // �����ߺ�ƽ��ͶӰ������ƽ���ϡ�
        auto plane = Vector3ToolsType::DotProduct(normal, vertices.at(0));
        auto dotProduct = Vector3ToolsType::DotProduct(normal, spherePoint);
        auto velocity = Vector3ToolsType::DotProduct(normal, relVelocity);
        auto time = (plane - dotProduct) / velocity;

        // ���ཻ�ĵط���
        auto intrPoint = spherePoint + time * relVelocity;

        // �鿴���ཻ������Щ�ߵ��ڲ�/�ⲿ��
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
                    // ��ʱ�����ཻ��
                    if (tMax < time)
                    {
                        // tMax֮��Ľ��㡣
                        this->SetIntersectionType(IntersectionType::Empty);
                        return;
                    }
                    else
                    {
                        // intrPoint�ǿռ��еĵ㣬�ٶ�TriVelΪ0��������ǣ��������µ�����Ӧ�õ�λ�á�
                        this->SetContactTime(time);
                        point = intrPoint + time * lhsVelocity;
                        this->SetIntersectionType(IntersectionType::Empty);
                        return;
                    }
                }
                else  // !inside[2]
                {
                    // ���<V2,V0>�Ŀ����ཻ��
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
                    // ���<V1,V2>�Ŀ����ཻ��
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
                    // �붥��V2��Ǳ�ڽ��㡣
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
                    // ���<V0,V1>�Ŀ����ཻ��
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
                    // �붥��V0��Ǳ�ڽ��㡣
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
                    // �붥��V1��Ǳ�ڽ��㡣
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
                    // ���ǲ�Ӧ�õ����
                    MATHEMATICS_ASSERTION_0(false, "����״��\n");
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
    // ��������������ཻ������Ǳ�ڱ������ӵġ��ؼ������㣬������Ϊvertex��
    // sideNorm���ɣ�vertex��vertex + 1����tri norm�γɵ�ƽ��ķ��ߣ�Ϊ�˱������¼����ͨ��

    // ��ʱ��0��齻��㡣
    auto dist = vertexs.at(index) - sphere.GetCenter();
    if (Vector3ToolsType::GetLengthSquared(dist) < sphere.GetRadius() * sphere.GetRadius())
    {
        // �Ѿ���ö����ཻ��
        this->SetContactTime(MathType::GetValue(0));
        return false;
    }

    // �����ξ�ֹ���������˶���
    auto relVelocity = velocity1 - velocity0;

    if (Vector3ToolsType::DotProduct(relVelocity, dist) <= MathType::GetValue(0))
    {
        return false;
    }

    // �ҵ��ٶ���������淨�ߵĽ��㡣

    // �����ߺ�ƽ��ͶӰ������ƽ���ϡ�
    auto plane = Vector3ToolsType::DotProduct(sideNorm, vertexs.at(index));
    auto center = Vector3ToolsType::DotProduct(sideNorm, sphere.GetCenter());
    auto velocity = Vector3ToolsType::DotProduct(sideNorm, relVelocity);
    auto factor = (plane - center) / velocity;
    auto spherePoint = sphere.GetCenter() + factor * relVelocity;

    // ͨ����������µ㶼ͶӰ�������α�Ե��ʹ���䡰���ߡ��ҵ��õ��ͬһ��Ե���ϣ����ҵ�����λ����һ�ࡣ
    auto vertexDot = Vector3ToolsType::DotProduct(side, vertexs.at(index));
    auto pointDot = Vector3ToolsType::DotProduct(side, spherePoint);
    const Vector3 end0 = vertexs.at(index);
    Vector3 end1{};
    if (vertexDot <= pointDot)
    {
        // ��ߵĽ��� (vertex,vertex+1).
        end1 = vertexs.at((index + 1) % 3);
    }
    else
    {
        // ��ߵĽ��� (vertex-1,vertex).
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

    // ������������Ե�������붥��Ľ��㣨�˲��Բ��������֣��������ʹ����ȫ����������ԡ�
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
    /// ����rkOrigin��rkDir����fRadius���泯���㴦�Ķ����ƶ��Ľ����ʱ��͵ص�
    /// ���Լ����ܴ���Ŀ��ܷ������������
    auto relVelocity = velocity1 - velocity0;
    auto minus = sphere.GetCenter() - vertex;
    const auto cross = Vector3ToolsType::CrossProduct(minus, relVelocity);
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto velocitySqr = Vector3ToolsType::GetLengthSquared(relVelocity);

    if (radiusSqr * velocitySqr < Vector3ToolsType::GetLengthSquared(cross))
    {
        // ����Խ�����塣
        return false;
    }

    // �ҵ��ཻ��ʱ�䡣
    auto dot = Vector3ToolsType::DotProduct(minus, relVelocity);
    auto diff = Vector3ToolsType::GetLengthSquared(minus) - radiusSqr;
    auto inv = MathType::InvSqrt(MathType::FAbs(dot * dot - velocitySqr * diff));

    auto contactTime = diff * inv / (MathType::GetValue(1) - dot * inv);
    this->SetContactTime(contactTime);
    if (tmax < contactTime)
    {
        // �ཻ���������ʱ��֮��
        return false;
    }

    // �ཻ��һ�������ζ��㡣
    point = vertex + contactTime * velocity0;

    return true;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_DETAIL_H