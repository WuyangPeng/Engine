///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Capsule3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorPlane3Capsule3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorPlane3Capsule3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using Capsule3 = Capsule3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorPlane3Capsule3(const Plane3& plane, const Capsule3& capsule, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetPlane() const noexcept;
        NODISCARD Capsule3 GetCapsule() const noexcept;

        NODISCARD bool CapsuleIsCulled() const noexcept;

    private:
        void Test() noexcept;

    private:
        Plane3 plane;
        Capsule3 capsule;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_H
