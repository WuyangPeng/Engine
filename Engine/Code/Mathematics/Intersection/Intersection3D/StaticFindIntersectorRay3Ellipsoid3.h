///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorRay3Ellipsoid3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Ellipsoid3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Ray3Type = Ray3<Real>;
        using Ellipsoid3Type = Ellipsoid3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorRay3Ellipsoid3(const Ray3Type& ray, const Ellipsoid3Type& ellipsoid, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3Type GetRay() const noexcept;
        NODISCARD Ellipsoid3Type GetEllipsoid() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Ray3Type ray;
        Ellipsoid3Type ellipsoid;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_H
