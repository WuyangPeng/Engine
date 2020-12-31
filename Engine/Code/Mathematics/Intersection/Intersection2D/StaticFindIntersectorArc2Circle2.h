///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 16:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Circle2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorArc2Circle2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorArc2Circle2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorArc2Circle2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorArc2Circle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using StaticFindIntersectorArc2Circle2Impl = StaticFindIntersectorArc2Circle2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StaticFindIntersectorArc2Circle2);

        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Arc2 GetArc() const noexcept;
        [[nodiscard]] const Circle2 GetCircle() const noexcept;

        // 相交集为静态查找相交查询。
        // m_Point.size()为0,1或2。
        // 当0 < m_Point.size()时，解释取决于相交类型。
        //   IntersectionType::Point:  m_Point 不同的相交点
        //   IntersectionType::Other:  圆弧在圆上。相交弧由GetIntersectionArc()返回。
        //   m_Point是无效的。
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Arc2 GetIntersectionArc() const;

    private:
        // 静态查找相交查询。
        void Find();

    private:
        IMPL_TYPE_DECLARE(StaticFindIntersectorArc2Circle2);
    };

    using FloatStaticFindIntersectorArc2Circle2 = StaticFindIntersectorArc2Circle2<float>;
    using DoubleStaticFindIntersectorArc2Circle2 = StaticFindIntersectorArc2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
