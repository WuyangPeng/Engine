///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:11)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/MathematicsDll.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Ray3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceRay3Ray3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Ray3Type = Ray3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using DistanceLine3Line3ToolType = DistanceLine3Line3Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceRay3Ray3(const Ray3Type& lhsRay, const Ray3Type& rhsRay) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3Type GetLhsRay() const noexcept;
        NODISCARD Ray3Type GetRhsRay() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3ToolType& tool) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3ToolType& tool) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3ToolType& tool) const;

    private:
        Ray3Type lhsRay;
        Ray3Type rhsRay;
    };

    using DistanceRay3Ray3F = DistanceRay3Ray3<float>;
    using DistanceRay3Ray3D = DistanceRay3Ray3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H
