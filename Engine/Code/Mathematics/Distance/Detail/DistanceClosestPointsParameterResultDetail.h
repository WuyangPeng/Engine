///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:44)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H

#include "DistanceClosestPointsParameterResult.h"
#include "DistanceClosestPointsResultDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename Vector>
Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::DistanceClosestPointsParameterResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter) noexcept
    : ParentType{ distance, contactTime, lhsClosestPoint, rhsClosestPoint }, lhsParameter{ lhsParameter }, rhsParameter{ rhsParameter }
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
Real Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::GetLhsParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsParameter;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::GetRhsParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsParameter;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::ImplTypeSharedPtr Mathematics::DistanceClosestPointsParameterResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_DETAIL_H
