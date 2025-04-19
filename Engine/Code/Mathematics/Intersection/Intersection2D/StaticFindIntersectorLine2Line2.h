///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Line2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Line2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Line2Type = Line2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine2Line2(const Line2Type& lhsLine, const Line2Type& rhsLine, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2Type GetLhsLine() const noexcept;
        NODISCARD Line2Type GetRhsLine() const noexcept;

        // �ཻ������ q = GetQuantity()������ǣ�
        //   q = 0: �߲��ཻ�� GetIntersection() ����IntersectionType::Empty��
        //   q = 1: ���ཻ��һ���㡣GetIntersection()����IntersectionType::Point��
        //          �����ཻ��ʹ��GetPoint()��
        //   q = INT_MAX:  �����ص��ġ�GetIntersection() ����IntersectionType::Line��
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2Type GetPoint() const;

    private:
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Line2Type lhsLine;
        Line2Type rhsLine;

        // �ཻ��
        int quantity;
        Vector2Type point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_LINE2_H
