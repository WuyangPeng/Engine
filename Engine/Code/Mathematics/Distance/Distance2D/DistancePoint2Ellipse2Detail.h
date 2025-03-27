///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_DETAIL_H

#include "DistancePoint2Ellipse2.h"
#include "Detail/DistancePoint2Ellipse2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Ellipse2<Real>::DistancePoint2Ellipse2(const Vector2Type& point, const Ellipse2Type& ellipse) noexcept
    : ParentType{}, point{ point }, ellipse{ ellipse }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Ellipse2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Ellipse2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Ellipse2<Real> Mathematics::DistancePoint2Ellipse2<Real>::GetEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipse;
}

template <typename Real>
typename Mathematics::DistancePoint2Ellipse2<Real>::DistanceResult Mathematics::DistancePoint2Ellipse2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在椭圆坐标系计算点的坐标。
    const auto difference = point - ellipse.GetCenter();
    const Vector2Type dot{ Vector2ToolsType::DotProduct(difference, ellipse.GetAxis0()),
                           Vector2ToolsType::DotProduct(difference, ellipse.GetAxis1()) };

    const DistancePoint2Ellipse2Tool<Real> tool{ ellipse.GetExtent0(), ellipse.GetExtent1(), dot, this->GetZeroThreshold() };

    const auto squaredDistance = tool.GetSquaredDistance();
    const auto outputVector = tool.GetOutputVector();

    const auto lhsClosestPoint = point;
    const auto rhsClosestPoint = ellipse.GetCenter() + outputVector[0] * ellipse.GetAxis0() + outputVector[1] * ellipse.GetAxis1();

    return DistanceResult{ squaredDistance, MathType::GetValue(0), lhsClosestPoint, rhsClosestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint2Ellipse2<Real>::DistanceResult Mathematics::DistancePoint2Ellipse2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedPoint = point.GetMove(t, lhsVelocity);
    const auto movedEllipse = ellipse.GetMove(t, rhsVelocity);

    ClassType distance{ movedPoint, movedEllipse };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_DETAIL_H
