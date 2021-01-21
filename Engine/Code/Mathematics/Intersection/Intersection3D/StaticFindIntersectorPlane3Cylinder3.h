///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 14:19)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorPlane3Cylinder3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Cylinder3 = Cylinder3<Real>;
        using Line3 = Line3<Real>;
        using Circle3 = Circle3<Real>;
        using Ellipse3 = Ellipse3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using TwoLine = std::pair<Line3, Line3>;

    public:
        StaticFindIntersectorPlane3Cylinder3(const Plane3& plane, const Cylinder3& cylinder, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane() const noexcept;
        [[nodiscard]] const Cylinder3 GetCylinder() const noexcept;

        // 剔除支持。 视锥台被认为位于平面的正侧。 如果圆柱体位于平面的负侧，则将其剔除。
        [[nodiscard]] bool CylinderIsCulled() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // *无限*圆柱体和平面的交集。
        enum class CylinderPlaneIntersection
        {
            EmptySet,
            OneLine,
            TwoLines,
            Circle,
            Ellipse
        };

        [[nodiscard]] CylinderPlaneIntersection GetType() const noexcept;

        // 当GetType()返回OneLine时有效。
        Line3 GetOneLine() const noexcept;

        // 当GetType()返回TwoLines时有效。
        TwoLine GetTwoLines() const noexcept;

        // 当GetType()返回Circle时有效。
        Circle3 GetCircle() const noexcept;

        // 当GetType()返回Ellipse时有效。
        Ellipse3 GetEllipse() const noexcept;

    private:
        // *无限*圆柱体的静态交点查询。
        void Find();

        Plane3 m_Plane;
        Cylinder3 m_Cylinder;

        // 圆柱无限时的相交设置。
        CylinderPlaneIntersection m_Type;
        Line3 m_Line0;
        Line3 m_Line1;
        Circle3 m_Circle;
        Ellipse3 m_Ellipse;
    };

    using FloatStaticFindIntersectorPlane3Cylinder3 = StaticFindIntersectorPlane3Cylinder3<float>;
    using DoubleStaticFindIntersectorPlane3Cylinder3 = StaticFindIntersectorPlane3Cylinder3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
