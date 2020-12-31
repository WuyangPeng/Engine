///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/17 16:28)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_IMPL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE FindIntersectorTriangle2Triangle2Impl final
    {
    public:
        using ClassType = FindIntersectorTriangle2Triangle2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Triangle2 = Triangle2<Real>;
        using Intersection = std::vector<Vector2D>;

    public:
        FindIntersectorTriangle2Triangle2Impl(const Triangle2& triangle0, const Triangle2& triangle1) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Triangle2 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle2 GetTriangle1() const noexcept;

        // 有关交集的信息。
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

        void SetPoint(const Intersection& point);
        void AddPoint(const Vector2D& point);

    private:
        // 要相交的对象。
        Triangle2 m_Triangle0;
        Triangle2 m_Triangle1;

        // 有关交集的信息。
        Intersection m_Point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_IMPL_H
