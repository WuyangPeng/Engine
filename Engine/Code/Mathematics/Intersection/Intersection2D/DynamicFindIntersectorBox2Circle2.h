///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:46)

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

        using MathType = typename ParentType::MathType;
        using Box2Type = Box2<Real>;
        using Circle2Type = Circle2<Real>;
        using Vector2Type = Vector2<Real>;

    public:
        DynamicFindIntersectorBox2Circle2(const Box2Type& box, const Circle2Type& circle, Real tmax, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box2Type GetBox() const noexcept;
        NODISCARD Circle2Type GetCircle() const noexcept;

        // 用于动态查找相交查询的相交集。
        NODISCARD Vector2Type GetContactPoint() const noexcept;

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
        Box2Type box;
        Circle2Type circle;

        // 相交点。
        Vector2Type contactPoint;
    };

    using DynamicFindIntersectorBox2Circle2F = DynamicFindIntersectorBox2Circle2<float>;
    using DynamicFindIntersectorBox2Circle2D = DynamicFindIntersectorBox2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H
