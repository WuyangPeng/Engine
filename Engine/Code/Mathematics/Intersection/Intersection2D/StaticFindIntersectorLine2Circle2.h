///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 18:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Circle2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Circle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Circle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Circle2 = Circle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine2Circle2(const Line2& line, const Circle2& circle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLine() const noexcept;
        [[nodiscard]] const Circle2 GetCircle() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        void Find();

        Line2 m_Line;
        Circle2 m_Circle;

        int m_Quantity;
        Vector2D m_Point0;
        Vector2D m_Point1;
    };

    using FloatStaticFindIntersectorLine2Circle2 = StaticFindIntersectorLine2Circle2<float>;
    using DoubleStaticFindIntersectorLine2Circle2 = StaticFindIntersectorLine2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H
