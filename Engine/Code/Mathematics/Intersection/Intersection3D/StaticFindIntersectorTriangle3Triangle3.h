///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/03 11:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorTriangle3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorTriangle3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Plane3 = Plane3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using Container = std::vector<Vector3>;

    public:
        StaticFindIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle, bool reportCoplanarIntersections = true, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetLhsTriangle() const noexcept;
        NODISCARD Triangle3 GetRhsTriangle() const noexcept;

        NODISCARD int GetQuantity() const;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        void Find();

        void ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3& vector3);

        void IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3& end0, const Vector3& end1);
        void GetCoplanarIntersection(const Plane3& plane, const Triangle3& lhsTriangle, const Triangle3& rhsTriangle);

    private:
        // 默认 'true'
        bool reportCoplanarIntersections;

        Triangle3 triangle0;
        Triangle3 triangle1;

        Container point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
