///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceLine3Rectangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Rectangle3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Line3Type = Line3<Real>;
        using Vector2Type = Vector2<Real>;
        using Rectangle3Type = Rectangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine3Rectangle3(const Line3Type& line, const Rectangle3Type& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Rectangle3Type GetRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

        NODISCARD Real GetRectangleCoordinate(int index) const;

    private:
        Line3Type line;
        Rectangle3Type rectangle;

        // 有关最接近点的信息。

        mutable Vector2Type rectCoord;
    };

    using DistanceLine3Rectangle3F = DistanceLine3Rectangle3<float>;
    using DistanceLine3Rectangle3D = DistanceLine3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RECTANGLE3_H
