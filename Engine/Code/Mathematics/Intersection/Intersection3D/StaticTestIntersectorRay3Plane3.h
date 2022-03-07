///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 21:37)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorRay3Plane3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorRay3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Ray3 = Ray3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3 GetRay() const noexcept;
        NODISCARD Plane3 GetPlane() const noexcept;

    private:
        void Test() noexcept;

    private:
        // 相交对象
        Ray3 ray;
        Plane3 plane;
    };
}

#endif  // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_H
