///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/20 15:39)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESLUT_FACTORY_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESLUT_FACTORY_DETAIL_H

#include "DistanceClosestPointsParameterResultDetail.h"
#include "DistanceMultipleClosestPointsResultDetail.h"
#include "DistanceResultFactory.h"

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultSharedPtr Mathematics::DistanceResultFactory<Real, Vector>::Create(Real distance)
{
    return std::make_shared<DistanceResultImpl>(distance);
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultSharedPtr Mathematics::DistanceResultFactory<Real, Vector>::Create(Real distance, Real contactTime)
{
    return std::make_shared<DistanceContactTimeResult<Real, Vector>>(distance, contactTime);
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultSharedPtr Mathematics::DistanceResultFactory<Real, Vector>::Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint)
{
    return std::make_shared<DistanceClosestPointsResult<Real, Vector>>(distance, contactTime, lhsClosestPoint, rhsClosestPoint);
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultSharedPtr Mathematics::DistanceResultFactory<Real, Vector>::Create(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints)
{
    return std::make_shared<DistanceMultipleClosestPointsResult<Real, Vector>>(distance, contactTime, lhsClosestPoints, rhsClosestPoints);
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultFactory<Real, Vector>::DistanceResultSharedPtr Mathematics::DistanceResultFactory<Real, Vector>::Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter)
{
    return std::make_shared<DistanceClosestPointsParameterResult<Real, Vector>>(distance, contactTime, lhsClosestPoint, rhsClosestPoint, lhsParameter, rhsParameter);
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESLUT_FACTORY_DETAIL_H
