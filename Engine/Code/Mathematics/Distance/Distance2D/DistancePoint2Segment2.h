///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:48)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Segment2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistancePoint2Segment2<Real>;
        using Vector2 = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2>;

        using Segment2 = Segment2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Segment2(const Vector2& point, const Segment2& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2 GetPoint() const noexcept;
        NODISCARD Segment2 GetSegment() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const override;

    private:
        Vector2 point;
        Segment2 segment;
    };

    using DistancePoint2Segment2F = DistancePoint2Segment2<float>;
    using DistancePoint2Segment2D = DistancePoint2Segment2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H
