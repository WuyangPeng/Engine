///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:11)

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
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Rectangle3Type = Rectangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceRectangle3Rectangle3(const Rectangle3Type& lhsRectangle, const Rectangle3Type& rhsRectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Rectangle3Type GetLhsRectangle() const noexcept;
        NODISCARD Rectangle3Type GetRhsRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        Rectangle3Type lhsRectangle;
        Rectangle3Type rhsRectangle;
    };

    using DistanceRectangle3Rectangle3F = DistanceRectangle3Rectangle3<float>;
    using DistanceRectangle3Rectangle3D = DistanceRectangle3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H
