///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_DETAIL_H

#include "DistancePoint2Ellipse2.h"
#include "Detail/DistancePoint2Ellipse2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Ellipse2<Real>::DistancePoint2Ellipse2(const Vector2& point, const Ellipse2& ellipse) noexcept
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

    // ����Բ����ϵ���������ꡣ
    const auto difference = point - ellipse.GetCenter();
    const Vector2 dot{ Vector2Tools::DotProduct(difference, ellipse.GetAxis0()),
                       Vector2Tools::DotProduct(difference, ellipse.GetAxis1()) };

    const DistancePoint2Ellipse2Tool<Real> tool{ ellipse.GetExtent0(), ellipse.GetExtent1(), dot, this->GetZeroThreshold() };

    const auto squaredDistance = tool.GetSquaredDistance();
    const auto outputVector = tool.GetOutputVector();

    const auto lhsClosestPoint = point;
    const auto rhsClosestPoint = ellipse.GetCenter() + outputVector[0] * ellipse.GetAxis0() + outputVector[1] * ellipse.GetAxis1();

    return DistanceResult{ squaredDistance, Math::GetValue(0), lhsClosestPoint, rhsClosestPoint };
}

template <typename Real>
typename Mathematics::DistancePoint2Ellipse2<Real>::DistanceResult Mathematics::DistancePoint2Ellipse2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
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
