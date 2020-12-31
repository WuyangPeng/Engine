///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/23 15:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Line2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Line2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine2Line2(const Line2& lhsLine, const Line2& rhsLine, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLhsLine() const noexcept;
        [[nodiscard]] const Line2 GetRhsLine() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: ���ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = INT_MAX:  �����ص��ġ�GetIntersection() ����IntersectionType::Line��
        [[nodiscard]] int GetQuantity() const noexcept;

    private:
        void Test();

        // Ҫ�ཻ�Ķ���
        Line2 m_LhsLine;
        Line2 m_RhsLine;

        // �ཻ��
        int m_Quantity;
    };

    using FloatStaticTestIntersectorLine2Line2 = StaticTestIntersectorLine2Line2<float>;
    using DoubleStaticTestIntersectorLine2Line2 = StaticTestIntersectorLine2Line2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_LINE2_H
