///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 15:40)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorSphere3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicTestIntersectorSphere3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax,
                                             const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere0() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere1() const noexcept;

    private:
        void Test();

    private:
        Sphere3 m_Sphere0;
        Sphere3 m_Sphere1;
    };

    using FloatDynamicTestIntersectorSphere3Sphere3 = DynamicTestIntersectorSphere3Sphere3<float>;
    using DoubleDynamicTestIntersectorSphere3Sphere3 = DynamicTestIntersectorSphere3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
