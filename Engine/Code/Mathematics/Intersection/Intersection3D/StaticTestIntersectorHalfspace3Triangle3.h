// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/24 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

// A halfspace is the set of points on the side of a plane to which the plane
// normal points.  The queries here are for intersection of a triangle and a
// halfspace.  In the dynamice find query, if the triangle is already
// intersecting the halfspace, the return value is 'false'.  The idea is to
// find first time of contact.

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorHalfspace3Triangle3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorHalfspace3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

    private:
        void Test();

        Plane3 m_Halfspace;
        Triangle3 m_Triangle;
    };

    using FloatStaticTestIntersectorHalfspace3Triangle3 = StaticTestIntersectorHalfspace3Triangle3<float>;
    using DoubleStaticTestIntersectorHalfspace3Triangle3 = StaticTestIntersectorHalfspace3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
