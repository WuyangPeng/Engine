///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/01 11:27)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Sphere3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 这里的查询是球体和半空间的交集。
/// 在动态查找查询中，如果球体已经与半空间相交，则返回值为“ false”。
/// 这个想法是找到第一次接触，在这种情况下，只有一个接触点。

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorHalfspace3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorHalfspace3Sphere3(const Plane3& halfspace,
                                                const Sphere3& sphere,
                                                Real tmax,
                                                const Vector3& lhsVelocity,
                                                const Vector3& rhsVelocity,
                                                const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Sphere3 GetSphere() const noexcept;

    private:
        void Test();

    private:
        Plane3 halfspace;
        Sphere3 sphere;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_H
