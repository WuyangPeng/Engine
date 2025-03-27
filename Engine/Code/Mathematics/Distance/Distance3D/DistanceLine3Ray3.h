///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Ray3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Ray3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Line3 = Line3<Real>;
        using Ray3 = Ray3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine3Ray3(const Line3& line, const Ray3& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Ray3 GetRay() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool) const;

    private:
        Line3 line;
        Ray3 ray;
    };

    using DistanceLine3Ray3F = DistanceLine3Ray3<float>;
    using DistanceLine3Ray3D = DistanceLine3Ray3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H
