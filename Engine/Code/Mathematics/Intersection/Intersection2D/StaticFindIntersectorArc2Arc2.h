///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:46)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Objects2DFwd.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Arc2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorArc2Arc2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Circle2Type = Circle2<Real>;
        using Arc2Type = Arc2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorArc2Arc2(const Arc2Type& lhsArc, const Arc2Type& rhsArc, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Arc2Type GetLhsArc() const noexcept;
        NODISCARD Arc2Type GetRhsArc() const noexcept;

        // �ཻ��Ϊ��̬�����ཻ��ѯ��
        // m_Point�Ĵ�СΪ0,1��2��
        // ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
        //   IntersectionType::Point:  ��ͬ���ཻ��
        //   IntersectionType::Other:  Բ���ص��㳬��һ�㡣
        // �ཻ����GetIntersectionArc()�� m_Point����Ч�ġ�
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2Type GetPoint(int index) const;
        NODISCARD Arc2Type GetIntersectionArc() const;

    private:
        using Intersection = std::vector<Vector2Type>;

    private:
        // ��̬�����ཻ��ѯ��
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Arc2Type lhsArc;
        Arc2Type rhsArc;

        // �ཻ��
        Intersection point;
        Arc2Type intersectionArc;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
