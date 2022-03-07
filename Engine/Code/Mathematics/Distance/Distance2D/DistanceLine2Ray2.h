///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/21 10:56)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Ray2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistanceLine2Ray2<Real>;
        using Vector2 = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2>;
        using Ray2 = Ray2<Real>;
        using Line2 = Line2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine2Ray2(const Line2& line, const Ray2& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Ray2 GetRay() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool) const;

    private:
        Line2 line;
        Ray2 ray;
    };

    using DistanceLine2Ray2F = DistanceLine2Ray2<float>;
    using DistanceLine2Ray2D = DistanceLine2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H
