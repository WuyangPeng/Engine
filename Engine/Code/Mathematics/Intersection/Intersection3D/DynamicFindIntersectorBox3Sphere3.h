///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/29 17:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorBox3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorBox3Sphere3(
            const Box3& box,
            const Sphere3& sphere,
            Real tmax,
            const Vector3D& lhsVelocity,
            const Vector3D& rhsVelocity,
            const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        // 用于动态查找相交查询的相交集。
        [[nodiscard]] const Vector3D GetContactPoint() const noexcept;

    private:
        void Find();

        // 动态查找功能的支持函数。
        [[nodiscard]] static Real GetVertexIntersection(Real diffX, Real diffY, Real diffZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ, Real radiusSqr) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] static Real GetEdgeIntersection(Real diffX, Real diffZ, Real relativeVelocityDotX, Real relativeVelocityDotZ, Real velocitySqr, Real radiusSqr) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] int FindFaceRegionIntersection(Real extentX, Real extentY, Real extentZ, Real centerDiffDotX, Real centerDiffDotY, Real centerDiffDotZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ, bool aboveFace) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] int FindJustEdgeIntersection(Real centerDiffDotY, Real extentX, Real extentY, Real extentZ, Real diffX, Real diffZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] int FindEdgeRegionIntersection(Real extentX, Real extentY, Real extentZ, Real centerDiffDotX, Real centerDiffDotY, Real centerDiffDotZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ, bool aboveEdge) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] int FindVertexRegionIntersection(Real extentX, Real extentY, Real extentZ, Real centerDiffDotX, Real centerDiffDotY, Real centerDiffDotZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    private:
        Box3 m_Box;
        Sphere3 m_Sphere;

        Vector3D m_ContactPoint;

        Real m_X;
        Real m_Y;
        Real m_Z;
    };

    using FloatDynamicFindIntersectorBox3Sphere3 = DynamicFindIntersectorBox3Sphere3<float>;
    using DoubleDynamicFindIntersectorBox3Sphere3 = DynamicFindIntersectorBox3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
