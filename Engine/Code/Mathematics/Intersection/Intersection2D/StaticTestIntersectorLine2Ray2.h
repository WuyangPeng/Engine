///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/25 10:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Ray2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 成员访问
        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Ray2 GetRay() const noexcept;

        // 相交集。让 q = GetQuantity()。情况是：
        //   q = 0: 线和射线不相交， GetIntersection() 返回IntersectionType::Empty。
        //   q = 1: 线和射线相交于一个点。GetIntersection()返回IntersectionType::Point。
        //   q = INT_MAX:  线和射线是重叠的。GetIntersection() 返回IntersectionType::Line。
        NODISCARD int GetQuantity() const noexcept;

    private:
        // 静态相交查找查询。
        void Test();

    private:
        // 要相交的对象。
        Line2 line;
        Ray2 ray;

        // 相交集信息
        int quantity;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
