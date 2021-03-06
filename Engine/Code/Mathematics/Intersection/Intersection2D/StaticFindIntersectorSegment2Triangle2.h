///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 17:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Triangle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorSegment2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Segment2 = Segment2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment2 GetSegment() const noexcept;
        [[nodiscard]] const Triangle2 GetTriangle() const noexcept;

        /// 相交集。 如果线段和三角形不相交，则GetQuantity() 返回0，在这种情况下，相交类型为IT_EMPTY。
        /// 如果线段和三角形在单个点上相交，则GetQuantity() 返回1，在这种情况下，相交类型为IT_POINT，而GetPoint()返回相交点。
        /// 如果段和三角形在段中相交，则GetQuantity() 返回2，在这种情况下，相交类型为IT_SEGMENT，而GetPoint()返回段端点。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        void Find();

        Segment2 m_Segment;
        Triangle2 m_Triangle;

        int m_Quantity;
        Vector2D m_Point0;
        Vector2D m_Point1;
    };

    using FloatStaticFindIntersectorSegment2Triangle2 = StaticFindIntersectorSegment2Triangle2<float>;
    using DoubleStaticFindIntersectorSegment2Triangle2 = StaticFindIntersectorSegment2Triangle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H
