///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:47)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Ellipse2.h"

namespace Mathematics
{
    template <typename Real>
    class DistancePoint2Ellipse2 : public DistanceBase<Real, Vector2<Real>>
    {
    public:
        using ClassType = DistancePoint2Ellipse2<Real>;
        using Vector2Type = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2Type>;

        using Ellipse2Type = Ellipse2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint2Ellipse2(const Vector2Type& point, const Ellipse2Type& ellipse) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2Type GetPoint() const noexcept;
        NODISCARD Ellipse2Type GetEllipse() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector2Type& lhsVelocity, const Vector2Type& rhsVelocity) const override;

    private:
        Vector2Type point;
        Ellipse2Type ellipse;
    };

    using DistancePoint2Ellipse2F = DistancePoint2Ellipse2<float>;
    using DistancePoint2Ellipse2D = DistancePoint2Ellipse2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H
