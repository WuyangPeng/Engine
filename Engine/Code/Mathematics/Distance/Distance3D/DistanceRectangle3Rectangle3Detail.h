///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:35)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_DETAIL_H

#include "DistanceRectangle3Rectangle3.h"
#include "DistanceSegment3Rectangle3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRectangle3Rectangle3<Real>::DistanceRectangle3Rectangle3(const Rectangle3& lhsRectangle, const Rectangle3& rhsRectangle) noexcept
    : ParentType{}, lhsRectangle{ lhsRectangle }, rhsRectangle{ rhsRectangle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceRectangle3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistanceRectangle3Rectangle3<Real>::GetLhsRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsRectangle;
}

template <typename Real>
Mathematics::Rectangle3<Real> Mathematics::DistanceRectangle3Rectangle3<Real>::GetRhsRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsRectangle;
}

template <typename Real>
typename Mathematics::DistanceRectangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceRectangle3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};

    auto sqrDist = Math::maxReal;

    // 将矩形0的边缘与矩形1的内部进行比较。
    for (auto outerIndex = 0; outerIndex < 2; ++outerIndex)
    {
        for (auto innerIndex = -1; innerIndex <= 1; innerIndex += 2)
        {
            auto center = lhsRectangle.GetCenter() + (innerIndex * lhsRectangle.GetExtent(1 - outerIndex)) * lhsRectangle.GetAxis(1 - outerIndex);
            const auto direction = lhsRectangle.GetAxis(outerIndex);
            auto extent = lhsRectangle.GetExtent(outerIndex);

            const Segment3<Real> edge{ extent, center, direction };

            DistanceSegment3Rectangle3<Real> distanceSegment3Rectangle3{ edge, rhsRectangle };
            auto squared = distanceSegment3Rectangle3.GetSquared();
            if (squared.GetDistance() < sqrDist)
            {
                closestPoint0 = squared.GetLhsClosestPoint();
                closestPoint1 = squared.GetRhsClosestPoint();
                sqrDist = squared.GetDistance();
            }
        }
    }

    // 比较矩形1的边缘与矩形0的内部。
    for (auto outerIndex = 0; outerIndex < 2; ++outerIndex)
    {
        for (auto innerIndex = -1; innerIndex <= 1; innerIndex += 2)
        {
            auto center = rhsRectangle.GetCenter() + (innerIndex * rhsRectangle.GetExtent(1 - outerIndex)) * rhsRectangle.GetAxis(1 - outerIndex);
            const auto direction = rhsRectangle.GetAxis(outerIndex);
            auto extent = rhsRectangle.GetExtent(outerIndex);
            const Segment3<Real> edge{ extent, center, direction };

            DistanceSegment3Rectangle3<Real> distanceSegment3Rectangle3{ edge, lhsRectangle };
            auto squared = distanceSegment3Rectangle3.GetSquared();
            if (squared.GetDistance() < sqrDist)
            {
                closestPoint0 = squared.GetLhsClosestPoint();
                closestPoint1 = squared.GetRhsClosestPoint();
                sqrDist = squared.GetDistance();
            }
        }
    }

    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1 };
}

template <typename Real>
typename Mathematics::DistanceRectangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceRectangle3Rectangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLhsRectangle = lhsRectangle.GetMove(t, lhsVelocity);
    const auto movedRhsRectangle = rhsRectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLhsRectangle, movedRhsRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_DETAIL_H