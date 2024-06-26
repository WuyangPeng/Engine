///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:41)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceContactTimeResult.h"

#include <vector>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceMultipleClosestPointsResult final : public DistanceContactTimeResult<Real, Vector>
    {
    public:
        using ClassType = DistanceMultipleClosestPointsResult<Real, Vector>;
        using ParentType = DistanceContactTimeResult<Real, Vector>;

        using ClosestPoints = std::vector<Vector>;
        using ImplTypeSharedPtr = typename ParentType::ImplTypeSharedPtr;

    public:
        DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector GetLhsClosestPoint(int index) const override;
        NODISCARD Vector GetRhsClosestPoint(int index) const override;

        NODISCARD int GetLhsClosestPointSize() const override;
        NODISCARD int GetRhsClosestPointSize() const override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

    private:
        ClosestPoints lhsClosestPoints;
        ClosestPoints rhsClosestPoints;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H
