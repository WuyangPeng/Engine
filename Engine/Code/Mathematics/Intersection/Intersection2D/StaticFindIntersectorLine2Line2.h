///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 18:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Line2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Line2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLhsLine() const noexcept;
        [[nodiscard]] const Line2 GetRhsLine() const noexcept;

        // 相交集。让 q = GetQuantity()。情况是：
        //   q = 0: 线不相交， GetIntersection() 返回IntersectionType::Empty。
        //   q = 1: 线相交于一个点。GetIntersection()返回IntersectionType::Point。
        //          访问相交点使用GetPoint()。
        //   q = INT_MAX:  线是重叠的。GetIntersection() 返回IntersectionType::Line。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint() const;

    private:
        void Find();

        // 要相交的对象。
        Line2 m_LhsLine;
        Line2 m_RhsLine;

        // 相交集
        int m_Quantity;
        Vector2D m_Point;
    };

    using FloatStaticFindIntersectorLine2Line2 = StaticFindIntersectorLine2Line2<float>;
    using DoubleStaticFindIntersectorLine2Line2 = StaticFindIntersectorLine2Line2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
