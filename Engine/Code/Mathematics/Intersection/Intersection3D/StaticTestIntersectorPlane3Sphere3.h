///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 18:21)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorPlane3Sphere3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorPlane3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorPlane3Sphere3(const Plane3& plane, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetPlane() const noexcept;
        NODISCARD Sphere3 GetSphere() const noexcept;

        NODISCARD bool SphereIsCulled() const noexcept;

    private:
        void Test() noexcept;

    private:
        Plane3 plane;
        Sphere3 sphere;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_H
