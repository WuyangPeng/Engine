///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:11)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceRay3Rectangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceRay3Rectangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Ray3 = Ray3<Real>;
        using Vector2 = Vector2<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Rectangle3(const Ray3& ray, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3 GetRay() const noexcept;
        NODISCARD Rectangle3 GetRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

        // 有关最接近点的信息。
        NODISCARD Real GetRectangleCoordinate(int index) const;

    private:
        Ray3 ray;
        Rectangle3 rectangle;

        // 有关最接近点的信息。

        mutable Vector2 rectCoord;
    };

    using DistanceRay3Rectangle3F = DistanceRay3Rectangle3<float>;
    using DistanceRay3Rectangle3D = DistanceRay3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RECTANGLE3_H
