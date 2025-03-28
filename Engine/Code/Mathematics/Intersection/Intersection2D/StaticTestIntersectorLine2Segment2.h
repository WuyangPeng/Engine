///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Segment2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Segment2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorLine2Segment2(const Line2& line, const Segment2& segment, const Real dotThreshold = MathType::GetZeroTolerance(), const Real intervalThreshold = MathType::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Segment2 GetSegment() const noexcept;

        // 相交测试使用线段的中心-范围形式。
        // 如果从端点（Vector2Type<Real>）开始并创建 Segment2<Real>对象，
        // 则到中心-范围格式的转换可能包含小的数字舍入误差。
        // 测试相交一个端点的两个线段的交集可能由于舍入误差而导致失败。
        // 为此，您可以指定一个小的正阈值，稍微放大线段的间隔。 默认值为零。
        NODISCARD Real GetIntervalThreshold() const noexcept;

        // 相交集。让 q = GetQuantity()。情况是：
        //   q = 0: 直线-线段不相交， GetIntersection() 返回IntersectionType::Empty。
        //   q = 1: 直线-线段相交于一个点。GetIntersection()返回IntersectionType::Point。
        //   q = 2: 直线-线段是重叠的且相交是线段。
        //          GetIntersection()返回IntersectionType::Segment。
        NODISCARD int GetQuantity() const noexcept;

    private:
        // 静态查找相交查询。
        void Test();

    private:
        // 要相交的对象。
        Line2 line;
        Segment2 segment;

        // 相交集
        int quantity;

        Real intervalThreshold;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H
