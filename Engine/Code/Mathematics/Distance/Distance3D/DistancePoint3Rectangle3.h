///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint3Rectangle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Rectangle3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Vector2Type = Vector2<Real>;
        using Rectangle3Type = Rectangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint3Rectangle3(const Vector3Type& point, const Rectangle3Type& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3Type GetPoint() const noexcept;
        NODISCARD Rectangle3Type GetRectangle() const noexcept;

        NODISCARD DistanceResult GetSquared() const override;

        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

        // �й���ӽ��ľ��ε����Ϣ��
        Real GetRectangleCoordinate(int index) const;

    private:
        Vector3Type point;
        Rectangle3Type rectangle;

        // �й���ӽ��ľ��ε����Ϣ
        mutable Vector2Type rectCoord;
    };

    using DistancePoint3Rectangle3F = DistancePoint3Rectangle3<float>;
    using DistancePoint3Rectangle3D = DistancePoint3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_H
