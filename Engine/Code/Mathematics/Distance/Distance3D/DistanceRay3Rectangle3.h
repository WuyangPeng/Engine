///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 11:02)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Rectangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceRay3Rectangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Ray3 = Ray3<Real>;
        using Vector2D = Vector2D<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Rectangle3(const Ray3& ray, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetRay() const noexcept;
        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        // 有关最接近点的信息。
        [[nodiscard]] Real GetRectangleCoordinate(int index) const;

    private:
        Ray3 m_Ray;
        Rectangle3 m_Rectangle;

        // 有关最接近点的信息。

        // closest0 = ray.origin + param*ray.direction
        // closest1 = rect.center + param0*rect.dir0 + param1*rect.dir1
        mutable Vector2D m_RectCoord;
    };

    using FloatDistanceRay3Rectangle3 = DistanceRay3Rectangle3<float>;
    using DoubleDistanceRay3Rectangle3 = DistanceRay3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_H
