///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:02)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cone3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorSphere3Cone3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorSphere3Cone3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Sphere3Type = Sphere3<Real>;
        using Cone3Type = Cone3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorSphere3Cone3(const Sphere3Type& sphere, const Cone3Type& cone, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Sphere3Type GetSphere() const noexcept;
        NODISCARD Cone3Type GetCone() const noexcept;

    private:
        void Test();

    private:
        Sphere3Type sphere;
        Cone3Type cone;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_CONE3_H
