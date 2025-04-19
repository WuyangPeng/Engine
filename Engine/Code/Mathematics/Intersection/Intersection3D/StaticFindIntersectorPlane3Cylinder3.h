///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Ellipse3.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorPlane3Cylinder3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Plane3Type = Plane3<Real>;
        using Cylinder3Type = Cylinder3<Real>;
        using Line3Type = Line3<Real>;
        using Circle3Type = Circle3<Real>;
        using Ellipse3Type = Ellipse3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using TwoLine = std::pair<Line3Type, Line3Type>;

    public:
        StaticFindIntersectorPlane3Cylinder3(const Plane3Type& plane, const Cylinder3Type& cylinder, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetPlane() const noexcept;
        NODISCARD Cylinder3Type GetCylinder() const noexcept;

        // 剔除支持。 视锥台被认为位于平面的正侧。 如果圆柱体位于平面的负侧，则将其剔除。
        NODISCARD bool CylinderIsCulled() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // *无限*圆柱体和平面的交集。
        enum class CylinderPlaneIntersection
        {
            EmptySet,
            OneLine,
            TwoLines,
            Circle,
            Ellipse
        };

        NODISCARD CylinderPlaneIntersection GetType() const noexcept;

        // 当GetType()返回OneLine时有效。
        Line3Type GetOneLine() const noexcept;

        // 当GetType()返回TwoLines时有效。
        TwoLine GetTwoLines() const noexcept;

        // 当GetType()返回Circle时有效。
        Circle3Type GetCircle() const noexcept;

        // 当GetType()返回Ellipse时有效。
        Ellipse3Type GetEllipse() const noexcept;

    private:
        // *无限*圆柱体的静态交点查询。
        void Find();

    private:
        Plane3Type plane;
        Cylinder3Type cylinder;

        // 圆柱无限时的相交设置。
        CylinderPlaneIntersection type;
        Line3Type line0;
        Line3Type line1;
        Circle3Type circle;
        Ellipse3Type ellipse;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
