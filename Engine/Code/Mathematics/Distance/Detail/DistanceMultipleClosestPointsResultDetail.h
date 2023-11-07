///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 15:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceClosestPointsResultDetail.h"
#include "DistanceMultipleClosestPointsResult.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename Vector>
Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
    : ParentType{ distance, contactTime }, lhsClosestPoints{ lhsClosestPoints }, rhsClosestPoints{ rhsClosestPoints }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
bool Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid() && lhsClosestPoints.size() == rhsClosestPoints.size())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Vector Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetLhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsClosestPoints.at(index);
}

template <typename Real, typename Vector>
Vector Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetRhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsClosestPoints.at(index);
}

template <typename Real, typename Vector>
int Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetLhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(lhsClosestPoints.size());
}

template <typename Real, typename Vector>
int Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetRhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(rhsClosestPoints.size());
}

template <typename Real, typename Vector>
typename Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::ImplTypeSharedPtr Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
