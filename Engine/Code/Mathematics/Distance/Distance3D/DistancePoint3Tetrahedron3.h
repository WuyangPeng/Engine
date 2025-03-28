///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Tetrahedron3.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint3Tetrahedron3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Tetrahedron3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Tetrahedron3Type = Tetrahedron3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint3Tetrahedron3(const Vector3Type& point, const Tetrahedron3Type& tetrahedron) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3Type GetPoint() const noexcept;
        NODISCARD Tetrahedron3Type GetTetrahedron() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        Vector3Type point;
        Tetrahedron3Type tetrahedron;
    };

    using DistancePoint3Tetrahedron3F = DistancePoint3Tetrahedron3<float>;
    using DistancePoint3Tetrahedron3D = DistancePoint3Tetrahedron3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H
