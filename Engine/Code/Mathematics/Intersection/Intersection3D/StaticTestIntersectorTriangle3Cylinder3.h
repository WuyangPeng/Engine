///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorTriangle3Cylinder3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorTriangle3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Cylinder3Type = Cylinder3<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorTriangle3Cylinder3(const Triangle3Type& triangle, const Cylinder3Type& cylinder, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3Type GetTriangle() const noexcept;
        NODISCARD Cylinder3Type GetCylinder() const noexcept;

    private:
        void Test();

    private:
        NODISCARD bool DiskOverlapsPoint(const Vector2Type& q) const;
        NODISCARD bool DiskOverlapsSegment(const Vector2Type& q0, const Vector2Type& q1) const;
        NODISCARD bool DiskOverlapsPolygon(const std::vector<Vector2Type>& q) const;

    private:
        Triangle3Type triangle;
        Cylinder3Type cylinder;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H
