///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:47)

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
        using Vector2Type = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2Type>;

        using Ray2Type = Ray2<Real>;
        using Line2Type = Line2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using DistanceLine2Line2ToolType = DistanceLine2Line2Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine2Ray2(const Line2Type& line, const Ray2Type& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2Type GetLine() const noexcept;
        NODISCARD Ray2Type GetRay() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPoints(const DistanceLine2Line2ToolType& tool) const;

    private:
        Line2Type line;
        Ray2Type ray;
    };

    using DistanceLine2Ray2F = DistanceLine2Ray2<float>;
    using DistanceLine2Ray2D = DistanceLine2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H
