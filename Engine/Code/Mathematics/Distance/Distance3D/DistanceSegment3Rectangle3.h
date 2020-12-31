///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 15:46)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment3Rectangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceSegment3Rectangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Segment3 = Segment3<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceSegment3Rectangle3(const Segment3& segment, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        [[nodiscard]] Real GetRectangleCoordinate(int index) const;

    private:
        Segment3 m_Segment;
        Rectangle3 m_Rectangle;

        // closest0 = seg.origin + param*seg.direction
        // closest1 = rect.center + param0*rect.dir0 + param1*rect.dir1
        mutable Vector2D m_RectCoord;
    };

    using FloatDistanceSegment3Rectangle3 = DistanceSegment3Rectangle3<float>;
    using DoubleDistanceSegment3Rectangle3 = DistanceSegment3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_RECTANGLE3_H
