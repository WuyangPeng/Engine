///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Segment3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Segment3<Real>;
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Segment3Type = Segment3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint3Segment3(const Vector3Type& point, const Segment3Type& segment) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3Type GetPoint() const noexcept;
        NODISCARD Segment3Type GetSegment() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        Vector3Type point;
        Segment3Type segment;
    };

    using DistancePoint3Segment3F = DistancePoint3Segment3<float>;
    using DistancePoint3Segment3D = DistancePoint3Segment3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H
