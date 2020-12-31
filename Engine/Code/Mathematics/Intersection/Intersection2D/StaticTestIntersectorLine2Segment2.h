///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/23 15:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Segment2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Segment2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine2Segment2(const Line2& line, const Segment2& segment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line2 GetLine() const noexcept;
        [[nodiscard]] const Segment2 GetSegment() const noexcept;

        // �ཻ����ʹ���߶ε�����-��Χ��ʽ��
        // ����Ӷ˵㣨Vector2D<Real>����ʼ������ Segment2<Real>����
        // ������-��Χ��ʽ��ת�����ܰ���С������������
        // �����ཻһ���˵�������߶εĽ�����������������������ʧ�ܡ�
        // Ϊ�ˣ�������ָ��һ��С������ֵ����΢�Ŵ��߶εļ���� Ĭ��ֵΪ�㡣
        [[nodiscard]] Real GetIntervalThreshold() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: ֱ��-�߶β��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: ֱ��-�߶��ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = 2: ֱ��-�߶����ص������ཻ���߶Ρ�
        //          GetIntersection()����IntersectionType::Segment��
        [[nodiscard]] int GetQuantity() const noexcept;

    private:
        // ��̬�����ཻ��ѯ��
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Line2 m_Line;
        Segment2 m_Segment;

        // �ཻ��
        int m_Quantity;

        Real m_IntervalThreshold;
    };

    using FloatStaticTestIntersectorLine2Segment2 = StaticTestIntersectorLine2Segment2<float>;
    using DoubleStaticTestIntersectorLine2Segment2 = StaticTestIntersectorLine2Segment2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_SEGMENT2_H
