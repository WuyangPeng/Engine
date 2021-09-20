///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/08 17:11)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H

#include "StaticFindIntersectorTriangle3Triangle3.h"
#include "Detail/FindIntersectorTriangle3Triangle3ImplDetail.h"
#include "Detail/TrianglePlaneRelationsDetail.h"
#include "Detail/TriangleProjectOntoAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorSegment2Triangle2Detail.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorTriangle2Triangle2Detail.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include "Mathematics/Objects2D/Triangle2Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Mathematics/Query/Query2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::StaticFindIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle, bool reportCoplanarIntersections, const Real epsilon)
    : ParentType{ epsilon }, impl{ lhsTriangle, rhsTriangle  }, m_ReportCoplanarIntersections{ reportCoplanarIntersections }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Find()
{
    const auto lhsTriangle = impl->GetTriangle0();
    const auto rhsTriangle = impl->GetTriangle1();

    // ��ȡm_LhsTriangle��ƽ��
    const Plane3 lhsPlane0{ lhsTriangle };

    // ����������m_RhsTriangle���㵽ƽ��lhsPlane0���з��ž��롣ʹ��epsilon-thick���ԡ�
    const TrianglePlaneRelations<Real> rhsTrianglePlaneRelations{ rhsTriangle, lhsPlane0, this->GetEpsilon() };

    if (rhsTrianglePlaneRelations.GetPositive() == 3 || rhsTrianglePlaneRelations.GetNegative() == 3)
    {
        // ������m_RhsTriangle��ȫ��ƽ��lhsPlane��һ�ࡣ
        return;
    }

    if (rhsTrianglePlaneRelations.GetZero() == 3)
    {
        // ������m_RhsTriangle��ƽ��lhsPlane������
        if (m_ReportCoplanarIntersections)
        {
            GetCoplanarIntersection(lhsPlane0, lhsTriangle, rhsTriangle);
            return;
        }
        return;
    }

    // ���������m_RhsTriangle��ƽ��lhsPlane֮��ĽӴ���
    if (rhsTrianglePlaneRelations.GetPositive() == 0 || rhsTrianglePlaneRelations.GetNegative() == 0)
    {
        if (rhsTrianglePlaneRelations.GetZero() == 2)
        {
            // ������m_RhsTriangle�ı���ƽ��lhsPlane�С�
            for (auto i = 0; i < 3; ++i)
            {
                if (rhsTrianglePlaneRelations.GetSign(i) != NumericalValueSymbol::Zero)
                {
                    const auto index0 = (i + 2) % 3;
                    const auto index1 = (i + 1) % 3;
                    IntersectsSegment(lhsPlane0, lhsTriangle, rhsTriangle.GetVertex(index0), rhsTriangle.GetVertex(index1));
                    return;
                }
            }
        }
        else
        {
            MATHEMATICS_ASSERTION_2(rhsTrianglePlaneRelations.GetZero() == 1, "�����κ�ƽ��Ӵ��������");

            // ������m_RhsTriangle�Ķ�����ƽ��lhsPlane�С�
            for (auto i = 0; i < 3; ++i)
            {
                if (rhsTrianglePlaneRelations.GetSign(i) == NumericalValueSymbol::Zero)
                {
                    ContainsPoint(lhsTriangle, lhsPlane0, rhsTriangle.GetVertex(i));
                    return;
                }
            }
        }
    }

    // ��ʱ��������m_RhsTriangle������ƽ��lhsPlane�ཻ�����㽻����߶Ρ�
    // Ȼ���������߶κ�������m_LhsTriangle֮��Ľ�����
    if (rhsTrianglePlaneRelations.GetZero() == 0)
    {
        const auto sign = (rhsTrianglePlaneRelations.GetPositive() == 1 ? NumericalValueSymbol::Positive : NumericalValueSymbol::Negative);
        for (auto i = 0; i < 3; ++i)
        {
            if (rhsTrianglePlaneRelations.GetSign(i) == sign)
            {
                const int index0 = (i + 2) % 3;
                const int index1 = (i + 1) % 3;
                auto t = rhsTrianglePlaneRelations.GetDistance(i) / (rhsTrianglePlaneRelations.GetDistance(i) - rhsTrianglePlaneRelations.GetDistance(index0));
                auto triangle0 = rhsTriangle.GetVertex(i) + t * (rhsTriangle.GetVertex(index0) - rhsTriangle.GetVertex(i));
                t = rhsTrianglePlaneRelations.GetDistance(i) / (rhsTrianglePlaneRelations.GetDistance(i) - rhsTrianglePlaneRelations.GetDistance(index1));
                auto triangle1 = rhsTriangle.GetVertex(i) + t * (rhsTriangle.GetVertex(index1) - rhsTriangle.GetVertex(i));
                IntersectsSegment(lhsPlane0, lhsTriangle, triangle0, triangle1);
                return;
            }
        }
    }

    // zero1 == 1
    for (auto i = 0; i < 3; ++i)
    {
        if (rhsTrianglePlaneRelations.GetSign(i) == NumericalValueSymbol::Zero)
        {
            const auto index0 = (i + 2) % 3;
            const auto index1 = (i + 1) % 3;
            auto t = rhsTrianglePlaneRelations.GetDistance(index0) / (rhsTrianglePlaneRelations.GetDistance(index0) - rhsTrianglePlaneRelations.GetDistance(index1));
            auto triangle0 = rhsTriangle.GetVertex(index0) + t * (rhsTriangle.GetVertex(index1) - rhsTriangle.GetVertex(index0));
            IntersectsSegment(lhsPlane0, lhsTriangle, rhsTriangle.GetVertex(i), triangle0);
            return;
        }
    }

    MATHEMATICS_ASSERTION_2(false, "�߼���Ӧ��ִ�е����\n");
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid()  )
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetLhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTriangle0();
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetRhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTriangle1();
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetPoint(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3D& point)
{
    /// ����ƽ�������ϵ�� ���������εĶ���Ϊ<V0,V1,V2>��
    /// ����ƽ��ĵ�λ���ȷ���ΪN�������ΪP��ѡ��V0��Ϊƽ���ԭ�㡣 �����᷽����������λ��������U0��U1��
    /// ����Ϊ{ U0��U1��N } ��һ���������� ƽ���е��κε�Q����дΪQ = V0 + x0 * U0 + x1 * U1��
    ///  �������Ϊx0 = Dot(U0,Q - V0)��x1 = Dot(U1,Q - V0)��

    const auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(plane.GetNormal());
    const auto uVector = vector3DOrthonormalBasis.GetUVector();
    const auto vVector = vector3DOrthonormalBasis.GetVVector();

    /// �����P��V1��V2��ƽ�����ꡣ Ϊ�����������Щ���м�ȥԭ�㣬����������£�ƽ������������P - V0��V1 - V0��V2 - V0��
    auto pointMinusVertex0 = point - triangle.GetVertex(0);
    auto vertex1MinusVertex0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto vertex2MinusVertex0 = triangle.GetVertex(2) - triangle.GetVertex(0);

    // P - V0��ƽ���ʾ��.
    const Vector2D<Real> planar{ Vector3DTools::DotProduct(uVector, pointMinusVertex0), Vector3DTools::DotProduct(vVector, pointMinusVertex0) };

    using Triangle2D = std::vector<Vector2D<Real>>;

    /// ������<V0-V0,V1-V0,V2-V0>��ƽ���ʾ��
    Triangle2D triangleVector{ Vector2D<Real>::GetZero(),
                               Vector2D<Real>{ Vector3DTools::DotProduct(uVector, vertex1MinusVertex0), Vector3DTools::DotProduct(vVector, vertex1MinusVertex0) },
                               Vector2D<Real>{ Vector3DTools::DotProduct(uVector, vertex2MinusVertex0), Vector3DTools::DotProduct(vVector, vertex2MinusVertex0) } };

    /// ����P-V0�Ƿ���������<0,V1-V0,V2-V0>�С�
    if (Query2<Real>{ triangleVector }.ToTriangle(planar, 0, 1, 2) != TriangleQueryType::Outside)
    {
        // ������߱��潻��㡣
        this->SetIntersectionType(IntersectionType::Point);
        impl->AddPoint(point);
    }
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3D& end0, const Vector3D& end1)
{
    /// ���������ζ���Ķ�ά��ʾ�Լ������������ƽ����߶ζ˵㡣 Ȼ�����2D�ռ��еĽ��㡣

    /// ��������ͶӰ����ƽ�淨������������ƽ���ϡ�
    auto maxNormal = 0;
    auto x = Math::FAbs(plane.GetNormal().GetX());
    auto y = Math::FAbs(plane.GetNormal().GetY());
    if (x < y)
    {
        maxNormal = 1;
        x = y;
    }
    y = Math::FAbs(plane.GetNormal().GetZ());
    if (x < y)
    {
        maxNormal = 2;
    }

    Vector2D<Real> projectEnd0{};
    Vector2D<Real> projectEnd1{};

    using Triangle2D = std::array<Vector2D<Real>, 3>;

    Triangle2D projectTriangleVector{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    if (maxNormal == 0)
    {
        // ͶӰ��yzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangleVector[i].SetX(triangle.GetVertex(i).GetY());
            projectTriangleVector[i].SetY(triangle.GetVertex(i).GetZ());
            projectEnd0.SetX(end0.GetY());
            projectEnd0.SetY(end0.GetZ());
            projectEnd1.SetX(end1.GetY());
            projectEnd1.SetY(end1.GetZ());
        }
    }
    else if (maxNormal == 1)
    {
        // ͶӰ��xzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangleVector[i].SetX(triangle.GetVertex(i).GetX());
            projectTriangleVector[i].SetY(triangle.GetVertex(i).GetZ());
            projectEnd0.SetX(end0.GetX());
            projectEnd0.SetY(end0.GetZ());
            projectEnd1.SetX(end1.GetX());
            projectEnd1.SetY(end1.GetZ());
        }
    }
    else
    {
        // ͶӰ��xyƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangleVector[i].SetX(triangle.GetVertex(i).GetX());
            projectTriangleVector[i].SetY(triangle.GetVertex(i).GetY());
            projectEnd0.SetX(end0.GetX());
            projectEnd0.SetY(end0.GetY());
            projectEnd1.SetX(end1.GetX());
            projectEnd1.SetY(end1.GetY());
        }
    }

    Triangle2<Real> projectTriangle{ projectTriangleVector[0], projectTriangleVector[1], projectTriangleVector[2] };

    const Segment2<Real> projectSegment{ projectEnd0, projectEnd1 };
    StaticFindIntersectorSegment2Triangle2<Real> calc{ projectSegment, projectTriangle };
    if (!calc.IsIntersection())
    {
        return;
    }

    const auto quantity = calc.GetQuantity();

    Triangle2D intersector;
    if (calc.GetIntersectionType() == IntersectionType::Segment)
    {
        this->SetIntersectionType(IntersectionType::Segment);

        intersector[0] = calc.GetPoint(0);
        intersector[1] = calc.GetPoint(1);
    }
    else
    {
        MATHEMATICS_ASSERTION_0(calc.GetIntersectionType() == IntersectionType::Point, "���������ǵ�\n");
        this->SetIntersectionType(IntersectionType::Point);

        intersector[0] = calc.GetPoint(0);
    }

    // ȡ��ͶӰ�ཻ�߶Ρ�
    if (maxNormal == 0)
    {
        Real invNormalX = (Math::GetValue(1)) / plane.GetNormal().GetX();
        for (auto i = 0; i < quantity; ++i)
        {
            Vector3D point{ Math::GetValue(0), intersector[i].GetX(), intersector[i].GetY() };

            point.SetX(invNormalX * (plane.GetConstant() - plane.GetNormal().GetY() * point.GetY() - plane.GetNormal().GetZ() * point.GetZ()));

            impl->AddPoint(point);
        }
    }
    else if (maxNormal == 1)
    {
        Real invNormalY = (Math::GetValue(1)) / plane.GetNormal().GetY();
        for (auto i = 0; i < quantity; ++i)
        {
            Vector3D point{ intersector[i].GetX(), intersector[i].GetY(), Math::GetValue(0) };

            point.SetZ(invNormalY * (plane.GetConstant() - plane.GetNormal().GetX() * point.GetX() - plane.GetNormal().GetZ() * point.GetZ()));

            impl->AddPoint(point);
        }
    }
    else
    {
        Real invNormalZ = (Math::GetValue(1)) / plane.GetNormal().GetZ();
        for (auto i = 0; i < quantity; ++i)
        {
            Vector3D point{ intersector[i].GetX(), intersector[i].GetY(), Math::GetValue(0) };

            point.SetZ(invNormalZ * (plane.GetConstant() - plane.GetNormal().GetX() * point.GetX() - plane.GetNormal().GetY() * point.GetY()));

            impl->AddPoint(point);
        }
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetCoplanarIntersection(const Plane3& plane, const Triangle3& triangle0, const Triangle3& triangle1)
{
    // ����ƽ�淨������������ƽ����ͶӰ�����Ρ�
    auto maxNormal = 0;
    auto x = Math::FAbs(plane.GetNormal().GetX());
    auto y = Math::FAbs(plane.GetNormal().GetY());
    if (x < y)
    {
        maxNormal = 1;
        x = y;
    }
    y = Math::FAbs(plane.GetNormal().GetZ());
    if (x < y)
    {
        maxNormal = 2;
    }

    using Triangle2D = std::array<Vector2D<Real>, 3>;

    Triangle2D projectTriangle0Vector{};
    Triangle2D projectTriangle1Vector{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    if (maxNormal == 0)
    {
        // ͶӰ��yzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector[i].SetCoordinate(triangle0.GetVertex(i).GetY(), triangle0.GetVertex(i).GetZ());
            projectTriangle1Vector[i].SetCoordinate(triangle1.GetVertex(i).GetY(), triangle1.GetVertex(i).GetZ());
        }
    }
    else if (maxNormal == 1)
    {
        // ͶӰ��xzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector[i].SetCoordinate(triangle0.GetVertex(i).GetX(), triangle0.GetVertex(i).GetZ());
            projectTriangle1Vector[i].SetCoordinate(triangle1.GetVertex(i).GetX(), triangle1.GetVertex(i).GetZ());
        }
    }
    else
    {
        // ͶӰ��xyƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector[i].SetCoordinate(triangle0.GetVertex(i).GetX(), triangle0.GetVertex(i).GetY());
            projectTriangle1Vector[i].SetCoordinate(triangle1.GetVertex(i).GetX(), triangle1.GetVertex(i).GetY());
        }
    }

    Triangle2<Real> projectTriangle0{ projectTriangle0Vector[0], projectTriangle0Vector[1], projectTriangle0Vector[2] };
    Triangle2<Real> projectTriangle1{ projectTriangle1Vector[0], projectTriangle1Vector[1], projectTriangle1Vector[2] };

    // 2D�������ཻ������Ҫ��ʱ������

    auto edge0 = projectTriangle0.GetVertex(1) - projectTriangle0.GetVertex(0);
    auto edge1 = projectTriangle0.GetVertex(2) - projectTriangle0.GetVertex(0);
    if (Vector2DTools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
    {
        // ��������˳ʱ�뷽������������
        projectTriangle0 = Triangle2<Real>{ projectTriangle0Vector[0], projectTriangle0Vector[2], projectTriangle0Vector[1] };
    }

    edge0 = projectTriangle1.GetVertex(1) - projectTriangle1.GetVertex(0);
    edge1 = projectTriangle1.GetVertex(2) - projectTriangle1.GetVertex(0);
    if (Vector2DTools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
    {
        // ��������˳ʱ�뷽������������
        projectTriangle1 = Triangle2<Real>{ projectTriangle1Vector[0], projectTriangle1Vector[2], projectTriangle1Vector[1] };
    }

    StaticFindIntersectorTriangle2Triangle2<Real> intr{ projectTriangle0, projectTriangle1 };
    if (!intr.IsIntersection())
    {
        return;
    }

    // ��2D����ӳ���3D�����οռ䡣
    const auto quantity = intr.GetQuantity();
    if (maxNormal == 0)
    {
        auto invNormalX = (Math::GetValue(1)) / plane.GetNormal().GetX();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3D point{ Math::GetValue(0), intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY() };
            point.SetX(invNormalX * (plane.GetConstant() - plane.GetNormal().GetY() * point.GetY() - plane.GetNormal().GetZ() * point.GetZ()));
            impl->AddPoint(point);
        }
    }
    else if (maxNormal == 1)
    {
        auto invNormalY = (Math::GetValue(1)) / plane.GetNormal().GetY();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3D point{ intr.GetPoint(i).GetX(), Math::GetValue(0), intr.GetPoint(i).GetY() };
            point.SetY(invNormalY * (plane.GetConstant() - plane.GetNormal().GetX() * point.GetX() - plane.GetNormal().GetZ() * point.GetZ()));
            impl->AddPoint(point);
        }
    }
    else
    {
        auto invNormalZ = (Math::GetValue(1)) / plane.GetNormal().GetZ();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3D point{ intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY(), Math::GetValue(0) };
            point.SetZ(invNormalZ * (plane.GetConstant() - plane.GetNormal().GetX() * point.GetX() - plane.GetNormal().GetY() * point.GetY()));
            impl->AddPoint(point);
        }
    }

    this->SetIntersectionType(IntersectionType::Plane);

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_ACHIEVE_H
