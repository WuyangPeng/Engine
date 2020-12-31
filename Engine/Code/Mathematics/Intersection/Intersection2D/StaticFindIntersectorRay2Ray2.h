///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 15:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Ray2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetLhsRay() const noexcept;
        [[nodiscard]] const Ray2 GetRhsRay() const noexcept;

        // 相交集。让 q = GetQuantity()。情况是：
        //   q = 0: 射线不相交， GetIntersection() 返回IntersectionType::Empty。
        //   q = 1: 射线相交于一个点。GetIntersection()返回IntersectionType::Point。
        //          访问相交点使用GetPoint(0)。
        //   q = 2: 射线是重叠的且相交是线段。 这种情况只发生在D1 = -D0。
        //          GetIntersection()返回IntersectionType::Segment。
        //          访问相交线段终点使用GetPoint(0)和GetPoint(1)。
        //   q = INT_MAX:  射线是重叠的且相交是射线。
        //                 这种情况只发生在D1 = D0。
        //                 GetIntersection()返回IntersectionType::Ray。
        //          访问相交射点原点使用GetPoint(0)。

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        void Find();

        // 要相交的对象。
        Ray2 m_LhsRay;
        Ray2 m_RhsRay;

        // 相交集
        int m_Quantity;
        Vector2D m_Point0;
        Vector2D m_Point1;
    };

    using FloatStaticFindIntersectorRay2Ray2 = StaticFindIntersectorRay2Ray2<float>;
    using DoubleStaticFindIntersectorRay2Ray2 = StaticFindIntersectorRay2Ray2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_H
