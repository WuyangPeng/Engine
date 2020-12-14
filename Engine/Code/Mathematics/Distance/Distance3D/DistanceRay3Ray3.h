///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 11:32)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Ray3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceRay3Ray3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Ray3 = Ray3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Ray3(const Ray3& lhsRay, const Ray3& rhsRay) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetLhsRay() const noexcept;
        [[nodiscard]] const Ray3 GetRhsRay() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3Tool& tool) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3Tool& tool) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3Tool& tool) const;

    private:
        Ray3 m_LhsRay;
        Ray3 m_RhsRay;
    };

    using FloatDistanceRay3Ray3 = DistanceRay3Ray3<float>;
    using DoubleDistanceRay3Ray3 = DistanceRay3Ray3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H
