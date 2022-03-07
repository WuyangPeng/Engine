///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 14:42)

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
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Tetrahedron3 = Tetrahedron3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Tetrahedron3(const Vector3& point, const Tetrahedron3& tetrahedron) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Tetrahedron3 GetTetrahedron() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Vector3 point;
        Tetrahedron3 tetrahedron;
    };

    using DistancePoint3Tetrahedron3F = DistancePoint3Tetrahedron3<float>;
    using DistancePoint3Tetrahedron3D = DistancePoint3Tetrahedron3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H
