///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorTriangle3Triangle3.h"
#include "Detail/TrianglePlaneRelationsDetail.h"
#include "Detail/TriangleProjectOntoAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
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
    : ParentType{ epsilon }, triangle0{ lhsTriangle }, triangle1{ rhsTriangle }, reportCoplanarIntersections{ reportCoplanarIntersections }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Find()
{
    // ��ȡm_LhsTriangle��ƽ��
    const Plane3 lhsPlane0{ triangle0 };

    // ����������m_RhsTriangle���㵽ƽ��lhsPlane0���з��ž��롣ʹ��epsilon-thick���ԡ�
    const TrianglePlaneRelations<Real> rhsTrianglePlaneRelations{ triangle1, lhsPlane0, this->GetEpsilon() };

    if (rhsTrianglePlaneRelations.GetPositive() == 3 || rhsTrianglePlaneRelations.GetNegative() == 3)
    {
        // ������m_RhsTriangle��ȫ��ƽ��lhsPlane��һ�ࡣ
        return;
    }

    if (rhsTrianglePlaneRelations.GetZero() == 3)
    {
        // ������m_RhsTriangle��ƽ��lhsPlane������
        if (reportCoplanarIntersections)
        {
            GetCoplanarIntersection(lhsPlane0, triangle0, triangle1);
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
                    IntersectsSegment(lhsPlane0, triangle0, triangle1.GetVertex(index0), triangle1.GetVertex(index1));
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
                    ContainsPoint(triangle0, lhsPlane0, triangle1.GetVertex(i));
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
                auto end0 = triangle1.GetVertex(i) + t * (triangle1.GetVertex(index0) - triangle1.GetVertex(i));
                t = rhsTrianglePlaneRelations.GetDistance(i) / (rhsTrianglePlaneRelations.GetDistance(i) - rhsTrianglePlaneRelations.GetDistance(index1));
                auto end1 = triangle1.GetVertex(i) + t * (triangle1.GetVertex(index1) - triangle1.GetVertex(i));
                IntersectsSegment(lhsPlane0, triangle0, end0, end1);
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
            auto end0 = triangle1.GetVertex(index0) + t * (triangle1.GetVertex(index1) - triangle1.GetVertex(index0));
            IntersectsSegment(lhsPlane0, triangle0, triangle1.GetVertex(i), end0);
            return;
        }
    }

    MATHEMATICS_ASSERTION_2(false, "�߼���Ӧ��ִ�е����\n");
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetLhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetRhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3Type& vector3)
{
    /// ����ƽ�������ϵ�� ���������εĶ���Ϊ<V0,V1,V2>��
    /// ����ƽ��ĵ�λ���ȷ���ΪN�������ΪP��ѡ��V0��Ϊƽ���ԭ�㡣 �����᷽����������λ��������U0��U1��
    /// ����Ϊ{ U0��U1��N } ��һ���������� ƽ���е��κε�Q����дΪQ = V0 + x0 * U0 + x1 * U1��
    ///  �������Ϊx0 = Dot(U0,Q - V0)��x1 = Dot(U1,Q - V0)��

    const auto vector3OrthonormalBasis = Vector3ToolsType::GenerateComplementBasis(plane.GetNormal());
    const auto uVector = vector3OrthonormalBasis.GetUVector();
    const auto vVector = vector3OrthonormalBasis.GetVVector();

    /// �����P��V1��V2��ƽ�����ꡣ Ϊ�����������Щ���м�ȥԭ�㣬����������£�ƽ������������P - V0��V1 - V0��V2 - V0��
    auto pointMinusVertex0 = vector3 - triangle.GetVertex(0);
    auto vertex1MinusVertex0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto vertex2MinusVertex0 = triangle.GetVertex(2) - triangle.GetVertex(0);

    // P - V0��ƽ���ʾ��.
    const Vector2<Real> planar{ Vector3ToolsType::DotProduct(uVector, pointMinusVertex0), Vector3ToolsType::DotProduct(vVector, pointMinusVertex0) };

    using Triangle = std::vector<Vector2<Real>>;

    /// ������<V0-V0,V1-V0,V2-V0>��ƽ���ʾ��
    Triangle triangleVector{ Vector2<Real>::GetZero(),
                             Vector2<Real>{ Vector3ToolsType::DotProduct(uVector, vertex1MinusVertex0), Vector3ToolsType::DotProduct(vVector, vertex1MinusVertex0) },
                             Vector2<Real>{ Vector3ToolsType::DotProduct(uVector, vertex2MinusVertex0), Vector3ToolsType::DotProduct(vVector, vertex2MinusVertex0) } };

    /// ����P-V0�Ƿ���������<0,V1-V0,V2-V0>�С�
    if (Query2<Real>{ triangleVector }.ToTriangle(planar, 0, 1, 2) != TriangleQueryType::Outside)
    {
        // ������߱��潻��㡣
        this->SetIntersectionType(IntersectionType::Point);
        point.emplace_back(vector3);
    }
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3Type& end0, const Vector3Type& end1)
{
    /// ���������ζ���Ķ�ά��ʾ�Լ������������ƽ����߶ζ˵㡣 Ȼ�����2D�ռ��еĽ��㡣

    /// ��������ͶӰ����ƽ�淨������������ƽ���ϡ�
    auto maxNormal = 0;
    auto x = MathType::FAbs(plane.GetNormal().GetX());
    auto y = MathType::FAbs(plane.GetNormal().GetY());
    if (x < y)
    {
        maxNormal = 1;
        x = y;
    }
    y = MathType::FAbs(plane.GetNormal().GetZ());
    if (x < y)
    {
        maxNormal = 2;
    }

    Vector2<Real> projectEnd0{};
    Vector2<Real> projectEnd1{};

    using Triangle = std::array<Vector2<Real>, 3>;

    Triangle projectTriangleVector{};

    if (maxNormal == 0)
    {
        // ͶӰ��yzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangleVector.at(i).SetX(triangle.GetVertex(i).GetY());
            projectTriangleVector.at(i).SetY(triangle.GetVertex(i).GetZ());
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
            projectTriangleVector.at(i).SetX(triangle.GetVertex(i).GetX());
            projectTriangleVector.at(i).SetY(triangle.GetVertex(i).GetZ());
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
            projectTriangleVector.at(i).SetX(triangle.GetVertex(i).GetX());
            projectTriangleVector.at(i).SetY(triangle.GetVertex(i).GetY());
            projectEnd0.SetX(end0.GetX());
            projectEnd0.SetY(end0.GetY());
            projectEnd1.SetX(end1.GetX());
            projectEnd1.SetY(end1.GetY());
        }
    }

    const Triangle2<Real> projectTriangle{ projectTriangleVector.at(0), projectTriangleVector.at(1), projectTriangleVector.at(2) };

    const Segment2<Real> projectSegment{ projectEnd0, projectEnd1 };
    StaticFindIntersectorSegment2Triangle2<Real> calc{ projectSegment, projectTriangle };
    if (!calc.IsIntersection())
    {
        return;
    }

    const auto quantity = calc.GetQuantity();

    Triangle intersector{};
    if (calc.GetIntersectionType() == IntersectionType::Segment)
    {
        this->SetIntersectionType(IntersectionType::Segment);

        intersector.at(0) = calc.GetPoint(0);
        intersector.at(1) = calc.GetPoint(1);
    }
    else
    {
        MATHEMATICS_ASSERTION_0(calc.GetIntersectionType() == IntersectionType::Point, "���������ǵ�\n");
        this->SetIntersectionType(IntersectionType::Point);

        intersector.at(0) = calc.GetPoint(0);
    }

    // ȡ��ͶӰ�ཻ�߶Ρ�
    if (maxNormal == 0)
    {
        Real invNormalX = (MathType::GetValue(1)) / plane.GetNormal().GetX();
        for (auto i = 0; i < quantity; ++i)
        {
            Vector3 vector3{ MathType::GetValue(0), intersector.at(i).GetX(), intersector.at(i).GetY() };

            vector3.SetX(invNormalX * (plane.GetConstant() - plane.GetNormal().GetY() * vector3.GetY() - plane.GetNormal().GetZ() * vector3.GetZ()));

            point.emplace_back(vector3);
        }
    }
    else if (maxNormal == 1)
    {
        Real invNormalY = (MathType::GetValue(1)) / plane.GetNormal().GetY();
        for (auto i = 0; i < quantity; ++i)
        {
            Vector3 vector3{ intersector.at(i).GetX(), intersector.at(i).GetY(), MathType::GetValue(0) };

            vector3.SetZ(invNormalY * (plane.GetConstant() - plane.GetNormal().GetX() * vector3.GetX() - plane.GetNormal().GetZ() * vector3.GetZ()));

            point.emplace_back(vector3);
        }
    }
    else
    {
        Real invNormalZ = (MathType::GetValue(1)) / plane.GetNormal().GetZ();
        for (auto i = 0; i < quantity; ++i)
        {
            Vector3 vector3{ intersector.at(i).GetX(), intersector.at(i).GetY(), MathType::GetValue(0) };

            vector3.SetZ(invNormalZ * (plane.GetConstant() - plane.GetNormal().GetX() * vector3.GetX() - plane.GetNormal().GetY() * vector3.GetY()));

            point.emplace_back(vector3);
        }
    }
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::GetCoplanarIntersection(const Plane3& plane, const Triangle3& lhsTriangle, const Triangle3& rhsTriangle)
{
    // ����ƽ�淨������������ƽ����ͶӰ�����Ρ�
    auto maxNormal = 0;
    auto x = MathType::FAbs(plane.GetNormal().GetX());
    auto y = MathType::FAbs(plane.GetNormal().GetY());
    if (x < y)
    {
        maxNormal = 1;
        x = y;
    }
    y = MathType::FAbs(plane.GetNormal().GetZ());
    if (x < y)
    {
        maxNormal = 2;
    }

    using Triangle = std::array<Vector2<Real>, 3>;

    Triangle projectTriangle0Vector{};
    Triangle projectTriangle1Vector{};

    if (maxNormal == 0)
    {
        // ͶӰ��yzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(lhsTriangle.GetVertex(i).GetY(), lhsTriangle.GetVertex(i).GetZ());
            projectTriangle1Vector.at(i).SetCoordinate(rhsTriangle.GetVertex(i).GetY(), rhsTriangle.GetVertex(i).GetZ());
        }
    }
    else if (maxNormal == 1)
    {
        // ͶӰ��xzƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(lhsTriangle.GetVertex(i).GetX(), lhsTriangle.GetVertex(i).GetZ());
            projectTriangle1Vector.at(i).SetCoordinate(rhsTriangle.GetVertex(i).GetX(), rhsTriangle.GetVertex(i).GetZ());
        }
    }
    else
    {
        // ͶӰ��xyƽ���ϡ�
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(lhsTriangle.GetVertex(i).GetX(), lhsTriangle.GetVertex(i).GetY());
            projectTriangle1Vector.at(i).SetCoordinate(rhsTriangle.GetVertex(i).GetX(), rhsTriangle.GetVertex(i).GetY());
        }
    }

    Triangle2<Real> projectTriangle0{ projectTriangle0Vector.at(0), projectTriangle0Vector.at(1), projectTriangle0Vector.at(2) };
    Triangle2<Real> projectTriangle1{ projectTriangle1Vector.at(0), projectTriangle1Vector.at(1), projectTriangle1Vector.at(2) };

    // 2D�������ཻ������Ҫ��ʱ������

    auto edge0 = projectTriangle0.GetVertex(1) - projectTriangle0.GetVertex(0);
    auto edge1 = projectTriangle0.GetVertex(2) - projectTriangle0.GetVertex(0);
    if (Vector2Tools<Real>::DotPerp(edge0, edge1) < MathType::GetValue(0))
    {
        // ��������˳ʱ�뷽������������
        projectTriangle0 = Triangle2<Real>{ projectTriangle0Vector.at(0), projectTriangle0Vector.at(2), projectTriangle0Vector.at(1) };
    }

    edge0 = projectTriangle1.GetVertex(1) - projectTriangle1.GetVertex(0);
    edge1 = projectTriangle1.GetVertex(2) - projectTriangle1.GetVertex(0);
    if (Vector2Tools<Real>::DotPerp(edge0, edge1) < MathType::GetValue(0))
    {
        // ��������˳ʱ�뷽������������
        projectTriangle1 = Triangle2<Real>{ projectTriangle1Vector.at(0), projectTriangle1Vector.at(2), projectTriangle1Vector.at(1) };
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
        auto invNormalX = (MathType::GetValue(1)) / plane.GetNormal().GetX();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3 vector3{ MathType::GetValue(0), intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY() };
            vector3.SetX(invNormalX * (plane.GetConstant() - plane.GetNormal().GetY() * vector3.GetY() - plane.GetNormal().GetZ() * vector3.GetZ()));
            point.emplace_back(vector3);
        }
    }
    else if (maxNormal == 1)
    {
        auto invNormalY = (MathType::GetValue(1)) / plane.GetNormal().GetY();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3 vector3{ intr.GetPoint(i).GetX(), MathType::GetValue(0), intr.GetPoint(i).GetY() };
            vector3.SetY(invNormalY * (plane.GetConstant() - plane.GetNormal().GetX() * vector3.GetX() - plane.GetNormal().GetZ() * vector3.GetZ()));
            point.emplace_back(vector3);
        }
    }
    else
    {
        auto invNormalZ = (MathType::GetValue(1)) / plane.GetNormal().GetZ();
        for (auto i = 0; i < quantity; i++)
        {
            Vector3 vector3{ intr.GetPoint(i).GetX(), intr.GetPoint(i).GetY(), MathType::GetValue(0) };
            vector3.SetZ(invNormalZ * (plane.GetConstant() - plane.GetNormal().GetX() * vector3.GetX() - plane.GetNormal().GetY() * vector3.GetY()));
            point.emplace_back(vector3);
        }
    }

    this->SetIntersectionType(IntersectionType::Plane);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
