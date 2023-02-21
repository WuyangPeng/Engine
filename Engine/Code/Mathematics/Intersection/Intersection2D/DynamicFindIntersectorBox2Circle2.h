///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 14:33)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Circle2.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorBox2Circle2 : public DynamicIntersector<Real, Vector2>
    {
    public:
        using ClassType = DynamicFindIntersectorBox2Circle2<Real>;
        using ParentType = DynamicIntersector<Real, Vector2>;
        using Math = typename ParentType::Math;
        using Box2 = Box2<Real>;
        using Circle2 = Circle2<Real>;
        using Vector2 = Vector2<Real>;

    public:
        DynamicFindIntersectorBox2Circle2(const Box2& box, const Circle2& circle, Real tmax, const Vector2& lhsVelocity, const Vector2& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box2 GetBox() const noexcept;
        NODISCARD Circle2 GetCircle() const noexcept;

        // 用于动态查找相交查询的相交集。
        NODISCARD Vector2 GetContactPoint() const noexcept;

    private:
        enum class IntersectingType
        {
            Initially = -1,
            NoIntersection = 0,
            Intersect = 1,
        };

        struct RegionInfo final
        {
            IntersectingType type;
            Real x;
            Real y;

            RegionInfo(IntersectingType type, Real x, Real y) noexcept;
            explicit RegionInfo(IntersectingType type) noexcept;
        };

        // 动态查找交叉点查询。
        void Find();

        // 支持动态查找。 如果对象最初相交，则两个函数都返回-1；如果没有相交，则返回0；如果它们在某个正时相交，则返回+1。
        NODISCARD RegionInfo TestVertexRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD RegionInfo TestEdgeRegion(Real centerDotX, Real centerDotY, Real velocityDotX, Real velocityDotY, Real extent0, Real extent1) noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        // 要相交的对象。
        Box2 box;
        Circle2 circle;

        // 相交点。
        Vector2 contactPoint;
    };

    using DynamicFindIntersectorBox2Circle2F = DynamicFindIntersectorBox2Circle2<float>;
    using DynamicFindIntersectorBox2Circle2D = DynamicFindIntersectorBox2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H
