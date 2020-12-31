///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 15:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Box2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorRay2Box2<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Ray2 = Ray2<Real>;
        using Box2 = Box2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorRay2Box2(const Ray2& ray, const Box2& box, const Real dotThreshold = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray2 GetRay() const noexcept;
        [[nodiscard]] const Box2 GetBox() const noexcept;

    private:
        void Test();

        Ray2 m_Ray;
        Box2 m_Box;
    };

    using FloatStaticTestIntersectorRay2Box2 = StaticTestIntersectorRay2Box2<float>;
    using DoubleStaticTestIntersectorRay2Box2 = StaticTestIntersectorRay2Box2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_H
