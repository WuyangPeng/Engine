///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 18:14)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Segment2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistanceLine2Segment2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Line2 = Line2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine2Segment2(const Line2& line, const Segment2& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLine() const noexcept;
        [[nodiscard]] const Segment2 GetSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsParallel(const DistanceLine2Line2Tool& tool) const;

    private:
        Line2 m_Line;
        Segment2 m_Segment;
    };

    using FloatDistanceLine2Segment2 = DistanceLine2Segment2<float>;
    using DoubleDistanceLine2Segment2 = DistanceLine2Segment2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_H
