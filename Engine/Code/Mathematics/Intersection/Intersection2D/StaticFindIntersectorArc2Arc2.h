///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 15:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Objects2DFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Arc2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorArc2Arc2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorArc2Arc2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorArc2Arc2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorArc2Arc2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using StaticFindIntersectorArc2Arc2Impl = StaticFindIntersectorArc2Arc2Impl<Real>;
 

        TYPE_DECLARE(StaticFindIntersectorArc2Arc2);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorArc2Arc2(const Arc2& lhsArc, const Arc2& rhsArc, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Arc2 GetLhsArc() const noexcept;
        [[nodiscard]] const Arc2 GetRhsArc() const noexcept;

        // 相交集为静态查找相交查询。
        // m_Point的大小为0,1或2。
        // 当0 < m_Point.size()时，解释取决于相交类型。
        //   IntersectionType::Point:  不同的相交点
        //   IntersectionType::Other:  圆弧重叠点超过一点。
        // 相交弧由GetIntersectionArc()。 m_Point是无效的。
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Arc2 GetIntersectionArc() const;

    private:
        // 静态查找相交查询。
        void Find();

    private:
        PackageType impl;
    };

    using FloatStaticFindIntersectorArc2Arc2 = StaticFindIntersectorArc2Arc2<float>;
    using DoubleStaticFindIntersectorArc2Arc2 = StaticFindIntersectorArc2Arc2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
