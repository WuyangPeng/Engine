///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/10 11:34)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_ACHIEVE_H

#include "DistanceRay3Ray3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"

template <typename Real>
Mathematics::DistanceRay3Ray3<Real>::DistanceRay3Ray3(const Ray3& lhsRay, const Ray3& rhsRay) noexcept
    : ParentType{}, m_LhsRay{ lhsRay }, m_RhsRay{ rhsRay }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceRay3Ray3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::DistanceRay3Ray3<Real>::GetLhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsRay;
}

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::DistanceRay3Ray3<Real>::GetRhsRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsRay;
}

template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool tool{ m_LhsRay.GetOrigin(), m_LhsRay.GetDirection(), m_RhsRay.GetOrigin(), m_RhsRay.GetDirection() };

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
                lhsT /= det;
                rhsT /= det;

                auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                       rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                       tool.GetOriginDifferenceSquaredLength();

                return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::GetValue(0), m_LhsRay.GetOrigin() + lhsT * m_LhsRay.GetDirection(),
                                       m_RhsRay.GetOrigin() + rhsT * m_RhsRay.GetDirection(), lhsT, rhsT };
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
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>::GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3Tool& tool) const
{
    return DistanceResult{ Math::GetNumericalRoundOffNonnegative(tool.GetOriginDifferenceSquaredLength()),
                           Math::GetValue(0), m_LhsRay.GetOrigin(), m_RhsRay.GetOrigin(), Math::GetValue(0), Math::GetValue(0) };
}

// private
template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>::GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3Tool& tool) const
{
    auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_LhsRay.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * m_LhsRay.GetDirection(),
                           m_RhsRay.GetOrigin(), -tool.GetOriginDifferenceDotLhsDirection(), Math::GetValue(0) };
}

// private
template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>::GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3Tool& tool) const
{
    auto squaredDistance = tool.GetSquaredDistanceWithRhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_LhsRay.GetOrigin(),
                           m_RhsRay.GetOrigin() - tool.GetOriginDifferenceDotRhsDirection() * m_RhsRay.GetDirection(),
                           Math::GetValue(0), -tool.GetOriginDifferenceDotRhsDirection() };
}

template <typename Real>
const typename Mathematics::DistanceRay3Ray3<Real>::DistanceResult Mathematics::DistanceRay3Ray3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_ACHIEVE_H
