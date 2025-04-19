///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:14)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceTriangle3Triangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceTriangle3Triangle3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Triangle3Type = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceTriangle3Triangle3(const Triangle3Type& lhsTriangle, const Triangle3Type& rhsTriangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3Type GetLhsTriangle() const noexcept;
        NODISCARD Triangle3Type GetRhsTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

        NODISCARD Real GetTriangleBary0(int index) const;
        NODISCARD Real GetTriangleBary1(int index) const;

    private:
        Triangle3Type lhsTriangle;
        Triangle3Type rhsTriangle;

        mutable Vector3Type triangleBary0;
        mutable Vector3Type triangleBary1;
    };

    using DistanceTriangle3Triangle3F = DistanceTriangle3Triangle3<float>;
    using DistanceTriangle3Triangle3D = DistanceTriangle3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H
