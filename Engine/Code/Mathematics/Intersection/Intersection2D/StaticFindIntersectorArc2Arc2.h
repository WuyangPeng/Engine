///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Objects2DFwd.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Arc2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorArc2Arc2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Circle2Type = Circle2<Real>;
        using Arc2Type = Arc2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorArc2Arc2(const Arc2Type& lhsArc, const Arc2Type& rhsArc, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Arc2Type GetLhsArc() const noexcept;
        NODISCARD Arc2Type GetRhsArc() const noexcept;

        // 相交集为静态查找相交查询。
        // m_Point的大小为0,1或2。
        // 当0 < m_Point.size()时，解释取决于相交类型。
        //   IntersectionType::Point:  不同的相交点
        //   IntersectionType::Other:  圆弧重叠点超过一点。
        // 相交弧由GetIntersectionArc()。 m_Point是无效的。
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2Type GetPoint(int index) const;
        NODISCARD Arc2Type GetIntersectionArc() const;

    private:
        using Intersection = std::vector<Vector2Type>;

    private:
        // 静态查找相交查询。
        void Find();

    private:
        // 要相交的对象。
        Arc2Type lhsArc;
        Arc2Type rhsArc;

        // 相交集
        Intersection point;
        Arc2Type intersectionArc;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
