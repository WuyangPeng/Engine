///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 21:45)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay2Segment2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistanceRay2Segment2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Ray2 = Ray2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay2Segment2(const Ray2& ray, const Segment2& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetRay() const noexcept;
        [[nodiscard]] const Segment2 GetSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;

    private:
        Ray2 m_Ray;
        Segment2 m_Segment;
    };

    using FloatDistanceRay2Segment2 = DistanceRay2Segment2<float>;
    using DoubleDistanceRay2Segment2 = DistanceRay2Segment2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H
