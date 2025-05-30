///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:00)

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
    class StaticTestIntersectorPlane3Cylinder3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorPlane3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Plane3Type = Plane3<Real>;
        using Cylinder3Type = Cylinder3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorPlane3Cylinder3(const Plane3Type& plane, const Cylinder3Type& cylinder, const Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetPlane() const noexcept;
        NODISCARD Cylinder3Type GetCylinder() const noexcept;

        NODISCARD bool CylinderIsCulled() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        void Test() noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        Plane3Type plane;
        Cylinder3Type cylinder;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H
