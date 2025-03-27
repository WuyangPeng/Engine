///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorTriangle2Triangle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorTriangle2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using MathType = typename ParentType::MathType;
        using Vector2 = Vector2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        StaticFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle2 GetTriangle0() const noexcept;
        NODISCARD Triangle2 GetTriangle1() const noexcept;

        NODISCARD int GetQuantity() const;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        using Intersection = std::vector<Vector2>;

    private:
        void Find();

        static Intersection ClipConvexPolygonAgainstLine(const Vector2& axis, Real dot, const Intersection& intersection);

    private:
        // Ҫ�ཻ�Ķ���
        Triangle2 triangle0;
        Triangle2 triangle1;

        // �йؽ�������Ϣ��
        Intersection point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
