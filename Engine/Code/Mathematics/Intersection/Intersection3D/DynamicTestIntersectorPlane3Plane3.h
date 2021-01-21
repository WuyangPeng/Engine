///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/14 14:45)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorPlane3Plane3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicTestIntersectorPlane3Plane3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax,
                                           const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane0() const noexcept;
        [[nodiscard]] const Plane3 GetPlane1() const noexcept;

    private:
        void Test();

    private:
        Plane3 m_Plane0;
        Plane3 m_Plane1;
    };

    using FloatDynamicTestIntersectorPlane3Plane3 = DynamicTestIntersectorPlane3Plane3<float>;
    using DoubleDynamicTestIntersectorPlane3Plane3 = DynamicTestIntersectorPlane3Plane3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_H
