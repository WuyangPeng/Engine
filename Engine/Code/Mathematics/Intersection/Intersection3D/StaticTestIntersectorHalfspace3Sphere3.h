// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Sphere3.h"

// A halfspace is the set of points on the side of a plane to which the plane
// normal points.  The queries here are for intersection of a sphere and a
// halfspace.  In the dynamice find query, if the sphere is already
// intersecting the halfspace, the return value is 'false'.  The idea is to
// find first time of contact, in which case there is a single point of
// contacct.

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorHalfspace3Sphere3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorHalfspace3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorHalfspace3Sphere3(const Plane3& halfspace, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

    private:
        void Test();

        Plane3 m_Halfspace;
        Sphere3 m_Sphere;
    };

    using FloatStaticTestIntersectorHalfspace3Sphere3 = StaticTestIntersectorHalfspace3Sphere3<float>;
    using DoubleStaticTestIntersectorHalfspace3Sphere3 = StaticTestIntersectorHalfspace3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H
