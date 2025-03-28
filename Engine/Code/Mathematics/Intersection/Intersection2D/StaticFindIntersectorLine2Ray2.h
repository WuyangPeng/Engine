///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Ray2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Ray2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Ray2 = Ray2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine2Ray2(const Line2& line, const Ray2& ray, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��Ա����
        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Ray2 GetRay() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �ߺ����߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: �ߺ������ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //          �����ཻ��ʹ��GetPoint(0)��
        //   q = INT_MAX:  �ߺ��������ص��ġ�GetIntersection() ����IntersectionType::Line��
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2Type GetPoint() const;

    private:
        // ��̬�ཻ���Ҳ�ѯ��
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Line2 line;
        Ray2 ray;

        // �ཻ����Ϣ
        int quantity;
        Vector2Type point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_RAY2_H
