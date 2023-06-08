///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Segment2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Segment2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Ray2 = Ray2<Real>;
        using Segment2 = Segment2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay2Segment2(const Ray2& ray, const Segment2& segment, const Real dotThreshold = Math::GetZeroTolerance(), const Real intervalThreshold = Math::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2 GetRay() const noexcept;
        NODISCARD Segment2 GetSegment() const noexcept;

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
        Ray2 ray;
        Segment2 segment;

        // �ཻ��
        int quantity;

        Real intervalThreshold;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_H
