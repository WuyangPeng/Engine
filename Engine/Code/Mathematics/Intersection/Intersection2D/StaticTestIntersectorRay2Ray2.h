///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/23 15:43)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Ray2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorRay2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetLhsRay() const noexcept;
        [[nodiscard]] const Ray2 GetRhsRay() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: ���߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �����ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = 2: �������ص������ཻ���߶Ρ� �������ֻ������D1 = -D0��
        //          GetIntersection()����IntersectionType::Segment��
        //   q = INT_MAX:  �������ص������ཻ�����ߡ�
        //                 �������ֻ������D1 = D0��
        //                 GetIntersection()����IntersectionType::Ray��
        [[nodiscard]] int GetQuantity() const noexcept;

    private:
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Ray2 m_LhsRay;
        Ray2 m_RhsRay;

        // �ཻ��
        int m_Quantity;
    };

    using FloatStaticTestIntersectorRay2Ray2 = StaticTestIntersectorRay2Ray2<float>;
    using DoubleStaticTestIntersectorRay2Ray2 = StaticTestIntersectorRay2Ray2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_RAY2_H
