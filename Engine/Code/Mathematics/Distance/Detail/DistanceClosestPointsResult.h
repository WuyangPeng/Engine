///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H
#define MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceContactTimeResult.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceClosestPointsResult : public DistanceContactTimeResult<Real, Vector>
    {
    public:
        using ClassType = DistanceClosestPointsResult<Real, Vector>;
        using ParentType = DistanceContactTimeResult<Real, Vector>;
        using ImplTypeSharedPtr = typename ParentType::ImplTypeSharedPtr;

    public:
        DistanceClosestPointsResult(Real distance, Real contactTime, const Vector& lhsClosestPoint, const Vector& rhsClosestPoint) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector GetLhsClosestPoint(int index) const noexcept override;
        NODISCARD Vector GetRhsClosestPoint(int index) const noexcept override;

        NODISCARD int GetLhsClosestPointSize() const noexcept override;
        NODISCARD int GetRhsClosestPointSize() const noexcept override;

        NODISCARD ImplTypeSharedPtr Clone() const override;

    private:
        static constexpr auto pointSize = 1;

    private:
        Vector lhsClosestPoint;
        Vector rhsClosestPoint;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CLOSEST_POINTS_RESULT_H
