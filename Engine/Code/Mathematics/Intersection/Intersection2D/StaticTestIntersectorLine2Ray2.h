///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/25 10:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Ray2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��Ա����
        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Ray2 GetRay() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �ߺ����߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �ߺ������ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = INT_MAX:  �ߺ��������ص��ġ�GetIntersection() ����IntersectionType::Line��
        NODISCARD int GetQuantity() const noexcept;

    private:
        // ��̬�ཻ���Ҳ�ѯ��
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Line2 line;
        Ray2 ray;

        // �ཻ����Ϣ
        int quantity;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_RAY2_H
