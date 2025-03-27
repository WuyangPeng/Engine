///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorCircle2Circle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorCircle2Circle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Circle2 = Circle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::MathType;
        using Intersection = std::vector<Vector2>;

    public:
        StaticFindIntersectorCircle2Circle2(const Circle2& lhsCircle, const Circle2& rhsCircle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Circle2 GetLhsCircle() const noexcept;
        NODISCARD Circle2 GetRhsCircle() const noexcept;

        // �ཻ��Ϊ��̬�����ཻ��ѯ��
        // m_Point.size()Ϊ0,1��2��
        // ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
        //   IntersectionType::Point:  m_Point ��ͬ���ཻ��
        //   IntersectionType::Other:  Բ��һ���ġ�����һ��Բ������GetIntersectionCircle���ء�
        //   m_Point����Ч�ġ�
        NODISCARD int GetQuantity() const;
        NODISCARD Vector2 GetPoint(int index) const;
        NODISCARD Circle2 GetIntersectionCircle() const;

    private:
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Circle2 lhsCircle;
        Circle2 rhsCircle;

        // �ཻ�㡣
        Intersection point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_H
