///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:56)

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

        using Vector3Type = Vector3<Real>;
        using Box3Type = Box3<Real>;
        using Sphere3Type = Sphere3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorBox3Sphere3(const Box3Type& box,
                                          const Sphere3Type& sphere,
                                          Real tmax,
                                          const Vector3Type& lhsVelocity,
                                          const Vector3Type& rhsVelocity,
                                          const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box3Type GetBox() const noexcept;
        NODISCARD Sphere3Type GetSphere() const noexcept;

        // 用于动态查找相交查询的相交集。
        NODISCARD Vector3Type GetContactPoint() const noexcept;

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
        Box3Type box;
        Sphere3Type sphere;

        Vector3Type contactPoint;

        Real x;
        Real y;
        Real z;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
