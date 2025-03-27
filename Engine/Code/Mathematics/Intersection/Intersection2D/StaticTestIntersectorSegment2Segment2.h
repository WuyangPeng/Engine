///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "StaticTestIntersector.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersector<Segment2<Real>, Segment2<Real>> : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersector<Segment2<Real>, Segment2<Real>>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        StaticTestIntersector(const Segment2& lhsSegment, const Segment2& rhsSegment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment2 GetLhsSegment() const noexcept;
        NODISCARD Segment2 GetRhsSegment() const noexcept;

        // �ཻ����ʹ���߶ε�����-��Χ��ʽ��
        // ����Ӷ˵㣨Vector2Type<Real>����ʼ������ Segment2<Real>����
        // ������-��Χ��ʽ��ת�����ܰ���С������������
        // �����ཻһ���˵�������߶εĽ�����������������������ʧ�ܡ�
        // Ϊ�ˣ�������ָ��һ��С������ֵ����΢�Ŵ��߶εļ���� Ĭ��ֵΪ�㡣
        NODISCARD Real GetIntervalThreshold() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �߶β��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �߶��ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //   q = 2: �߶����ص������ཻ���߶Ρ�
        //          GetIntersection()����IntersectionType::Segment��
        NODISCARD int GetQuantity() const noexcept;

    private:
        // ��̬�����ཻ��ѯ��
        void Test();

    private:
        // Ҫ�ཻ�Ķ���
        Segment2 lhsSegment;
        Segment2 rhsSegment;

        // �ཻ��
        int quantity;

        Real intervalThreshold;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_SEGMENT2_H
