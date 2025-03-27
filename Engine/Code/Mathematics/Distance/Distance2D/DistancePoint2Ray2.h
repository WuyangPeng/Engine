///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:48)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Ray2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistancePoint2Ray2<Real>;
        using Vector2 = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2>;

        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Ray2(const Vector2& point, const Ray2& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2 GetPoint() const noexcept;
        NODISCARD Ray2 GetRay() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const override;

    private:
        Vector2 point;
        Ray2 ray;
    };

    using DistancePoint2Ray2F = DistancePoint2Ray2<float>;
    using DistancePoint2Ray2D = DistancePoint2Ray2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
