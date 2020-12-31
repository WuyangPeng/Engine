///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 11:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_IMPL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ellipse2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE StaticFindIntersectorEllipse2Ellipse2Impl final
    {
    public:
        using ClassType = StaticFindIntersectorEllipse2Ellipse2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Ellipse2 = Ellipse2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Intersection = std::vector<Vector2D>;
        using TransverseType = std::array<bool, 4>;

    public:
        StaticFindIntersectorEllipse2Ellipse2Impl(const Ellipse2& ellipse0, const Ellipse2& ellipse1) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Ellipse2 GetEllipse0() const noexcept;
        [[nodiscard]] const Ellipse2 GetEllipse1() const noexcept;

        void AddIntersection(const Vector2D& point, bool transverse);

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Ellipse2 GetIntersectionEllipse() const noexcept;
        [[nodiscard]] bool IsTransverseIntersection(int index) const;

        [[nodiscard]] int GetDigitsAccuracy() const noexcept;

    private:
        // 要相交的对象。
        Ellipse2 m_Ellipse0;
        Ellipse2 m_Ellipse1;

        // 相交点。
        Intersection m_Point;
        TransverseType m_Transverse;

        // 求根的准确性位数。 默认值为10。
        int m_DigitsAccuracy;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_IMPL_H
