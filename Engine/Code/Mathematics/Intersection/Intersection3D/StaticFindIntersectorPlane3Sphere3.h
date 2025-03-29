///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorPlane3Sphere3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Plane3Type = Plane3<Real>;
        using Sphere3Type = Sphere3<Real>;
        using Circle3Type = Circle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorPlane3Sphere3(const Plane3Type& plane, const Sphere3Type& sphere, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetPlane() const noexcept;
        NODISCARD Sphere3Type GetSphere() const noexcept;

        /// 剔除支持。 视锥台被认为位于平面的正侧。 如果球面在平面的负侧，则将其剔除。
        NODISCARD bool SphereIsCulled() const noexcept;

        // 相交集。 该圆仅在Find()返回“ true”时才有效。 如果不存在相交，则将圆半径设置为-1，以附加指示圆无效。
        NODISCARD Circle3Type GetCircle() const noexcept;

    private:
        void Find();

    private:
        Plane3Type plane;
        Sphere3Type sphere;

        Circle3Type circle;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
