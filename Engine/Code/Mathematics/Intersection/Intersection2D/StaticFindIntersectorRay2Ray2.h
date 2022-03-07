///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/24 16:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Ray2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay2Ray2(const Ray2& lhsRay, const Ray2& rhsRay, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2 GetLhsRay() const noexcept;
        NODISCARD Ray2 GetRhsRay() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: ���߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �����ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //          �����ཻ��ʹ��GetPoint(0)��
        //   q = 2: �������ص������ཻ���߶Ρ� �������ֻ������D1 = -D0��
        //          GetIntersection()����IntersectionType::Segment��
        //          �����ཻ�߶��յ�ʹ��GetPoint(0)��GetPoint(1)��
        //   q = INT_MAX:  �������ص������ཻ�����ߡ�
        //                 �������ֻ������D1 = D0��
        //                 GetIntersection()����IntersectionType::Ray��
        //          �����ཻ���ԭ��ʹ��GetPoint(0)��

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Ray2 lhsRay;
        Ray2 rhsRay;

        // �ཻ��
        int quantity;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_RAY2_H
