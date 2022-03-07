///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/20 15:55)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceClosestPointsResult.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceClosestPointsParameterResult : public DistanceClosestPointsResult<Real, Vector>
    {
    public:
        using ClassType = DistanceClosestPointsParameterResult<Real, Vector>;
        using ParentType = DistanceClosestPointsResult<Real, Vector>;
        using ImplTypeSharedPtr = typename ParentType::ImplTypeSharedPtr;

    public:
        DistanceClosestPointsParameterResult(Real distance,
                                             Real contactTime,
                                             const Vector& lhsClosestPoint,
                                             const Vector& rhsClosestPoint,
                                             Real lhsParameter,
                                             Real rhsParameter) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Real GetLhsParameter() const noexcept override;
        NODISCARD Real GetRhsParameter() const noexcept override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

    private:
        Real lhsParameter;
        Real rhsParameter;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_PARAMETER_RESULT_H
