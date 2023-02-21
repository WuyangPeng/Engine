///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/28 10:57)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorBox3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorBox3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorBox3Sphere3(const Box3& box,
                                          const Sphere3& sphere,
                                          Real tmax,
                                          const Vector3& lhsVelocity,
                                          const Vector3& rhsVelocity,
                                          const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box3 GetBox() const noexcept;
        NODISCARD Sphere3 GetSphere() const noexcept;

        // 用于动态查找相交查询的相交集。
        NODISCARD Vector3 GetContactPoint() const noexcept;

    private:
        void Find();

        // 动态查找功能的支持函数。
        NODISCARD static Real GetVertexIntersection(Real diffX, Real diffY, Real diffZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ, Real radiusSqr) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD static Real GetEdgeIntersection(Real diffX, Real diffZ, Real relativeVelocityDotX, Real relativeVelocityDotZ, Real velocitySqr, Real radiusSqr) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD int FindFaceRegionIntersection(Real extentX, Real extentY, Real extentZ, Real centerDiffDotX, Real centerDiffDotY, Real centerDiffDotZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ, bool aboveFace) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD int FindJustEdgeIntersection(Real centerDiffDotY, Real extentX, Real extentY, Real extentZ, Real diffX, Real diffZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD int FindEdgeRegionIntersection(Real extentX, Real extentY, Real extentZ, Real centerDiffDotX, Real centerDiffDotY, Real centerDiffDotZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ, bool aboveEdge) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD int FindVertexRegionIntersection(Real extentX, Real extentY, Real extentZ, Real centerDiffDotX, Real centerDiffDotY, Real centerDiffDotZ, Real relativeVelocityDotX, Real relativeVelocityDotY, Real relativeVelocityDotZ) noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        Box3 box;
        Sphere3 sphere;

        Vector3 contactPoint;

        Real x;
        Real y;
        Real z;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
