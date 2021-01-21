///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/15 16:28)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorTriangle3Triangle3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicTestIntersectorTriangle3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax,
                                                 const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle1() const noexcept;

    private:
        void Test();

        struct IntersectInfo final
        {
            bool m_Result;
            Real m_TFirst;
            Real m_TLast;

            IntersectInfo() noexcept;
            IntersectInfo(bool result, Real tFirst, Real tLast) noexcept;
        };

        [[nodiscard]] static IntersectInfo TestOverlap(Real tMax, Real speed, Real uMin, Real uMax, Real vMin, Real vMax) noexcept;

        [[nodiscard]] IntersectInfo TestOverlap(const Vector3D& axis, Real tMax, const Vector3D& velocity);

        static IntersectInfo ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis);

    private:
        Triangle3 m_Triangle0;
        Triangle3 m_Triangle1;
    };

    using FloatDynamicTestIntersectorTriangle3Triangle3 = DynamicTestIntersectorTriangle3Triangle3<float>;
    using DoubleDynamicTestIntersectorTriangle3Triangle3 = DynamicTestIntersectorTriangle3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
