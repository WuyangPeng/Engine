///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 14:51)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_ACHIEVE_H

#include "DistanceRectangle3Rectangle3.h"
#include "DistanceSegment3Rectangle3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceRectangle3Rectangle3<Real>::DistanceRectangle3Rectangle3(const Rectangle3& lhsRectangle, const Rectangle3& rhsRectangle) noexcept
    : ParentType{}, m_LhsRectangle{ lhsRectangle }, m_RhsRectangle{ rhsRectangle }
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
const Mathematics::Rectangle3<Real> Mathematics::DistanceRectangle3Rectangle3<Real>::GetLhsRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsRectangle;
}

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::DistanceRectangle3Rectangle3<Real>::GetRhsRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsRectangle;
}

template <typename Real>
typename const Mathematics::DistanceRectangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceRectangle3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};

    auto sqrDist = Math::sm_MaxReal;

    // 将矩形0的边缘与矩形1的内部进行比较。
    for (auto outerIndex = 0; outerIndex < 2; ++outerIndex)
    {
        for (auto innerIndex = -1; innerIndex <= 1; innerIndex += 2)
        {
            auto center = m_LhsRectangle.GetCenter() + (innerIndex * m_LhsRectangle.GetExtent(1 - outerIndex)) * m_LhsRectangle.GetAxis(1 - outerIndex);
            const auto direction = m_LhsRectangle.GetAxis(outerIndex);
            auto extent = m_LhsRectangle.GetExtent(outerIndex);

            const Segment3<Real> edge{ extent, center, direction };

            DistanceSegment3Rectangle3<Real> distanceSegment3Rectangle3{ edge, m_RhsRectangle };
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
            auto center = m_RhsRectangle.GetCenter() + (innerIndex * m_RhsRectangle.GetExtent(1 - outerIndex)) * m_RhsRectangle.GetAxis(1 - outerIndex);
            const auto direction = m_RhsRectangle.GetAxis(outerIndex);
            auto extent = m_RhsRectangle.GetExtent(outerIndex);
            const Segment3<Real> edge{ extent, center, direction };

            DistanceSegment3Rectangle3<Real> distanceSegment3Rectangle3{ edge, m_LhsRectangle };
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
typename const Mathematics::DistanceRectangle3Rectangle3<Real>::DistanceResult Mathematics::DistanceRectangle3Rectangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLhsRectangle = m_LhsRectangle.GetMove(t, lhsVelocity);
    const auto movedRhsRectangle = m_RhsRectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLhsRectangle, movedRhsRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_ACHIEVE_H