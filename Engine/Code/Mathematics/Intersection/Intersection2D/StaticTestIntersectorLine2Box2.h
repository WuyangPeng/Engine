///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorLine2Box2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Box2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Box2 = Box2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorLine2Box2(const Line2& line, const Box2& box, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Box2 GetBox() const noexcept;

    private:
        void Test();

    private:
        Line2 line;
        Box2 box;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_H
