///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 15:41)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_IMPL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE StaticFindIntersectorArc2Circle2Impl final
    {
    public:
        using ClassType = StaticFindIntersectorArc2Circle2Impl<Real>;

        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = Math<Real>;
        using Intersection = std::vector<Vector2D>;

    public:
        StaticFindIntersectorArc2Circle2Impl(const Arc2& arc, const Circle2& circle) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Arc2 GetArc() const noexcept;
        [[nodiscard]] const Circle2 GetCircle() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Arc2 GetIntersectionArc() const noexcept;

        void AddIntersection(const Vector2D& point);

    private:
        // 要相交的对象。
        Arc2 m_Arc;
        Circle2 m_Circle;

        // 相交集
        Intersection m_Point;
    };

}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_IMPL_H
