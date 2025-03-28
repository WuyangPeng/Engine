///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceCircle3Circle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceCircle3Circle3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Circle3Type = Circle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceCircle3Circle3(const Circle3Type& lhsCircle, const Circle3Type& rhsCircle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Circle3Type GetLhsCircle() const noexcept;
        NODISCARD Circle3Type GetRhsCircle() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        Circle3Type lhsCircle;
        Circle3Type rhsCircle;
    };

    using DistanceCircle3Circle3F = DistanceCircle3Circle3<float>;
    using DistanceCircle3Circle3D = DistanceCircle3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
