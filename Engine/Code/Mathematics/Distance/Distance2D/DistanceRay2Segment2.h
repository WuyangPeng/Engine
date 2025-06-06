///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:49)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/DistanceInternalFwd.h"
#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay2Segment2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistanceRay2Segment2<Real>;
        using Vector2Type = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2Type>;

        using Ray2Type = Ray2<Real>;
        using Segment2Type = Segment2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using DistanceLine2Line2ToolType = DistanceLine2Line2Tool<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceRay2Segment2(const Ray2Type& ray, const Segment2Type& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray2Type GetRay() const noexcept;
        NODISCARD Segment2Type GetSegment() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const override;

    private:
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine2Line2ToolType& tool, Real rhsExtent) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine2Line2ToolType& tool, Real rhsExtent) const;
        NODISCARD DistanceResult GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine2Line2ToolType& tool, Real rhsExtent) const;

    private:
        Ray2Type ray;
        Segment2Type segment;
    };

    using DistanceRay2Segment2F = DistanceRay2Segment2<float>;
    using DistanceRay2Segment2D = DistanceRay2Segment2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H
