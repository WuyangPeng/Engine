///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/17 13:37)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox2Circle2 : public DynamicIntersector<Real, Vector2D>
    {
    public:
        using ClassType = DynamicFindIntersectorBox2Circle2<Real>;
        using ParentType = DynamicIntersector<Real, Vector2D>;
        using Math = typename ParentType::Math;
        using Box2 = Box2<Real>;
        using Circle2 = Circle2<Real>;
        using Vector2D = Vector2D<Real>;

    public:
        DynamicFindIntersectorBox2Circle2(const Box2& box, const Circle2& circle, Real tmax, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box2 GetBox() const noexcept;
        [[nodiscard]] const Circle2 GetCircle() const noexcept;

        // 用于动态查找相交查询的相交集。
        [[nodiscard]] const Vector2D GetContactPoint() const noexcept;

    private:
        enum class IntersectingType
        {
            Initially = -1,
            NoIntersection = 0,
            Intersect = 1,
        };

        struct RegionInfo final
        {
            IntersectingType m_Type;
            Real m_X;
            Real m_Y;

            RegionInfo(IntersectingType type, Real x, Real y) noexcept;
            explicit RegionInfo(IntersectingType type) noexcept;
        };

        // 动态查找交叉点查询。
        void Find();

        // 支持动态查找。 如果对象最初相交，则两个函数都返回-1；如果没有相交，则返回0；如果它们在某个正时相交，则返回+1。
        [[nodiscard]] RegionInfo TestVertexRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] RegionInfo TestEdgeRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    private:
        // 要相交的对象。
        Box2 m_Box;
        Circle2 m_Circle;

        // 相交点。
        Vector2D m_ContactPoint;
    };

    using FloatDynamicFindIntersectorBox2Circle2 = DynamicFindIntersectorBox2Circle2<float>;
    using DoubleDynamicFindIntersectorBox2Circle2 = DynamicFindIntersectorBox2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H
