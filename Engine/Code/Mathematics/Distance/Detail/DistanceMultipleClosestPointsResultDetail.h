///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/20 15:44)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceClosestPointsResultDetail.h"
#include "DistanceMultipleClosestPointsResult.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, typename Vector>
Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
    : ParentType{ distance, contactTime }, lhsClosestPoints{ lhsClosestPoints }, rhsClosestPoints{ rhsClosestPoints }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

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
