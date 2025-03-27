///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorTriangle2Triangle2 : public DynamicIntersector<Real, Vector2>
    {
    public:
        using ClassType = DynamicTestIntersectorTriangle2Triangle2<Real>;
        using ParentType = DynamicIntersector<Real, Vector2>;

        using MathType = typename ParentType::MathType;
        using Vector2 = Vector2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        DynamicTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2& velocity0, const Vector2& velocity1, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle2 GetTriangle0() const noexcept;
        NODISCARD Triangle2 GetTriangle1() const noexcept;

    private:
        using Intersection = std::vector<Vector2>;
        static constexpr auto size = 3;

    private:
        void Test();

        enum class SideType
        {
            None = 0,
            Left = -1,
            Right = +1,
        };

        enum class ProjectionMap
        {
            M21,  // 2个顶点映射到最小值，1个顶点映射到最大值
            M12,  // 1个顶点映射到最小值，2个顶点映射到最大值
            M11  // 1个顶点映射到最小值，1个顶点映射到最大值
        };

        class Configuration final
        {
        public:
            using IndexContainer = std::array<int, size>;

            ProjectionMap projectionMap;  // 顶点如何映射到投影间隔
            IndexContainer index;  // 顶点的排序索引

            // 间隔是 [min,max]
            Real min;
            Real max;
        };

        struct IntersectInfo final
        {
            bool result;
            SideType side;
            Configuration tCfg0;
            Configuration tCfg1;
            Real tFirst;
            Real tLast;

            IntersectInfo() noexcept;
            IntersectInfo(bool result, SideType side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept;
        };

        NODISCARD Configuration ComputeTwo(const Intersection& vertex, const Vector2& axis, int i0, int i1, int i2);

        NODISCARD Configuration ComputeThree(const Intersection& vertex, const Vector2& axis, const Vector2& point);

        NODISCARD static IntersectInfo NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept;

    private:
        Triangle2 triangle0;
        Triangle2 triangle1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
