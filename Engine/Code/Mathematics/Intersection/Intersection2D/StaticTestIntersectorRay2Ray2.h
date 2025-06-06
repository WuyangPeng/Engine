///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Ray2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorRay2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Ray2Type = Ray2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorRay2Ray2(const Ray2Type& lhsRay, const Ray2Type& rhsRay, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2Type GetLhsRay() const noexcept;
        NODISCARD Ray2Type GetRhsRay() const noexcept;

        // 相交集。让 q = GetQuantity()。情况是：
        //   q = 0: 射线不相交， GetIntersection() 返回IntersectionType::Empty。
        //   q = 1: 射线相交于一个点。GetIntersection()返回IntersectionType::Point。
        //   q = 2: 射线是重叠的且相交是线段。 这种情况只发生在D1 = -D0。
        //          GetIntersection()返回IntersectionType::Segment。
        //   q = INT_MAX:  射线是重叠的且相交是射线。
        //                 这种情况只发生在D1 = D0。
        //                 GetIntersection()返回IntersectionType::Ray。
        NODISCARD int GetQuantity() const noexcept;

    private:
        void Test();

    private:
        // 要相交的对象。
        Ray2Type lhsRay;
        Ray2Type rhsRay;

    private:
        // 相交集
        int quantity;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
