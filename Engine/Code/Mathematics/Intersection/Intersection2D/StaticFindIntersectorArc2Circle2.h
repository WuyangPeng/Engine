///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/23 17:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Circle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorArc2Circle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Circle2 = Circle2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;
        using Intersection = std::vector<Vector2>;

    public:
        StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Arc2 GetArc() const noexcept;
        NODISCARD Circle2 GetCircle() const noexcept;

        // �ཻ��Ϊ��̬�����ཻ��ѯ��
        // m_Point.size()Ϊ0,1��2��
        // ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
        //   IntersectionType::Point:  m_Point ��ͬ���ཻ��
        //   IntersectionType::Other:  Բ����Բ�ϡ��ཻ����GetIntersectionArc()���ء�
        //   m_Point����Ч�ġ�
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2 GetPoint(int index) const;
        NODISCARD Arc2 GetIntersectionArc() const;

    private:
        // ��̬�����ཻ��ѯ��
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Arc2 arc;
        Circle2 circle;

        // �ཻ��
        Intersection point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
