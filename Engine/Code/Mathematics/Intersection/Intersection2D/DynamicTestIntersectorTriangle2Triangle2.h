///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:46)

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
        using Vector2Type = Vector2<Real>;
        using Triangle2Type = Triangle2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;

    public:
        DynamicTestIntersectorTriangle2Triangle2(const Triangle2Type& triangle0, const Triangle2Type& triangle1, Real tmax, const Vector2Type& velocity0, const Vector2Type& velocity1, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle2Type GetTriangle0() const noexcept;
        NODISCARD Triangle2Type GetTriangle1() const noexcept;

    private:
        using Intersection = std::vector<Vector2Type>;
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
            M21,  // 2������ӳ�䵽��Сֵ��1������ӳ�䵽���ֵ
            M12,  // 1������ӳ�䵽��Сֵ��2������ӳ�䵽���ֵ
            M11  // 1������ӳ�䵽��Сֵ��1������ӳ�䵽���ֵ
        };

        class Configuration final
        {
        public:
            using IndexContainer = std::array<int, size>;

            ProjectionMap projectionMap;  // �������ӳ�䵽ͶӰ���
            IndexContainer index;  // �������������

            // ����� [min,max]
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

        NODISCARD Configuration ComputeTwo(const Intersection& vertex, const Vector2Type& axis, int i0, int i1, int i2);

        NODISCARD Configuration ComputeThree(const Intersection& vertex, const Vector2Type& axis, const Vector2Type& point);

        NODISCARD static IntersectInfo NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed) noexcept;

    private:
        Triangle2Type triangle0;
        Triangle2Type triangle1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
