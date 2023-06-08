///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:56)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint3Triangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Triangle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Triangle3(const Vector3& point, const Triangle3& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

        // �й���ӽ��������ε����Ϣ��
        NODISCARD Real GetTriangleBary(int index) const;

    private:
        Vector3 point;
        Triangle3 triangle;

        mutable Vector3 triangleBary;
    };

    using DistancePoint3Triangle3F = DistancePoint3Triangle3<float>;
    using DistancePoint3Triangle3D = DistancePoint3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_H
