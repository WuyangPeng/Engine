///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/24 17:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorRay2Triangle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Ray2 = Ray2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay2Triangle2(const Ray2& ray, const Triangle2& triangle, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2 GetRay() const noexcept;
        NODISCARD Triangle2 GetTriangle() const noexcept;

        /// �ཻ���� ������ߺ������β��ཻ����GetQuantity()����0������������£��ཻ����ΪIT_EMPTY��
        /// ������ߺ��������ڵ����㴦�ཻ����GetQuantity()����1������������£��ཻ����ΪIT_POINT����GetPoint()�����ཻ�㡣
        ///  ������ߺ��������ڶ����ཻ����GetQuantity()����2������������£��ཻ����ΪIT_SEGMENT����GetPoint()���ضζ˵㡣
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        void Find();

    private:
        Ray2 ray;
        Triangle2 triangle;

        int quantity;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_H
