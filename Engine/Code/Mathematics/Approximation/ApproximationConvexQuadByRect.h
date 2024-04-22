/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 16:51)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONVEX_QUAD_BY_RECT_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONVEX_QUAD_BY_RECT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Primitives/OrientedBox.h"

/// 矩形与近似矩形的凸四边形的最小二乘拟合。该算法在中进行了描述。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationConvexQuadByRect
    {
    public:
        using ClassType = ApproximationConvexQuadByRect<Real>;

        using Math = Math<Real>;
        using Vector2 = Algebra::Vector2<Real>;
        using OrientedBox2 = Algebra::OrientedBox2<Real>;

    public:
        ApproximationConvexQuadByRect() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static OrientedBox2 Fit(const std::array<Vector2, 4>& p);
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONVEX_QUAD_BY_RECT_H
