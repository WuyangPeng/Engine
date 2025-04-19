///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorTriangle2Triangle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorTriangle2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Triangle2Type = Triangle2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorTriangle2Triangle2(const Triangle2Type& triangle0, const Triangle2Type& triangle1, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle2Type GetTriangle0() const noexcept;
        NODISCARD Triangle2Type GetTriangle1() const noexcept;

    private:
        using Container = std::vector<Vector2Type>;

    private:
        void Test();

        NODISCARD static NumericalValueSymbol WhichSide(const Container& vertex, const Vector2Type& point, const Vector2Type& direction);

    private:
        Triangle2Type triangle0;
        Triangle2Type triangle1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
