///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:51)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Segment3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Segment3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Line3Type = Line3<Real>;
        using Segment3Type = Segment3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using DistanceLine3Line3ToolType = DistanceLine3Line3Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine3Segment3(const Line3Type& line, const Segment3Type& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Segment3Type GetSegment() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPoints(const DistanceLine3Line3ToolType& tool, Real rhsExtent) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsParallel(const DistanceLine3Line3ToolType& tool) const;

    private:
        Line3Type line;
        Segment3Type segment;
    };

    using DistanceLine3Segment3F = DistanceLine3Segment3<float>;
    using DistanceLine3Segment3D = DistanceLine3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H
