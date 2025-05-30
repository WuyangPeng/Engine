///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H

#include "DistanceRay2Ray2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistanceRay2Ray2<Real>::DistanceRay2Ray2(const Ray2Type& lhsRay, const Ray2Type& rhsRay) noexcept
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

    const DistanceLine2Line2ToolType tool{ lhsRay.GetOrigin(),
                                       lhsRay.GetDirection(),
                                       rhsRay.GetOrigin(),
                                       rhsRay.GetDirection() };

    const auto det = tool.GetDet();
    const auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();

    if (this->GetZeroThreshold() <= det)
    {
        // 射线不平行。
        const auto lhsT = tool.GetLhsT();
        const auto rhsT = tool.GetRhsT();

        if (MathType::GetValue(0) <= lhsT)
        {
            // 区域0（内部）
            if (MathType::GetValue(0) <= rhsT)
            {
                // 最小值为两个射线内部点。
                return DistanceResult{ MathType::GetValue(0),
                                       MathType::GetValue(0),
                                       lhsRay.GetOrigin() + lhsT / det * lhsRay.GetDirection(),
                                       rhsRay.GetOrigin() + rhsT / det * rhsRay.GetDirection() };
            }
            else  // 区域3（边）
            {
                if (MathType::GetValue(0) <= originDifferenceDotLhsDirection)
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

            if (MathType::GetValue(0) <= rhsT)  // 区域1（边）
            {
                if (MathType::GetValue(0) <= originDifferenceDotRhsDirection)
                {
                    return GetSquaredWithClosestPointsIsOrigin(tool);
                }
                else
                {
                    return GetSquaredWithClosestPointsIsRhs(tool);
                }
            }
            else  // 区域2（角）
            {
                if (originDifferenceDotLhsDirection < MathType::GetValue(0))
                {
                    return GetSquaredWithClosestPointsIsLhs(tool);
                }
                else
                {
                    if (MathType::GetValue(0) <= originDifferenceDotRhsDirection)
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
        // 射线是平行的。
        const auto directionDot = tool.GetDirectionDot();

        if (MathType::GetValue(0) < directionDot)
        {
            // 相反的方向向量。
            if (MathType::GetValue(0) <= originDifferenceDotLhsDirection)
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
            // 相同的方向向量
            if (MathType::GetValue(0) <= originDifferenceDotLhsDirection)
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

template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsOrigin(const DistanceLine2Line2ToolType& tool) const
{
    return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(tool.GetOriginDifferenceSquaredLength()),
                           MathType::GetValue(0),
                           lhsRay.GetOrigin(),
                           rhsRay.GetOrigin() };
}

template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsLhs(const DistanceLine2Line2ToolType& tool) const
{
    const auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, MathType::GetValue(0), lhsRay.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * lhsRay.GetDirection(), rhsRay.GetOrigin() };
}

template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsRhs(const DistanceLine2Line2ToolType& tool) const
{
    const auto squaredDistance = tool.GetSquaredDistanceWithRhs();

    return DistanceResult{ squaredDistance, MathType::GetValue(0), lhsRay.GetOrigin(), rhsRay.GetOrigin() - tool.GetOriginDifferenceDotRhsDirection() * rhsRay.GetDirection() };
}

template <typename Real>
typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const
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
