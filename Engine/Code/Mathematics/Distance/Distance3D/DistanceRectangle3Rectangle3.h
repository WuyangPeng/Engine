///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 15:25)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceRectangle3Rectangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceRectangle3Rectangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRectangle3Rectangle3(const Rectangle3& lhsRectangle, const Rectangle3& rhsRectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Rectangle3 GetLhsRectangle() const noexcept;
        NODISCARD Rectangle3 GetRhsRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Rectangle3 lhsRectangle;
        Rectangle3 rhsRectangle;
    };

    using DistanceRectangle3Rectangle3F = DistanceRectangle3Rectangle3<float>;
    using DistanceRectangle3Rectangle3D = DistanceRectangle3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H
