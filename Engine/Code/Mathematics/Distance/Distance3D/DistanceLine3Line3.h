///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/21 15:22)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Line3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Line3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Line3 = Line3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Line3(const Line3& lhsLine, const Line3& rhsLine) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLhsLine() const noexcept;
        NODISCARD Line3 GetRhsLine() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Line3 lhsLine;
        Line3 rhsLine;
    };

    using DistanceLine3Line3F = DistanceLine3Line3<float>;
    using DistanceLine3Line3D = DistanceLine3Line3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H
