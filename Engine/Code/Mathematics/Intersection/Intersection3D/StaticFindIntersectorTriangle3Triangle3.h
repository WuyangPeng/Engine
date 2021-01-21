///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/08 16:50)

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
    class FindIntersectorTriangle3Triangle3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle3Triangle3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle3Triangle3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle3Triangle3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorTriangle3Triangle3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using StaticFindIntersectorTriangle3Triangle3Impl = FindIntersectorTriangle3Triangle3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StaticFindIntersectorTriangle3Triangle3);

        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Plane3 = Plane3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle, bool reportCoplanarIntersections = true, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetLhsTriangle() const noexcept;
        [[nodiscard]] const Triangle3 GetRhsTriangle() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        [[nodiscard]] void ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3D& point);

        [[nodiscard]] void IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3D& end0, const Vector3D& end1);
        [[nodiscard]] void GetCoplanarIntersection(const Plane3& plane, const Triangle3& triangle0, const Triangle3& triangle1);

    private:
        // 默认 'true'
        bool m_ReportCoplanarIntersections;

        IMPL_TYPE_DECLARE(StaticFindIntersectorTriangle3Triangle3);
    };

    using FloatStaticFindIntersectorTriangle3Triangle3 = StaticFindIntersectorTriangle3Triangle3<float>;
    using DoubleStaticFindIntersectorTriangle3Triangle3 = StaticFindIntersectorTriangle3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
