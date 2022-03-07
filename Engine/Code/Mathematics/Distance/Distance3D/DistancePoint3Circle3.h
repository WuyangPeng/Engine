///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/22 14:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Circle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Circle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;
        using Circle3 = Circle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Circle3(const Vector3& point, const Circle3& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Circle3 GetCircle() const noexcept;

        /// ��̬�����ѯ�� ����ӵ�P��Բ�ľ��롣 ��P�ڷ���C + t * N�ϣ�����C��Բ�Ĳ���N�ǰ�����Բ��ƽ��ķ���ʱ��������Բ�㶼��P�Ⱦࡣ
        /// ����������£����ص�ΪC + r * U������U�Ǵ�ֱ��N��������
        NODISCARD DistanceResult GetSquared() const override;

        // ��̬�����ѯ�ĺ������㡣
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Vector3 point;
        Circle3 circle;
    };

    using DistancePoint3Circle3F = DistancePoint3Circle3<float>;
    using DistancePoint3Circle3D = DistancePoint3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
