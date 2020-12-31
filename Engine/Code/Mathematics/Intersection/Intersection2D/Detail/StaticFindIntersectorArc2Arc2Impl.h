///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_IMPL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Objects2DFwd.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE StaticFindIntersectorArc2Arc2Impl final
    {
    public:
        using ClassType = StaticFindIntersectorArc2Arc2Impl<Real>;
        using Vector2D = Vector2D<Real>;
        using Arc2 = Arc2<Real>;
        using Math = Math<Real>;
        using Intersection = std::vector<Vector2D>;

    public:
        StaticFindIntersectorArc2Arc2Impl(const Arc2& lhsArc, const Arc2& rhsArc) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Arc2 GetLhsArc() const noexcept;
        [[nodiscard]] const Arc2 GetRhsArc() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Arc2 GetIntersectionArc() const noexcept;

        void AddIntersection(const Vector2D& point);
        void SetIntersection(const Intersection& points);
        void SetIntersection(const Arc2& intersectionArc) noexcept;

    private:
        // 要相交的对象。
        Arc2 m_LhsArc;
        Arc2 m_RhsArc;

        // 相交集
        Intersection m_Point;
        Arc2 m_IntersectionArc;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_IMPL_H
