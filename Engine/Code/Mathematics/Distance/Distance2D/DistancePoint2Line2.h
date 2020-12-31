///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 15:21)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Line2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistancePoint2Line2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Line2 = Line2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Line2(const Vector2D& point, const Line2& line) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector2D GetPoint() const noexcept;
        [[nodiscard]] const Line2 GetLine() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        Vector2D m_Point;
        Line2 m_Line;
    };

    using FloatDistancePoint2Line2 = DistancePoint2Line2<float>;
    using DoubleDistancePoint2Line2 = DistancePoint2Line2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H
