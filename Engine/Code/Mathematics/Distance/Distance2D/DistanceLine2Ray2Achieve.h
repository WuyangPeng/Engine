///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 16:34)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H

#include "DistanceLine2Ray2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistanceLine2Ray2<Real>::DistanceLine2Ray2(const Line2& line, const Ray2& ray) noexcept
    : ParentType{}, m_Line{ line }, m_Ray{ ray }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine2Ray2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line2<Real> Mathematics::DistanceLine2Ray2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Ray2<Real> Mathematics::DistanceLine2Ray2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ m_Line.GetOrigin(), m_Line.GetDirection(), m_Ray.GetOrigin(), m_Ray.GetDirection() };

    auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        auto rhsT = tool.GetRhsT();

        if (Math::GetValue(0) <= rhsT)
        {
            // 两个内部点最接近，一个在直线上，一个在射线上。
            auto lhsT = tool.GetLhsT();

            return DistanceResult{ Math::GetValue(0), Math::GetValue(0), m_Line.GetOrigin() + lhsT / det * m_Line.GetDirection(), m_Ray.GetOrigin() + rhsT / det * m_Ray.GetDirection() };
        }
        else
        {
            // 射线的原点同直线的某一点最接近。
            return GetSquaredWithClosestPoints(tool);
        }
    }
    else
    {
        // 线是平行的，最接近的一对点在射线原点。
        return GetSquaredWithClosestPoints(tool);
    }
}

template <typename Real>
const typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool) const
{
    auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_Line.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * m_Line.GetDirection(), m_Ray.GetOrigin() };
}

template <typename Real>
const typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = m_Line.GetMove(t, lhsVelocity);
    const auto movedRay = m_Ray.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H
