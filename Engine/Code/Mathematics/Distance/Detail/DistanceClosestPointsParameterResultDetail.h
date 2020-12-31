///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 18:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H

#include "DistanceClosestPointsParameterResult.h"
#include "DistanceClosestPointsResultDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::DistanceClosestPointsParameterResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter) noexcept
    : ParentType{ distance, contactTime, lhsClosestPoint, rhsClosestPoint }, m_LhsParameter{ lhsParameter }, m_RhsParameter{ rhsParameter }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Real Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::GetLhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsParameter;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::GetRhsParameter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsParameter;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::ImplTypePtr Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H
