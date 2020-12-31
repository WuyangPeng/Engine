///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 11:21)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Segment3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Segment3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Segment3 = Segment3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Segment3(const Vector3D& point, const Segment3& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Segment3 GetSegment() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Segment3 m_Segment;
    };

    using FloatDistancePoint3Segment3 = DistancePoint3Segment3<float>;
    using DoubleDistancePoint3Segment3 = DistancePoint3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H
