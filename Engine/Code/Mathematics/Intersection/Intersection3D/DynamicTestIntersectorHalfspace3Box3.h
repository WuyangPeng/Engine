///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/13 11:38)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Plane3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 
/// 这里的查询是一个盒子和半个平面的交集。 
/// 在动态查找查询中，如果该框已经与半个平面相交，则返回值为'false'。
/// 这个想法是寻找第一次接触。

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorHalfspace3Box3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicTestIntersectorHalfspace3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box, Real tmax,
                                             const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

    private:
        void Test();

    private:
        Plane3 m_Halfspace;
        Box3 m_Box;
    };

    using FloatDynamicTestIntersectorHalfspace3Box3 = DynamicTestIntersectorHalfspace3Box3<float>;
    using DoubleDynamicTestIntersectorHalfspace3Box3 = DynamicTestIntersectorHalfspace3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H
