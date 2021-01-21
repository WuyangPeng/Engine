///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 18:56)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay3Triangle3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Ray3 = Ray3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetRay() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] Real GetRayParameter() const noexcept;
        [[nodiscard]] Real GetTriangleBary0() const noexcept;
        [[nodiscard]] Real GetTriangleBary1() const noexcept;
        [[nodiscard]] Real GetTriangleBary2() const noexcept;

    private:
        void Find();

    private:
        // 相交对象
        Ray3 m_Ray;
        Triangle3 m_Triangle;

        // 相交对象集信息
        Real m_RayParameter;
        Real m_TriangleBary0;
        Real m_TriangleBary1;
        Real m_TriangleBary2;
    };

    using FloatStaticFindIntersectorRay3Triangle3 = StaticFindIntersectorRay3Triangle3<float>;
    using DoubleStaticFindIntersectorRay3Triangle3 = StaticFindIntersectorRay3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
