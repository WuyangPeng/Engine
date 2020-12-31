///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 10:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_BOX3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Box3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceRay3Box3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Ray3 = Ray3<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Box3(const Ray3& ray, const Box3& box) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetRay() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Ray3 m_Ray;
        Box3 m_Box;
    };

    using FloatDistanceRay3Box3 = DistanceRay3Box3<float>;
    using DoubleDistanceRay3Box3 = DistanceRay3Box3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_BOX3_H
