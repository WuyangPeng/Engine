// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Ellipse3.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorPlane3Cylinder3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorPlane3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Cylinder3 = Cylinder3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorPlane3Cylinder3(const Plane3& plane, const Cylinder3& cylinder, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane() const;
        [[nodiscard]] const Cylinder3 GetCylinder() const;

        // Culling support.  The view frustum is assumed to be on the positive
        // side of the plane.  The cylinder is culled if it is on the negative
        // side of the plane.
        [[nodiscard]] bool CylinderIsCulled() const;

    private:
        // Static intersection query for a *finite* cylinder.
        void Test();

        // The objects to intersect.
        Plane3 m_Plane;
        Cylinder3 m_Cylinder;
    };

    using FloatStaticTestIntersectorPlane3Cylinder3 = StaticTestIntersectorPlane3Cylinder3<float>;
    using DoubleStaticTestIntersectorPlane3Cylinder3 = StaticTestIntersectorPlane3Cylinder3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H
