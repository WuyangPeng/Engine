///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/08 18:26)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H

#include "DistanceRay2Ray2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistanceRay2Ray2<Real>::DistanceRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay) noexcept
    : m_LhsRay{ lhsRay }, m_RhsRay{ rhsRay }
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
const Mathematics::Ray2<Real> Mathematics::DistanceRay2Ray2<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsRay;
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::DistanceRay2Ray2<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsRay;
}

template <typename Real>
const typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ m_LhsRay.GetOrigin(), m_LhsRay.GetDirection(),
                                       m_RhsRay.GetOrigin(), m_RhsRay.GetDirection() };

    auto det = tool.GetDet();
    auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();

    if (this->GetZeroThreshold() <= det)
    {
        // ���߲�ƽ�С�
        auto lhsT = tool.GetLhsT();
        auto rhsT = tool.GetRhsT();

        if (Math::GetValue(0) <= lhsT)
        {
            // ����0���ڲ���
            if (Math::GetValue(0) <= rhsT)
            {
                // ��СֵΪ���������ڲ��㡣
                return DistanceResult{ Math::GetValue(0), Math::GetValue(0), m_LhsRay.GetOrigin() + lhsT / det * m_LhsRay.GetDirection(),
                                       m_RhsRay.GetOrigin() + rhsT / det * m_RhsRay.GetDirection() };
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
        auto directionDot = tool.GetDirectionDot();

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
const typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsOrigin(const DistanceLine2Line2Tool& tool) const
{
    return DistanceResult{ Math::GetNumericalRoundOffNonnegative(tool.GetOriginDifferenceSquaredLength()),
                           Math::GetValue(0), m_LhsRay.GetOrigin(), m_RhsRay.GetOrigin() };
}

// private
template <typename Real>
const typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsLhs(const DistanceLine2Line2Tool& tool) const
{
    auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_LhsRay.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * m_LhsRay.GetDirection(), m_RhsRay.GetOrigin() };
}

// private
template <typename Real>
const typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquaredWithClosestPointsIsRhs(const DistanceLine2Line2Tool& tool) const
{
    auto squaredDistance = tool.GetSquaredDistanceWithRhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_LhsRay.GetOrigin(), m_RhsRay.GetOrigin() - tool.GetOriginDifferenceDotRhsDirection() * m_RhsRay.GetDirection() };
}

template <typename Real>
const typename Mathematics::DistanceRay2Ray2<Real>::DistanceResult Mathematics::DistanceRay2Ray2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedRay = m_LhsRay.GetMove(t, lhsVelocity);
    const auto rhsMovedRay = m_RhsRay.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedRay, rhsMovedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_ACHIEVE_H
