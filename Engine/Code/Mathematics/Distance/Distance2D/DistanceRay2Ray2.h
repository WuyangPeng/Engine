///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/21 11:15)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay2Ray2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistanceRay2Ray2<Real>;
        using Vector2 = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2>;
        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2 GetLhsRay() const noexcept;
        NODISCARD Ray2 GetRhsRay() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine2Line2Tool& tool) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine2Line2Tool& tool) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine2Line2Tool& tool) const;

    private:
        Ray2 lhsRay;
        Ray2 rhsRay;
    };

    using DistanceRay2Ray2F = DistanceRay2Ray2<float>;
    using DistanceRay2Ray2D = DistanceRay2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H
