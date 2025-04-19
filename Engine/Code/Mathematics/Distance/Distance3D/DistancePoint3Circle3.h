///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:09)

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
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Circle3Type = Circle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint3Circle3(const Vector3Type& point, const Circle3Type& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3Type GetPoint() const noexcept;
        NODISCARD Circle3Type GetCircle() const noexcept;

        /// ��̬�����ѯ�� ����ӵ�P��Բ�ľ��롣 ��P�ڷ���C + t * N�ϣ�����C��Բ�Ĳ���N�ǰ�����Բ��ƽ��ķ���ʱ��������Բ�㶼��P�Ⱦࡣ
        /// ����������£����ص�ΪC + r * U������U�Ǵ�ֱ��N��������
        NODISCARD DistanceResult GetSquared() const override;

        // ��̬�����ѯ�ĺ������㡣
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        Vector3Type point;
        Circle3Type circle;
    };

    using DistancePoint3Circle3F = DistancePoint3Circle3<float>;
    using DistancePoint3Circle3D = DistancePoint3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_CIRCLE3_H
