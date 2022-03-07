///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/21 16:17)

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
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Circle3 = Circle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceCircle3Circle3(const Circle3& lhsCircle, const Circle3& rhsCircle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Circle3 GetLhsCircle() const noexcept;
        NODISCARD Circle3 GetRhsCircle() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Circle3 lhsCircle;
        Circle3 rhsCircle;
    };

    using DistanceCircle3Circle3F = DistanceCircle3Circle3<float>;
    using DistanceCircle3Circle3D = DistanceCircle3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
