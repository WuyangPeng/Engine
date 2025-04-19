///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:48)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Line2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistancePoint2Line2<Real>;
        using Vector2Type = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2Type>;

        using Line2Type = Line2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint2Line2(const Vector2Type& point, const Line2Type& line) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2Type GetPoint() const noexcept;
        NODISCARD Line2Type GetLine() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const override;

    private:
        Vector2Type point;
        Line2Type line;
    };

    using DistancePoint2Line2F = DistancePoint2Line2<float>;
    using DistancePoint2Line2D = DistancePoint2Line2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H
