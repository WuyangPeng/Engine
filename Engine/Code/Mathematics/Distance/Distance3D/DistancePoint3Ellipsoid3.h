///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/21 15:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint3Ellipsoid3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Ellipsoid3<Real>;
        using Vector3 = Vector3<Real>;
        using Ellipsoid3 = Ellipsoid3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Ellipsoid3(const Vector3& point, const Ellipsoid3& ellipsoid) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Ellipsoid3 GetEllipsoid() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Vector3 point;
        Ellipsoid3 ellipsoid;
    };

    using DistancePoint3Ellipsoid3F = DistancePoint3Ellipsoid3<float>;
    using DistancePoint3Ellipsoid3D = DistancePoint3Ellipsoid3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_ELLIPSOID3_H
