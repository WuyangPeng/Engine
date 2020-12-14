///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/05 1:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H

#include "DistanceClosestPointsResultDetail.h"
#include "DistanceMultipleClosestPointsResult.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, typename Vector>
Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
    : ParentType{ distance, contactTime }, m_LhsClosestPoints{ lhsClosestPoints }, m_RhsClosestPoints{ rhsClosestPoints }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_LhsClosestPoints.size() == m_RhsClosestPoints.size())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
const Vector Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetLhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsClosestPoints.at(index);
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetRhsClosestPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsClosestPoints.at(index);
}

template <typename Real, typename Vector>
int Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetLhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_LhsClosestPoints.size());
}

template <typename Real, typename Vector>
int Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::GetRhsClosestPointSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_RhsClosestPoints.size());
}

template <typename Real, typename Vector>
typename Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::ImplTypePtr Mathematics::DistanceMultipleClosestPointsResult<Real, Vector>::Clone() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_DETAIL_H
