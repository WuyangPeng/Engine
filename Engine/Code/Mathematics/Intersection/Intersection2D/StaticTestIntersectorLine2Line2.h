///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Line2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Line2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLhsLine() const noexcept;
        NODISCARD Line2 GetRhsLine() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: ���ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = INT_MAX:  �����ص��ġ�GetIntersection() ����IntersectionType::Line��
        NODISCARD int GetQuantity() const noexcept;

    private:
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Line2 lhsLine;
        Line2 rhsLine;

        // �ཻ��
        int quantity;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H
