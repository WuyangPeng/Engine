///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:15)

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
    // 获取m_LhsTriangle的平面
    const Plane3 lhsPlane0{ triangle0 };

    // 计算三角形m_RhsTriangle顶点到平面lhsPlane0的有符号距离。使用epsilon-thick测试。
    const TrianglePlaneRelations<Real> rhsTrianglePlaneRelations{ triangle1, lhsPlane0, this->GetEpsilon() };

    if (rhsTrianglePlaneRelations.GetPositive() == 3 || rhsTrianglePlaneRelations.GetNegative() == 3)
    {
        // 三角形m_RhsTriangle完全在平面lhsPlane的一侧。
        return;
    }

    if (rhsTrianglePlaneRelations.GetZero() == 3)
    {
        // 三角形m_RhsTriangle由平面lhsPlane包含。
        if (reportCoplanarIntersections)
        {
            GetCoplanarIntersection(lhsPlane0, triangle0, triangle1);
            return;
        }
        return;
    }

    // 检查三角形m_RhsTriangle和平面lhsPlane之间的接触。
    if (rhsTrianglePlaneRelations.GetPositive() == 0 || rhsTrianglePlaneRelations.GetNegative() == 0)
    {
        if (rhsTrianglePlaneRelations.GetZero() == 2)
        {
            // 三角形m_RhsTriangle的边在平面lhsPlane中。
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
            MATHEMATICS_ASSERTION_2(rhsTrianglePlaneRelations.GetZero() == 1, "三角形和平面接触计算错误！");

            // 三角形m_RhsTriangle的顶点在平面lhsPlane中。
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

    // 此时，三角形m_RhsTriangle横向与平面lhsPlane相交。计算交点的线段。
    // 然后测试这个线段和三角形m_LhsTriangle之间的交集。
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

    MATHEMATICS_ASSERTION_2(false, "逻辑不应该执行到这里！\n");
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
    /// 生成平面的坐标系。 传入三角形的顶点为<V0,V1,V2>。
    /// 输入平面的单位长度法向为N，输入点为P。选择V0作为平面的原点。 坐标轴方向是两个单位长度向量U0和U1，
    /// 构造为{ U0，U1，N } 是一个正交集。 平面中的任何点Q均可写为Q = V0 + x0 * U0 + x1 * U1。
    ///  坐标计算为x0 = Dot(U0,Q - V0)和x1 = Dot(U1,Q - V0)。

    const auto vector3OrthonormalBasis = Vector3ToolsType::GenerateComplementBasis(plane.GetNormal());
    const auto uVector = vector3OrthonormalBasis.GetUVector();
    const auto vVector = vector3OrthonormalBasis.GetVVector();

    /// 计算点P，V1和V2的平面坐标。 为简化起见，从这些点中减去原点，在这种情况下，平面坐标适用于P - V0，V1 - V0和V2 - V0。
    auto pointMinusVertex0 = vector3 - triangle.GetVertex(0);
    auto vertex1MinusVertex0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto vertex2MinusVertex0 = triangle.GetVertex(2) - triangle.GetVertex(0);

    // P - V0的平面表示。.
    const Vector2<Real> planar{ Vector3ToolsType::DotProduct(uVector, pointMinusVertex0), Vector3ToolsType::DotProduct(vVector, pointMinusVertex0) };

    using Triangle = std::vector<Vector2<Real>>;

    /// 三角形<V0-V0,V1-V0,V2-V0>的平面表示。
    Triangle triangleVector{ Vector2<Real>::GetZero(),
                             Vector2<Real>{ Vector3ToolsType::DotProduct(uVector, vertex1MinusVertex0), Vector3ToolsType::DotProduct(vVector, vertex1MinusVertex0) },
                             Vector2<Real>{ Vector3ToolsType::DotProduct(uVector, vertex2MinusVertex0), Vector3ToolsType::DotProduct(vVector, vertex2MinusVertex0) } };

    /// 测试P-V0是否在三角形<0,V1-V0,V2-V0>中。
    if (Query2<Real>{ triangleVector }.ToTriangle(planar, 0, 1, 2) != TriangleQueryType::Outside)
    {
        // 向调用者报告交叉点。
        this->SetIntersectionType(IntersectionType::Point);
        point.emplace_back(vector3);
    }
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3Type& end0, const Vector3Type& end1)
{
    /// 计算三角形顶点的二维表示以及相对于三角形平面的线段端点。 然后计算2D空间中的交点。

    /// 将三角形投影到与平面法线最对齐的坐标平面上。
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
        // 投影到yz平面上。
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
        // 投影到xz平面上。
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
        // 投影到xy平面上。
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
        MATHEMATICS_ASSERTION_0(calc.GetIntersectionType() == IntersectionType::Point, "交叉点必须是点\n");
        this->SetIntersectionType(IntersectionType::Point);

        intersector.at(0) = calc.GetPoint(0);
    }

    // 取消投影相交线段。
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
    // 在与平面法线最对齐的坐标平面上投影三角形。
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
        // 投影到yz平面上。
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(lhsTriangle.GetVertex(i).GetY(), lhsTriangle.GetVertex(i).GetZ());
            projectTriangle1Vector.at(i).SetCoordinate(rhsTriangle.GetVertex(i).GetY(), rhsTriangle.GetVertex(i).GetZ());
        }
    }
    else if (maxNormal == 1)
    {
        // 投影到xz平面上。
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(lhsTriangle.GetVertex(i).GetX(), lhsTriangle.GetVertex(i).GetZ());
            projectTriangle1Vector.at(i).SetCoordinate(rhsTriangle.GetVertex(i).GetX(), rhsTriangle.GetVertex(i).GetZ());
        }
    }
    else
    {
        // 投影到xy平面上。
        for (auto i = 0; i < 3; ++i)
        {
            projectTriangle0Vector.at(i).SetCoordinate(lhsTriangle.GetVertex(i).GetX(), lhsTriangle.GetVertex(i).GetY());
            projectTriangle1Vector.at(i).SetCoordinate(rhsTriangle.GetVertex(i).GetX(), rhsTriangle.GetVertex(i).GetY());
        }
    }

    Triangle2<Real> projectTriangle0{ projectTriangle0Vector.at(0), projectTriangle0Vector.at(1), projectTriangle0Vector.at(2) };
    Triangle2<Real> projectTriangle1{ projectTriangle1Vector.at(0), projectTriangle1Vector.at(1), projectTriangle1Vector.at(2) };

    // 2D三角形相交例程需要逆时针排序。

    auto edge0 = projectTriangle0.GetVertex(1) - projectTriangle0.GetVertex(0);
    auto edge1 = projectTriangle0.GetVertex(2) - projectTriangle0.GetVertex(0);
    if (Vector2Tools<Real>::DotPerp(edge0, edge1) < MathType::GetValue(0))
    {
        // 三角形是顺时针方向，请重新排序。
        projectTriangle0 = Triangle2<Real>{ projectTriangle0Vector.at(0), projectTriangle0Vector.at(2), projectTriangle0Vector.at(1) };
    }

    edge0 = projectTriangle1.GetVertex(1) - projectTriangle1.GetVertex(0);
    edge1 = projectTriangle1.GetVertex(2) - projectTriangle1.GetVertex(0);
    if (Vector2Tools<Real>::DotPerp(edge0, edge1) < MathType::GetValue(0))
    {
        // 三角形是顺时针方向，请重新排序。
        projectTriangle1 = Triangle2<Real>{ projectTriangle1Vector.at(0), projectTriangle1Vector.at(2), projectTriangle1Vector.at(1) };
    }

    StaticFindIntersectorTriangle2Triangle2<Real> intr{ projectTriangle0, projectTriangle1 };
    if (!intr.IsIntersection())
    {
        return;
    }

    // 将2D交点映射回3D三角形空间。
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
