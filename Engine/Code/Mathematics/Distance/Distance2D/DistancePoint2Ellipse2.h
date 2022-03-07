///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/21 13:42)

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
        using Vector2 = Vector2<Real>;
        using ParentType = DistanceBase<Real, Vector2>;
        using Ellipse2 = Ellipse2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint2Ellipse2(const Vector2& point, const Ellipse2& ellipse) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2 GetPoint() const noexcept;
        NODISCARD Ellipse2 GetEllipse() const noexcept;

        // ��̬�����ѯ��
        NODISCARD DistanceResult GetSquared() const override;

        // �������㶯̬�����ѯ��
        NODISCARD DistanceResult GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const override;

    private:
        Vector2 point;
        Ellipse2 ellipse;
    };

    using DistancePoint2Ellipse2F = DistancePoint2Ellipse2<float>;
    using DistancePoint2Ellipse2D = DistancePoint2Ellipse2<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H
