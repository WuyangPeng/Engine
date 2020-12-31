///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 11:16)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX2_CIRCLE2_H

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorBox2Circle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorBox2Circle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Box2 = Box2<Real>;
        using Circle2 = Circle2<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorBox2Circle2(const Box2& box, const Circle2& circle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box2 GetBox() const noexcept;
        [[nodiscard]] const Circle2 GetCircle() const noexcept;

    private:
        // 静态查找相交查询。
        void Test();

    private:
        // 要相交的对象。
        Box2 m_Box;
        Circle2 m_Circle;
    };

    using FloatStaticTestIntersectorBox2Circle2 = StaticTestIntersectorBox2Circle2<float>;
    using DoubleStaticTestIntersectorBox2Circle2 = StaticTestIntersectorBox2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX2_CIRCLE2_H
