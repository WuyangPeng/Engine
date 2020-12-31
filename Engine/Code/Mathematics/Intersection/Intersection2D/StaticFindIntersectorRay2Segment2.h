///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 15:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Segment2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Segment2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Ray2 = Ray2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetRay() const noexcept;
        [[nodiscard]] const Segment2 GetSegment() const noexcept;

        // 相交测试使用线段的中心-范围形式。
        // 如果从端点（Vector2D<Real>）开始并创建 Segment2<Real>对象，
        // 则到中心-范围格式的转换可能包含小的数字舍入误差。
        // 测试相交一个端点的两个线段的交集可能由于舍入误差而导致失败。
        // 为此，您可以指定一个小的正阈值，稍微放大线段的间隔。 默认值为零。
        [[nodiscard]] Real GetIntervalThreshold() const noexcept;

        // 相交集。让 q = GetQuantity()。情况是：
        //   q = 0: 线段不相交， GetIntersection() 返回IntersectionType::Empty。
        //   q = 1: 线段相交于一个点。GetIntersection()返回IntersectionType::Point。
        //          访问相交点使用GetPoint(0)。
        //   q = 2: 线段是重叠的且相交是线段。
        //          GetIntersection()返回IntersectionType::Segment。
        //          访问相交线段终点使用GetPoint(0)和GetPoint(1)。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        // 静态查找相交查询。
        void Find();

    private:
        // 要相交的对象。
        Ray2 m_Ray;
        Segment2 m_Segment;

        // 相交集
        int m_Quantity;

        Real m_IntervalThreshold;
        Vector2D m_Point0;
        Vector2D m_Point1;
    };

    using FloatStaticFindIntersectorRay2Segment2 = StaticFindIntersectorRay2Segment2<float>;
    using DoubleStaticFindIntersectorRay2Segment2 = StaticFindIntersectorRay2Segment2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_H
