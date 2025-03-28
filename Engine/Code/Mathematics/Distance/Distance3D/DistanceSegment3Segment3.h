///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:13)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment3Segment3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceSegment3Segment3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Segment3Type = Segment3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using DistanceLine3Line3ToolType = DistanceLine3Line3Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceSegment3Segment3(const Segment3Type& lhsSegment, const Segment3Type& rhsSegment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3Type GetLhsSegment() const noexcept;
        NODISCARD Segment3Type GetRhsSegment() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsLhsSide(const DistanceLine3Line3ToolType& tool, Real lhsExtent, Real rhsExtent) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsRhsSide(const DistanceLine3Line3ToolType& tool, Real lhsExtent, Real rhsExtent) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine3Line3ToolType& tool, Real lhsExtent, Real rhsExtent) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine3Line3ToolType& tool, Real lhsExtent, Real rhsExtent) const;

    private:
        Segment3Type lhsSegment;
        Segment3Type rhsSegment;
    };

    using DistanceSegment3Segment3F = DistanceSegment3Segment3<float>;
    using DistanceSegment3Segment3D = DistanceSegment3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H
