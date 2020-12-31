///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 10:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class FindIntersectorTriangle2Triangle2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle2Triangle2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle2Triangle2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle2Triangle2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorTriangle2Triangle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using StaticFindIntersectorTriangle2Triangle2Impl = FindIntersectorTriangle2Triangle2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StaticFindIntersectorTriangle2Triangle2);

        using ParentType = StaticIntersector<Real, Vector2D>;
        using Math = typename ParentType::Math;
        using Vector2D = Vector2D<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        StaticFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle2 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle2 GetTriangle1() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        using Intersection = std::vector<Vector2D>;

    private:
        void Find();

        static Intersection ClipConvexPolygonAgainstLine(const Vector2D& axis, Real dot, const Intersection& intersection);

    private:
        IMPL_TYPE_DECLARE(StaticFindIntersectorTriangle2Triangle2);
    };

    using FloatStaticFindIntersectorTriangle2Triangle2 = StaticFindIntersectorTriangle2Triangle2<float>;
    using DoubleStaticFindIntersectorTriangle2Triangle2 = StaticFindIntersectorTriangle2Triangle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
