///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/07 16:14)

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

    // ��ȡ�����ζ��㡣
    auto vertices = m_Triangle.GetVertex();

    using EdgesType = std::array<Vector3D, 3>;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // ��ȡ�����εı�Ե��
    EdgesType edges{ vertices[1] - vertices[0], vertices[2] - vertices[1], vertices[0] - vertices[2] };

    // �õ������η��ߡ�
    auto normal = Vector3DTools::CrossProduct(edges[1], edges[0]);

    // ��������ͶӰ�������η����ϡ�
    auto normalDotCenter = Vector3DTools::DotProduct(normal, m_Sphere.GetCenter());

    // �뾶�ڷ��߷����ϵ�ͶӰ���ȡ� ֱ��������Ҫʱ�����ʹƽ������һ�����ߡ�
    auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto normRadiusSqr = Vector3DTools::VectorMagnitudeSquared(normal) * radiusSqr;

    // �����η����ϵ�������ͶӰ��
    auto normalDotTriangle = Vector3DTools::DotProduct(normal, vertices[0]);

    // ���嵽�������ط��ߵľ��롣
    auto distance = normalDotCenter - normalDotTriangle;

    // �ɱ�i�������η����γɵ�ƽ��ķ��ߡ�
    EdgesType edgesCrossNormal{ Vector3DTools::CrossProduct(edges[0], normal),
                                Vector3DTools::CrossProduct(edges[1], normal),
                                Vector3DTools::CrossProduct(edges[2], normal) };

    using InsideType = std::array<bool, 3>;

    if (distance * distance <= normRadiusSqr)
    {
        // ���嵱ǰ�������ε�ƽ���ཻ��

        // �鿴�����������ڲ�/�ⲿ�ı�Ե��

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
                    // �����ڵ������Ρ�
                    this->SetContactTime(Math::GetValue(0));
                    this->SetIntersectionType(IntersectionType::Empty);
                    return;
                }
                else  // !inside[2]
                {
                    // ���<V2,V0>�����ཻ��
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
                    // ���<V1,V2>�����ཻ��
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
                    // ��ԵΪ <V1,V2>, <V2,V0>�Ŀ����ཻ��
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
                    // ���<V0,V1>�����ཻ��
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
                    // ��ԵΪ <V2,V0>, <V0,V1>�Ŀ����ཻ��
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
                    // ��ԵΪ <V0,V1>, <V1,V2>�Ŀ����ཻ��
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
        const Vector3D relVelocity = rhsVelocity - lhsVelocity;

        // ���������������ƽ��Ľ��㡣 ������������ε�ƽ���Ϸ����˵��λ��ȷ���˿��ܵ��ཻ���͡�
        normal.Normalize();

        // ���ϵĵ����ǹ�����������ƽ���ཻ��
        Vector3D spherePoint{};

        // �����������ε���һ�ࣿ
        if (normalDotTriangle < normalDotCenter)
        {
            // ����
            if (Math::GetValue(0) <= Vector3DTools::DotProduct(relVelocity, normal))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = m_Sphere.GetCenter() - m_Sphere.GetRadius() * normal;
        }
        else
        {
            // ����
            if (Vector3DTools::DotProduct(relVelocity, normal) <= Math::GetValue(0))
            {
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }

            spherePoint = m_Sphere.GetCenter() + m_Sphere.GetRadius() * normal;
        }

        // �ҵ��ٶ�������������ƽ��Ľ��㡣

        // �����ߺ�ƽ��ͶӰ������ƽ���ϡ�
        auto plane = Vector3DTools::DotProduct(normal, vertices[0]);
        auto point = Vector3DTools::DotProduct(normal, spherePoint);
        auto velocity = Vector3DTools::DotProduct(normal, relVelocity);
        auto time = (plane - point) / velocity;

        // ���ཻ�ĵط���
        auto intrPoint = spherePoint + time * relVelocity;

        // �鿴���ཻ������Щ�ߵ��ڲ�/�ⲿ��
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
                        m_Point = intrPoint + time * lhsVelocity;
                        this->SetIntersectionType(IntersectionType::Empty);
                        return;
                    }
                }
                else  // !inside[2]
                {
                    // ���<V2,V0>�Ŀ����ཻ��
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
                    // ���<V1,V2>�Ŀ����ཻ��
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
                    // �붥��V2��Ǳ�ڽ��㡣
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
                    // ���<V0,V1>�Ŀ����ཻ��
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
                    // �붥��V0��Ǳ�ڽ��㡣
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
                    // �붥��V1��Ǳ�ڽ��㡣
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
                    // ���ǲ�Ӧ�õ����
                    MATHEMATICS_ASSERTION_0(false, "����״��\n");
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

    // ��������������ཻ������Ǳ�ڱ������ӵġ��ؼ������㣬������Ϊvertex��
    // sideNorm���ɣ�vertex��vertex + 1����tri norm�γɵ�ƽ��ķ��ߣ�Ϊ�˱������¼����ͨ��

    // ��ʱ��0��齻��㡣
    auto dist = vertexs[index] - m_Sphere.GetCenter();
    if (Vector3DTools::VectorMagnitudeSquared(dist) < m_Sphere.GetRadius() * m_Sphere.GetRadius())
    {
        // �Ѿ���ö����ཻ��
        this->SetContactTime(Math::GetValue(0));
        return false;
    }

    // �����ξ�ֹ���������˶���
    auto relVelocity = velocity1 - velocity0;

    if (Vector3DTools::DotProduct(relVelocity, dist) <= Math::GetValue(0))
    {
        return false;
    }

    // �ҵ��ٶ���������淨�ߵĽ��㡣

    // �����ߺ�ƽ��ͶӰ������ƽ���ϡ�
    auto plane = Vector3DTools::DotProduct(sideNorm, vertexs[index]);
    auto center = Vector3DTools::DotProduct(sideNorm, m_Sphere.GetCenter());
    auto velocity = Vector3DTools::DotProduct(sideNorm, relVelocity);
    auto factor = (plane - center) / velocity;
    auto point = m_Sphere.GetCenter() + factor * relVelocity;

    // ͨ����������µ㶼ͶӰ�������α�Ե��ʹ���䡰���ߡ��ҵ��õ��ͬһ��Ե���ϣ����ҵ�����λ����һ�ࡣ
    auto vertexDot = Vector3DTools::DotProduct(side, vertexs[index]);
    auto pointDot = Vector3DTools::DotProduct(side, point);
    const Vector3D end0 = vertexs[index];
    Vector3D end1{};
    if (vertexDot <= pointDot)
    {
        // ��ߵĽ��� (vertex,vertex+1).
        end1 = vertexs[(index + 1) % 3];
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
            end1 = vertexs[2];
        }
    }
    const Segment3<Real> seg{ end0, end1 };

    // ������������Ե�������붥��Ľ��㣨�˲��Բ��������֣��������ʹ����ȫ����������ԡ�
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
    /// ����rkOrigin��rkDir����fRadius���泯���㴦�Ķ����ƶ��Ľ����ʱ��͵ص�
    /// ���Լ����ܴ���Ŀ��ܷ������������
    auto relVelocity = velocity1 - velocity0;
    auto minus = m_Sphere.GetCenter() - vertex;
    const auto cross = Vector3DTools::CrossProduct(minus, relVelocity);
    auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
    auto velocitySqr = Vector3DTools::VectorMagnitudeSquared(relVelocity);

    if (radiusSqr * velocitySqr < Vector3DTools::VectorMagnitudeSquared(cross))
    {
        // ����Խ�����塣
        return false;
    }

    // �ҵ��ཻ��ʱ�䡣
    auto dot = Vector3DTools::DotProduct(minus, relVelocity);
    auto diff = Vector3DTools::VectorMagnitudeSquared(minus) - radiusSqr;
    auto inv = Math::InvSqrt(Math::FAbs(dot * dot - velocitySqr * diff));

    auto contactTime = diff * inv / (Math::GetValue(1) - dot * inv);
    this->SetContactTime(contactTime);
    if (tmax < contactTime)
    {
        // �ཻ���������ʱ��֮��
        return false;
    }

    // �ཻ��һ�������ζ��㡣
    m_Point = vertex + contactTime * velocity0;
    return true;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_ACHIEVE_H