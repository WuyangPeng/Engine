///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 18:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay3Sphere3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Ray3 = Ray3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay3Sphere3(const Ray3& ray, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetRay() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;
        [[nodiscard]] Real GetRayParameter(int index) const;

    private:
        void Find();

        Ray3 m_Ray;
        Sphere3 m_Sphere;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
        Real m_RayParameter0;
        Real m_RayParameter1;
    };

    using FloatStaticFindIntersectorRay3Sphere3 = StaticFindIntersectorRay3Sphere3<float>;
    using DoubleStaticFindIntersectorRay3Sphere3 = StaticFindIntersectorRay3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_H
