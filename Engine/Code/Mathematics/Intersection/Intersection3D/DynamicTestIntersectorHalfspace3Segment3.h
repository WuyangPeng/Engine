///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/14 14:32)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Segment3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 
/// 这里的查询用于线段和半角的交集。
/// 在动态查找查询中，如果线段已经与半空间相交，则返回值为'false'。 
/// 这个想法是寻找第一次接触。

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorHalfspace3Segment3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Segment3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax,
                                                 const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Segment3 GetSegment() const noexcept;

    private:
        void Test();

    private:
        Plane3 m_Halfspace;
        Segment3 m_Segment;
    };

    using FloatDynamicTestIntersectorHalfspace3Segment3 = DynamicTestIntersectorHalfspace3Segment3<float>;
    using DoubleDynamicTestIntersectorHalfspace3Segment3 = DynamicTestIntersectorHalfspace3Segment3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H
