///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:37)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_DETAIL_H

#include "DistanceSegment3Rectangle3.h"
#include "DistanceSegment3Triangle3.h"
#include "DistanceTriangle3Rectangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceTriangle3Rectangle3<Real>::DistanceTriangle3Rectangle3(const Triangle3& triangle, const Rectangle3& rectangle) noexcept
    : ParentType{}, triangle{ triangle }, rectangle{ rectangle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceTriangle3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistanceTriangle3Rectangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistanceTriangle3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
typename Mathematics::DistanceTriangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    // �Ƚ������εı�Ե����ε��ڲ���
    auto sqrDist = Math::maxReal;

    for (auto index0 = 2, index1 = 0; index1 < 3; index0 = index1++)
    {
        auto center = (Math::GetRational(1, 2)) * (triangle.GetVertex(index0) + triangle.GetVertex(index1));
        auto direction = triangle.GetVertex(index1) - triangle.GetVertex(index0);
        auto extent = (Math::GetRational(1, 2)) * Vector3Tools::GetLength(direction);

        const Segment3<Real> edge{ extent, center, direction };

        DistanceSegment3Rectangle3<Real> distanceSegment3Rectangle3{ edge, rectangle };

        if (auto squared = distanceSegment3Rectangle3.GetSquared();
            squared.GetDistance() < sqrDist)
        {
            // �����ε���closestPoint0�б��棬�����ε���closestPoint1�б��档
            // distanceSegment3Rectangle3������������triangleEdge-rectangle��
            // ��˱��밴������ʾ����GetLhsClosestPoint()��GetRhsClosestPoint()��
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();
        }
    }

    // �ȽϾ��εı�Ե�������ε��ڲ���
    for (auto index1 = 0; index1 < 2; ++index1)
    {
        for (auto index0 = -1; index0 <= 1; index0 += 2)
        {
            auto center = rectangle.GetCenter() + (index0 * rectangle.GetExtent(1 - index1)) * rectangle.GetAxis(1 - index1);
            const auto direction = rectangle.GetAxis(index1);
            auto extent = rectangle.GetExtent(index1);

            const Segment3<Real> edge{ extent, center, direction };

            DistanceSegment3Triangle3<Real> distanceSegment3Triangle3{ edge, triangle };

            if (auto squared = distanceSegment3Triangle3.GetSquared();
                squared.GetDistance() < sqrDist)
            {
                // ���ε���closestPoint0�б��棬�������ε���closestPoint1�б��档
                // distanceSegment3Triangle3������������rectangleEdge-triangle��
                // ��˱��밴������ʾ����GetRhsClosestPoint()��GetLhsClosestPoint()��
                closestPoint0 = squared.GetRhsClosestPoint();
                closestPoint1 = squared.GetLhsClosestPoint();
                sqrDist = squared.GetDistance();
            }
        }
    }
    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename Mathematics::DistanceTriangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Rectangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedTriangle = triangle.GetMove(t, lhsVelocity);
    const auto movedRectangle = rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedTriangle, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_DETAIL_H