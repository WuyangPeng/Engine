///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:11)

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
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Triangle3Type = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint3Triangle3(const Vector3Type& point, const Triangle3Type& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3Type GetPoint() const noexcept;
        NODISCARD Triangle3Type GetTriangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

        // �й���ӽ��������ε����Ϣ��
        NODISCARD Real GetTriangleBary(int index) const;

    private:
        Vector3Type point;
        Triangle3Type triangle;

        mutable Vector3Type triangleBary;
    };

    using DistancePoint3Triangle3F = DistancePoint3Triangle3<float>;
    using DistancePoint3Triangle3D = DistancePoint3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TRIANGLE3_H
