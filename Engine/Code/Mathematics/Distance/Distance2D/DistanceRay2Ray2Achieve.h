///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/21 11:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H

#include "DistanceRay2Ray2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistanceRay2Ray2<Real>::DistanceRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay) noexcept
    : lhsRay{ lhsRay }, rhsRay{ rhsRay }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceRay2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray2<Real> Mathematics::DistanceRay2Ray2<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsRay;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::DistanceRay2Ray2<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsRay;
}

template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ lhsRay.GetOrigin(),
                                       lhsRay.GetDirection(),
                                       rhsRay.GetOrigin(),
                                       rhsRay.GetDirection() };

    const auto det = tool.GetDet();
    const auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();

    if (this->GetZeroThreshold() <= det)
    {
        // ���߲�ƽ�С�
        const auto lhsT = tool.GetLhsT();
        const auto rhsT = tool.GetRhsT();

        if (Math::GetValue(0) <= lhsT)
        {
            // ����0���ڲ���
            if (Math::GetValue(0) <= rhsT)
            {
                // ��СֵΪ���������ڲ��㡣
                return DistanceResult{ Math::GetValue(0),
                                       Math::GetValue(0),
                                       lhsRay.GetOrigin() + lhsT / det * lhsRay.GetDirection(),
                                       rhsRay.GetOrigin() + rhsT / det * rhsRay.GetDirection() };
            }
            else  // ����3���ߣ�
            {
                if (Math::GetValue(0) <= originDifferenceDotLhsDirection)
                {
                    return GetSquaredWithClosestPointsIsOrigin(tool);
                }
                else
                {
                    return GetSquaredWithClosestPointsIsLhs(tool);
                }
            }
        }
        else
        {
            auto originDifferenceDotRhsDirection = tool.GetOriginDifferenceDotRhsDirection();

            if (Math::GetValue(0) <= rhsT)  // ����1���ߣ�
            {
                if (Math::GetValue(0) <= originDifferenceDotRhsDirection)
                {
                    return GetSquaredWithClosestPointsIsOrigin(tool);
                }
                else
                {
                    return GetSquaredWithClosestPointsIsRhs(tool);
                }
            }
            else  // ����2���ǣ�
            {
                if (originDifferenceDotLhsDirection < Math::GetValue(0))
                {
                    return GetSquaredWithClosestPointsIsLhs(tool);
                }
                else
                {
                    if (Math::GetValue(0) <= originDifferenceDotRhsDirection)
                    {
                        return GetSquaredWithClosestPointsIsOrigin(tool);
                    }
                    else
                    {
                        return GetSquaredWithClosestPointsIsRhs(tool);
                    }
                }
            }
        }
    }
    else
    {
        // ������ƽ�еġ�
        const auto directionDot = tool.GetDirectionDot();

        if (Math::GetValue(0) < directionDot)
        {
            // �෴�ķ���������
            if (Math::GetValue(0) <= originDifferenceDotLhsDirection)
            {
                return GetSquaredWithClosestPointsIsOrigin(tool);
            }
            else
            {
                return GetSquaredWithClosestPointsIsLhs(tool);
            }
        }
        else
        {
            // ��ͬ�ķ�������
            if (Math::GetValue(0) <= originDifferenceDotLhsDirection)
            {
                return GetSquaredWithClosestPointsIsRhs(tool);
            }
            else
            {
                return GetSquaredWithClosestPointsIsLhs(tool);
            }
        }
    }
}

// private
template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsOrigin(const DistanceLine2Line2Tool& tool) const
{
    return DistanceResult{ Math::GetNumericalRoundOffNonnegative(tool.GetOriginDifferenceSquaredLength()),
                           Math::GetValue(0),
                           lhsRay.GetOrigin(),
                           rhsRay.GetOrigin() };
}

// private
template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsLhs(const DistanceLine2Line2Tool& tool) const
{
    const auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), lhsRay.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * lhsRay.GetDirection(), rhsRay.GetOrigin() };
}

// private
template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsRhs(const DistanceLine2Line2Tool& tool) const
{
    const auto squaredDistance = tool.GetSquaredDistanceWithRhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), lhsRay.GetOrigin(), rhsRay.GetOrigin() - tool.GetOriginDifferenceDotRhsDirection() * rhsRay.GetDirection() };
}

template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedRay = lhsRay.GetMove(t, lhsVelocity);
    const auto rhsMovedRay = rhsRay.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedRay, rhsMovedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H
