///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:11)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceClosestPointsResult.h"
#include "DistanceContactTimeResultDetail.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsResult<Real, Vector>::DistanceClosestPointsResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint) noexcept
    : ParentType{ distance, contactTime }, lhsClosestPoint{ lhsClosestPoint }, rhsClosestPoint{ rhsClosestPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
bool Mathematics::DistanceClosestPointsResult<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Vector Mathematics::DistanceClosestPointsResult<Real, Vector>::GetLhsClosestPoint([[maybe_unused]] int index) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsClosestPoint;
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceClosestPointsResult<Real, Vector>::GetRhsClosestPoint([[maybe_unused]] int index) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsClosestPoint;
}

template <typename Real, typename Vector>
int Mathematics::DistanceClosestPointsResult<Real, Vector>::GetLhsClosestPointSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return pointSize;
}

template <typename Real, typename Vector>
int Mathematics::DistanceClosestPointsResult<Real, Vector>::GetRhsClosestPointSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return pointSize;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceClosestPointsResult<Real, Vector>::ImplTypeSharedPtr Mathematics::DistanceClosestPointsResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H
