///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 13:01)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment3Segment3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceSegment3Segment3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Segment3 = Segment3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceSegment3Segment3(const Segment3& lhsSegment, const Segment3& rhsSegment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetLhsSegment() const noexcept;
        [[nodiscard]] const Segment3 GetRhsSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsLhsSide(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRhsSide(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;

    private:
        Segment3 m_LhsSegment;
        Segment3 m_RhsSegment;
    };

    using FloatDistanceSegment3Segment3 = DistanceSegment3Segment3<float>;
    using DoubleDistanceSegment3Segment3 = DistanceSegment3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H
