///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:04)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorTriangle3Triangle3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorTriangle3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicTestIntersectorTriangle3Triangle3(const Triangle3& triangle0,
                                                 const Triangle3& triangle1,
                                                 Real tMax,
                                                 const Vector3& lhsVelocity,
                                                 const Vector3& rhsVelocity,
                                                 const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetTriangle0() const noexcept;
        NODISCARD Triangle3 GetTriangle1() const noexcept;

    private:
        void Test();

        struct IntersectInfo final
        {
            bool result;
            Real tFirst;
            Real tLast;

            IntersectInfo() noexcept;
            IntersectInfo(bool result, Real tFirst, Real tLast) noexcept;
        };

        NODISCARD static IntersectInfo TestOverlap(Real tMax, Real speed, Real uMin, Real uMax, Real vMin, Real vMax) noexcept;

        NODISCARD IntersectInfo TestOverlap(const Vector3& axis, Real tMax, const Vector3& velocity);

        NODISCARD static IntersectInfo ProjectOntoAxis(const Triangle3& triangle, const Vector3& axis);

    private:
        Triangle3 triangle0;
        Triangle3 triangle1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
