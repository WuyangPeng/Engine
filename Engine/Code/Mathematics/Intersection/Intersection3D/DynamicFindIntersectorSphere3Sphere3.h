///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:00)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorSphere3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorSphere3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0,
                                             const Sphere3& sphere1,
                                             Real tMax,
                                             const Vector3& lhsVelocity,
                                             const Vector3& rhsVelocity,
                                             const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Sphere3 GetSphere0() const noexcept;
        NODISCARD Sphere3 GetSphere1() const noexcept;

        // 用于静态查找交叉点查询的交叉点集。
        NODISCARD Circle3 GetCircle() const noexcept;

        // 用于动态查找相交查询的相交集。
        NODISCARD Vector3 GetContactPoint() const noexcept;

    private:
        // 动态查找交叉点查询。
        void Find();

    private:
        // 要相交的对象。
        Sphere3 sphere0;
        Sphere3 sphere1;

        // 静态球体的相交圆。
        Circle3 circle;

        // 动态球体的交点。
        Vector3 contactPoint;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
