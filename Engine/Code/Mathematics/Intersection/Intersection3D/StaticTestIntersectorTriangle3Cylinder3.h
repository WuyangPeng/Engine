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

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Cylinder3 = Cylinder3<Real>;
        using Vector2 = Vector2<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorTriangle3Cylinder3(const Triangle3& triangle, const Cylinder3& cylinder, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetTriangle() const noexcept;
        NODISCARD Cylinder3 GetCylinder() const noexcept;

    private:
        void Test();

    private:
        NODISCARD bool DiskOverlapsPoint(const Vector2& q) const;
        NODISCARD bool DiskOverlapsSegment(const Vector2& q0, const Vector2& q1) const;
        NODISCARD bool DiskOverlapsPolygon(const std::vector<Vector2>& q) const;

    private:
        Triangle3 triangle;
        Cylinder3 cylinder;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H
