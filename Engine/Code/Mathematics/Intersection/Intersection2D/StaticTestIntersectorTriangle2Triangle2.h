///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 22:02)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorTriangle2Triangle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorTriangle2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle2 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle2 GetTriangle1() const noexcept;

    private:
        using Container = std::vector<Vector2D>;

    private:
        void Test();

        [[nodiscard]] static NumericalValueSymbol WhichSide(const Container& vertex, const Vector2D& point, const Vector2D& direction);

    private:
        Triangle2 m_Triangle0;
        Triangle2 m_Triangle1;
    };

    using FloatStaticTestIntersectorTriangle2Triangle2 = StaticTestIntersectorTriangle2Triangle2<float>;
    using DoubleStaticTestIntersectorTriangle2Triangle2 = StaticTestIntersectorTriangle2Triangle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
