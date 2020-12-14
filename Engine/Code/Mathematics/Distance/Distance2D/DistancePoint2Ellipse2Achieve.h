///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 15:04)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_ACHIEVE_H

#include "DistancePoint2Ellipse2.h"
#include "Detail/DistancePoint2Ellipse2ToolDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Ellipse2<Real>::DistancePoint2Ellipse2(const Vector2D& point, const Ellipse2& ellipse) noexcept
    : ParentType{}, m_Point{ point }, m_Ellipse{ ellipse }
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
const Mathematics::Vector2D<Real> Mathematics::DistancePoint2Ellipse2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::DistancePoint2Ellipse2<Real>::GetEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipse;
}

template <typename Real>
const typename Mathematics::DistancePoint2Ellipse2<Real>::DistanceResult Mathematics::DistancePoint2Ellipse2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在椭圆坐标系计算点的坐标。
    auto difference = m_Point - m_Ellipse.GetCenter();
    const Vector2D dot{ Vector2DTools::DotProduct(difference, m_Ellipse.GetAxis0()),
                        Vector2DTools::DotProduct(difference, m_Ellipse.GetAxis1()) };

    const DistancePoint2Ellipse2Tool<Real> tool{ m_Ellipse.GetExtent0(), m_Ellipse.GetExtent1(), dot, this->GetZeroThreshold() };

    auto squaredDistance = tool.GetSquaredDistance();
    auto outputVector = tool.GetOutputVector();

    const auto lhsClosestPoint = m_Point;
    auto rhsClosestPoint = m_Ellipse.GetCenter() + outputVector[0] * m_Ellipse.GetAxis0() + outputVector[1] * m_Ellipse.GetAxis1();

    return DistanceResult{ squaredDistance, Math::GetValue(0), lhsClosestPoint, rhsClosestPoint };
}

template <typename Real>
const typename Mathematics::DistancePoint2Ellipse2<Real>::DistanceResult Mathematics::DistancePoint2Ellipse2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedPoint = m_Point.GetMove(t, lhsVelocity);
    auto movedEllipse = m_Ellipse.GetMove(t, rhsVelocity);

    ClassType distance{ movedPoint, movedEllipse };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_ACHIEVE_H
