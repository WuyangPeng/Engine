///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 21:45)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment2Segment2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistanceSegment2Segment2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment2 GetLhsSegment() const noexcept;
        [[nodiscard]] const Segment2 GetRhsSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsLhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;

    private:
        Segment2 m_LhsSegment;
        Segment2 m_RhsSegment;
    };

    using FloatDistanceSegment2Segment2 = DistanceSegment2Segment2<float>;
    using DoubleDistanceSegment2Segment2 = DistanceSegment2Segment2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_H
