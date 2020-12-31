///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 16:31)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Ray2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistanceLine2Ray2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Ray2 = Ray2<Real>;
        using Line2 = Line2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine2Ray2(const Line2& line, const Ray2& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLine() const noexcept;
        [[nodiscard]] const Ray2 GetRay() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool) const;

    private:
        Line2 m_Line;
        Ray2 m_Ray;
    };

    using FloatDistanceLine2Ray2 = DistanceLine2Ray2<float>;
    using DoubleDistanceLine2Ray2 = DistanceLine2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H
