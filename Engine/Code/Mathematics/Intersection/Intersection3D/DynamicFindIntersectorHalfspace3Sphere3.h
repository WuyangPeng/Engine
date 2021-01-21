///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/04 13:14)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_H

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorHalfspace3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorHalfspace3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorHalfspace3Sphere3(const Plane3& halfspace, const Sphere3& sphere, Real tmax,
                                                const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        // 相交集为空或点。 
        [[nodiscard]] const Vector3D GetPoint() const noexcept;

    private:
        void Find();

        Plane3 m_Halfspace;
        Sphere3 m_Sphere;

        Vector3D m_Point;
    };

    using FloatDynamicFindIntersectorHalfspace3Sphere3 = DynamicFindIntersectorHalfspace3Sphere3<float>;
    using DoubleDynamicFindIntersectorHalfspace3Sphere3 = DynamicFindIntersectorHalfspace3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_H
