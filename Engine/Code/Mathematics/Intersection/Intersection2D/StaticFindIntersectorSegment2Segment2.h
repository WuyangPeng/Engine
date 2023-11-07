///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Segment2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorSegment2Segment2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment2 GetLhsSegment() const noexcept;
        NODISCARD Segment2 GetRhsSegment() const noexcept;

        // �ཻ����ʹ���߶ε�����-��Χ��ʽ��
        // ����Ӷ˵㣨Vector2<Real>����ʼ������ Segment2<Real>����
        // ������-��Χ��ʽ��ת�����ܰ���С������������
        // �����ཻһ���˵�������߶εĽ�����������������������ʧ�ܡ�
        // Ϊ�ˣ�������ָ��һ��С������ֵ����΢�Ŵ��߶εļ���� Ĭ��ֵΪ�㡣
        NODISCARD Real GetIntervalThreshold() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �߶β��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �߶��ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //          �����ཻ��ʹ��GetPoint(0)��
        //   q = 2: �߶����ص������ཻ���߶Ρ�
        //          GetIntersection()����IntersectionType::Segment��
        //          �����ཻ�߶��յ�ʹ��GetPoint(0)��GetPoint(1)��
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        // ��̬�����ཻ��ѯ��
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Segment2 lhsSegment;
        Segment2 rhsSegment;

        // �ཻ��
        int quantity;

        Real intervalThreshold;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_SEGMENT2_H
