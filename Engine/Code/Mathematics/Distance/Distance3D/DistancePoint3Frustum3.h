///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/14 12:55)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_FRUSTUM3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Frustum3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Frustum3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Frustum3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Frustum3 = Frustum3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Frustum3(const Vector3D& point, const Frustum3& frustum) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Frustum3 GetFrustum() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Frustum3 m_Frustum;
    };

    using FloatDistancePoint3Frustum3 = DistancePoint3Frustum3<float>;
    using DoubleDistancePoint3Frustum3 = DistancePoint3Frustum3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_FRUSTUM3_H
