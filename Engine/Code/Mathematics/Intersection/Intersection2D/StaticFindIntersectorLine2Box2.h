///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorLine2Box2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorLine2Box2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;
        using Vector2 = Vector2<Real>;
        using Line2 = Line2<Real>;
        using Box2 = Box2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine2Box2(const Line2& line, const Box2& box, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line2 GetLine() const noexcept;
        NODISCARD Box2 GetBox() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        void Find();

    private:
        Line2 line;
        Box2 box;

        int quantity;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_H
