///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 18:44)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceContactTimeResult.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceClosestPointsResult : public DistanceContactTimeResult<Real, Vector>
    {
    public:
        using ClassType = DistanceClosestPointsResult<Real, Vector>;
        using ParentType = DistanceContactTimeResult<Real, Vector>;
        using ImplTypePtr = ParentType::ImplTypePtr;

    public:
        DistanceClosestPointsResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector GetLhsClosestPoint(int index) const noexcept override;
        [[nodiscard]] const Vector GetRhsClosestPoint(int index) const noexcept override;

        [[nodiscard]] int GetLhsClosestPointSize() const noexcept override;
        [[nodiscard]] int GetRhsClosestPointSize() const noexcept override;

        [[nodiscard]] ImplTypePtr Clone() const override;

    private:
        static constexpr auto sm_PointSize = 1;

    private:
        Vector m_LhsClosestPoint;
        Vector m_RhsClosestPoint;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H
