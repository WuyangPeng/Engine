///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 15:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_DETAIL_H

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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_DETAIL_H
