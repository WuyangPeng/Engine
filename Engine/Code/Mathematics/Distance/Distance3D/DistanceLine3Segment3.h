///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 18:34)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Segment3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Segment3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Segment3 = Segment3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Segment3(const Line3& line, const Segment3& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Segment3 GetSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;
        [[nodiscard]] const DistanceResult GetSquaredWithClosestPointsIsParallel(const DistanceLine3Line3Tool& tool) const;

    private:
        Line3 m_Line;
        Segment3 m_Segment;
    };

    using FloatDistanceLine3Segment3 = DistanceLine3Segment3<float>;
    using DoubleDistanceLine3Segment3 = DistanceLine3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H
