///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 16:49)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Ray2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistancePoint2Ray2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Ray2 = Ray2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Ray2(const Vector2D& point, const Ray2& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector2D GetPoint() const noexcept;
        [[nodiscard]] const Ray2 GetRay() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        Vector2D m_Point;
        Ray2 m_Ray;
    };

    using FloatDistancePoint2Ray2 = DistancePoint2Ray2<float>;
    using DoubleDistancePoint2Ray2 = DistancePoint2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
