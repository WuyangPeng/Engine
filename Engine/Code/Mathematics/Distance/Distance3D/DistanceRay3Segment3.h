///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 12:52)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Segment3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceRay3Segment3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Ray3 = Ray3<Real>;
        using Segment3 = Segment3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRay3Segment3(const Ray3& ray, const Segment3& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Ray3 GetRay() const noexcept;
        [[nodiscard]] const Segment3 GetSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;

    private:
        Ray3 m_Ray;
        Segment3 m_Segment;
    };

    using FloatDistanceRay3Segment3 = DistanceRay3Segment3<float>;
    using DoubleDistanceRay3Segment3 = DistanceRay3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_H
