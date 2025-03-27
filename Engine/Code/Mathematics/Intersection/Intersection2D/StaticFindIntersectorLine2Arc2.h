///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Arc2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Arc2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine2Arc2(const Line2& line, const Arc2& arc, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Arc2 GetArc() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        void Find();

    private:
        Line2 line;
        Arc2 arc;

        int quantity;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_ARC2_H
