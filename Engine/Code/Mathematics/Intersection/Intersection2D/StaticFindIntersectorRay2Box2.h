///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorRay2Box2 : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticFindIntersectorRay2Box2<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Ray2 = Ray2<Real>;
        using Box2 = Box2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorRay2Box2(const Ray2& ray, const Box2& box, const Real dotThreshold = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2 GetRay() const noexcept;
        NODISCARD Box2 GetBox() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector2 GetPoint(int index) const;

    private:
        void Find();

    private:
        Ray2 ray;
        Box2 box;

        int quantity;
        Vector2 point0;
        Vector2 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_BOX2_H
