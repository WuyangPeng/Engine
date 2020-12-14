///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 18:45)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceClosestPointsResult.h"
#include "DistanceContactTimeResultDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsResult<Real, Vector>::DistanceClosestPointsResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint) noexcept
    : ParentType{ distance, contactTime }, m_LhsClosestPoint{ lhsClosestPoint }, m_RhsClosestPoint{ rhsClosestPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

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
const Vector Mathematics::DistanceClosestPointsResult<Real, Vector>::GetLhsClosestPoint([[maybe_unused]] int index) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsClosestPoint;
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceClosestPointsResult<Real, Vector>::GetRhsClosestPoint([[maybe_unused]] int index) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsClosestPoint;
}

template <typename Real, typename Vector>
int Mathematics::DistanceClosestPointsResult<Real, Vector>::GetLhsClosestPointSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sm_PointSize;
}

template <typename Real, typename Vector>
int Mathematics::DistanceClosestPointsResult<Real, Vector>::GetRhsClosestPointSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sm_PointSize;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceClosestPointsResult<Real, Vector>::ImplTypePtr Mathematics::DistanceClosestPointsResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_DETAIL_H
