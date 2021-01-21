///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/20 19:22)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_ACHIEVE_H

#include "StaticFindIntersectorRay3Triangle3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Triangle3<Real>::StaticFindIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, m_Ray{ ray }, m_Triangle{ triangle }, m_RayParameter{}, m_TriangleBary0{}, m_TriangleBary1{}, m_TriangleBary2{ Math::GetValue(1) }
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
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorRay3Triangle3<Real>::Find()
{
    // ����ƫ��ԭ�㣬�ߺͷ��ߡ�
    auto diff = m_Ray.GetOrigin() - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge2 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);
    const auto normal = Vector3DTools::CrossProduct(edge1, edge2);

    // ��� Q + t * D = b1 * E1 + b2 * E2��Q = kDiff��D = ���߷���
    // E1 = kEdge1, E2 = kEdge2, N = Cross(E1,E2))
    //   |Dot(D,N)| * b1 = sign(Dot(D,N)) * Dot(D,Cross(Q,E2))
    //   |Dot(D,N)| * b2 = sign(Dot(D,N)) * Dot(D,Cross(E1,Q))
    //   |Dot(D,N)| * t = -sign(Dot(D,N)) * Dot(Q,N)
    auto directionDotNormal = Vector3DTools::DotProduct(m_Ray.GetDirection(), normal);
    auto sign = Math::GetValue(0);
    if (Math::GetZeroTolerance() < directionDotNormal)
    {
        sign = Math::GetValue(1);
    }
    else if (directionDotNormal < -Math::GetZeroTolerance())
    {
        sign = Math::GetValue(-1);
        directionDotNormal = -directionDotNormal;
    }
    else
    {
        // ���ߺ���������ƽ�еģ���ʹ�����ཻҲ����Ϊ���޽�������
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto value0 = sign * Vector3DTools::DotProduct(m_Ray.GetDirection(), Vector3DTools::CrossProduct(diff, edge2));
    if (Math::GetValue(0) <= value0)
    {
        auto value1 = sign * Vector3DTools::DotProduct(m_Ray.GetDirection(), Vector3DTools::CrossProduct(edge1, diff));
        if (Math::GetValue(0) <= value1)
        {
            if (value0 + value1 <= directionDotNormal)
            {
                // �����������ཻ����������Ƿ��ཻ��
                auto value2 = -sign * Vector3DTools::DotProduct(diff, normal);
                if (Math::GetValue(0) <= value2)
                {
                    // �������������ཻ��
                    auto inv = (Math::GetValue(1)) / directionDotNormal;
                    m_RayParameter = value2 * inv;
                    m_TriangleBary1 = value0 * inv;
                    m_TriangleBary2 = value1 * inv;
                    m_TriangleBary0 = Math::GetValue(1) - m_TriangleBary1 - m_TriangleBary2;
                    this->SetIntersectionType(IntersectionType::Point);
                    return;
                }
                // else: t < 0, û�н���
            }
            // else: b1+b2 > 1, û�н���
        }
        // else: b2 < 0,  û�н���
    }
    // else: b1 < 0, û�н���

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetRayParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RayParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangleBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangleBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Triangle3<Real>::GetTriangleBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary2;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_ACHIEVE_H