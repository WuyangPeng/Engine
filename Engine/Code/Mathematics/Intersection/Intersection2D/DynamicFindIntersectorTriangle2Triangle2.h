///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorTriangle2Triangle2 : public DynamicIntersector<Real, Vector2>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle2Triangle2<Real>;
        using ParentType = DynamicIntersector<Real, Vector2>;
        using Math = typename ParentType::Math;
        using Vector2 = Vector2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        DynamicFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2& velocity0, const Vector2& velocity1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle2 GetTriangle0() const noexcept;
        NODISCARD Triangle2 GetTriangle1() const noexcept;

        // 有关交集的信息。
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        using Intersection = std::vector<Vector2>;
        static constexpr auto size = 3;
        using Vector2Container = std::array<Vector2, size>;

    private:
        enum class SideType
        {
            None = 0,
            Left = -1,
            Right = +1,
        };

        // 动态查询。
        void Find();

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

        NODISCARD Configuration ComputeThree(const Intersection& vertex, const Vector2& axis, const Vector2& vector);

        NODISCARD static IntersectInfo NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept;

        NODISCARD static Intersection GetIntersection(const Configuration& cfg0, const Configuration& cfg1, SideType side, const Vector2Container& moveV0, const Vector2Container& moveV1);

    private:
        // 要相交的对象。
        Triangle2 triangle0;
        Triangle2 triangle1;

        // 有关交集的信息。
        Intersection point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
