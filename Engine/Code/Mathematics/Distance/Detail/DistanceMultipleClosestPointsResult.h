///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/05 1:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceContactTimeResult.h"

#include <vector>

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceMultipleClosestPointsResult : public DistanceContactTimeResult<Real, Vector>
    {
    public:
        using ClassType = DistanceMultipleClosestPointsResult<Real, Vector>;
        using ParentType = DistanceContactTimeResult<Real, Vector>;
        using ClosestPoints = std::vector<Vector>;
        using ImplTypePtr = ParentType::ImplTypePtr;

    public:
        DistanceMultipleClosestPointsResult(Real distance, Real contactTime, const ClosestPoints& lhsClosestPoints, const ClosestPoints& rhsClosestPoints);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector GetLhsClosestPoint(int index) const override;
        [[nodiscard]] const Vector GetRhsClosestPoint(int index) const override;

        [[nodiscard]] int GetLhsClosestPointSize() const override;
        [[nodiscard]] int GetRhsClosestPointSize() const override;

        [[nodiscard]] ImplTypePtr Clone() const override;

    private:
        ClosestPoints m_LhsClosestPoints;
        ClosestPoints m_RhsClosestPoints;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_MULTIPLE_CLOSEST_POINTS_RESULT_H
