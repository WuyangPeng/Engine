///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/15 13:08)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Triangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceRay3Triangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Ray3 = Ray3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Triangle3(const Ray3& ray, const Triangle3& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetRay() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        // �й���ӽ������Ϣ��
        [[nodiscard]] Real GetTriangleBary(int index) const;

    private:
        Ray3 m_Ray;
        Triangle3 m_Triangle;

        // closest0 = ray.origin+param*ray.direction
        // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
        mutable Vector3D m_TriangleBary;
    };

    using FloatDistanceRay3Triangle3 = DistanceRay3Triangle3<float>;
    using DoubleDistanceRay3Triangle3 = DistanceRay3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_TRIANGLE3_H
