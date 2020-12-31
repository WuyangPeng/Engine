///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 19:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Box2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorBox2Box2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorBox2Box2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Box2 = Box2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorBox2Box2(const Box2& lhsBox, const Box2& rhsBox, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box2 GetLhsBox() const noexcept;
        [[nodiscard]] const Box2 GetRhsBox() const noexcept;

    private:
        // 静态查找相交查询。
        void Test();

    private:
        // 要相交的对象。
        Box2 m_LhsBox;
        Box2 m_RhsBox;
    };

    using FloatStaticTestIntersectorBox2Box2 = StaticTestIntersectorBox2Box2<float>;
    using DoubleStaticTestIntersectorBox2Box2 = StaticTestIntersectorBox2Box2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_H
