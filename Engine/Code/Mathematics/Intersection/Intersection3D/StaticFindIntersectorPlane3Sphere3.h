///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 18:00)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorPlane3Sphere3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorPlane3Sphere3(const Plane3& plane, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        /// 剔除支持。 视锥台被认为位于平面的正侧。 如果球面在平面的负侧，则将其剔除。
        [[nodiscard]] bool SphereIsCulled() const noexcept;

        // 相交集。 该圆仅在Find()返回“ true”时才有效。 如果不存在相交，则将圆半径设置为-1，以附加指示圆无效。
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

    private:
        void Find();

    private:
        Plane3 m_Plane;
        Sphere3 m_Sphere;

        Circle3 m_Circle;
    };

    using FloatStaticFindIntersectorPlane3Sphere3 = StaticFindIntersectorPlane3Sphere3<float>;
    using DoubleStaticFindIntersectorPlane3Sphere3 = StaticFindIntersectorPlane3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
