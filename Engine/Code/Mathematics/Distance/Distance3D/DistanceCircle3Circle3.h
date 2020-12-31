///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 14:58)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceCircle3Circle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceCircle3Circle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceCircle3Circle3(const Circle3& lhsCircle, const Circle3& rhsCircle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Circle3 GetLhsCircle() const noexcept;
        [[nodiscard]] const Circle3 GetRhsCircle() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Circle3 m_LhsCircle;
        Circle3 m_RhsCircle;
    };

    using FloatDistanceCircle3Circle3 = DistanceCircle3Circle3<float>;
    using DoubleDistanceCircle3Circle3 = DistanceCircle3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
