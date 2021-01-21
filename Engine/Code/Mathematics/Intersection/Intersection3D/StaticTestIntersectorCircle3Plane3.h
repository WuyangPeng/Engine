///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 15:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorCircle3Plane3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorCircle3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Circle3 = Circle3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorCircle3Plane3(const Circle3& circle, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Circle3 GetCircle() const noexcept;
        [[nodiscard]] const Plane3 GetPlane() const noexcept;

    private:
        void Test();

        Circle3 m_Circle;
        Plane3 m_Plane;
    };

    using FloatStaticTestIntersectorCircle3Plane3 = StaticTestIntersectorCircle3Plane3<float>;
    using DoubleStaticTestIntersectorCircle3Plane3 = StaticTestIntersectorCircle3Plane3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_H
