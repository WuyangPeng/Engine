///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:49)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H

#include "DistanceLine2Ray2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

template <typename Real>
Mathematics::DistanceLine2Ray2<Real>::DistanceLine2Ray2(const Line2& line, const Ray2& ray) noexcept
    : ParentType{}, line{ line }, ray{ ray }
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
Mathematics::Line2<Real> Mathematics::DistanceLine2Ray2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Ray2<Real> Mathematics::DistanceLine2Ray2<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ line.GetOrigin(), line.GetDirection(), ray.GetOrigin(), ray.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        const auto rhsT = tool.GetRhsT();

        if (Math::GetValue(0) <= rhsT)
        {
            // �����ڲ�����ӽ���һ����ֱ���ϣ�һ���������ϡ�
            const auto lhsT = tool.GetLhsT();

            return DistanceResult{ Math::GetValue(0), Math::GetValue(0), line.GetOrigin() + lhsT / det * line.GetDirection(), ray.GetOrigin() + rhsT / det * ray.GetDirection() };
        }
        else
        {
            // ���ߵ�ԭ��ֱͬ�ߵ�ĳһ����ӽ���
            return GetSquaredWithClosestPoints(tool);
        }
    }
    else
    {
        // ����ƽ�еģ���ӽ���һ�Ե�������ԭ�㡣
        return GetSquaredWithClosestPoints(tool);
    }
}

template <typename Real>
typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool) const
{
    const auto squaredDistance = tool.GetSquaredDistanceWithLhs();

    return DistanceResult{ squaredDistance, Math::GetValue(0), line.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * line.GetDirection(), ray.GetOrigin() };
}

template <typename Real>
typename Mathematics::DistanceLine2Ray2<Real>::DistanceResult Mathematics::DistanceLine2Ray2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = line.GetMove(t, lhsVelocity);
    const auto movedRay = ray.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedRay };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_ACHIEVE_H
