///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:14)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceTriangle3Rectangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceTriangle3Rectangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Rectangle3 = Rectangle3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceTriangle3Rectangle3(const Triangle3& triangle, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetTriangle() const noexcept;
        NODISCARD Rectangle3 GetRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Triangle3 triangle;
        Rectangle3 rectangle;
    };

    using DistanceTriangle3Rectangle3F = DistanceTriangle3Rectangle3<float>;
    using DistanceTriangle3Rectangle3D = DistanceTriangle3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_RECTANGLE3_H
