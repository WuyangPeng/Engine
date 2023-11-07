///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Ray2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorRay2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2 GetLhsRay() const noexcept;
        NODISCARD Ray2 GetRhsRay() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: ���߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �����ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = 2: �������ص������ཻ���߶Ρ� �������ֻ������D1 = -D0��
        //          GetIntersection()����IntersectionType::Segment��
        //   q = INT_MAX:  �������ص������ཻ�����ߡ�
        //                 �������ֻ������D1 = D0��
        //                 GetIntersection()����IntersectionType::Ray��
        NODISCARD int GetQuantity() const noexcept;

    private:
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Ray2 lhsRay;
        Ray2 rhsRay;

    private:
        // �ཻ��
        int quantity;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
