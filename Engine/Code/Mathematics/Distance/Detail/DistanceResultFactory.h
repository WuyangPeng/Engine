///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:42)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceInternalFwd.h"

#include <vector>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceResultFactory final
    {
    public:
        using ClassType = DistanceResultFactory<Real, Vector>;

        using DistanceResultImpl = DistanceResultImpl<Real, Vector>;
        using DistanceResultSharedPtr = std::shared_ptr<DistanceResultImpl>;
        using ClosestPoints = std::vector<Vector>;

    public:
        DistanceResultFactory() = delete;

        NODISCARD static DistanceResultSharedPtr Create(Real distance);
        NODISCARD static DistanceResultSharedPtr Create(Real distance, Real contactTime);
        NODISCARD static DistanceResultSharedPtr Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint);
        NODISCARD static DistanceResultSharedPtr Create(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);
        NODISCARD static DistanceResultSharedPtr Create(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint, Real lhsParameter, Real rhsParameter);
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RESULT_FACTORY_H
