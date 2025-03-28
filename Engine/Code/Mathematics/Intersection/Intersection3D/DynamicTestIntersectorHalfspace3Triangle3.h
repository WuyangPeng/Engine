///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:02)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 这里的查询是三角形和半空间的交集。
/// 在动态查找查询中，如果三角形已经与半空间相交，则返回值为'false'。 这个想法是寻找第一次接触。

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorHalfspace3Triangle3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Plane3Type = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicTestIntersectorHalfspace3Triangle3(const Plane3Type& halfspace,
                                                  const Triangle3Type& triangle,
                                                  Real tmax,
                                                  const Vector3Type& lhsVelocity,
                                                  const Vector3Type& rhsVelocity,
                                                  const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetHalfspace() const noexcept;
        NODISCARD Triangle3Type GetTriangle() const noexcept;

    private:
        void Test();

    private:
        Plane3Type halfspace;
        Triangle3Type triangle;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
