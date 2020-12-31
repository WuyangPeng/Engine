///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 15:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Triangle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLine() const noexcept;
        [[nodiscard]] const Triangle2 GetTriangle() const noexcept;

    private:
        void Test();

        Line2 m_Line;
        Triangle2 m_Triangle;
    };

    using FloatStaticTestIntersectorLine2Triangle2 = StaticTestIntersectorLine2Triangle2<float>;
    using DoubleStaticTestIntersectorLine2Triangle2 = StaticTestIntersectorLine2Triangle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_H
