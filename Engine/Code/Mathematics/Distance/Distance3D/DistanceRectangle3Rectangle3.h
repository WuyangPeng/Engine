///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 14:42)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRectangle3Rectangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceRectangle3Rectangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceRectangle3Rectangle3(const Rectangle3& lhsRectangle, const Rectangle3& rhsRectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Rectangle3 GetLhsRectangle() const noexcept;
        [[nodiscard]] const Rectangle3 GetRhsRectangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Rectangle3 m_LhsRectangle;
        Rectangle3 m_RhsRectangle;
    };

    using FloatDistanceRectangle3Rectangle3 = DistanceRectangle3Rectangle3<float>;
    using DoubleDistanceRectangle3Rectangle3 = DistanceRectangle3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_RECTANGLE3_RECTANGLE3_H
