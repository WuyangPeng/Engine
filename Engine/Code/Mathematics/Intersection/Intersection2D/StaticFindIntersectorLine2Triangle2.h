///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Triangle2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorLine2Triangle2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Triangle2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2Type = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Triangle2 = Triangle2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Triangle2 GetTriangle() const noexcept;

        /// �ཻ���� ���ֱ�ߺ������β��ཻ���� GetQuantity()����0������������£��ཻ����ΪIT_EMPTY��
        /// ���ֱ�ߺ��������ڵ��������ཻ���� GetQuantity()����1������������£��ཻ����ΪIT_POINT����GetPoint() �����ཻ�㡣
        /// ���ֱ�ߺ��������ڶ����ཻ����GetQuantity()����2������������£��ཻ����ΪIT_SEGMENT����GetPoint() ���ضζ˵㡣
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Line2 line;
        Triangle2 triangle;

        int quantity;
        Vector2Type point0;
        Vector2Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_H
