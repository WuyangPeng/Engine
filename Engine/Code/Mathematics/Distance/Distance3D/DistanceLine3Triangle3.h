///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceLine3Triangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Triangle3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Line3Type = Line3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine3Triangle3(const Line3Type& line, const Triangle3Type& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Triangle3Type GetTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

        NODISCARD Real GetTriangleBary(int index) const;

    private:
        Line3Type line;
        Triangle3Type triangle;

        // 有关最接近点的信息。

        mutable Vector3Type triangleBary;
    };

    using DistanceLine3Triangle3F = DistanceLine3Triangle3<float>;
    using DistanceLine3Triangle3D = DistanceLine3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_TRIANGLE3_H
