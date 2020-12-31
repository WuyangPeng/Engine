///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 16:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceTriangle3Rectangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceTriangle3Rectangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Rectangle3 = Rectangle3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceTriangle3Rectangle3(const Triangle3& triangle, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;
        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Triangle3 m_Triangle;
        Rectangle3 m_Rectangle;
    };

    using FloatDistanceTriangle3Rectangle3 = DistanceTriangle3Rectangle3<float>;
    using DoubleDistanceTriangle3Rectangle3 = DistanceTriangle3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_H
