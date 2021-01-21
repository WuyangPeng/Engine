///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 11:21)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSphere3Sphere3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorSphere3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere0() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere1() const noexcept;

        // 用于静态查找交叉点查询的交叉点集。
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

        // 用于动态查找相交查询的相交集。
        [[nodiscard]] const Vector3D GetContactPoint() const noexcept;

    private:
        void Find();

        Sphere3 m_Sphere0;
        Sphere3 m_Sphere1;

        // 静态球体的相交圆。
        Circle3 m_Circle;

        // 动态球体的交点。
        Vector3D m_ContactPoint;
    };

    using FloatStaticFindIntersectorSphere3Sphere3 = StaticFindIntersectorSphere3Sphere3<float>;
    using DoubleStaticFindIntersectorSphere3Sphere3 = StaticFindIntersectorSphere3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
