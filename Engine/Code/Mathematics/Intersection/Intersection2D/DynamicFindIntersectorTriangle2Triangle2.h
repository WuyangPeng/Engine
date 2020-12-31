///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/17 16:22)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Intersection/Intersector1.h"
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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorTriangle2Triangle2 : public DynamicIntersector<Real, Vector2D>
    {
    public:
        using DynamicFindIntersectorTriangle2Triangle2Impl = FindIntersectorTriangle2Triangle2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(DynamicFindIntersectorTriangle2Triangle2);

        using ParentType = DynamicIntersector<Real, Vector2D>;
        using Math = typename ParentType::Math;
        using Vector2D = Vector2D<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        DynamicFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax, const Vector2D& velocity0, const Vector2D& velocity1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle2 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle2 GetTriangle1() const noexcept;

        // 有关交集的信息。
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;

    private:
        using Intersection = std::vector<Vector2D>;
        static constexpr auto sm_Size = 3;
        using Vector2DContainer = std::array<Vector2D, sm_Size>;

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
            using IndexContainer = std::array<int, sm_Size>;

            ProjectionMap m_Map;  // 顶点如何映射到投影间隔
            IndexContainer m_Index;  // 顶点的排序索引

            // 间隔是 [min,max]
            Real m_Min;
            Real m_Max;
        };

        struct IntersectInfo final
        {
            bool m_Result;
            SideType m_Side;
            Configuration m_TCfg0;
            Configuration m_TCfg1;
            Real m_TFirst;
            Real m_TLast;

            IntersectInfo() noexcept;
            IntersectInfo(bool result, SideType side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept;
        };

        [[nodiscard]] Configuration ComputeTwo(const Intersection& vertex, const Vector2D& axis, int i0, int i1, int i2);

        [[nodiscard]] Configuration ComputeThree(const Intersection& vertex, const Vector2D& axis, const Vector2D& point);

        [[nodiscard]] static IntersectInfo NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept;

        [[nodiscard]] static Intersection GetIntersection(const Configuration& cfg0, const Configuration& cfg1, SideType side, const Vector2DContainer& moveV0, const Vector2DContainer& moveV1);

    private:
        IMPL_TYPE_DECLARE(DynamicFindIntersectorTriangle2Triangle2);
    };

    using FloatDynamicFindIntersectorTriangle2Triangle2 = DynamicFindIntersectorTriangle2Triangle2<float>;
    using DoubleDynamicFindIntersectorTriangle2Triangle2 = DynamicFindIntersectorTriangle2Triangle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
