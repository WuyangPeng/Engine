///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 18:22)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorSphere3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorSphere3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax,
                                             const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere0() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere1() const noexcept;

        // 用于静态查找交叉点查询的交叉点集。
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

        // 用于动态查找相交查询的相交集。
        [[nodiscard]] const Vector3D GetContactPoint() const noexcept;

    private:
        // 动态查找交叉点查询。
        void Find();

        // 要相交的对象。
        Sphere3 m_Sphere0;
        Sphere3 m_Sphere1;

        // 静态球体的相交圆。
        Circle3 m_Circle;

        // 动态球体的交点。
        Vector3D m_ContactPoint;
    };

    using FloatDynamicFindIntersectorSphere3Sphere3 = DynamicFindIntersectorSphere3Sphere3<float>;
    using DoubleDynamicFindIntersectorSphere3Sphere3 = DynamicFindIntersectorSphere3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
