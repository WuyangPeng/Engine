///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 15:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_BOX3_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment3Box3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceSegment3Box3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Segment3 = Segment3<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceSegment3Box3(const Segment3& segment, const Box3& box) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Segment3 m_Segment;
        Box3 m_Box;
    };

    using FloatDistanceSegment3Box3 = DistanceSegment3Box3<float>;
    using DoubleDistanceSegment3Box3 = DistanceSegment3Box3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_BOX3_H
