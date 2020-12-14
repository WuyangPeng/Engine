///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 18:23)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay2Ray2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistanceRay2Ray2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Ray2 = Ray2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetLhsRay() const noexcept;
        [[nodiscard]] const Ray2 GetRhsRay() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine2Line2Tool& tool) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine2Line2Tool& tool) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine2Line2Tool& tool) const;

    private:
        Ray2 m_LhsRay;
        Ray2 m_RhsRay;
    };

    using FloatDistanceRay2Ray2 = DistanceRay2Ray2<float>;
    using DoubleDistanceRay2Ray2 = DistanceRay2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_RAY2_H
