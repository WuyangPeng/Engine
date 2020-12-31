///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 17:11)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_ACHIEVE_H

#include "DistanceSegment3Rectangle3.h"
#include "DistanceSegment3Triangle3.h"
#include "DistanceTriangle3Rectangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceTriangle3Rectangle3<Real>::DistanceTriangle3Rectangle3(const Triangle3& triangle, const Rectangle3& rectangle) noexcept
    : ParentType{}, m_Triangle{ triangle }, m_Rectangle{ rectangle }
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
const Mathematics::Triangle3<Real> Mathematics::DistanceTriangle3Rectangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::DistanceTriangle3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rectangle;
}

template <typename Real>
typename const Mathematics::DistanceTriangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};

    // 比较三角形的边缘与矩形的内部。
    auto sqrDist = Math::sm_MaxReal;

    for (auto index0 = 2, index1 = 0; index1 < 3; index0 = index1++)
    {
        auto center = (Math::GetRational(1, 2)) * (m_Triangle.GetVertex(index0) + m_Triangle.GetVertex(index1));
        auto direction = m_Triangle.GetVertex(index1) - m_Triangle.GetVertex(index0);
        auto extent = (Math::GetRational(1, 2)) * Vector3DTools::VectorMagnitude(direction);

        const Segment3<Real> edge{ extent, center, direction };

        DistanceSegment3Rectangle3<Real> distanceSegment3Rectangle3{ edge, m_Rectangle };
        auto squared = distanceSegment3Rectangle3.GetSquared();
        if (squared.GetDistance() < sqrDist)
        {
            // 三角形点在closestPoint0中报告，而矩形点在closestPoint1中报告。
            // distanceSegment3Rectangle3计算器适用于triangleEdge-rectangle，
            // 因此必须按如下所示调用GetLhsClosestPoint()和GetRhsClosestPoint()。
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();
        }
    }

    // 比较矩形的边缘与三角形的内部。
    for (auto index1 = 0; index1 < 2; ++index1)
    {
        for (auto index0 = -1; index0 <= 1; index0 += 2)
        {
            auto center = m_Rectangle.GetCenter() + (index0 * m_Rectangle.GetExtent(1 - index1)) * m_Rectangle.GetAxis(1 - index1);
            const auto direction = m_Rectangle.GetAxis(index1);
            auto extent = m_Rectangle.GetExtent(index1);

            const Segment3<Real> edge{ extent, center, direction };

            DistanceSegment3Triangle3<Real> distanceSegment3Triangle3{ edge, m_Triangle };
            auto squared = distanceSegment3Triangle3.GetSquared();
            if (squared.GetDistance() < sqrDist)
            {
                // 矩形点在closestPoint0中报告，而三角形点在closestPoint1中报告。
                // distanceSegment3Triangle3计算器适用于rectangleEdge-triangle，
                // 因此必须按如下所示调用GetRhsClosestPoint()和GetLhsClosestPoint()。
                closestPoint0 = squared.GetRhsClosestPoint();
                closestPoint1 = squared.GetLhsClosestPoint();
                sqrDist = squared.GetDistance();
            }
        }
    }
    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename const Mathematics::DistanceTriangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceTriangle3Rectangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedTriangle = m_Triangle.GetMove(t, lhsVelocity);
    const auto movedRectangle = m_Rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedTriangle, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_ACHIEVE_H