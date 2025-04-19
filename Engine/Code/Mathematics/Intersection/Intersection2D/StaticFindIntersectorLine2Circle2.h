///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Circle2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Circle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Circle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Line2Type = Line2<Real>;
        using Circle2Type = Circle2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine2Circle2(const Line2Type& line, const Circle2Type& circle, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2Type GetLine() const noexcept;
        NODISCARD Circle2Type GetCircle() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Line2Type line;
        Circle2Type circle;

        int quantity;
        Vector2Type point0;
        Vector2Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H
