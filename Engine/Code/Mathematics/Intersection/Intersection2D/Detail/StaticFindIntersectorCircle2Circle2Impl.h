///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 16:40)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_IMPL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE StaticFindIntersectorCircle2Circle2Impl final
    {
    public:
        using ClassType = StaticFindIntersectorCircle2Circle2Impl<Real>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = Math<Real>;
        using Intersection = std::vector<Vector2D>;

    public:
        StaticFindIntersectorCircle2Circle2Impl(const Circle2& lhsCircle, const Circle2& rhsCircle) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Circle2 GetLhsCircle() const noexcept;
        [[nodiscard]] const Circle2 GetRhsCircle() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Circle2 GetIntersectionCircle() const noexcept;

        void AddIntersection(const Vector2D& point);

    private:
        // 要相交的对象。
        Circle2 m_LhsCircle;
        Circle2 m_RhsCircle;

        // 相交点。
        Intersection m_Point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_IMPL_H
