///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/23 15:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Ray2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��Ա����
        [[nodiscard]] const Line2 GetLine() const noexcept;
        [[nodiscard]] const Ray2 GetRay() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �ߺ����߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �ߺ������ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = INT_MAX:  �ߺ��������ص��ġ�GetIntersection() ����IntersectionType::Line��
        [[nodiscard]] int GetQuantity() const noexcept;

    private:
        // ��̬�ཻ���Ҳ�ѯ��
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Line2 m_Line;
        Ray2 m_Ray;

        // �ཻ����Ϣ
        int m_Quantity;
    };

    using FloatStaticTestIntersectorLine2Ray2 = StaticTestIntersectorLine2Ray2<float>;
    using DoubleStaticTestIntersectorLine2Ray2 = StaticTestIntersectorLine2Ray2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
