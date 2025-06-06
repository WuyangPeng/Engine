///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    // 查找交叉点查询。 相交点是
    // P = origin + t * direction = b0 * V0 + b1 * V1 + b2 * V2
    template <typename Real>
    class StaticFindIntersectorRay3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Ray3Type = Ray3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorRay3Triangle3(const Ray3Type& ray, const Triangle3Type& triangle, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3Type GetRay() const noexcept;
        NODISCARD Triangle3Type GetTriangle() const noexcept;

        NODISCARD Real GetRayParameter() const noexcept;
        NODISCARD Real GetTriangleBary0() const noexcept;
        NODISCARD Real GetTriangleBary1() const noexcept;
        NODISCARD Real GetTriangleBary2() const noexcept;

    private:
        void Find();

    private:
        // 相交对象
        Ray3Type ray;
        Triangle3Type triangle;

        // 相交对象集信息
        Real rayParameter;
        Real triangleBary0;
        Real triangleBary1;
        Real triangleBary2;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
