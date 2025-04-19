///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay3Plane3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Ray3Type = Ray3<Real>;
        using Plane3Type = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorRay3Plane3(const Ray3Type& ray, const Plane3Type& plane, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3Type GetRay() const noexcept;
        NODISCARD Plane3Type GetPlane() const noexcept;

        NODISCARD Real GetRayParameter() const noexcept;

    private:
        void Find() noexcept;

    private:
        // 相交对象
        Ray3Type ray;
        Plane3Type plane;

        // 相交对象集信息
        Real rayParameter;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H
