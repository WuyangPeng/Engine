///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 17:32)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Segment2 : public DistanceBase<Real, Vector2D<Real>>
    {
    public:
        using ClassType = DistancePoint2Segment2<Real>;
        using Vector2D = Vector2D<Real>;
        using ParentType = DistanceBase<Real, Vector2D>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Segment2(const Vector2D& point, const Segment2& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector2D GetPoint() const noexcept;
        [[nodiscard]] const Segment2 GetSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

    private:
        Vector2D m_Point;
        Segment2 m_Segment;
    };

    using FloatDistancePoint2Segment2 = DistancePoint2Segment2<float>;
    using DoubleDistancePoint2Segment2 = DistancePoint2Segment2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H
