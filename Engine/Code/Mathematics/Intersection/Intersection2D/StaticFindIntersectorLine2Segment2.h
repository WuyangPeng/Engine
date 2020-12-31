///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/22 10:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Segment2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Segment2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Line2 = Line2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine2Segment2(const Line2& line, const Segment2& segment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::GetValue(0));

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
        //          �����ཻ��ʹ��GetPoint(0)��
        //   q = 2: ֱ��-�߶����ص������ཻ���߶Ρ�
        //          GetIntersection()����IntersectionType::Segment��
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector2D GetPoint() const;

    private:
        // ��̬�����ཻ��ѯ��
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Line2 m_Line;
        Segment2 m_Segment;

        // �ཻ��
        int m_Quantity;

        Real m_IntervalThreshold;
        Vector2D m_Point;
    };

    using FloatStaticFindIntersectorLine2Segment2 = StaticFindIntersectorLine2Segment2<float>;
    using DoubleStaticFindIntersectorLine2Segment2 = StaticFindIntersectorLine2Segment2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_H
