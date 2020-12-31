///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 14:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Arc2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Arc2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Ray2 = Ray2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay2Arc2(const Ray2& ray, const Arc2& arc, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetRay() const noexcept;
        [[nodiscard]] const Arc2 GetArc() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        void Find();

        Ray2 m_Ray;
        Arc2 m_Arc;

        int m_Quantity;
        Vector2D m_Point0;
        Vector2D m_Point1;
    };

    using FloatStaticFindIntersectorRay2Arc2 = StaticFindIntersectorRay2Arc2<float>;
    using DoubleStaticFindIntersectorRay2Arc2 = StaticFindIntersectorRay2Arc2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_ARC2_H
