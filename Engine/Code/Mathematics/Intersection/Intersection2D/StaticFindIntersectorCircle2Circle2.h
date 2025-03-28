///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorCircle2Circle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorCircle2Circle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Circle2Type = Circle2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;
        using Intersection = std::vector<Vector2Type>;

    public:
        StaticFindIntersectorCircle2Circle2(const Circle2Type& lhsCircle, const Circle2Type& rhsCircle, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Circle2Type GetLhsCircle() const noexcept;
        NODISCARD Circle2Type GetRhsCircle() const noexcept;

        // 相交集为静态查找相交查询。
        // m_Point.size()为0,1或2。
        // 当0 < m_Point.size()时，解释取决于相交类型。
        //   IntersectionType::Point:  m_Point 不同的相交点
        //   IntersectionType::Other:  圆是一样的。其中一个圆对象由GetIntersectionCircle返回。
        //   m_Point是无效的。
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2Type GetPoint(int index) const;
        NODISCARD Circle2Type GetIntersectionCircle() const;

    private:
        void Find();

    private:
        // 要相交的对象。
        Circle2Type lhsCircle;
        Circle2Type rhsCircle;

        // 相交点。
        Intersection point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H
