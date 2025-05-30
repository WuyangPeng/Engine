///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorSegment2Triangle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorSegment2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Segment2Type = Segment2<Real>;
        using Triangle2Type = Triangle2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorSegment2Triangle2(const Segment2Type& segment, const Triangle2Type& triangle, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment2Type GetSegment() const noexcept;
        NODISCARD Triangle2Type GetTriangle() const noexcept;

        /// 相交集。 如果线段和三角形不相交，则GetQuantity() 返回0，在这种情况下，相交类型为IT_EMPTY。
        /// 如果线段和三角形在单个点上相交，则GetQuantity() 返回1，在这种情况下，相交类型为IT_POINT，而GetPoint()返回相交点。
        /// 如果段和三角形在段中相交，则GetQuantity() 返回2，在这种情况下，相交类型为IT_SEGMENT，而GetPoint()返回段端点。
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Segment2Type segment;
        Triangle2Type triangle;

        int quantity;
        Vector2Type point0;
        Vector2Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H
